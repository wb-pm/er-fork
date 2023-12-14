/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERFootMuSiTrackFinder.h"

#include <cassert>

#include "TVector3.h"
#include "TMath.h"

#include "FairRootManager.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"
#include "FairLink.h"

#include "ERRunAna.h"
#include "ERDigi.h"

 //--------------------------------------------------------------------------------------------------
ERFootMuSiTrackFinder::ERFootMuSiTrackFinder()
  : ERTask("ER FootMuSi track finding scheme")
{
  fAvailibleRunManagers.push_back("ERRunAna");
  fFootMuSiSetup = ERFootMuSiSetup::Instance();
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiTrackFinder::ERFootMuSiTrackFinder(Int_t verbose)
  : ERTask("ER FootMuSi track finding scheme ", verbose)
{
  fAvailibleRunManagers.push_back("ERRunAna");
  fFootMuSiSetup = ERFootMuSiSetup::Instance();
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::SetHitStation(TString subassemblyName, TString componentId)
{
  TString xStripArrayName = componentId;
  TString yStripArrayName = componentId;
  fSiHitStationsPair[subassemblyName].emplace(
    std::make_pair(componentId, std::pair<TString, TString>(xStripArrayName.Append("_X"),
      yStripArrayName.Append("_Y"))));
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::SetHitStation(TString subassemblyName, TString componentIdX,
  TString componentIdY)
{
  fSiHitStationsPair[subassemblyName].emplace(
    std::make_pair(componentIdX + componentIdY, std::pair<TString, TString>(componentIdX, componentIdY)));
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::
SetHitPositionCorrection(const TString& station_name, ERChannel channel, float strip_fraction)
{
  if (strip_fraction < -0.5 || strip_fraction > 0.5)
  {
    LOG(FATAL) << "Correction of hit position in strip should be in range [-0.5, 0.5]"
      << FairLogger::endl;
  }
  hit_position_corrections_[station_name][channel] = strip_fraction;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::SetStripEdepRange(Double_t edepMin, Double_t edepMax)
{
  fSiDigiEdepMin = edepMin;
  fSiDigiEdepMax = edepMax;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::SetInteractionPosition(double x, double y, double z)
{
  interaction_position_is_set_ = true;
  interaction_x_ = x;
  interaction_y_ = y;
  interaction_z_ = z;
}
//--------------------------------------------------------------------------------------------------
TVector3 ERFootMuSiTrackFinder::
GetGlobalHitPositionByStrip(const TString& branch_name, const ERChannel channel) const
{
  // Local position of strip center
  TVector3 local_position = fFootMuSiSetup->GetStripLocalPosition(branch_name, channel);
  const Double_t strip_width = fFootMuSiSetup->GetStripWidth(branch_name, channel);
  // Apply user coorections
  for (const auto& station_to_channels : hit_position_corrections_)
  {
    const TString station_name = station_to_channels.first;
    if (!branch_name.Contains(station_name))
      continue;
    const std::map<ERChannel,float> channel_to_position_correction = station_to_channels.second;
    const std::map<ERChannel,float>::const_iterator channel_and_correction = channel_to_position_correction.find(channel);
    if (channel_and_correction == channel_to_position_correction.end())
      continue;
    const float correction = channel_and_correction->second;
    const Double_t current_position = local_position[0];
    local_position[0] = current_position + strip_width * correction;
    LOG(DEBUG) << "[ERQFootMuSiTrackFinder] Local position of strip " << channel << " of "
      << station_name << " corrected from " << current_position << " to "
      << local_position[0] << FairLogger::endl;
  }
  return fFootMuSiSetup->ToGlobalCoordinateSystem(branch_name, local_position);
}
//--------------------------------------------------------------------------------------------------
InitStatus ERFootMuSiTrackFinder::Init()
{
  if (ERTask::Init() != kSUCCESS)
    return kFATAL;

  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman)
    Fatal("Init", "No FairRootManager");
  TList* allbrNames = ioman->GetBranchNameList();
  TIter nextBranch(allbrNames);
  TObjString* bName;
  std::vector<TString> pointBranches;
  while (bName = (TObjString*)nextBranch())
  {
    TString bFullName = bName->GetString();
    if (bFullName.Contains("Digi") && bFullName.Contains("FootMuSi"))
    {
      Int_t bPrefixNameLength = bFullName.First('_');
      TString brName(bFullName(bPrefixNameLength + 1, bFullName.Length()));
      fFootMuSiDigi[brName] = (TClonesArray*)ioman->GetObject(bFullName);
    }
  }
  // Register output track branches only for stations that are setted by interface SetStation(){
  for (const auto itSubassemblies : fSiHitStationsPair)
  {
    for (const auto itComponent : itSubassemblies.second)
    {
      fFootMuSiHit[itComponent.first] = new TClonesArray("ERFootMuSiHit", 10);
      ioman->Register("FootMuSiHit_" + itComponent.first, "FootMuSi", fFootMuSiHit[itComponent.first], kTRUE);
    }
  }

  fFootMuSiTrack = new TClonesArray("ERFootMuSiTrack", 100);
  ioman->Register("FootMuSiTrack", "FootMuSi", fFootMuSiTrack, kTRUE);

  fFootMuSiSetup->ERFootMuSiSetup::ReadGeoParamsFromParContainer();

  //@TODO check setup and digi branch names

  return kSUCCESS;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::Exec(Option_t* opt)
{
  LOG(DEBUG) << "[ERFootMuSiTrackFinder]------------Started--------------------------------------"
    << FairLogger::endl;
  Reset();
  for (const auto& itSubassemblies : fSiHitStationsPair)
  {
    for (const auto& itComponent : itSubassemblies.second)
    {
      // pairs of X and Y strips that have difference between edep less than fEdepDiffXY
      std::vector<std::pair<Int_t, Int_t>> hitFootMuSiPoint;
      // strips with edep in correct interval (fSiDigiEdepMin, fSiDigiEdepMax)
      std::vector<Int_t> correctStripsX;
      // strips with edep in correct interval (fSiDigiEdepMin, fSiDigiEdepMax)
      std::vector<Int_t> correctStripsY;
      const TString xDigiBranchName = itComponent.second.first;
      const TString yDigiBranchName = itComponent.second.second;
      if (fFootMuSiSetup->GetStationType(xDigiBranchName) != fFootMuSiSetup->GetStationType(yDigiBranchName))
      {
        LOG(FATAL) << "Do not mix R and Q FootMuSis for hit finding" << FairLogger::endl;
      }
      const TClonesArray* xDigi = fFootMuSiDigi[xDigiBranchName];
      const TClonesArray* yDigi = fFootMuSiDigi[yDigiBranchName];
      if (!xDigi || !yDigi)
      {
        continue;
      }
      if (xDigi->GetEntriesFast() == 0 || yDigi->GetEntriesFast() == 0)
      {
        continue;
      }
      for (Int_t iXDigi = 0; iXDigi < xDigi->GetEntriesFast(); iXDigi++)
      {
        const Double_t xStripEdep = ((ERDigi*)xDigi->At(iXDigi))->Edep();
        if (xStripEdep > fSiDigiEdepMin && xStripEdep < fSiDigiEdepMax)
        {
          correctStripsX.push_back(iXDigi);
        }
      }
      for (Int_t iYDigi = 0; iYDigi < yDigi->GetEntriesFast(); iYDigi++)
      {
        const Double_t yStripEdep = ((ERDigi*)yDigi->At(iYDigi))->Edep();
        if (yStripEdep > fSiDigiEdepMin && yStripEdep < fSiDigiEdepMax)
        {
          correctStripsY.push_back(iYDigi);
        }
      }
      for (const auto itCorrectStripsX : correctStripsX)
      {
        const Double_t xStripEdep = ((ERDigi*)xDigi->At(itCorrectStripsX))->Edep();
        for (const auto itCorrectStripsY : correctStripsY)
        {
          const Double_t yStripEdep = ((ERDigi*)yDigi->At(itCorrectStripsY))->Edep();
          if (TMath::Abs(xStripEdep - yStripEdep) < fEdepDiffXY)
          {
            hitFootMuSiPoint.push_back(std::pair<Int_t, Int_t>(itCorrectStripsX, itCorrectStripsY));
          }
        }
      }
      LOG(DEBUG) << "[ERFootMuSiTrackFinder] Strips array pair " << itComponent.second.first << " "
        << itComponent.second.second << FairLogger::endl;
      LOG(DEBUG) << "[ERFootMuSiTrackFinder] Hits count on pair " << hitFootMuSiPoint.size() << FairLogger::endl;
      for (const auto& itHitPoint : hitFootMuSiPoint)
      {
        const Int_t xChannelIndex = itHitPoint.first;
        const Int_t yChannelIndex = itHitPoint.second;
        const ERDigi* xStrip = dynamic_cast<ERDigi*>(xDigi->At(xChannelIndex));
        const ERDigi* yStrip = dynamic_cast<ERDigi*>(yDigi->At(yChannelIndex));
        if (!xStrip || !yStrip)
          continue;
        const ERChannel xChannel = xStrip->Channel();
        const ERChannel yChannel = yStrip->Channel();
        if (fFootMuSiSetup->GetStationType(xDigiBranchName) == ERFootMuSiSetup::StationType::QStation)
        {
          CreateHitInFootMuSi(xChannelIndex, yChannelIndex, xChannel, yChannel,
            xStrip->Edep(), yStrip->Edep(), xDigiBranchName, yDigiBranchName,
            itComponent.first);
        }
        else
        {
          CreateHitInRFootMuSi(xChannelIndex, yChannelIndex, xChannel, yChannel,
            xStrip->Edep(), yStrip->Edep(), xDigiBranchName, yDigiBranchName,
            itComponent.first);
        }
      }
    }
  }
  Int_t numberOfPairs = std::distance(fFootMuSiHit.begin(), fFootMuSiHit.end());
  //TODO: for now the rest part of the code, responsible for track recreation, will be hardcoded to 3 pairs of stations
  TClonesArray* hitsFirstStationPair = fFootMuSiHit.begin()->second;
  TClonesArray* hitsSecondStationPair = std::next(fFootMuSiHit.begin())->second;
  TClonesArray* hitsThirdStationPair = std::next(fFootMuSiHit.begin(), 2)->second;
  LOG(INFO) << "First stations pair name" << fFootMuSiHit.begin()->first << FairLogger::endl;
  LOG(INFO) << "Second stations pair name" << std::next(fFootMuSiHit.begin())->first << FairLogger::endl;
  LOG(INFO) << "Third stations pair name" << std::next(fFootMuSiHit.begin(), 2)->first << FairLogger::endl;
  for (int iHitFirstPair = 0; iHitFirstPair < hitsFirstStationPair->GetEntriesFast(); ++iHitFirstPair)
  {
        ERFootMuSiHit* hitFirstPair = (ERFootMuSiHit*)hitsFirstStationPair->At(iHitFirstPair);
    for (int iHitSecondPair = 0; iHitSecondPair < hitsSecondStationPair->GetEntriesFast(); ++iHitSecondPair)
    {
        ERFootMuSiHit* hitSecondPair = (ERFootMuSiHit*)hitsSecondStationPair->At(iHitSecondPair);
      for (int iHitThirdPair = 0; iHitThirdPair < hitsThirdStationPair->GetEntriesFast(); ++iHitThirdPair)
      {
        ERFootMuSiHit* hitThirdPair = (ERFootMuSiHit*)hitsThirdStationPair->At(iHitThirdPair);
        TVector3 vectorFirstPairX = hitFirstPair->GetXStationVertex();
        TVector3 vectorFirstPairY = hitFirstPair->GetYStationVertex();
        TVector3 vectorSecondPairX = hitSecondPair->GetXStationVertex();
        TVector3 vectorSecondPairY = hitSecondPair->GetYStationVertex();
        TVector3 vectorThirdPairX = hitThirdPair->GetXStationVertex();
        TVector3 vectorThirdPairY = hitThirdPair->GetYStationVertex();

        const Double_t kxFirst = (vectorSecondPairX.X() - vectorFirstPairX.X())/(vectorSecondPairX.Z()-vectorFirstPairX.Z());
        const Double_t bxFirst = vectorSecondPairX.X() - kxFirst*vectorSecondPairX.Z(); 

        vectorFirstPairY.SetX(kxFirst*vectorFirstPairY.Z()+bxFirst);
        vectorSecondPairY.SetX(kxFirst*vectorSecondPairY.Z()+bxFirst);
        const TVector3& firstHitPoint = vectorSecondPairY - vectorFirstPairY;
        
        const Double_t kxSecond = (vectorThirdPairX.X()-vectorSecondPairX.X())/(vectorThirdPairX.Z()-vectorSecondPairX.Z());
        const Double_t bxSecond = vectorThirdPairX.X() - kxSecond*vectorThirdPairX.Z();
        vectorSecondPairY.SetX(kxSecond*vectorSecondPairY.Z() + bxSecond);
        vectorThirdPairY.SetX(kxSecond*vectorThirdPairY.Z() + bxSecond);
        const TVector3& secondHitPoint = vectorThirdPairY - vectorSecondPairY;

        LOG(DEBUG) << "X coordinate reconstruction at first station: " << kxFirst*vectorFirstPairY.Z()+bxFirst << ", at the second station: " << kxFirst*vectorSecondPairY.Z()+bxFirst << FairLogger::endl << ", at the second station (another pair): " << kxSecond*vectorSecondPairY.Z() + bxSecond << ", at the third station: " << kxSecond*vectorThirdPairY.Z() + bxSecond << FairLogger::endl;
        if(fabs((kxFirst*vectorSecondPairY.Z()+bxFirst) - (kxSecond*vectorSecondPairY.Z() + bxSecond)) > 0.001)
        {
          continue;
        }
        if ( secondHitPoint.Angle(firstHitPoint) < fAngleBetweenHitsCut)
        {
          ERFootMuSiTrack* track = AddTrack(vectorFirstPairY, vectorSecondPairY, vectorThirdPairY);
          //ERFootMuSiTrack* track = AddTrack(firstHitPoint,secondHitPoint);
        }
      }
    }
  }
  LOG(DEBUG) << "[ERFootMuSiTrackFinder]------------Finished--------------------------------------"
  << "The number of tracks is: " << fFootMuSiTrack->GetEntriesFast()
    << FairLogger::endl;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::CreateHitInFootMuSi(
  const Int_t xChannelIndex, const Int_t yChannelIndex, const Int_t xChannel, const Int_t yChannel,
  const Double_t xEdep, const Double_t yEdep, const TString& xDigiBranchName, const TString& yDigiBranchName,
  const TString& hitBranchName)
{
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Branch names X:" << xDigiBranchName
    << " Y: " << yDigiBranchName << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Strips pair numbers " << xChannel << " "
    << yChannel << FairLogger::endl;
  // Calc unknown coordinated using condition: target, hit on first station(closest) and
  // hit on second station lie on line :
  // {x2, y2, z2} = {interaction_x_, interaction_y_, interaction_z_} + k * ({x1, y1, z1} - {interaction_x_, interaction_y_, interaction_z_}).
  const bool xStationIsClosest = fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel) < fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel);
  // We know all about z coordinate, so
  const double z1 = xStationIsClosest
    ? fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel)
    : fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel);
  const double z2 = xStationIsClosest
    ? fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel)
    : fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel);
  assert(z1 != interaction_z_);
  const double k = (z2 - interaction_z_) / (z1 - interaction_z_);
  double x1 = 0., x2 = 0., y1 = 0., y2 = 0.;
  if (xStationIsClosest)
  { // find y1, x2 from equation
    x1 = GetGlobalHitPositionByStrip(xDigiBranchName, xChannel)[0];
    y2 = GetGlobalHitPositionByStrip(yDigiBranchName, yChannel)[1];
    LOG(DEBUG) << "[ERFootMuSiTrackFinder] Coordinates from strips. x1 = " << x1
      << " y2 = " << y2 << " z1 = " << z1 << " z2 = " << z2 << FairLogger::endl;
    y1 = (-1. / k) * ((1. - k) * interaction_y_ - y2);
    x2 = (1. - k) * interaction_x_ + k * x1;
  }
  else
  { // find x1, y2 from equation
    x2 = GetGlobalHitPositionByStrip(xDigiBranchName, xChannel)[0];
    y1 = GetGlobalHitPositionByStrip(yDigiBranchName, yChannel)[1];
    LOG(DEBUG) << "[ERFootMuSiTrackFinder] Coordinates from strips. x2 = " << x2
      << " y1 = " << y1 << " z1 = " << z1 << " z2 = " << z2 << FairLogger::endl;
    x1 = (-1. / k) * ((1. - k) * interaction_x_ - x2);
    y2 = (1. - k) * interaction_y_ + k * y1;
  }
  const TVector3& xStationVertex = xStationIsClosest ? TVector3(x1, y1, z1) : TVector3(x2, y2, z2);
  const TVector3& yStationVertex = xStationIsClosest ? TVector3(x2, y2, z2) : TVector3(x1, y1, z1);
  const TVector3& xStationLocalVertex = fFootMuSiSetup->ToStationCoordinateSystem(xDigiBranchName, xStationVertex);
  const TVector3& yStationLocalVertex = fFootMuSiSetup->ToStationCoordinateSystem(yDigiBranchName, yStationVertex);
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] X Station Vertex (" << xStationVertex.x() << " " << xStationVertex.y()
    << " " << xStationVertex.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Y Station Vertex (" << yStationVertex.x() << " " << yStationVertex.y()
    << " " << yStationVertex.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] X Station Vertex in station CS (" << xStationLocalVertex.x() << " " << xStationLocalVertex.y()
    << " " << xStationLocalVertex.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Y Station Vertex in station CS (" << yStationLocalVertex.x() << " " << yStationLocalVertex.y()
    << " " << yStationLocalVertex.z() << ")" << FairLogger::endl;
  ERFootMuSiHit* hit = AddHit(TVector3(interaction_x_, interaction_y_, interaction_z_), xStationVertex, yStationVertex,
    xStationLocalVertex, yStationLocalVertex, xChannel, yChannel, xEdep, yEdep,
    hitBranchName);
  // track->AddLink(FairLink(xDigiBranchName, xChannelIndex));
  // track->AddLink(FairLink(yDigiBranchName, yChannelIndex));
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::CreateHitInRFootMuSi(
  const Int_t phiChannelIndex, const Int_t rChannelIndex, const Int_t phiChannel, const Int_t rChannel,
  const Double_t phiEdep, const Double_t rEdep, const TString& phiDigiBranchName, const TString& rDigiBranchName,
  const TString& trackBranchName)
{
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Branch names phi:" << phiDigiBranchName
    << " R: " << rDigiBranchName << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] phi channel = " << phiChannel << " r channel = "
    << rChannel << FairLogger::endl;
  // Calc unknown coordinated using condition: target, hit on first station(closest) and
  // hit on second station lie on line :
  // {x2, y2, z2} = {interaction_x_, interaction_y_, interaction_z_} + k * ({x1, y1, z1} - {interaction_x_, interaction_y_, interaction_z_}).
  // x = x_station + r * cos(phi); y = y_station + r * sin(phi)
  // Lets 1 - phi station(we know phi1), 2 - r station (we know r2)
  // r2 cos(phi2) = interaction_x_ - x_station2 + k(x_station1 + r1 cos(phi1) - interaction_x_)
  // r2 sin(phi2) = interaction_y_ - y_station2 + k(y_station1 + r1 sin(phi1) - interaction_x_)
  // k = (z2 - interaction_z_) / (z1 - interaction_z_)
  // ----
  // r1: r2^2 = (interaction_x_ - x_station2 + k(x_station1 + r1 cos(phi1) - interaction_x_))^2
  //            + (interaction_y_ - y_station2 + k(y_station1 + r1 sin(phi1) - interaction_y_))^2
  // A = interaction_x_ - x_station2 + k(x_station1 - interaction_x_)
  // B = k cos(phi1)
  // C = interaction_y_ - y_station2 + k(y_station1 - interaction_y_)
  // D = k sin(phi1)
  // r2^2 = (A + Br1)^2 + (C + Dr1)^2
  // r1 = -/+(sqrt(D^2(r2^2 - A^2)+2ABCD +B^2(r2^2 - C^2)) +- AB +/- CD) / (B^2 +D^2)
  // r1 = -/+(sqrt(D^2(r2^2 - A^2)+2ABCD +B^2(r2^2 - C^2)) +- AB +/- CD) / k^2
  const TVector3 station1 = fFootMuSiSetup->GetStationTranslation(phiDigiBranchName);
  const TVector3 station2 = fFootMuSiSetup->GetStationTranslation(rDigiBranchName);
  const TVector3 target(interaction_x_, interaction_y_, interaction_z_);
  const Double_t phi1 = fFootMuSiSetup->GetStripPhi(phiDigiBranchName, phiChannel);
  const Double_t r2 = fFootMuSiSetup->GetStripR(rDigiBranchName, rChannel);
  const Double_t k = (station2.Z() - interaction_z_) / (station1.Z() - interaction_z_);
  const Double_t A = interaction_x_ - station2.X() + k * (station1.X() - interaction_x_);
  const Double_t B = k * TMath::Cos(phi1 * TMath::RadToDeg());
  const Double_t C = interaction_y_ - station2.Y() + k * (station1.Y() - interaction_y_);
  const Double_t D = k * TMath::Sin(phi1 * TMath::RadToDeg());
  const Double_t r1 = (TMath::Sqrt(D * D * (r2 * r2 - A * A) + 2 * A * B * C * D + B * B * (r2 * r2 - C * C)) - A * B - C * D) / (k * k);
  const TVector3 local_vertex1(r1 * TMath::Cos(phi1 * TMath::DegToRad()), r1 * TMath::Sin(phi1 * TMath::DegToRad()), 0.);
  const TVector3 global_vertex1 = station1 + local_vertex1;
  const TVector3 global_vertex2 = target + k * (global_vertex1 - target);
  const TVector3 local_vertex2 = global_vertex2 - station2;
  const Double_t phi2 = TMath::ACos(local_vertex2.X() / r2) * TMath::RadToDeg();
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] phi station: phi = " << phi1 << " r = " << r1 << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] r station: phi = " << phi2 << " r = " << r2 << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] phi station: local vertex = (" << local_vertex1.x() << " " << local_vertex1.y()
    << " " << local_vertex1.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] r station: local vertex = (" << local_vertex2.x() << " " << local_vertex2.y()
    << " " << local_vertex2.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] phi station: global vertex = (" << global_vertex1.x() << " " << global_vertex1.y()
    << " " << global_vertex1.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] r station: global vertex = (" << global_vertex2.x() << " " << global_vertex2.y()
    << " " << global_vertex2.z() << ")" << FairLogger::endl;
  ERFootMuSiHit* hit = AddHit(TVector3(interaction_x_, interaction_y_, interaction_z_), global_vertex1, global_vertex2,
    local_vertex1, local_vertex2, phiChannel, rChannel, phiEdep, rEdep,
    trackBranchName);
  // track->AddLink(FairLink(phiDigiBranchName, phiChannelIndex));
  // track->AddLink(FairLink(rDigiBranchName, rChannelIndex));
}
//--------------------------------------------------------------------------------------------------
/* std::vector<const TVector3&> ERFootMuSiTrackFinder::ProjectOntoYPlane(ERFootMuSiHit* firstHit, ERFootMuSiHit* secondHit)
{

}  */
//--------------------------------------------------------------------------------------------------
void ERFootMuSiTrackFinder::Reset()
{
  for (const auto itHitBranches : fFootMuSiHit)
  {

    if (itHitBranches.second)
    {
      itHitBranches.second->Delete();
    }
  }
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiHit* ERFootMuSiTrackFinder::AddHit(
  const TVector3& targetVertex, const TVector3& xStationVertex, const TVector3& yStationVertex,
  const TVector3& xStationLocalVertex, const TVector3& yStationLocalVertex,
  const Int_t xChannel, const Int_t yChannel, const Double_t xEdep, const Double_t yEdep,
  const TString& digiBranchName)
{
  return new ((*fFootMuSiHit[digiBranchName])[fFootMuSiHit[digiBranchName]->GetEntriesFast()])
    ERFootMuSiHit(targetVertex, xStationVertex, yStationVertex, xStationLocalVertex,
      yStationLocalVertex, xChannel, yChannel, xEdep, yEdep);
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiTrack* ERFootMuSiTrackFinder::AddTrack(const TVector3& firstPairVector, const TVector3& secondPairVector, const TVector3& thirdPairVector)
{
  return new ((*fFootMuSiTrack)[fFootMuSiTrack->GetEntriesFast()])
    ERFootMuSiTrack(firstPairVector, secondPairVector, thirdPairVector);
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiTrack* ERFootMuSiTrackFinder::AddTrack(const TVector3& firstHitPointVector, const TVector3& secondHitPointVector)
{
  return new ((*fFootMuSiTrack)[fFootMuSiTrack->GetEntriesFast()])
    ERFootMuSiTrack(firstHitPointVector,secondHitPointVector);
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiTrackFinder)

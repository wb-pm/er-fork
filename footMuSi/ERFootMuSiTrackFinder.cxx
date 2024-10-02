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
#include "TF1.h"
#include "Fit/BinData.h"
#include "Fit/Fitter.h"
#include "Math/WrappedMultiTF1.h"

#include "FairRootManager.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"
#include "FairLink.h"


#include "ERRunAna.h"
#include "ERDigi.h"
#include "ERDecay7CEventHeader.h"
#include "ERDecayMCEventHeader.h"
#include "ERMCTrack.h"

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
TVector3 ERFootMuSiTrackFinder::
GetGlobalHitPositionByStrip(const TString& branch_name, const ERChannel channel) const
{
  // Local position of strip center
  TVector3 local_position = fFootMuSiSetup->GetStripLocalPosition(branch_name, channel);
  const Double_t strip_width = fFootMuSiSetup->GetStripWidth(branch_name, channel);
  // Apply user corrections
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
//For testing the idea with sending unchanged proton coordinates into the tracks
  fMCTracks = (TClonesArray*)ioman->GetObject("MCTrack");
  fMCEventHeader = (TClonesArray*)ioman->GetObject("MCEventHeader."); 

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
  ioman->Register("MCEventHeader.","FootMuSi",fMCEventHeader,kTRUE);
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
      LOG(DEBUG) << FairLogger::endl << "[ERFootMuSiTrackFinder] Strips array pair " << itComponent.second.first << " "
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
        LOG(DEBUG) << "[ERFootMuSiTrackFinder] The X channel of the hit: " << xChannel << " The Y channel of the hit: " << yChannel << FairLogger::endl;
        //Use the condition for energy deposition in order to choose a specific particle, proton or he3 in the case of 7C decay
        if (fLowerEdepCut > xStrip->Edep() || fUpperEdepCut < xStrip->Edep() || fLowerEdepCut > yStrip->Edep() || fUpperEdepCut < yStrip->Edep())
        {
          LOG(INFO) << "[ERFootMuSiTrackFinder] Hit energy is not in the set energy deposition range, skipping the hit" << FairLogger::endl;
          continue;
        }
        if (fFootMuSiSetup->GetStationType(xDigiBranchName) == ERFootMuSiSetup::StationType::QStation && fFootMuSiSetup->GetStationType(yDigiBranchName) == ERFootMuSiSetup::StationType::QStation)
        {
          CreateHitInFootMuSi(xChannelIndex, yChannelIndex, xChannel, yChannel,
            xStrip->Edep(), yStrip->Edep(), xDigiBranchName, yDigiBranchName,
            itComponent.first);
        }
        else
        {
          LOG(ERROR) << "[ERFootMuSiTrackFinder] The station is not a Q type" << FairLogger::endl;
        }
      }
    }
  }
Bool_t isProtonDebug = true;  
std::vector<TVector3> p1Xp1YHits(3);
std::vector<TVector3> p1Xp2YHits(3);
std::vector<TVector3> p1Yp2XHits(3);
std::vector<TVector3> p2Xp2YHits(3);
#if isProtonDebug
#endif

  //Test by putting coordinates of protons' continued trajectories from reaction position into the track finder
if(isProtonDebug)
{
  ERDecay7CEventHeader *decayEventHeader = (ERDecay7CEventHeader*)fMCEventHeader;
  ERDecayMCEventHeader *decayMCEventHeader = (ERDecayMCEventHeader*)fMCEventHeader;
  TVector3 initialPosition = decayMCEventHeader->GetReactionPos();
  TLorentzVector firstProton = decayEventHeader->Getp1();
  TLorentzVector secondProton = decayEventHeader->Getp2();
  //Having four different combinations of protons' X and Y coordinates correspondence
  //In order to check the granularity let's make an arbitrary strips division. The size of one strip is t = 0.015 cm
  // We should take the existing coordinate and turn it to the nearest multiple of t
  // The zero of the axis is located in strip number 300
  // The 1st strip center should be located at -5 + t/2
  // So if the strip is inside the region of -5 + t, it should go to the first strip and so on
  // the formula should look something like this: -5 + t/2(1 + floor((5 + y)/(t))) 
  // Now we should modify the X coordinate at each station and only then imply this formula
  //Left and right coordinates of the detectors
  Bool_t isGranularity = true;
  Double_t detectorNegativeEdge = -5.;
  Double_t detectorPositiveEdge = 5.;
  Double_t stripSize = 0.015;
  std::vector<Double_t> detectorsZ = {20.,21.,36.,37.,52.,53.};
  // Testing the algorithm for projecting the coordinate from X detector to Y detector at each pairs

  //First proton coordinates at respective detectors
  Double_t p1FirstDetectorX = (detectorsZ.at(0)-initialPosition.Z())*(firstProton.Px()/firstProton.Pz())+initialPosition.X();
  Double_t p1SecondDetectorY = (detectorsZ.at(1)-initialPosition.Z())*(firstProton.Py()/firstProton.Pz())+initialPosition.Y();
  Double_t p1ThirdDetectorX = (detectorsZ.at(2)-initialPosition.Z())*(firstProton.Px()/firstProton.Pz())+initialPosition.X();
  Double_t p1FourthDetectorY = (detectorsZ.at(3)-initialPosition.Z())*(firstProton.Py()/firstProton.Pz())+initialPosition.Y();
  Double_t p1FifthDetectorX = (detectorsZ.at(4)-initialPosition.Z())*(firstProton.Px()/firstProton.Pz())+initialPosition.X();
  Double_t p1SixthDetectorY = (detectorsZ.at(5)-initialPosition.Z())*(firstProton.Py()/firstProton.Pz())+initialPosition.Y(); 

  //Accounting the granularity of the detectors for the first proton coordinates
  Double_t p1FirstDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1FirstDetectorX)/(stripSize));
  Double_t p1SecondDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1SecondDetectorY)/(stripSize));
  Double_t p1ThirdDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1ThirdDetectorX)/(stripSize));
  Double_t p1FourthDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1FourthDetectorY)/(stripSize));
  Double_t p1FifthDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1FifthDetectorX)/(stripSize));
  Double_t p1SixthDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p1SixthDetectorY)/(stripSize));

  //Parameters for the straight line that is used for projecting X coordinates of the first proton onto Y detectors
  Double_t p1Slope = (p1FifthDetectorX - p1FirstDetectorX)/(detectorsZ.at(4) - detectorsZ.at(0));
  Double_t p1SlopeCentered = (p1FifthDetectorXCentered - p1FirstDetectorXCentered)/(detectorsZ.at(4) - detectorsZ.at(0));
  Double_t p1Intercept = (p1FirstDetectorX + p1FifthDetectorX - p1Slope*(detectorsZ.at(0) + detectorsZ.at(4)))/2;
  Double_t p1InterceptCentered = (p1FirstDetectorXCentered + p1FifthDetectorXCentered - p1SlopeCentered * (detectorsZ.at(0) + detectorsZ.at(4)))/2;

  //Second proton coordinates at respective detectors

  Double_t p2FirstDetectorX = (detectorsZ.at(0)-initialPosition.Z())*(secondProton.Px()/secondProton.Pz())+initialPosition.X();
  Double_t p2SecondDetectorY = (detectorsZ.at(1)-initialPosition.Z())*(secondProton.Py()/secondProton.Pz())+initialPosition.Y();
  Double_t p2ThirdDetectorX = (detectorsZ.at(2)-initialPosition.Z())*(secondProton.Px()/secondProton.Pz())+initialPosition.X();
  Double_t p2FourthDetectorY = (detectorsZ.at(3)-initialPosition.Z())*(secondProton.Py()/secondProton.Pz())+initialPosition.Y();
  Double_t p2FifthDetectorX = (detectorsZ.at(4)-initialPosition.Z())*(secondProton.Px()/secondProton.Pz())+initialPosition.X();
  Double_t p2SixthDetectorY = (detectorsZ.at(5)-initialPosition.Z())*(secondProton.Py()/secondProton.Pz())+initialPosition.Y(); 

  //Accounting the granularity of the detectors for the second proton coordinates
  Double_t p2FirstDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2FirstDetectorX)/(stripSize));
  Double_t p2SecondDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2SecondDetectorY)/(stripSize));
  Double_t p2ThirdDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2ThirdDetectorX)/(stripSize));
  Double_t p2FourthDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2FourthDetectorY)/(stripSize));
  Double_t p2FifthDetectorXCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2FifthDetectorX)/(stripSize));
  Double_t p2SixthDetectorYCentered = detectorNegativeEdge + stripSize/2 + stripSize*floor((detectorPositiveEdge+p2SixthDetectorY)/(stripSize));

  //Parameters for the straight line that is used for projecting X coordinates of the first proton onto Y detectors
  Double_t p2Slope = (p2FifthDetectorX - p2FirstDetectorX)/(detectorsZ.at(4) - detectorsZ.at(0));
  Double_t p2SlopeCentered = (p2FifthDetectorXCentered - p2FirstDetectorXCentered)/(detectorsZ.at(4) - detectorsZ.at(0));
  Double_t p2Intercept = (p2FirstDetectorX + p2FifthDetectorX - p2Slope*(detectorsZ.at(0) + detectorsZ.at(4)))/2;
  Double_t p2InterceptCentered = (p2FirstDetectorXCentered + p2FifthDetectorXCentered - p2SlopeCentered * (detectorsZ.at(0) + detectorsZ.at(4)))/2;

  //Setting the vectors of each protons combination, depending on whether the granularity is taken into account
  if(isGranularity){
    p1Xp1YHits.at(0).SetXYZ(detectorsZ.at(1)*p1SlopeCentered+p1InterceptCentered,p1SecondDetectorYCentered,detectorsZ.at(1));
    p1Xp1YHits.at(1).SetXYZ(detectorsZ.at(3)*p1SlopeCentered+p1InterceptCentered,p1FourthDetectorYCentered,detectorsZ.at(3));
    p1Xp1YHits.at(2).SetXYZ(detectorsZ.at(5)*p1SlopeCentered+p1InterceptCentered,p1SixthDetectorYCentered,detectorsZ.at(5));

    p1Xp2YHits.at(0).SetXYZ(detectorsZ.at(1)*p1SlopeCentered+p1InterceptCentered,p2SecondDetectorYCentered,detectorsZ.at(1));
    p1Xp2YHits.at(1).SetXYZ(detectorsZ.at(3)*p1SlopeCentered+p1InterceptCentered,p2FourthDetectorYCentered,detectorsZ.at(3));
    p1Xp2YHits.at(2).SetXYZ(detectorsZ.at(5)*p1SlopeCentered+p1InterceptCentered,p2SixthDetectorYCentered,detectorsZ.at(5));

    p1Yp2XHits.at(0).SetXYZ(detectorsZ.at(1)*p2SlopeCentered+p2InterceptCentered,p1SecondDetectorYCentered,detectorsZ.at(1));
    p1Yp2XHits.at(1).SetXYZ(detectorsZ.at(3)*p2SlopeCentered+p2InterceptCentered,p1FourthDetectorYCentered,detectorsZ.at(3));
    p1Yp2XHits.at(2).SetXYZ(detectorsZ.at(5)*p2SlopeCentered+p2InterceptCentered,p1SixthDetectorYCentered,detectorsZ.at(5));

    p2Xp2YHits.at(0).SetXYZ(detectorsZ.at(1)*p2SlopeCentered+p2InterceptCentered,p2SecondDetectorYCentered,detectorsZ.at(1));
    p2Xp2YHits.at(1).SetXYZ(detectorsZ.at(3)*p2SlopeCentered+p2InterceptCentered,p2FourthDetectorYCentered,detectorsZ.at(3));
    p2Xp2YHits.at(2).SetXYZ(detectorsZ.at(5)*p2SlopeCentered+p2InterceptCentered,p2SixthDetectorYCentered,detectorsZ.at(5));
  }
  else{
    p1Xp1YHits.at(0).SetXYZ(detectorsZ.at(1)*p1Slope+p1Intercept,p1SecondDetectorY,detectorsZ.at(1));
    p1Xp1YHits.at(1).SetXYZ(detectorsZ.at(3)*p1Slope+p1Intercept,p1FourthDetectorY,detectorsZ.at(3));
    p1Xp1YHits.at(2).SetXYZ(detectorsZ.at(5)*p1Slope+p1Intercept,p1SixthDetectorY,detectorsZ.at(5));

    p1Xp2YHits.at(0).SetXYZ(detectorsZ.at(1)*p1Slope+p1Intercept,p2SecondDetectorY,detectorsZ.at(1));
    p1Xp2YHits.at(1).SetXYZ(detectorsZ.at(3)*p1Slope+p1Intercept,p2FourthDetectorY,detectorsZ.at(3));
    p1Xp2YHits.at(2).SetXYZ(detectorsZ.at(5)*p1Slope+p1Intercept,p2SixthDetectorY,detectorsZ.at(5));

    p1Yp2XHits.at(0).SetXYZ(detectorsZ.at(1)*p2Slope+p2Intercept,p1SecondDetectorY,detectorsZ.at(1));
    p1Yp2XHits.at(1).SetXYZ(detectorsZ.at(3)*p2Slope+p2Intercept,p1FourthDetectorY,detectorsZ.at(3));
    p1Yp2XHits.at(2).SetXYZ(detectorsZ.at(5)*p2Slope+p2Intercept,p1SixthDetectorY,detectorsZ.at(5));

    p2Xp2YHits.at(0).SetXYZ(detectorsZ.at(1)*p2Slope+p2Intercept,p2SecondDetectorY,detectorsZ.at(1));
    p2Xp2YHits.at(1).SetXYZ(detectorsZ.at(3)*p2Slope+p2Intercept,p2FourthDetectorY,detectorsZ.at(3));
    p2Xp2YHits.at(2).SetXYZ(detectorsZ.at(5)*p2Slope+p2Intercept,p2SixthDetectorY,detectorsZ.at(5));
  }


  // Conditions for accounting the size of detectors
  Bool_t p1Xp1YCondition = (fabs(p1Xp1YHits.at(0).X()) <= 5) && (fabs(p1Xp1YHits.at(0).Y()) <= 5) && (fabs(p1Xp1YHits.at(1).X()) <= 5) && (fabs(p1Xp1YHits.at(1).Y()) <= 5) && (fabs(p1Xp1YHits.at(2).X()) <= 5) && (fabs(p1Xp1YHits.at(2).Y()) <= 5);

  Bool_t p1Xp2YCondition = (fabs(p1Xp2YHits.at(0).X()) <= 5) && (fabs(p1Xp2YHits.at(0).Y()) <= 5) && (fabs(p1Xp2YHits.at(1).X()) <= 5) && (fabs(p1Xp2YHits.at(1).Y()) <= 5) && (fabs(p1Xp2YHits.at(2).X()) <= 5) && (fabs(p1Xp2YHits.at(2).Y()) <= 5);

  Bool_t p1Yp2XCondition = (fabs(p1Yp2XHits.at(0).X()) <= 5) && (fabs(p1Yp2XHits.at(0).Y()) <= 5) && (fabs(p1Yp2XHits.at(1).X()) <= 5) && (fabs(p1Yp2XHits.at(1).Y()) <= 5) && (fabs(p1Yp2XHits.at(2).X()) <= 5) && (fabs(p1Yp2XHits.at(2).Y()) <= 5);

  Bool_t p2Xp2YCondition = (fabs(p2Xp2YHits.at(0).X()) <= 5) && (fabs(p2Xp2YHits.at(0).Y()) <= 5) && (fabs(p2Xp2YHits.at(1).X()) <= 5) && (fabs(p2Xp2YHits.at(1).Y()) <= 5) && (fabs(p2Xp2YHits.at(2).X()) <= 5) && (fabs(p2Xp2YHits.at(2).Y()) <= 5);

  if(p2Xp2YCondition)
  {
    ERFootMuSiTrack *track = AddTrack(p2Xp2YHits.at(0),p2Xp2YHits.at(1),p2Xp2YHits.at(2));
  }
  if(p1Yp2XCondition)
  {
    ERFootMuSiTrack *track = AddTrack(p1Yp2XHits.at(0),p1Yp2XHits.at(1),p1Yp2XHits.at(2));
  }
  if(p1Xp2YCondition)
  {
    ERFootMuSiTrack *track = AddTrack(p1Xp2YHits.at(0),p1Xp2YHits.at(1),p1Xp2YHits.at(2));
  }
  if(p1Xp1YCondition)
  {
    ERFootMuSiTrack *track = AddTrack(p1Xp1YHits.at(0),p1Xp1YHits.at(1),p1Xp1YHits.at(2));
  }
}
//..........................
  Int_t numberOfPairs = std::distance(fFootMuSiHit.begin(), fFootMuSiHit.end());
  //TODO: for now the rest part of the code, responsible for track recreation, will be hardcoded to 3 pairs of stations
  TClonesArray* hitsFirstStationPair = fFootMuSiHit.begin()->second;
  TClonesArray* hitsSecondStationPair = std::next(fFootMuSiHit.begin())->second;
  TClonesArray* hitsThirdStationPair = std::next(fFootMuSiHit.begin(), 2)->second;
  LOG(INFO) << "First stations pair name is " << fFootMuSiHit.begin()->first << FairLogger::endl;
  LOG(INFO) << "Second stations pair name is " << std::next(fFootMuSiHit.begin())->first << FairLogger::endl;
  LOG(INFO) << "Third stations pair name is" << std::next(fFootMuSiHit.begin(), 2)->first << FairLogger::endl;
  for (int iHitFirstPair = 0; iHitFirstPair < hitsFirstStationPair->GetEntriesFast(); ++iHitFirstPair)
  {
        ERFootMuSiHit* hitFirstPair = (ERFootMuSiHit*)hitsFirstStationPair->At(iHitFirstPair);
    for (int iHitSecondPair = 0; iHitSecondPair < hitsSecondStationPair->GetEntriesFast(); ++iHitSecondPair)
    {
        ERFootMuSiHit* hitSecondPair = (ERFootMuSiHit*)hitsSecondStationPair->At(iHitSecondPair);
        TVector3 vectorFirstPairX = hitFirstPair->GetXStationHit();
        TVector3 vectorFirstPairY = hitFirstPair->GetYStationHit();
        TVector3 vectorSecondPairX = hitSecondPair->GetXStationHit();
        TVector3 vectorSecondPairY = hitSecondPair->GetYStationHit();
        const Double_t kxFirst = (vectorSecondPairX.X() - vectorFirstPairX.X())/(vectorSecondPairX.Z()-vectorFirstPairX.Z());
        const Double_t bxFirst = (vectorFirstPairX.X() + vectorSecondPairX.X() - kxFirst*(vectorFirstPairX.Z()+vectorSecondPairX.Z()))/2; 

        vectorFirstPairY.SetX(kxFirst*vectorFirstPairY.Z()+bxFirst);
        vectorSecondPairY.SetX(kxFirst*vectorSecondPairY.Z()+bxFirst);
        TVector3 firstSegment = vectorSecondPairY - vectorFirstPairY;
      for (int iHitThirdPair = 0; iHitThirdPair < hitsThirdStationPair->GetEntriesFast(); ++iHitThirdPair)
      {
        ERFootMuSiHit* hitThirdPair = (ERFootMuSiHit*)hitsThirdStationPair->At(iHitThirdPair);
        TVector3 vectorThirdPairX = hitThirdPair->GetXStationHit();
        TVector3 vectorThirdPairY = hitThirdPair->GetYStationHit();

        const Double_t kxSecond = (vectorThirdPairX.X()-vectorSecondPairX.X())/(vectorThirdPairX.Z()-vectorSecondPairX.Z());
        const Double_t bxSecond = (vectorSecondPairX.X() + vectorThirdPairX.X() - kxSecond*(vectorSecondPairX.Z()+vectorThirdPairX.Z()))/2;
        vectorThirdPairY.SetX(kxSecond*vectorThirdPairY.Z() + bxSecond);
        TVector3 secondSegment = vectorThirdPairY - vectorSecondPairY;
        if (secondSegment.Angle(firstSegment) < fAngleBetweenHitsCut) {
            ERFootMuSiTrack* track = AddTrack(vectorFirstPairY,vectorSecondPairY,vectorThirdPairY);
            track->SetAnglesWithInitialP(secondSegment.Angle(firstSegment),0.);
        }
// Let's implement a new condition getting rid of fake hits and other unwanted hits, by continuing the momentum from the initial protons and comparing the angle between this prolonged tracks and hits 
        if(isProtonDebug)
        {
          TVector3 p1FirstSegmentComparison = p1Xp1YHits[1] - p1Xp1YHits[0];
          TVector3 p1SecondSegmentComparison = p1Xp1YHits[2] - p1Xp1YHits[1];
          Double_t p1FirstAngleComparison = p1FirstSegmentComparison.Angle(firstSegment);
          Double_t p1SecondAngleComparison = p1SecondSegmentComparison.Angle(secondSegment);
          TVector3 p2FirstSegmentComparison = p2Xp2YHits[1] - p2Xp2YHits[0];
          TVector3 p2SecondSegmentComparison = p2Xp2YHits[2] - p2Xp2YHits[1];
          Double_t p2FirstAngleComparison = p2FirstSegmentComparison.Angle(firstSegment);
          Double_t p2SecondAngleComparison = p2SecondSegmentComparison.Angle(secondSegment);
          if ( secondSegment.Angle(firstSegment) < fAngleBetweenHitsCut && p1FirstAngleComparison < 0.035 && p2FirstAngleComparison < 0.035)
          {
            ERFootMuSiTrack* track = AddTrack(vectorFirstPairY,vectorSecondPairY,vectorThirdPairY);
            track->SetFirstHitRefIndex(hitFirstPair->GetRefIndex());
            track->SetSecondHitRefIndex(hitSecondPair->GetRefIndex());
            track->SetThirdHitRefIndex(hitThirdPair->GetRefIndex());
            track->SetAnglesWithInitialP(p1FirstAngleComparison,p1SecondAngleComparison);
          }
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
  // Let's remove calculation of an unknown coordinate here, so we can use the projection later, when we have multiple pairs of stations
  const bool xStationIsClosest = fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel) < fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel);
  // We know all about z coordinate, so
  const double z1 = xStationIsClosest
    ? fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel)
    : fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel);
  const double z2 = xStationIsClosest
    ? fFootMuSiSetup->GetStripGlobalZ(yDigiBranchName, yChannel)
    : fFootMuSiSetup->GetStripGlobalZ(xDigiBranchName, xChannel);
  double x1 = 0.,y1 = 0., x2 = 0., y2 = 0.;  
  if (xStationIsClosest)
  { 
/*     TVector3 xDetectorGlobalHit = GetGlobalHitPositionByStrip(xDigiBranchName, xChannel);
    TVector3 yDetectorGlobalHit = GetGlobalHitPositionByStrip(yDigiBranchName, yChannel); */

/*     x1 = xDetectorGlobalHit.X();
    y1 = xDetectorGlobalHit.Y();
    x2 = yDetectorGlobalHit.X();
    y2 = yDetectorGlobalHit.Y(); */
    x1 = fFootMuSiSetup->GetStripGlobalX(xDigiBranchName, xChannel);
/*     y1 = fFootMuSiSetup->GetStripGlobalY(xDigiBranchName, xChannel);
    x2 = fFootMuSiSetup->GetStripGlobalX(yDigiBranchName, yChannel); */
    y2 = fFootMuSiSetup->GetStripGlobalY(yDigiBranchName, yChannel);

  }
  else
  { 
/*     TVector3 xDetectorGlobalHit = GetGlobalHitPositionByStrip(xDigiBranchName, xChannel);
    TVector3 yDetectorGlobalHit = GetGlobalHitPositionByStrip(yDigiBranchName, yChannel); */
/*     x1 = yDetectorGlobalHit.X();
    y1 = yDetectorGlobalHit.Y();
    x2 = xDetectorGlobalHit.X();
    y2 = xDetectorGlobalHit.Y(); */
/*     x1 = fFootMuSiSetup->GetStripGlobalX(yDigiBranchName, yChannel); */
    y1 = fFootMuSiSetup->GetStripGlobalY(yDigiBranchName, yChannel);
    x2 = fFootMuSiSetup->GetStripGlobalX(xDigiBranchName, xChannel);
/*     y2 = fFootMuSiSetup->GetStripGlobalY(xDigiBranchName, xChannel); */
  }
  const TVector3& xStationHit = xStationIsClosest ? TVector3(x1, y1, z1) : TVector3(x2, y2, z2);
  const TVector3& yStationHit = xStationIsClosest ? TVector3(x2, y2, z2) : TVector3(x1, y1, z1);
  const TVector3& xStationLocalHit = fFootMuSiSetup->ToStationCoordinateSystem(xDigiBranchName, xStationHit);
  const TVector3& yStationLocalHit = fFootMuSiSetup->ToStationCoordinateSystem(yDigiBranchName, yStationHit);
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] X Station Vertex (" << xStationHit.x() << " " << xStationHit.y()
    << " " << xStationHit.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Y Station Vertex (" << yStationHit.x() << " " << yStationHit.y()
    << " " << yStationHit.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] X Station Vertex in station CS (" << xStationLocalHit.x() << " " << xStationLocalHit.y()
    << " " << xStationLocalHit.z() << ")" << FairLogger::endl;
  LOG(DEBUG) << "[ERFootMuSiTrackFinder] Y Station Vertex in station CS (" << yStationLocalHit.x() << " " << yStationLocalHit.y()
    << " " << yStationLocalHit.z() << ")" << FairLogger::endl;
  ERFootMuSiHit* hit = AddHit(xStationHit, yStationHit,
    xStationLocalHit, yStationLocalHit, xChannel, yChannel, xEdep, yEdep,
    hitBranchName);
}
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
   if(fFootMuSiTrack)
  {
    fFootMuSiTrack->Delete();
  } 
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiHit* ERFootMuSiTrackFinder::AddHit(
  const TVector3& xStationHit, const TVector3& yStationHit,
  const TVector3& xStationLocalHit, const TVector3& yStationLocalHit,
  const Int_t xChannel, const Int_t yChannel, const Double_t xEdep, const Double_t yEdep,
  const TString& digiBranchName)
{
  return new ((*fFootMuSiHit[digiBranchName])[fFootMuSiHit[digiBranchName]->GetEntriesFast()])
    ERFootMuSiHit(xStationHit, yStationHit, xStationLocalHit,
      yStationLocalHit, xChannel, yChannel, xEdep, yEdep);
}
//--------------------------------------------------------------------------------------------------
/* ERFootMuSiTrack* ERFootMuSiTrackFinder::AddTrack(ERFootMuSiHit* firstHit,ERFootMuSiHit* secondHit,ERFootMuSiHit* thirdHit,Double_t hitsFitChi2)
{
  return new ((*fFootMuSiTrack)[fFootMuSiTrack->GetEntriesFast()])
    ERFootMuSiTrack(firstHit, secondHit, thirdHit,hitsFitChi2);
} */
//--------------------------------------------------------------------------------------------------
ERFootMuSiTrack* ERFootMuSiTrackFinder::AddTrack(const TVector3& firstHit, const TVector3& secondHit, const TVector3& thirdHit)
{
  return new ((*fFootMuSiTrack)[fFootMuSiTrack->GetEntriesFast()])
    ERFootMuSiTrack(firstHit,secondHit,thirdHit);
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiTrackFinder)

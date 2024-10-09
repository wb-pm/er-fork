/* December 21, 2021 at 1:06 PM

Arbitrary model of eloss and time errors in telescopes */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERFootMuSiDigitizer.h"

#include "TVector3.h"
#include "TGeoMatrix.h"
#include "TMath.h"
#include "TRandom3.h"

#include "FairRootManager.h"
#include "FairRuntimeDb.h"
#include "FairLink.h"
#include "FairLogger.h"

#include "ERDetectorList.h"
#include "ERPoint.h"

//-------------------------------------------------------------------------------------------------
ERFootMuSiDigitizer::ERFootMuSiDigitizer()
  : ERDigitizer("ER FootMuSi digitization")
{
  fAvailibleRunManagers.push_back("ERRunSim");
  fAvailibleRunManagers.push_back("ERRunAna");
}
//-------------------------------------------------------------------------------------------------
ERFootMuSiDigitizer::ERFootMuSiDigitizer(Int_t verbose)
  : ERDigitizer("ER FootMuSi digitization ", verbose)
{
  fAvailibleRunManagers.push_back("ERRunSim");
  fAvailibleRunManagers.push_back("ERRunAna");
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSiDigitizer::SetSiElossSigma(float sigma) { 
  fSiElossModel = [sigma](float eloss) { return gRandom->Gaus(eloss, sigma);};
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSiDigitizer::SetSiTimeSigma(float sigma) {
  fSiTimeModel = [sigma](float time) { return gRandom->Gaus(time, sigma);};
}
//-------------------------------------------------------------------------------------------------
InitStatus ERFootMuSiDigitizer::Init() {
  if (ERTask::Init() != kSUCCESS)
    return kFATAL;
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");

  TList* allbrNames = ioman->GetBranchNameList();
  TIter nextBranch(allbrNames);
  TObjString* bName;
  std::vector<TString> pointBranches;
  while (bName = (TObjString*)nextBranch()) {
    TString bFullName = bName->GetString();
    LOG(DEBUG) << "Branch full name " << bFullName << FairLogger::endl;
    if (bFullName.Contains("Point") && bFullName.Contains("FootMuSi")) {
      // Rename input point branches to output digi branches by changing class name prefix
      // ERDetectorPoint_sensitiveVolNameNumber -> ERDetectorDigi_sensitiveVolNameNumber
      // In map of output collections first parameter is full input branch name without class prefix 
      Int_t bPrefixNameLength = bFullName.First('_');
      TString brName(bFullName(bPrefixNameLength + 1, bFullName.Length()));
      fQFootMuSiPoints[brName] = (TClonesArray*) ioman->GetObject(bFullName);
      TString bPrefixName(bFullName(0, bPrefixNameLength));
      bPrefixName.Replace(bPrefixNameLength - 5, bPrefixNameLength, "Digi");
      TString outBrName =  bPrefixName + "_" + brName;
      fFootMuSiDigi[brName] = new TClonesArray("ERDigi", consts::approx_telescope_digi_number);
      LOG(DEBUG) << "Branch name " << brName << FairLogger::endl;
      ioman->Register(outBrName, "FootMuSi", fFootMuSiDigi[brName], kTRUE);
    }
  }
  return kSUCCESS;
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSiDigitizer::Exec(Option_t* opt) {
  Reset();
  for (const auto &itPointBranches : fQFootMuSiPoints) {
    LOG(DEBUG) << "Number of points in " << itPointBranches.first << " is = " << itPointBranches.second->GetEntriesFast() << FairLogger::endl;
    Double_t  elossThreshold, timeThreshold;
    Double_t  elossSigma, timeSigma;
    std::map<Int_t, std::vector<Int_t>> sortedPoints;
    std::function<float(float)> calc_eloss_with_error;
    std::function<float(float)> calc_time_with_error;
    if (itPointBranches.first.Contains("Si")) {
      elossThreshold = fSiElossThreshold;
      calc_eloss_with_error = fSiElossModel;
      calc_time_with_error = fSiTimeModel;
    }
    for (Int_t iPoint = 0; iPoint < itPointBranches.second->GetEntriesFast(); iPoint++){
      ERPoint* point = (ERPoint*)(itPointBranches.second->At(iPoint));
      sortedPoints[point->GetVolNb()].push_back(iPoint);
    }
    for (const auto &itPoint : sortedPoints) {
      Float_t   edep = 0.; //sum edep a in strip
      Float_t   time = std::numeric_limits<float>::max(); // min time in strip
      for (const auto itPointsForCurrentVolume : itPoint.second) {
        const auto* point = (ERPoint*)(itPointBranches.second->At(itPointsForCurrentVolume));
        edep += point->GetEnergyLoss();
        if (point->GetTime() < time) {
          time = point->GetTime();
        }
      }
      if (edep == 0) {  // if no points in input branch
        continue;
      }
      edep = calc_eloss_with_error(edep);
      if (edep < elossThreshold)
        continue;
      time = calc_time_with_error(time);
      auto* digi = AddDigi(edep, time, itPoint.first, itPointBranches.first);
      //for (const auto itPointsForCurrentVolume : itPoint.second) {
      //  digi->AddLink(FairLink("ERPoint", itPointsForCurrentVolume));
      //}
    }
  }
  /*@TODO: This functionality can be transferred to ERDigitizer if the information 
  about the conformity of the trigger station and the digi collection moves there.*/
  for ( const auto &itDigiBranch : fFootMuSiDigi ) {
    TString branchName = itDigiBranch.first;
    TClonesArray* digiCol = itDigiBranch.second;
    for ( const auto &trigger : fTriggers) {
      TString triggerStation = trigger.first;
      if (branchName.Contains(triggerStation)){
        LOG(DEBUG) << "Apply trigger to station " << triggerStation << FairLogger::endl;
        ApplyTrigger(triggerStation,digiCol);
      }
    }
  }
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSiDigitizer::Reset() {
  for (const auto itDigiBranches : fFootMuSiDigi) {
    if (itDigiBranches.second) {
      itDigiBranches.second->Delete();
    }
  }
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSiDigitizer::Finish(){   
}
//-------------------------------------------------------------------------------------------------
ERDigi* ERFootMuSiDigitizer::AddDigi(Float_t edep, Double_t time, Int_t stripNb,
                                       TString digiBranchName) {
  ERDigi *digi = new((*fFootMuSiDigi[digiBranchName])
      [fFootMuSiDigi[digiBranchName]->GetEntriesFast()]) ERDigi(edep, time, stripNb);
  return digi;
}
//-------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiDigitizer)

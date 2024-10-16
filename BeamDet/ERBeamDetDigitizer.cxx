/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERBeamDetDigitizer.h"

#include "TVector3.h"
#include "TGeoMatrix.h"
#include "TMath.h"
#include "TRandom3.h"

#include "FairRootManager.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include "ERBeamDetSetup.h"
#include "ERDetectorList.h"
#include "ERSupport.h"

using namespace std;

//--------------------------------------------------------------------------------------------------
ERBeamDetDigitizer::ERBeamDetDigitizer()
  : ERDigitizer("ER beamdet digitization")
{}
//--------------------------------------------------------------------------------------------------
ERBeamDetDigitizer::ERBeamDetDigitizer(Int_t verbose)
  : ERDigitizer("ER beamdet digitization ", verbose)
{}
//--------------------------------------------------------------------------------------------------
InitStatus ERBeamDetDigitizer::Init() {
  if (ERTask::Init() != kSUCCESS)
    return kFATAL;
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman) Fatal("Init", "No FairRootManager");
  fBeamDetToFPoints = (TClonesArray*) ioman->GetObject("BeamDetToFPoint");
  fBeamDetMWPCPoints = (TClonesArray*) ioman->GetObject("BeamDetMWPCPoint");
  if (!fBeamDetToFPoints)
    Fatal("Init", "Can`t find collection BeamDetToFPoint!"); 
  if (!fBeamDetMWPCPoints)
    Fatal("Init", "Can`t find collection BeamDetMWPCPoint!"); 
  // Register output arrays
  fBeamDetToFDigi1 = new TClonesArray("ERDigi", consts::approx_beamdet_tof_digi_number);
  fBeamDetToFDigi2 = new TClonesArray("ERDigi", consts::approx_beamdet_tof_digi_number);
  fBeamDetMWPCDigiX1 = new TClonesArray("ERDigi", consts::approx_beamdet_mwpc_digi_number);
  fBeamDetMWPCDigiX2 = new TClonesArray("ERDigi", consts::approx_beamdet_mwpc_digi_number);
  fBeamDetMWPCDigiY1 = new TClonesArray("ERDigi", consts::approx_beamdet_mwpc_digi_number);
  fBeamDetMWPCDigiY2 = new TClonesArray("ERDigi", consts::approx_beamdet_mwpc_digi_number);
  ioman->Register("BeamDetToFDigi1", "BeamDetToF Digi", fBeamDetToFDigi1, kTRUE /*write to output*/);
  ioman->Register("BeamDetToFDigi2", "BeamDetToF Digi", fBeamDetToFDigi2, kTRUE);
  ioman->Register("BeamDetMWPCDigiX1", "BeamDetMWPC x1 Digi", fBeamDetMWPCDigiX1, kTRUE);
  ioman->Register("BeamDetMWPCDigiX2", "BeamDetMWPC x2 Digi", fBeamDetMWPCDigiX2, kTRUE);
  ioman->Register("BeamDetMWPCDigiY1", "BeamDetMWPC y1 Digi", fBeamDetMWPCDigiY1, kTRUE);
  ioman->Register("BeamDetMWPCDigiY2", "BeamDetMWPC y2 Digi", fBeamDetMWPCDigiY2, kTRUE);
  return kSUCCESS;
}
//--------------------------------------------------------------------------------------------------
void ERBeamDetDigitizer::Exec(Option_t* opt) {
  Reset();
  map<Int_t, vector<Int_t>> pointsToF;
  for (Int_t iPoint = 0; iPoint < fBeamDetToFPoints->GetEntriesFast(); iPoint++){
    ERBeamDetTOFPoint* point = (ERBeamDetTOFPoint*)fBeamDetToFPoints->At(iPoint);
    pointsToF[point->GetToFNb()].push_back(iPoint);
  }
  map<Int_t, vector<Int_t> >::iterator  itPlate;
  vector<Int_t>::iterator               itToFPoint;
  for(itPlate = pointsToF.begin(); itPlate != pointsToF.end(); ++itPlate){
    Float_t edep = 0.; //sum edep in plate
    Float_t time = numeric_limits<float>::max(); // min time in plate
    for (itToFPoint = itPlate->second.begin(); itToFPoint != itPlate->second.end(); ++itToFPoint){
      ERBeamDetTOFPoint* point = (ERBeamDetTOFPoint*)(fBeamDetToFPoints->At(*itToFPoint));
      edep += point->GetEnergyLoss();

      if (point->GetTime() < time){
        time = point->GetTime();
      }
    }
    if(fSigmaEOverEToFIsSet) {
      fElossSigmaToF = edep * fElossSigmaOverElossToF / TMath::Sqrt(edep);
    }
    edep = gRandom->Gaus(edep, fElossSigmaToF);
    if (edep < fToFElossThreshold)
      continue;
    time = gRandom->Gaus(time, fTimeSigmaToF);
    ERDigi *digi = AddToFDigi(edep, time, itPlate->first);
    itToFPoint = itPlate->second.begin();
    //for (; itToFPoint != itPlate->second.end(); ++itToFPoint){
    //  digi->AddLink(FairLink("BeamDetToFPoint", *itToFPoint));
    //}
  }
   //Sort the MWPCpoints by MWPC, planes and wires
  map<Int_t, map<Int_t, map<Int_t, vector<Int_t>>>> points;
  for (Int_t iPoint = 0; iPoint < fBeamDetMWPCPoints->GetEntriesFast(); iPoint++){
    auto* point = dynamic_cast<ERBeamDetMWPCPoint*>(fBeamDetMWPCPoints->At(iPoint));
    points[point->GetMWPCNb()][point->GetPlaneNb()][point->GetWireNb()].push_back(iPoint);
  }
  for (auto& mwpc_points : points) {
    const auto mwpc_nb = mwpc_points.first; 
    for (auto& plane_points : mwpc_points.second) {
      const auto plane_nb = plane_points.first;
      for(auto& wire_points : plane_points.second) {
        const auto wire_nb = wire_points.first;
        float edep = 0.; //sum edep in wire
        float time = numeric_limits<float>::max(); // min time in wire
        for (auto& point_nb : wire_points.second) {
          auto* point = dynamic_cast<ERBeamDetMWPCPoint*>(fBeamDetMWPCPoints->At(point_nb));
          edep += point->GetEnergyLoss();
          if (point->GetTime() < time){
            time = point->GetTime();
          }
        }
        edep = gRandom->Gaus(edep, fElossSigmaMWPC);
        if (edep < fMWPCElossThreshold)
          continue;
        time = gRandom->Gaus(time, fTimeSigmaMWPC);
        ERDigi *digi = AddMWPCDigi(edep, time, mwpc_nb, plane_nb, static_cast<ERChannel>(wire_nb));
        //for (auto tMWPCPoint = itWire->second.begin(); itMWPCPoint != itWire->second.end(); ++itMWPCPoint){
        //  digi->AddLink(FairLink("BeamDetMWPCPoint", *itMWPCPoint));
        //}
      }
    }
  }
  /*@TODO: This functionality can be transferred to ERDigitizer if the information 
  about the conformity of the trigger station and the digi collection moves there.*/
  ERBeamDetSetup* setup = ERBeamDetSetup::Instance();
  ApplyTrigger(setup->GetToFType(0),fBeamDetToFDigi1);
  ApplyTrigger(setup->GetToFType(1),fBeamDetToFDigi2);
}
//--------------------------------------------------------------------------------------------------
void ERBeamDetDigitizer::Reset() {
  for (auto* collection : {fBeamDetMWPCDigiX1, fBeamDetMWPCDigiX2, 
                          fBeamDetMWPCDigiY1, fBeamDetMWPCDigiY2,
                          fBeamDetToFDigi1, fBeamDetToFDigi2}) {
    if (collection)
      collection->Delete();
  }
}
//--------------------------------------------------------------------------------------------------
ERDigi* ERBeamDetDigitizer::AddMWPCDigi(float edep, float time, Int_t mwpcNb, 
                                        Int_t planeNb, ERChannel wireNb) {
  ERDigi *digi;
  if(mwpcNb == 1) {
    if(planeNb == 1) {
      digi = new((*fBeamDetMWPCDigiX1)[fBeamDetMWPCDigiX1->GetEntriesFast()])
          ERDigi(edep, time, wireNb);
    } else {
      digi = new((*fBeamDetMWPCDigiY1)[fBeamDetMWPCDigiY1->GetEntriesFast()])
          ERDigi(edep, time, wireNb);
    }
  }
  if(mwpcNb == 2) {
    if(planeNb == 1) {
      digi = new((*fBeamDetMWPCDigiX2)[fBeamDetMWPCDigiX2->GetEntriesFast()])
             ERDigi(edep, time, wireNb);
    } else {
      digi = new((*fBeamDetMWPCDigiY2)[fBeamDetMWPCDigiY2->GetEntriesFast()])
             ERDigi(edep, time, wireNb);
    }
  }
  return digi;
}
//--------------------------------------------------------------------------------------------------
ERDigi* ERBeamDetDigitizer::AddToFDigi(float edep, float time, int tofNb) {
  ERDigi *digi; 
  if(tofNb == 1) {
    digi = new((*fBeamDetToFDigi1)[fBeamDetToFDigi1->GetEntriesFast()])
        ERDigi(edep, time, 0);
  }
  if(tofNb == 2) {
    digi = new((*fBeamDetToFDigi2)[fBeamDetToFDigi2->GetEntriesFast()])
        ERDigi(edep, time, 0);
  }
  return digi;
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERBeamDetDigitizer)

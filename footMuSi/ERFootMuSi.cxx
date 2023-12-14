/* February 11, 2021 at 11:31 AM

Small refactoring in BeamDet and work with capacities of TClonesArrays */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERFootMuSi.h"

#include "TClonesArray.h"
#include "TParticle.h"
#include "TVirtualMC.h"
#include "TString.h"

#include "FairRootManager.h"
#include "FairRun.h"
#include "FairRunSim.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include "ERFootMuSiGeoComponentSensitive.h"
#include "ERPoint.h"
//-------------------------------------------------------------------------------------------------
ERFootMuSi::ERFootMuSi() :
  ERDetector("ERFootMuSi", kTRUE)
{
  ResetParameters();
  flGeoPar = new TList();
  flGeoPar->SetName( GetName());
  fFootMuSiSetup = ERFootMuSiSetup::Instance();
  fVerboseLevel = 1;
  fVersion = 1;
}
//-------------------------------------------------------------------------------------------------
ERFootMuSi::ERFootMuSi(const char* name, Bool_t active, Int_t verbose)
  : ERDetector(name, active,1)
{
  ResetParameters();
  flGeoPar = new TList();
  flGeoPar->SetName( GetName());
  fFootMuSiSetup = ERFootMuSiSetup::Instance();
  fVersion = 1;
  fVerboseLevel = verbose;
}
//-------------------------------------------------------------------------------------------------
ERFootMuSi::~ERFootMuSi() {
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::Initialize() {
  FairDetector::Initialize();
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::AddPoint(TClonesArray& clref) {
  TGeoHMatrix matrix;
  gMC->GetTransformation(gMC->CurrentVolPath(), matrix);
  Double_t globalPos[3],localPos[3];
  fPosIn.Vect().GetXYZ(globalPos);
  matrix.MasterToLocal(globalPos,localPos);
  TVector3 pos_in_local_cs;
  pos_in_local_cs.SetXYZ(localPos[0],localPos[1],localPos[2]);
  new(clref[clref.GetEntriesFast()]) ERPoint(
    fEventID, fTrackID, fMot0TrackID, fChannel, fMass,
    TVector3(fPosIn.X(),   fPosIn.Y(),  fPosIn.Z()),
    pos_in_local_cs,
    TVector3(fPosOut.X(),  fPosOut.Y(),  fPosOut.Z()),
    TVector3(fMomIn.Px(),  fMomIn.Py(),  fMomIn.Pz()),
    TVector3(fMomOut.Px(), fMomOut.Py(), fMomOut.Pz()),
    fTime, fTime, fLength, fEloss, -1 /*light yield*/,fPDG, -1 /*charge*/);
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::ConstructGeometry() {
  fFootMuSiSetup->ConstructGeometry();
  SetGeometryFileName(fFootMuSiSetup->GetGeoFileName());
  ConstructRootGeometry();
}
//-------------------------------------------------------------------------------------------------
Bool_t ERFootMuSi::ProcessHits(FairVolume* vol) {
  if ( gMC->IsTrackEntering() ) { // Return true if this is the first step of the track in the current volume
    fEloss  = 0.;
    fEventID = gMC->CurrentEvent();
    gMC->TrackPosition(fPosIn);
    gMC->TrackMomentum(fMomIn);
    fTrackID  = gMC->GetStack()->GetCurrentTrackNumber();
    fTime   = gMC->TrackTime() * 1.0e09;  // Return the current time of flight of the track being transported
    fLength = gMC->TrackLength(); // Return the length of the current track from its origin (in cm)
    fMot0TrackID  = gMC->GetStack()->GetCurrentTrack()->GetMother(0);
    fMass = gMC->ParticleMass(gMC->TrackPid()) * 1000; // MeV
    fPDG = gMC->TrackPid();
  }
  fEloss += gMC->Edep() * 1000.; // MeV //Return the energy lost in the current step
  if ((gMC->IsTrackExiting()    || //Return true if this is the last step of the track in the current volume
       gMC->IsTrackStop()       || //Return true if the track energy has fallen below the threshold
       gMC->IsTrackDisappeared()) && fEloss > 0.) {
    gMC->TrackPosition(fPosOut);
    gMC->TrackMomentum(fMomOut);
    const TString path = gMC->CurrentVolPath();
    const auto* component = dynamic_cast<ERFootMuSiGeoComponentSensitive*>(fFootMuSiSetup->GetComponent(path));
    if (!component)
      LOG(FATAL) << "[ERFootMuSi] Not found setup component for sensitive volume path" 
                  << path << FairLogger::endl;
    for (const auto orientation : component->GetOrientationsAroundZ()) {
      for (const auto channelSide : component->GetChannelSides()) {
        fChannel = component->GetChannelFromSensitiveNodePath(path, orientation);
        TClonesArray* pointCollection = 
            fPoints[component->GetVolumeName()][component->GetBranchName(ERDataObjectType::Point, orientation, channelSide)];
        AddPoint(*pointCollection);
      }
    }
  }
  return kTRUE;
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::BeginEvent() {
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::EndOfEvent() {
  if (fVerboseLevel > 1) {
    Print();
  }
  Reset();
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::Register() {
  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman)
    Fatal("Init", "IO manager is not set");
  for (const auto* component : fFootMuSiSetup->GetAllComponents()) {
    if (!dynamic_cast<const ERFootMuSiGeoComponentSensitive*>(component))
      continue;
    for (const auto branchName : component->GetBranchNames(ERDataObjectType::Point)) {
      LOG(DEBUG) << "[ERFootMuSi] Register branch " << branchName 
                 << " for component " << component->GetVolumeName() << FairLogger::endl;
      fPoints[component->GetVolumeName()][branchName] = 
          new TClonesArray("ERPoint", consts::approx_telescope_point_number);
      ioman->Register(branchName, "FootMuSi", fPoints[component->GetVolumeName()][branchName], kTRUE);
    }
  }
}
//-------------------------------------------------------------------------------------------------
TClonesArray* ERFootMuSi::GetCollection(Int_t iColl) const {
 /* if (iColl == 0)
    return fSiPoint;
  if (iColl == 0)
    return fCsIPoint;
*/
  return NULL;
}
//-------------------------------------------------------------------------------------------------
//TODO Add Print Implementation for points
void ERFootMuSi::Print(Option_t *option) const {
  LOG(DEBUG) << "======== Si Points ==================" << FairLogger::endl;
  for (auto& componentPoints : fPoints) {
    for (auto& branchPoints : componentPoints.second){
      ERPoint* point = (ERPoint*)branchPoints.second;
      point->Print();
      }
    }
  }
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::Reset() {
  for(auto& componentPoints : fPoints) {
    for (auto& branchPoints : componentPoints.second) {
      branchPoints.second->Clear();
    }
  }
  ResetParameters();
}
//-------------------------------------------------------------------------------------------------
//TODO Add CopyClones Implementation
void ERFootMuSi::CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset) {
/*  LOG(INFO) << "   ERFootMuSi::CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset)"
            << FairLogger::endl;
  Int_t nEntries = cl1->GetEntriesFast();
  LOG(INFO) << "QFootMuSi: " << nEntries << " entries to add" << FairLogger::endl;
  TClonesArray& clref = *cl2;
  ERFootMuSiSiPoint* oldpoint = NULL;
  for (Int_t i=0; i<nEntries; i++) {
  oldpoint = (ERFootMuSiSiPoint*) cl1->At(i);
   Int_t index = oldpoint->GetTrackID() + offset;
   oldpoint->SetTrackID(index);
   new (clref[cl2->GetEntriesFast()]) ERFootMuSiSiPoint(*oldpoint);
  }
  LOG(INFO) << "decector: " << cl2->GetEntriesFast() << " merged entries" << FairLogger::endl;
*/
}
//-------------------------------------------------------------------------------------------------
Bool_t ERFootMuSi::CheckIfSensitive(std::string name) {
  TString volName = name;
  if(volName.BeginsWith("Sensitive")) {
    return kTRUE;
  }
  return kFALSE;
}
//-------------------------------------------------------------------------------------------------
void ERFootMuSi::ResetParameters() {
};
//-------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSi)


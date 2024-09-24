/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/


#include "ERALPIDE.h"

#include "TVirtualMC.h"

#include "ERALPIDEGeoPar.h"






//--------------------------------------------------------------------------------------------------
ERALPIDE::ERALPIDE():
    ERDetector("ERALPIDE",kTRUE),
    fALPIDEPoints(new TClonesArray("ERALPIDEPoint")),
    fALPIDESteps(new TClonesArray("ERALPIDEStep")),
    fStoreSteps(kFALSE)
   {
    flGeoPar = new TList();
    flGeoPar->SetName (GetName()); 
    fVerboseLevel = 1;
   } 
//--------------------------------------------------------------------------------------------------
ERALPIDE::ERALPIDE(const char* name, Bool_t active, Int_t verbose):
    ERDetector(name,active),
    fALPIDEPoints(new TClonesArray("ERALPIDEPoint")),
    fALPIDESteps(new TClonesArray("ERALPIDEStep")),
    fStoreSteps(kFALSE)
   {
    flGeoPar = new TList();
    flGeoPar->SetName (GetName()); 
    fVerboseLevel = verbose;
   } 
//--------------------------------------------------------------------------------------------------
ERALPIDE::~ERALPIDE() {
  if (fALPIDEPoints) {
    fALPIDEPoints->Delete();
    delete fALPIDEPoints;
  }
  if (fALPIDESteps){
    fALPIDESteps->Delete();
    delete fALPIDESteps;
  }
}
//--------------------------------------------------------------------------------------------------
TClonesArray* ERALPIDE::GetCollection(Int_t iColl) const {
  if (iColl == 0) 
    return fALPIDEPoints;
  else 
    return NULL;
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::Initialize() {
  FairDetector::Initialize();
  FairRuntimeDb* rtdb = FairRun::Instance()->GetRuntimeDb();
  ERALPIDEGeoPar* par = (ERALPIDEGeoPar*)(rtdb->getContainer("ERALPIDEGeoPar"));
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::Register() {
  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman)
    LOG(FATAL) << "IO manager is not set" << FairLogger::endl;
  fMCTracks = (TClonesArray*) ioman->GetObject("MCTrack");
  ioman->Register("ALPIDEPoint","ERALPIDE", fALPIDEPoints, kTRUE);
  ioman->Register("ALPIDEStep","ERALPIDE", fALPIDESteps, kTRUE);
}
//--------------------------------------------------------------------------------------------------
Bool_t ERALPIDE::ProcessHits(FairVolume* vol) {
  //Start point
  if ( gMC->IsTrackEntering() ) { // Return true if this is the first step of the track in sensitive volume
    StartPoint();
  }

  if (fStoreSteps) {
    AddStep();
    return kTRUE;
  }
  fELoss += gMC->Edep() * 1e3; // MeV //Return the energy lost in the current step
  
  //Finish point
  if (gMC->IsTrackExiting() || gMC->IsTrackStop() || gMC->IsTrackDisappeared()) { 
    FinishPoint();
  }
  fStepNr++;
}

//--------------------------------------------------------------------------------------------------

void ERALPIDE::StartPoint() {
  fELoss  = 0.;
  fEventID = gMC->CurrentEvent();

  TLorentzVector pos, mom;

  gMC->TrackPosition(pos);
  gMC->TrackMomentum(mom);
  fPosIn = pos.Vect();
  fMomIn = mom.Vect();

  fTrackID  = gMC->GetStack()->GetCurrentTrackNumber();

  fTime   = gMC->TrackTime() * 1.0e09;// Return the current time track being transported
  fLength = gMC->TrackLength(); // Return the length of the current track from its origin (in cm)
  //fMot0TrackID  = gMC->GetStack()->GetCurrentTrack()->GetMother(0);
  fMass = gMC->ParticleMass(gMC->TrackPid()); // GeV/c2

  fPDG = gMC->TrackPid();
  fStepNr = 0;
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::FinishPoint() {
  TLorentzVector pos, mom;

  gMC->TrackPosition(pos);
  gMC->TrackMomentum(mom);
  fPosOut = pos.Vect();
  fMomOut = mom.Vect();

  if (fELoss > 0.){
      AddALPIDEPoint();
  }
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::EndOfEvent() {
  if (fVerboseLevel > 1) {
    Print();
  }

  Reset();
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::Print(Option_t *option) const {
  if (fALPIDEPoints->GetEntriesFast() > 0){
    LOG(INFO) << "======== ALPIDE Points ==================" << FairLogger::endl;
    for (Int_t i_point = 0; i_point < fALPIDEPoints->GetEntriesFast(); i_point++){
      ERALPIDEPoint* point = (ERALPIDEPoint*)fALPIDEPoints->At(i_point);
      point->Print();
    }
  }
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::Reset() {
  fALPIDEPoints->Clear();
  fALPIDESteps->Clear();
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset) {
  Int_t nEntries = cl1->GetEntriesFast();
  LOG(DEBUG) << "ERALPIDE: " << nEntries << " entries to add" << FairLogger::endl;
  TClonesArray& clref = *cl2;
  ERALPIDEPoint* oldpoint = NULL;
  for (Int_t i=0; i<nEntries; i++) {
  oldpoint = (ERALPIDEPoint*) cl1->At(i);
   Int_t index = oldpoint->GetTrackID() + offset;
   oldpoint->SetTrackID(index);
   new (clref[cl2->GetEntriesFast()]) ERALPIDEPoint(*oldpoint);
  }
  LOG(DEBUG) << "ERALPIDE: " << cl2->GetEntriesFast() << " merged entries" << FairLogger::endl;
}
//--------------------------------------------------------------------------------------------------
ERALPIDEPoint* ERALPIDE::AddALPIDEPoint() {
  TClonesArray& clref = *fALPIDEPoints;
  Int_t size = clref.GetEntriesFast();
  return new(clref[size]) ERALPIDEPoint(fEventID, fTrackID,  fMass,
              TVector3(fPosIn.X(),  fPosIn.Y(), fPosIn.Z()),
              TVector3(fPosOut.X(), fPosOut.Y(), fPosOut.Z()),
              TVector3(fMomIn.Px(), fMomIn.Py(), fMomIn.Pz()),
              TVector3(fMomOut.Px(), fMomOut.Py(), fMomOut.Pz()),
              fTime, fLength, fELoss, fPDG, fPixelNo);
}
//--------------------------------------------------------------------------------------------------
ERALPIDEStep* ERALPIDE::AddStep(){
  
  TClonesArray& clref = *fALPIDESteps;
  //Fill step info
  ExpertTrackingStatus trackStatus = ERALPIDEStep::GetTrackStatus();
  TArrayI processesID;
  gMC->StepProcesses(processesID);
  TLorentzVector curPosIn;
  TLorentzVector curMomIn;
  gMC->TrackPosition(curPosIn);
  gMC->TrackMomentum(curMomIn);


  return new(clref[fALPIDESteps->GetEntriesFast()]) 
                                      ERALPIDEStep(fEventID, fStepNr, fTrackID, 0,
                                      TVector3(curPosIn.X(),   curPosIn.Y(),   curPosIn.Z()),
                                      TVector3(curMomIn.X(),   curMomIn.Y(),   curMomIn.Z()),  
                                      gMC->TrackTime() * 1.0e09, gMC->TrackStep(), gMC->TrackPid(),
                                      fMass,trackStatus,gMC->Edep(),gMC->TrackCharge(),processesID);                                  
}
//--------------------------------------------------------------------------------------------------
void ERALPIDE::ConstructGeometry() {
  TString fileName = GetGeometryFileName();
  if(fileName.EndsWith(".root")) {
    LOG(DEBUG) << "Constructing ALPIDE geometry from ROOT file " << fileName.Data() << FairLogger::endl;
    ConstructRootGeometry();
  } else {
    LOG(FATAL) << "Geometry file name is not set!" << FairLogger::endl;
  }
  
}
//--------------------------------------------------------------------------------------------------
Bool_t ERALPIDE::CheckIfSensitive(std::string name) {
  TString volName = name;
  if(volName.Contains("SiliconPlate")) {
    return kTRUE;
  }
  return kFALSE;
}

//--------------------------------------------------------------------------------------------------
ClassImp(ERALPIDE)
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/


#include "ERAlpide.h"

#include "TVirtualMC.h"

#include "ERAlpideGeoPar.h"






 //--------------------------------------------------------------------------------------------------
ERAlpide::ERAlpide() :
  ERDetector("ERAlpide", kTRUE),
  fAlpidePoints(new TClonesArray("ERAlpidePoint")),
  fAlpideSteps(new TClonesArray("ERAlpideStep")),
  fStoreSteps(kFALSE)
{
  flGeoPar = new TList();
  flGeoPar->SetName(GetName());
  fVerboseLevel = 1;
}
//--------------------------------------------------------------------------------------------------
ERAlpide::ERAlpide(const char* name, Bool_t active, Int_t verbose) :
  ERDetector(name, active),
  fAlpidePoints(new TClonesArray("ERAlpidePoint")),
  fAlpideSteps(new TClonesArray("ERAlpideStep")),
  fStoreSteps(kFALSE)
{
  flGeoPar = new TList();
  flGeoPar->SetName(GetName());
  fVerboseLevel = verbose;
}
//--------------------------------------------------------------------------------------------------
ERAlpide::~ERAlpide() {
  if (fAlpidePoints) {
    fAlpidePoints->Delete();
    delete fAlpidePoints;
  }
  if (fAlpideSteps) {
    fAlpideSteps->Delete();
    delete fAlpideSteps;
  }
}
//--------------------------------------------------------------------------------------------------
TClonesArray* ERAlpide::GetCollection(Int_t iColl) const {
  if (iColl == 0)
    return fAlpidePoints;
  else
    return NULL;
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::Initialize() {
  FairDetector::Initialize();
  FairRuntimeDb* rtdb = FairRun::Instance()->GetRuntimeDb();
  ERAlpideGeoPar* par = (ERAlpideGeoPar*)(rtdb->getContainer("ERAlpideGeoPar"));
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::Register() {
  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman)
    LOG(FATAL) << "IO manager is not set" << FairLogger::endl;
  fMCTracks = (TClonesArray*)ioman->GetObject("MCTrack");
  ioman->Register("AlpidePoint", "ERAlpide", fAlpidePoints, kTRUE);
  ioman->Register("AlpideStep", "ERAlpide", fAlpideSteps, kTRUE);
}
//--------------------------------------------------------------------------------------------------
Bool_t ERAlpide::ProcessHits(FairVolume* vol) {
  static Int_t          eventID;           //!  event index
  static Int_t          trackID;           //!  track index
  static Int_t          mot0TrackID;       //!  0th mother track index
  static Double_t       mass;              //!  mass
  static TLorentzVector posIn, posOut;    //!  position
  static TLorentzVector momIn, momOut;    //!  momentum
  static Double32_t     time;              //!  time
  static Double32_t     length;            //!  length
  static Double32_t     eLoss;             //!  energy loss
  static Int_t          pdg;                //! particle ID
  static Int_t pixelNoX;                                       ///< number of entrance pixel along x axis 
  static Int_t pixelNoY;                                       ///< number of entrance pixel along y axis
  static Int_t pixelNoX_out;                                       ///< number of exit pixel along x axis 
  static Int_t pixelNoY_out;                                       ///< number of exit pixel along y axis

  static Int_t stepNumber;

  const Double_t plateXlength = 10.; ///< size of carbon plate along X axis
  const Double_t plateYlength = 10.; ///< size of carbon plate along Y axis
  const Double_t pixelXlength = 10. / (6. * 512.); ///<size of one pixel along X axis
  const Double_t pixelYlength = 10. / (6. * 1024.); ///<size of one pixel along Y axis
  //Start point
  if (gMC->IsTrackEntering()) { // Return true if this is the first step of the track in sensitive volume
    eLoss = 0.;
    eventID = gMC->CurrentEvent();

    gMC->TrackPosition(posIn);
    gMC->TrackMomentum(momIn);
    pixelNoX = Int_t((posIn.X() + plateXlength / 2) / pixelXlength);
    pixelNoY = Int_t((posIn.Y() + plateYlength / 2) / pixelYlength);
    trackID = gMC->GetStack()->GetCurrentTrackNumber();

    time = gMC->TrackTime() * 1.0e09;// Return the current time track being transported
    length = gMC->TrackLength(); // Return the length of the current track from its origin (in cm)
    mot0TrackID = gMC->GetStack()->GetCurrentTrack()->GetMother(0);
    mass = gMC->ParticleMass(gMC->TrackPid()); // GeV/c2
    LOG(INFO) << "mother id " << mot0TrackID << ", mass " << mass << FairLogger::endl;

    pdg = gMC->TrackPid();
    stepNumber = 0;
  }
  if (fStoreSteps) {
    static TLorentzVector posStep, momStep;
    static ExpertTrackingStatus trackStatus;
    static TArrayI processesID;
    static Int_t pixelNoXStep, pixelNoYStep;
    pixelNoXStep = Int_t((posStep.X() + plateXlength / 2) / pixelXlength);
    pixelNoYStep = Int_t((posStep.Y() + plateYlength / 2) / pixelYlength);

    gMC->TrackPosition(posStep);
    gMC->TrackMomentum(momStep);
    trackStatus = ERAlpideStep::GetTrackStatus();
    gMC->StepProcesses(processesID);
    ERAlpideStep* AlpideStep = AddAlpideStep(eventID, stepNumber, trackID, TVector3(posStep.X(), posStep.Y(), posStep.Z()), TVector3(momStep.X(), momStep.Y(), momStep.Z()), pixelNoXStep, pixelNoYStep, gMC->TrackTime() * 1e9, gMC->TrackStep(), gMC->TrackPid(), gMC->TrackMass(), trackStatus, gMC->Edep()*1e3, gMC->TrackCharge(), processesID);
    if (fVerboseLevel > 1) AlpideStep->Print();

  }
  eLoss += gMC->Edep() * 1e3; // MeV //Return the energy lost in the current step
  stepNumber++;

  //Finish point
  if (gMC->IsTrackExiting() || gMC->IsTrackStop() || gMC->IsTrackDisappeared()) {
    //LOG(DEBUG) << "Current volume of the point is" << gMC->CurrentVolName() << FairLogger::endl;
    gMC->TrackPosition(posOut);
    gMC->TrackMomentum(momOut);
    pixelNoX_out = Int_t((posOut.X() + plateXlength / 2) / pixelXlength);
    pixelNoY_out = Int_t((posOut.Y() + plateYlength / 2) / pixelYlength);
    if (eLoss > 0.) {
      AddAlpidePoint(eventID, trackID, gMC->GetStack()->GetCurrentTrack()->GetMother(0), gMC->TrackMass(),
        TVector3(posIn.X(), posIn.Y(), posIn.Z()),
        TVector3(posOut.X(), posOut.Y(), posOut.Z()),
        TVector3(momIn.Px(), momIn.Py(), momIn.Pz()),
        TVector3(momOut.Px(), momOut.Py(), momOut.Pz()),
        time, length, eLoss, pdg, pixelNoX, pixelNoY, pixelNoX_out, pixelNoY_out);
    }
  }
  return kTRUE;
}

//--------------------------------------------------------------------------------------------------
void ERAlpide::EndOfEvent() {
  if (fVerboseLevel > 1) {
    Print();
  }

  Reset();
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::Print(Option_t* option) const {
  if (fAlpidePoints->GetEntriesFast() > 0) {
    LOG(INFO) << "======== Alpide Points ==================" << FairLogger::endl;
    for (Int_t i_point = 0; i_point < fAlpidePoints->GetEntriesFast(); i_point++) {
      ERAlpidePoint* point = (ERAlpidePoint*)fAlpidePoints->At(i_point);
      point->Print();
    }
  }
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::Reset() {
  fAlpidePoints->Clear();
  fAlpideSteps->Clear();
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset) {
  Int_t nEntries = cl1->GetEntriesFast();
  LOG(DEBUG) << "ERAlpide: " << nEntries << " entries to add" << FairLogger::endl;
  TClonesArray& clref = *cl2;
  ERAlpidePoint* oldpoint = NULL;
  for (Int_t i = 0; i < nEntries; i++) {
    oldpoint = (ERAlpidePoint*)cl1->At(i);
    Int_t index = oldpoint->GetTrackID() + offset;
    oldpoint->SetTrackID(index);
    new (clref[cl2->GetEntriesFast()]) ERAlpidePoint(*oldpoint);
  }
  LOG(DEBUG) << "ERAlpide: " << cl2->GetEntriesFast() << " merged entries" << FairLogger::endl;
}
//--------------------------------------------------------------------------------------------------
ERAlpidePoint* ERAlpide::AddAlpidePoint(Int_t eventID, Int_t trackID, Int_t mot0TrackID, Double_t mass,
  const TVector3& posIn,
  const TVector3& posOut,
  const TVector3& momIn,
  const TVector3& momOut,
  Double_t time, Double_t length, Double_t eLoss, Int_t PDG, Int_t pixelNoX, Int_t pixelNoY, Int_t pixelNoX_out, Int_t pixelNoY_out) {
  TClonesArray& clref = *fAlpidePoints;
  Int_t size = clref.GetEntriesFast();
  return new(clref[size]) ERAlpidePoint(eventID, trackID, mot0TrackID, mass,
    TVector3(posIn.X(), posIn.Y(), posIn.Z()),
    TVector3(posOut.X(), posOut.Y(), posOut.Z()),
    TVector3(momIn.Px(), momIn.Py(), momIn.Pz()),
    TVector3(momOut.Px(), momOut.Py(), momOut.Pz()),
    time, length, eLoss, PDG, pixelNoX, pixelNoY, pixelNoX_out, pixelNoY_out);
}
//--------------------------------------------------------------------------------------------------
ERAlpideStep* ERAlpide::AddAlpideStep(Int_t eventID, Int_t stepNr, Int_t trackID,
  TVector3 pos,
  TVector3 mom,
  Int_t pixelNoX,
  Int_t pixelNoY,
  Double_t tof,
  Double_t length,
  Int_t pid,
  Double_t mass,
  ExpertTrackingStatus trackStatus,
  Double_t eLoss,
  Double_t charge,
  TArrayI  processID) {

  TClonesArray& clref = *fAlpideSteps;

  return new(clref[fAlpideSteps->GetEntriesFast()])
    ERAlpideStep(eventID, stepNr, trackID,
      pos,
      mom,
      pixelNoX,
      pixelNoY,
      tof,
      length,
      pid,
      mass,
      trackStatus,
      eLoss,
      charge,
      processID);
}
//--------------------------------------------------------------------------------------------------
void ERAlpide::ConstructGeometry() {
  TString fileName = GetGeometryFileName();
  if (fileName.EndsWith(".root")) {
    LOG(DEBUG) << "Constructing Alpide geometry from ROOT file " << fileName.Data() << FairLogger::endl;
    ConstructRootGeometry();
  }
  else {
    LOG(FATAL) << "Geometry file name is not set!" << FairLogger::endl;
  }

}
//--------------------------------------------------------------------------------------------------
Bool_t ERAlpide::CheckIfSensitive(std::string name) {
  TString volName = name;
  if (volName.Contains("SiliconPlate")) {
    return kTRUE;
  }
  return kFALSE;
}

//--------------------------------------------------------------------------------------------------
ClassImp(ERAlpide)
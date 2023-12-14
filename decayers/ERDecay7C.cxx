/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERDecay7C.h"

#include "TVirtualMC.h"

#include "FairRunSim.h"
#include "FairLogger.h"
#include "FairMCEventHeader.h"

#include "G4IonTable.hh"
#include "ERDecayMCEventHeader.h"
#include "ERDecay7CEventHeader.h"

ERDecay7C::ERDecay7C():
  ERDecay("7C"),
  fTargetDecayFinish(kFALSE),
  fTargetReactZ(0.),
  fMinStep(0.01),
  f9C(NULL),
  f7C(NULL),
  f3He(NULL),
  fp  (NULL),
  fDecayFilePath(""),
  fDecayFileFinished(kFALSE),
  fDecayFileCurrentEvent(0)
{
  FairRunSim* run = FairRunSim::Instance();
  fIon3He = new FairIon("3He",2,3,2, 0., 2.808391);
  fUnstableIon7C = new FairIon("7C",  6, 7, 6, 0.,TDatabasePDG::Instance()->GetParticle("proton")->Mass()*4 + fIon3He->GetMass());
  std::cout << fUnstableIon7C->GetMass();
  run->AddNewIon(fUnstableIon7C);
  run->AddNewIon(fIon3He);

  fLv7C = new TLorentzVector();
}
//-------------------------------------------------------------------------------------------------
ERDecay7C::~ERDecay7C() {
  if (fDecayFile.is_open())
    fDecayFile.close();
  if (fDecayFilePath == ""){ // LV from TGenPhaseSpace will be deleted in TGenPhaseSpace
    if (fLv3He){
      delete fLv3He;
      delete fLvp1;
      delete fLvp2;
      delete fLvp3;
      delete fLvp4;
    }
  }
}

//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::Init() {

  std::cout << "Decayer Init." << std::endl;

f9C = TDatabasePDG::Instance()->GetParticle("9C");
if ( ! f9C ) {
  std::cerr  << "-W- ERDecay7C: Ion 9C not found in database!" << std::endl;
  return kFALSE;
}

  f7C = TDatabasePDG::Instance()->GetParticle("7C");
  if ( ! f7C ) {
    std::cerr  << "-W- ERDecay7C: Ion 7C not found in database!" << std::endl;
    f7C = TDatabasePDG::Instance()->AddParticle("7C","7C",6.5614830,0,1e-3,21.,"Baryon",1000060070);
    return kTRUE;
  }

  f3He = TDatabasePDG::Instance()->GetParticle(fIon3He->GetName());
  if ( ! f3He ) {
    std::cerr  << "-W- ERDecay7C: Ion 3He not found in database!" << std::endl;
    return kFALSE;
  }

  fp = TDatabasePDG::Instance()->GetParticle("proton");
  if ( ! fp ) {
    std::cerr  << "-W- ERDecay7C: Particle proton not found in database!" << std::endl;
    return kFALSE;
  }

CalculateTargetParameters();

  if (fDecayFilePath != ""){
    LOG(INFO) << "Use decay kinematics from external text file" << FairLogger::endl;
    fDecayFile.open(fDecayFilePath.Data());
    if (!fDecayFile.is_open())
      LOG(FATAL) << "Can`t open decay file " << fDecayFilePath << FairLogger::endl;

    fLv3He = new TLorentzVector();
    fLvp1 = new TLorentzVector();
    fLvp2 = new TLorentzVector();
    fLvp3 = new TLorentzVector();
    fLvp4 = new TLorentzVector();
  }

  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::DecayPhaseGenerator() {
  if (fDecayFilePath == ""){
    LOG(ERROR) << "Please enter the decay file name! Decay phase generator is turned off " << FairLogger::endl;
/*     Double_t decayMasses[5];
    decayMasses[0] = f3He->Mass();
    decayMasses[1] = fp->Mass(); 
    decayMasses[2] = fp->Mass();
    decayMasses[3] = fp->Mass(); 
    decayMasses[4] = fp->Mass();
    fDecayPhaseSpace->SetDecay(*fLv7C, 5, decayMasses);
    fDecayPhaseSpace->Generate();
    fLv3He = fDecayPhaseSpace->GetDecay(0);
    fLvp1 = fDecayPhaseSpace->GetDecay(1);
    fLvp2 = fDecayPhaseSpace->GetDecay(2);
    fLvp3 = fDecayPhaseSpace->GetDecay(3);
    fLvp4 = fDecayPhaseSpace->GetDecay(4);
    return kTRUE; */
    return kFALSE;
  }
  if (fDecayFile.eof()){
    LOG(ERROR) << "Decay file finished! There are no more events in file " << fDecayFilePath
               << " to be processed." << FairLogger::endl;
    return kFALSE;
  }
  std::string event_line;
  std::getline(fDecayFile,event_line);
  std::istringstream iss(event_line);
  std::vector<std::string> outputs_components((std::istream_iterator<std::string>(iss)),
                                               std::istream_iterator<std::string>());
  if (outputs_components.size() != 5*3){
    LOG(ERROR) << "Wrong components number in raw in decay file!" << FairLogger::endl;
    return kFALSE;
  }
  // Fill momentum vectors in CM.
  TVector3 p3He(std::stod(outputs_components[0]),std::stod(outputs_components[1]),
               std::stod(outputs_components[2]));
  TVector3 pp1(std::stod(outputs_components[3]),std::stod(outputs_components[4]),
               std::stod(outputs_components[5]));
  TVector3 pp2(std::stod(outputs_components[6]),std::stod(outputs_components[7]),
               std::stod(outputs_components[8]));
  TVector3 pp3(std::stod(outputs_components[9]),std::stod(outputs_components[10]),
               std::stod(outputs_components[11]));
  TVector3 pp4(std::stod(outputs_components[12]),std::stod(outputs_components[13]),
               std::stod(outputs_components[14]));
  // Apply scale factor
  const auto MeV2GeV = 1./1000.;
  p3He *= MeV2GeV;
  pp1 *= MeV2GeV;
  pp2 *= MeV2GeV;
  pp3 *= MeV2GeV;
  pp4 *= MeV2GeV;
  const auto fill_output_lorentz_vectors_in_lab = 
      [this](TLorentzVector* lv, const TVector3& p, const Double_t mass) {
        lv->SetXYZM(p.X(), p.Y(), p.Z(), mass);
        lv->Boost(fLv7C->BoostVector());
      };
  fill_output_lorentz_vectors_in_lab(fLv3He, p3He, f3He->Mass());
  fill_output_lorentz_vectors_in_lab(fLvp1, pp1, fp->Mass());
  fill_output_lorentz_vectors_in_lab(fLvp2, pp2, fp->Mass());
  fill_output_lorentz_vectors_in_lab(fLvp3, pp3, fp->Mass());
  fill_output_lorentz_vectors_in_lab(fLvp4, pp4, fp->Mass());
  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::Stepping() {
  if(!fTargetDecayFinish && gMC->TrackPid() == 1000060090
     && TString(gMC->CurrentVolName()).Contains(GetInteractionVolumeName()))
  {
    if (!fIsInterationPointFound) {
      if (!FindInteractionPoint()) {
        fTargetDecayFinish = kTRUE;
        return kTRUE;
      } else {
        fDistanceFromEntrance = 0;
      }
    }
    gMC->SetMaxStep(fMinStep);
    TLorentzVector curPos;
    gMC->TrackPosition(curPos);
    Double_t trackStep = gMC->TrackStep();
    fDistanceFromEntrance += trackStep;
    if (fDistanceFromEntrance > fDistanceToInteractPoint) {
      std::cout << "Start reaction in target. Defined pos: " << fDistanceToInteractPoint << ", current pos: " << curPos.Z() << std::endl;
      fLv7C->SetXYZM(0.,0.,0.,fUnstableIon7C->GetMass());
      TLorentzVector lv9C;
      gMC->TrackMomentum(lv9C);

      if (lv9C.P() == 0) { // temporary fix of bug with zero kinetic energy
        return kTRUE;
      }

      fLv7C->Boost(lv9C.BoostVector());

      if (!DecayPhaseGenerator()){
        fTargetDecayFinish = kTRUE;
        return kTRUE;
      }

      Int_t C9TrackNb, C7TrackNb, He3TrackNb, p1TrackNb, p2TrackNb, p3TrackNb, p4TrackNb;

      C9TrackNb = gMC->GetStack()->GetCurrentTrackNumber();

      gMC->GetStack()->PushTrack(1, -1, f9C->PdgCode(),
                                 lv9C.Px(), lv9C.Py(), lv9C.Pz(),
                                 lv9C.E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, C9TrackNb, f9C->Mass(), 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, f3He->PdgCode(),
                                 fLv3He->Px(), fLv3He->Py(), fLv3He->Pz(),
                                 fLv3He->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, He3TrackNb, f3He->Mass(), 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
                                 fLvp1->Px(),fLvp1->Py(),fLvp1->Pz(),
                                 fLvp1->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, p1TrackNb, fp->Mass(), 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
                                 fLvp2->Px(),fLvp2->Py(),fLvp2->Pz(),
                                 fLvp2->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, p2TrackNb, fp->Mass(), 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
                                 fLvp3->Px(),fLvp3->Py(),fLvp3->Pz(),
                                 fLvp3->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, p3TrackNb, fp->Mass(), 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
                                 fLvp4->Px(),fLvp4->Py(),fLvp4->Pz(),
                                 fLvp4->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, p4TrackNb, fp->Mass(), 0);
      gMC->StopTrack();
      fTargetDecayFinish = kTRUE;
      gMC->SetMaxStep(100.);

      FairRunSim* run = FairRunSim::Instance();
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")){   
        ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(C9TrackNb);
        header->AddOutputParticle(C9TrackNb);
        header->AddOutputParticle(C7TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(p1TrackNb);
        header->AddOutputParticle(p2TrackNb);
        header->AddOutputParticle(p3TrackNb);
        header->AddOutputParticle(p4TrackNb);
      }   
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecay7CEventHeader")){   
        ERDecay7CEventHeader* header = (ERDecay7CEventHeader*)run->GetMCEventHeader();
        header->SetData(curPos.Vect(), lv9C, *fLv7C,  *fLv3He, *fLvp1, *fLvp2, *fLvp3, *fLvp4, gMC->TrackTime()*1e9);
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(C9TrackNb);
        header->AddOutputParticle(C9TrackNb);
        header->AddOutputParticle(C7TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(p1TrackNb);
        header->AddOutputParticle(p2TrackNb);
        header->AddOutputParticle(p3TrackNb);
        header->AddOutputParticle(p4TrackNb);
        header->SetTrigger(1);
      }
      }
    }
  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
void ERDecay7C::BeginEvent() { 
  fTargetDecayFinish = kFALSE;
  fIsInterationPointFound = kFALSE;
  //Seems like it is not used
  fTargetReactZ = fRnd->Uniform(-fTargetThickness / 2, fTargetThickness / 2);
  FairRunSim* run = FairRunSim::Instance();
}

//-------------------------------------------------------------------------------------------------
void ERDecay7C::FinishEvent() {
  FairRunSim* run = FairRunSim::Instance();
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")){   
    ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecay7CEventHeader")){   
    ERDecay7CEventHeader* header = (ERDecay7CEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
}
ClassImp(ERDecay7C)

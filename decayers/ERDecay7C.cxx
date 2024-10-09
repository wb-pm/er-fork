/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERDecay7C.h"

#include "G4IonTable.hh"

#include "TVirtualMC.h"

#include "FairRunSim.h"
#include "FairLogger.h"
#include "FairMCEventHeader.h"

#include "ERDecayMCEventHeader.h"
#include "ERDecay7CEventHeader.h"

 //Since in the ERDecay7C only masses and pdg codes of ions are being used, this data will be taken from G4IonTable. But G4IonTable gives masses in MeV, so it is important to divide by 1000 for converting to GeV!
 //There is a problem with taking mass from the TDatabasePDG, because it is defined there for atoms and not for ions 

ERDecay7C::ERDecay7C() :
  ERDecay("7C"),
  fTargetDecayFinish(kFALSE),
  fMinStep(0.01),
  f9C(NULL),
  f7C(NULL),
  f3He(NULL),
  fp(NULL),
  fIs7CGaussianExcitation(kFALSE),
  fIs7CUniformExcitation(kFALSE),
  fDecayFilePath(""),
  fDecayFileFinished(kFALSE),
  f7CExcitation(1.),
  fDecayFileExcitation(1.),
  fDecayFileCurrentEvent(0)
{
  fLv7C = new TLorentzVector();
}
//-------------------------------------------------------------------------------------------------
ERDecay7C::~ERDecay7C() {
  if (fDecayFile.is_open())
    fDecayFile.close();
  //TODO: Change the logic of deleting the lorentz vectors
  if (fDecayFilePath == "") {
    if (fLv3He) {
      delete fLv3He;
      delete fLvp1;
      delete fLvp2;
      delete fLvp3;
      delete fLvp4;
      delete fLv7C;
    }
  }
}

//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::Init() {

  LOG(INFO) << "[ERDecay7C] -------------Started--------------" << FairLogger::endl;
  f9C = TDatabasePDG::Instance()->GetParticle("9C");
  if (!f9C) {
    LOG(ERROR) << "Ion 9C not found in database!" << FairLogger::endl;
    return kFALSE;
  }
  LOG(INFO) << "Ion 7C is not in database! Adding the 7C ion..." << FairLogger::endl;
  const Double_t mass7C = G4IonTable::GetIonTable()->GetIonMass(1, 1) * 4 / 1000. + G4IonTable::GetIonTable()->GetIonMass(2, 3) / 1000.;
  f7C = TDatabasePDG::Instance()->AddParticle("7C", "7C", mass7C, 0, 1e-3, 18., "Baryon", 1000060070);
  f7C->Print();

  f3He = TDatabasePDG::Instance()->GetParticle("HE3");
  f3He->Print();
  if (!f3He) {
    LOG(ERROR) << "Ion 3He not found in database!" << FairLogger::endl;
    return kFALSE;
  }

  fp = TDatabasePDG::Instance()->GetParticle("proton");
  fp->Print();
  if (!fp) {
    LOG(ERROR) << "Particle proton not found in database!" << FairLogger::endl;
    return kFALSE;
  }

  CalculateTargetParameters();

  if (fDecayFilePath != "") {
    LOG(INFO) << "Use decay kinematics from external text file" << fDecayFilePath << FairLogger::endl;
    fDecayFile.open(fDecayFilePath.Data());
    if (!fDecayFile.is_open())
      LOG(FATAL) << "Can't open decay file " << fDecayFilePath << FairLogger::endl;
    //Read excitation energy from the file and skip the first lines without momenta components  
    std::string headerLine;
    std::getline(fDecayFile, headerLine);
    if (headerLine.find("Decay Energy") != std::string::npos)
    {
      std::istringstream iss(headerLine);
      std::string tempString;
      iss >> tempString >> tempString >> fDecayFileExcitation;
      if (fDecayFileExcitation < 0) {
        LOG(ERROR) << "Decay energy can't be less than 0" << FairLogger::endl;
        return kFALSE;
      }
      else {
        LOG(WARNING) << "Decay energy is not found in " << fDecayFilePath << ", using the default value of 1 MeV" << FairLogger::endl;
      }
      LOG(INFO) << "Decay energy of 7C = " << fDecayFileExcitation << " MeV" << FairLogger::endl;
    }
    //Ignore the line with masses
    std::getline(fDecayFile, headerLine);
    //Ignore the line with names of momenta components
    std::getline(fDecayFile, headerLine);

    fLv3He = new TLorentzVector();
    fLvp1 = new TLorentzVector();
    fLvp2 = new TLorentzVector();
    fLvp3 = new TLorentzVector();
    fLvp4 = new TLorentzVector();
  }

  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
void ERDecay7C::Print7CExcitation()
{
}
//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::DecayPhaseGenerator() {
  if (fDecayFilePath == "") {
    LOG(ERROR) << "Please enter the decay file name! Decay phase generator is turned off " << FairLogger::endl;
    //Built-in decay phase generator is unreliable, therefore it is not used! 
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
  if (fDecayFile.eof()) {
    LOG(ERROR) << "Decay file finished! There are no more events in file " << fDecayFilePath << " to be processed." << FairLogger::endl;
    return kFALSE;
  }
  std::string event_line;
  std::getline(fDecayFile, event_line);
  std::istringstream iss(event_line);
  std::vector<std::string> outputs_components((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
  const Int_t decayProductsNo = 5;
  const Int_t momentumComponentsNo = 3;
  if (outputs_components.size() != (decayProductsNo * momentumComponentsNo)) {
    LOG(ERROR) << "Wrong number of row values in a decay file!" << fDecayFilePath << FairLogger::endl;
    return kFALSE;
  }
  // Fill decay products momentum vectors in CM.
  TVector3 p3He(std::stod(outputs_components[0]), std::stod(outputs_components[1]), std::stod(outputs_components[2]));

  TVector3 pp1(std::stod(outputs_components[3]), std::stod(outputs_components[4]), std::stod(outputs_components[5]));

  TVector3 pp2(std::stod(outputs_components[6]), std::stod(outputs_components[7]), std::stod(outputs_components[8]));

  TVector3 pp3(std::stod(outputs_components[9]), std::stod(outputs_components[10]), std::stod(outputs_components[11]));

  TVector3 pp4(std::stod(outputs_components[12]), std::stod(outputs_components[13]), std::stod(outputs_components[14]));
  // Apply scale factor
  const auto excitationScale = sqrt(f7CExcitation / fDecayFileExcitation);
  const auto MeV2GeV = 1. / 1000.;
  const auto scale = excitationScale * MeV2GeV;
  p3He *= scale;
  pp1 *= scale;
  pp2 *= scale;
  pp3 *= scale;
  pp4 *= scale;
  const auto fill_output_lorentz_vectors_in_lab =
    [this](TLorentzVector* lv, const TVector3& p, const Double_t mass) {
    lv->SetXYZM(p.X(), p.Y(), p.Z(), mass);
    lv->Boost(fLv7C->BoostVector());
    };
  fill_output_lorentz_vectors_in_lab(fLv3He, p3He, G4IonTable::GetIonTable()->GetIonMass(2, 3) * MeV2GeV);
  fill_output_lorentz_vectors_in_lab(fLvp1, pp1, G4IonTable::GetIonTable()->GetIonMass(1, 1) * MeV2GeV);
  fill_output_lorentz_vectors_in_lab(fLvp2, pp2, G4IonTable::GetIonTable()->GetIonMass(1, 1) * MeV2GeV);
  fill_output_lorentz_vectors_in_lab(fLvp3, pp3, G4IonTable::GetIonTable()->GetIonMass(1, 1) * MeV2GeV);
  fill_output_lorentz_vectors_in_lab(fLvp4, pp4, G4IonTable::GetIonTable()->GetIonMass(1, 1) * MeV2GeV);
  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
Bool_t ERDecay7C::Stepping() {
  if (!fTargetDecayFinish && gMC->TrackPid() == f9C->PdgCode()
    && TString(gMC->CurrentVolName()).Contains(GetInteractionVolumeName()))
  {
    if (!fIsInterationPointFound) {
      if (!FindInteractionPoint()) {
        fTargetDecayFinish = kTRUE;
        return kTRUE;
      }
      else {
        fDistanceFromEntrance = 0;
      }
    }
    gMC->SetMaxStep(fMinStep);
    TLorentzVector curPos;
    gMC->TrackPosition(curPos);
    Double_t trackStep = gMC->TrackStep();
    fDistanceFromEntrance += trackStep;
    if (fDistanceFromEntrance > fDistanceToInteractPoint) {
      LOG(INFO) << "Start reaction in target. Defined pos: " << fDistanceToInteractPoint << ", current pos: " << curPos.Z() << FairLogger::endl;
      TLorentzVector lv9C;
      gMC->TrackMomentum(lv9C);

      //TODO: Figure out why in some events the momentum is 0 
      if (lv9C.P() == 0) { // temporary fix of bug with zero kinetic energy
        return kTRUE;
      }
      if(fIs7CGaussianExcitation)
      {
        LOG(INFO) << "Excitation energy distribution is set to gaussian" << FairLogger::endl;
        f7CExcitation = gRandom->Gaus(f7CGaussianExcitationMean,f7CGaussianExcitationSigma);

      }
      else if(fIs7CUniformExcitation)
      {
        LOG(INFO) << "Excitation energy distribution is set to uniform" << FairLogger::endl;
        f7CExcitation = gRandom->Uniform(f7CUniformExcitationMin,f7CUniformExcitationMax);
      }
      else
      {
        f7CExcitation = 20.;
        LOG(INFO) << "Excitation energy distribution is not set, using the default value of " << f7CExcitation << " MeV" << FairLogger::endl;
      }
      LOG(DEBUG) << "The excitation energy of 7C = " << f7CExcitation << " MeV" << FairLogger::endl;
      fLv7C->SetXYZM(0., 0., 0., f7C->Mass() + f7CExcitation);
      fLv7C->Boost(lv9C.BoostVector());

      if (!DecayPhaseGenerator()) {
        fTargetDecayFinish = kTRUE;
        return kTRUE;
      }

      Int_t C9TrackNb, C7TrackNb, He3TrackNb, p1TrackNb, p2TrackNb, p3TrackNb, p4TrackNb;

      C9TrackNb = gMC->GetStack()->GetCurrentTrackNumber();

      //Create tracks of decay's products
/*       gMC->GetStack()->PushTrack(1, C9TrackNb, f3He->PdgCode(),
        fLv3He->Px(), fLv3He->Py(), fLv3He->Pz(),
        fLv3He->E(), curPos.X(), curPos.Y(), curPos.Z(),
        gMC->TrackTime(), 0., 0., 0.,
        kPDecay, He3TrackNb,1, 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
        fLvp1->Px(), fLvp1->Py(), fLvp1->Pz(),
        fLvp1->E(), curPos.X(), curPos.Y(), curPos.Z(),
        gMC->TrackTime(), 0., 0., 0.,
        kPDecay, p1TrackNb,1, 0); */
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
        fLvp2->Px(), fLvp2->Py(), fLvp2->Pz(),
        fLvp2->E(), curPos.X(), curPos.Y(), curPos.Z(),
        gMC->TrackTime(), 0., 0., 0.,
        kPDecay, p2TrackNb, 1, 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
        fLvp3->Px(), fLvp3->Py(), fLvp3->Pz(),
        fLvp3->E(), curPos.X(), curPos.Y(), curPos.Z(),
        gMC->TrackTime(), 0., 0., 0.,
        kPDecay, p3TrackNb, 1, 0);
      gMC->GetStack()->PushTrack(1, C9TrackNb, fp->PdgCode(),
        fLvp4->Px(), fLvp4->Py(), fLvp4->Pz(),
        fLvp4->E(), curPos.X(), curPos.Y(), curPos.Z(),
        gMC->TrackTime(), 0., 0., 0.,
        kPDecay, p4TrackNb, 1, 0);
      gMC->StopTrack();
      fTargetDecayFinish = kTRUE;
      gMC->SetMaxStep(100.);

      FairRunSim* run = FairRunSim::Instance();
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")) {
        ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(C9TrackNb);
        header->AddOutputParticle(C7TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(p1TrackNb);
        header->AddOutputParticle(p2TrackNb);
        header->AddOutputParticle(p3TrackNb);
        header->AddOutputParticle(p4TrackNb);
      }
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecay7CEventHeader")) {
        ERDecay7CEventHeader* header = (ERDecay7CEventHeader*)run->GetMCEventHeader();
        header->SetData(curPos.Vect(), lv9C, *fLv7C, *fLv3He, *fLvp1, *fLvp2, *fLvp3, *fLvp4, gMC->TrackTime() * 1e9);
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(C9TrackNb);
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
  //fTargetReactZ = fRnd->Uniform(-fTargetThickness / 2, fTargetThickness / 2);
  FairRunSim* run = FairRunSim::Instance();
}

//-------------------------------------------------------------------------------------------------
void ERDecay7C::FinishEvent() {
  FairRunSim* run = FairRunSim::Instance();
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")) {
    ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecay7CEventHeader")) {
    ERDecay7CEventHeader* header = (ERDecay7CEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
}
ClassImp(ERDecay7C)

/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERDecay3Hto3He.h"

#include <iostream>
#include <string>
#include <sstream>

#include "TVirtualMC.h"
#include "TLorentzVector.h"
#include "TMCProcess.h"
#include "TRandom.h"
#include "TVector.h"

#include "FairRunSim.h"
#include "FairLogger.h"

#include "ERDecayMCEventHeader.h"
#include "ER3Hto3HeEventHeader.h"
#include "ERMCEventHeader.h"

using namespace std;

ERDecay3Hto3He::ERDecay3Hto3He():
  ERDecay("3Hto3He"),
  fDecayFinish(kFALSE),
  fTargetReactZ(0.),
  fMinStep(0.01),
  f3H(NULL),
  f1H(NULL),
  fn1(NULL),
  f3He(NULL),
  f3HeMass(0.),
  fReactionHappen(0),
  fADInput(NULL),
  fADFunction(NULL)
{
  fRnd = new TRandom3();
  // fRnd->SetSeed();
  fRnd2 = new TRandom3();
  fRnd2->SetSeed();
  fReactionPhaseSpace = new TGenPhaseSpace();
  FairRunSim* run = FairRunSim::Instance();
//   fUnstableIon10He = new FairIon("10He",  2, 10, 2);
//   // fIon1H        = new FairIon("1H", 1, 1, 1);
//   run->AddNewIon(fUnstableIon10He);
//   // run->AddNewIon(fIon1H);

  fLvN1 = new TLorentzVector();
  fLv3He = new TLorentzVector();
}

// // //-------------------------------------------------------------------------------------------------
ERDecay3Hto3He::~ERDecay3Hto3He() {}
//-------------------------------------------------------------------------------------------------
Bool_t ERDecay3Hto3He::Init() {

  cout << "Decayer Init." << endl;

  f3He = TDatabasePDG::Instance()->GetParticle(1000020030);
  if ( ! f3He ) {
    std::cerr  << "-W- ERDecay3Hto3He: Ion 3He not found in database!" << endl;
    return kFALSE;
  }

  f3H = TDatabasePDG::Instance()->GetParticle("Triton");
  if ( ! f3H ) {
    std::cerr  << "-W- ERDecay3Hto3He: Ion Triton not found in database!" << endl;
    return kFALSE;
  }
  

  fn1 = TDatabasePDG::Instance()->GetParticle("neutron");
  if ( ! fn1 ) {
    std::cerr  << "-W- ERDecay3Hto3He: Particle neutron not found in database!" << endl;
    return kFALSE;
  }
  
  f1H = TDatabasePDG::Instance()->GetParticle("proton");
  if ( ! f1H ) {
    std::cerr  << "-W- ERDecay3Hto3He: Particle proton not found in database!" << endl;
    return kFALSE;
  }
  
  f3HeMass = f3He->Mass(); // if user mass is not defined in ERDecay3Hto3He::SetHe10Mass() than get a GEANT mass
  CalculateTargetParameters();


  printf("\n++++++++++++\nList of particles\n++++++++++++\n");
  f3H->Print();
  printf("mass 3H %f\n",f3H->Mass());
  printf("mass p %f\n",f1H->Mass());
  printf("mass 3He %f\n",f3HeMass);
  printf("mass n %f\n",fn1->Mass());
  f1H->Print();
  f3He->Print();
  fn1->Print();
  
  
    // f6He = TDatabasePDG::Instance()->GetParticle("6He");
  // if ( ! f6He ) {
    // std::cerr  << "-W- ERDecay3Hto3He: Ion 6He not found in database!" << endl;
    // return kFALSE;
  // }
 
  // printf("8He PDG = %i\n",f8He->PdgCode());
    // printf("6He PDG = %i\n",f6He->PdgCode());
  // printf("triton PDG = %i\n",f3H->PdgCode());
  // printf("neutron PDG = %i\n",fn->PdgCode());
  // printf("proton PDG = %i\n",f1H->PdgCode());
 //  printf("10He PDG = %i\n",fUnstableIon10He->PdgCode());
  
  return kTRUE;
}
//-------------------------------------------------------------------------------------------------
Bool_t ERDecay3Hto3He::Stepping() {
  if(!fDecayFinish && gMC->TrackPid() == 1000010030
     && TString(gMC->CurrentVolName()).Contains(GetInteractionVolumeName()))
  {
    if (!fIsInterationPointFound) {
      if (!FindInteractionPoint()) {
        fDecayFinish = kTRUE;
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
      
      
      // 8He + 2H → 3He + 7H
	  // 8He + 3H -> 1H + 10He
      TLorentzVector lv3H;
      gMC->TrackMomentum(lv3H);
      
      if (lv3H.P() == 0) { // temporary fix of bug with zero kinetic energy
        return kTRUE;
      }

      TLorentzVector lv1H(0., 0., 0., f1H->Mass());
      TLorentzVector lvReaction;
      lvReaction = lv3H + lv1H;

      const TVector3 boost = lvReaction.BoostVector(); //Get Pcm 3 vector
      Double_t ECM = 0;
      TLorentzVector lv3HCM, lv1HCM;
      lv3HCM = lv3H;
      lv1HCM = lv1H;
      lv3HCM.Boost(-boost);
      lv1HCM.Boost(-boost);
      ECM = lv3HCM(3) + lv1HCM(3);
      
      Int_t reactionAttempsCounter = 0;
      const auto MeV2GeV = 1./1000.;
      
	
	if((ECM - fn1->Mass() - f3HeMass) > 0) { // выход из цикла while для PhaseGenerator
          fReactionHappen = kTRUE;
          LOG(DEBUG) << "[ERDecay3Hto3He] Reaction is happen" << endl;
    } else { 
        LOG(DEBUG) << "[ERDecay3Hto3He] Reaction didn't happen" << endl;
        return kFALSE;
    }

    ReactionPhaseGenerator(ECM); 
    fLv3He->Boost(boost);
    fLvN1->Boost(boost);
      
  //========================================================================================    

      Int_t H3TrackNb, He3TrackNb,n1TrackNb;

      H3TrackNb = gMC->GetStack()->GetCurrentTrackNumber();

      /*																					//???????????
      gMC->GetStack()->PushTrack(1, He8TrackNb, f7H->PdgCode(),						
                                 fLv7H->Px(), fLv7H->Py(), fLv7H->Pz(),
                                 fLv7H->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, H7TrackNb, decay7HMass, 0);*/
      /*cout<<"**************** ERDecay3Hto3He ******************"<<endl;
      cout<<"gMC->GetStack()->PushTrack(...)"<<endl;
      cout<<"H3TrackNb= "<<H3TrackNb<<endl;
      cout<<"f3He->PdgCode() = "<<f3He->PdgCode()<<endl;
      cout<<"fLv3He->Px() = "<<fLv3He->Px()<<endl;
      cout<<"fLv3He->Py() = "<<fLv3He->Py()<<endl;
      cout<<"fLv3He->Pz() = "<<fLv3He->Pz()<<endl;
      cout<<"fLv3He->E() = "<<fLv3He->E()<<endl;
      cout<<"curPos.X() = "<<curPos.X()<<endl;
      cout<<"curPos.Y() = "<<curPos.Y()<<endl;
      cout<<"curPos.Z() = "<<curPos.Z()<<endl;
      cout<<"gMC->TrackTime() = "<<gMC->TrackTime()<<endl;
      cout<<"kPPrimary = "<<kPPrimary<<endl;
      cout<<"He3TrackNb = "<<He3TrackNb<<endl;
      cout<<"f3He->Mass() = "<<f3He->Mass()<<endl;
      cout<<"******************** end ************************"<<endl;*/

      gMC->GetStack()->PushTrack(1, H3TrackNb, f3He->PdgCode(),
                                 fLv3He->Px(), fLv3He->Py(), fLv3He->Pz(),
                                 fLv3He->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPPrimary, He3TrackNb, f3He->Mass(), 0);
      gMC->GetStack()->PushTrack(1, H3TrackNb, fn1->PdgCode(),
                                 fLvN1->Px(),fLvN1->Py(),fLvN1->Pz(),
                                 fLvN1->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPPrimary, n1TrackNb, fn1->Mass(), 0);
      gMC->StopTrack();
      fDecayFinish = kTRUE;
      gMC->SetMaxStep(100.);

      FairRunSim* run = FairRunSim::Instance();
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")){   
        ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(H3TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(n1TrackNb);
      }   
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ER3Hto3HeEventHeader")){   
        ER3Hto3HeEventHeader* header = (ER3Hto3HeEventHeader*)run->GetMCEventHeader();
        header->SetData(curPos.Vect(), lv3H,  lv1H, *fLvN1, *fLv3He, gMC->TrackTime() * 1e9);
        header->SetReactionPos(curPos.Vect());
        header->SetInputIon(H3TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(n1TrackNb);
        header->SetTrigger(1);
      }
    }
  }
  return kTRUE;
}

//-------------------------------------------------------------------------------------------------
void ERDecay3Hto3He::BeginEvent() { 
fDecayFinish = kFALSE;
  fIsInterationPointFound = kFALSE;
  fTargetReactZ = fRnd->Uniform(-fTargetThickness / 2, fTargetThickness / 2);
  FairRunSim* run = FairRunSim::Instance();
}

//-------------------------------------------------------------------------------------------------
void ERDecay3Hto3He::FinishEvent() {
  FairRunSim* run = FairRunSim::Instance();
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")){   
    ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
  if (TString(run->GetMCEventHeader()->ClassName()).Contains("ER3Hto3HeEventHeader")){   
    ER3Hto3HeEventHeader* header = (ER3Hto3HeEventHeader*)run->GetMCEventHeader();
    header->Clear();
  }
}

//-------------------------------------------------------------------------------------------------
void ERDecay3Hto3He::ReactionPhaseGenerator(Double_t Ecm) {
  Double_t m1 = f3He->Mass();
  Double_t m2 = fn1->Mass();

  // Energy of 1-st particle in cm.
  // total energy of the first particle is calculated as
  Double_t E1 = 0.5 * (Ecm * Ecm + m1 * m1 - m2 * m2) / Ecm;

  //Impulse in CM
  Double_t Pcm = TMath::Sqrt(E1 * E1 - m1 * m1);
  //Generate angles of particles in CM
  Double_t thetaCM;
  if(!fADInput) { // if file with angular distribution isn't setted than isotropic distribution is generated
      thetaCM = TMath::ACos(gRandom->Uniform(-1, 1));
//    thetaCM = TMath::ACos(gRandom->Uniform(-1, -0.965925826));	

    //thetaCM = TMath::ACos(gRandom->Uniform(0.984807753,1));		//вырезаю задние углы для попадания в протонный детектор
  } else { 
    thetaCM = fADFunction->GetRandom(fThetaMin, fThetaMax)*TMath::DegToRad();
  }
  Double_t phi = gRandom->Uniform(0., 2. * TMath::Pi());
  TVector3 Pcmv;
  Pcmv.SetMagThetaPhi(Pcm, thetaCM, phi);

  fLv3He->SetXYZM(0., 0., 0., 0.);
  fLvN1->SetXYZM(0., 0., 0., 0.);
  fLv3He->SetXYZM(Pcmv(0), Pcmv(1), Pcmv(2), m1);
  fLvN1->SetXYZM(-Pcmv(0), -Pcmv(1), -Pcmv(2), m2);
}

//-------------------------------------------------------------------------------------------------
Double_t ERDecay3Hto3He::ADEvaluate(Double_t *x, Double_t *p) {
  if (fADInput->IsZombie()) {
    Error("ERDecay3Hto3He::ADEvaluate", "AD input was not loaded");
    return -1;
  }
  // on each step of creating distribution function returns interpolated value of input data
  return fADInput->Eval(x[0]);
}

//-------------------------------------------------------------------------------------------------
void ERDecay3Hto3He::SetAngularDistribution(TString ADFile) {
  TString ADFilePath = gSystem->Getenv("VMCWORKDIR");
  ADFilePath += "/input/" + ADFile;
  std::ifstream f;
  f.open(ADFilePath.Data());
  if (!f.is_open()) {
    LOG(FATAL) << "Can't open file " << ADFilePath << FairLogger::endl;
  }
  Int_t nPoints = std::count(std::istreambuf_iterator<char>(f),
                              std::istreambuf_iterator<char>(), '\n');
  f.seekg(0, std::ios::beg);
  TVectorD tet(nPoints);
  TVectorD sigma(nPoints);
  LOG(DEBUG2) << "nPoints = " << nPoints << FairLogger::endl;
  Int_t i = 0;
  while (!f.eof()) {
    // Костыль
    if (i == nPoints) break;
    f >> tet(i) >> sigma(i);
    LOG(DEBUG2) << i << ": " << tet(i) << "\t" << sigma(i) << FairLogger::endl;
    i++;
  }
  fADInput = new TGraph(tet, sigma);
  if (fADInput->GetN() <= 0) { //if there are no points in input file
    LOG(INFO) << "ERDecay3Hto3He::SetAngularDistribution: "
              << "Too few inputs for creation of AD function!" << FairLogger::endl;
    return;
  }
  Double_t* angle = fADInput->GetX();  // get first column variables that contains number of point 

  // Creation of angular distribution function using class member function.
  // Constructor divides interval (0; fADInput->GetN()-1) into grid.
  // On each step of grid it calls ADEvaluate() to get interpolated values of input data.
  fThetaMin = angle[0];
  fThetaMax = angle[fADInput->GetN()-1];
  fADFunction = new TF1("angDistr", this, &ERDecay3Hto3He::ADEvaluate, 
                         fThetaMin, fThetaMax, 0, "ERDecay3Hto3He", "ADEvaluate");
  fADFunction->Eval(1.);
}
//-------------------------------------------------------------------------------------------------
// void ERDecay3Hto3He::PrintMass(){
	// printf("\n++++++++++++\nList of particles\n++++++++++++\n");
	// f8He->Print();
	// f10He->Print();
	// f3H->Print();
	// f1H->Print();
	// fn->Print();
	// // return;
// }
//-------------------------------------------------------------------------------------------------
ClassImp(ERDecay3Hto3He)

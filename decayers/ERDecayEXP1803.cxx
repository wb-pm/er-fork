/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERDecayEXP1803.h"

#include <iostream>

#include "TVirtualMC.h"
#include "TLorentzVector.h"
#include "TMCProcess.h"
#include "TRandom.h"

#include "FairRunSim.h"
#include "FairLogger.h"

#include "ERDecayMCEventHeader.h"
#include "ERMCEventHeader.h"

using namespace std;

ERDecayEXP1803::ERDecayEXP1803():
  ERDecay("EXP1803"),
  fDecayFinish(kFALSE),
  fTargetReactZ(0.),
  fMinStep(0.01),
  f6He(NULL),
  f2H (NULL),
  f3He(NULL),
  f5H (NULL),
  f3H (NULL),
  fn  (NULL),
  fIon3He(NULL),
  f5HMass(0.),
  fIs5HUserMassSet(false),
  fIs5HExcitationSet(false)
{
  fRnd = new TRandom3();
  fReactionPhaseSpace = new TGenPhaseSpace();
  fDecayPhaseSpace = new TGenPhaseSpace();
  FairRunSim* run = FairRunSim::Instance();
  fUnstableIon5H = new FairIon("5H",  1, 5, 1);
  fIon3He                = new FairIon("3He", 2, 3, 2);
  run->AddNewIon(fUnstableIon5H);
  run->AddNewIon(fIon3He);
}
//-------------------------------------------------------------------------------------------------
ERDecayEXP1803::~ERDecayEXP1803() {
}
//-------------------------------------------------------------------------------------------------
void ERDecayEXP1803::SetH5Exitation(Double_t excMean, Double_t fwhm, Double_t distibWeight) {
  f5HExcitationMean.push_back(excMean);
  f5HExcitationSigma.push_back(fwhm / 2.355);
  if (!fIs5HExcitationSet) {
    f5HExcitationWeight.push_back(distibWeight);    
    fIs5HExcitationSet = true;
    return ;
  }
  f5HExcitationWeight.push_back(f5HExcitationWeight.back() + distibWeight);
}
//-------------------------------------------------------------------------------------------------
Bool_t ERDecayEXP1803::Init(){
  f6He = TDatabasePDG::Instance()->GetParticle("6He");
  if ( ! f6He ) {
    std::cerr  << "-W- ERDecayEXP1803: Ion 6He not found in database!" << endl;
    return kFALSE;
  }

  f2H = TDatabasePDG::Instance()->GetParticle("Deuteron");
  if ( ! f2H ) {
    std::cerr  << "-W- ERDecayEXP1803: Ion Deuteron not found in database!" << endl;
    return kFALSE;
  }

  f5H = TDatabasePDG::Instance()->GetParticle("5H");
  if ( ! f5H ) {
    std::cerr  << "-W- ERDecayEXP1803: Ion 5H not found in database!" << endl;
    return kFALSE;
  }

  f3He = TDatabasePDG::Instance()->GetParticle(fIon3He->GetName());
  if ( ! f3He ) {
    std::cerr  << "-W- ERDecayEXP1803: Ion 3He not found in database!" << endl;
    return kFALSE;
  }

  f3H = TDatabasePDG::Instance()->GetParticle("Triton");
  if ( ! f3H ) {
    std::cerr  << "-W- ERDecayEXP1803: Ion Triton not found in database!" << endl;
    return kFALSE;
  }

  fn = TDatabasePDG::Instance()->GetParticle("neutron");
  if ( ! fn ) {
    std::cerr  << "-W- ERDecayEXP1803: Particle neutron not found in database!" << endl;
    return kFALSE;
  }

  return kTRUE;
}
//-------------------------------------------------------------------------------------------------
Bool_t ERDecayEXP1803::Stepping() {
  if(!fDecayFinish && gMC->TrackPid() == 1000020060 && TString(gMC->CurrentVolName()).Contains(fVolumeName)){
    gMC->SetMaxStep(fMinStep);
    TLorentzVector curPos;
    gMC->TrackPosition(curPos);
    if (curPos.Z() > fTargetReactZ){
      // std::cout << "Start reation in target. Defined pos: " << fTargetReactZ << ", current pos: " << curPos.Z() << endl;
      // 6He + 2H → 3He + 5H
      TLorentzVector lv6He;
      gMC->TrackMomentum(lv6He);
      cout << "He6 momentum " << lv6He.Px() << " " << lv6He.Py() << " " << lv6He.Pz() << endl; 

      TLorentzVector lv2H(0., 0., 0., f2H->Mass());
      cout << "H2 momentum " << lv2H.Px() << " " << lv2H.Py() << " " << lv2H.Pz() << endl; 
      TLorentzVector lvReaction;
      lvReaction = lv6He + lv2H;
      cout << "lvReaction momentum" << lvReaction.Px() << " " << lvReaction.Py() << " " << lvReaction.Pz() << endl; 

      Double_t mass5H = (fIs5HUserMassSet) ? f5HMass : f5H->Mass();
      Double_t exc = 0;
      if (fIs5HExcitationSet) {
        Double_t randWeight = gRandom->Uniform(0., f5HExcitationWeight.back());
        Int_t distribNum = 0;
        for (; distribNum < f5HExcitationWeight.size(); distribNum++) {
          if (randWeight < f5HExcitationWeight[distribNum]) {
            break;
          }
        }
        exc = gRandom->Gaus(f5HExcitationMean[distribNum], f5HExcitationSigma[distribNum]);
        fUnstableIon5H->SetExcEnergy(exc);
      }
      mass5H += exc;
      cout  << "exc 123 " << exc << endl;
      LOG(DEBUG) << "Ion H5 mass in reaction " << mass5H << FairLogger::endl;

      Double_t reactMasses[2];
      reactMasses[0] = f3He->Mass();
      cout << "H3 mass " << reactMasses[0] << endl;
      reactMasses[1] = mass5H;
      cout << "mass5H mass " << reactMasses[1] << endl;
     
      cout << "reaction decay momentum" << lvReaction.Px() << " " << lvReaction.Py() << " " << lvReaction.Pz() << endl; 

      fReactionPhaseSpace->SetDecay(lvReaction, 2, reactMasses);
      fReactionPhaseSpace->Generate();

      TLorentzVector *lv3He = fReactionPhaseSpace->GetDecay(0);
      cout << "h3 decay momentum " << lv3He->Px() << " " << lv3He->Py() << " " << lv3He->Pz() << endl; 
      TLorentzVector *lv5H  = fReactionPhaseSpace->GetDecay(1);
      cout << "H5 decay momentum " << lv5H->Px() << " " << lv5H->Py() << " " << lv5H->Pz() << endl; 
      //5H → f3H + n +n.
      Double_t decayMasses[3];
      decayMasses[0] = f3H->Mass();
      decayMasses[1] = fn->Mass(); 
      decayMasses[2] = fn->Mass();

      fDecayPhaseSpace->SetDecay(*lv5H, 3, decayMasses);
      fDecayPhaseSpace->Generate();

      TLorentzVector *lv3H = fDecayPhaseSpace->GetDecay(0);
      TLorentzVector *lvn1 = fDecayPhaseSpace->GetDecay(1);
      TLorentzVector *lvn2 = fDecayPhaseSpace->GetDecay(2);


      Int_t He6TrackNb, H5TrackNb, He3TrackNb, H3TrackNb, n1TrackNb, n2TrackNb;

      He6TrackNb = gMC->GetStack()->GetCurrentTrackNumber();

      cout << "h5 pdg " << f5H->PdgCode() << endl;
      gMC->GetStack()->PushTrack(1, He6TrackNb, f5H->PdgCode(),
                                 lv5H->Px(),lv5H->Py(),lv5H->Pz(),
                                 lv5H->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, H5TrackNb, mass5H, 0);
      gMC->GetStack()->PushTrack(1, He6TrackNb, f3He->PdgCode(),
                                 lv3He->Px(),lv3He->Py(),lv3He->Pz(),
                                 lv3He->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, He3TrackNb, f3He->Mass(), 0);
      gMC->GetStack()->PushTrack(1, He6TrackNb, f3H->PdgCode(),
                                 lv3H->Px(),lv3H->Py(),lv3H->Pz(),
                                 lv3H->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, H3TrackNb, f3H->Mass(), 0);
      gMC->GetStack()->PushTrack(1, He6TrackNb, fn->PdgCode(),
                                 lvn1->Px(),lvn1->Py(),lvn1->Pz(),
                                 lvn1->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, n1TrackNb, fn->Mass(), 0);
      gMC->GetStack()->PushTrack(1, He6TrackNb, fn->PdgCode(),
                                 lvn2->Px(),lvn2->Py(),lvn2->Pz(),
                                 lvn2->E(), curPos.X(), curPos.Y(), curPos.Z(),
                                 gMC->TrackTime(), 0., 0., 0.,
                                 kPDecay, n2TrackNb, fn->Mass(), 0);
      LOG(INFO) << He6TrackNb << " " << H5TrackNb << " " << He3TrackNb << FairLogger::endl;
      gMC->StopTrack();
      fDecayFinish = kTRUE;
      gMC->SetMaxStep(100.);

      FairRunSim* run = FairRunSim::Instance();
      if (TString(run->GetMCEventHeader()->ClassName()).Contains("ERDecayMCEventHeader")){   
        ERDecayMCEventHeader* header = (ERDecayMCEventHeader*)run->GetMCEventHeader();
        header->SetDecayPos(curPos.Vect());
        header->SetInputIon(He6TrackNb);
        header->AddOutputParticle(H5TrackNb);
        header->AddOutputParticle(He3TrackNb);
        header->AddOutputParticle(H3TrackNb);
        header->AddOutputParticle(n1TrackNb);
        header->AddOutputParticle(n2TrackNb);
      }
    }
  }
  return kTRUE;
}
//-------------------------------------------------------------------------------------------------
void ERDecayEXP1803::BeginEvent() { 
  fDecayFinish = kFALSE;
  fTargetReactZ = fRnd->Uniform(-fTargetThickness / 2, fTargetThickness / 2);
  FairRunSim* run = FairRunSim::Instance();
}
//-------------------------------------------------------------------------------------------------
void ERDecayEXP1803::FinishEvent() {
}
//-------------------------------------------------------------------------------------------------
ClassImp(ERDecayEXP1803)

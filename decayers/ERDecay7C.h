/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERDECAY7C_H
#define ERDECAY7C_H

#include <vector>
#include <fstream>

#include "TGraph.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TRandom2.h"
#include "TLorentzVector.h"

#include "FairIon.h"

#include "ERDecay.h"

class ERDecay7C : public ERDecay {

public:
  ERDecay7C();
  ~ERDecay7C();

/*Modifiers*/

  void SetMinStep(Double_t minStep) {fMinStep = minStep;}
  void SetDecayFile(const TString& filePath){ fDecayFilePath = filePath; }
  void SetTargetThickness(Double_t targetThickness) {fTargetThickness = targetThickness;}

public:
  Bool_t Init();
  Bool_t Stepping();

  void BeginEvent();
  void FinishEvent();

  Bool_t DecayPhaseGenerator();

private:

  TParticlePDG   *f9C;
  TParticlePDG   *f7C;
  TParticlePDG   *f3He;
  TParticlePDG   *fp;

  TLorentzVector *fLv7C; //!
  TLorentzVector *fLv3He; //!
  TLorentzVector *fLvp1; //!
  TLorentzVector *fLvp2; //!
  TLorentzVector *fLvp3; //!
  TLorentzVector *fLvp4; //!

  FairIon        *fUnstableIon7C;
  FairIon        *fIon3He;

  Double_t         fTargetReactZ;
  Double_t         fMinStep;
  Double_t         fTargetThickness;
  Bool_t           fTargetDecayFinish;

  TString         fDecayFilePath;
  Bool_t          fDecayFileFinished;
  Int_t           fDecayFileCurrentEvent;
  std::ifstream   fDecayFile;

  ClassDef(ERDecay7C,1)
};

#endif

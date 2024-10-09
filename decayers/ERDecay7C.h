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
  void Set7CGaussianExcitation(Double_t excitationMean, Double_t excitationSigma)
  {
    f7CGaussianExcitationMean = excitationMean;
    f7CGaussianExcitationSigma = excitationSigma;
    fIs7CGaussianExcitation = kTRUE;
  }
  void Set7CUniformExcitation(Double_t excitationMin, Double_t excitationMax)
  {
    f7CUniformExcitationMin = excitationMin;
    f7CUniformExcitationMax = excitationMax;
    fIs7CUniformExcitation = kTRUE;
  }

  void Print7CExcitation();

public:
  Bool_t Init();
  Bool_t Stepping();

  void BeginEvent();
  void FinishEvent();

  Bool_t DecayPhaseGenerator();

private:
  //Particles identification numbers
  TParticlePDG   *f9C;
  TParticlePDG   *f7C;
  TParticlePDG   *f3He;
  TParticlePDG   *fp;

  //Lorentz vectors
  TLorentzVector *fLv7C; //!
  TLorentzVector *fLv3He; //!
  TLorentzVector *fLvp1; //!
  TLorentzVector *fLvp2; //!
  TLorentzVector *fLvp3; //!
  TLorentzVector *fLvp4; //!

/*   std::vector<Double_t> f7CGaussianExcitationMean;
  std::vector<Double_t> f7CGaussianExcitationSigma; 
  std::vector<Double_t> f7CExcitationWeight; */
  //Members for controlling the excitation of 7C
  Double_t f7CExcitation;
  Double_t f7CGaussianExcitationMean;
  Double_t f7CGaussianExcitationSigma;
  Double_t f7CUniformExcitationMin;
  Double_t f7CUniformExcitationMax;

  Bool_t fIs7CUniformExcitation;
  Bool_t fIs7CGaussianExcitation;

  Double_t         fMinStep;
  Double_t         fTargetThickness;
  Bool_t           fTargetDecayFinish;

  TString         fDecayFilePath;
  Bool_t          fDecayFileFinished;
  Int_t           fDecayFileCurrentEvent;
  Double_t        fDecayFileExcitation;
  std::ifstream   fDecayFile;

  ClassDef(ERDecay7C,1)
};

#endif

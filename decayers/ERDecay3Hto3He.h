/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERDecay3Hto3He_H
#define ERDecay3Hto3He_H

#include <vector>
#include <fstream>

#include "TGraph.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TRandom2.h"
#include "TGenPhaseSpace.h"
#include "TLorentzVector.h"

#include "FairIon.h"

#include "ERDecay.h"

class ERDecay3Hto3He : public ERDecay {

public:
  ERDecay3Hto3He();
  ~ERDecay3Hto3He();
  
  /*Modifiers*/
  void SetMinStep(Double_t minStep) {fMinStep = minStep;}
  void SetTargetThickness(Double_t targetThickness) {fTargetThickness = targetThickness;}
   
 /** @brief Sets distribution is contained in file.
   ** @param ADfile  file with angular distribution.
  **/

void SetAngularDistribution(TString ADfile);   

public:
  Bool_t Init();
  Bool_t Stepping();
  // Bool_t Init() { return true; } 
  // Bool_t Stepping() { return true; } 


 void BeginEvent();
 void FinishEvent();
 // void PrintMass();

private:
  /** @brief Body reaction in phase space approach.
     ** @param Ecm     Total energy in CM.
    ** @oaram h7Mass  H7 ion mass.
  **/
   void ReactionPhaseGenerator(Double_t Ecm);

private:
  TRandom3       *fRnd;
  TRandom3       *fRnd2;
  
  TParticlePDG   *f3H;
  TParticlePDG   *f1H;
  TParticlePDG   *fn1;
  TParticlePDG   *f3He;
     //TParticlePDG   *f6He;

  
  TLorentzVector *fLv3H; //!
  TLorentzVector *fLv1H; //!
  TLorentzVector *fLvN1; //!	8He decay
  TLorentzVector *fLv3He; //!
 
//  FairIon        *fIon1H;
  //FairIon        *fUnstableIon10He;

  TGenPhaseSpace  *fReactionPhaseSpace;
  Double_t         fTargetReactZ;
  Double_t         fMinStep;
  Double_t         fTargetThickness;

  Double_t        f3HeMass;
  Bool_t          fReactionHappen;
  Bool_t          fDecayFinish;

  TGraph *fADInput = nullptr;    //!   distribution (angular distribution) graph containing AD input
  TF1    *fADFunction = nullptr; //!   function describing AD (angular distribution) of binary reaction
  Double_t fThetaMin = 0.;
  Double_t fThetaMax = 0.;

  //ADEvaluate function is necessary for TF1 constructor
  Double_t ADEvaluate(Double_t *x, Double_t *p);
  
  

  ClassDef(ERDecay3Hto3He,1);
};

#endif

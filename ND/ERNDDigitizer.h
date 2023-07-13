/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERNDDigitizer_H
#define ERNDDigitizer_H

#include "TClonesArray.h"

#include "FairTask.h"

#include "ERNDDigi.h"
#include "ERBC404Digi.h"
#include "ERNDSetup.h"

class ERNDDigitizer : public FairTask {

public:
  /** Default constructor **/
  ERNDDigitizer();

  /** Constructor 
  ** verbose: 1 - only standard log print, 2 - print digi information 
  **/
  ERNDDigitizer(Int_t verbose);

  /** Destructor **/
  ~ERNDDigitizer();

  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();
  
  /** Modifiers **/
  void SetLYErrorND(Float_t a, Float_t b, Float_t c) {fLYErrorNDA = a;fLYErrorNDB = b;fLYErrorNDC = c;}
  void SetEdepErrorND(Float_t a, Float_t b, Float_t c) {fEdepErrorNDA = a;fEdepErrorNDB = b;fEdepErrorNDC = c;}
  void SetTimeErrorND(Float_t a) {fTimeErrorNDA = a;}

  void SetLYErrorBC404(Float_t a, Float_t b, Float_t c) {fLYErrorBC404A = a;fLYErrorBC404B = b;fLYErrorBC404C = c;}
  void SetEdepErrorBC404(Float_t a, Float_t b, Float_t c) {fEdepErrorBC404A = a;fEdepErrorBC404B = b;fEdepErrorBC404C = c;}
  void SetTimeErrorBC404(Float_t a) {fTimeErrorBC404A = a;}

  
  void SetQuenchThresholdND(Float_t th) {fQuenchThresholdND = th;}
  void SetLYThresholdND(Float_t th) {fLYThresholdND = th;}
  void SetProbabilityNDB(Float_t b) {fProbabilityNDB = b;}
  void SetProbabilityNDC(Float_t c) {fProbabilityNDC = c;}

  void SetQuenchThresholdBC404(Float_t th) {fQuenchThresholdBC404 = th;}
  void SetLYThresholdBC404(Float_t th) {fLYThresholdBC404 = th;}
  void SetProbabilityBC404B(Float_t b) {fProbabilityBC404B = b;}
  void SetProbabilityBC404C(Float_t c) {fProbabilityBC404C = c;}

  /** Accessors **/ 
  Float_t ElossThresholdND() const {return fQuenchThresholdND;}
  Float_t LYThresholdND() const {return fLYThresholdND;}
  Float_t ProbabilityNDB() const {return fProbabilityNDB;}
  Float_t ProbabilityNDC() const {return fProbabilityNDC;}

  Float_t ElossThresholdBC404() const {return fQuenchThresholdBC404;}
  Float_t LYThresholdBC404() const {return fLYThresholdBC404;}
  Float_t ProbabilityBC404B() const {return fProbabilityBC404B;}
  Float_t ProbabilityBC404C() const {return fProbabilityBC404C;}

protected:
  //Input arrays
  TClonesArray* fNDPoints = nullptr;
  TClonesArray* fBC404Points = nullptr;
  //Output arrays
  TClonesArray* fNDDigis = nullptr;
  TClonesArray* fBC404Digis = nullptr;

  static Int_t fEvent;
  Float_t fEdepErrorNDA, fEdepErrorNDB, fEdepErrorNDC;
  Float_t fLYErrorNDA, fLYErrorNDB, fLYErrorNDC;
  Float_t fTimeErrorNDA;
  Float_t fQuenchThresholdND;
  Float_t fLYThresholdND;
  Float_t fProbabilityNDB;
  Float_t fProbabilityNDC;

  Float_t fEdepErrorBC404A, fEdepErrorBC404B, fEdepErrorBC404C;
  Float_t fLYErrorBC404A, fLYErrorBC404B, fLYErrorBC404C;
  Float_t fTimeErrorBC404A;
  Float_t fQuenchThresholdBC404;
  Float_t fLYThresholdBC404;
  Float_t fProbabilityBC404B;
  Float_t fProbabilityBC404C;

  ERNDSetup* fSetup = nullptr;
protected:
  ERNDDigi* AddNDDigi(Int_t stilbenNb, Float_t edep, Float_t edep_n1, Float_t edep_n2, Float_t edep_mis, Int_t parentTrackID, 
                    Float_t lightYield, Float_t time, Float_t neutronProb, Float_t x_in, Float_t y_in, Float_t z_in);
  ERBC404Digi* AddBC404Digi(Int_t hexNR, Float_t edep, Int_t parentTrackID, Float_t lightYield, Float_t time, 
                    Float_t neutronProb, Float_t x_in, Float_t y_in, Float_t z_in);
  Float_t NeutronProbabilityND(Float_t edep, Float_t ly);
  Float_t NeutronProbabilityBC404(Float_t edep, Float_t ly);
private:
  virtual void SetParContainers();
  
  ClassDef(ERNDDigitizer,1)
};

#endif

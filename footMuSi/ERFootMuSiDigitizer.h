/* January 14, 2022 at 9:27 AM

Add functional header to ERTelescopeDigitizer */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSiDigitizer_H
#define ERFootMuSiDigitizer_H

#include <limits>
#include <functional>

#include "TClonesArray.h"

#include "ERDigitizer.h"
#include "ERDigi.h"
#include "ERFootMuSiSetup.h"

class ERFootMuSiSetup;

class ERFootMuSiDigitizer : public ERDigitizer {
 public:
  ERFootMuSiDigitizer();
  /** Constructor 
  ** verbose: 1 - only standard log print, 2 - print digi information 
  **/
  ERFootMuSiDigitizer(Int_t verbose);
  virtual ~ERFootMuSiDigitizer() = default;
  /** Virtual method Init **/
  virtual InitStatus Init();
  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);
  /** Virtual method Finish **/
  virtual void Finish();
  /** Virtual method Reset **/
  virtual void Reset();
  /** Modifiers **/
  void SetSiElossThreshold(float th){fSiElossThreshold = th;}
  void SetSiElossSigma(float sigma);
  void SetSiTimeSigma(float sigma);
  void SetSiElossModel(const std::function<float(float)>& model) {fSiElossModel = model;}
  void SetSiTimeModel(const std::function<float(float)>& model) {fSiTimeModel = model;}
protected:
  //Input arrays
  std::map<TString, TClonesArray*> fQFootMuSiPoints;
  //Output arrays
  std::map<TString, TClonesArray*> fFootMuSiDigi;
  Float_t       fSiElossThreshold = 0.;
  std::function<float(float)> fSiElossModel = [](float eloss) { return eloss; };
  std::function<float(float)> fSiTimeModel = [](float time) { return time; };
protected:
  ERDigi* AddDigi(Float_t edep, Double_t time, Int_t stripNb, TString digiBranchName);
private:
  ClassDef(ERFootMuSiDigitizer,1)
};

#endif

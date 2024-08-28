// -------------------------------------------------------------------------
// -----                        ERGadastDigitizer header file          -----
// -----                  Created 03/15  by V.Schetinin                -----
// -------------------------------------------------------------------------

#ifndef ERGadastDigitizer_H
#define ERGadastDigitizer_H

#include <functional>
#include <utility>
#include <tuple>
#include <vector>

#include "TRandom3.h"
#include "TStopwatch.h"
#include "TH1F.h"
#include "TClonesArray.h"

#include "FairTask.h"

#include "ERGadastCsIDigi.h"
#include "ERGadastLaBrDigi.h"
#include "ERGadastDigiPar.h"
#include "ERGadastSetup.h"

class TObjectArray;
class TH1F;
class TH2F;
class TF1;
class TRandom;

class ERGadastDigitizer : public FairTask {

public:
  using BlockAddress = std::pair<size_t, size_t>;
  using CoefficientMatrix = std::vector<std::vector<std::vector<float>>>;
  /** Default constructor **/
  ERGadastDigitizer();

  /** Constructor 
  ** verbose: 1 - only standard log print, 2 - print digi information 
  **/
  ERGadastDigitizer(Int_t verbose);

  /** Destructor **/
  ~ERGadastDigitizer();

  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();
  
  /** Modifiers **/
  void SetCsILC(Float_t lc);
  void SetCsILC(std::map<BlockAddress, float>& lc);
  void SetCsILC(std::map<BlockAddress, CoefficientMatrix>& lc);

  void SetCsIEdepError(Float_t a, Float_t b, Float_t c);
  void SetCsIEdepError(std::map<BlockAddress, float>& a, 
                       std::map<BlockAddress, float>& b,
                       std::map<BlockAddress, float>& c);
  void SetCsIEdepError(std::map<BlockAddress, CoefficientMatrix>& a, 
                       std::map<BlockAddress, CoefficientMatrix>& b,
                       std::map<BlockAddress, CoefficientMatrix>& c);
  
  void SetCsITimeError(Float_t a) {fCsITimeErrorA = a;}
  
  void SetLaBrLC(Float_t lc){fLaBrLC = lc;}
  void SetLaBrEdepError(Float_t a, Float_t b, Float_t c) {fLaBrEdepErrorA = a;fLaBrEdepErrorB = b;fLaBrEdepErrorC = c;}
  void SetLaBrTimeError(Float_t a) {fLaBrTimeErrorA = a;}
  
  void SetCsIElossThreshold(Float_t treshold){fCsIElossThreshold = treshold;}
  void SetLaBrElossThreshold(Float_t treshold){fLaBrElossThreshold = treshold;}

  void SetGammasMultiplicity(Int_t multiplicity){fMultiplicity = multiplicity;}
  void SetDecayTime(Double_t decayTime){fDecayTime = decayTime;}
  void SetSignalsInterval(Double_t signalsInterval){fSignalsInterval = signalsInterval;}

  void SetPoissonCs(Double_t poissonCs){fPoissonCs = poissonCs;}
  void SetPoissonCo(Double_t poissonCo){fPoissonCo = poissonCo;}

  void SetSeed(Int_t seed){fMtGenerator.seed(seed);}
  /** Accessors **/ 

protected:
  //Digitization parameters
  ERGadastDigiPar* fDigiPar;
  //Input arrays
  TClonesArray* fGadastCsIPoints = nullptr;
  TClonesArray* fGadastLaBrPoints = nullptr;

  ERGadastSetup* fSetup = nullptr;
 
  //Output arrays
  TClonesArray* fGadastCsIDigi = nullptr;
  TClonesArray* fGadastLaBrDigi = nullptr;

  //light collection
  Float_t fCsILC;
  Float_t fCsIEdepErrorA,fCsIEdepErrorB,fCsIEdepErrorC;
  Float_t fCsITimeErrorA;
  Float_t fLaBrLC;
  Float_t fLaBrEdepErrorA,fLaBrEdepErrorB,fLaBrEdepErrorC;
  Float_t fLaBrTimeErrorA;

  Float_t fCsIElossThreshold;
  Float_t fLaBrElossThreshold;

  //gammas multiplicity
  Int_t fMultiplicity;
  //Signal attenuation parameters [microseconds]
  Double_t fDecayTime;
  Double_t fSignalsInterval; 
  //Poisson means
  Double_t fPoissonCs;
  Double_t fPoissonCo; 

  //For debug purposes
  Int_t fSeed;
  std::mt19937 fMtGenerator; 

  std::function<float(BlockAddress, size_t, size_t, size_t)> fCsILCFun = 
      [](BlockAddress, size_t, size_t, size_t) {return 1.;};
  std::function<std::tuple<size_t, size_t, size_t>(BlockAddress)> fCsILCGrid =
      [](BlockAddress)  {return std::make_tuple(1,1,1);};

  std::function<float(BlockAddress, size_t, size_t, size_t)> fCsILCAFun = 
      [](BlockAddress, size_t, size_t, size_t) {return 0.;};
  std::function<std::tuple<size_t, size_t, size_t>(BlockAddress)> fCsILCAGrid =
      [](BlockAddress)  {return std::make_tuple(1,1,1);};

  std::function<float(BlockAddress, size_t, size_t, size_t)> fCsILCBFun = 
      [](BlockAddress, size_t, size_t, size_t) {return 1.;};
  std::function<std::tuple<size_t, size_t, size_t>(BlockAddress)> fCsILCBGrid =
      [](BlockAddress)  {return std::make_tuple(1,1,1);};

  std::function<float(BlockAddress, size_t, size_t, size_t)> fCsILCCFun = 
      [](BlockAddress, size_t, size_t, size_t) {return 1.;};
  std::function<std::tuple<size_t, size_t, size_t>(BlockAddress)> fCsILCCGrid =
      [](BlockAddress)  {return std::make_tuple(1,1,1);};
protected:
  
  ERGadastCsIDigi* AddCsIDigi(Float_t Edep,Int_t wall,Int_t block, Int_t cell, Int_t Events_Poisson_Cs, 
  Int_t Events_Poisson_Co, Int_t CsGammas_Before, Int_t CsGammas_After, Int_t Co1Gammas_Before, Int_t Co1Gammas_After, 
  Int_t Co2Gammas_Before, Int_t Co2Gammas_After);
  ERGadastLaBrDigi* AddLaBrDigi(Float_t Edep, Int_t cell);
  
private:
  virtual void SetParContainers();
  
  ClassDef(ERGadastDigitizer,1)
};

#endif

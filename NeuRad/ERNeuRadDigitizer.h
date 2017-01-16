// -------------------------------------------------------------------------
// -----                        ERNeuRadDigitizer header file          -----
// -----                  Created 03/15  by V.Schetinin                -----
// -------------------------------------------------------------------------

#ifndef ERNEURADDIGITIZER_H
#define ERNEURADDIGITIZER_H

#include <vector>
using std::vector;

#include "TRandom3.h"
#include "TStopwatch.h"
#include "TH1F.h"

#include "FairTask.h"

#include "ERNeuRadPoint.h"
#include "ERNeuRadPhotoElectron.h"
#include "ERNeuRadPMTSignal.h"
#include "ERNeuRadDigiPar.h"
#include "ERNeuRadSetup.h"

class TObjectArray;
class TH1F;
class TH2F;
class TF1;
class TRandom;

class ERNeuRadDigitizer : public FairTask {

public:
  /** Default constructor **/
  ERNeuRadDigitizer();

  /** Constructor 
  ** verbose: 1 - only standard log print, 2 - print digi information 
  **/
  ERNeuRadDigitizer(Int_t verbose);

  /** Destructor **/
  ~ERNeuRadDigitizer();

  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();
  
  /** Modifiers **/
  inline void SetPMTJitter(const Double_t PMTJitter)    {fPMTJitter = PMTJitter;}
  inline void SetPMTDelay(const Double_t PMTDelay)      {fPMTDelay = PMTDelay;}
  inline void SetScincilationTau(const Double_t tau)    {fScincilationTau = tau;}
  inline void SetScincilationDT(const Double_t dt)      {fScincilationDT = dt;}

  inline void SetPixelThreshold(const Float_t pThreshold){fPixelThreshold = pThreshold;}

  /** Accessors **/ 
  Int_t PhotoElectronCount()  const;
  Int_t PMTSignalCount()   const;
protected:
  //Digitization parameters
  ERNeuRadDigiPar* fDigiPar;
  ERNeuRadSetup* fNeuRadSetup;
  //Input arrays
  TClonesArray *fNeuRadPoints;
  TClonesArray *fNeuRadFirstStep;

  //Output arrays
  TClonesArray *fNeuRadPhotoElectron;
  TClonesArray *fNeuRadPMTSignal;

  //Output histos
  TH1F* fHPECountF;
  TH1F* fHPECountB;

  TH1F* fHAmplitudesB;

  Int_t fFpeCount;
  Int_t fBpeCount;
  
  //constants
  static const Double_t cSciFiLightYield; // [photons/MeV]
  static const Double_t cSpeedOfLight; //[cm/ns]
  static const Double_t cMaterialSpeedOfLight;//[cm/ns]
  static const Int_t    cErrorPointsInModuleCount;
  static const Double_t cLightFractionInTotalIntReflection;
  //доля света захватываемая файбером в полное внутренне отражение в каждую сторону.
  static const Double_t cPMTDelay; //[ns]
  static const Double_t cPMTJitter; //[ns]
  static const Int_t    cPECountForOneElectronsSim;
  static const Double_t cScincilationTau; //[ns]
  static const Double_t cScincilationDT;  //[ns]
  static const Double_t cMaxPointLength; //[cm] //старый параметр, для идеи дробления поинта в диджитизации. Будет удален в следующих версиях
  
  //Allow for user params
  Double_t fPMTJitter; //[ns]
  Double_t fPMTDelay; //[ns]
  Double_t fExcessNoiseFactor;
  Double_t fScincilationTau; //[ns]
  Double_t fScincilationDT;  //[ns]

  TStopwatch fPhotoElectronsCreatingTimer;
  Double_t fPhotoElectronsCreatingTime;
  TStopwatch fPMTSignalCreatingTimer;
  Double_t fPMTSignalCreatingTime;
  Float_t fOnePEInteg;
  Float_t fPixelThreshold;
  Float_t fSumAmplitudeF;
  Float_t fSumAmplitudeB;
protected:
  ERNeuRadPhotoElectron* AddPhotoElectron(Int_t i_point, Int_t side, Double_t lytime, Double_t cathode_time, Double_t anode_time, 
									Int_t photon_count, Int_t photoel_count,Double_t amplitude, Int_t onePE);

  virtual ERNeuRadPMTSignal* AddPMTSignal(Int_t iBundle, Int_t iFiber, Int_t fpoints_count, Int_t side);
  
  virtual void PhotoElectronsCreating(Int_t i_point, ERNeuRadPoint *point,
                          std::vector<ERNeuRadPhotoElectron* >** frontPointsPerFibers,
                          std::vector<ERNeuRadPhotoElectron* >** backPointsPerFibers);
                        
  virtual void PMTSignalsCreating(Int_t iBundle, Int_t iFiber,
                                std::vector<ERNeuRadPhotoElectron* >** frontPointsPerFibers,
                                std::vector<ERNeuRadPhotoElectron* >** backPointsPerFibers,
                                Float_t& sumFrontQDC, Float_t& sumBackQDC);

  Int_t Crosstalks(Int_t iBundle, Int_t iFiber);
  TRandom3  *fRand;
private:
  virtual void SetParContainers();
  
  ClassDef(ERNeuRadDigitizer,1)
};

#endif

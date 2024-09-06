// -------------------------------------------------------------------------
// -----                      ERGadastStep header file             -----
// -----                  Created 03/16  by v. Schetinin            -----
// -------------------------------------------------------------------------


/**  ERGadastStep.h
 **/

#ifndef ERGadastStep_H
#define ERGadastStep_H


#include "TObject.h"
#include "TVector3.h"
#include "TArrayI.h"


#include "FairMultiLinkedData.h"

#include "ERMCTrack.h"

class ERGadastStep : public FairMultiLinkedData
{
 public:

  /** Default constructor **/
  ERGadastStep();

  /** Constructor with arguments
   *@param EventID  Index of Event
   *@param trackID  Index of MCTrack
   *@param mot0trackID Index of Mother MCTrack
   *@param fiberInBundleNb number of fiber in bundle
   *@param pos    Coordinates at entrance of point [cm]
   *@param mom    Momentum of track first step[GeV]
   *@param tof      Time since event start [ns]
   *@param length Track length since creation [cm]
   *@param pid   
   **/
  ERGadastStep(Int_t eventID, Int_t stepNr,Int_t trackID,
		  Int_t mot0trackID,
      Int_t fiberInBundleNb,
		  TVector3 pos, 
      TVector3 mom, 
		  Double_t tof, 
      Double_t length, 
      Int_t pid,
      Double_t mass,
      ExpertTrackingStatus trackStatus,
      Double_t eLoss,
      Double_t charge,
      TArrayI  processID);


  /** Copy constructor **/
  ERGadastStep(const ERGadastStep&);


  /** Destructor **/
  virtual ~ERGadastStep();
  
  ERGadastStep& operator=(const ERGadastStep&) { return *this; }
  
  /** Accessors **/
  Double_t GetFiberInBundleNb() const {return fFiberInBundleNb;}
  Double_t GetX() const {return fX;}
  Double_t GetY() const {return fY;}
  Double_t GetZ() const {return fZ;}
  void Print();
  
  static ExpertTrackingStatus GetTrackStatus();
  
 protected:
  
  Int_t fEventID;
  Int_t fStepNr;
  Int_t fTrackID;
  Int_t fMot0TrackID;
  Int_t fFiberInBundleNb;
  Double32_t fX,  fY,  fZ;
  Double32_t fPx, fPy, fPz;
  Double32_t fTOF;
  Double32_t fLength;
  Int_t fPID;
  Double_t fMass;
  ExpertTrackingStatus fTrackStatus;
  Double_t fEloss;
  Double_t fCharge;
  TArrayI fProcessID;
  

  ClassDef(ERGadastStep,1)
};

#endif

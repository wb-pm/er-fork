// -------------------------------------------------------------------------
// -----                        ExpertNeuRad header file               -----
// -----                  Created 03/15  by V.Schetinin                -----
// -------------------------------------------------------------------------

/**  ExpertNeuRad.h
 **/


#ifndef ExpertNeuRad_H
#define ExpertNeuRad_H

#include "FairDetector.h"
#include "ExpertNeuRadStep.h"
#include "ExpertNeuRadPoint.h"

#include "TH1F.h"
#include "TLorentzVector.h"

using namespace std;

class TClonesArray;
class FairVolume;
class TF1;

class ExpertNeuRad : public FairDetector
{
  
public:
  
  /** Default constructor **/
  ExpertNeuRad();
  
  
  /** Standard constructor.
   *@param name    ExpertNeuRad detector name
   *@param active  sensitivity flag
   *@param verbose Verbosity level. 1 - only standart logs, 2 - Print points after each event, 3 - GEANT Step information
   **/
  ExpertNeuRad(const char* name, Bool_t active, Int_t verbose);
  
  
  /** Destructor **/
  virtual ~ExpertNeuRad();
  
  
  /** Virtual method ProcessHits
   **   
   ** Defines the action to be taken when a step is inside the
   ** active volume. Creates a ExpertNeuRadPoint and adds it to the
   ** collection.
   *@param vol  Pointer to the active volume
   **/
  virtual Bool_t ProcessHits(FairVolume* vol = 0);
  
  
  /** Virtual method BeginEvent
   **
   **/
  virtual void BeginEvent();
  
  /** Virtual method EndOfEvent
   **
   ** If verbosity level is set, print point collection at the
   ** end of the event.
   **/
  virtual void EndOfEvent();
  
  /** Virtual method Register
   **
   ** Registers the point collection in the ROOT manager.
   **/
  virtual void Register();
  
  
  /** Accessor to the point collection **/
  virtual TClonesArray* GetCollection(Int_t iColl) const;
  
  
  /** Virtual method Print
   **
   ** Screen output of hit collection.
   **/
  virtual void Print(Option_t *option="") const;
  
  
  /** Virtual method Reset
   **
   ** Clears the point collection
   **/
  virtual void Reset();
  
  
  /** Virtual method CopyClones
   **
   ** Copies the hit collection with a given track index offset
   *@param cl1     Origin
   *@param cl2     Target
   *@param offset  Index offset
   **/
  virtual void CopyClones(TClonesArray* cl1, TClonesArray* cl2,
			  Int_t offset);
  
  
  /** Virtaul method Construct geometry
   **
   ** Constructs the ExpertNeuRad geometry
   **/
  virtual void ConstructGeometry();
  
   /** Virtaul method Initialize
   **
   ** Initialize detector data
   **/
  virtual void Initialize();

  /** Virtaul method CheckIfSensitive 
	**Check whether a volume is sensitive.
  ** @param(name)  Volume name
  ** @value        kTRUE if volume is sensitive, else kFALSE
  **
  ** The decision is based on the volume name (has to contain "fiber").
  **/
  virtual Bool_t CheckIfSensitive(std::string name);
  
  /** Virtaul method SetGeomVersion
  **/
  void SetGeomVersion(Int_t vers ) { fVersion = vers; }
  
  void SetStorePrimarySteps() {fStorePrimarySteps = kTRUE;}
  void SetStoreAllSteps() {fStoreAllSteps = kTRUE;}
private:
  TClonesArray*  fNeuRadPoints;     //!  The point collection
  TClonesArray*  fNeuRadFirstStep;  //!  The first step collection
  TClonesArray*  fNeuRadSteps;      //!  The steps collection
  Int_t fVersion;                    //! geometry version
    
  Bool_t fStorePrimarySteps;
  Bool_t fStoreAllSteps;
private:
  /** Private method AddPoint
   **
   ** Adds a NeuRadPoint to the Point Collection
   **/
  ExpertNeuRadPoint* AddPoint(Int_t eventID, Int_t trackID,
			  Int_t mot0trackID,
        Int_t fiberInBundleNb,
			  Double_t mass,
			  TVector3 posIn,
			  TVector3 pos_out, TVector3 momIn,
			  TVector3 momOut, Double_t time,
			  Double_t length, Double_t eLoss, Double_t lightYield);
  
  /** Private method AddFirstStep
  **
  ** Adds a NeuRadStep to the FirstStep Collection
  **/
  ExpertNeuRadStep* AddFirstStep(Int_t eventID, Int_t stepNr,Int_t trackID,
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
        
  /** Private method AddStep
  **
  ** Adds a NeuRadStep to the Steps Collection
  **/      
  ExpertNeuRadStep* AddStep(Int_t eventID, Int_t stepNr,Int_t trackID,
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
  
  /** Private method ResetParameters
   **
   ** Resets the private members for the track parameters
   **/
  void ResetParameters();
  
  ClassDef(ExpertNeuRad,1);
};

#endif 

/* Taken from: ERTelescope.h
Commit: August 6, 2020 at 7:52 AM
Description: ERQTelescope -> ERTelescope renaming */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSi_H
#define ERFootMuSi_H

#include "ERDetector.h"
#include "ERFootMuSiSetup.h"

#include "TLorentzVector.h"

class TClonesArray;
class FairVolume;
class TF1;

class ERFootMuSi : public ERDetector {
public:
  /** Default constructor **/
  ERFootMuSi();
  /** Standard constructor.
   *@param name    ERFootMuSi name
   *@param active  sensitivity flag
   *@param verbose Verbosity level. 1 - only standard logs, 2 - Print points after each event, 3 - GEANT Step information
   **/
  ERFootMuSi(const char* name, Bool_t active, Int_t verbose);
  /** Destructor **/
  virtual ~ERFootMuSi();
  /** Virtual method ProcessHits
   **
   ** Defines the action to be taken when a step is inside the
   ** active volume. Creates a ERTelescopePoint and adds it to the
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
   /** Virtual method Initialize
   **
   ** Initialize ERFootMuSi data
   **/
  virtual void Initialize();
  /** @brief Builds geometry and writes it to temporary file
   ** trough parameters from ERBeamDetSetup class object.
   ** Virtual from FairDetector.
  **/
  virtual void ConstructGeometry();
  /** Virtual method CheckIfSensitive
	**Check whether a volume is sensitive.
  ** @param(name)  Volume name
  ** @value        kTRUE if volume is sensitive, else kFALSE
  **
  ** The decision is based on the volume name.
  **/
  virtual Bool_t CheckIfSensitive(std::string name);
  /** Virtual method SetGeomVersion
  **/
  void SetGeomVersion(Int_t vers ) { fVersion = vers; }
private:
  ERFootMuSiSetup* fFootMuSiSetup = nullptr; //!
  std::map<TString,std::map<TString,TClonesArray*>> fPoints;
  Int_t                     fVersion = -1;           //! geometry version
  Int_t                     fEventID = -1;           //!  event index
  Int_t                     fTrackID = -2;           //!  track index
  Int_t                     fMot0TrackID = -2;       //!  0th mother track index
  Double_t                  fMass = 0.;              //!  mass
  TLorentzVector            fPosIn, fPosOut;    //!  position
  TLorentzVector            fMomIn, fMomOut;    //!  momentum
  Double32_t                fTime = 0.;              //!  time
  Double32_t                fLength = 0.;            //!  length
  Double32_t                fEloss = 0.;             //!  energy loss
  Int_t                     fChannel = -1;
  Int_t                     fPDG = -1;
private:
  /** Private method AddPoint
   **
   ** Adds a ERFootMuSi point to the Point Collection
   **/
  void AddPoint(TClonesArray& clref);
  /** Private method ResetParameters
   **
   ** Resets the private members for the track parameters
   **/
  void ResetParameters();

  ClassDef(ERFootMuSi, 1);
};

#endif

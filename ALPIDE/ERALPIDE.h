/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERALPIDE_H
#define ERALPIDE_H

#include "ERDetector.h"

#include "ERALPIDEPoint.h"
#include "ERALPIDEStep.h"

/** @class ERALPIDE
 ** @brief Class for the MC transport of the ALPIDE detector 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
 ** The ERALPIDE defines the behaviour of the ALPIDE system during
 ** transport simulation. It constructs the ALPIDE transport geometry
 ** and creates objects of type ERALPIDEPoints and ERALPIDESteps if requested.
**/

class ERALPIDE : public ERDetector
{

public:
  
  /** @brief Default constructor **/
  ERALPIDE();
  /** @brief Standard constructor
     ** @param name    ERALPIDE detector name
     ** @param active  Sensitivity flag
     ** @param verbose Verbosity level. 1 - only standart logs,
     **                                 2 - Print points after each event, 
     **                                 3 - GEANT Step information.
  **/
  ERALPIDE(const char* name, Bool_t active, Int_t verbose);
   
  /** @brief Destructor **/
  virtual ~ERALPIDE();

  /* Modifiers */

  /** @brief Store all geant steps in sensitive volume.
  **/
  void SetStoreSteps() {fStoreSteps = kTRUE;}

  /*Accessors*/

  /** @brief Get array of ERALPIDEPoint
   ** @param iColl  number of point collection
   ** @return Pointer to ERALPIDEPoint array. NULL if iColl > 0.
   **
   ** Abstract from FairDetector.
  **/
  virtual TClonesArray* GetCollection(Int_t iColl) const;

public:

  /** @brief Initialization
   ** class method FairDetector::Initialize() is called.
   ** ALPIDEGeoPar initialized from RuntimeDB
   ** Virtual from FairDetector.
  **/
  virtual void Initialize();

  /** @brief Register output array (ALPIDEPoint) to the I/O manager
   ** Virtual from FairDetector.
  **/
  virtual void Register();

  /** @brief Virtual method 
   ** Defines the action to be taken when a step is inside the active volume. Creates ERALPIDEPoint and adds it to the collection.
   ** @param vol  Pointer to the active volume
   ** Virtual from FairDetector.
  **/
  virtual Bool_t ProcessHits(FairVolume* vol = 0);

  /** @brief Action at end of event
   ** Short status log and Reset().
   ** Virtual from FairDetector.
  **/
  virtual void EndOfEvent();
  
  /** @brief Screen log
   ** Prints ALPIDEPoint information
   ** Virtual from TObject.
  **/
  virtual void Print(Option_t *option="") const;

  /** @brief Clears the point and steps collections
   ** Virtual from FairDetector
  **/
  virtual void Reset();

  /** @brief Copies the points collection with a given track index offset
   ** @param cl1     Origin
   ** @param cl2     Target
   ** @param offset  Index offset
   ** Virtual from FairDetector
  **/
  virtual void CopyClones(TClonesArray* cl1, TClonesArray* cl2, Int_t offset);

  /** @brief Check whether a volume is sensitive.
   ** @param name  Volume name
   ** @value        kTRUE if volume is sensitive, else kFALSE
   ** The decision is based on the volume name (has to contain "SiliconPlate").
   ** Virtual from FairModule.
  **/
  virtual Bool_t CheckIfSensitive(std::string name);
  // Constructs the ALPIDE geometry
  virtual void ConstructGeometry();  

private:

  /** @brief Adds an ALPIDEPoint to the Point Collection **/
  ERALPIDEPoint* AddALPIDEPoint(Int_t eventID, Int_t trackID,  Int_t mot0TrackID, Double_t mass,
              const TVector3& posIn,
              const TVector3& posOut,
              const TVector3& momIn,
              const TVector3& momOut,
              Double_t time, Double_t length, Double_t eLoss, Int_t fPDG, Int_t fPixelNoX,Int_t fPixelNoY,Int_t fPixelNoX_out,Int_t fPixelNoY_out);

  /** @brief Adds an ALPIDEStep to the Step Collection **/
  ERALPIDEStep* AddALPIDEStep(Int_t eventID, Int_t stepNr,Int_t trackID,
		  TVector3 pos, 
      TVector3 mom, 
      Int_t pixelNoX,
      Int_t pixelNoY,
		  Double_t tof, 
      Double_t length, 
      Int_t pid,
      Double_t mass,
      ExpertTrackingStatus trackStatus,
      Double_t eLoss,
      Double_t charge,
      TArrayI  processID);

  /** @brief Start new point creation. Reinit current point data **/
  void StartPoint();

  /** @brief Finish point creation. **/
  void FinishPoint();

private:

    TClonesArray* fALPIDEPoints = nullptr;

    TClonesArray* fALPIDESteps = nullptr;

    TClonesArray* fMCTracks = nullptr; 

    Bool_t fStoreSteps;

    Int_t fStepNumber;

ClassDef(ERALPIDE, 1);
};


#endif

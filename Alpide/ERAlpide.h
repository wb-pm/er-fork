/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERAlpide_H
#define ERAlpide_H

#include "ERDetector.h"

#include "ERAlpidePoint.h"
#include "ERAlpideStep.h"

/** @class ERAlpide
 ** @brief Class for the MC transport of the Alpide detector 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
 ** The ERAlpide defines the behaviour of the Alpide system during
 ** transport simulation. It constructs the Alpide transport geometry
 ** and creates objects of type ERAlpidePoints and ERAlpideSteps if requested.
**/
//Temporary namespace for keeping the dimensions of Alpide geometry and number of chips
namespace AlpideSpecs {
  const  Double_t plateXlength = 10.; ///< size of silicon plate along X axis
  const  Double_t plateYlength = 10.; ///< size of silicon plate along Y axis
  const  Int_t chipsNumber = 6; ///< number of chips on the plate
  const  Int_t pixelsXNumber = 512; ///< number of pixels along X axis
  const  Int_t pixelsYNumber = 1024; ///< number of pixels along Y axis
  const  Double_t pixelXlength = plateXlength / (chipsNumber * pixelsXNumber); ///<size of one pixel along X axis
  const  Double_t pixelYlength = plateYlength / (chipsNumber * pixelsYNumber); ///<size of one pixel along Y axis
}

class ERAlpide : public ERDetector
{

public:
  
  /** @brief Default constructor **/
  ERAlpide();
  /** @brief Standard constructor
     ** @param name    ERAlpide detector name
     ** @param active  Sensitivity flag
     ** @param verbose Verbosity level. 1 - only standart logs,
     **                                 2 - Print points after each event, 
     **                                 3 - GEANT Step information.
  **/
  ERAlpide(const char* name, Bool_t active, Int_t verbose);
   
  /** @brief Destructor **/
  virtual ~ERAlpide();

  /* Modifiers */

  /** @brief Store all geant steps in sensitive volume.
  **/
  void SetStoreSteps() {fStoreSteps = kTRUE;}

  /*Accessors*/

  /** @brief Get array of ERAlpidePoint
   ** @param iColl  number of point collection
   ** @return Pointer to ERAlpidePoint array. NULL if iColl > 0.
   **
   ** Abstract from FairDetector.
  **/
  virtual TClonesArray* GetCollection(Int_t iColl) const;

public:

  /** @brief Initialization
   ** class method FairDetector::Initialize() is called.
   ** AlpideGeoPar initialized from RuntimeDB
   ** Virtual from FairDetector.
  **/
  virtual void Initialize();

  /** @brief Register output array (AlpidePoint) to the I/O manager
   ** Virtual from FairDetector.
  **/
  virtual void Register();

  /** @brief Virtual method 
   ** Defines the action to be taken when a step is inside the active volume. Creates ERAlpidePoint and adds it to the collection.
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
   ** Prints AlpidePoint information
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
  // Constructs the Alpide geometry
  virtual void ConstructGeometry();  

protected:

  /** @brief Calculate the pixel number from the coordinates **/
  void LocalToPixel(Double_t globalX, Double_t globalY, Int_t& pixelNoX, Int_t& pixelNoY);
  
  void PixelToLocal(Int_t pixelNoX, Int_t pixelNoY,Double_t& globalX, Double_t& globalY);

private:

  /** @brief Adds an AlpidePoint to the Point Collection **/
  ERAlpidePoint* AddAlpidePoint(Int_t eventID, Int_t trackID,  Int_t mot0TrackID, Double_t mass,
              const TVector3& posIn,
              const TVector3& posInLocal,
              const TVector3& posOut,
              const TVector3& momIn,
              const TVector3& momOut,
              Double_t time, Double_t length, Double_t eLoss, Int_t fPDG, Int_t fPixelNoX,Int_t fPixelNoY,Int_t fPixelNoX_out,Int_t fPixelNoY_out);

  /** @brief Adds an AlpideStep to the Step Collection **/
  ERAlpideStep* AddAlpideStep(Int_t eventID, Int_t stepNr,Int_t trackID,
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

    TClonesArray* fAlpidePoints = nullptr;

    TClonesArray* fAlpideSteps = nullptr;

    TClonesArray* fMCTracks = nullptr; 

    Bool_t fStoreSteps;

    Int_t fStepNumber;

ClassDef(ERAlpide, 1);
};
#endif

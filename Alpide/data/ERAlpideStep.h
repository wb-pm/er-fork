/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
//Probably this class is not necessary
#ifndef ERAlpideStep_H
#define ERAlpideStep_H

#include "TVector3.h"
#include "TArrayI.h"

#include "FairMultiLinkedData.h"

#include "ERMCTrack.h"

/** @class ERAlpideStep
 ** @brief Class for stepping action of Alpide detector 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
**/

class ERAlpideStep : public FairMultiLinkedData 
{
 public:

  /** Default constructor **/
  ERAlpideStep();

  /** Constructor with arguments
   *@param EventID  Index of Event
   *@param trackID  Index of MCTrack
   *@param pixelNo  number of pixel
   *@param pos    Coordinates at entrance of point [cm]
   *@param mom    Momentum of track first step[GeV]
   *@param tof      Time since event start [ns]
   *@param length Track length since creation [cm]
   *@param pid   
   **/
  ERAlpideStep(Int_t eventID, Int_t stepNr,Int_t trackID,
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


  /** Copy constructor **/
  ERAlpideStep(const ERAlpideStep&);


  /** Destructor **/
  virtual ~ERAlpideStep();
  
  ERAlpideStep& operator=(const ERAlpideStep&) { return *this; }
  
  /** Accessors **/
  Double_t GetX() const {return fX;}
  Double_t GetY() const {return fY;}
  Double_t GetZ() const {return fZ;}
  void Print();
  
  static ExpertTrackingStatus GetTrackStatus();
  
 protected:
  
  Int_t fEventID;
  Int_t fStepNr;
  Int_t fTrackID;
  Int_t fPixelNoX, fPixelNoY;
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
  

  ClassDef(ERAlpideStep,1)
};

#endif

/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERALPIDEHit_H
#define ERALPIDEHit_H

#include "TObject.h"
#include "TVector3.h"

#include "FairHit.h"

/** @class ERALPIDEHit
 ** @brief Class for hits of the ALPIDE detector 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
**/

class ERALPIDEHit : public FairHit {

public:
  /** Default constructor **/
  ERALPIDEHit();

  /** Standard constructor 
  *@param statNr Station number
  *@param pos    Position coordinates [cm]
  *@param dpos   Errors in position coordinates [cm]
  *@param flag   Hit flag
  **/
  ERALPIDEHit(int32_t statNr, TVector3& pos, TVector3& dpos, int32_t indexCentralX = 0, int32_t indexCentralY = 0,
            int32_t fClusterIndex = 0, int32_t flag = 0);


  /** Destructor **/
  virtual ~ERALPIDEHit();

  /** Output to screen **/
  virtual void Print(const Option_t* opt = nullptr) const;

  /** Setters **/
  void SetTime(double time) { fTime = time; }
  void SetTimeError(double error) { fTimeError = error; }
  /** Accessors **/

protected:
  int32_t fFlag;  // Hit flag; to be used later
  int32_t fClusterIndex;
  int32_t fIndexCentralX;
  int32_t fIndexCentralY;
  int32_t fDetectorID;
  double fTime;         ///< Hit time [ns]
  double fTimeError;    ///< Error of hit time [ns]

  ClassDef(ERALPIDEHit, 1);
};

#endif

/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERALPIDEHit.h"

#include "FairLogger.h"

// -----   Default constructor   -------------------------------------------
ERALPIDEHit::ERALPIDEHit() :
  fFlag(-1)
  , fClusterIndex(-1)
  , fIndexCentralX(-1)
  , fIndexCentralY(-1)
  , fDetectorID(-1)
{
  SetTime(0.);
  SetTimeError(0.);
}
// -------------------------------------------------------------------------
// -----   Standard constructor   ------------------------------------------
ERALPIDEHit::ERALPIDEHit(int32_t statNr, TVector3& pos, TVector3& dpos, int32_t indexCentralX, int32_t indexCentralY,
                     int32_t clusterIndex, int32_t flag)
  : FairHit(0, pos, dpos, 0.)
  , fFlag(flag)
  , fClusterIndex(clusterIndex)
  , fIndexCentralX(indexCentralX)
  , fIndexCentralY(indexCentralY)
  , fDetectorID(-1)
{
  //fDetectorID = DetectorId(statNr);
  SetTime(0.);
  SetTimeError(0.);
}
// -------------------------------------------------------------------------
// -----   Destructor   ----------------------------------------------------
ERALPIDEHit::~ERALPIDEHit() {}
// -------------------------------------------------------------------------
// -----   Public method Print   -------------------------------------------
void ERALPIDEHit::Print(const Option_t* /*opt*/) const
{
  LOG(INFO) << "ALPIDE Hit " << " at (" << GetX() << ", " << GetY() << ", " << GetZ()
            << ") cm";
}
// -------------------------------------------------------------------------


ClassImp(ERALPIDEHit)

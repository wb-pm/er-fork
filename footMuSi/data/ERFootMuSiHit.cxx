/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiHit.h"
//--------------------------------------------------------------------------------------------------
ERFootMuSiHit::ERFootMuSiHit(const TVector3& xStationHit, 
                                     const TVector3& yStationHit, const TVector3& xStationLocalHit,
                                     const TVector3& yStationLocalHit, const Int_t xChannel, const Int_t yChannel,
                                     const Double_t xEdep, const Double_t yEdep)
: fXStationHit(xStationHit), fYStationHit(yStationHit),
  fXStationLocalHit(xStationLocalHit), fYStationLocalHit(yStationLocalHit),
  fXChannel(xChannel), fYChannel(yChannel), fXEdep(xEdep), fYEdep(yEdep)
{
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiHit)

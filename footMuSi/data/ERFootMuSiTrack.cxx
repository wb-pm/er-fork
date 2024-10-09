/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiTrack.h"

/* ERFootMuSiTrack::ERFootMuSiTrack(ERFootMuSiHit* firstHit, ERFootMuSiHit* secondHit,ERFootMuSiHit* thirdHit, Double_t HitsFitChi2):
fFirstHit(firstHit), fSecondHit(secondHit), fThirdHit(thirdHit),fHitsFitChi2(HitsFitChi2)
{
} */
ERFootMuSiTrack::ERFootMuSiTrack(const TVector3& firstHit, const TVector3& secondHit, const TVector3& thirdHit, std::vector<Double_t> distancesToPixels):
fFirstHit(firstHit), fSecondHit(secondHit), fThirdHit(thirdHit),fDistancesToPixels(distancesToPixels)
{    
}
ClassImp(ERFootMuSiTrack)

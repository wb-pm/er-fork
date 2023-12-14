/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiTrack.h"

ERFootMuSiTrack::ERFootMuSiTrack(const TVector3& firstPairVector, const TVector3& secondPairVector,const TVector3& thirdPairVector):
fFirstPairVector(firstPairVector), fSecondPairVector(secondPairVector), fThirdPairVector(thirdPairVector)
{
}
ERFootMuSiTrack::ERFootMuSiTrack(const TVector3& firstHitPointVector, const TVector3& secondHitPointVector):fFirstHitPoint(firstHitPointVector),fSecondHitPoint(secondHitPointVector)
{

}
ClassImp(ERFootMuSiTrack)
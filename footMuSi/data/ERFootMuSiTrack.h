/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERFootMuSiTrack_H
#define ERFootMuSiTrack_H

#include <vector>

#include "TVector3.h"

#include "FairMultiLinkedData.h"
#include "ERFootMuSiHit.h"

/** @class ERFootMuSiTrack
 ** @brief 
 ** @author B. Khamidullin
 ** @version 1.0
**/

class ERFootMuSiTrack : public FairMultiLinkedData {

public:
  /** @brief Default constructor **/
    ERFootMuSiTrack() = default;
  /** @brief Constructor 
   **/
    ERFootMuSiTrack(const TVector3& firstPairVector, const TVector3& secondPairVector,const TVector3& thirdPairVector);
    ERFootMuSiTrack(const TVector3& firstHitPointVector, const TVector3& secondHitPointVector);

    TVector3 GetFirstPairVector() const {return fFirstPairVector;}
    TVector3 GetSecondPairVector() const {return fSecondPairVector;}
    TVector3 GetThirdPairVector() const {return fThirdPairVector;}
private:
    std::vector<ERFootMuSiHit*> fFootMuSiHitsOfTrack;
    TVector3 fFirstHitPoint;
    TVector3 fSecondHitPoint;
    TVector3 fFirstPairVector; 
    TVector3 fSecondPairVector; 
    TVector3 fThirdPairVector; 

    ClassDef(ERFootMuSiTrack,1)
};

#endif

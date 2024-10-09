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
 ** @author B. Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
**/

class ERFootMuSiTrack : public FairMultiLinkedData {

public:
  /** @brief Default constructor **/
    ERFootMuSiTrack() = default;
  /** @brief Constructor 
   **/
/*     ERFootMuSiTrack(ERFootMuSiHit* firstHit, ERFootMuSiHit* secondHit,ERFootMuSiHit* thirdHit, Double_t HitsFitChi2 = 0.0); */
    ERFootMuSiTrack(const TVector3& firstHit, const TVector3& secondHit, const TVector3& thirdHit, const std::vector<Double_t> distancesToPixels);

/*     ERFootMuSiHit* GetFirstHit() const {return fFirstHit;}
    ERFootMuSiHit* GetSecondHit() const {return fSecondHit;}
    ERFootMuSiHit* GetThirdHit() const {return fThirdHit;} */

    TVector3 GetFirstHit() const {return fFirstHit;}
    TVector3 GetSecondHit() const {return fSecondHit;}
    TVector3 GetThirdHit() const {return fThirdHit;}
    void SetFirstHitRefIndex(Int_t firstHitRefIndex) {fFirstHitRefIndex = firstHitRefIndex;}
    void SetSecondHitRefIndex(Int_t secondHitRefIndex) {fSecondHitRefIndex = secondHitRefIndex;}
    void SetThirdHitRefIndex(Int_t thirdHitRefIndex) {fThirdHitRefIndex = thirdHitRefIndex;}
    Int_t GetFirstHitRefIndex() const {return fFirstHitRefIndex;}
    Int_t GetSecondHitRefIndex() const {return fSecondHitRefIndex;}
    Int_t GetThirdHitRefIndex() const {return fThirdHitRefIndex;}
    void SetAnglesWithInitialP(Double_t firstAngle, Double_t secondAngle) {
        fFirstAngleComparison = firstAngle; fSecondAngleComparison = secondAngle;
    };

private:
    TVector3 fFirstHit;
    TVector3 fSecondHit;
    TVector3 fThirdHit;
    Int_t fFirstHitRefIndex;
    Int_t fSecondHitRefIndex;
    Int_t fThirdHitRefIndex;
    Double_t fFirstAngleComparison;
    Double_t fSecondAngleComparison;
    std::vector<Double_t> fDistancesToPixels;
/*     ERFootMuSiHit* fFirstHit;
    ERFootMuSiHit* fSecondHit;
    ERFootMuSiHit* fThirdHit;
    Double_t fHitsFitChi2; */

    ClassDef(ERFootMuSiTrack,1)
};

#endif

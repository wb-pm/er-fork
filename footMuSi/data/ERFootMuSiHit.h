/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERFootMuSiHit_H
#define ERFootMuSiHit_H

#include "TNamed.h"
#include "TVector3.h"

#include "FairMultiLinkedData.h"
#include "FairHit.h"

/** @class ERFootMuSiHitFinder
 ** @brief 
 ** @author 
 ** @version 1.0
**/

class ERFootMuSiHit : public FairHit{

public:
  /** @brief Default constructor **/
  ERFootMuSiHit() = default;
  /** @brief Constructor 
   ** @param fTargetVertex - Hit vertex on target;
   ** @param fXStationHit - Hit vertex on FootMuSi station, which produced X coordinate;
   ** @param fYStationHit - Hit vertex on FootMuSi station, which produced Y coordinate;
   ** @param fXStationLocalHit - Hit vertex in station CS on FootMuSi station, which produced X coordinate;
   ** @param fYStationLocalHit - Hit vertex in station CS on FootMuSi station, which produced Y coordinate;
   ** @param fXChannel - Channel number in FootMuSi station, which produced X coordinate;
   ** @param fYChannel - Channel number in FootMuSi station, which produced Y coordinate;
   ** @param fXEdep - Edep in FootMuSi station, which produced X coordinate;
   ** @param fYEdep - Edep in FootMuSi station, which produced Y coordinate;
  **/
  ERFootMuSiHit(const TVector3& xStationHit, const TVector3& yStationHit,
                    const TVector3& xStationLocalHit, const TVector3& yStationLocalHit, 
                    Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep);
  /* Accessors */
  TVector3 GetXStationHit() const {return fXStationHit;}
  TVector3 GetYStationHit() const {return fYStationHit;}
  TVector3 GetXStationLocalHit() const {return fXStationLocalHit;}
  TVector3 GetYStationLocalHit() const {return fYStationLocalHit;}
  Int_t GetXChannel() const {return fXChannel;}
  Int_t GetYChannel() const {return fYChannel;}
  Double_t GetXEdep() const {return fXEdep;}
  Double_t GetYEdep() const {return fYEdep;}
private:
  TVector3 fXStationHit;
  TVector3 fYStationHit;
  TVector3 fXStationLocalHit;
  TVector3 fYStationLocalHit;
  Int_t fXChannel = -1;
  Int_t fYChannel = -1;
  Double_t fXEdep = -1.;
  Double_t fYEdep = -1.;

  ClassDef(ERFootMuSiHit, 1)
};

#endif

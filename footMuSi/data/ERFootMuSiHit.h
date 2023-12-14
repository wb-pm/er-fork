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

/** @class ERFootMuSiHitFinder
 ** @brief 
 ** @author 
 ** @version 1.0
**/

class ERFootMuSiHit : public FairMultiLinkedData{

public:
  /** @brief Default constructor **/
  ERFootMuSiHit() = default;
  /** @brief Constructor 
   ** @param fTargetVertex - Hit vertex on target;
   ** @param fXStationVertex - Hit vertex on FootMuSi station, which produced X coordinate;
   ** @param fYStationVertex - Hit vertex on FootMuSi station, which produced Y coordinate;
   ** @param fXStationLocalVertex - Hit vertex in station CS on FootMuSi station, which produced X coordinate;
   ** @param fYStationLocalVertex - Hit vertex in station CS on FootMuSi station, which produced Y coordinate;
   ** @param fXChannel - Channel number in FootMuSi station, which produced X coordinate;
   ** @param fYChannel - Channel number in FootMuSi station, which produced Y coordinate;
   ** @param fXEdep - Edep in FootMuSi station, which produced X coordinate;
   ** @param fYEdep - Edep in FootMuSi station, which produced Y coordinate;
  **/
  ERFootMuSiHit(const TVector3& targetVertex, const TVector3& xStationVertex, const TVector3& yStationVertex,
                    const TVector3& xStationLocalVertex, const TVector3& yStationLocalVertex, 
                    Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep);
  /* Accessors */
  TVector3 GetTargetVertex() const {return fTargetVertex;}
  TVector3 GetXStationVertex() const {return fXStationVertex;}
  TVector3 GetYStationVertex() const {return fYStationVertex;}
  TVector3 GetXStationLocalVertex() const {return fXStationLocalVertex;}
  TVector3 GetYStationLocalVertex() const {return fYStationLocalVertex;}
  TVector3 GetVertexInZPlane(Double_t z) const;
  Double_t GetXInZPlane(Double_t z) const;
  Double_t GetYInZPlane(Double_t z) const;
  TVector3 GetDirection() const;
  TVector3 GetBackDirection() const {return (-1.) * GetDirection();}
  Int_t GetXChannel() const {return fXChannel;}
  Int_t GetYChannel() const {return fYChannel;}
  Double_t GetXEdep() const {return fXEdep;}
  Double_t GetYEdep() const {return fYEdep;}
private:
  TVector3 fTargetVertex;
  TVector3 fXStationVertex;
  TVector3 fYStationVertex;
  TVector3 fXStationLocalVertex;
  TVector3 fYStationLocalVertex;
  Int_t fXChannel = -1;
  Int_t fYChannel = -1;
  Double_t fXEdep = -1.;
  Double_t fYEdep = -1.;

  ClassDef(ERFootMuSiHit, 1)
};

#endif

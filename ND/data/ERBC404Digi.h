/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERBC404Digi_H
#define ERBC404Digi_H

#include "TVector3.h"

#include "ERDigi.h"

class ERBC404Digi : public ERDigi {
 public:
  ERBC404Digi() = default;
  ERBC404Digi(ERChannel hexNR, float edep, int parentTrackID, float lightYield, float time, 
                    float neutronProb, float x_in, float y_in, float z_in, float tac = -1.);

  /** Accessors **/
  float LightYield() const {return fLightYield;}
  float NeutronProb() const {return fNeutronProb;}
  float TAC() const {return fTAC;}
  float ParentTrackID() const {return fParentTrackID;}
  /** Modifiers **/
  void SetTAC(const Double_t TAC) {fTAC = TAC;}
 protected:
  float fLightYield = -1.;
  float fNeutronProb = -1.;
  float fTAC = -1.;
  float fX_in = -1.;		//sonya:new variables x_in,y_in,z_in - enter point of neutron
  float fY_in = -1.;
  float fZ_in = -1.;
  int fParentTrackID = -1;
  ClassDef(ERBC404Digi, 1)
};

#endif


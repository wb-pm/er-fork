/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
//sonya:new variables x_in,y_in,z_in - enter point of neutron

#include "ERBC404Digi.h"

ERBC404Digi::ERBC404Digi(ERChannel hexNR, float edep, int parentTrackID, float lightYield, float time, 
                    float neutronProb, float x_in, float y_in, float z_in, float tac)
    : ERDigi(edep, time, hexNR), fParentTrackID(parentTrackID), fLightYield(lightYield),
        fNeutronProb(neutronProb), fX_in(x_in), fY_in(y_in), fZ_in(z_in) , fTAC(tac)
{}

ClassImp(ERBC404Digi)

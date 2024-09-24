/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERALPIDEPoint.h"

#include "FairLogger.h"
//--------------------------------------------------------------------------------------------------
ERALPIDEPoint::ERALPIDEPoint():
  FairMCPoint(),
  fX_out(0.), fY_out(0.), fZ_out(0.),
  fPx_out(0.), fPy_out(0.), fPz_out(0.) 
{
}

//--------------------------------------------------------------------------------------------------
ERALPIDEPoint::ERALPIDEPoint(Int_t eventID, Int_t trackID,
    Double_t mass,
    TVector3 posIn,
    TVector3 posOut, TVector3 momIn, TVector3 momOut,
    Double_t tof, Double_t length, Double_t eLoss, Int_t pdg,
    Int_t pixelNo):
  FairMCPoint(trackID, -1., posIn, momIn, tof, length, eLoss),
  fEventID(eventID),
  fX_out(posOut.X()), fY_out(posOut.Y()), fZ_out(posOut.Z()),
  fPx_out(momOut.X()), fPy_out(momOut.Y()), fPz_out(momOut.Z()),
  fPDG(pdg), fPixelNo(pixelNo) 
{
}

//--------------------------------------------------------------------------------------------------
ERALPIDEPoint::~ERALPIDEPoint() {
}

//--------------------------------------------------------------------------------------------------
void ERALPIDEPoint::Print(const Option_t* opt) const {
  LOG(INFO) << "ERALPIDEPoint: track " << fTrackID;
  LOG(INFO) << "    Position (" << fX << ", " << fY << ", " << fZ << ") cm" << FairLogger::endl;
  LOG(INFO) << "    Momentum (" << fPx << ", " << fPy << ", " << fPz << ") GeV" << FairLogger::endl;
  LOG(INFO) << "    Time " << fTime << " ns,  Length " << fLength << " cm" << FairLogger::endl;
  LOG(INFO) << "    Energy loss " << fELoss << " keV "<< FairLogger::endl;
  LOG(INFO) << "    Pixel number " << fPixelNo << FairLogger::endl;
}

//--------------------------------------------------------------------------------------------------
Double_t ERALPIDEPoint::GetX(Double_t z) const {
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fX_out+fX)/2.;
  Double_t dz = fZ_out - fZ;
  return ( fX + (z-fZ) / dz * (fX_out-fX) );
}

//--------------------------------------------------------------------------------------------------
Double_t ERALPIDEPoint::GetY(Double_t z) const {
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fY_out+fY)/2.;
  Double_t dz = fZ_out - fZ;
  return ( fY + (z-fZ) / dz * (fY_out-fY) );
}

//--------------------------------------------------------------------------------------------------
Bool_t ERALPIDEPoint::IsUsable() const {
  Double_t dz = fZ_out - fZ;
  if ( TMath::Abs(dz) < 1.e-4 ) return kFALSE;
  return kTRUE;
}

//--------------------------------------------------------------------------------------------------
ClassImp(ERALPIDEPoint)

/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERAlpidePoint.h"

#include "FairLogger.h"
//TODO: Fix having some duplicate methods
//-------------------------------------------------------------------------------------------------- Preferably not to use the default constructor!
ERAlpidePoint::ERAlpidePoint():
  FairMCPoint(),
  fX_out(0.), fY_out(0.), fZ_out(0.),
  fPx_out(0.), fPy_out(0.), fPz_out(0.) 
{
}

//--------------------------------------------------------------------------------------------------
ERAlpidePoint::ERAlpidePoint(Int_t eventID, Int_t trackID, Int_t mot0TrackID,
    Double_t mass,
    TVector3 posIn, TVector3 posInLocal,
    TVector3 posOut, TVector3 momIn, TVector3 momOut,
    Double_t tof, Double_t length, Double_t eLoss, Int_t pdg,
    Int_t pixelNoX, Int_t pixelNoY, Int_t pixelNoX_out, Int_t pixelNoY_out):
  FairMCPoint(trackID, -1., posIn, momIn, tof, length, eLoss,eventID),
  fMass(mass), fMot0TrackID(mot0TrackID),
  fX_in_local(posInLocal.X()),fY_in_local(posInLocal.Y()),fZ_in_local(posInLocal.Z()),
  fX_out(posOut.X()), fY_out(posOut.Y()), fZ_out(posOut.Z()),
  fPx_out(momOut.X()), fPy_out(momOut.Y()), fPz_out(momOut.Z()),
  fPDG(pdg), fPixelNoX(pixelNoX),fPixelNoY(pixelNoY), fPixelNoX_out(pixelNoX_out), fPixelNoY_out(pixelNoY_out) 
{
}

//--------------------------------------------------------------------------------------------------
ERAlpidePoint::~ERAlpidePoint() {
}

//--------------------------------------------------------------------------------------------------
void ERAlpidePoint::Print(const Option_t* opt) const {
  LOG(INFO) << "ERAlpidePoint: track " << fTrackID << ", event ID " << fEventId << FairLogger::endl;
  LOG(INFO) << "    Position (" << fX << ", " << fY << ", " << fZ << ") cm" << FairLogger::endl;
  LOG(INFO) << "    Momentum (" << fPx << ", " << fPy << ", " << fPz << ") GeV" << FairLogger::endl;
  LOG(INFO) << "    Mother track ID " << fMot0TrackID << ", Mass " << fMass << " GeV" << FairLogger::endl;
  LOG(INFO) << "    Time " << fTime << " ns,  Length " << fLength << " cm" << FairLogger::endl;
  LOG(INFO) << "    Energy loss " << fELoss << " MeV "<< FairLogger::endl;
  LOG(INFO) << "    Pixel number along x axis (in) " << fPixelNoX << ", along y axis (in): " << fPixelNoY << FairLogger::endl;
  LOG(INFO) << "    PDG: " << fPDG << FairLogger::endl;
}

//--------------------------------------------------------------------------------------------------
Double_t ERAlpidePoint::GetX(Double_t z) const {
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fX_out+fX)/2.;
  Double_t dz = fZ_out - fZ;
  return ( fX + (z-fZ) / dz * (fX_out-fX) );
}

//--------------------------------------------------------------------------------------------------
Double_t ERAlpidePoint::GetY(Double_t z) const {
  if ( (fZ_out-z)*(fZ-z) >= 0. ) return (fY_out+fY)/2.;
  Double_t dz = fZ_out - fZ;
  return ( fY + (z-fZ) / dz * (fY_out-fY) );
}

//--------------------------------------------------------------------------------------------------
Bool_t ERAlpidePoint::IsUsable() const {
  Double_t dz = fZ_out - fZ;
  if ( TMath::Abs(dz) < 1.e-4 ) return kFALSE;
  return kTRUE;
}

//--------------------------------------------------------------------------------------------------
ClassImp(ERAlpidePoint)

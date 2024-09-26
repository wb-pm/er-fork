/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
//Probably this class is not necessary
#include "ERALPIDEStep.h"

#include "TVector3.h"
#include "TVirtualMC.h"

#include "FairLogger.h"

#include "ERMCTrack.h"

// -----   Default constructor   -------------------------------------------
ERALPIDEStep::ERALPIDEStep()
  : fX(0.), fY(0.), fZ(0.),
    fPx(0.), fPy(0.), fPz(0.)
{
}
// -------------------------------------------------------------------------

// -----   Standard constructor   ------------------------------------------
ERALPIDEStep::ERALPIDEStep(Int_t eventID, Int_t stepNr,Int_t trackID,
		  Int_t pixelNo,
		  TVector3 pos, 
      TVector3 mom, 
		  Double_t tof, 
      Double_t length, 
      Int_t pid,
      Double_t mass,
      ExpertTrackingStatus trackStatus,
      Double_t eLoss,
      Double_t charge,
      TArrayI  processID)
  : fEventID(eventID), fStepNr(stepNr), fTrackID(trackID), fPixelNo(pixelNo),
    fX(pos.X()), fY(pos.Y()), fZ(pos.Z()),
    fPx(mom.X()), fPy(mom.Y()), fPz(mom.Z()),
    fTOF(tof), fLength(length), fPID(pid), fMass(mass),
    fTrackStatus(trackStatus),
    fEloss(eLoss),
    fCharge(charge),
    fProcessID(processID)
{
}
// -------------------------------------------------------------------------



// -------------------------------------------------------------------------
ERALPIDEStep::ERALPIDEStep(const ERALPIDEStep& right)
  : fEventID(right.fEventID),  fStepNr(right.fStepNr), fTrackID(right.fTrackID), 
    fPixelNo(right.fPixelNo),
    fX(right.fX), fY(right.fY), fZ(right.fZ),
    fPx(right.fPx), fPy(right.fPy), fPz(right.fPz),
    fTOF(right.fTOF), fLength(right.fLength), fPID(right.fPID),fMass(right.fMass),
    fTrackStatus(right.fTrackStatus),
    fEloss(right.fEloss), fCharge(right.fCharge), fProcessID(right.fProcessID)
{
}
// -------------------------------------------------------------------------



// -----   Destructor   ----------------------------------------------------
ERALPIDEStep::~ERALPIDEStep()
{
}
// -------------------------------------------------------------------------

// -----   Public method Print   ---------------------------------------
void ERALPIDEStep::Print()
{
  // Particle being tracked
  const char *sParticle;
  
  switch(fPID){
    case 2212:          sParticle="proton"    ;break;
    case 2112:          sParticle="neutron"   ;break;
    case 22:            sParticle="gamma"     ;break;
    case 50000050:      sParticle="ckov"      ;break;
    case 111:           sParticle="pi0"       ;break;  
    case 211:           sParticle="pi+"       ;break;  
    case -211:          sParticle="Pi-"       ;break;  
    case 1000010020:    sParticle="deuteron"  ;break;
    case 1000010030:    sParticle="triton"    ;break;
    case 1000020030:    sParticle="he3"       ;break;
    case 1000020040:    sParticle="alpha"     ;break;
    default:            sParticle="not known" ;break;
  }
  
  LOG(INFO) << "-I- STEPINFO:" << FairLogger::endl;
  TString flag;
  switch (fTrackStatus) {
    case Entering :      flag="enters to";               break;
    case Exiting :  flag="exits from";              break;
    case Inside :   flag="inside";                  break;
    case Stop :     flag="stopped in";              break;
    default:                                        flag="unknown tracking status"; break;  
  }
  
  LOG(INFO) << "STEP = " << fStepNr << " particle="<< sParticle << "(" << fPID << ") Edep = " 
            << fEloss << "[KeV]" << FairLogger::endl;
  LOG(INFO) << "track_status = "  << flag.Data() << " track_charge = " << fCharge 
            << "track_nb = " << fTrackID << FairLogger::endl;
  LOG(INFO) << "track_pos = "  << fX << " " << fY << " " << fZ << FairLogger::endl;
  LOG(INFO) << "track_mom = "  << fPx << " " << fPy << " " << fPz << FairLogger::endl;
  
  for ( int i = 0 ; i < fProcessID.GetSize(); i++){
    //if(proc.At(i)!=22 && proc.At(i)!=23 && proc.At(i)!=31 && proc.At(i)!=43 &&  proc.At(i)!=13){
    LOG(INFO) << "process: " << fProcessID.At(i) <<"  "<< TMCProcessName[fProcessID.At(i)] 
              << FairLogger::endl;
	}
  LOG(INFO) << FairLogger::endl;
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ExpertTrackingStatus ERALPIDEStep::GetTrackStatus(){
  if(gMC->IsTrackAlive()) {
    if(gMC->IsTrackEntering())      
      return Entering;
    else if(gMC->IsTrackExiting())  
      return Exiting;
    else if(gMC->IsTrackInside())   
      return Inside;
  } else {
    return Stop;
  }
  
}
// ----------------------------------------------------------------------------

ClassImp(ERALPIDEStep)
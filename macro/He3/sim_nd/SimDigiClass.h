//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 11 12:02:28 2023 by ROOT version 6.10/08
// from TTree er//cbmroot
// found on file: sim_digi.root
//////////////////////////////////////////////////////////

#ifndef SimDigiClass_h
#define SimDigiClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "FairMultiLinkedData_Interface.h"
#include "ERNDPoint.h"
#include "ERNDDigi.h"
#include "TNamed.h"

class SimDigiClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxcbmroot_Stack_MCTrack = 6137;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y = 6;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y = 5;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y = 5;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y = 4;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y = 9;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X = 8;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X = 3;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y = 3;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y = 3;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y = 2;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y = 2;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y = 2;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y = 2;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X = 3;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X = 2;
   static constexpr Int_t kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y = 2;
   static constexpr Int_t kMaxcbmroot_BeamDet_BeamDetToFPoint = 6;
   static constexpr Int_t kMaxcbmroot_BeamDet_BeamDetMWPCPoint = 27;
   static constexpr Int_t kMaxcbmroot_ND_NDPoint = 2;
   static constexpr Int_t kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1 = 1;
   static constexpr Int_t kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2 = 1;
   static constexpr Int_t kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1 = 17;
   static constexpr Int_t kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2 = 19;
   static constexpr Int_t kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1 = 15;
   static constexpr Int_t kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2 = 17;
   static constexpr Int_t kMaxcbmroot_ND digi_NDDigi = 1;
   static constexpr Int_t kMaxcbmroot_Event_MCEventHeader = 1;

   // Declaration of leaf types
   Int_t           MCTrack_;
   UInt_t          MCTrack_fUniqueID[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   UInt_t          MCTrack_fBits[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Int_t           MCTrack_fID[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Int_t           MCTrack_fPdgCode[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Int_t           MCTrack_fMotherId[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fPx[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fPy[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fPz[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fStartX[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fStartY[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fStartZ[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double32_t      MCTrack_fStartT[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Int_t           MCTrack_fNPoints[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double_t        MCTrack_fMass[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double_t        MCTrack_fEnergy[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double_t        MCTrack_fTheta[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   Double_t        MCTrack_fPhi[kMaxcbmroot_Stack_MCTrack];   //[cbmroot.Stack.MCTrack_]
   TLorentzVector  MCTrack_fMomentum[kMaxcbmroot_Stack_MCTrack];
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_;
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   UInt_t          TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double32_t      TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Double_t        TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_;
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_;
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fBits[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   UInt_t          TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventId[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTime[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fELoss[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fDetectorID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMot0TrackID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fVolNb[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMass[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fXlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fYlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZlocal[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double32_t      TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz_out[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeIn[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeOut[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLightYield[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPID[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fCharge[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Double_t        TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackLength[kMaxcbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_]
   Int_t           TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_;
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_]
   UInt_t          TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_]
   UShort_t        TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_]
   Float_t         TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_]
   Int_t           TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_;
   UInt_t          TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_]
   UInt_t          TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_]
   UShort_t        TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_]
   Float_t         TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_]
   Float_t         TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_]
   Int_t           TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_;
   UInt_t          TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_]
   UInt_t          TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fBits[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_]
   UShort_t        TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fChannel[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_]
   Float_t         TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fTime[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_]
   Float_t         TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fEdep[kMaxcbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y];   //[cbmroot.Telescope.TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_]
   Int_t           BeamDetToFPoint_;
   UInt_t          BeamDetToFPoint_fUniqueID[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   UInt_t          BeamDetToFPoint_fBits[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fTrackID[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   UInt_t          BeamDetToFPoint_fEventId[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPx[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPy[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPz[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fTime[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fLength[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fELoss[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fDetectorID[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fX[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fY[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fZ[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fEventID[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fMot0TrackID[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fPid[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fX_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fY_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fZ_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPx_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPy_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double32_t      BeamDetToFPoint_fPz_out[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Double_t        BeamDetToFPoint_fLightYield[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetToFPoint_fToFNb[kMaxcbmroot_BeamDet_BeamDetToFPoint];   //[cbmroot.BeamDet.BeamDetToFPoint_]
   Int_t           BeamDetMWPCPoint_;
   UInt_t          BeamDetMWPCPoint_fUniqueID[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   UInt_t          BeamDetMWPCPoint_fBits[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fTrackID[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   UInt_t          BeamDetMWPCPoint_fEventId[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPx[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPy[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPz[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fTime[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fLength[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fELoss[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fDetectorID[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fX[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fY[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fZ[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fEventID[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fMot0TrackID[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fPid[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fX_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fY_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fZ_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPx_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPy_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double32_t      BeamDetMWPCPoint_fPz_out[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Double_t        BeamDetMWPCPoint_fLightYield[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fMWPCNb[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fPlaneNb[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           BeamDetMWPCPoint_fWireNb[kMaxcbmroot_BeamDet_BeamDetMWPCPoint];   //[cbmroot.BeamDet.BeamDetMWPCPoint_]
   Int_t           NDPoint_;
   UInt_t          NDPoint_fUniqueID[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   UInt_t          NDPoint_fBits[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fTrackID[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   UInt_t          NDPoint_fEventId[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPx[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPy[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPz[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fTime[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fLength[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fELoss[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fDetectorID[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fX[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fY[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fZ[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fEventID[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fMot0TrackID[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double_t        NDPoint_fMass[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fX_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fY_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fZ_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPx_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPy_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Double32_t      NDPoint_fPz_out[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fStilbenNr[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Float_t         NDPoint_fLightYield[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fPdg[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fParentTrackId[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           NDPoint_fParentPdgId[kMaxcbmroot_ND_NDPoint];   //[cbmroot.ND.NDPoint_]
   Int_t           BeamDetToFDigi1_;
   UInt_t          BeamDetToFDigi1_fUniqueID[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi1_]
   UInt_t          BeamDetToFDigi1_fBits[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi1_]
   UShort_t        BeamDetToFDigi1_fChannel[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi1_]
   Float_t         BeamDetToFDigi1_fTime[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi1_]
   Float_t         BeamDetToFDigi1_fEdep[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi1];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi1_]
   Int_t           BeamDetToFDigi2_;
   UInt_t          BeamDetToFDigi2_fUniqueID[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi2_]
   UInt_t          BeamDetToFDigi2_fBits[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi2_]
   UShort_t        BeamDetToFDigi2_fChannel[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi2_]
   Float_t         BeamDetToFDigi2_fTime[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi2_]
   Float_t         BeamDetToFDigi2_fEdep[kMaxcbmroot_BeamDetToF Digi_BeamDetToFDigi2];   //[cbmroot.BeamDetToF Digi.BeamDetToFDigi2_]
   Int_t           BeamDetMWPCDigiX1_;
   UInt_t          BeamDetMWPCDigiX1_fUniqueID[kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1];   //[cbmroot.BeamDetMWPC x1 Digi.BeamDetMWPCDigiX1_]
   UInt_t          BeamDetMWPCDigiX1_fBits[kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1];   //[cbmroot.BeamDetMWPC x1 Digi.BeamDetMWPCDigiX1_]
   UShort_t        BeamDetMWPCDigiX1_fChannel[kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1];   //[cbmroot.BeamDetMWPC x1 Digi.BeamDetMWPCDigiX1_]
   Float_t         BeamDetMWPCDigiX1_fTime[kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1];   //[cbmroot.BeamDetMWPC x1 Digi.BeamDetMWPCDigiX1_]
   Float_t         BeamDetMWPCDigiX1_fEdep[kMaxcbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1];   //[cbmroot.BeamDetMWPC x1 Digi.BeamDetMWPCDigiX1_]
   Int_t           BeamDetMWPCDigiX2_;
   UInt_t          BeamDetMWPCDigiX2_fUniqueID[kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2];   //[cbmroot.BeamDetMWPC x2 Digi.BeamDetMWPCDigiX2_]
   UInt_t          BeamDetMWPCDigiX2_fBits[kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2];   //[cbmroot.BeamDetMWPC x2 Digi.BeamDetMWPCDigiX2_]
   UShort_t        BeamDetMWPCDigiX2_fChannel[kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2];   //[cbmroot.BeamDetMWPC x2 Digi.BeamDetMWPCDigiX2_]
   Float_t         BeamDetMWPCDigiX2_fTime[kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2];   //[cbmroot.BeamDetMWPC x2 Digi.BeamDetMWPCDigiX2_]
   Float_t         BeamDetMWPCDigiX2_fEdep[kMaxcbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2];   //[cbmroot.BeamDetMWPC x2 Digi.BeamDetMWPCDigiX2_]
   Int_t           BeamDetMWPCDigiY1_;
   UInt_t          BeamDetMWPCDigiY1_fUniqueID[kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1];   //[cbmroot.BeamDetMWPC y1 Digi.BeamDetMWPCDigiY1_]
   UInt_t          BeamDetMWPCDigiY1_fBits[kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1];   //[cbmroot.BeamDetMWPC y1 Digi.BeamDetMWPCDigiY1_]
   UShort_t        BeamDetMWPCDigiY1_fChannel[kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1];   //[cbmroot.BeamDetMWPC y1 Digi.BeamDetMWPCDigiY1_]
   Float_t         BeamDetMWPCDigiY1_fTime[kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1];   //[cbmroot.BeamDetMWPC y1 Digi.BeamDetMWPCDigiY1_]
   Float_t         BeamDetMWPCDigiY1_fEdep[kMaxcbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1];   //[cbmroot.BeamDetMWPC y1 Digi.BeamDetMWPCDigiY1_]
   Int_t           BeamDetMWPCDigiY2_;
   UInt_t          BeamDetMWPCDigiY2_fUniqueID[kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2];   //[cbmroot.BeamDetMWPC y2 Digi.BeamDetMWPCDigiY2_]
   UInt_t          BeamDetMWPCDigiY2_fBits[kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2];   //[cbmroot.BeamDetMWPC y2 Digi.BeamDetMWPCDigiY2_]
   UShort_t        BeamDetMWPCDigiY2_fChannel[kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2];   //[cbmroot.BeamDetMWPC y2 Digi.BeamDetMWPCDigiY2_]
   Float_t         BeamDetMWPCDigiY2_fTime[kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2];   //[cbmroot.BeamDetMWPC y2 Digi.BeamDetMWPCDigiY2_]
   Float_t         BeamDetMWPCDigiY2_fEdep[kMaxcbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2];   //[cbmroot.BeamDetMWPC y2 Digi.BeamDetMWPCDigiY2_]
   Int_t           NDDigi_;
   UInt_t          NDDigi_fUniqueID[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   UInt_t          NDDigi_fBits[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   UShort_t        NDDigi_fChannel[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fTime[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fEdep[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fLightYield[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fNeutronProb[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fTAC[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fX_in[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fY_in[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fZ_in[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fEdep_n1[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fEdep_n2[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Float_t         NDDigi_fEdep_mis[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   Int_t           NDDigi_fParentTrackID[kMaxcbmroot_ND digi_NDDigi];   //[cbmroot.ND digi.NDDigi_]
   ER3Hto3HeEventHeader *MCEventHeader_;
   UInt_t          MCEventHeader_ERDecayMCEventHeader_fUniqueID;
   UInt_t          MCEventHeader_ERDecayMCEventHeader_fBits;
   TString         MCEventHeader_ERDecayMCEventHeader_fName;
   TString         MCEventHeader_ERDecayMCEventHeader_fTitle;
   UInt_t          MCEventHeader_ERDecayMCEventHeader_fRunId;
   UInt_t          MCEventHeader_ERDecayMCEventHeader_fEventId;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fX;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fY;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fZ;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fT;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fB;
   Int_t           MCEventHeader_ERDecayMCEventHeader_fNPrim;
   Bool_t          MCEventHeader_ERDecayMCEventHeader_fIsSet;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fRotX;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fRotY;
   Double32_t      MCEventHeader_ERDecayMCEventHeader_fRotZ;
   TVector3        MCEventHeader_ERDecayMCEventHeader_fReactionPos;
   Int_t           MCEventHeader_ERDecayMCEventHeader_fInputTrackID;
   TArrayI         MCEventHeader_ERDecayMCEventHeader_fOutputTrackID;
   Int_t           MCEventHeader_ERDecayMCEventHeader_fOutputsTracksNb;
   Int_t           MCEventHeader_ERDecayMCEventHeader_fTrigger;
   Int_t           MCEventHeader_ERDecayMCEventHeader_fTriggerPriority;
   TLorentzVector  MCEventHeader_fH3;
   TLorentzVector  MCEventHeader_fH1;
   TLorentzVector  MCEventHeader_fn1;
   TLorentzVector  MCEventHeader_fHe3;
   Int_t           MCEventHeader_fTrigger;
   Int_t           MCEventHeader_fTriggerPriority;
   Float_t         MCEventHeader_fTime;

   // List of branches
   TBranch        *b_cbmroot_Stack_MCTrack_;   //!
   TBranch        *b_MCTrack_fUniqueID;   //!
   TBranch        *b_MCTrack_fBits;   //!
   TBranch        *b_MCTrack_fID;   //!
   TBranch        *b_MCTrack_fPdgCode;   //!
   TBranch        *b_MCTrack_fMotherId;   //!
   TBranch        *b_MCTrack_fPx;   //!
   TBranch        *b_MCTrack_fPy;   //!
   TBranch        *b_MCTrack_fPz;   //!
   TBranch        *b_MCTrack_fStartX;   //!
   TBranch        *b_MCTrack_fStartY;   //!
   TBranch        *b_MCTrack_fStartZ;   //!
   TBranch        *b_MCTrack_fStartT;   //!
   TBranch        *b_MCTrack_fNPoints;   //!
   TBranch        *b_MCTrack_fMass;   //!
   TBranch        *b_MCTrack_fEnergy;   //!
   TBranch        *b_MCTrack_fTheta;   //!
   TBranch        *b_MCTrack_fPhi;   //!
   TBranch        *b_MCTrack_fMomentum;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fBits;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventId;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTime;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLength;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fELoss;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fDetectorID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMot0TrackID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fVolNb;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMass;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fXlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fYlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZlocal;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz_out;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeIn;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeOut;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLightYield;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPID;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fCharge;   //!
   TBranch        *b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fEdep;   //!
   TBranch        *b_cbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fBits;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fChannel;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fTime;   //!
   TBranch        *b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fEdep;   //!
   TBranch        *b_cbmroot_BeamDet_BeamDetToFPoint_;   //!
   TBranch        *b_BeamDetToFPoint_fUniqueID;   //!
   TBranch        *b_BeamDetToFPoint_fBits;   //!
   TBranch        *b_BeamDetToFPoint_fTrackID;   //!
   TBranch        *b_BeamDetToFPoint_fEventId;   //!
   TBranch        *b_BeamDetToFPoint_fPx;   //!
   TBranch        *b_BeamDetToFPoint_fPy;   //!
   TBranch        *b_BeamDetToFPoint_fPz;   //!
   TBranch        *b_BeamDetToFPoint_fTime;   //!
   TBranch        *b_BeamDetToFPoint_fLength;   //!
   TBranch        *b_BeamDetToFPoint_fELoss;   //!
   TBranch        *b_BeamDetToFPoint_fDetectorID;   //!
   TBranch        *b_BeamDetToFPoint_fX;   //!
   TBranch        *b_BeamDetToFPoint_fY;   //!
   TBranch        *b_BeamDetToFPoint_fZ;   //!
   TBranch        *b_BeamDetToFPoint_fEventID;   //!
   TBranch        *b_BeamDetToFPoint_fMot0TrackID;   //!
   TBranch        *b_BeamDetToFPoint_fPid;   //!
   TBranch        *b_BeamDetToFPoint_fX_out;   //!
   TBranch        *b_BeamDetToFPoint_fY_out;   //!
   TBranch        *b_BeamDetToFPoint_fZ_out;   //!
   TBranch        *b_BeamDetToFPoint_fPx_out;   //!
   TBranch        *b_BeamDetToFPoint_fPy_out;   //!
   TBranch        *b_BeamDetToFPoint_fPz_out;   //!
   TBranch        *b_BeamDetToFPoint_fLightYield;   //!
   TBranch        *b_BeamDetToFPoint_fToFNb;   //!
   TBranch        *b_cbmroot_BeamDet_BeamDetMWPCPoint_;   //!
   TBranch        *b_BeamDetMWPCPoint_fUniqueID;   //!
   TBranch        *b_BeamDetMWPCPoint_fBits;   //!
   TBranch        *b_BeamDetMWPCPoint_fTrackID;   //!
   TBranch        *b_BeamDetMWPCPoint_fEventId;   //!
   TBranch        *b_BeamDetMWPCPoint_fPx;   //!
   TBranch        *b_BeamDetMWPCPoint_fPy;   //!
   TBranch        *b_BeamDetMWPCPoint_fPz;   //!
   TBranch        *b_BeamDetMWPCPoint_fTime;   //!
   TBranch        *b_BeamDetMWPCPoint_fLength;   //!
   TBranch        *b_BeamDetMWPCPoint_fELoss;   //!
   TBranch        *b_BeamDetMWPCPoint_fDetectorID;   //!
   TBranch        *b_BeamDetMWPCPoint_fX;   //!
   TBranch        *b_BeamDetMWPCPoint_fY;   //!
   TBranch        *b_BeamDetMWPCPoint_fZ;   //!
   TBranch        *b_BeamDetMWPCPoint_fEventID;   //!
   TBranch        *b_BeamDetMWPCPoint_fMot0TrackID;   //!
   TBranch        *b_BeamDetMWPCPoint_fPid;   //!
   TBranch        *b_BeamDetMWPCPoint_fX_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fY_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fZ_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fPx_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fPy_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fPz_out;   //!
   TBranch        *b_BeamDetMWPCPoint_fLightYield;   //!
   TBranch        *b_BeamDetMWPCPoint_fMWPCNb;   //!
   TBranch        *b_BeamDetMWPCPoint_fPlaneNb;   //!
   TBranch        *b_BeamDetMWPCPoint_fWireNb;   //!
   TBranch        *b_cbmroot_ND_NDPoint_;   //!
   TBranch        *b_NDPoint_fUniqueID;   //!
   TBranch        *b_NDPoint_fBits;   //!
   TBranch        *b_NDPoint_fTrackID;   //!
   TBranch        *b_NDPoint_fEventId;   //!
   TBranch        *b_NDPoint_fPx;   //!
   TBranch        *b_NDPoint_fPy;   //!
   TBranch        *b_NDPoint_fPz;   //!
   TBranch        *b_NDPoint_fTime;   //!
   TBranch        *b_NDPoint_fLength;   //!
   TBranch        *b_NDPoint_fELoss;   //!
   TBranch        *b_NDPoint_fDetectorID;   //!
   TBranch        *b_NDPoint_fX;   //!
   TBranch        *b_NDPoint_fY;   //!
   TBranch        *b_NDPoint_fZ;   //!
   TBranch        *b_NDPoint_fEventID;   //!
   TBranch        *b_NDPoint_fMot0TrackID;   //!
   TBranch        *b_NDPoint_fMass;   //!
   TBranch        *b_NDPoint_fX_out;   //!
   TBranch        *b_NDPoint_fY_out;   //!
   TBranch        *b_NDPoint_fZ_out;   //!
   TBranch        *b_NDPoint_fPx_out;   //!
   TBranch        *b_NDPoint_fPy_out;   //!
   TBranch        *b_NDPoint_fPz_out;   //!
   TBranch        *b_NDPoint_fStilbenNr;   //!
   TBranch        *b_NDPoint_fLightYield;   //!
   TBranch        *b_NDPoint_fPdg;   //!
   TBranch        *b_NDPoint_fParentTrackId;   //!
   TBranch        *b_NDPoint_fParentPdgId;   //!
   TBranch        *b_cbmroot_BeamDetToF Digi_BeamDetToFDigi1_;   //!
   TBranch        *b_BeamDetToFDigi1_fUniqueID;   //!
   TBranch        *b_BeamDetToFDigi1_fBits;   //!
   TBranch        *b_BeamDetToFDigi1_fChannel;   //!
   TBranch        *b_BeamDetToFDigi1_fTime;   //!
   TBranch        *b_BeamDetToFDigi1_fEdep;   //!
   TBranch        *b_cbmroot_BeamDetToF Digi_BeamDetToFDigi2_;   //!
   TBranch        *b_BeamDetToFDigi2_fUniqueID;   //!
   TBranch        *b_BeamDetToFDigi2_fBits;   //!
   TBranch        *b_BeamDetToFDigi2_fChannel;   //!
   TBranch        *b_BeamDetToFDigi2_fTime;   //!
   TBranch        *b_BeamDetToFDigi2_fEdep;   //!
   TBranch        *b_cbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1_;   //!
   TBranch        *b_BeamDetMWPCDigiX1_fUniqueID;   //!
   TBranch        *b_BeamDetMWPCDigiX1_fBits;   //!
   TBranch        *b_BeamDetMWPCDigiX1_fChannel;   //!
   TBranch        *b_BeamDetMWPCDigiX1_fTime;   //!
   TBranch        *b_BeamDetMWPCDigiX1_fEdep;   //!
   TBranch        *b_cbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2_;   //!
   TBranch        *b_BeamDetMWPCDigiX2_fUniqueID;   //!
   TBranch        *b_BeamDetMWPCDigiX2_fBits;   //!
   TBranch        *b_BeamDetMWPCDigiX2_fChannel;   //!
   TBranch        *b_BeamDetMWPCDigiX2_fTime;   //!
   TBranch        *b_BeamDetMWPCDigiX2_fEdep;   //!
   TBranch        *b_cbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1_;   //!
   TBranch        *b_BeamDetMWPCDigiY1_fUniqueID;   //!
   TBranch        *b_BeamDetMWPCDigiY1_fBits;   //!
   TBranch        *b_BeamDetMWPCDigiY1_fChannel;   //!
   TBranch        *b_BeamDetMWPCDigiY1_fTime;   //!
   TBranch        *b_BeamDetMWPCDigiY1_fEdep;   //!
   TBranch        *b_cbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2_;   //!
   TBranch        *b_BeamDetMWPCDigiY2_fUniqueID;   //!
   TBranch        *b_BeamDetMWPCDigiY2_fBits;   //!
   TBranch        *b_BeamDetMWPCDigiY2_fChannel;   //!
   TBranch        *b_BeamDetMWPCDigiY2_fTime;   //!
   TBranch        *b_BeamDetMWPCDigiY2_fEdep;   //!
   TBranch        *b_cbmroot_ND digi_NDDigi_;   //!
   TBranch        *b_NDDigi_fUniqueID;   //!
   TBranch        *b_NDDigi_fBits;   //!
   TBranch        *b_NDDigi_fChannel;   //!
   TBranch        *b_NDDigi_fTime;   //!
   TBranch        *b_NDDigi_fEdep;   //!
   TBranch        *b_NDDigi_fLightYield;   //!
   TBranch        *b_NDDigi_fNeutronProb;   //!
   TBranch        *b_NDDigi_fTAC;   //!
   TBranch        *b_NDDigi_fX_in;   //!
   TBranch        *b_NDDigi_fY_in;   //!
   TBranch        *b_NDDigi_fZ_in;   //!
   TBranch        *b_NDDigi_fEdep_n1;   //!
   TBranch        *b_NDDigi_fEdep_n2;   //!
   TBranch        *b_NDDigi_fEdep_mis;   //!
   TBranch        *b_NDDigi_fParentTrackID;   //!
   TBranch        *b_cbmroot_Event_MCEventHeader_;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fUniqueID;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fBits;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fName;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTitle;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRunId;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fEventId;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fX;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fY;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fZ;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fT;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fB;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fNPrim;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fIsSet;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotX;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotY;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotZ;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fReactionPos;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fInputTrackID;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fOutputTrackID;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fOutputsTracksNb;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTrigger;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTriggerPriority;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fH3;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fH1;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fn1;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fHe3;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTrigger;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTriggerPriority;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTime;   //!

   SimDigiClass(TTree *tree=0);
   virtual ~SimDigiClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SimDigiClass_cxx
SimDigiClass::SimDigiClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("sim_digi.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("sim_digi.root");
      }
      f->GetObject("er",tree);

   }
   Init(tree);
}

SimDigiClass::~SimDigiClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SimDigiClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SimDigiClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SimDigiClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   MCEventHeader_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("MCTrack", &MCTrack_, &b_cbmroot_Stack_MCTrack_);
   fChain->SetBranchAddress("MCTrack.fUniqueID", MCTrack_fUniqueID, &b_MCTrack_fUniqueID);
   fChain->SetBranchAddress("MCTrack.fBits", MCTrack_fBits, &b_MCTrack_fBits);
   fChain->SetBranchAddress("MCTrack.fID", MCTrack_fID, &b_MCTrack_fID);
   fChain->SetBranchAddress("MCTrack.fPdgCode", MCTrack_fPdgCode, &b_MCTrack_fPdgCode);
   fChain->SetBranchAddress("MCTrack.fMotherId", MCTrack_fMotherId, &b_MCTrack_fMotherId);
   fChain->SetBranchAddress("MCTrack.fPx", MCTrack_fPx, &b_MCTrack_fPx);
   fChain->SetBranchAddress("MCTrack.fPy", MCTrack_fPy, &b_MCTrack_fPy);
   fChain->SetBranchAddress("MCTrack.fPz", MCTrack_fPz, &b_MCTrack_fPz);
   fChain->SetBranchAddress("MCTrack.fStartX", MCTrack_fStartX, &b_MCTrack_fStartX);
   fChain->SetBranchAddress("MCTrack.fStartY", MCTrack_fStartY, &b_MCTrack_fStartY);
   fChain->SetBranchAddress("MCTrack.fStartZ", MCTrack_fStartZ, &b_MCTrack_fStartZ);
   fChain->SetBranchAddress("MCTrack.fStartT", MCTrack_fStartT, &b_MCTrack_fStartT);
   fChain->SetBranchAddress("MCTrack.fNPoints", MCTrack_fNPoints, &b_MCTrack_fNPoints);
   fChain->SetBranchAddress("MCTrack.fMass", MCTrack_fMass, &b_MCTrack_fMass);
   fChain->SetBranchAddress("MCTrack.fEnergy", MCTrack_fEnergy, &b_MCTrack_fEnergy);
   fChain->SetBranchAddress("MCTrack.fTheta", MCTrack_fTheta, &b_MCTrack_fTheta);
   fChain->SetBranchAddress("MCTrack.fPhi", MCTrack_fPhi, &b_MCTrack_fPhi);
   fChain->SetBranchAddress("MCTrack.fMomentum", MCTrack_fMomentum, &b_MCTrack_fMomentum);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y", &TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_1_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y", &TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_2_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y", &TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_3_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y", &TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_4_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y", &TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_5_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X", &TelescopePoint_Telescope_he8_SingleSi_SSD20_X_, &b_cbmroot_Telescope_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fUniqueID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fUniqueID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fBits", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fBits, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fTrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fEventId", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventId, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPx", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPy", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPz", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fTime", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTime, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fELoss", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fELoss, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fDetectorID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fDetectorID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fX", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fY", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fZ", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fEventID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fMot0TrackID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMot0TrackID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fVolNb", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fVolNb, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fMass", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMass, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fXlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fXlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fYlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fYlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fZlocal", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZlocal, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fX_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fY_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fZ_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPx_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPy_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPz_out", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz_out, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fTimeIn", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeIn, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fTimeOut", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeOut, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fLightYield", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLightYield, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fPID", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPID, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fCharge", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fCharge, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_he8_SingleSi_SSD20_X.fTrackLength", TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackLength, &b_TelescopePoint_Telescope_he8_SingleSi_SSD20_X_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X", &TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_, &b_cbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fUniqueID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fUniqueID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fBits", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fBits, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fTrackID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fEventId", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventId, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPx", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPy", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPz", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fTime", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTime, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fLength", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLength, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fELoss", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fELoss, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fDetectorID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fDetectorID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fX", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fY", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fZ", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fEventID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fMot0TrackID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMot0TrackID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fVolNb", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fVolNb, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fMass", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMass, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fXlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fXlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fYlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fYlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fZlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fX_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fY_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fZ_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPx_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPy_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPz_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fTimeIn", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeIn, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fTimeOut", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeOut, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fLightYield", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLightYield, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fPID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fCharge", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fCharge, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_X.fTrackLength", TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackLength, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_X_fTrackLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y", &TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_, &b_cbmroot_Telescope_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fUniqueID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fBits", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fBits, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fBits);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fTrackID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fEventId", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventId, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventId);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPx", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPy", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPz", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fTime", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTime, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTime);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fLength", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLength, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLength);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fELoss", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fELoss, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fELoss);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fDetectorID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fDetectorID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fDetectorID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fX", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fY", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fZ", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fEventID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fEventID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fMot0TrackID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMot0TrackID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMot0TrackID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fVolNb", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fVolNb, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fVolNb);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fMass", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMass, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fMass);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fXlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fXlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fXlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fYlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fYlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fYlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fZlocal", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZlocal, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZlocal);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fX_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fX_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fY_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fY_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fZ_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fZ_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPx_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPx_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPy_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPy_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPz_out", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz_out, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPz_out);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fTimeIn", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeIn, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeIn);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fTimeOut", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeOut, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTimeOut);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fLightYield", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLightYield, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fLightYield);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fPID", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPID, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fPID);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fCharge", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fCharge, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fCharge);
   fChain->SetBranchAddress("TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y.fTrackLength", TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackLength, &b_TelescopePoint_Telescope_proton_DoubleSi_R_XY_Y_fTrackLength);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X", &TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fUniqueID", TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fUniqueID, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fBits", TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fBits, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fChannel", TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fChannel, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fTime", TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fTime, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fEdep", TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fEdep, &b_TelescopeDigi_Telescope_he8_SingleSi_SSD20_X_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X", &TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X.fUniqueID", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fUniqueID, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X.fBits", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fBits, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X.fChannel", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fChannel, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X.fTime", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fTime, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X.fEdep", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fEdep, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_X_fEdep);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y", &TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_, &b_cbmroot_Telescope_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y.fUniqueID", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y.fBits", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fBits, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fBits);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y.fChannel", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fChannel, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fChannel);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y.fTime", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fTime, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fTime);
   fChain->SetBranchAddress("TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y.fEdep", TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fEdep, &b_TelescopeDigi_Telescope_proton_DoubleSi_R_XY_Y_fEdep);
   fChain->SetBranchAddress("BeamDetToFPoint", &BeamDetToFPoint_, &b_cbmroot_BeamDet_BeamDetToFPoint_);
   fChain->SetBranchAddress("BeamDetToFPoint.fUniqueID", BeamDetToFPoint_fUniqueID, &b_BeamDetToFPoint_fUniqueID);
   fChain->SetBranchAddress("BeamDetToFPoint.fBits", BeamDetToFPoint_fBits, &b_BeamDetToFPoint_fBits);
   fChain->SetBranchAddress("BeamDetToFPoint.fTrackID", BeamDetToFPoint_fTrackID, &b_BeamDetToFPoint_fTrackID);
   fChain->SetBranchAddress("BeamDetToFPoint.fEventId", BeamDetToFPoint_fEventId, &b_BeamDetToFPoint_fEventId);
   fChain->SetBranchAddress("BeamDetToFPoint.fPx", BeamDetToFPoint_fPx, &b_BeamDetToFPoint_fPx);
   fChain->SetBranchAddress("BeamDetToFPoint.fPy", BeamDetToFPoint_fPy, &b_BeamDetToFPoint_fPy);
   fChain->SetBranchAddress("BeamDetToFPoint.fPz", BeamDetToFPoint_fPz, &b_BeamDetToFPoint_fPz);
   fChain->SetBranchAddress("BeamDetToFPoint.fTime", BeamDetToFPoint_fTime, &b_BeamDetToFPoint_fTime);
   fChain->SetBranchAddress("BeamDetToFPoint.fLength", BeamDetToFPoint_fLength, &b_BeamDetToFPoint_fLength);
   fChain->SetBranchAddress("BeamDetToFPoint.fELoss", BeamDetToFPoint_fELoss, &b_BeamDetToFPoint_fELoss);
   fChain->SetBranchAddress("BeamDetToFPoint.fDetectorID", BeamDetToFPoint_fDetectorID, &b_BeamDetToFPoint_fDetectorID);
   fChain->SetBranchAddress("BeamDetToFPoint.fX", BeamDetToFPoint_fX, &b_BeamDetToFPoint_fX);
   fChain->SetBranchAddress("BeamDetToFPoint.fY", BeamDetToFPoint_fY, &b_BeamDetToFPoint_fY);
   fChain->SetBranchAddress("BeamDetToFPoint.fZ", BeamDetToFPoint_fZ, &b_BeamDetToFPoint_fZ);
   fChain->SetBranchAddress("BeamDetToFPoint.fEventID", BeamDetToFPoint_fEventID, &b_BeamDetToFPoint_fEventID);
   fChain->SetBranchAddress("BeamDetToFPoint.fMot0TrackID", BeamDetToFPoint_fMot0TrackID, &b_BeamDetToFPoint_fMot0TrackID);
   fChain->SetBranchAddress("BeamDetToFPoint.fPid", BeamDetToFPoint_fPid, &b_BeamDetToFPoint_fPid);
   fChain->SetBranchAddress("BeamDetToFPoint.fX_out", BeamDetToFPoint_fX_out, &b_BeamDetToFPoint_fX_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fY_out", BeamDetToFPoint_fY_out, &b_BeamDetToFPoint_fY_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fZ_out", BeamDetToFPoint_fZ_out, &b_BeamDetToFPoint_fZ_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fPx_out", BeamDetToFPoint_fPx_out, &b_BeamDetToFPoint_fPx_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fPy_out", BeamDetToFPoint_fPy_out, &b_BeamDetToFPoint_fPy_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fPz_out", BeamDetToFPoint_fPz_out, &b_BeamDetToFPoint_fPz_out);
   fChain->SetBranchAddress("BeamDetToFPoint.fLightYield", BeamDetToFPoint_fLightYield, &b_BeamDetToFPoint_fLightYield);
   fChain->SetBranchAddress("BeamDetToFPoint.fToFNb", BeamDetToFPoint_fToFNb, &b_BeamDetToFPoint_fToFNb);
   fChain->SetBranchAddress("BeamDetMWPCPoint", &BeamDetMWPCPoint_, &b_cbmroot_BeamDet_BeamDetMWPCPoint_);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fUniqueID", BeamDetMWPCPoint_fUniqueID, &b_BeamDetMWPCPoint_fUniqueID);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fBits", BeamDetMWPCPoint_fBits, &b_BeamDetMWPCPoint_fBits);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fTrackID", BeamDetMWPCPoint_fTrackID, &b_BeamDetMWPCPoint_fTrackID);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fEventId", BeamDetMWPCPoint_fEventId, &b_BeamDetMWPCPoint_fEventId);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPx", BeamDetMWPCPoint_fPx, &b_BeamDetMWPCPoint_fPx);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPy", BeamDetMWPCPoint_fPy, &b_BeamDetMWPCPoint_fPy);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPz", BeamDetMWPCPoint_fPz, &b_BeamDetMWPCPoint_fPz);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fTime", BeamDetMWPCPoint_fTime, &b_BeamDetMWPCPoint_fTime);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fLength", BeamDetMWPCPoint_fLength, &b_BeamDetMWPCPoint_fLength);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fELoss", BeamDetMWPCPoint_fELoss, &b_BeamDetMWPCPoint_fELoss);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fDetectorID", BeamDetMWPCPoint_fDetectorID, &b_BeamDetMWPCPoint_fDetectorID);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fX", BeamDetMWPCPoint_fX, &b_BeamDetMWPCPoint_fX);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fY", BeamDetMWPCPoint_fY, &b_BeamDetMWPCPoint_fY);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fZ", BeamDetMWPCPoint_fZ, &b_BeamDetMWPCPoint_fZ);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fEventID", BeamDetMWPCPoint_fEventID, &b_BeamDetMWPCPoint_fEventID);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fMot0TrackID", BeamDetMWPCPoint_fMot0TrackID, &b_BeamDetMWPCPoint_fMot0TrackID);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPid", BeamDetMWPCPoint_fPid, &b_BeamDetMWPCPoint_fPid);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fX_out", BeamDetMWPCPoint_fX_out, &b_BeamDetMWPCPoint_fX_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fY_out", BeamDetMWPCPoint_fY_out, &b_BeamDetMWPCPoint_fY_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fZ_out", BeamDetMWPCPoint_fZ_out, &b_BeamDetMWPCPoint_fZ_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPx_out", BeamDetMWPCPoint_fPx_out, &b_BeamDetMWPCPoint_fPx_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPy_out", BeamDetMWPCPoint_fPy_out, &b_BeamDetMWPCPoint_fPy_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPz_out", BeamDetMWPCPoint_fPz_out, &b_BeamDetMWPCPoint_fPz_out);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fLightYield", BeamDetMWPCPoint_fLightYield, &b_BeamDetMWPCPoint_fLightYield);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fMWPCNb", BeamDetMWPCPoint_fMWPCNb, &b_BeamDetMWPCPoint_fMWPCNb);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fPlaneNb", BeamDetMWPCPoint_fPlaneNb, &b_BeamDetMWPCPoint_fPlaneNb);
   fChain->SetBranchAddress("BeamDetMWPCPoint.fWireNb", BeamDetMWPCPoint_fWireNb, &b_BeamDetMWPCPoint_fWireNb);
   fChain->SetBranchAddress("NDPoint", &NDPoint_, &b_cbmroot_ND_NDPoint_);
   fChain->SetBranchAddress("NDPoint.fUniqueID", NDPoint_fUniqueID, &b_NDPoint_fUniqueID);
   fChain->SetBranchAddress("NDPoint.fBits", NDPoint_fBits, &b_NDPoint_fBits);
   fChain->SetBranchAddress("NDPoint.fTrackID", NDPoint_fTrackID, &b_NDPoint_fTrackID);
   fChain->SetBranchAddress("NDPoint.fEventId", NDPoint_fEventId, &b_NDPoint_fEventId);
   fChain->SetBranchAddress("NDPoint.fPx", NDPoint_fPx, &b_NDPoint_fPx);
   fChain->SetBranchAddress("NDPoint.fPy", NDPoint_fPy, &b_NDPoint_fPy);
   fChain->SetBranchAddress("NDPoint.fPz", NDPoint_fPz, &b_NDPoint_fPz);
   fChain->SetBranchAddress("NDPoint.fTime", NDPoint_fTime, &b_NDPoint_fTime);
   fChain->SetBranchAddress("NDPoint.fLength", NDPoint_fLength, &b_NDPoint_fLength);
   fChain->SetBranchAddress("NDPoint.fELoss", NDPoint_fELoss, &b_NDPoint_fELoss);
   fChain->SetBranchAddress("NDPoint.fDetectorID", NDPoint_fDetectorID, &b_NDPoint_fDetectorID);
   fChain->SetBranchAddress("NDPoint.fX", NDPoint_fX, &b_NDPoint_fX);
   fChain->SetBranchAddress("NDPoint.fY", NDPoint_fY, &b_NDPoint_fY);
   fChain->SetBranchAddress("NDPoint.fZ", NDPoint_fZ, &b_NDPoint_fZ);
   fChain->SetBranchAddress("NDPoint.fEventID", NDPoint_fEventID, &b_NDPoint_fEventID);
   fChain->SetBranchAddress("NDPoint.fMot0TrackID", NDPoint_fMot0TrackID, &b_NDPoint_fMot0TrackID);
   fChain->SetBranchAddress("NDPoint.fMass", NDPoint_fMass, &b_NDPoint_fMass);
   fChain->SetBranchAddress("NDPoint.fX_out", NDPoint_fX_out, &b_NDPoint_fX_out);
   fChain->SetBranchAddress("NDPoint.fY_out", NDPoint_fY_out, &b_NDPoint_fY_out);
   fChain->SetBranchAddress("NDPoint.fZ_out", NDPoint_fZ_out, &b_NDPoint_fZ_out);
   fChain->SetBranchAddress("NDPoint.fPx_out", NDPoint_fPx_out, &b_NDPoint_fPx_out);
   fChain->SetBranchAddress("NDPoint.fPy_out", NDPoint_fPy_out, &b_NDPoint_fPy_out);
   fChain->SetBranchAddress("NDPoint.fPz_out", NDPoint_fPz_out, &b_NDPoint_fPz_out);
   fChain->SetBranchAddress("NDPoint.fStilbenNr", NDPoint_fStilbenNr, &b_NDPoint_fStilbenNr);
   fChain->SetBranchAddress("NDPoint.fLightYield", NDPoint_fLightYield, &b_NDPoint_fLightYield);
   fChain->SetBranchAddress("NDPoint.fPdg", NDPoint_fPdg, &b_NDPoint_fPdg);
   fChain->SetBranchAddress("NDPoint.fParentTrackId", NDPoint_fParentTrackId, &b_NDPoint_fParentTrackId);
   fChain->SetBranchAddress("NDPoint.fParentPdgId", NDPoint_fParentPdgId, &b_NDPoint_fParentPdgId);
   fChain->SetBranchAddress("BeamDetToFDigi1", &BeamDetToFDigi1_, &b_cbmroot_BeamDetToF Digi_BeamDetToFDigi1_);
   fChain->SetBranchAddress("BeamDetToFDigi1.fUniqueID", BeamDetToFDigi1_fUniqueID, &b_BeamDetToFDigi1_fUniqueID);
   fChain->SetBranchAddress("BeamDetToFDigi1.fBits", BeamDetToFDigi1_fBits, &b_BeamDetToFDigi1_fBits);
   fChain->SetBranchAddress("BeamDetToFDigi1.fChannel", BeamDetToFDigi1_fChannel, &b_BeamDetToFDigi1_fChannel);
   fChain->SetBranchAddress("BeamDetToFDigi1.fTime", BeamDetToFDigi1_fTime, &b_BeamDetToFDigi1_fTime);
   fChain->SetBranchAddress("BeamDetToFDigi1.fEdep", BeamDetToFDigi1_fEdep, &b_BeamDetToFDigi1_fEdep);
   fChain->SetBranchAddress("BeamDetToFDigi2", &BeamDetToFDigi2_, &b_cbmroot_BeamDetToF Digi_BeamDetToFDigi2_);
   fChain->SetBranchAddress("BeamDetToFDigi2.fUniqueID", BeamDetToFDigi2_fUniqueID, &b_BeamDetToFDigi2_fUniqueID);
   fChain->SetBranchAddress("BeamDetToFDigi2.fBits", BeamDetToFDigi2_fBits, &b_BeamDetToFDigi2_fBits);
   fChain->SetBranchAddress("BeamDetToFDigi2.fChannel", BeamDetToFDigi2_fChannel, &b_BeamDetToFDigi2_fChannel);
   fChain->SetBranchAddress("BeamDetToFDigi2.fTime", BeamDetToFDigi2_fTime, &b_BeamDetToFDigi2_fTime);
   fChain->SetBranchAddress("BeamDetToFDigi2.fEdep", BeamDetToFDigi2_fEdep, &b_BeamDetToFDigi2_fEdep);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1", &BeamDetMWPCDigiX1_, &b_cbmroot_BeamDetMWPC x1 Digi_BeamDetMWPCDigiX1_);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1.fUniqueID", BeamDetMWPCDigiX1_fUniqueID, &b_BeamDetMWPCDigiX1_fUniqueID);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1.fBits", BeamDetMWPCDigiX1_fBits, &b_BeamDetMWPCDigiX1_fBits);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1.fChannel", BeamDetMWPCDigiX1_fChannel, &b_BeamDetMWPCDigiX1_fChannel);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1.fTime", BeamDetMWPCDigiX1_fTime, &b_BeamDetMWPCDigiX1_fTime);
   fChain->SetBranchAddress("BeamDetMWPCDigiX1.fEdep", BeamDetMWPCDigiX1_fEdep, &b_BeamDetMWPCDigiX1_fEdep);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2", &BeamDetMWPCDigiX2_, &b_cbmroot_BeamDetMWPC x2 Digi_BeamDetMWPCDigiX2_);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2.fUniqueID", BeamDetMWPCDigiX2_fUniqueID, &b_BeamDetMWPCDigiX2_fUniqueID);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2.fBits", BeamDetMWPCDigiX2_fBits, &b_BeamDetMWPCDigiX2_fBits);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2.fChannel", BeamDetMWPCDigiX2_fChannel, &b_BeamDetMWPCDigiX2_fChannel);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2.fTime", BeamDetMWPCDigiX2_fTime, &b_BeamDetMWPCDigiX2_fTime);
   fChain->SetBranchAddress("BeamDetMWPCDigiX2.fEdep", BeamDetMWPCDigiX2_fEdep, &b_BeamDetMWPCDigiX2_fEdep);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1", &BeamDetMWPCDigiY1_, &b_cbmroot_BeamDetMWPC y1 Digi_BeamDetMWPCDigiY1_);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1.fUniqueID", BeamDetMWPCDigiY1_fUniqueID, &b_BeamDetMWPCDigiY1_fUniqueID);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1.fBits", BeamDetMWPCDigiY1_fBits, &b_BeamDetMWPCDigiY1_fBits);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1.fChannel", BeamDetMWPCDigiY1_fChannel, &b_BeamDetMWPCDigiY1_fChannel);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1.fTime", BeamDetMWPCDigiY1_fTime, &b_BeamDetMWPCDigiY1_fTime);
   fChain->SetBranchAddress("BeamDetMWPCDigiY1.fEdep", BeamDetMWPCDigiY1_fEdep, &b_BeamDetMWPCDigiY1_fEdep);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2", &BeamDetMWPCDigiY2_, &b_cbmroot_BeamDetMWPC y2 Digi_BeamDetMWPCDigiY2_);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2.fUniqueID", BeamDetMWPCDigiY2_fUniqueID, &b_BeamDetMWPCDigiY2_fUniqueID);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2.fBits", BeamDetMWPCDigiY2_fBits, &b_BeamDetMWPCDigiY2_fBits);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2.fChannel", BeamDetMWPCDigiY2_fChannel, &b_BeamDetMWPCDigiY2_fChannel);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2.fTime", BeamDetMWPCDigiY2_fTime, &b_BeamDetMWPCDigiY2_fTime);
   fChain->SetBranchAddress("BeamDetMWPCDigiY2.fEdep", BeamDetMWPCDigiY2_fEdep, &b_BeamDetMWPCDigiY2_fEdep);
   fChain->SetBranchAddress("NDDigi", &NDDigi_, &b_cbmroot_ND digi_NDDigi_);
   fChain->SetBranchAddress("NDDigi.fUniqueID", NDDigi_fUniqueID, &b_NDDigi_fUniqueID);
   fChain->SetBranchAddress("NDDigi.fBits", NDDigi_fBits, &b_NDDigi_fBits);
   fChain->SetBranchAddress("NDDigi.fChannel", NDDigi_fChannel, &b_NDDigi_fChannel);
   fChain->SetBranchAddress("NDDigi.fTime", NDDigi_fTime, &b_NDDigi_fTime);
   fChain->SetBranchAddress("NDDigi.fEdep", NDDigi_fEdep, &b_NDDigi_fEdep);
   fChain->SetBranchAddress("NDDigi.fLightYield", NDDigi_fLightYield, &b_NDDigi_fLightYield);
   fChain->SetBranchAddress("NDDigi.fNeutronProb", NDDigi_fNeutronProb, &b_NDDigi_fNeutronProb);
   fChain->SetBranchAddress("NDDigi.fTAC", NDDigi_fTAC, &b_NDDigi_fTAC);
   fChain->SetBranchAddress("NDDigi.fX_in", NDDigi_fX_in, &b_NDDigi_fX_in);
   fChain->SetBranchAddress("NDDigi.fY_in", NDDigi_fY_in, &b_NDDigi_fY_in);
   fChain->SetBranchAddress("NDDigi.fZ_in", NDDigi_fZ_in, &b_NDDigi_fZ_in);
   fChain->SetBranchAddress("NDDigi.fEdep_n1", NDDigi_fEdep_n1, &b_NDDigi_fEdep_n1);
   fChain->SetBranchAddress("NDDigi.fEdep_n2", NDDigi_fEdep_n2, &b_NDDigi_fEdep_n2);
   fChain->SetBranchAddress("NDDigi.fEdep_mis", NDDigi_fEdep_mis, &b_NDDigi_fEdep_mis);
   fChain->SetBranchAddress("NDDigi.fParentTrackID", NDDigi_fParentTrackID, &b_NDDigi_fParentTrackID);
   fChain->SetBranchAddress("MCEventHeader.", &MCEventHeader_, &b_cbmroot_Event_MCEventHeader_);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fUniqueID", &MCEventHeader_ERDecayMCEventHeader_fUniqueID, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fUniqueID);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fBits", &MCEventHeader_ERDecayMCEventHeader_fBits, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fBits);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fName", &MCEventHeader_ERDecayMCEventHeader_fName, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fName);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fTitle", &MCEventHeader_ERDecayMCEventHeader_fTitle, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTitle);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fRunId", &MCEventHeader_ERDecayMCEventHeader_fRunId, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRunId);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fEventId", &MCEventHeader_ERDecayMCEventHeader_fEventId, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fEventId);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fX", &MCEventHeader_ERDecayMCEventHeader_fX, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fX);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fY", &MCEventHeader_ERDecayMCEventHeader_fY, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fY);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fZ", &MCEventHeader_ERDecayMCEventHeader_fZ, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fZ);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fT", &MCEventHeader_ERDecayMCEventHeader_fT, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fT);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fB", &MCEventHeader_ERDecayMCEventHeader_fB, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fB);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fNPrim", &MCEventHeader_ERDecayMCEventHeader_fNPrim, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fNPrim);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fIsSet", &MCEventHeader_ERDecayMCEventHeader_fIsSet, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fIsSet);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fRotX", &MCEventHeader_ERDecayMCEventHeader_fRotX, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotX);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fRotY", &MCEventHeader_ERDecayMCEventHeader_fRotY, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotY);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fRotZ", &MCEventHeader_ERDecayMCEventHeader_fRotZ, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fRotZ);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fReactionPos", &MCEventHeader_ERDecayMCEventHeader_fReactionPos, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fReactionPos);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fInputTrackID", &MCEventHeader_ERDecayMCEventHeader_fInputTrackID, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fInputTrackID);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fOutputTrackID", &MCEventHeader_ERDecayMCEventHeader_fOutputTrackID, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fOutputTrackID);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fOutputsTracksNb", &MCEventHeader_ERDecayMCEventHeader_fOutputsTracksNb, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fOutputsTracksNb);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fTrigger", &MCEventHeader_ERDecayMCEventHeader_fTrigger, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTrigger);
   fChain->SetBranchAddress("MCEventHeader.ERDecayMCEventHeader.fTriggerPriority", &MCEventHeader_ERDecayMCEventHeader_fTriggerPriority, &b_MCEventHeader_cbmroot_Event_MCEventHeader_ERDecayMCEventHeader_fTriggerPriority);
   fChain->SetBranchAddress("MCEventHeader.fH3", &MCEventHeader_fH3, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fH3);
   fChain->SetBranchAddress("MCEventHeader.fH1", &MCEventHeader_fH1, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fH1);
   fChain->SetBranchAddress("MCEventHeader.fn1", &MCEventHeader_fn1, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fn1);
   fChain->SetBranchAddress("MCEventHeader.fHe3", &MCEventHeader_fHe3, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fHe3);
   fChain->SetBranchAddress("MCEventHeader.fTrigger", &MCEventHeader_fTrigger, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTrigger);
   fChain->SetBranchAddress("MCEventHeader.fTriggerPriority", &MCEventHeader_fTriggerPriority, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTriggerPriority);
   fChain->SetBranchAddress("MCEventHeader.fTime", &MCEventHeader_fTime, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTime);
   Notify();
}

Bool_t SimDigiClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SimDigiClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SimDigiClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SimDigiClass_cxx

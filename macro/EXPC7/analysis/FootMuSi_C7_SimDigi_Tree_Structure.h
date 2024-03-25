//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 11 11:17:15 2024 by ROOT version 6.10/08
// from TTree er//cbmroot
// found on file: tracks_into_single_branch_twoprotons.root
//////////////////////////////////////////////////////////

#ifndef FootMuSi_C7_SimDigi_Tree_Structure_h
#define FootMuSi_C7_SimDigi_Tree_Structure_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "FairMultiLinkedData_Interface.h"
#include "TNamed.h"
#include "TGeoAtt.h"
#include "TAttLine.h"
#include "TAttMarker.h"
#include "TVirtualGeoTrack.h"
#include "TGeoTrack.h"

class FootMuSi_C7_SimDigi_Tree_Structure {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxcbmroot_Stack_MCTrack = 219;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X = 7;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y = 5;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X = 6;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y = 11;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X = 8;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y = 4;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X = 5;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y = 5;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X = 6;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y = 5;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X = 6;
   static constexpr Int_t kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y = 4;
   static constexpr Int_t kMaxcbmroot_Event_MCEventHeader = 1;
   static constexpr Int_t kMaxcbmroot_MCGeoTrack_GeoTracks = 219;

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
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_;
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_;
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   UInt_t          FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double32_t      FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_;
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_;
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   UInt_t          FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double32_t      FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_;
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_;
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   UInt_t          FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventId[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fELoss[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fDetectorID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMot0TrackID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fVolNb[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMass[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fXlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fYlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZlocal[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double32_t      FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz_out[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeIn[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeOut[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLightYield[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPID[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fCharge[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackLength[kMaxcbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_;
   UInt_t          FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_]
   UInt_t          FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_]
   UShort_t        FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_]
   Float_t         FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_]
   Float_t         FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_]
   Int_t           FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_;
   UInt_t          FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_]
   UInt_t          FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_]
   UShort_t        FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_]
   Float_t         FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_]
   Float_t         FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_;
   UInt_t          FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_]
   UInt_t          FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_]
   UShort_t        FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_]
   Float_t         FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_]
   Float_t         FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_]
   Int_t           FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_;
   UInt_t          FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_]
   UInt_t          FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_]
   UShort_t        FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_]
   Float_t         FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_]
   Float_t         FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_;
   UInt_t          FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_]
   UInt_t          FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_]
   UShort_t        FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_]
   Float_t         FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_]
   Float_t         FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_]
   Int_t           FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_;
   UInt_t          FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_]
   UInt_t          FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fBits[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_]
   UShort_t        FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fChannel[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_]
   Float_t         FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fTime[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_]
   Float_t         FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fEdep[kMaxcbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y];   //[cbmroot.FootMuSi.FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_]
   ERDecay7CEventHeader *MCEventHeader_;
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
   TLorentzVector  MCEventHeader_fC9;
   TLorentzVector  MCEventHeader_fC7;
   TLorentzVector  MCEventHeader_fHe3;
   TLorentzVector  MCEventHeader_fp1;
   TLorentzVector  MCEventHeader_fp2;
   TLorentzVector  MCEventHeader_fp3;
   TLorentzVector  MCEventHeader_fp4;
   Int_t           MCEventHeader_fTrigger;
   Int_t           MCEventHeader_fTriggerPriority;
   Float_t         MCEventHeader_fTime;
   Int_t           GeoTracks_;
   UInt_t          GeoTracks_fUniqueID[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   UInt_t          GeoTracks_fBits[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   UInt_t          GeoTracks_fGeoAtt[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Short_t         GeoTracks_fLineColor[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Short_t         GeoTracks_fLineStyle[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Short_t         GeoTracks_fLineWidth[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Short_t         GeoTracks_fMarkerColor[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Short_t         GeoTracks_fMarkerStyle[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Float_t         GeoTracks_fMarkerSize[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Int_t           GeoTracks_fPDG[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Int_t           GeoTracks_fId[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Int_t           GeoTracks_fPointsSize[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Int_t           GeoTracks_fNpoints[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot.MCGeoTrack.GeoTracks_]
   Double_t       *GeoTracks_fPoints[kMaxcbmroot_MCGeoTrack_GeoTracks];   //[cbmroot_MCGeoTrack_GeoTracks_fNpoints]

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
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fBits;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventId;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTime;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLength;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fELoss;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fDetectorID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMot0TrackID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fVolNb;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMass;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fXlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fYlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZlocal;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz_out;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeIn;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeOut;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLightYield;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPID;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fCharge;   //!
   TBranch        *b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackLength;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fEdep;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fEdep;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fEdep;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fEdep;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fEdep;   //!
   TBranch        *b_cbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fBits;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fChannel;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fTime;   //!
   TBranch        *b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fEdep;   //!
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
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fC9;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fC7;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fHe3;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fp1;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fp2;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fp3;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fp4;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTrigger;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTriggerPriority;   //!
   TBranch        *b_MCEventHeader_cbmroot_Event_MCEventHeader_fTime;   //!
   TBranch        *b_cbmroot_MCGeoTrack_GeoTracks_;   //!
   TBranch        *b_GeoTracks_fUniqueID;   //!
   TBranch        *b_GeoTracks_fBits;   //!
   TBranch        *b_GeoTracks_fGeoAtt;   //!
   TBranch        *b_GeoTracks_fLineColor;   //!
   TBranch        *b_GeoTracks_fLineStyle;   //!
   TBranch        *b_GeoTracks_fLineWidth;   //!
   TBranch        *b_GeoTracks_fMarkerColor;   //!
   TBranch        *b_GeoTracks_fMarkerStyle;   //!
   TBranch        *b_GeoTracks_fMarkerSize;   //!
   TBranch        *b_GeoTracks_fPDG;   //!
   TBranch        *b_GeoTracks_fId;   //!
   TBranch        *b_GeoTracks_fPointsSize;   //!
   TBranch        *b_GeoTracks_fNpoints;   //!
   TBranch        *b_GeoTracks_fPoints;   //!

   FootMuSi_C7_SimDigi_Tree_Structure(TTree *tree=0);
   virtual ~FootMuSi_C7_SimDigi_Tree_Structure();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FootMuSi_C7_SimDigi_Tree_Structure_cxx
FootMuSi_C7_SimDigi_Tree_Structure::FootMuSi_C7_SimDigi_Tree_Structure(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("tracks_into_single_branch_twoprotons.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("tracks_into_single_branch_twoprotons.root");
      }
      f->GetObject("er",tree);

   }
   Init(tree);
}

FootMuSi_C7_SimDigi_Tree_Structure::~FootMuSi_C7_SimDigi_Tree_Structure()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FootMuSi_C7_SimDigi_Tree_Structure::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FootMuSi_C7_SimDigi_Tree_Structure::LoadTree(Long64_t entry)
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

void FootMuSi_C7_SimDigi_Tree_Structure::Init(TTree *tree)
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
   // Set array pointer
   for(int i=0; i<kMaxcbmroot_MCGeoTrack_GeoTracks; ++i) GeoTracks_fPoints[i] = 0;

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
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X", &FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fUniqueID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fBits", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fBits, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTrackID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fEventId", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventId, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPy", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTime", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTime, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fLength", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLength, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fELoss", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fELoss, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fDetectorID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fDetectorID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fX", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fY", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fZ", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fEventID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fMot0TrackID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMot0TrackID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fVolNb", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fVolNb, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fMass", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMass, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fXlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fXlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fYlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fYlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fZlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fX_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fY_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fZ_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPy_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTimeIn", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeIn, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTimeOut", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeOut, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fLightYield", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLightYield, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fCharge", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fCharge, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTrackLength", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackLength, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X_fTrackLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y", &FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fUniqueID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fBits", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fBits, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fTrackID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fEventId", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventId, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPy", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fTime", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTime, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fLength", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLength, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fELoss", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fELoss, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fDetectorID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fDetectorID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fX", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fY", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fZ", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fEventID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fMot0TrackID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMot0TrackID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fVolNb", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fVolNb, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fMass", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMass, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fXlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fXlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fYlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fYlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fZlocal", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZlocal, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fX_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fY_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fZ_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPy_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz_out, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fTimeIn", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeIn, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fTimeOut", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeOut, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fLightYield", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLightYield, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPID", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPID, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fCharge", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fCharge, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fTrackLength", FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackLength, &b_FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y_fTrackLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X", &FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fUniqueID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fBits", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fBits, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fTrackID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fEventId", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventId, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPx", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPy", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPz", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fTime", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTime, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fLength", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLength, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fELoss", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fELoss, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fDetectorID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fDetectorID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fX", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fY", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fZ", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fEventID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fMot0TrackID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMot0TrackID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fVolNb", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fVolNb, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fMass", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMass, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fXlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fXlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fYlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fYlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fZlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fX_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fY_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fZ_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPx_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPy_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPz_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fTimeIn", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeIn, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fTimeOut", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeOut, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fLightYield", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLightYield, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fPID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fCharge", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fCharge, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X.fTrackLength", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackLength, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_3_X_fTrackLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y", &FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fUniqueID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fBits", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fBits, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fTrackID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fEventId", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventId, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPx", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPy", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPz", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fTime", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTime, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fLength", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLength, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fELoss", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fELoss, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fDetectorID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fDetectorID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fX", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fY", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fZ", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fEventID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fMot0TrackID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMot0TrackID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fVolNb", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fVolNb, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fMass", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMass, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fXlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fXlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fYlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fYlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fZlocal", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZlocal, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fX_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fY_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fZ_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPx_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPy_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPz_out", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz_out, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fTimeIn", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeIn, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fTimeOut", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeOut, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fLightYield", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLightYield, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fPID", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPID, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fCharge", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fCharge, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y.fTrackLength", FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackLength, &b_FootMuSiPoint_C7_second_pair_SingleSi_SSD150_4_Y_fTrackLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X", &FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fUniqueID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fBits", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fBits, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fTrackID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fEventId", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventId, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPx", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPy", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPz", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fTime", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTime, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fLength", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLength, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fELoss", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fELoss, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fDetectorID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fDetectorID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fX", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fY", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fZ", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fEventID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fMot0TrackID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMot0TrackID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fVolNb", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fVolNb, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fMass", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMass, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fXlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fXlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fYlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fYlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fZlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fX_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fY_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fZ_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPx_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPy_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPz_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fTimeIn", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeIn, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fTimeOut", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeOut, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fLightYield", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLightYield, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fPID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fCharge", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fCharge, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X.fTrackLength", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackLength, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_5_X_fTrackLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y", &FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_, &b_cbmroot_FootMuSi_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fUniqueID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fBits", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fBits, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fBits);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fTrackID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fEventId", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventId, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventId);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPx", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPy", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPz", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fTime", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTime, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTime);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fLength", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLength, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLength);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fELoss", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fELoss, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fELoss);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fDetectorID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fDetectorID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fDetectorID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fX", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fY", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fZ", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fEventID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fEventID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fMot0TrackID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMot0TrackID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMot0TrackID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fVolNb", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fVolNb, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fVolNb);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fMass", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMass, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fMass);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fXlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fXlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fXlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fYlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fYlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fYlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fZlocal", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZlocal, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZlocal);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fX_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fX_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fY_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fY_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fZ_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fZ_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPx_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPx_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPy_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPy_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPz_out", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz_out, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPz_out);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fTimeIn", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeIn, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeIn);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fTimeOut", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeOut, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTimeOut);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fLightYield", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLightYield, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fLightYield);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fPID", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPID, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fPID);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fCharge", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fCharge, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fCharge);
   fChain->SetBranchAddress("FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y.fTrackLength", FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackLength, &b_FootMuSiPoint_C7_third_pair_SingleSi_SSD150_6_Y_fTrackLength);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X", &FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fUniqueID", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fBits", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fBits, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fChannel", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fChannel, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fTime", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fTime, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fEdep", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fEdep, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X_fEdep);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y", &FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y.fUniqueID", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y.fBits", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fBits, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y.fChannel", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fChannel, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y.fTime", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fTime, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y.fEdep", FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fEdep, &b_FootMuSiDigi_C7_first_pair_SingleSi_SSD150_2_Y_fEdep);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X", &FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X.fUniqueID", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X.fBits", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fBits, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X.fChannel", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fChannel, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X.fTime", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fTime, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X.fEdep", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fEdep, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_3_X_fEdep);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y", &FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y.fUniqueID", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y.fBits", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fBits, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y.fChannel", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fChannel, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y.fTime", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fTime, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y.fEdep", FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fEdep, &b_FootMuSiDigi_C7_second_pair_SingleSi_SSD150_4_Y_fEdep);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X", &FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X.fUniqueID", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X.fBits", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fBits, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X.fChannel", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fChannel, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X.fTime", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fTime, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X.fEdep", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fEdep, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_5_X_fEdep);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y", &FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_, &b_cbmroot_FootMuSi_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y.fUniqueID", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y.fBits", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fBits, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fBits);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y.fChannel", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fChannel, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fChannel);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y.fTime", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fTime, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fTime);
   fChain->SetBranchAddress("FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y.fEdep", FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fEdep, &b_FootMuSiDigi_C7_third_pair_SingleSi_SSD150_6_Y_fEdep);
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
   fChain->SetBranchAddress("MCEventHeader.fC9", &MCEventHeader_fC9, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fC9);
   fChain->SetBranchAddress("MCEventHeader.fC7", &MCEventHeader_fC7, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fC7);
   fChain->SetBranchAddress("MCEventHeader.fHe3", &MCEventHeader_fHe3, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fHe3);
   fChain->SetBranchAddress("MCEventHeader.fp1", &MCEventHeader_fp1, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fp1);
   fChain->SetBranchAddress("MCEventHeader.fp2", &MCEventHeader_fp2, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fp2);
   fChain->SetBranchAddress("MCEventHeader.fp3", &MCEventHeader_fp3, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fp3);
   fChain->SetBranchAddress("MCEventHeader.fp4", &MCEventHeader_fp4, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fp4);
   fChain->SetBranchAddress("MCEventHeader.fTrigger", &MCEventHeader_fTrigger, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTrigger);
   fChain->SetBranchAddress("MCEventHeader.fTriggerPriority", &MCEventHeader_fTriggerPriority, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTriggerPriority);
   fChain->SetBranchAddress("MCEventHeader.fTime", &MCEventHeader_fTime, &b_MCEventHeader_cbmroot_Event_MCEventHeader_fTime);
   fChain->SetBranchAddress("GeoTracks", &GeoTracks_, &b_cbmroot_MCGeoTrack_GeoTracks_);
   fChain->SetBranchAddress("GeoTracks.fUniqueID", GeoTracks_fUniqueID, &b_GeoTracks_fUniqueID);
   fChain->SetBranchAddress("GeoTracks.fBits", GeoTracks_fBits, &b_GeoTracks_fBits);
   fChain->SetBranchAddress("GeoTracks.fGeoAtt", GeoTracks_fGeoAtt, &b_GeoTracks_fGeoAtt);
   fChain->SetBranchAddress("GeoTracks.fLineColor", GeoTracks_fLineColor, &b_GeoTracks_fLineColor);
   fChain->SetBranchAddress("GeoTracks.fLineStyle", GeoTracks_fLineStyle, &b_GeoTracks_fLineStyle);
   fChain->SetBranchAddress("GeoTracks.fLineWidth", GeoTracks_fLineWidth, &b_GeoTracks_fLineWidth);
   fChain->SetBranchAddress("GeoTracks.fMarkerColor", GeoTracks_fMarkerColor, &b_GeoTracks_fMarkerColor);
   fChain->SetBranchAddress("GeoTracks.fMarkerStyle", GeoTracks_fMarkerStyle, &b_GeoTracks_fMarkerStyle);
   fChain->SetBranchAddress("GeoTracks.fMarkerSize", GeoTracks_fMarkerSize, &b_GeoTracks_fMarkerSize);
   fChain->SetBranchAddress("GeoTracks.fPDG", GeoTracks_fPDG, &b_GeoTracks_fPDG);
   fChain->SetBranchAddress("GeoTracks.fId", GeoTracks_fId, &b_GeoTracks_fId);
   fChain->SetBranchAddress("GeoTracks.fPointsSize", GeoTracks_fPointsSize, &b_GeoTracks_fPointsSize);
   fChain->SetBranchAddress("GeoTracks.fNpoints", GeoTracks_fNpoints, &b_GeoTracks_fNpoints);
   fChain->SetBranchAddress("GeoTracks.fPoints", GeoTracks_fPoints, &b_GeoTracks_fPoints);
   Notify();
}

Bool_t FootMuSi_C7_SimDigi_Tree_Structure::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FootMuSi_C7_SimDigi_Tree_Structure::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FootMuSi_C7_SimDigi_Tree_Structure::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FootMuSi_C7_SimDigi_Tree_Structure_cxx

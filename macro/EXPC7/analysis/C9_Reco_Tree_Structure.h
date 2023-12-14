//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov 27 20:51:48 2023 by ROOT version 6.10/08
// from TTree er//cbmout
// found on file: reco_twoprotons_decay_helium_1mm_10000events_mult_assembly.root
//////////////////////////////////////////////////////////

#ifndef C9_Reco_Tree_Structure_h
#define C9_Reco_Tree_Structure_h

#if !defined(__CLING__)
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "FairMultiLinkedData.h"
#include "FairLink.h"
#include "ERTelescopeTrack.h"
#include "TNamed.h"
#include "ERTelescopeParticle.h"
#endif

class C9_Reco_Tree_Structure {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxcbmout_EvtHeader_EventHeader = 1;
   static constexpr Int_t kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y = 121;
   static constexpr Int_t kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y = 121;
   static constexpr Int_t kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y = 112;
   static constexpr Int_t kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010 = 121;
   static constexpr Int_t kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030 = 121;

   // Declaration of leaf types
   FairEventHeader *EventHeader_;
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_;
   UInt_t          TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   UInt_t          TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   set<FairLink>   TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   UChar_t         TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   UShort_t        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Float_t         TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   TVector3        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fTargetVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.Telescope.TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_;
   UInt_t          TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   UInt_t          TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   set<FairLink>   TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   UChar_t         TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   UShort_t        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Float_t         TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   TVector3        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fTargetVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.Telescope.TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_;
   UInt_t          TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   UInt_t          TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   set<FairLink>   TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   UChar_t         TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   UShort_t        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Float_t         TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   TVector3        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fTargetVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalVertex[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep[kMaxcbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.Telescope.TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_;
   UInt_t          TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fUniqueID[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   UInt_t          TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fBits[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   TString         TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fName[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];
   TString         TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fTitle[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];
   TLorentzVector  TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fLVInteraction[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fKineticEnergy[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fDeadEloss[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   UShort_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   UShort_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_]
   Int_t           TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_;
   UInt_t          TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fUniqueID[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   UInt_t          TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fBits[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   TString         TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fName[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];
   TString         TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fTitle[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];
   TLorentzVector  TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fLVInteraction[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fKineticEnergy[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fDeadEloss[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   UShort_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   UShort_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThickStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]
   Double_t        TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThinStation[kMaxcbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030];   //[cbmout.Telescope.TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_]

   // List of branches
   TBranch        *b_cbmout_EvtHeader_EventHeader_;   //!
   TBranch        *b_cbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fTargetVertex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep;   //!
   TBranch        *b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep;   //!
   TBranch        *b_cbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fTargetVertex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep;   //!
   TBranch        *b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep;   //!
   TBranch        *b_cbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fTargetVertex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationVertex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalVertex;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep;   //!
   TBranch        *b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep;   //!
   TBranch        *b_cbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fUniqueID;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fBits;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fName;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fTitle;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fLVInteraction;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fKineticEnergy;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fDeadEloss;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThinStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThinStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThinStation;   //!
   TBranch        *b_cbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fUniqueID;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fBits;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fName;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fTitle;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fLVInteraction;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fKineticEnergy;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fDeadEloss;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThinStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThinStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThickStation;   //!
   TBranch        *b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThinStation;   //!

   C9_Reco_Tree_Structure(TTree *tree=0);
   virtual ~C9_Reco_Tree_Structure();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef C9_Reco_Tree_Structure_cxx
C9_Reco_Tree_Structure::C9_Reco_Tree_Structure(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("reco_twoprotons_decay_helium_1mm_10000events_mult_assembly.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("reco_twoprotons_decay_helium_1mm_10000events_mult_assembly.root");
      }
      f->GetObject("er",tree);

   }
   Init(tree);
}

C9_Reco_Tree_Structure::~C9_Reco_Tree_Structure()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t C9_Reco_Tree_Structure::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t C9_Reco_Tree_Structure::LoadTree(Long64_t entry)
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

void C9_Reco_Tree_Structure::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EventHeader_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventHeader.", &EventHeader_, &b_cbmout_EvtHeader_EventHeader_);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y", &TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_, &b_cbmout_Telescope_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fUniqueID", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fBits", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fLinks", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fFile", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fType", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fEntry", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fIndex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fWeight", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fDefaultType", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fTargetVertex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fTargetVertex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fTargetVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationVertex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationVertex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYStationVertex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationVertex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationLocalVertex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalVertex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYStationLocalVertex", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalVertex, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXChannel", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYChannel", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXEdep", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep);
   fChain->SetBranchAddress("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYEdep", TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep, &b_TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y", &TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_, &b_cbmout_Telescope_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fUniqueID", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fBits", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fLinks", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fFile", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fType", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fEntry", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fIndex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fWeight", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fDefaultType", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fTargetVertex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fTargetVertex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fTargetVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationVertex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationVertex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYStationVertex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationVertex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationLocalVertex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalVertex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYStationLocalVertex", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalVertex, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXChannel", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYChannel", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXEdep", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep);
   fChain->SetBranchAddress("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYEdep", TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep, &b_TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y", &TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_, &b_cbmout_Telescope_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fUniqueID", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fBits", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fLinks", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fFile", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fType", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fEntry", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fIndex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fWeight", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fDefaultType", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fTargetVertex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fTargetVertex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fTargetVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXStationVertex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationVertex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYStationVertex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationVertex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXStationLocalVertex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalVertex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYStationLocalVertex", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalVertex, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalVertex);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXChannel", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYChannel", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXEdep", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep);
   fChain->SetBranchAddress("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYEdep", TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep, &b_TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010", &TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_, &b_cbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fUniqueID", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fUniqueID, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fUniqueID);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fBits", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fBits, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fBits);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fName", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fName, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fName);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fTitle", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fTitle, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fTitle);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fLVInteraction", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fLVInteraction, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fLVInteraction);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fKineticEnergy", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fKineticEnergy, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fKineticEnergy);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fDeadEloss", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fDeadEloss, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fDeadEloss);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fEdepInThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fEdepInThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fEdepInThinStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fChannelOfThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThinStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fChannelOfThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fChannelOfThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fCorrectedEdepInThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010.fCorrectedEdepInThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000010010_fCorrectedEdepInThinStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030", &TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_, &b_cbmout_Telescope_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fUniqueID", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fUniqueID, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fUniqueID);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fBits", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fBits, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fBits);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fName", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fName, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fName);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fTitle", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fTitle, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fTitle);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fLVInteraction", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fLVInteraction, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fLVInteraction);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fKineticEnergy", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fKineticEnergy, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fKineticEnergy);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fDeadEloss", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fDeadEloss, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fDeadEloss);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fEdepInThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fEdepInThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fEdepInThinStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fChannelOfThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThinStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fChannelOfThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fChannelOfThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fCorrectedEdepInThickStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThickStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThickStation);
   fChain->SetBranchAddress("TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030.fCorrectedEdepInThinStation", TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThinStation, &b_TelescopeParticle_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_1000020030_fCorrectedEdepInThinStation);
   Notify();
}

Bool_t C9_Reco_Tree_Structure::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void C9_Reco_Tree_Structure::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t C9_Reco_Tree_Structure::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef C9_Reco_Tree_Structure_cxx

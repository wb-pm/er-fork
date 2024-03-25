//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 17 12:19:55 2024 by ROOT version 6.10/08
// from TTree er//cbmout
// found on file: reco__fit_hitstracks_into_single_branch_twoprotons.root
//////////////////////////////////////////////////////////

#ifndef FootMuSi_C7_Reco_Tree_Structure_h
#define FootMuSi_C7_Reco_Tree_Structure_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "FairMultiLinkedData.h"
#include "FairLink.h"

class FootMuSi_C7_Reco_Tree_Structure {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxcbmout_EvtHeader_EventHeader = 1;
   static constexpr Int_t kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y = 168;
   static constexpr Int_t kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y = 56;
   static constexpr Int_t kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y = 42;
   static constexpr Int_t kMaxcbmout_FootMuSi_FootMuSiTrack = 864;
   static constexpr Int_t kMaxcbmout_FootMuSi_FootMuSiVertex = 259;

   // Declaration of leaf types
   FairEventHeader *EventHeader_;
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_;
   UInt_t          FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   UInt_t          FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   set<FairLink>   FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   UChar_t         FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   UShort_t        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Float_t         FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   TVector3        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   TVector3        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Double_t        FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_]
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_;
   UInt_t          FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   UInt_t          FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   set<FairLink>   FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   UChar_t         FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   UShort_t        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Float_t         FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   TVector3        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   TVector3        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Double_t        FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_]
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_;
   UInt_t          FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   UInt_t          FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   set<FairLink>   FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   UChar_t         FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   UShort_t        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Float_t         FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   TVector3        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   TVector3        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalHit[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Double_t        FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep[kMaxcbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y];   //[cbmout.FootMuSi.FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_]
   Int_t           FootMuSiTrack_;
   UInt_t          FootMuSiTrack_fUniqueID[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   UInt_t          FootMuSiTrack_fBits[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   set<FairLink>   FootMuSiTrack_fLinks[kMaxcbmout_FootMuSi_FootMuSiTrack];
   UChar_t         FootMuSiTrack_fEntryNr_fFile[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   UShort_t        FootMuSiTrack_fEntryNr_fType[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   Int_t           FootMuSiTrack_fEntryNr_fEntry[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   Int_t           FootMuSiTrack_fEntryNr_fIndex[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   Float_t         FootMuSiTrack_fEntryNr_fWeight[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   Int_t           FootMuSiTrack_fDefaultType[kMaxcbmout_FootMuSi_FootMuSiTrack];   //[cbmout.FootMuSi.FootMuSiTrack_]
   TVector3        FootMuSiTrack_fFirstHit[kMaxcbmout_FootMuSi_FootMuSiTrack];
   TVector3        FootMuSiTrack_fSecondHit[kMaxcbmout_FootMuSi_FootMuSiTrack];
   TVector3        FootMuSiTrack_fThirdHit[kMaxcbmout_FootMuSi_FootMuSiTrack];
   Int_t           FootMuSiVertex_;
   UInt_t          FootMuSiVertex_fUniqueID[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]
   UInt_t          FootMuSiVertex_fBits[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]
   Int_t           FootMuSiVertex_fTracksID[kMaxcbmout_FootMuSi_FootMuSiVertex][3];   //[cbmout.FootMuSi.FootMuSiVertex_]
   Int_t           FootMuSiVertex_fTracksNb[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]
   Float_t         FootMuSiVertex_fX[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]
   Float_t         FootMuSiVertex_fY[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]
   Float_t         FootMuSiVertex_fZ[kMaxcbmout_FootMuSi_FootMuSiVertex];   //[cbmout.FootMuSi.FootMuSiVertex_]

   // List of branches
   TBranch        *b_cbmout_EvtHeader_EventHeader_;   //!
   TBranch        *b_cbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep;   //!
   TBranch        *b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep;   //!
   TBranch        *b_cbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep;   //!
   TBranch        *b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep;   //!
   TBranch        *b_cbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationHit;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalHit;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep;   //!
   TBranch        *b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep;   //!
   TBranch        *b_cbmout_FootMuSi_FootMuSiTrack_;   //!
   TBranch        *b_FootMuSiTrack_fUniqueID;   //!
   TBranch        *b_FootMuSiTrack_fBits;   //!
   TBranch        *b_FootMuSiTrack_fLinks;   //!
   TBranch        *b_FootMuSiTrack_fEntryNr_fFile;   //!
   TBranch        *b_FootMuSiTrack_fEntryNr_fType;   //!
   TBranch        *b_FootMuSiTrack_fEntryNr_fEntry;   //!
   TBranch        *b_FootMuSiTrack_fEntryNr_fIndex;   //!
   TBranch        *b_FootMuSiTrack_fEntryNr_fWeight;   //!
   TBranch        *b_FootMuSiTrack_fDefaultType;   //!
   TBranch        *b_FootMuSiTrack_fFirstHit;   //!
   TBranch        *b_FootMuSiTrack_fSecondHit;   //!
   TBranch        *b_FootMuSiTrack_fThirdHit;   //!
   TBranch        *b_cbmout_FootMuSi_FootMuSiVertex_;   //!
   TBranch        *b_FootMuSiVertex_fUniqueID;   //!
   TBranch        *b_FootMuSiVertex_fBits;   //!
   TBranch        *b_FootMuSiVertex_fTracksID;   //!
   TBranch        *b_FootMuSiVertex_fTracksNb;   //!
   TBranch        *b_FootMuSiVertex_fX;   //!
   TBranch        *b_FootMuSiVertex_fY;   //!
   TBranch        *b_FootMuSiVertex_fZ;   //!

   FootMuSi_C7_Reco_Tree_Structure(TTree *tree=0);
   virtual ~FootMuSi_C7_Reco_Tree_Structure();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FootMuSi_C7_Reco_Tree_Structure_cxx
FootMuSi_C7_Reco_Tree_Structure::FootMuSi_C7_Reco_Tree_Structure(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("reco__fit_hitstracks_into_single_branch_twoprotons.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("reco__fit_hitstracks_into_single_branch_twoprotons.root");
      }
      f->GetObject("er",tree);

   }
   Init(tree);
}

FootMuSi_C7_Reco_Tree_Structure::~FootMuSi_C7_Reco_Tree_Structure()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FootMuSi_C7_Reco_Tree_Structure::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FootMuSi_C7_Reco_Tree_Structure::LoadTree(Long64_t entry)
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

void FootMuSi_C7_Reco_Tree_Structure::Init(TTree *tree)
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
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y", &FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_, &b_cbmout_FootMuSi_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fUniqueID", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fBits", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fBits);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fLinks", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fLinks);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fFile", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fType", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fType);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fEntry", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fIndex", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fEntryNr.fWeight", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fDefaultType", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fDefaultType);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationHit", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationHit, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYStationHit", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationHit, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationLocalHit", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalHit, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYStationLocalHit", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalHit, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXChannel", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYChannel", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXEdep", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fXEdep);
   fChain->SetBranchAddress("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYEdep", FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep, &b_FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y_fYEdep);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y", &FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_, &b_cbmout_FootMuSi_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fUniqueID", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fBits", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fBits);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fLinks", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fLinks);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fFile", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fType", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fType);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fEntry", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fIndex", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fEntryNr.fWeight", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fDefaultType", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fDefaultType);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationHit", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationHit, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYStationHit", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationHit, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationLocalHit", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalHit, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYStationLocalHit", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalHit, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXChannel", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYChannel", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXEdep", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fXEdep);
   fChain->SetBranchAddress("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYEdep", FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep, &b_FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y_fYEdep);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y", &FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_, &b_cbmout_FootMuSi_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fUniqueID", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fUniqueID);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fBits", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fBits);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fLinks", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fLinks);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fFile", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fFile);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fType", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fType);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fEntry", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fEntry);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fIndex", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fIndex);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fEntryNr.fWeight", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fEntryNr_fWeight);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fDefaultType", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fDefaultType);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXStationHit", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationHit, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYStationHit", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationHit, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXStationLocalHit", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalHit, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYStationLocalHit", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalHit, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYStationLocalHit);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXChannel", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYChannel", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYChannel);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXEdep", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fXEdep);
   fChain->SetBranchAddress("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYEdep", FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep, &b_FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y_fYEdep);
   fChain->SetBranchAddress("FootMuSiTrack", &FootMuSiTrack_, &b_cbmout_FootMuSi_FootMuSiTrack_);
   fChain->SetBranchAddress("FootMuSiTrack.fUniqueID", FootMuSiTrack_fUniqueID, &b_FootMuSiTrack_fUniqueID);
   fChain->SetBranchAddress("FootMuSiTrack.fBits", FootMuSiTrack_fBits, &b_FootMuSiTrack_fBits);
   fChain->SetBranchAddress("FootMuSiTrack.fLinks", FootMuSiTrack_fLinks, &b_FootMuSiTrack_fLinks);
   fChain->SetBranchAddress("FootMuSiTrack.fEntryNr.fFile", FootMuSiTrack_fEntryNr_fFile, &b_FootMuSiTrack_fEntryNr_fFile);
   fChain->SetBranchAddress("FootMuSiTrack.fEntryNr.fType", FootMuSiTrack_fEntryNr_fType, &b_FootMuSiTrack_fEntryNr_fType);
   fChain->SetBranchAddress("FootMuSiTrack.fEntryNr.fEntry", FootMuSiTrack_fEntryNr_fEntry, &b_FootMuSiTrack_fEntryNr_fEntry);
   fChain->SetBranchAddress("FootMuSiTrack.fEntryNr.fIndex", FootMuSiTrack_fEntryNr_fIndex, &b_FootMuSiTrack_fEntryNr_fIndex);
   fChain->SetBranchAddress("FootMuSiTrack.fEntryNr.fWeight", FootMuSiTrack_fEntryNr_fWeight, &b_FootMuSiTrack_fEntryNr_fWeight);
   fChain->SetBranchAddress("FootMuSiTrack.fDefaultType", FootMuSiTrack_fDefaultType, &b_FootMuSiTrack_fDefaultType);
   fChain->SetBranchAddress("FootMuSiTrack.fFirstHit", FootMuSiTrack_fFirstHit, &b_FootMuSiTrack_fFirstHit);
   fChain->SetBranchAddress("FootMuSiTrack.fSecondHit", FootMuSiTrack_fSecondHit, &b_FootMuSiTrack_fSecondHit);
   fChain->SetBranchAddress("FootMuSiTrack.fThirdHit", FootMuSiTrack_fThirdHit, &b_FootMuSiTrack_fThirdHit);
   fChain->SetBranchAddress("FootMuSiVertex", &FootMuSiVertex_, &b_cbmout_FootMuSi_FootMuSiVertex_);
   fChain->SetBranchAddress("FootMuSiVertex.fUniqueID", FootMuSiVertex_fUniqueID, &b_FootMuSiVertex_fUniqueID);
   fChain->SetBranchAddress("FootMuSiVertex.fBits", FootMuSiVertex_fBits, &b_FootMuSiVertex_fBits);
   fChain->SetBranchAddress("FootMuSiVertex.fTracksID[3]", FootMuSiVertex_fTracksID, &b_FootMuSiVertex_fTracksID);
   fChain->SetBranchAddress("FootMuSiVertex.fTracksNb", FootMuSiVertex_fTracksNb, &b_FootMuSiVertex_fTracksNb);
   fChain->SetBranchAddress("FootMuSiVertex.fX", FootMuSiVertex_fX, &b_FootMuSiVertex_fX);
   fChain->SetBranchAddress("FootMuSiVertex.fY", FootMuSiVertex_fY, &b_FootMuSiVertex_fY);
   fChain->SetBranchAddress("FootMuSiVertex.fZ", FootMuSiVertex_fZ, &b_FootMuSiVertex_fZ);
   Notify();
}

Bool_t FootMuSi_C7_Reco_Tree_Structure::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FootMuSi_C7_Reco_Tree_Structure::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FootMuSi_C7_Reco_Tree_Structure::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FootMuSi_C7_Reco_Tree_Structure_cxx

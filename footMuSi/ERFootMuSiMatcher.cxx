/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiMatcher.h"

#include <iostream>
#include <map>

#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"

#include "ERDetectorList.h"

#include "ERMCTrack.h"
#include "ERPoint.h"
#include "ERFootMuSiHit.h"
#include "ERFootMuSiTrack.h"
#include "ERFootMuSiVertex.h"
// ----------------------------------------------------------------------------
ERFootMuSiMatcher::ERFootMuSiMatcher()
  : FairTask("ER FootMuSi matching scheme"),
  fTrueTracksNb(0), 
  fWrongTracksNb(0),
  fMCTracksNb(0),
  fShortMCTracksNb(0),
  fNotFoundVerteciesNb(0)
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERFootMuSiMatcher::ERFootMuSiMatcher(Int_t verbose)
  : FairTask("ER FootMuSi matching scheme ", verbose),
  fTrueTracksNb(0), 
  fWrongTracksNb(0),
  fMCTracksNb(0),
  fShortMCTracksNb(0),
  fNotFoundVerteciesNb(0)
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERFootMuSiMatcher::~ERFootMuSiMatcher()
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERFootMuSiMatcher::SetParContainers()
{
  // Get run and runtime database
  FairRunAna* run = FairRunAna::Instance();
  if ( ! run ) Fatal("SetParContainers", "No analysis run");

  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  if ( ! rtdb ) Fatal("SetParContainers", "No runtime database");
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
InitStatus ERFootMuSiMatcher::Init()
{
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");
  
  fMCTracks = (TClonesArray*) ioman->GetObject("MCTrack");
  fFootMuSiPoints = (TClonesArray*) ioman->GetObject("FootMuSiPoint");
  fFootMuSiHits = (TClonesArray*) ioman->GetObject("FootMuSiHit");
  fFootMuSiTracks = (TClonesArray*) ioman->GetObject("FootMuSiTrack");
  fFootMuSiVertecies = (TClonesArray*) ioman->GetObject("FootMuSiVertex");

  fHVertexDz = new TH1F("Vertex z quality", "Vertex z quality", 5000, 0., .5);
  fHVertexDxy = new TH1F("Vertex xy quality", "Vertex xy quality", 5000, 0., .5);
  return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
void ERFootMuSiMatcher::Exec(Option_t* opt)
{
 std::cout << std::endl;
 std::cout << "ERFootMuSiMatcher:" << std::endl;
 Int_t trueTracks = 0;
 Int_t wrongTracks = 0;
 for(Int_t iTrack = 0; iTrack < fFootMuSiTracks->GetEntriesFast(); iTrack++){
 	ERFootMuSiTrack* track = (ERFootMuSiTrack*)fFootMuSiTracks->At(iTrack);
    Int_t firstHitRefIndex = track->GetFirstHitRefIndex();
    Int_t secondHitRefIndex = track->GetSecondHitRefIndex();
    Int_t thirdHitRefIndex = track->GetThirdHitRefIndex();

    if (firstHitRefIndex == -1 || secondHitRefIndex == -1 || thirdHitRefIndex == -1){ //fakes
    	wrongTracks++;
    	continue;
    }
 	ERPoint* point0 = (ERPoint*)fFootMuSiPoints->At(firstHitRefIndex);
 	ERPoint* point1 = (ERPoint*)fFootMuSiPoints->At(secondHitRefIndex);
 	ERPoint* point2 = (ERPoint*)fFootMuSiPoints->At(thirdHitRefIndex);
 	if ((point0->GetTrackID() == point1->GetTrackID()) && (point1->GetTrackID() == point2->GetTrackID()))
 		trueTracks++;
 	else
 		wrongTracks++;  
 }
 
 std::map<Int_t,Int_t> pointsOnTracks;
 for (Int_t iPoint = 0; iPoint < fFootMuSiPoints->GetEntriesFast(); iPoint++){
    ERPoint* point = (ERPoint*)fFootMuSiPoints->At(iPoint);
    pointsOnTracks[point->GetTrackID()]++;
 }
 Int_t shortMCTracks = 0;
 for (std::map<Int_t,Int_t>::iterator it = pointsOnTracks.begin(); it != pointsOnTracks.end(); ++it){
  if(it->second < 3)
    shortMCTracks++;
 }

 std::cout << "True tracks:" << trueTracks << std::endl;
 std::cout << "Wrong tracks:" << wrongTracks << std::endl;
 fTrueTracksNb += trueTracks;
 fWrongTracksNb += wrongTracks;
 fMCTracksNb += pointsOnTracks.size();
 fShortMCTracksNb+= shortMCTracks;

 Int_t notFoundVerteciesNb = 0;
 //Выделяем mc вершины по массиву треков
 std::vector<MCVertex> MCVertecies;
 for (Int_t iTrack = 0; iTrack < fMCTracks->GetEntriesFast(); iTrack++){
    ERMCTrack* mcTrack = (ERMCTrack*)fMCTracks->At(iTrack);
    Bool_t addedToMC = kFALSE;
    if (mcTrack->GetMotherId() == -1){
      for(std::vector<MCVertex>::iterator it = MCVertecies.begin(); it!=MCVertecies.end(); it++){
        if ( ((*it).x - mcTrack->GetStartX() < 0.01) &&
             ((*it).y - mcTrack->GetStartY() < 0.01) &&
             ((*it).y - mcTrack->GetStartY() < 0.01))
            addedToMC = kTRUE;
      }
      if (!addedToMC)
        MCVertecies.push_back(MCVertex(mcTrack->GetStartX(), mcTrack->GetStartY(), mcTrack->GetStartZ()));
    }
  }
  //Смотрим какие вершины нашли
  for(std::vector<MCVertex>::iterator it = MCVertecies.begin(); it!=MCVertecies.end(); it++){
      MCVertex mcVertex = (*it);
      Bool_t found = kFALSE;
      Float_t distFound = 99999999.;
      ERFootMuSiVertex* vertFound;
      for(Int_t iVert =0; iVert < fFootMuSiVertecies->GetEntriesFast(); iVert++ ){
        ERFootMuSiVertex* vert = (ERFootMuSiVertex*)fFootMuSiVertecies->At(iVert);
        Float_t dist = TMath::Sqrt((vert->X()-mcVertex.x)*(vert->X()-mcVertex.x) +
                                   (vert->Y()-mcVertex.y)*(vert->Y()-mcVertex.y) +
                                   (vert->Z()-mcVertex.z)*(vert->Z()-mcVertex.z));
        if (dist < 1.){
          found = kTRUE;
          if (dist < distFound){ //выделяем наилучшую найденную вершину
            distFound = dist;
            vertFound = vert;
          }
        }
      }
      if (!found){
        notFoundVerteciesNb++;
      }else{
        fHVertexDz->Fill(TMath::Abs(vertFound->Z() - mcVertex.z));
        fHVertexDxy->Fill(TMath::Sqrt((vertFound->Y() - mcVertex.y)*(vertFound->Y() - mcVertex.y)
                                      +(vertFound->X() - mcVertex.x)*(vertFound->Z() - mcVertex.z)));
      }
   }

   std::cout << "Not found primary vertecies:" << notFoundVerteciesNb << std::endl;
   fNotFoundVerteciesNb += notFoundVerteciesNb;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void ERFootMuSiMatcher::Reset()
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERFootMuSiMatcher::Finish()
{  
  std::cout << std::endl;
  std::cout << "========= ERFootMuSiMatcher : ================" << std::endl;

  std::cout << "MC tracks: " << fMCTracksNb << std::endl;
  std::cout << "Short MC tracks: " << fShortMCTracksNb << std::endl;
  std::cout << "True tracks: " << fTrueTracksNb << std::endl;
  std::cout << "Wrong tracks: " << fWrongTracksNb << std::endl;
  std::cout << "Eff. all: " << (Float_t)fTrueTracksNb/(Float_t)fMCTracksNb << std::endl;
  std::cout << "Eff. long: " << (Float_t)fTrueTracksNb/(Float_t)(fMCTracksNb-fShortMCTracksNb)<< std::endl;
  std::cout << "Not found primary vertecies: " << fNotFoundVerteciesNb << std::endl;

  fHVertexDz->Write();
  fHVertexDxy->Write();

}
// ----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ClassImp(ERFootMuSiMatcher)

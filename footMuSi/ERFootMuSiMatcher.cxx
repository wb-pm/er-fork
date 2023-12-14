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
#include "ERFootMuSiPoint.h"
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
  fNotFoundedVerteciesNb(0)
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
  fNotFoundedVerteciesNb(0)
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
    ERFootMuSiHit* hit0 = track->Hit(0);
    ERFootMuSiHit* hit1 = track->Hit(1);
    ERFootMuSiHit* hit2 = track->Hit(2);

    if (hit0->GetRefIndex() == -1 || hit1->GetRefIndex() == -1 || hit2->GetRefIndex() == -1){ //fakes
    	wrongTracks++;
    	continue;
    }
 	ERFootMuSiPoint* point0 = (ERFootMuSiPoint*)fFootMuSiPoints->At(hit0->GetRefIndex());
 	ERFootMuSiPoint* point1 = (ERFootMuSiPoint*)fFootMuSiPoints->At(hit1->GetRefIndex());
 	ERFootMuSiPoint* point2 = (ERFootMuSiPoint*)fFootMuSiPoints->At(hit2->GetRefIndex());
 	if ((point0->GetTrackID() == point1->GetTrackID()) && (point1->GetTrackID() == point2->GetTrackID()))
 		trueTracks++;
 	else
 		wrongTracks++;  
 }
 
 map<Int_t,Int_t> pointsOnTracks;
 for (Int_t iPoint = 0; iPoint < fFootMuSiPoints->GetEntriesFast(); iPoint++){
    ERFootMuSiPoint* point = (ERFootMuSiPoint*)fFootMuSiPoints->At(iPoint);
    pointsOnTracks[point->GetTrackID()]++;
 }
 Int_t shortMCTracks = 0;
 for (map<Int_t,Int_t>::iterator it = pointsOnTracks.begin(); it != pointsOnTracks.end(); ++it){
  if(it->second < 3)
    shortMCTracks++;
 }

 std::cout << "True tracks:" << trueTracks << std::endl;
 std::cout << "Wrong tracks:" << wrongTracks << std::endl;
 fTrueTracksNb += trueTracks;
 fWrongTracksNb += wrongTracks;
 fMCTracksNb += pointsOnTracks.size();
 fShortMCTracksNb+= shortMCTracks;

 Int_t notFoundedVerteciesNb = 0;
 //Выделяем mc вершины по массиву треков
 vector<MCVertex> MCVertecies;
 for (Int_t iTrack = 0; iTrack < fMCTracks->GetEntriesFast(); iTrack++){
    ERMCTrack* mcTrack = (ERMCTrack*)fMCTracks->At(iTrack);
    Bool_t addedToMC = kFALSE;
    if (mcTrack->GetMotherId() == -1){
      for(vector<MCVertex>::iterator it = MCVertecies.begin(); it!=MCVertecies.end(); it++){
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
  for(vector<MCVertex>::iterator it = MCVertecies.begin(); it!=MCVertecies.end(); it++){
      MCVertex mcVertex = (*it);
      Bool_t founded = kFALSE;
      Float_t distFounded = 99999999.;
      ERFootMuSiVertex* vertFounded;
      for(Int_t iVert =0; iVert < fFootMuSiVertecies->GetEntriesFast(); iVert++ ){
        ERFootMuSiVertex* vert = (ERFootMuSiVertex*)fFootMuSiVertecies->At(iVert);
        Float_t dist = TMath::Sqrt((vert->X()-mcVertex.x)*(vert->X()-mcVertex.x) +
                                   (vert->Y()-mcVertex.y)*(vert->Y()-mcVertex.y) +
                                   (vert->Z()-mcVertex.z)*(vert->Z()-mcVertex.z));
        if (dist < 1.){
          founded = kTRUE;
          if (dist < distFounded){ //выделяем наилучшую найденную вершину
            distFounded = dist;
            vertFounded = vert;
          }
        }
      }
      if (!founded){
        notFoundedVerteciesNb++;
      }else{
        fHVertexDz->Fill(TMath::Abs(vertFounded->Z() - mcVertex.z));
        fHVertexDxy->Fill(TMath::Sqrt((vertFounded->Y() - mcVertex.y)*(vertFounded->Y() - mcVertex.y)
                                      +(vertFounded->X() - mcVertex.x)*(vertFounded->Z() - mcVertex.z)));
      }
   }

   std::cout << "Not founded primary vertecies:" << notFoundedVerteciesNb << std::endl;
   fNotFoundedVerteciesNb += notFoundedVerteciesNb;
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
  std::cout << "Not founded primary vertecies: " << fNotFoundedVerteciesNb << std::endl;

  fHVertexDz->Write();
  fHVertexDxy->Write();

}
// ----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ClassImp(ERFootMuSiMatcher)

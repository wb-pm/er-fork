    /********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiVertexFinder.h"

#include <vector>
#include <iostream>

#include "TVector3.h"
#include "TMath.h"
#include "TMatrix.h"
#include "TF3.h"
#include "TError.h"
#include "Fit/BinData.h"
#include "Fit/Fitter.h"
#include "Math/WrappedMultiTF1.h"

#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include "ERDetectorList.h"
#include "ERFootMuSiTrack.h"
#include "ERFootMuSiPoint.h"

// ----------------------------------------------------------------------------
ERFootMuSiVertexFinder::ERFootMuSiVertexFinder()
  : FairTask("ER FootMuSi vertex finding scheme")
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERFootMuSiVertexFinder::ERFootMuSiVertexFinder(Int_t verbose)
  : FairTask("ER FootMuSi vertex finding scheme ", verbose)
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERFootMuSiVertexFinder::~ERFootMuSiVertexFinder()
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERFootMuSiVertexFinder::SetParContainers()
{
  // Get run and runtime database
  FairRunAna* run = FairRunAna::Instance();
  if ( ! run ) Fatal("SetParContainers", "No analysis run");

  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  if ( ! rtdb ) Fatal("SetParContainers", "No runtime database");
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
InitStatus ERFootMuSiVertexFinder::Init()
{
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");
  
  fFootMuSiTracks = (TClonesArray*) ioman->GetObject("FootMuSiTrack");
  //todo check

  // Register output array fFootMuSiHits
  fFootMuSiVertices = new TClonesArray("ERFootMuSiVertex",1000);

  ioman->Register("FootMuSiVertex", "FootMuSi", fFootMuSiVertices, kTRUE);
   
  return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
void ERFootMuSiVertexFinder::Exec(Option_t* opt)
{ 
  LOG(DEBUG) << "[ERFootMuSiVertexFinder]------------Started--------------------------------------"
    << FairLogger::endl;
  Reset();
      //temporary for storing the previously found vertex
      ERFootMuSiVertex* tempVertex = new ERFootMuSiVertex(-10000.,-10000.,-10000.);
  //Searching for a common perpendicular for a pair of tracks
  for(Int_t iTrack = 0; iTrack < fFootMuSiTracks->GetEntriesFast(); iTrack++){
    ERFootMuSiTrack* track1 = (ERFootMuSiTrack*)fFootMuSiTracks->At(iTrack);
    
    //Fitting the first track with a straight line
    ROOT::Fit::BinData track1Data(3,2);
    double track1XY[2];
    track1XY[0] = track1->GetFirstHit().X();
    track1XY[1] = track1->GetFirstHit().Y();
    track1Data.Add(track1XY,track1->GetFirstHit().Z(), 0.001);
    track1XY[0] = track1->GetSecondHit().X();
    track1XY[1] = track1->GetSecondHit().Y();
    track1Data.Add(track1XY,track1->GetSecondHit().Z(), 0.001);
    track1XY[0] = track1->GetThirdHit().X();
    track1XY[1] = track1->GetThirdHit().Y();
    track1Data.Add(track1XY,track1->GetThirdHit().Z(), 0.001);

    TF2 * f = new TF2("f2","[0]*x + [1]*y + [2]*1");
    ROOT::Fit::Fitter fitter;
    ROOT::Math::WrappedMultiTF1 wf(*f,f->GetNdim());
    fitter.SetFunction(wf);
    bool ret = fitter.Fit(track1Data);
    const ROOT::Fit::FitResult & res = fitter.Result();
    //res.Print(LOG(DEBUG));
    f->SetFitResult(res);
    //The fit results are used for the direction of the first track
    TVector3 directTrack1(track1->GetFirstHit().X()-track1->GetSecondHit().X(),
                          track1->GetFirstHit().Y()-track1->GetSecondHit().Y(),
                          f->Eval(track1->GetFirstHit().X(),track1->GetFirstHit().Y()) 
                          - f->Eval(track1->GetSecondHit().X(),track1->GetSecondHit().Y()));
    for(Int_t jTrack = iTrack+1; jTrack < fFootMuSiTracks->GetEntriesFast(); jTrack++){
      if (iTrack == jTrack)
        continue;
      ERFootMuSiTrack* track2 = (ERFootMuSiTrack*)fFootMuSiTracks->At(jTrack);
       //Fitting the second track with a straight line
      ROOT::Fit::BinData track2Data(3,2);
      double track2XY[2];
      track2XY[0] = track2->GetFirstHit().X();
      track2XY[1] = track2->GetFirstHit().Y();
      track2Data.Add(track2XY,track2->GetFirstHit().Z(), 0.001);
      track2XY[0] = track2->GetSecondHit().X();
      track2XY[1] = track2->GetSecondHit().Y();
      track2Data.Add(track2XY,track2->GetSecondHit().Z(), 0.001);
      track2XY[0] = track2->GetThirdHit().X();
      track2XY[1] = track2->GetThirdHit().Y();
      track2Data.Add(track2XY,track2->GetThirdHit().Z(), 0.001);

      ROOT::Fit::Fitter fitter2;
      ROOT::Math::WrappedMultiTF1 wf2(*f,f->GetNdim());
      fitter2.SetFunction(wf2);
      bool ret2 = fitter2.Fit(track2Data);
      const ROOT::Fit::FitResult & res2 = fitter2.Result();
      //res2.Print(LOG(DEBUG));
      f->SetFitResult(res2);
    //The fit results are used for the direction of the second track
      TVector3 directTrack2(track2->GetFirstHit().X()-track2->GetSecondHit().X(),
                          track2->GetFirstHit().Y()-track2->GetSecondHit().Y(),
                          f->Eval(track2->GetFirstHit().X(),track2->GetFirstHit().Y()) 
                          - f->Eval(track2->GetSecondHit().X(),track2->GetSecondHit().Y()));

      //Making a vector that is perpendicular to both of the tracks
      TVector3 p = directTrack1.Cross(directTrack2);

      //Writing down equations for straight lines in a parametric form, in order to find the common perpendicular
      //Difference between points on the straight lines is in a direct ratio to the perpendicular vector
      TMatrixT<double> mat(3,3);
      mat(0,0) = directTrack1.X();
      mat(0,1)  = -directTrack2.X();
      mat(0,2)  = -p.X();
      mat(1,0)  = directTrack1.Y();
      mat(1,1)  = -directTrack2.Y();
      mat(1,2)  = -p.Y();
      mat(2,0)  = directTrack1.Z();
      mat(2,1)  = -directTrack2.Z();
      mat(2,2)  = -p.Z();

      TMatrixT<double> right(3,1);

      right(0,0) = track2->GetFirstHit().X()-track1->GetFirstHit().X();
      right(1,0) = track2->GetFirstHit().Y()-track1->GetFirstHit().Y();
      right(2,0) = track2->GetFirstHit().Z()-track1->GetFirstHit().Z();

      TMatrixT<double> matInv(3,3);
      matInv = mat.Invert();
      TMatrixT<double> lambda(3,1);
      lambda = matInv*right;
      TVector3 orig(track1->GetFirstHit().X(), track1->GetFirstHit().Y(), track1->GetFirstHit().Z());
      TVector3 orig2(track2->GetFirstHit().X(), track2->GetFirstHit().Y(), track2->GetFirstHit().Z());
      TVector3 vertex = orig + lambda(0,0)*directTrack1;
      TVector3 vertex2 = orig2 + lambda(1,0)*directTrack2;
      if ((fabs(lambda(2,0)) < fTrackDistanceCut) && (fabs(vertex2.Z()) < 2.5 )){
        ERFootMuSiVertex* vert = new ERFootMuSiVertex((vertex.X() + vertex2.X())/2., (vertex.Y() + vertex2.Y())/2.,(vertex.Z() + vertex2.Z())/2.);
        //ERFootMuSiVertex* vert = AddVertex((vertex.X() + vertex2.X())/2., (vertex.Y() + vertex2.Y())/2.,(vertex.Z() + vertex2.Z())/2.);
        vert->AddTrackDistance(lambda(2,0));
        vert->AddTrack(iTrack);
        vert->AddTrack(jTrack);
          //Adding functionality to merge verticies right in the tracks loop 
        Double_t dist = TMath::Sqrt((tempVertex->X()-vert->X())*(tempVertex->X()-vert->X()) + (tempVertex->Y()-vert->Y())*(tempVertex->Y()-vert->Y()) + (tempVertex->Z()-vert->Z())*(tempVertex->Z()-vert->Z()));
        //vert->AddDistanceBetweenVertices(dist);
        if(dist < fVerticesMergeDistanceCut){
          if(jTrack%100==0){
          LOG(DEBUG) << "Vertices merging! (first iteration), merges: " << jTrack << FairLogger::endl;
          }
          vert->SetX((vert->X()+tempVertex->X())/2.);
          vert->SetY((vert->Y()+tempVertex->Y())/2.);
          vert->SetZ((vert->Z()+tempVertex->Z())/2.);
/*           for (Int_t kTrack = 0; kTrack < tempVertex->TrackNb(); kTrack++){
            vert->AddTrack(tempVertex->Track(kTrack));
          } */
          continue;
        }
        AddVertex(*vert);
        tempVertex = vert;
        }
    }
  }
  //merge vertices
  for (Int_t iVert = 0; iVert < fFootMuSiVertices->GetEntriesFast(); iVert++){
    ERFootMuSiVertex* vert1 = (ERFootMuSiVertex*)fFootMuSiVertices->At(iVert);
    for (Int_t jVert = iVert+1; jVert < fFootMuSiVertices->GetEntriesFast(); jVert++){
      if(iVert == jVert)
      {
        continue;
      }
      ERFootMuSiVertex* vert2 = (ERFootMuSiVertex*)fFootMuSiVertices->At(jVert);
      Double_t dist = TMath::Sqrt((vert2->X()-vert1->X())*(vert2->X()-vert1->X()) +  
                                  (vert2->Y()-vert1->Y())*(vert2->Y()-vert1->Y()) + 
                                  (vert2->Z()-vert1->Z())*(vert2->Z()-vert1->Z()));
        vert1->AddDistanceBetweenVertices(dist);
      if(dist < fVerticesMergeDistanceCut){
        if(jVert%100 == 0){
        LOG(DEBUG) << "Vertices merging! (second iteration), merges: " << jVert << FairLogger::endl;
        }
        vert1->SetX((vert1->X()+vert2->X())/2.);
        vert1->SetY((vert1->Y()+vert2->Y())/2.);
        vert1->SetZ((vert1->Z()+vert2->Z())/2.);
        for (Int_t iTrack = 0; iTrack < vert2->TrackNb(); iTrack++){
          vert1->AddTrack(vert2->Track(iTrack));
        }
        fFootMuSiVertices->RemoveAt(jVert);
      }
    } fFootMuSiVertices->Compress(); //Delete empty spaces after going through all of the comparisons of vertices, so that not to skip some of them 
  }
  LOG(DEBUG) << "Vertices count: " << fFootMuSiVertices->GetEntriesFast() << FairLogger::endl;
  for(Int_t iVert=0; iVert < fFootMuSiVertices->GetEntriesFast(); iVert++){
    ERFootMuSiVertex* vert = (ERFootMuSiVertex*)fFootMuSiVertices->At(iVert);
    LOG(INFO) << "Vertex "<< iVert << ": (" <<  vert->X() << "," << vert->Y() << "," << vert->Z() << ")" << FairLogger::endl;
  }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void ERFootMuSiVertexFinder::Reset()
{
  if (fFootMuSiVertices) {
    fFootMuSiVertices->Delete();
  }
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERFootMuSiVertexFinder::Finish()
{   
  
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
ERFootMuSiVertex* ERFootMuSiVertexFinder::AddVertex(Double_t x, Double_t y, Double_t z){
  ERFootMuSiVertex *vertex = new((*fFootMuSiVertices)[fFootMuSiVertices->GetEntriesFast()])
                              ERFootMuSiVertex(x,y,z);
  return vertex;
}
//----------------------------------------------------------------------------
ERFootMuSiVertex* ERFootMuSiVertexFinder::AddVertex(ERFootMuSiVertex& oldVertex){
  ERFootMuSiVertex *vertex = new((*fFootMuSiVertices)[fFootMuSiVertices->GetEntriesFast()])
                              ERFootMuSiVertex(oldVertex);
  return vertex;
}
//-----------------------------------------------------------------------------
ClassImp(ERFootMuSiVertexFinder)

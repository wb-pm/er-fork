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
  //Searching for a common perpendicular for a pair of tracks
  for(Int_t iTrack = 0; iTrack < fFootMuSiTracks->GetEntriesFast(); iTrack++){
    ERFootMuSiTrack* track1 = (ERFootMuSiTrack*)fFootMuSiTracks->At(iTrack);
    
    //Fitting the first track with a straight line
    ROOT::Fit::BinData track1Data(3,2);
    double track1XY[2];
    track1XY[0] = track1->GetFirstPairVector().X();
    track1XY[1] = track1->GetFirstPairVector().Y();
    track1Data.Add(track1XY,track1->GetFirstPairVector().Z(), 0.001);
    track1XY[0] = track1->GetSecondPairVector().X();
    track1XY[1] = track1->GetSecondPairVector().Y();
    track1Data.Add(track1XY,track1->GetSecondPairVector().Z(), 0.001);
    track1XY[0] = track1->GetThirdPairVector().X();
    track1XY[1] = track1->GetThirdPairVector().Y();
    track1Data.Add(track1XY,track1->GetThirdPairVector().Z(), 0.001);

    TF2 * f = new TF2("f2","[0]*x + [1]*y + [2]*1");
    f->SetParameters(2,2,2);
    ROOT::Fit::Fitter fitter;
    ROOT::Math::WrappedMultiTF1 wf(*f,2);
    fitter.SetFunction(wf);
    bool ret = fitter.Fit(track1Data);
    const ROOT::Fit::FitResult & res = fitter.Result();
    //res.Print(std::cout);
    f->SetFitResult(res);
    //The fit results are used for the direction of the first track
    TVector3 directTrack1(track1->GetFirstPairVector().X()-track1->GetSecondPairVector().X(),
                          track1->GetFirstPairVector().Y()-track1->GetSecondPairVector().Y(),
                          f->Eval(track1->GetFirstPairVector().X(),track1->GetFirstPairVector().Y()) 
                          - f->Eval(track1->GetSecondPairVector().X(),track1->GetSecondPairVector().Y()));
    for(Int_t jTrack = iTrack+1; jTrack < fFootMuSiTracks->GetEntriesFast(); jTrack++){
      if (iTrack == jTrack)
        continue;
      ERFootMuSiTrack* track2 = (ERFootMuSiTrack*)fFootMuSiTracks->At(jTrack);
       //Fitting the second track with a straight line
      ROOT::Fit::BinData track2Data(3,2);
      double track2XY[2];
      track2XY[0] = track2->GetFirstPairVector().X();
      track2XY[1] = track2->GetFirstPairVector().Y();
      track2Data.Add(track2XY,track2->GetFirstPairVector().Z(), 0.001);
      track2XY[0] = track2->GetSecondPairVector().X();
      track2XY[1] = track2->GetSecondPairVector().Y();
      track2Data.Add(track2XY,track2->GetSecondPairVector().Z(), 0.001);
      track2XY[0] = track2->GetThirdPairVector().X();
      track2XY[1] = track2->GetThirdPairVector().Y();
      track2Data.Add(track2XY,track2->GetThirdPairVector().Z(), 0.001);

      ROOT::Fit::Fitter fitter2;
      ROOT::Math::WrappedMultiTF1 wf2(*f,3);
      fitter2.SetFunction(wf2);
      bool ret2 = fitter2.Fit(track2Data);
      const ROOT::Fit::FitResult & res2 = fitter2.Result();
      //res2.Print(std::cout);
      f->SetFitResult(res2);
    //The fit results are used for the direction of the second track
      TVector3 directTrack2(track2->GetFirstPairVector().X()-track2->GetSecondPairVector().X(),
                          track2->GetFirstPairVector().Y()-track2->GetSecondPairVector().Y(),
                          f->Eval(track2->GetFirstPairVector().X(),track2->GetFirstPairVector().Y()) 
                          - f->Eval(track2->GetSecondPairVector().X(),track2->GetSecondPairVector().Y()));

      //Making a vector that is perpendicular to both of the tracks
      TVector3 p = directTrack1.Cross(directTrack2);

      //Writing down equations for straight lines in a parametric form, in order to find the common perpendicular
      //Difference between points on the straight lines is in a direct to the perpendicular vector
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

      right(0,0) = track2->GetFirstPairVector().X()-track1->GetFirstPairVector().X();
      right(1,0) = track2->GetFirstPairVector().Y()-track1->GetFirstPairVector().Y();
      right(2,0) = track2->GetFirstPairVector().Z()-track1->GetFirstPairVector().Z();

      TMatrixT<double> matInv(3,3);
      matInv = mat.Invert();
      TMatrixT<double> lambda(3,1);
      lambda = matInv*right;
      TVector3 orig(track1->GetFirstPairVector().X(), track1->GetFirstPairVector().Y(), track1->GetFirstPairVector().Z());
      TVector3 orig2(track2->GetFirstPairVector().X(), track2->GetFirstPairVector().Y(), track2->GetFirstPairVector().Z());
      TVector3 vertex = orig + lambda(0,0)*directTrack1;
      TVector3 vertex2 = orig2 + lambda(1,0)*directTrack2;
      if (fabs(lambda(2,0)) < fTrackDistanceCut && fabs(vertex2.Z()) < 0.015 ){
        ERFootMuSiVertex* vert = AddVertex((vertex.X() + vertex2.X())/2., (vertex.Y() + vertex2.Y())/2.,(vertex.Z() + vertex2.Z())/2.);
        vert->AddTrack(iTrack);
        vert->AddTrack(jTrack);
      }
    }
  }
  Int_t rems = 0;
  //merge vertices
  for (Int_t iVert = 0; iVert < fFootMuSiVertices->GetEntriesFast(); iVert++){
    ERFootMuSiVertex* vert1 = (ERFootMuSiVertex*)fFootMuSiVertices->At(iVert);
    for (Int_t jVert = iVert+1; jVert < fFootMuSiVertices->GetEntriesFast(); jVert++){
      if(iVert == jVert)
      {
        continue;
      }
      ERFootMuSiVertex* vert2 = (ERFootMuSiVertex*)fFootMuSiVertices->At(jVert);
      Float_t dist = TMath::Sqrt((vert2->X()-vert1->X())*(vert2->X()-vert1->X()) +  
                                  (vert2->Y()-vert1->Y())*(vert2->Y()-vert1->Y()) + 
                                  (vert2->Z()-vert1->Z())*(vert2->Z()-vert1->Z()));
      if(dist < fVerticesMergeDistanceCut ){
        std::cout << "Vertices merging!" << std::endl;
        vert1->SetX((vert1->X()+vert2->X())/2.);
        vert1->SetY((vert1->Y()+vert2->Y())/2.);
        vert1->SetZ((vert1->Z()+vert2->Z())/2.);
        for (Int_t iTrack = 0; iTrack < vert2->TrackNb(); iTrack++){
          vert1->AddTrack(vert2->Track(iTrack));
        }
        rems++;
        if(rems%1000==0){
        LOG(INFO) << "rems = " << rems << FairLogger::endl; 
        }
        fFootMuSiVertices->RemoveAt(jVert);
      }
      fFootMuSiVertices->Compress();
    }
  }
  std::cout << "Vertices count: " << fFootMuSiVertices->GetEntriesFast() << std::endl;
  for(Int_t iVert=0; iVert < fFootMuSiVertices->GetEntriesFast(); iVert++){
    ERFootMuSiVertex* vert = (ERFootMuSiVertex*)fFootMuSiVertices->At(iVert);
    std::cout << "Vertex "<< iVert << ": (" <<  vert->X() << "," << vert->Y() << "," << vert->Z() << ")" << std::endl;
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
ERFootMuSiVertex* ERFootMuSiVertexFinder::AddVertex(Float_t x, Float_t y, Float_t z){
  ERFootMuSiVertex *vertex = new((*fFootMuSiVertices)[fFootMuSiVertices->GetEntriesFast()])
                              ERFootMuSiVertex(x,y,z);
  return vertex;
}
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
ClassImp(ERFootMuSiVertexFinder)

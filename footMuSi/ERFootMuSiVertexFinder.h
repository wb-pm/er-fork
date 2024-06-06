    /********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERFootMuSiVertexFinder_H
#define ERFootMuSiVertexFinder_H

#include "TClonesArray.h"

#include "FairTask.h"

#include "ERFootMuSiVertex.h"

class ERFootMuSiVertexFinder : public FairTask {

public:
  /** Default constructor **/
  ERFootMuSiVertexFinder();

  /** Constructor 
  ** verbose: 1 - only standard log print
  **/
  ERFootMuSiVertexFinder(Int_t verbose);

  /** Destructor **/
  ~ERFootMuSiVertexFinder();

  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();
  
  /** Modifiers **/
  void SetTrackDistanceCut(Double_t dist){fTrackDistanceCut = dist;}
  void SetVerticesMergeDistanceCut(Double_t mergeDistance){fVerticesMergeDistanceCut = mergeDistance;}
  /** Accessors **/ 
protected:
  //Input arrays
  TClonesArray *fFootMuSiTracks;

  //Output arrays
  TClonesArray *fFootMuSiVertices;
  

  ERFootMuSiVertex* AddVertex(Double_t x, Double_t y, Double_t z);
  ERFootMuSiVertex* AddVertex(ERFootMuSiVertex& oldVertex);
protected:

private:
  Double_t fTrackDistanceCut;
  Double_t fVerticesMergeDistanceCut;

  virtual void SetParContainers();
  
  ClassDef(ERFootMuSiVertexFinder,1)
};

#endif

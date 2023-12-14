/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSiMatcher_H
#define ERFootMuSiMatcher_H


#include "TClonesArray.h"
#include "TH1F.h"

#include "FairTask.h"

class ERFootMuSiMatcher : public FairTask {

public:
  /** Default constructor **/
  ERFootMuSiMatcher();

  /** Constructor 
  ** verbose: 1 - only standard log print, 2 - print digi information 
  **/
  ERFootMuSiMatcher(Int_t verbose);

  /** Destructor **/
  ~ERFootMuSiMatcher();

  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();
  
  /** Modifiers **/

  /** Accessors **/ 
protected:
  //Input arrays
  TClonesArray *fFootMuSiPoints;
  TClonesArray *fFootMuSiHits;
  TClonesArray *fFootMuSiTracks;
  TClonesArray *fFootMuSiVertecies;
  TClonesArray *fMCTracks;
  Int_t fTrueTracksNb;
  Int_t fWrongTracksNb;
  Int_t fMCTracksNb;
  Int_t fShortMCTracksNb;
  Int_t fNotFoundedVerteciesNb;

  //Histo
  TH1F* fHVertexDz;
  TH1F* fHVertexDxy;
protected:
  
private:
  virtual void SetParContainers();
  
  ClassDef(ERFootMuSiMatcher,1)
};

struct MCVertex{
  Float_t x;
  Float_t y;
  Float_t z;
  MCVertex(Float_t x_, Float_t y_, Float_t z_){x =x_;  y=y_; z=z_;}
};

#endif

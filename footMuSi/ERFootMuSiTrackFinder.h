/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSiTrackFinder_H
#define ERFootMuSiTrackFinder_H

#include <utility>
#include <limits>
#include "TClonesArray.h"

#include "ERTask.h"
#include "ERFootMuSiHit.h"
#include "ERFootMuSiTrack.h"
#include "ERFootMuSiSetup.h"

/** @class ERFootMuSiTrackFinder
 ** @brief 
 ** @author 
 ** @version 1.0
**/

class ERFootMuSiTrackFinder : public ERTask {
public:
  /** @brief Default constructor **/
  ERFootMuSiTrackFinder();
  /** @brief Constructor 
   ** @param verbosity level **/
  ERFootMuSiTrackFinder(Int_t verbose);
  /** @brief Destructor **/
  ~ERFootMuSiTrackFinder() = default;
  /* Modifiers */
  void SetHitStation(TString subassemblyName, TString componentIdX, TString componentIdY); 
  void SetHitStation(TString subassemblyName, TString componentId);
  void SetHitPositionCorrection(const TString& station_name, ERChannel channel,
                                  float strip_fraction);
  void SetStripEdepRange(Double_t edepMin, Double_t edepMax);
  void SetEdepMaxDiffXY(Double_t edepDiff) {fEdepDiffXY = edepDiff;}
  void SetAngleBetweenHitsCut(Double_t angleCut) {fAngleBetweenHitsCut = angleCut;}
public:
  /** @brief Defines all input and output object colletions participating
   ** in track finding. **/
  virtual InitStatus Init();
  /** @brief Defines the transformation actions for all input data (Digi) to 
   ** output data (Hit) for each event. **/
  virtual void Exec(Option_t* opt);
  /** @brief Resets all output data. **/
  virtual void Reset();
protected:
  //Paramaters
  ERFootMuSiSetup* fFootMuSiSetup = nullptr;      ///< access to ERFootMuSiSetup class instance
  //Input arrays
  std::map<TString, TClonesArray*> fFootMuSiDigi;
  //Output arrays
  std::map<TString, TClonesArray*> fFootMuSiHit;
  TClonesArray* fFootMuSiTrack = nullptr;
  TClonesArray* fMCTracks;
  TClonesArray* fMCEventHeader;
  //// map<subassembly,map<component, pair<xBranch, yBranch>>> 
  std::map<TString, std::map<TString, std::pair<TString, TString>>> fSiHitStationsPair;
  std::map<TString, std::map<ERChannel, float>> hit_position_corrections_; 
  Double_t fSiDigiEdepMin = std::numeric_limits<double>::min();
  Double_t fSiDigiEdepMax = std::numeric_limits<double>::max();
  Double_t fEdepDiffXY = std::numeric_limits<double>::max();
private:
  Double_t fAngleBetweenHitsCut;
  /** @brief Adds a ERFootMuSiHit to the output Collection **/
  ERFootMuSiHit* AddHit(const TVector3& xStationHit, const TVector3& yStationHit,
                              const TVector3& xStationLocalHit, const TVector3& yStationLocalHit, 
                              Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep,
                              const TString& digiBranchName);
  /** @brief Adds a ERFootMuSiTrack to the output Collection **/
/*   ERFootMuSiTrack* AddTrack(ERFootMuSiHit* firstHit,ERFootMuSiHit* secondHit,ERFootMuSiHit* thirdHit,Double_t hitsFitChi2); */
  ERFootMuSiTrack* AddTrack(const TVector3& firstHit, const TVector3& secondHit, const TVector3& thirdHit);
  void CreateHitInFootMuSi(Int_t xChannelIndex, Int_t yChannelIndex, Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep,
                               const TString& xBranchName, const TString& yBranchName, const TString& trackBranchName);
  TVector3 GetGlobalHitPositionByStrip(const TString& branch_name, ERChannel channel) const;
  ClassDef(ERFootMuSiTrackFinder, 1)
};
#endif

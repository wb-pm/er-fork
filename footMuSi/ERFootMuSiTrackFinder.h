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
  void SetInteractionPosition(double x, double y, double z);
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
  //// map<subassembly,map<component, pair<xBranch, yBranch>>> 
  std::map<TString, std::map<TString, std::pair<TString, TString>>> fSiHitStationsPair;
  std::map<TString, std::map<ERChannel, float>> hit_position_corrections_; 
  Double_t fSiDigiEdepMin = std::numeric_limits<double>::min();
  Double_t fSiDigiEdepMax = std::numeric_limits<double>::max();
  Double_t fEdepDiffXY = std::numeric_limits<double>::max();
  double interaction_x_ = 0.;
  double interaction_y_ = 0.;
  double interaction_z_ = 0.;
  bool interaction_position_is_set_ = false;
private:
  Double_t fAngleBetweenHitsCut;
  /** @brief Adds a ERFootMuSiHit to the output Collection **/
  ERFootMuSiHit* AddHit(const TVector3& targetVertex, const TVector3& xStationVertex, const TVector3& yStationVertex,
                              const TVector3& xStationLocalVertex, const TVector3& yStationLocalVertex, 
                              Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep,
                              const TString& digiBranchName);
  /** @brief Adds a ERFootMuSiTrack to the output Collection **/
  ERFootMuSiTrack* AddTrack(const TVector3& firstPairVector, const TVector3& secondPairVector,const TVector3& thirdPairVector);
  ERFootMuSiTrack* AddTrack(const TVector3& firstHitPointVector, const TVector3& secondHitPointVector);
  void CreateHitInFootMuSi(Int_t xChannelIndex, Int_t yChannelIndex, Int_t xChannel, Int_t yChannel, Double_t xEdep, Double_t yEdep,
                               const TString& xBranchName, const TString& yBranchName, const TString& trackBranchName);
  void CreateHitInRFootMuSi(Int_t xChannelIndex, Int_t yChannelIndex, Int_t phiChannel, Int_t RChannel, Double_t phiEdep, Double_t rEdep,
                               const TString& phiBranchName, const TString& rBranchName, const TString& trackBranchName);
  TVector3 GetGlobalHitPositionByStrip(const TString& branch_name, ERChannel channel) const;
  ClassDef(ERFootMuSiTrackFinder, 1)
};
#endif

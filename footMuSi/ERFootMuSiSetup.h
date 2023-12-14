/* May 23, 2021 at 3:01 PM

Correction of telescope coordinate and indexing in non-uniform station for EXP1904 */
#ifndef ERFootMuSiSetup_H
#define ERFootMuSiSetup_H

#include "ERSetup.h"

#include "TString.h"
#include <TXMLNode.h>
#include "Rtypes.h"
#include "TVector3.h"
#include "TGeoMatrix.h"

struct ERFootMuSiStrip{
  Double_t fGlobalX = -1.;
  Double_t fGlobalY = -1.;
  Double_t fGlobalZ = -1.;
  Double_t fLocalX = -1.;
  Double_t fLocalY = -1.;
  Double_t fLocalZ = -1.;
  Double_t fWidth = -1.;
  ERFootMuSiStrip() = default;
  ERFootMuSiStrip(Double_t globalX, Double_t globalY, Double_t globalZ,
                   Double_t  localX, Double_t  localY, Double_t localZ,
                   Double_t width);
  ERFootMuSiStrip(Double_t* globTrans, Double_t* localTrans, Double_t width);
};

struct ERRFootMuSiStrip {
  Double_t fPhi = -1.;
  Double_t fR = -1.;
  ERRFootMuSiStrip() = default;
  ERRFootMuSiStrip(const Double_t phi, const Double_t r) : fPhi(phi), fR(r) {}
};

class ERFootMuSiSetup : public ERSetup {
public:
  enum StationType {QStation, RStation};
  virtual ~ERFootMuSiSetup() = default;
  static ERFootMuSiSetup* Instance();
  /* Modifiers */
  /* Accessors */
  Double_t GetStripGlobalX(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripGlobalY(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripGlobalZ(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripLocalX(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripLocalY(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripLocalZ(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripPhi(const TString& componentBranchName, Int_t stripNb) const;
  Double_t GetStripR(const TString& componentBranchName, Int_t stripNb) const;
  TVector3 GetStationTranslation(const TString& componentBranchName) const;
  Double_t GetStripWidth(TString componentBranchName, Int_t stripNb) const;
  TVector3 GetStripLocalPosition(const TString& componentBranchName,
                                unsigned int stripNb) const;
  TVector3 ToStationCoordinateSystem(const TString& componentBranchName, 
                                    const TVector3& vectorInGlobalCS) const;
  TVector3 ToGlobalCoordinateSystem(const TString& componentBranchName,
                                    const TVector3& vectorInStationCS) const;
  StationType GetStationType(const TString& componentBranchName) const; 

public:
  virtual void ReadGeoParamsFromParContainer();
  // static void PrintDetectorParameters(void);
  // static void PrintDetectorParametersToFile(TString fileName);
private:
  ERFootMuSiSetup() = default;
  void GetTransInMotherNode (TGeoNode const* node, Double_t b[3]);
  void FillRStrips(TGeoNode* r_station, const TString& branch_name);
  std::map<TString, std::vector<ERFootMuSiStrip>> fStrips;
  std::map<TString, std::vector<ERRFootMuSiStrip>> fRStrips;
  std::map<TString, TGeoHMatrix> fStationGlobalToLocalMatrixies;
  std::map<TString, StationType> fStationTypes;
  static ERFootMuSiSetup* fInstance;
  bool fGeometryInited = false;
  ClassDef(ERFootMuSiSetup,1)
};
#endif

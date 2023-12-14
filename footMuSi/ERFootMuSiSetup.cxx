/*  May 23, 2021 at 3:01 PM

Correction of telescope coordinate and indexing in non-uniform station for EXP1904 */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERFootMuSiSetup.h"

#include <ostream>
#include <iostream>

#include "TGeoSphere.h"
#include "TError.h"
#include "TMath.h"
#include "TGeoManager.h"
#include "TGeoMatrix.h"
#include "TROOT.h"
#include <Riostream.h>
#include <TDOMParser.h>
#include <TXMLAttr.h>
#include <TXMLNode.h>
#include <TList.h>

#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairGeoLoader.h"
#include "FairGeoMedium.h"
#include "FairGeoInterface.h"
#include "FairGeoBuilder.h"
#include "FairGeoMedia.h"
#include "FairLogger.h"

ERFootMuSiSetup* ERFootMuSiSetup::fInstance = nullptr;  
//--------------------------------------------------------------------------------------------------
ERFootMuSiStrip::ERFootMuSiStrip(Double_t globalX, Double_t globalY, Double_t globalZ,
                                   Double_t  localX, Double_t  localY, Double_t localZ,
                                   Double_t width)
    : fGlobalX(globalX), fGlobalY(globalY), fGlobalZ(globalZ),
      fLocalX(localX), fLocalY(localY), fLocalZ(localZ), fWidth(width)
{
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiStrip::ERFootMuSiStrip(Double_t* globTrans, Double_t* localTrans, Double_t width)
    : fGlobalX(globTrans[0]), fGlobalY(globTrans[1]), fGlobalZ(globTrans[2]),
      fLocalX(localTrans[0]), fLocalY(localTrans[1]), fLocalZ(localTrans[2]), fWidth(width)
{
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiSetup* ERFootMuSiSetup::Instance(){
  if (fInstance == NULL) {
    fInstance = new ERFootMuSiSetup();
    return fInstance;
  }
  else
    return fInstance;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripGlobalX(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fGlobalX;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripGlobalY(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fGlobalY;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripGlobalZ(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fGlobalZ;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripLocalX(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fLocalX;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripLocalY(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fLocalY;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripLocalZ(const TString& componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fLocalZ;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripWidth(TString componentBranchName, Int_t stripNb) const {
  return fStrips.at(componentBranchName).at(stripNb).fWidth;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripPhi(const TString& componentBranchName, const Int_t stripNb) const {
  if (fRStrips.find(componentBranchName) == fRStrips.end()) {
    LOG(FATAL) << "R strips has not been filled for " << componentBranchName << FairLogger::endl;
  }
  if (stripNb >= fRStrips.at(componentBranchName).size()) {
    LOG(FATAL) << "Wrong strip number " << stripNb << " for station " <<  componentBranchName << FairLogger::endl;
  }
  if (fRStrips.at(componentBranchName).at(stripNb).fPhi == -1) {
    LOG(FATAL) << "Strip of station " << componentBranchName << " has not attribute phi" << FairLogger::endl;
  }
  return fRStrips.at(componentBranchName).at(stripNb).fPhi;
}
//--------------------------------------------------------------------------------------------------
Double_t ERFootMuSiSetup::GetStripR(const TString& componentBranchName, const Int_t stripNb) const {
  if (fRStrips.find(componentBranchName) == fRStrips.end()) {
    LOG(FATAL) << "R strips has not been filled for " << componentBranchName << FairLogger::endl;
  }
  if (stripNb >= fRStrips.at(componentBranchName).size()) {
    LOG(FATAL) << "Wrong strip number " << stripNb << " for station " <<  componentBranchName << FairLogger::endl;
  }
  if (fRStrips.at(componentBranchName).at(stripNb).fR == -1) {
    LOG(FATAL) << "Strip of station " << componentBranchName << " has not attribute R" << FairLogger::endl;
  }
  return fRStrips.at(componentBranchName).at(stripNb).fR;
}
//--------------------------------------------------------------------------------------------------
TVector3 ERFootMuSiSetup::
GetStripLocalPosition(const TString& componentBranchName, const unsigned int stripNb) const {
  return TVector3(fStrips.at(componentBranchName).at(stripNb).fLocalX,
                  fStrips.at(componentBranchName).at(stripNb).fLocalY,
                  fStrips.at(componentBranchName).at(stripNb).fLocalZ);
}
//--------------------------------------------------------------------------------------------------
TVector3 ERFootMuSiSetup::GetStationTranslation(const TString& componentBranchName) const {
  return fStationGlobalToLocalMatrixies.at(componentBranchName).GetTranslation();
}
//--------------------------------------------------------------------------------------------------
ERFootMuSiSetup::StationType ERFootMuSiSetup::GetStationType(const TString& componentBranchName) const {
  if (fStationTypes.find(componentBranchName) == fStationTypes.end())
    LOG(FATAL) << "Station type has not been filled for " << componentBranchName << FairLogger::endl;
  return fStationTypes.at(componentBranchName);
}
//--------------------------------------------------------------------------------------------------
TVector3 ERFootMuSiSetup::ToStationCoordinateSystem (const TString& componentBranchName, 
                                                       const TVector3& vectorInGlobalCS) const {
  Double_t global[3], local[3];
  for (int i(0); i < 3; i++)
    global[i] = vectorInGlobalCS[i];
  fStationGlobalToLocalMatrixies.at(componentBranchName).MasterToLocal(global, local);
  return TVector3(local);
}
//--------------------------------------------------------------------------------------------------
TVector3 ERFootMuSiSetup::ToGlobalCoordinateSystem(const TString& componentBranchName, 
                                                      const TVector3& vectorInStationCS) const {
  Double_t global[3], local[3];
  for (int i(0); i < 3; i++)
    local[i] = vectorInStationCS[i];
  fStationGlobalToLocalMatrixies.at(componentBranchName).LocalToMaster(local, global);
  return TVector3(global);
}
//--------------------------------------------------------------------------------------------------
TGeoHMatrix GetGlobalToLocalMatrix(const TString& path) {
  TGeoIterator nextNode(gGeoManager->GetTopVolume());
  while(nextNode()) {
    TString nodePath;
    nextNode.GetPath(nodePath);
    if (nodePath == path) {
      return (*static_cast<const TGeoHMatrix*>(nextNode.GetCurrentMatrix()));
    }
  }
  LOG(FATAL) << "Path " << path << " not found in geometry" << FairLogger::endl;
  return nullptr;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiSetup::GetTransInMotherNode (TGeoNode const* node, Double_t b[3]) {
  memcpy(b, node->GetMatrix()->GetTranslation(), sizeof(double)*3);
}
// Написать несколько методов для работы с объемами:
// 1) Функция получения координаты в глобальной СК. (скорее всего функция в п.1) 
//    Проход от самого низкого дочернего объема до родительского внтри одной функции
// ------------------------------- -----------------------------------------------------------------
void ERFootMuSiSetup::ReadGeoParamsFromParContainer() {
  if (fGeometryInited)
    return;
  LOG(DEBUG) << "Loading FootMuSi setup from parameters database file." << FairLogger::endl;
  if ( ! gGeoManager ) {
    std::cerr << "ERFootMuSiSetup: cannot initialise without TGeoManager!"<< std::endl;
  }
  gGeoManager->CdTop();
  
  TGeoNode* cave = gGeoManager->GetCurrentNode();
  TGeoNode* qFootMuSi  = NULL;
  TGeoNode* qFootMuSiDetector = NULL;
  TGeoNode* qFootMuSiStation = NULL;
  const auto strip_width = [](TGeoNode* strip_node) {
    const auto strip_shape = strip_node->GetVolume()->GetShape();
    double low, high;
    return TMath::Min(strip_shape->GetAxisRange(1, low, high),
                      strip_shape->GetAxisRange(2, low, high));
  };
  for (Int_t iNode = 0; iNode < cave->GetNdaughters(); iNode++) { // cycle by volumes in TOP
    TString detectorName = cave->GetDaughter(iNode)->GetName();
    if ( detectorName.Contains("FootMuSi", TString::kIgnoreCase) ) {
      qFootMuSi = cave->GetDaughter(iNode); 
      for (Int_t iDetector = 0; iDetector < qFootMuSi->GetNdaughters(); iDetector++) { // cycle by subassemblies in QFootMuSi
        qFootMuSiDetector = qFootMuSi->GetDaughter(iDetector);
        for (Int_t iStation = 0; iStation < qFootMuSiDetector->GetNdaughters(); iStation++) { // cycle by components in station
          qFootMuSiStation = qFootMuSiDetector->GetDaughter(iStation);
          TString qFootMuSiStationName = qFootMuSiStation->GetName();
          Double_t boxInStripTrans[3];
          Double_t stripInStationTrans[3];
          Double_t stripInDetectorTrans[3];
          Double_t stripGlobTrans[3];
          const bool is_r_station = qFootMuSiStation->GetNdaughters() == 1 
              && TString(qFootMuSiStation->GetDaughter(0)->GetName()).Contains("r_station");
          TString digiBranchName = qFootMuSiStationName;
          digiBranchName.Remove(digiBranchName.Last('_'), digiBranchName.Length());
          if (qFootMuSiStationName.Contains("DoubleSi", TString::kIgnoreCase) ) {
            TString firstStripArrayName, secondStripArrayName;
            if (qFootMuSiStationName.Contains("XY")) {
              firstStripArrayName = digiBranchName + "_X";
              secondStripArrayName = digiBranchName + "_Y";
            } else {
              firstStripArrayName = digiBranchName + "_Y";
              secondStripArrayName = digiBranchName + "_X";              
            }
            if (is_r_station) {
              LOG(DEBUG) << "Read geometry info for Double R station corresponded to volume " << qFootMuSiStationName 
                         << " and branch name " << digiBranchName << FairLogger::endl;
              auto* r_station = qFootMuSiStation->GetDaughter(0);
              FillRStrips(r_station, firstStripArrayName);
              auto* any_segment = r_station->GetDaughter(0);
              FillRStrips(any_segment, secondStripArrayName);
              fStationTypes[firstStripArrayName] = StationType::RStation;
              fStationTypes[secondStripArrayName] = StationType::RStation;
            } else {
              TGeoNode* doubleSiStrip;
              Bool_t    flagFirstStripReaded = kFALSE;
              Int_t     iDoubleSiStrip = 0;
              for (; iDoubleSiStrip < qFootMuSiStation->GetNdaughters(); iDoubleSiStrip++) {
                doubleSiStrip = qFootMuSiStation->GetDaughter(iDoubleSiStrip);
                GetTransInMotherNode(doubleSiStrip, stripInStationTrans);
                // Now we assume that QFootMuSi center in the global zero.
                // It is neccesary to write clear function to find global coordinates
                // by all forefathers nodes if possible. Maybe with some FairRoot methods
                qFootMuSiStation->LocalToMaster(stripInStationTrans, stripInDetectorTrans);
                qFootMuSiDetector->LocalToMaster(stripInDetectorTrans, stripGlobTrans);
                fStrips[firstStripArrayName].emplace_back(stripGlobTrans, stripInStationTrans,
                                                          strip_width(doubleSiStrip));
                LOG(DEBUG) << firstStripArrayName << " strip " 
                                << fStrips[firstStripArrayName].size()-1 << " global coordinates: "
                                << stripGlobTrans[0] << ", " 
                                << stripGlobTrans[1] << ", " 
                                << stripGlobTrans[2] ;
                LOG(DEBUG)  << " | local coordinates: "
                            << boxInStripTrans[0] << ", " 
                            << boxInStripTrans[1] << ", " 
                            << boxInStripTrans[2] << FairLogger::endl; 
                TGeoNode* doubleSiBox;
                Int_t iDoubleSiBox = 0;
                if (!flagFirstStripReaded) {
                  for (; iDoubleSiBox < doubleSiStrip->GetNdaughters(); iDoubleSiBox++) {
                    Double_t siBoxLocalTrans[3];
                    doubleSiBox = doubleSiStrip->GetDaughter(iDoubleSiBox);
                    TString siBoxName = doubleSiBox->GetName();
                    GetTransInMotherNode(doubleSiBox, boxInStripTrans);
                    (qFootMuSiStationName.Contains("XY")) ? stripInStationTrans[0] = 0
                                                          : stripInStationTrans[1] = 0;
                    doubleSiStrip->LocalToMaster(boxInStripTrans, stripInStationTrans);
                    qFootMuSiStation->LocalToMaster(stripInStationTrans, stripInDetectorTrans);
                    qFootMuSiDetector->LocalToMaster(stripInDetectorTrans, stripGlobTrans);
                    fStrips[secondStripArrayName].emplace_back(stripGlobTrans, boxInStripTrans,
                                                               strip_width(doubleSiBox));
                    LOG(DEBUG) << secondStripArrayName << " strip " 
                                << fStrips[secondStripArrayName].size()-1 << " global coordinates: "
                                << stripGlobTrans[0] << ", " 
                                << stripGlobTrans[1] << ", " 
                                << stripGlobTrans[2];
                    LOG(DEBUG)  << " | local coordinates: "
                                << boxInStripTrans[0] << ", " 
                                << boxInStripTrans[1] << ", " 
                                << boxInStripTrans[2] << FairLogger::endl;; 

                  }
                  flagFirstStripReaded = kTRUE;
                }
              }
              fStationTypes[firstStripArrayName] = StationType::QStation;
              fStationTypes[secondStripArrayName] = StationType::QStation;
            }
            TString stationPath;
            stationPath.Form("cave/%s/%s/%s", qFootMuSi->GetName(), qFootMuSiDetector->GetName(),
                             qFootMuSiStationName.Data());
            fStationGlobalToLocalMatrixies[firstStripArrayName] = GetGlobalToLocalMatrix(stationPath);
            fStationGlobalToLocalMatrixies[secondStripArrayName] = fStationGlobalToLocalMatrixies[firstStripArrayName];
            fStationGlobalToLocalMatrixies[firstStripArrayName].Print();
          } 
          if (qFootMuSiStationName.Contains("SingleSi", TString::kIgnoreCase) ) {
            if (is_r_station) {
              LOG(DEBUG) << "Read geometry info for R station corresponded to volume " << qFootMuSiStationName 
                         << " and branch name " << digiBranchName << FairLogger::endl;
              FillRStrips(qFootMuSiStation->GetDaughter(0), digiBranchName);
              fStationTypes[digiBranchName] = StationType::RStation;
            } else {
              TGeoNode* singleSiStrip;
              Int_t     iSingleSiStrip = 0;
              for (; iSingleSiStrip < qFootMuSiStation->GetNdaughters(); iSingleSiStrip++) {
                singleSiStrip = qFootMuSiStation->GetDaughter(iSingleSiStrip);
                GetTransInMotherNode(singleSiStrip, stripInStationTrans);
                qFootMuSiStation->LocalToMaster(stripInStationTrans, stripInDetectorTrans);
                qFootMuSiDetector->LocalToMaster(stripInDetectorTrans, stripGlobTrans);
                LOG(DEBUG) << qFootMuSiStationName << " strip " 
                    << iSingleSiStrip << " global coordinates: "
                    << stripGlobTrans[0] << ", " 
                    << stripGlobTrans[1] << ", " 
                    << stripGlobTrans[2]; 
                LOG(DEBUG) << " | local coordinates: " 		         
                    << stripInStationTrans[0] << ", " 
                    << stripInStationTrans[1] << ", " 
                    << stripInStationTrans[2] << FairLogger::endl; 
                fStrips[digiBranchName].emplace_back(stripGlobTrans, stripInStationTrans,
                                                     strip_width(singleSiStrip)); 
              }
              fStationTypes[digiBranchName] = StationType::QStation;
            }
            TString stationPath;
            stationPath.Form("cave/%s/%s/%s", qFootMuSi->GetName(), qFootMuSiDetector->GetName(),
                             qFootMuSiStationName.Data());
            fStationGlobalToLocalMatrixies[digiBranchName] = GetGlobalToLocalMatrix(stationPath);
            fStationGlobalToLocalMatrixies[digiBranchName].Print();
          }
        }
      }
    }
  }
  gGeoManager->CdTop();
  fGeometryInited = true;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiSetup::FillRStrips(TGeoNode* r_station, const TString& branch_name) {
  const bool is_phi_station = branch_name.EndsWith("_X");
  std::cerr << 1 << std::endl;
  for (int i_strip = 0; i_strip < r_station->GetNdaughters(); i_strip++) {
    auto* strip = r_station->GetDaughter(i_strip);
    if (is_phi_station) {
      auto* combi_trans = dynamic_cast<TGeoCombiTrans*>(strip->GetMatrix());
      if (!combi_trans) {
        LOG(FATAL) << "Unexpected matrix type in R FootMuSi station" << FairLogger::endl;
      }
      const auto phi = combi_trans->GetRotation()->GetPhiRotation();
      fRStrips[branch_name].emplace_back(phi, -1.);
      LOG(DEBUG) << branch_name << " strip " << i_strip << " phi = " << phi << FairLogger::endl;
    } else {
      auto shape = dynamic_cast<TGeoSphere*>(strip->GetVolume()->GetShape());
      if (!shape) {
        LOG(FATAL) << "Unexpected shape type in R FootMuSi station" << FairLogger::endl;
      }
      const auto r_min = TMath::Tan(shape->GetTheta1() * TMath::DegToRad()) * shape->GetRmin();
      const auto r_max = TMath::Tan(shape->GetTheta2() * TMath::DegToRad()) * shape->GetRmax();
      const auto r = (r_max + r_min) / 2.;
      fRStrips[branch_name].emplace_back(-1., r);
      LOG(DEBUG) << branch_name << " strip " << i_strip << " R = " << r << FairLogger::endl;
    }
  }
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiSetup)

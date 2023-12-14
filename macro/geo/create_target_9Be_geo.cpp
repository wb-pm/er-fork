#if !defined(__CLING__) 

#include "TString.h"
#include "TSystem.h"
#include "TGeoMedium.h"
#include "TGeoManager.h"
#include "TROOT.h"
#include "TGeoVolume.h"
#include "TFile.h"
#include "TBrowser.h"
#include "TGeoTube.h"

#include "FairGeoLoader.h"
#include "FairGeoInterface.h"
#include "FairGeoMedium.h"
#include "FairGeoMedia.h"
#include "FairGeoBuilder.h"

#endif
void create_target_9Be_geo()

{
  TString erPath = gSystem->Getenv("VMCWORKDIR");
  // Output paths
  TString outGeoFilenameRoot = erPath + "/geometry/target_9Be_5cm_geo.root";
  // Input paths
  TString medFile = erPath + "/geometry/media.geo";

  // Materials and media
  FairGeoLoader* geoLoad = new FairGeoLoader("TGeo", "FairGeoLoader");
  FairGeoInterface* geoFace = geoLoad->getGeoInterface();
  geoFace->setMediaFile(medFile);
  geoFace->readMedia();
  FairGeoMedia* geoMedia = geoFace->getMedia();
  FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

  // Geometry manager
  TGeoManager* geoM = (TGeoManager*)gROOT->FindObject("FAIRGeom");

  TString mediumName = "beryllium";
  FairGeoMedium* mberyllium = geoMedia->getMedium(mediumName);
  if (!mberyllium) Fatal("create_target_9Be_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mberyllium);
  TGeoMedium* pberyllium = geoM->GetMedium(mediumName);
  if (!pberyllium) Fatal("create_target_9Be_geo", "Medium %s not found", mediumName.Data());

  // General dimensions

  Double_t target9Be_R = 10.; // cm
  Double_t target9Be_Z = 5; // cm

  //Translations and rotations

  Double_t transX = 0.; // cm
  Double_t transY = 0.; // cm
  Double_t transZ = 0.; // cm

  TGeoRotation* rotNoRot = new TGeoRotation("rotNoRot", 0., 0., 0.);
  rotNoRot->RegisterYourself();

  // Shapes
  TGeoTube* target9BeShape = new TGeoTube("target9BeShape",0,target9Be_R,target9Be_Z/2);
  
  // Volumes
  TGeoVolume* target9BeVol = new TGeoVolume("target9BeVol",target9BeShape,pberyllium);

  // This is the one but last level in the hierarchy
  // This volume-assembly is the only volume to be inserted into TOP

  TGeoVolumeAssembly* subdetectorVolAss = new TGeoVolumeAssembly("target_9Be");
  subdetectorVolAss->AddNode(target9BeVol, 1,
    new TGeoCombiTrans("mTarget9BeVolInTarget",transX, transY, transZ, rotNoRot));

  // World


  TGeoVolumeAssembly* topVolAss = new TGeoVolumeAssembly("TOP");
  topVolAss->AddNode(subdetectorVolAss,1);

  geoM->SetTopVolume(topVolAss);
  geoM->CloseGeometry();
  geoM->CheckOverlaps();
  geoM->PrintOverlaps();

  TFile* outGeoFileRoot = new TFile(outGeoFilenameRoot, "RECREATE");
  geoM->GetTopVolume()->Write();
  outGeoFileRoot->Close();

  // Draw
  TBrowser* bro = new TBrowser("bro", "bro");
  geoM->GetTopVolume()->Draw("ogl");
}
void create_target_3h_1h_steel_geo()
{
  TString erPath = gSystem->Getenv("VMCWORKDIR");

  // Output paths
  TString outGeoFilenameRoot = erPath + "/geometry/target.1h_Steel.geo.root";
  TString outGeoFilenameGdml = erPath + "/geometry/target.1h_Steel.gdml";

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

  TString mediumName;

  mediumName = "mylar";
  FairGeoMedium* mmylar = geoMedia->getMedium(mediumName);
  if (!mmylar) Fatal("create_target_1h_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mmylar);
  TGeoMedium* pmylar = geoM->GetMedium(mediumName);
  if (!pmylar) Fatal("create_target_1h_geo", "Medium %s not found", mediumName.Data());

  mediumName = "H2";
  FairGeoMedium* mH2 = geoMedia->getMedium(mediumName);
  if (!mH2) Fatal("create_target_1h_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mH2);
  TGeoMedium* pH2 = geoM->GetMedium(mediumName);
  if (!pH2) Fatal("create_target_1h_geo", "Medium %s not found", mediumName.Data());
  
  mediumName = "beryllium";
  FairGeoMedium* mBeryllium = geoMedia->getMedium( mediumName);
  if ( ! mBeryllium ) Fatal("SOS", "FairMedium beryllium not found");
  geoBuild->createMedium(mBeryllium);
  TGeoMedium* pBeryllium = geoM->GetMedium("beryllium");
  if ( ! pBeryllium ) Fatal("SOS", "Medium vacuum not found");

  // General dimensions
  Double_t transX = 0.; // cm
  Double_t transY = 0.; // cm
  Double_t transZ = 0.; // cm
  Double_t target1HR = 1.25; // cm
  //Double_t target1HZ = 0.6; // cm
  Double_t target1HZ = 0.07; // cm
  //Double_t shellOuterThickness = 0.0010; // cm default=[0.5]
  //Double_t shellZThickness = 0.0010; // cm default=[0.25]
  Double_t shellOuterThickness = 0.001; // cm default=[0.5]
  Double_t shellZThickness = 0.001; // cm default=[0.25]

  // Shapes
  TGeoTube* target1HShape = new TGeoTube("target1HShape",
    0.,
    target1HR,
    target1HZ/2.);
  TGeoTube* targetShellShape = new TGeoTube("targetShellShape",
    0.,
    target1HR + shellOuterThickness,
    (target1HZ + 2*shellZThickness)/2.);

  // Volumes
  TGeoVolume* target1HVol = new TGeoVolume("target1HVol", target1HShape, pH2);
  TGeoVolume* targetShellVol = new TGeoVolume("targetShellVol", targetShellShape, pBeryllium);

  // Matrices
  TGeoRotation* rotNoRot = new TGeoRotation("rotNoRot", 0., 0., 0.);
  rotNoRot->RegisterYourself();

  // Structure
  targetShellVol->AddNode(target1HVol, 1);

  // This is the one but last level in the hierarchy
  // This volume-assembly is the only volume to be inserted into TOP
  TGeoVolumeAssembly* subdetectorVolAss = new TGeoVolumeAssembly("target_1h");
  subdetectorVolAss->AddNode(targetShellVol, 1,
    new TGeoCombiTrans("mTarget1HVolInTarget", transX, transY, transZ, rotNoRot));

  // World ------------------------------------
  TGeoVolumeAssembly* topVolAss = new TGeoVolumeAssembly("TOP");
  topVolAss->AddNode(subdetectorVolAss, 1);

  // Finalize
  geoM->SetTopVolume(topVolAss);
  geoM->CloseGeometry();
  geoM->CheckOverlaps();
  geoM->PrintOverlaps();
  
  // Export
  TFile* outGeoFileRoot = new TFile(outGeoFilenameRoot, "RECREATE");
  geoM->GetTopVolume()->Write();
  outGeoFileRoot->Close();

  // Draw
  TBrowser* bro = new TBrowser("bro", "bro");
  geoM->GetTopVolume()->Draw("ogl");
}

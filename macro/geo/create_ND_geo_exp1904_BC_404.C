TGeoXtru *createSixPolygon(Double_t d, Double_t thickness);

void create_ND_geo_exp1904_BC_404(TString SensitiveVolName)
{
  TString erPath = gSystem->Getenv("VMCWORKDIR");

  // Output paths
  TString outGeoFilenameRoot = erPath + "/geometry/ND.geo.exp1904.BC.404.root";

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

  mediumName = "Air";
  FairGeoMedium* mAir = geoMedia->getMedium(mediumName);
  if (!mAir) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mAir);
  TGeoMedium* pAir = geoM->GetMedium(mediumName);
  if (!pAir) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());
  
  mediumName = "Stilbene";
  FairGeoMedium* mStilbene = geoMedia->getMedium(mediumName);
  if (!mStilbene) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mStilbene);
  TGeoMedium* pStilbene = geoM->GetMedium(mediumName);
  if (!pStilbene) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());

  mediumName = "Steel";
  FairGeoMedium* mSteel = geoMedia->getMedium(mediumName);
  if (!mSteel) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mSteel);
  TGeoMedium* pSteel = geoM->GetMedium(mediumName);
  if (!pSteel) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());

  mediumName = "aluminium";
  FairGeoMedium* maluminium = geoMedia->getMedium(mediumName);
  if (!maluminium) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(maluminium);
  TGeoMedium* paluminium = geoM->GetMedium(mediumName);
  if (!paluminium) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());

  mediumName = "mylar";
  FairGeoMedium* mMylar = geoMedia->getMedium(mediumName);
  if (!mMylar) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mMylar);
  TGeoMedium* pMylar = geoM->GetMedium(mediumName);
  if (!pMylar) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());

  mediumName = "BC408";
  FairGeoMedium* mBC408 = geoMedia->getMedium(mediumName);
  if (!mBC408) Fatal("create_ND_geo", "FairMedium %s not found", mediumName.Data());
  geoBuild->createMedium(mBC408);
  TGeoMedium* pBC408 = geoM->GetMedium(mediumName);
  if (!pBC408) Fatal("create_ND_geo", "Medium %s not found", mediumName.Data());

  Double_t NDZPOZ = 490.;            //Расстояние от мишени до дальнего датчика
  Double_t r = 40;                  //Расстояние от мишени до стенки
  Double_t H = (NDZPOZ - r)*2;      //Длина по Оси-Z для PlaneShape
  Double_t scale = 10;              //в мм
  
  // Shapes
  TGeoBBox* PlaneShape = new TGeoBBox("PlaneShape",400./2., 400./2., H/2.);
  TGeoBBox* targetBox = new TGeoBBox("targetBox", 20./2., 20./2., 1./2.);
  TGeoBBox* wallBox = new TGeoBBox("wallBox", 30./2., 30./2., 1./2.);

  // Volume
  TGeoVolume* AirBox = new TGeoVolume("NDAirBox", PlaneShape, pAir);
  TGeoVolume* targetVol = new TGeoVolume("targetVol", targetBox, pAir);
  TGeoVolume* wallVol = new TGeoVolume("wallVol", wallBox, pAir);

  // Matrices
  TGeoRotation* rotNoRot = new TGeoRotation("rotNoRot", 0., 0., 0.);
  rotNoRot->RegisterYourself();

  SensitiveVolName.ToLower();

  if (SensitiveVolName == "crystal"){

    // General dimensions
    Double_t R_min_Crystal = 0.0; // cm
    Double_t R_max_Crystal = 4.0; // cm
    Double_t HeightZ_Crystal = 5.0; // cm
    Double_t R_min_Shell = 0.0; // cm
    Double_t R_max_Shell = 4.2; // cm
    Double_t HeightZ_Shell = 5.2; // cm
    Double_t R_min_Housing = 0.0; // cm
    Double_t R_max_Housing = 4.8; // cm
    Double_t HeightZ_Housing = 5.4; // cm

    // Shapes
    TGeoTube* crystalSh = new TGeoTube("crystalSh", R_min_Crystal, R_max_Crystal, HeightZ_Crystal/2.);
    TGeoTube* shellSh = new TGeoTube("shellSh", R_min_Shell, R_max_Shell, HeightZ_Shell/2.);
    TGeoTube* housingSh = new TGeoTube("housingSh", R_min_Housing, R_max_Housing, HeightZ_Housing/2.);

    // Volumes
    TGeoVolume* crystalVol = new TGeoVolume("crystalVol", crystalSh, pStilbene);
    crystalVol->SetLineColor(kBlue);

    TGeoVolume* shellVol = new TGeoVolume("shellVol", shellSh, paluminium);
    shellVol->SetLineColor(kRed);

    TGeoVolume* housingVol = new TGeoVolume("housingVol", housingSh, pSteel);
    housingVol->SetLineColor(kGray);
    housingVol->SetTransparency(60);

    TGeoVolume* moduleVol = new TGeoVolumeAssembly("moduleVol");
    moduleVol->SetLineColor(kOrange);
    moduleVol->SetTransparency(70);

    // Structure
    // Crystal in shell
    shellVol->AddNode(crystalVol, 1, new TGeoCombiTrans("mCrystalInShell", 0., 0., (HeightZ_Shell-HeightZ_Crystal)/2., rotNoRot));
    // Shell in housing
    housingVol->AddNode(shellVol, 1, new TGeoCombiTrans("mCrystalInShell", 0., 0., (HeightZ_Housing-HeightZ_Crystal)/2., rotNoRot));
    // housing in Module
    moduleVol->AddNode(housingVol, 1, new TGeoCombiTrans("mCrystalInShell", 0., 0., (HeightZ_Shell-HeightZ_Crystal)/2., rotNoRot));

    float R = 48; //mm    
    float h = TMath::Sqrt(3)*R; //высота равностороннего треугольника со стороной 2R

    float xyz[45][3] = {  
      8*R,  -2*h, 7865  , //0
      6*R,  -2*h, 7900  , //1
      4*R,  -2*h, 7925  , //2
      2*R,  -2*h, 7939.9  , //3
      0.0,  -2*h, 7945  , //4
      -2*R, -2*h, 7939.9  , //5
      -4*R, -2*h, 7925  , //6
      -6*R, -2*h, 7900  , //7
      -8*R, -2*h, 7865  , //8
      9*R,  -h, 7865  , //9
      7*R,  -h, 7900  , //10
      5*R,  -h, 7925  , //11
      3*R,  -h, 7939.9  , //12
      R,  -h, 7945  , //13
      -R, -h, 7939.9  , //14
      -3*R, -h, 7925  , //15
      -5*R, -h, 7900  , //16
      -7*R, -h, 7865  , //17
      8*R,  0.0,  7865  , //18
      6*R,  0.0,  7900  , //19
      4*R,  0.0,  7925  , //20
      2*R,  0.0,  7939.9  , //21
      0.0,  0.0,  7945  , //22
      -2*R, 0.0,  7939.9  , //23
      -4*R, 0.0,  7925  , //24
      -6*R, 0.0,  7900  , //25
      -8*R, 0.0,  7865  , //26
      9*R,  h,  7865  , //27
      7*R,  h,  7900  , //28
      5*R,  h,  7925  , //29
      3*R,  h,  7939.9  , //30
      R,  h,  7945  , //31
      -R, h,  7939.9  , //32
      -3*R, h,  7925  , //33
      -5*R, h,  7900  , //34
      -7*R, h,  7865  , //35
      8*R,  2*h,  7865  , //36
      6*R,  2*h,  7900  , //37
      4*R,  2*h,  7925  , //38
      2*R,  2*h,  7939.9  , //39
      0.0,  2*h,  7945  , //40
      -2*R, 2*h,  7939.9  , //41
      -4*R, 2*h,  7925  , //42
      -6*R, 2*h,  7900  , //43
      -8*R, 2*h,  7865  , //44   
      };

  /*for (int i_module(0); i_module < 45; i_module++) {                                                                          
        AirBox->AddNode(moduleVol, i_module, new TGeoCombiTrans("module", xyz[i_module][0] / scale, 
                                                                          xyz[i_module][1] / scale, 
                                                                          xyz[i_module][2] / scale - 0.5*(NDZPOZ-r-deltaH), rotNoRot)); //-200 */
    for (int i_module(0); i_module < 45; i_module++) { 
        AirBox->AddNode(moduleVol, i_module, new TGeoCombiTrans("module", xyz[i_module][0] / scale, 
                                                                          xyz[i_module][1] / scale, 
                                                                          xyz[i_module][2] / scale -xyz[22][2]/scale, rotNoRot));  //Растановка датчиков по оси-z относительно датчика в ячейке [22][2]
    } 
  }

  if (SensitiveVolName == "bc404"){

    // Shapes
    TGeoXtru* sixBC404 = createSixPolygon(8.66, 7.5);
    TGeoXtru* sixMylar = createSixPolygon(8.86, 7.6);

    // Volumes
    TGeoVolume* sixBC404Vol = new TGeoVolume("sixBC404Vol", sixBC404, pBC408);
    TGeoVolume* sixMylarVol = new TGeoVolume("sixMylarVol", sixMylar, pMylar);

    // Structure
    // BC404 in mylar
    sixMylarVol->AddNode(sixBC404Vol, 1, new TGeoCombiTrans("mBC404InMylar", 0., 0., 0., rotNoRot));

    Double_t gap = 0.14;            //зазор между шестиугольниками
    Double_t D = 9. + 2*gap;        //диаметр вписанной в шестиугольник окружности, для расчета координат шестиугольников
    
    //Координаты
    D = D*sqrt(3);  //диаметр вписанной в шестиугольник окружности
    Double_t X0 = 0.5*D/sqrt(3);
    Double_t Y0 = 0.5*D;
    Double_t X1 = D/sqrt(3);
    Double_t Y1 = 0;
    Double_t X2 = X0;
    Double_t Y2 = -Y0;
    Double_t X3 = -X2;
    Double_t Y3 = Y2;
    Double_t X4 = -X1;
    Double_t Y4 = Y1;
    Double_t X5 = -X0;
    Double_t Y5 = Y0;

    AirBox->AddNode(sixMylarVol,0, new TGeoCombiTrans("polygon1",X0,Y0,0., rotNoRot));
    AirBox->AddNode(sixMylarVol,1, new TGeoCombiTrans("polygon2",X1,Y1,0., rotNoRot));
    AirBox->AddNode(sixMylarVol,2, new TGeoCombiTrans("polygon3",X2,Y2,0., rotNoRot));
    AirBox->AddNode(sixMylarVol,3, new TGeoCombiTrans("polygon4",X3,Y3,0., rotNoRot));
    AirBox->AddNode(sixMylarVol,4, new TGeoCombiTrans("polygon5",X4,Y4,0., rotNoRot));
    AirBox->AddNode(sixMylarVol,5, new TGeoCombiTrans("polygon5",X5,Y5,0., rotNoRot));
  }
    
  //////////////////////////////////////////////////////////////////////////////////////////////////
  // World ------------------------------------
  TGeoVolumeAssembly* topVolAss = new TGeoVolumeAssembly("TOP");
  // This is the one but last level in the hierarchy
  // This volume-assembly is the only volume to be inserted into TOP
  TGeoVolumeAssembly* ND = new TGeoVolumeAssembly("ND");
  topVolAss->AddNode(ND, 1, new TGeoCombiTrans("AirBox", 0., 0., NDZPOZ, rotNoRot));	//("AirBox", 0., 0., 200., rotNoRot)) /*0.5*(NDZPOZ-r+deltaH)*/
  ND->AddNode(AirBox,1);

  topVolAss->AddNode(targetVol,1, new TGeoCombiTrans("targetVol", 0., 0., 0., rotNoRot));
  topVolAss->AddNode(wallVol,1, new TGeoCombiTrans("wallVol", 0., 0., 40., rotNoRot));

  // Finalize
  geoM->SetTopVolume(topVolAss);
  geoM->CloseGeometry();
  geoM->CheckOverlaps();
  geoM->PrintOverlaps();
  geoM->CheckGeometry();
  geoM->CheckGeometryFull();
  geoM->Test();

  // Export
  TFile* outGeoFileRoot = new TFile(outGeoFilenameRoot, "RECREATE");
  geoM->GetTopVolume()->Write();
  outGeoFileRoot->Close();

  // Draw
  TBrowser* bro = new TBrowser("bro", "bro");
  geoM->GetTopVolume()->Draw("ogl");
}


   
TGeoXtru *createSixPolygon(Double_t d, Double_t thickness){

    //  Функция создания правильных шестиугольников от диаметра вписаной окружности                     
    // Double_t d - диаметр вписанной в шестиугольник окружности;
    // Double_t thickness - толщина по оси Z;

    TGeoXtru* sixPolygon = new TGeoXtru(2);

    // Координаты вершин шестиугольника
    Double_t x0 = 0.;
    Double_t y0 = d/sqrt(3.);
    Double_t x1 = 0.5*d;
    Double_t y1 = 0.5*d/sqrt(3.);
    Double_t x2 = x1;
    Double_t y2 = -y1;
    Double_t x3 = x0;
    Double_t y3 = -y0;
    Double_t x4 = -x1;
    Double_t y4 = y2;
    Double_t x5 = x4;
    Double_t y5 = y1;

    // Массивы по оси X и Y
    Double_t x[6] = {x0, x1, x2, x3, x4, x5};  
    Double_t y[6] = {y0, y1, y2, y3, y4, y5};

      // DefinePolygon()
    // n - число вершин >2
    // xv[n] - массив позиций X вершины
    // yv[n] - массив позиций Y вершины
    sixPolygon->DefinePolygon(6, x,y);

      // DefineSection()
    // 0 -номер секции; 
    // 5(z)-коор. секции;
    // 0(x),0(y)- коор.секции
    // 1. - масштаб секции
    sixPolygon->DefineSection(0, 0., 0., 0., 1.); 
    sixPolygon->DefineSection(1, thickness, 0., 0., 1.);

    return sixPolygon;
}
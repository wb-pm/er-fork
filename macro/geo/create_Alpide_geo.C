#include "TGeoManager.h"
#include "TSystem.h"
#include "TGeoMedium.h"
#include "TROOT.h"
#include "TFile.h"
#include "TGeoCompositeShape.h"

#include "FairGeoLoader.h"
#include "FairGeoInterface.h"
#include "FairGeoMedia.h"
#include "FairGeoMedium.h"
#include "FairGeoBuilder.h"
#include "FairLogger.h"

void create_Alpide_geo()
{
    TGeoManager* gGeoMan = nullptr;

    // -------   Load media from media file   -----------------------------------
    FairGeoLoader* geoLoad = new FairGeoLoader("TGeo", "FairGeoLoader");
    FairGeoInterface* geoFace = geoLoad->getGeoInterface();
    TString geoPath = gSystem->Getenv("VMCWORKDIR");
    TString medFile = geoPath + "/geometry/media.geo";

    geoFace->setMediaFile(medFile);
    geoFace->readMedia();
    gGeoMan = gGeoManager;
    // -----------------   Get and create the required media    -----------------
    FairGeoMedia* geoMedia = geoFace->getMedia();
    FairGeoBuilder* geoBuild = geoLoad->getGeoBuilder();

    FairGeoMedium* silicon = geoMedia->getMedium("silicon");
    if (!silicon) LOG(FATAL) << "create_Alpide_geo.C: FairMedium silicon not found" << FairLogger::endl;
    geoBuild->createMedium(silicon);
    silicon->print();
/*     TGeoMedium* pSi = gGeoMan->GetMedium("silicon");
    if (!pSi) LOG(FATAL) << "create_Alpide_geo.C: Medium silicon not found" << FairLogger::endl; */

    FairGeoMedium* vacuum = geoMedia->getMedium("vacuum");
    if (!vacuum) LOG(FATAL) << "create_Alpide_geo.C: FairMedium vacuum not found" << FairLogger::endl;
    geoBuild->createMedium(vacuum);
    vacuum->print();

    FairGeoMedium* aluminium = geoMedia->getMedium("aluminium");
    if (!aluminium) LOG(FATAL) << "create_Alpide_geo.C: FairMedium aluminium not found" << FairLogger::endl;
    geoBuild->createMedium(aluminium);
    aluminium->print();

    FairGeoMedium* carbon = geoMedia->getMedium("carbon");
    if (!carbon) LOG(FATAL) << "create_Alpide_geo.C: FairMedium carbon not found" << FairLogger::endl;
    geoBuild->createMedium(carbon);

    FairGeoMedium* helium = geoMedia->getMedium("helium");
    if (!helium) LOG(FATAL) << "create_Alpide_geo.C: FairMedium helium not found" << FairLogger::endl;
    geoBuild->createMedium(helium);

    FairGeoMedium* mylar = geoMedia->getMedium("mylar");
    if (!mylar) LOG(FATAL) << "create_Alpide_geo.C: FairMedium mylar not found" << FairLogger::endl;
    geoBuild->createMedium(mylar);
    // --------------------------------------------------------------------------
  //------------------------- VOLUMES -----------------------------------------

  // --------------   Create geometry and top volume  -------------------------
    gGeoMan = (TGeoManager*)gROOT->FindObject("FAIRGeom");
    gGeoMan->SetName("DETgeom");
    TGeoVolume* top = new TGeoVolumeAssembly("TOP");
    gGeoMan->SetTopVolume(top);
    // --------------------------------------------------------------------------

    //------------------ Alpide station -----------------------------------------
    TGeoVolume* Alpide = new TGeoVolumeAssembly("Alpide");
    //Everything in cm

    const Double_t carbonPlateSize = 10.;
    const Double_t carbonPlateThickness = 0.1;

    const Double_t chipThickness = 0.005; // 50 microns
    const Double_t chipGap = 0.001;
    const Double_t chipWidth = (carbonPlateSize - 5 * chipGap) / 6;
    const Double_t chipHeight = (carbonPlateSize - 2 * chipGap) / 3;

    const Double_t pixelWidth = chipWidth / 512.;
    const Double_t pixelHeight = chipHeight / 1024.;
    const Double_t pixelThickness = 0.005;

    const Double_t frameWidth = 1.0;
    const Double_t frameThickness = 0.05;
    
    //------------------ Detector box -----------------------------------------

    const Double_t aluminiumBoxThickness = 0.2;
    const Double_t aluminiumOuterBoxLength = 60.;
    const Double_t aluminiumInnerBoxLength = aluminiumOuterBoxLength-aluminiumBoxThickness;

    TGeoVolume* aluminiumOuterBox = gGeoMan->MakeBox("aluminiumOuterBox",gGeoMan->GetMedium("aluminium"),aluminiumOuterBoxLength/2,aluminiumOuterBoxLength/2,aluminiumOuterBoxLength/2);

    TGeoVolume* aluminiumInnerBox = gGeoMan->MakeBox("aluminiumInnerBox",gGeoMan->GetMedium("helium"),aluminiumInnerBoxLength/2,aluminiumInnerBoxLength/2,aluminiumInnerBoxLength/2);

    TGeoCompositeShape* hollowBox = new TGeoCompositeShape("hollowBox","aluminiumOuterBox-aluminiumInnerBox");
    TGeoVolume* aluminiumBox = new TGeoVolume("aluminiumBox",hollowBox,gGeoMan->GetMedium("aluminium"));
    Alpide->AddNode(aluminiumBox,1,new TGeoTranslation(0,0,15));

    // Carbon plate (10x10 cm, 1 mm thick)
/*     TGeoVolume* carbonPlate = gGeoMan->MakeBox("CarbonPlate", pC, carbonPlateSize / 2, carbonPlateSize / 2, carbonPlateThickness / 2);
    Alpide->AddNode(carbonPlate, 1, new TGeoTranslation(0, 0, 0)); */
    //Silicon plate, for now substituting the planned chips
    TGeoVolume* siliconPlate = gGeoMan->MakeBox("SiliconPlate", gGeoMan->GetMedium("silicon"), carbonPlateSize / 2, carbonPlateSize / 2, chipThickness / 2);
    Alpide->AddNode(siliconPlate, 1, new TGeoTranslation(0, 0, 0));

    //Aluminium frame around the carbon plate (1 cm wide, 0.5 mm thick)
    TGeoVolume* aluminiumFrameLeft = gGeoMan->MakeBox("AlFrameL", gGeoMan->GetMedium("aluminium"), frameWidth / 2, carbonPlateSize / 2, frameThickness / 2);
    TGeoVolume* aluminiumFrameRight = gGeoMan->MakeBox("AlFrameR", gGeoMan->GetMedium("aluminium"), frameWidth / 2, carbonPlateSize / 2, frameThickness / 2);
    TGeoVolume* aluminiumFrameTop = gGeoMan->MakeBox("AlFrameT", gGeoMan->GetMedium("aluminium"), carbonPlateSize / 2, frameWidth / 2, frameThickness / 2);
    TGeoVolume* aluminiumFrameBottom = gGeoMan->MakeBox("AlFrameB", gGeoMan->GetMedium("aluminium"), carbonPlateSize / 2, frameWidth / 2, frameThickness / 2);

    // Add frames to the world, positioning them around the carbon plate
    Alpide->AddNode(aluminiumFrameLeft, 1, new TGeoTranslation(-(carbonPlateSize / 2 + frameWidth / 2), 0, 0));
    Alpide->AddNode(aluminiumFrameRight, 1, new TGeoTranslation(carbonPlateSize / 2 + frameWidth / 2, 0, 0));
    Alpide->AddNode(aluminiumFrameTop, 1, new TGeoTranslation(0, -(carbonPlateSize / 2 + frameWidth / 2), 0));
    Alpide->AddNode(aluminiumFrameBottom, 1, new TGeoTranslation(0, carbonPlateSize / 2 + frameWidth / 2, 0));
    // Create a chip (30x90 mm², 100 µm thick)
    //Should place 18 chips on a plate
    Int_t chipID = 0;
/*     const Int_t pxRowTotal = 2;
    const Int_t pxColTotal = 2; */
/*     for (Int_t row = 0; row < 3; ++row) {
        for (Int_t col = 0; col < 6; ++col) {
            TString chipTitle;
            TGeoVolume* chip = gGeoMan->MakeBox("chip", pSi, chipWidth / 2, chipHeight / 2, chipThickness / 2);
            Double_t xPos = -carbonPlateSize / 2 + chipWidth / 2 + col * (chipWidth + chipGap);
            Double_t yPos = -carbonPlateSize / 2 + chipHeight / 2 + row * (chipHeight + chipGap);
            Alpide->AddNode(chip, chipID++, new TGeoTranslation(xPos, yPos, carbonPlateThickness / 2 + chipThickness / 2)); */
            //Have tried to implement pixels as separate volumes, this approach is bad, because the amount of pixels is too large
/*             for (Int_t pxRow = 0; pxRow < pxRowTotal; ++pxRow) {
                for (Int_t pxCol = 0; pxCol < pxColTotal; ++pxCol){
                    Double_t pxPosX = xPos - chipWidth/2 + pixelWidth/2+pxCol*pixelWidth;
                    Double_t pxPosY = yPos - chipHeight/2 + pixelHeight/2 +pxRow*pixelHeight;
                    TString pixelTitle;
                    pixelTitle.Form("pixel%d",pxCol + pxRow*pxColTotal);
                    TGeoVolume* pixel = gGeoMan->MakeBox(pixelTitle.Data(),pSi,pixelWidth /2,pixelHeight/2,pixelThickness/2);
                    Alpide->AddNode(pixel,chipID*pxRowTotal*pxColTotal + pxRow*pxColTotal+pxCol,new TGeoTranslation(pxPosX,pxPosY,carbonPlateThickness/2+chipThickness/2 + pixelThickness/2));
                }
            } */
/*         }
    } */
    top->AddNode(Alpide, 0, new TGeoTranslation(0., 0., 6.8));
    // ---------------   Finish   -----------------------------------------------
    gGeoMan->CloseGeometry();
    gGeoMan->CheckOverlaps(0.001);
    gGeoMan->PrintOverlaps();
    gGeoMan->Test();
    top->Draw();

    // ---------------   Create geometry file   ---------------------------------
    TString geoFileName = geoPath + "/geometry/Alpide_nochips_box.geo.root";
    //TString geoFileName = geoPath + "/geometry/Alpide_pixels.geo.root";
    TFile* geoFile = new TFile(geoFileName, "RECREATE");
    top->Write();
    geoFile->Close();
    // --------------------------------------------------------------------------
}
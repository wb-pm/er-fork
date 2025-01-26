
#include "TString.h"
#include "TSystem.h"
#include "TGeoManager.h"
#include "TGDMLParse.h"
#include "TGeoVolume.h"
#include "TFile.h"

void Import_GDML_Export_ROOT()
{
	TGeoManager *gdml = new TGeoManager("gdml", "FAIRGeom");

	TGDMLParse parser;
	// Define your input GDML file HERE
	TString gdmlName = "gadast_single_crystal_large";
	TGeoVolume* gdmlTop = parser.GDMLReadFile (gdmlName + ".gdml");
	std::cout << "GDML file " << gdmlName + ".gdml" << " has been parsed" << std::endl;
	TGeoVolume* rootTop = new TGeoVolumeAssembly("TOP");

	gGeoManager->SetTopVolume(gdmlTop);

  
	// Define your position HERE
	TGeoRotation* rot = new TGeoRotation ("rot", 0., 0., 0.);
	TGeoCombiTrans* posrot = new TGeoCombiTrans (0., 0., 0., rot);

	rootTop->AddNode (gdmlTop, 1, posrot);

	gGeoManager->CloseGeometry();

	// Define you output ROOT file HERE
	TFile* outfile = new TFile(gdmlName + ".root", "RECREATE");
	rootTop->Write();
	std::cout << "ROOT file " << gdmlName + ".root" << " has been created" << std::endl;
	//outfile->Close();
  
}


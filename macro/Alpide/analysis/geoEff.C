#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TCanvas.h"
//A small script for calculating the geometrical efficiency of the C7 experiment setup
/* const Double_t fromTargetToAlpide =  // cm
const Double_t fromAlpideToFirstFOOT = 12// cm
const Double_t betweenFOOTPairs // cm */
const Double_t distanceZ = 55.;
void drawRectangle(TCanvas* canvasForDraw);
void geoEff()
{
    TFile* fileEventHeader = new TFile("../sim/sim_UniformDecayerTest_Alpide_3foot_ranges1000mm.root"); 
    TTree* treeEventHeader = (TTree*)fileEventHeader->Get("er");
    ;
    TCanvas* cGeoEff = new TCanvas("GeoEff","GeoEff");
    treeEventHeader->SetAlias("reactionX","MCEventHeader.ERDecayMCEventHeader.fReactionPos.X()");
    treeEventHeader->SetAlias("reactionZ","MCEventHeader.ERDecayMCEventHeader.fReactionPos.Z()");
    treeEventHeader->SetAlias("reactionY","MCEventHeader.ERDecayMCEventHeader.fReactionPos.Y()");
    treeEventHeader->SetAlias("p1Px","MCEventHeader.fp1.Px()");
    treeEventHeader->SetAlias("p1Py","MCEventHeader.fp1.Py()");
    treeEventHeader->SetAlias("p1Pz","MCEventHeader.fp1.Pz()");
    TString momentumProjection = Form("reactionX + (%f - reactionZ)*(p1Px/p1Pz):reactionY + (%f - reactionZ)*(p1Py/p1Pz)",distanceZ,distanceZ);
   //treeEventHeader->Draw("x_reaction1","","");
   treeEventHeader->Draw(momentumProjection,"","colz");
    drawRectangle(cGeoEff);
}

void drawRectangle(TCanvas* canvasToDraw){
canvasToDraw->cd();
TLine *line1 = new TLine(-10, -10, 10, -10);
TLine *line2 = new TLine(10, -10, 10, 10);
TLine *line3 = new TLine(10, 10, -10, 10);
TLine *line4 = new TLine(-10, 10, -10, -10);

// Set line attributes (optional)
line1->SetLineColor(kRed);
line2->SetLineColor(kRed);
line3->SetLineColor(kRed);
line4->SetLineColor(kRed);

// Draw lines
line1->Draw();
line2->Draw();
line3->Draw();
line4->Draw();
}
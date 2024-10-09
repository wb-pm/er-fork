#include "TTree.h"
#include "TFile.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TH2D.h"
#include "TPaletteAxis.h"

void simRecoComparison(TTree* reco_tree);
TString eventSelection = "";

void draw()
{
    TFile* threeProtons = new TFile("../digi/digi_TestTracks_Alpide_3foot_ranges1000mm.root");
    TTree* tree_threeProtons = (TTree*)threeProtons->Get("er");
    simRecoComparison(tree_threeProtons);
}

void simRecoComparison(TTree* reco_tree)
{
    //gStyle->SetOptStat(0);
    TCanvas *canvas = new TCanvas();
    canvas->Divide(3,2,0.005,0.005);
    canvas->cd(1);
    reco_tree->Draw("FootMuSiVertex.fX:MCEventHeader.ERDecayMCEventHeader.fReactionPos.fX>>hX",eventSelection,"colz");
    TH2D *hX = (TH2D*)gPad->GetPrimitive("hX");
    gPad->SetBottomMargin(0.15);
    hX->GetXaxis()->SetTitle("X_{decay}, cm");
    hX->GetXaxis()->SetTitleSize(0.07);
    hX->GetYaxis()->SetTitle("X_{vertex}, cm");
    hX->GetYaxis()->SetTitleSize(0.07);
    hX->GetYaxis()->SetTitleOffset(.72);
    hX->GetZaxis()->SetTitle("Counts");
    hX->GetYaxis()->SetTitleSize(0.06);
    hX->GetZaxis()->SetTitleOffset(0.);
    hX->SetTitle("");
    gPad->Update();
    TPaletteAxis* paletteX = (TPaletteAxis*)hX->GetListOfFunctions()->FindObject("palette");
    paletteX->SetX1NDC(0.86);
    paletteX->SetX2NDC(0.9);
    canvas->cd(2);
    reco_tree->Draw("FootMuSiVertex.fY:MCEventHeader.ERDecayMCEventHeader.fReactionPos.fY>>hY",eventSelection,"colz");
    TH2D *hY = (TH2D*)gPad->GetPrimitive("hY");
    gPad->SetBottomMargin(0.15);
    hY->GetXaxis()->SetTitle("Y_{decay}, cm");
    hY->GetXaxis()->SetTitleSize(0.07);
    hY->GetYaxis()->SetTitle("Y_{vertex}, cm");
    hY->GetXaxis()->SetTitleSize(0.07);
    hY->GetYaxis()->SetTitleOffset(.72);
    hY->GetZaxis()->SetTitle("Counts");
    hY->GetYaxis()->SetTitleSize(0.06);
    hY->GetZaxis()->SetTitleOffset(0.);
    hY->SetTitle("");
    gPad->Update();
    TPaletteAxis* paletteY = (TPaletteAxis*)hY->GetListOfFunctions()->FindObject("palette");
    paletteY->SetX1NDC(0.86);
    paletteY->SetX2NDC(0.9);
    canvas->cd(3);
    reco_tree->Draw("FootMuSiVertex.fZ:MCEventHeader.ERDecayMCEventHeader.fReactionPos.fZ>>hZ",eventSelection,"colz");
    TH2D *hZ = (TH2D*)gPad->GetPrimitive("hZ");
    gPad->SetBottomMargin(0.15);
    hZ->GetXaxis()->SetTitle("Z_{decay}, cm");
    hZ->GetXaxis()->SetTitleSize(0.07);
        hZ->GetYaxis()->SetTitle("Z_{vertex}, cm");
    hZ->GetXaxis()->SetTitleSize(0.07);
    hZ->GetYaxis()->SetTitleOffset(.72);
    hZ->GetZaxis()->SetTitle("Counts");
    hZ->GetYaxis()->SetTitleSize(0.06);
    hZ->GetZaxis()->SetTitleOffset(0.);
    hZ->SetTitle("");
    gPad->Update();
    TPaletteAxis* paletteZ = (TPaletteAxis*)hZ->GetListOfFunctions()->FindObject("palette");
    paletteZ->SetX1NDC(0.86);
    paletteZ->SetX2NDC(0.9);
    canvas->cd(4);
    reco_tree->Draw("FootMuSiVertex.fX - MCEventHeader.ERDecayMCEventHeader.fReactionPos.fX>>hDifX",eventSelection,"");
    TH2D *hDifX = (TH2D*)gPad->GetPrimitive("hDifX");
    gPad->SetBottomMargin(0.15);
    hDifX->GetXaxis()->SetTitle("X_{vertex} - X_{decay}, cm");
    hDifX->GetXaxis()->SetTitleSize(0.07);
    hDifX->GetYaxis()->SetTitle("Counts");
    hDifX->GetYaxis()->SetTitleOffset(0.87);
    hDifX->GetYaxis()->SetTitleSize(0.06);
    hDifX->SetTitle("");
    canvas->cd(5);
    reco_tree->Draw("FootMuSiVertex.fY - MCEventHeader.ERDecayMCEventHeader.fReactionPos.fY>>hDifY",eventSelection,"");
    TH2D *hDifY = (TH2D*)gPad->GetPrimitive("hDifY");
    gPad->SetBottomMargin(0.15);
    hDifY->GetXaxis()->SetTitle("Y_{vertex} - Y_{decay}, cm");
    hDifY->GetXaxis()->SetTitleSize(0.07);
    hDifY->GetYaxis()->SetTitle("Counts");
    hDifY->GetYaxis()->SetTitleOffset(0.87);
    hDifY->GetYaxis()->SetTitleSize(0.06);
    hDifY->SetTitle("");
    canvas->cd(6);
    reco_tree->Draw("FootMuSiVertex.fZ - MCEventHeader.ERDecayMCEventHeader.fReactionPos.fZ>>hDifZ",eventSelection,"");
    TH2D *hDifZ = (TH2D*)gPad->GetPrimitive("hDifZ");
    gPad->SetBottomMargin(0.15);
    hDifZ->GetXaxis()->SetTitle("Z_{vertex} - Z_{decay}, cm");
    hDifZ->GetXaxis()->SetTitleSize(0.07);
    hDifZ->GetYaxis()->SetTitle("Counts");
    hDifZ->GetYaxis()->SetTitleOffset(0.87);
    hDifZ->GetYaxis()->SetTitleSize(0.06);
    hDifZ->SetTitle("");
/*     canvas->cd(3);
    sim_tree->Draw("MCEventHeader.ERDecayMCEventHeader.fReactionPos.fZ",eventSelection,"");
    canvas->cd(4);
    reco_tree->Draw("FootMuSiVertex.fZ",eventSelection,""); */

}
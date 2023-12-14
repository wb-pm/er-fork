#include <iostream>

#include "TFile.h"

#include "TTree.h"
#include "TH1F.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TCut.h"

#include "C9_Sim_Digi_Tree_Structure.h"
#include "C9_Reco_Tree_Structure.h"

void reconstructTrack(TTree* reco_tree);
void showChannels(TTree* reco_tree);
void energyDepositions(TTree* edep_tree);
TCut eventSelection = "Entry$ == 46";

void MakeClassAnalysis()
{
    TFile *input_root_decay_1mm = new TFile("../output/reco_twoprotons_decay_helium_1mm_10000events_mult_assembly.root", "READ");
    TTree *input_tree_decay_1mm = (TTree*)input_root_decay_1mm->Get("er");
    TCanvas *c1 = new TCanvas();
    c1->Divide(2,2);
    c1->cd(1);
    input_tree_decay_1mm->Draw("TelescopeTrack_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.GetDirection().Theta()*TMath::RadToDeg()","");
    c1->cd(2);
    input_tree_decay_1mm->Draw("TelescopeTrack_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.GetDirection().Theta()*TMath::RadToDeg()","");
    c1->cd(3);
    input_tree_decay_1mm->Draw("TelescopeTrack_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.GetDirection().Theta()*TMath::RadToDeg()","");
/*     TFile *input_root_decay_0p001mm = new TFile("../output/test_decay_e_range0p001mm.root", "READ");
    TTree *input_tree_decay_0p001mm = (TTree*)input_root_decay_0p001mm->Get("er"); */

/*     C9_Tree_Structure* analysis_class = new C9_Tree_Structure(input_tree);
    analysis_class->Loop(); */
    //reconstructTrack(input_tree);
    //showChannels(input_tree);
    //input_tree_decay->Scan("TelescopeDigi_Telescope_C9_SingleSi_SSD150_1_X.fChannel");
    //energyDepositions(input_tree_decay);
/*     energyDepositions(input_tree_decay_0p01mm_oneproton);
    TCanvas *c2 = new TCanvas();
    c2->Divide(3,1);
    c2->cd(1);
    input_tree_decay->SetMarkerColor(kRed);
    input_tree_decay->SetMarkerStyle(20);
    input_tree_decay->SetMarkerSize(2.);
    input_tree_decay->Draw("TelescopeDigi_Telescope_C9_SingleSi_SSD150_1_X.fChannel:TelescopeDigi_Telescope_C9_SingleSi_SSD150_2_Y.fChannel",eventSelection);
c2->cd(2);
    input_tree_decay->Draw("TelescopeDigi_Telescope_C9_SingleSi_SSD150_3_X.fChannel:TelescopeDigi_Telescope_C9_SingleSi_SSD150_4_Y.fChannel",eventSelection,"");
    c2->cd(3);
    input_tree_decay->Draw("TelescopeDigi_Telescope_C9_SingleSi_SSD150_5_X.fChannel:TelescopeDigi_Telescope_C9_SingleSi_SSD150_6_Y.fChannel",eventSelection,""); */


    //input_tree->Draw(">>nonZeroEntries","TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fXChannel != 0","entrylist");
}

void reconstructTrack(TTree* reco_tree){
    TCanvas *canvas = new TCanvas();
    canvas->Divide(3,2);
    canvas->cd(1);
    reco_tree->Draw("TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fXStationVertex.fX:TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fYStationVertex.fY",eventSelection,"colz");
    //TH1F *histogram = (TH1F*)gPad->GetPrimitive("hHits");
    canvas->cd(2);
    reco_tree->Draw("","","colz");
    canvas->cd(3);
    reco_tree->Draw("TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fXStationVertex.fX:TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fYStationVertex.fY",eventSelection,"colz");
    canvas->cd(4);
    reco_tree->Draw("(TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fXStationVertex.fX-TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fXStationVertex.fX):(TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fXStationVertex.fZ-TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fXStationVertex.fZ)",eventSelection,"colz");

}

void showChannels(TTree* reco_tree)
{
    TCanvas *canvas = new TCanvas();
    canvas->Divide(3,2);
    canvas->cd(1);
    reco_tree->Draw("TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fXChannel:TelescopeTrack_Telescope_C9_SingleSi_SSD150_1_XTelescope_C9_SingleSi_SSD150_2_Y.fYChannel",eventSelection,"colz");
    canvas->cd(2);
    reco_tree->Draw("TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fXChannel:TelescopeTrack_Telescope_C9_SingleSi_SSD150_3_XTelescope_C9_SingleSi_SSD150_4_Y.fYChannel",eventSelection,"colz");
    canvas->cd(3);
    reco_tree->Draw("TelescopeTrack_Telescope_C9_SingleSi_SSD150_5_XTelescope_C9_SingleSi_SSD150_6_Y.fXChannel:TelescopeTrack_Telescope_C9_SingleSi_SSD150_5_XTelescope_C9_SingleSi_SSD150_6_Y.fYChannel",eventSelection,"colz");
}

void energyDepositions(TTree* edep_tree)
{
    TCanvas *c1 = new TCanvas();
    c1->Divide(2,1);
    c1->cd(1);
    edep_tree->Draw("TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fELoss>>hElectrons","TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fPID == 11","");
    TH1F *hElectrons = (TH1F*)gPad->GetPrimitive("hElectrons");
    hElectrons->SetLineColor(kRed);
    edep_tree->Draw("TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fELoss>>hProtons","TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fPID == 2212","same");
    TH1F *hProtons = (TH1F*)gPad->GetPrimitive("hProtons");
    hProtons->SetLineColor(kGreen);
    edep_tree->Draw("TelescopeDigi_Telescope_C9_SingleSi_SSD150_1_X.fEdep","","same");
    c1->cd(2);
    edep_tree->Draw("TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fELoss","TelescopePoint_Telescope_C9_SingleSi_SSD150_1_X.fPID == 1000020030","");
}
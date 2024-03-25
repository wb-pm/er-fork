#include <iostream>

#include "TFile.h"
#include "TROOT.h"
#include "TTree.h"
#include "TH1F.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TCut.h"
#include "TF1.h"
#include "TMath.h"
#include "TH2D.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TPaletteAxis.h"

#include "FootMuSi_C7_SimDigi_Tree_Structure.h"
#include "FootMuSi_C7_Reco_Tree_Structure.h"


void simInfo(TTree* sim_tree);
void reconstructTrack(TTree* reco_tree);
void showChannels(TTree* reco_tree);
void energyDepositions(TTree* edep_tree);
void singleEvent(TTree* singleEventTree);
void scatteringAnglesSim(TTree* sim_tree);
void simRecoComparison(TTree* sim_tree, TTree* reco_tree);
//TCut eventSelection = "fabs(MCEventHeader.ERDecayMCEventHeader.fReactionPos.fX) > 1 && fabs(MCEventHeader.ERDecayMCEventHeader.fReactionPos.fY) > 1 && fabs(FootMuSiVertex.fX) > 1 && fabs(FootMuSiVertex.fY) > 1";
TCut eventSelection = "";
TF1* multipleScattering();

void MakeClassAnalysis()
{
    TFile *input_root_twoprotons = new TFile("../outputFootMuSi/spread_beam_tracks_into_single_branch_twoprotons_100mm_cuts.root", "READ");
    TTree *input_tree_twoprotons = (TTree*)input_root_twoprotons->Get("er");
    //TFile *input_root_reco_twoprotons = new TFile("../outputFootMuSi/reco__fit_hits_smallanglecut_inmomentum_comparison_anglecondition_spread_beam_tracks_into_single_branch_twoprotons.root", "READ");
    TFile *input_root_reco_twoprotons = new TFile("../outputFootMuSi/reco__fit_hits_smallanglecut_inmomentum_comparison_anglecondition_spread_beam_tracks_into_single_branch_twoprotons.root", "READ");
    TTree *input_tree_reco_twoprotons = (TTree*)input_root_reco_twoprotons->Get("er");
/*     simInfo(input_tree_twoprotons); */
simRecoComparison(input_tree_twoprotons,input_tree_reco_twoprotons);
/*     reconstructTrack(input_tree_reco_twoprotons); 
    scatteringAnglesSim(input_tree_twoprotons); */
/*     energyDepositions(input_tree_twoprotons);
    singleEvent(input_tree_reco_twoprotons); */

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

void simRecoComparison(TTree* sim_tree, TTree* reco_tree)
{
    TGaxis::SetMaxDigits(4);
    gStyle->SetOptStat(0);
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

void scatteringAnglesSim(TTree* sim_tree)
{
    TCanvas *canvas = new TCanvas();
    canvas->Divide(1,2);
    canvas->cd(1);
/*     sim_tree->Draw("TMath::ACos((FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out)/(TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz)*TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out)))>>hMultScatProjected(400,-10e-3,10e-3)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212",""); */
TString argMultScat = "(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out)/(TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz)*TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out))";
    sim_tree->Draw("TMath::ACos((FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out)/(TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz)*TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPz_out)))>>hMultScatProjected(400,-10e-3,10e-3)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212","");
    TH1D* hMultScatProjected = (TH1D*)gPad->GetPrimitive("hMultScatProjected");
    TF1* scatteringFunction = multipleScattering();
    hMultScatProjected->Scale(scatteringFunction->GetMaximum()/hMultScatProjected->GetMaximum(),"nosw2");
    scatteringFunction->Draw("same");
    canvas->cd(2);
/*     sim_tree->Draw("TMath::ACos((FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out)/(TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz)*TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out)))>>hMultScatProjected2(400,-10e-3,10e-3)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPID == 2212",""); */
    sim_tree->Draw("TMath::ACos((FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out)/(TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz)*TMath::Sqrt(FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPx_out+FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out*FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPz_out)))>>hMultScatProjected2(400,-10e-3,10e-3)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y.fPID == 2212","");
    TH1D* hMultScatProjected2 = (TH1D*)gPad->GetPrimitive("hMultScatProjected2");
    hMultScatProjected2->Scale(scatteringFunction->GetMaximum()/hMultScatProjected2->GetMaximum(),"nosw2");
    scatteringFunction->Draw("same");
/*     sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_2_Y"); */
}

void reconstructTrack(TTree* reco_tree){
    TCanvas *canvas = new TCanvas();
    canvas->Divide(1,2);
/*     canvas->cd(1);
    reco_tree->Draw("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXChannel:FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYChannel",eventSelection,"lego");
    canvas->cd(2);
    reco_tree->Draw("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXChannel:FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYChannel",eventSelection,"lego");
    canvas->cd(3);
    reco_tree->Draw("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXChannel:FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYChannel",eventSelection,"lego");
    canvas->cd(4);
    reco_tree->Draw("FootMuSiTrack[0].fFirstHit.fX",eventSelection,"");
    canvas->cd(5);
    reco_tree->Draw("FootMuSiTrack[0].fFirstHit.fY", eventSelection, "");
    canvas->cd(6);
    reco_tree->Draw("FootMuSiTrack[0].fFirstHit.fZ", eventSelection, ""); */
    canvas->cd(1);
    TF1* scatteringFunction = multipleScattering();
    reco_tree->Draw("TMath::ACos((FootMuSiTrack.fSecondHit.fX*FootMuSiTrack.fFirstHit.fX + FootMuSiTrack.fSecondHit.fY*FootMuSiTrack.fFirstHit.fY + FootMuSiTrack.fSecondHit.fZ*FootMuSiTrack.fFirstHit.fZ)/(FootMuSiTrack.fFirstHit.Mag()*FootMuSiTrack.fSecondHit.Mag()))>>hMultScat(400,0.,0.005)", "@FootMuSiTrack.size() == 4", "");
    TH1F* hMultScat = (TH1F*)gPad->GetPrimitive("hMultScat");
    hMultScat->Scale(scatteringFunction->GetMaximum()/hMultScat->GetMaximum(),"nosw2");
    scatteringFunction->Draw("same");
    canvas->cd(2);
    reco_tree->Draw("TMath::ACos((FootMuSiTrack.fThirdHit.fX*FootMuSiTrack.fSecondHit.fX + FootMuSiTrack.fThirdHit.fY*FootMuSiTrack.fSecondHit.fY + FootMuSiTrack.fThirdHit.fZ*FootMuSiTrack.fSecondHit.fZ)/(FootMuSiTrack.fSecondHit.Mag()*FootMuSiTrack.fThirdHit.Mag()))>>hMultScat2(400,0.,0.005)","@FootMuSiTrack.size() == 4","");
    TH1F* hMultScat2 = (TH1F*)gPad->GetPrimitive("hMultScat2");
    hMultScat2->Scale(scatteringFunction->GetMaximum()/hMultScat2->GetMaximum(),"nosw2");
    scatteringFunction->Draw("same");

/*     reco_tree->Draw("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationHit.fX:FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYStationHit.fY","","colz");
    canvas->cd(4);
    reco_tree->Draw("(FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationHit.fX-FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationHit.fX):(FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXStationHit.fZ-FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationHit.fZ)","","colz"); */

}

/* void recoSimCombined(TTree* sim_tree, TTree* ) */

void simInfo(TTree* sim_tree)
{
    TCanvas *canvas = new TCanvas();
    canvas->Divide(5,2);
    canvas->cd(1);
    sim_tree->Draw("MCEventHeader.fp1.Z()",eventSelection,"");
    canvas->cd(2);
    sim_tree->Draw("MCEventHeader.fp2.Z()",eventSelection,"");
    canvas->cd(3);
    sim_tree->Draw("MCTrack.fID","MCTrack.fPdgCode == 2212","");
    canvas->cd(4);
    sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTrackID",eventSelection,"");
    canvas->cd(5);
    sim_tree->Draw("MCTrack.fPdgCode",eventSelection,"");
    canvas->cd(6);
    sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID",eventSelection,"");
    canvas->cd(7);
    sim_tree->Draw("MCTrack.fPz",eventSelection && "MCTrack.fPdgCode == 2212","");
    canvas->cd(8);
    sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fMot0TrackID",eventSelection,"");
    canvas->cd(9);
    sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fUniqueID","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212","");
    canvas->cd(10);
    sim_tree->Draw("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fUniqueID","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212","");
/*     sim_tree->Draw("MCTrack.fStartX",eventSelection && "MCTrack.fPdgCode == 2212","");
    canvas->cd(2);
    sim_tree->Draw("MCTrack.fStartY",eventSelection && "MCTrack.fPdgCode == 2212","");
    canvas->cd(3);
    sim_tree->Draw("MCTrack.fStartZ",eventSelection && "MCTrack.fPdgCode == 2212","");
    canvas->cd(4);
    sim_tree->Draw("MCTrack.fPx",eventSelection && "MCTrack.fPdgCode == 2212" && "MCTrack.fID == 2","");
    canvas->cd(5);
    sim_tree->Draw("MCTrack.fPy",eventSelection && "MCTrack.fPdgCode == 2212" && "MCTrack.fID == 2","");
    canvas->cd(6);
    sim_tree->Draw("MCTrack.fPz",eventSelection && "MCTrack.fPdgCode == 2212" && "MCTrack.fID == 2","");
    canvas->cd(7);
    sim_tree->Draw("MCTrack.fID",eventSelection && "MCTrack.fPdgCode == 2212");
    canvas->cd(8);
    sim_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fTrackID",eventSelection); */
}

void showChannels(TTree* reco_tree)
{
    TCanvas *canvas = new TCanvas();
    canvas->Divide(3,2);
    canvas->cd(1);
    reco_tree->Draw("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXChannel:FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fYChannel",eventSelection,"colz");
    canvas->cd(2);
    reco_tree->Draw("FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fXChannel:FootMuSiHit_C7_second_pair_SingleSi_SSD150_3_XC7_second_pair_SingleSi_SSD150_4_Y.fYChannel",eventSelection,"colz");
    canvas->cd(3);
    reco_tree->Draw("FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fXChannel:FootMuSiHit_C7_third_pair_SingleSi_SSD150_5_XC7_third_pair_SingleSi_SSD150_6_Y.fYChannel",eventSelection,"colz");
}

void energyDepositions(TTree* edep_tree)
{
    TCanvas *c1 = new TCanvas();
    c1->Divide(3,2);
    c1->cd(1);
    edep_tree->Draw("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fEdep","","");
/*     edep_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fELoss>>hElectrons","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 11"&&eventSelection,"same");
    TH1F *hElectrons = (TH1F*)gPad->GetPrimitive("hElectrons");
    hElectrons->SetLineColor(kRed);
    edep_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fELoss>>hProtons","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212"&&eventSelection,"same");
    TH1F *hProtons = (TH1F*)gPad->GetPrimitive("hProtons");
    hProtons->SetLineColor(kGreen); */
    c1->cd(2);
    edep_tree->Draw("FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fELoss","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 1000030060","");
    c1->cd(3);
    edep_tree->Draw("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fEdep>>hProtons(400,0.,0.5)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 2212","");
    c1->cd(4);
    edep_tree->Draw("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fEdep>>hNotProtons(400,0.,0.5)","FootMuSiPoint_C7_first_pair_SingleSi_SSD150_1_X.fPID == 11","");
     c1->cd(5);
    edep_tree->Draw("FootMuSiDigi_C7_first_pair_SingleSi_SSD150_1_X.fChannel","","");
}

void singleEvent(TTree* singleEventTree)
{
    TCanvas *c1 = new TCanvas();
    c1->Divide(3,2);
    c1->cd(1);
    singleEventTree->Draw("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXEdep",eventSelection,"");
    c1->cd(2);
    singleEventTree->Draw("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXChannel",eventSelection,"");
    c1->cd(3);
    singleEventTree->Draw("FootMuSiHit_C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y.fXStationHit.X()",eventSelection,"");
    c1->cd(4);
    singleEventTree->Draw("FootMuSiTrack.fFirstHit.fX:FootMuSiTrack.fFirstHit.fY",eventSelection,"colz");
    c1->cd(5);
    singleEventTree->Draw("FootMuSiTrack.fSecondHit.fX:FootMuSiTrack.fSecondHit.fY",eventSelection,"colz");
    c1->cd(6);
    singleEventTree->Draw("FootMuSiTrack.fThirdHit.fX:FootMuSiTrack.fThirdHit.fY",eventSelection,"colz");
}

TF1* multipleScattering()
{
    double p_x = 0.003631*1000;// MeV/c
    double p_y = 0.03567*1000;// MeV/c
    double p_z = 1.215*1000;// MeV/c
    double m = 938.259; // MeV/c^2
    double p = sqrt(p_x*p_x + p_y*p_y + p_z*p_z); // MeV/c
    double u = sqrt(p*p/(m*m+p*p)); // *c
    const double coefMeV = 13.6; //MeV
    int z = 1;
    double x = 0.015; //cm
    double X_0 = 9.45; //cm
    double theta_0 = (coefMeV*z*sqrt(x/X_0)*(1+0.038*log(x/X_0)))/(p*u);
/*     TCanvas* c1 = new TCanvas(); */
    TF1* angle_distribution = new TF1("angle_distribution", "gaus",-10e-3,10e-3);
    angle_distribution->SetParameter(0,1/(TMath::Sqrt(2*TMath::Pi()*theta_0*theta_0)));
    angle_distribution->SetParameter(1, 0.);
    angle_distribution->SetParameter(2,theta_0);
/*     angle_distribution->Draw(); */
    std::cout << angle_distribution->GetParameter(0) << std::endl;
    std::cout << angle_distribution->GetParameter(2) << std::endl;
    return angle_distribution;
}
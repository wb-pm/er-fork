
#if !defined(__CLING__)

#include "TTree.h"
#include "TFile.h"
#include "TRatioPlot.h"

#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TH1F.h"
#include "TCut.h"

#include "TParameter.h"
#endif
std::array<TFile*, 25> fr1;
std::array<TTree*, 25> tr1;
void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth = 2);
void DrawTree()
{
	TString simulation_filename = "../output/sim_thintarget.root";
    OpenTree(1, simulation_filename, kGreen);
    //tr1[1]->Draw("MCEventHeader.fHe3.E()+MCEventHeader.fp1.E()+MCEventHeader.fp2.E()+MCEventHeader.fp3.E()+MCEventHeader.fp4.E()");
    TCanvas *canvas_1 = new TCanvas();
    canvas_1->Divide(2,2);
    canvas_1->cd(1);
    tr1[1]->Draw("sqrt(MCEventHeader.fC7.E()*MCEventHeader.fC7.E()-MCEventHeader.fC7.P()*MCEventHeader.fC7.P())*1000.","sqrt(MCEventHeader.fC7.E()*MCEventHeader.fC7.E()-MCEventHeader.fC7.P()*MCEventHeader.fC7.P())*1000. > 0.");
    canvas_1->cd(2);
    tr1[1]->Draw("sqrt(MCEventHeader.fC9.E()*MCEventHeader.fC9.E()-MCEventHeader.fC9.P()*MCEventHeader.fC9.P())*1000.","sqrt(MCEventHeader.fC9.E()*MCEventHeader.fC9.E()-MCEventHeader.fC9.P()*MCEventHeader.fC9.P())*1000. > 0.");
}

void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth)
{
	
	fr1[treeID] = new TFile(filename, "READ");
	tr1[treeID] = (TTree*)fr1[treeID]->Get("er");
	tr1[treeID]->SetLineColor(color);
	tr1[treeID]->SetLineWidth(lineWidth);
	
}	
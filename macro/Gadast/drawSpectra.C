//Drawing and comparing spectra from ROOT files
#include <iostream>
#include <array>

#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

std::array<TFile*, 25> fr1;
std::array<TTree*, 25> tr1;
std::array<TH1D*, 25> h1;
TH1D *histExp;
TH1D *histExpCs;
TH1D *histExpCo;
void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth = 2);
void DrawingSimExp(Int_t treeID, TString filename, TH1D* histExperment);
void DrawingTwoSimOneExp(Int_t treeID1,Int_t treeID2, TString filename);

void drawSpectra()
{ 
	gROOT->SetStyle("Pub");
	gStyle->SetOptTitle(kTRUE);
	TCanvas* c1 = new TCanvas();
	TFile *frExp = new TFile("ROOT_Files/sub_back_877.root", "READ");
	histExp = (TH1D*)frExp->Get("Subtracted_Background_Energy");
	TFile *frExpCs = new TFile("ROOT_Files/sub_back_877cs.root", "READ");
	histExpCs = (TH1D*)frExpCs->Get("Subtracted_Background_Energy");
	TFile *frExpCo = new TFile("ROOT_Files/sub_back_877co.root", "READ");
	histExpCo = (TH1D*)frExpCo->Get("Subtracted_Background_Energy");	
	//TFile *frExp = new TFile("ROOT_Files/887_st.root", "READ");
	//histExp = (TH1D*)frExp->Get("Calibrated Fitting");	
	//auto *hExpClear = new TH1D(*histExp);
	//hExpClear->Rebin(8);
	histExp->Rebin(8);
	histExpCs->Rebin(8);
	histExpCo->Rebin(8);
	histExpCs->SetLineColor(kRed);
	histExpCo->SetLineColor(kGreen);
	/*TF1 *funct = new TF1("name","1",0,4000);
	
	histExpCs->Add(funct, 5000, "");
	histExpCs->Draw();
	histExp->Draw("same");
	histExpCo->Draw("same");
	TCanvas* c2 = new TCanvas();
	c2->cd();
	histExpCs->Add(funct, -5000, "");
	histExp->Add(funct, -5000, "");
	Int_t low_range_integral = histExp->GetXaxis()->FindBin(550.0);
    Int_t up_range_integral = histExp->GetXaxis()->FindBin(750.0);
    Int_t low_range_integralCs = histExpCs->GetXaxis()->FindBin(550.0);
    Int_t up_range_integralCs = histExpCs->GetXaxis()->FindBin(750.0);
    cout << "blue " << histExp->Integral(low_range_integral, up_range_integral) << endl;
    cout << "red " << histExpCs->Integral(low_range_integralCs, up_range_integralCs) << endl;
    histExp->Scale(histExpCs->GetMaximum()/histExp->GetMaximum(),"nosw2");
	histExpCs->Draw();
	histExp->Draw("same");
	histExpCo->Draw("same");*/	
	//OpenTree(11, "avcs2co4mult6inter0to1000sht960lonu880expdata.root", kGreen);
	TString simulation_filename = "test_run.root";
	OpenTree(11, simulation_filename, kGreen);
	OpenTree(12, "LO_Simulations/avcs2co4mult6inter0to1000sht960lonu880expdata.root", kMagenta);
	//DrawingSimExp(11, "avcs2co4mult6inter0to1000sht960lonu880expdata",histExp);
	//DrawingSimExp(11, simulation_filename,histExp);
	DrawingTwoSimOneExp(11,12,"avcs2co4mult6inter0to1000sht960lonu880extreme+avcs2co4mult6inter0to1000sht960lonu880.root");
}


void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth = 2)
{
	
	fr1[treeID] = new TFile(filename, "READ");
	tr1[treeID] = (TTree*)fr1[treeID]->Get("er");
	tr1[treeID]->SetLineColor(color);
	tr1[treeID]->SetLineWidth(lineWidth);
	
}	

void DrawingSimExp(Int_t treeID, TString filename, TH1D* histExperment)
{
	
	TString drawCommand;
	drawCommand.Form("GadastCsIDigi.fEdep*1000>>%s", filename.Data());
	tr1[treeID]->Draw("GadastCsIDigi.fEdep*1000>>htemp(1000,0.,3000.)");
	h1[treeID] = (TH1D*)gPad->GetPrimitive("htemp");
	h1[treeID]->SetTitle(filename);
	h1[treeID]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID]->GetYaxis()->SetTitle("Counts");
	TH1D* histExpShifted = new TH1D("h3", "Shifted", 1023, histExperment->GetXaxis()->GetBinLowEdge(1)+3., histExp->GetXaxis()->GetBinUpEdge(1024)+3.);
    for (Int_t cal_u = 1; cal_u < 1024; cal_u++)
            {
                histExpShifted->SetBinContent(cal_u, histExperment->GetBinContent(cal_u));
            }	
	//histExp->GetXaxis()->SetRangeUser(500.,700.);
	//Double_t histExpCsPeak = histExp->GetMaximum();
	//histExp->GetXaxis()->SetRangeUser(0.,3000.);
	/*if(h1[treeID]->GetMaximum() > histExperment->GetMaximum())
	{
		h1[treeID]->Scale(histExperment->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	}
	else
	{
		histExperment->Scale(h1[treeID]->GetMaximum()/histExperment->GetMaximum(),"nosw2");
	}*/
	if(h1[treeID]->GetMaximum() > histExpShifted->GetMaximum())
	{
		h1[treeID]->Scale(histExpShifted->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	}
	else
	{
		histExpShifted->Scale(h1[treeID]->GetMaximum()/histExpShifted->GetMaximum(),"nosw2");
	}	
	h1[treeID]->GetXaxis()->SetRangeUser(500.,700.);
	Double_t histExpCsPeak = h1[treeID]->GetMaximum();
	h1[treeID]->GetXaxis()->SetRangeUser(0.,3000.);	
	histExperment->Scale(histExpCsPeak/histExperment->GetMaximum(),"nosw2");
	//h1[treeID]->Scale(histExpShifted->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	//histExpShifted->Draw("same");
	histExperment->Draw("samehist");
	
	TLegend *legend=new TLegend(0.6,0.50,0.75,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(h1[treeID], "Simulation", "l");
    legend->AddEntry(histExperment, "Experiment", "l");
    legend->Draw();
	
	/*TLine* cs_compton_edge = new TLine(477.34, 0, 477.34, h1[treeID]->GetMaximum());
	cs_compton_edge->SetLineStyle(2);
	cs_compton_edge->SetLineWidth(2);
	cs_compton_edge->Draw();
	TLine* backscatter_peak = new TLine(184.32, 0, 184.32, h1[treeID]->GetMaximum());
	backscatter_peak->SetLineStyle(2);
	backscatter_peak->SetLineWidth(2);
	backscatter_peak->Draw();		
	TLine* cs_peak = new TLine(661.662, 0, 661.662, h1[treeID]->GetMaximum());
	cs_peak->SetLineStyle(2);
	cs_peak->SetLineWidth(2);
	cs_peak->Draw();
	TLine* double_cs_peak = new TLine(1323.324, 0, 1323.324, h1[treeID]->GetMaximum());
	double_cs_peak->SetLineStyle(2);
	double_cs_peak->SetLineWidth(2);
	double_cs_peak->Draw();*/
}

void DrawingTwoSimOneExp(Int_t treeID1,Int_t treeID2, TString filename)
{
	tr1[treeID1]->Draw("GadastCsIDigi.fEdep*1000>>htemp(1000,0.,3000.)");
	h1[treeID1] = (TH1D*)gPad->GetPrimitive("htemp");
	h1[treeID1]->SetTitle(filename);
	h1[treeID1]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID1]->GetYaxis()->SetTitle("Counts");
	TH1D* histExpShifted = new TH1D("h3", "Shifted", 1023, histExp->GetXaxis()->GetBinLowEdge(1)+15., histExp->GetXaxis()->GetBinUpEdge(1024)+15.);
    for (Int_t cal_u = 1; cal_u < 1024; cal_u++)
            {
                histExpShifted->SetBinContent(cal_u, histExp->GetBinContent(cal_u));
            }	
	//h1[treeID1]->Scale(histExp->GetMaximum()/h1[treeID1]->GetMaximum(),"nosw2");
	/*histExp->GetXaxis()->SetRangeUser(500.,700.);
	Double_t histExpCsPeak = histExp->GetMaximum();
	histExp->GetXaxis()->SetRangeUser(0.,3000.);
	if(h1[treeID]->GetMaximum() > histExp->GetMaximum())
	{
		h1[treeID]->Scale(histExp->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	}
	else
	{
		histExp->Scale(h1[treeID]->GetMaximum()/histExp->GetMaximum(),"nosw2");
	}*/
	
	tr1[treeID2]->Draw("GadastCsIDigi.fEdep*1000>>htemp2(1000,0.,3000.)", "", "Same");
	h1[treeID2] = (TH1D*)gPad->GetPrimitive("htemp2");
	h1[treeID2]->Scale(histExp->GetMaximum()/h1[treeID2]->GetMaximum(),"nosw2");
	h1[treeID1]->Scale(histExp->GetMaximum()/h1[treeID1]->GetMaximum(),"nosw2");
	h1[treeID2]->SetTitle(filename);
	h1[treeID2]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID2]->GetYaxis()->SetTitle("Counts");
	//h1[treeID2]->Scale(histExp->GetMaximum()/h1[treeID2]->GetMaximum(),"nosw2");
	//histExpShifted->Draw("same");
	histExp->Draw("samehist");
	
		
	TLegend *legend=new TLegend(0.6,0.50,0.9,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(h1[treeID1], "Simulation (with #DeltaLO)", "l");
    legend->AddEntry(h1[treeID2], "Simulation (without #DeltaLO)", "l");
    legend->AddEntry(histExp, "Experiment", "l");
    legend->Draw();
	
	/*TLine* cs_compton_edge = new TLine(477.34, 0, 477.34, h1[treeID1]->GetMaximum());
	cs_compton_edge->SetLineStyle(2);
	cs_compton_edge->SetLineWidth(2);
	cs_compton_edge->Draw();
	TLine* backscatter_peak = new TLine(184.32, 0, 184.32, h1[treeID1]->GetMaximum());
	backscatter_peak->SetLineStyle(2);
	backscatter_peak->SetLineWidth(2);
	backscatter_peak->Draw();		
	TLine* cs_peak = new TLine(661.662, 0, 661.662, h1[treeID1]->GetMaximum());
	cs_peak->SetLineStyle(2);
	cs_peak->SetLineWidth(2);
	cs_peak->Draw();
	TLine* double_cs_peak = new TLine(1323.324, 0, 1323.324, h1[treeID1]->GetMaximum());
	double_cs_peak->SetLineStyle(2);
	double_cs_peak->SetLineWidth(2);
	double_cs_peak->Draw();*/
}

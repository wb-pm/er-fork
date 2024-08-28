//Drawing and comparing spectra of Gadast tests simulations and experiment
#include <iostream>
#include <array>

#include "TH1D.h"
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TGaxis.h"
#include "TString.h"
#include "TF1.h"
//Hack, because can't obtain function directly from the histogram
Double_t calculateGaussian(Double_t *x, Double_t *par)
{
    return par[0]*exp(-0.5*((x[0]-par[1])/par[2])*((x[0]-par[1])/par[2]));
}
//Linear background function
Double_t calculateLinearBackground(Double_t *x, Double_t *par)
{
    return par[0] + par[1]*x[0];
}
//Compton edge function
Double_t calculateComptonEdge(Double_t *x, Double_t *par)
{
    return par[0]/(1.0+exp(2*par[1]*(x[0]-par[2])));
}
//Fit for Cs137
Double_t fitCaesiumPeak(Double_t *x, Double_t *par)
{
    return calculateGaussian(x,par) + calculateLinearBackground(x,&par[3]);
}
//Fit for Co60
Double_t fitCobaltPeak(Double_t *x, Double_t *par)
{
    return calculateGaussian(x,par) + calculateLinearBackground(x,&par[3]) + calculateGaussian(x,&par[5]);
}


std::array<TFile*, 25> fr1;
std::array<TTree*, 25> tr1;
std::array<TH1D*, 25> h1;
TH1D *histExpFront;
TH1D *histExpCs;
TH1D *histExpCo;
TH1D *histExpSide;
void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth = 2);
void DrawingSimExp(Int_t treeID, TString filename, TH1D* histExperment);
void DrawingTwoSimOneExp(Int_t treeID1,Int_t treeID2, TString filename, TH1D* histExp);
void DrawingTwoExp(TH1D* histFront, TH1D* histSide);
void DrawingTwoSim(Int_t treeID1, Int_t treeID2);
void drawSpectra()
{ 
	gROOT->SetStyle("Pub");
	gStyle->SetLineWidth(1);
/* 	TFile *frExp = new TFile("ROOT_Files/sub_back_877.root", "READ");
	histExp = (TH1D*)frExp->Get("Subtracted_Background_Energy"); */
	TFile *frExpFront = new TFile("ROOT_Files/892_ft.root", "READ");
	histExpFront = (TH1D*)frExpFront->Get("Calibrated_Fitting");
/* 	TFile *frExpSide = new TFile("ROOT_Files/892_st.root");
	histExpSide = (TH1D*)frExpSide->Get("Calibrated Fitting"); */
	TFile *frExpSide = new TFile("ROOT_Files/892_st2.root");
	histExpSide = (TH1D*)frExpSide->Get("hist_calibrated_spectrum");
	histExpSide->SetLineColor(kBlue);
	TFile *frExpCs = new TFile("ROOT_Files/sub_back_877cs.root", "READ");
	histExpCs = (TH1D*)frExpCs->Get("Subtracted_Background_Energy");
	TFile *frExpCo = new TFile("ROOT_Files/sub_back_877co.root", "READ");
	histExpCo = (TH1D*)frExpCo->Get("Subtracted_Background_Energy");	
	histExpFront->Rebin(8);
	histExpCs->Rebin(8);
	histExpCo->Rebin(8);
	histExpSide->Rebin(8);
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
	TString simulation_filename = "resolutionTests/";
	TString simulation_filename_second = "ComptonTests/standardDigiNormalLengthSideCuts1mmPlate6cmCo360kBqA0107B0279C0098noLONU.root";
	OpenTree(11, simulation_filename, kGreen);
	OpenTree(12, simulation_filename_second, kMagenta);
	//DrawingSimExp(11, "avcs2co4mult6inter0to1000sht960lonu880expdata",histExp);
	//DrawingSimExp(11, simulation_filename,histExp);
	DrawingTwoSimOneExp(11,12,simulation_filename+simulation_filename_second,histExpSide);
	//DrawingTwoExp(histExp,histExpSide);
	//DrawingTwoSim(11,12);
}


void OpenTree(Int_t treeID, TString filename, EColor color, Int_t lineWidth = 2)
{
	
	fr1[treeID] = new TFile(filename, "READ");
	tr1[treeID] = (TTree*)fr1[treeID]->Get("er");
	tr1[treeID]->SetLineColor(color);
	tr1[treeID]->SetLineWidth(lineWidth);
	tr1[treeID]->SetTitle(filename);
	
}	

void DrawingSimExp(Int_t treeID, TString filename, TH1D* histExperment)
{
	
	TString drawCommand;
	drawCommand.Form("GadastCsIDigi.fEdep*1000>>%s", filename.Data());
	tr1[treeID]->Draw("GadastCsIDigi.fEdep*1000>>htemp(1024,0.,3000.)");
	h1[treeID] = (TH1D*)gPad->GetPrimitive("htemp");
	//h1[treeID]->SetTitle(filename);
	h1[treeID]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID]->GetYaxis()->SetTitle("Counts");
	TH1D* histExpShifted = new TH1D("h3", "Shifted", 1023, histExperment->GetXaxis()->GetBinLowEdge(1)+3., histExperment->GetXaxis()->GetBinUpEdge(1024)+3.);
    for (Int_t cal_u = 1; cal_u < 1024; cal_u++)
            {
                histExpShifted->SetBinContent(cal_u, histExperment->GetBinContent(cal_u));
            }	
	if(h1[treeID]->GetMaximum() > histExpShifted->GetMaximum())
	{
		h1[treeID]->Scale(histExpShifted->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	}
	else
	{
		histExpShifted->Scale(h1[treeID]->GetMaximum()/histExpShifted->GetMaximum(),"nosw2");
	}	
	gPad->SetLeftMargin(0.15);
	histExperment->Draw("samehist");
	
	h1[treeID]->GetXaxis()->SetRangeUser(1100.,1250.);
	h1[treeID]->Scale(histExperment->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	h1[treeID]->GetXaxis()->SetRangeUser(0.,3000.);	

	TLegend *legend=new TLegend(0.6,0.50,0.75,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(h1[treeID], tr1[treeID]->GetTitle(), "l");
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

void DrawingTwoSimOneExp(Int_t treeID1,Int_t treeID2, TString filename, TH1D* histExp)
{
	TCanvas* canvas2Sim1Exp = new TCanvas("canvas2Sim1Exp","canvas2Sim1Exp");
	canvas2Sim1Exp->cd();
	tr1[treeID1]->Draw("GadastCsIDigi.fEdep*1000>>htemp(1024,0.,3000.)");
	h1[treeID1] = (TH1D*)gPad->GetPrimitive("htemp");
	h1[treeID1]->SetTitle(filename);
	h1[treeID1]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID1]->GetYaxis()->SetTitle("Counts");
	TH1D* histExpSideShifted = new TH1D("h3", "Shifted", 1023, histExp->GetXaxis()->GetBinLowEdge(1)-3, histExp->GetXaxis()->GetBinUpEdge(1024)-3);
    for (Int_t cal_u = 1; cal_u < 1024; cal_u++)
            {
                histExpSideShifted->SetBinContent(cal_u, histExp->GetBinContent(cal_u));
            }	
	//h1[treeID1]->Scale(histExpSide->GetMaximum()/h1[treeID1]->GetMaximum(),"nosw2");
	/*histExpSide->GetXaxis()->SetRangeUser(500.,700.);
	Double_t histExpSideCsPeak = histExpSide->GetMaximum();
	histExpSide->GetXaxis()->SetRangeUser(0.,3000.);
	if(h1[treeID]->GetMaximum() > histExpSide->GetMaximum())
	{
		h1[treeID]->Scale(histExpSide->GetMaximum()/h1[treeID]->GetMaximum(),"nosw2");
	}
	else
	{
		histExpSide->Scale(h1[treeID]->GetMaximum()/histExpSide->GetMaximum(),"nosw2");
	}*/
	
	tr1[treeID2]->Draw("GadastCsIDigi.fEdep*1000>>htemp2(1024,0.,3000.)", "", "Same");
	h1[treeID2] = (TH1D*)gPad->GetPrimitive("htemp2");
	h1[treeID2]->SetTitle(filename);
	h1[treeID2]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID2]->GetYaxis()->SetTitle("Counts");
	histExpSideShifted->Draw("samehist");
	histExp->Draw("samehist");
	TF1* funcExpCs = histExp->GetFunction("fitCs");
	TF1 *funcExpCo = histExp->GetFunction("fitCo");
	
	h1[treeID1]->GetXaxis()->SetRangeUser(1100,1250);
	h1[treeID2]->GetXaxis()->SetRangeUser(1100,1250);
	histExp->GetXaxis()->SetRangeUser(1100,1250);
	h1[treeID1]->Scale(histExp->GetMaximum()/h1[treeID1]->GetMaximum(),"nosw2");
	h1[treeID2]->Scale(histExp->GetMaximum()/h1[treeID2]->GetMaximum(),"nosw2");
	h1[treeID1]->GetXaxis()->SetRangeUser(0,3000);
	h1[treeID2]->GetXaxis()->SetRangeUser(0,3000);
	histExp->GetXaxis()->SetRangeUser(0,3000);
	TF1 *fitCs = new TF1("fitCs", fitCaesiumPeak, 600, 720, 5);
	fitCs->SetParameter(0,6000);
	fitCs->SetParameter(1,661);
	fitCs->SetParameter(2,25);
	fitCs->SetParNames("Cs_Amplitude", "Cs_Mean", "Cs_Sigma", "Cs_Constant", "Cs_Tangent");
	fitCs->SetLineColor(kBlack);
	TF1 *fitCo = new TF1("fitCo", fitCobaltPeak, 1050, 1450, 8);
	fitCo->SetParameter(0, 3000);
	fitCo->SetParameter(1, 1173);
	fitCo->SetParameter(2, 35);

	fitCo->SetParameter(5, 2500);
	fitCo->SetParameter(6, 1317);
	fitCo->SetParameter(7, 36);

	fitCo->SetLineColor(kBlack);
	fitCo->SetParNames("1stCo_Amplitude", "1stCo_Mean", "1stCo_Sigma", "Co_Constant", "CoTangent", "2ndCo_Amplitude", "2ndCo_Mean", "2ndCo_Sigma");
	std::cout << "Now fitting for the simulation..." << std::endl;
	h1[treeID1]->Fit(fitCs,"NR");
	h1[treeID1]->Fit(fitCo,"NR+");

	std::cout << "Now fitting for the experiment..." << std::endl;
	histExp->Fit(fitCs,"NR");
	histExp->Fit(fitCo,"NR+");

	TLegend *legend=new TLegend(0.6,0.50,0.9,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(h1[treeID1], tr1[treeID1]->GetTitle(), "l");
    legend->AddEntry(h1[treeID2], tr1[treeID2]->GetTitle(), "l");
    legend->AddEntry(histExp, "Experiment", "l");
    legend->Draw();

/* 	canvas2Sim1Exp->Update();	
	TLine* cs_compton_edge = new TLine(477.34, canvas2Sim1Exp->GetUymin(), 477.34, canvas2Sim1Exp->GetUymax());
	cs_compton_edge->SetLineStyle(2);
	cs_compton_edge->SetLineWidth(2);
	cs_compton_edge->Draw();
	TLine* backscatter_peak = new TLine(184.32, canvas2Sim1Exp->GetUymin(), 184.32, canvas2Sim1Exp->GetUymax());
	backscatter_peak->SetLineStyle(2);
	backscatter_peak->SetLineWidth(2);
	backscatter_peak->Draw();		
	TLine* cs_peak = new TLine(661.662, canvas2Sim1Exp->GetUymin(), 661.662, canvas2Sim1Exp->GetUymax());
	cs_peak->SetLineStyle(2);
	cs_peak->SetLineWidth(2);
	cs_peak->Draw();
	TLine* double_cs_peak = new TLine(1323.324, canvas2Sim1Exp->GetUymin(), 1323.324, canvas2Sim1Exp->GetUymax());
	double_cs_peak->SetLineStyle(2);
	double_cs_peak->SetLineWidth(2);
	double_cs_peak->Draw(); */
}

void DrawingTwoExp(TH1D* histFront, TH1D* histSide)
{

	histFront->GetXaxis()->SetRangeUser(1100,1250);
	histSide->GetXaxis()->SetRangeUser(1100,1250);
	//Scale according to 1st cobalt-60 peak
	histFront->Scale(histSide->GetMaximum()/histFront->GetMaximum(),"nosw2");
	histFront->GetXaxis()->SetRangeUser(0,3000);
	histSide->GetXaxis()->SetRangeUser(0,3000);
	histFront->Draw("hist");
	histFront->SetLineWidth(1);
	histFront->SetLineColor(kRed);
	histSide->Draw("samehist");
	histSide->SetLineWidth(1);
}

void DrawingTwoSim(Int_t treeID1, Int_t treeID2)
{
	TCanvas* canvas2Sim = new TCanvas("canvas2Sim", "canvas2Sim");
	canvas2Sim->cd();
	tr1[treeID1]->Draw("GadastCsIDigi.fEdep*1000>>htemp(1000,0.,3000.)");
	h1[treeID1] = (TH1D*)gPad->GetPrimitive("htemp");
	h1[treeID1]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID1]->GetYaxis()->SetTitle("Counts");

	tr1[treeID2]->Draw("GadastCsIDigi.fEdep*1000>>htemp2(1000,0.,3000.)", "", "Same");
	h1[treeID2] = (TH1D*)gPad->GetPrimitive("htemp2");

	h1[treeID2]->GetXaxis()->SetTitle("Energy, keV");
	h1[treeID2]->GetYaxis()->SetTitle("Counts");

	h1[treeID1]->GetXaxis()->SetRangeUser(1100,1250);
	h1[treeID2]->GetXaxis()->SetRangeUser(1100,1250);
	h1[treeID1]->Scale(h1[treeID2]->GetMaximum()/h1[treeID1]->GetMaximum(),"nosw2");
	h1[treeID1]->GetXaxis()->SetRangeUser(0,3000);
	h1[treeID2]->GetXaxis()->SetRangeUser(0,3000);

	TLegend *legend=new TLegend(0.6,0.50,0.9,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(h1[treeID1], tr1[treeID1]->GetTitle(), "l");
    legend->AddEntry(h1[treeID2], tr1[treeID2]->GetTitle(), "l");
    legend->Draw();
}
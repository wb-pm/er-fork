#if !defined(__CLING__)
#include "TTree.h"
#include "TLeaf.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TClonesArray.h"
#include "TBrowser.h"
#include "TRandom.h"
#include "TH1D.h"
#include "TPad.h"
#include "Fit/FitConfig.h"
#include "Fit/BinData.h"
#include "Fit/Fitter.h"
#include "Fit/Chi2FCN.h"
#include "TF1.h"
#include "Math/Polynomial.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TStyle.h"

#include "ERGadastCsIDigi.h"
#endif
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

TH1D* readExperimentHist(TString fileName);
TH1D* readSimulationHist(TString fileName, TString histName, TH1D* experimental_hist);
Double_t calculateSigma(Double_t a, Double_t b, Double_t c, Double_t edep);
void calibrateExperiment(TH1D* experiment_hist, std::vector<Double_t> energyValues);
void drawSimExp(TH1D* digitized_hist, TH1D* experiment_hist);
void printSigmas(Double_t a, Double_t b, Double_t c, Bool_t isLONU);
void drawTwoSimOneExp(TH1D* digitized_lonu_hist, TH1D* digitized_no_lonu_hist, TH1D* experiment_hist);
TH1D* fillHistogramWithOther(TH1D* initial_hist, TH1D* values_hist);
void fitHistogram(TH1D* fit_hist);
const Double_t aGlobalCoefLONU = 0.0157, bGlobalCoefLONU = 0.00978, cGlobalCoefLONU = 0.02265;
const Double_t aGlobalCoefNoLONU = 0.0197, bGlobalCoefNoLONU = 0.00978, cGlobalCoefNoLONU = 0.02265;
void drawSpectraV2()

{ //Now have to redo the script and exclude the resolution application part
    gErrorIgnoreLevel = kError;
    gStyle->SetOptStat(0);

    printSigmas(aGlobalCoefLONU,bGlobalCoefLONU,cGlobalCoefLONU,true);
    printSigmas(aGlobalCoefNoLONU,bGlobalCoefNoLONU,cGlobalCoefNoLONU,false);
    TH1D* experiment_for_no_lonu_hist = readExperimentHist("ExperimentData/SideMeasurements/892_st.root");
    TH1D* experiment_for_lonu_hist = (TH1D*)experiment_for_no_lonu_hist->Clone();
    std::vector<Double_t> energyValuesNoLonu = {661.662,1173.240,1332.508};
    std::vector<Double_t> energyValuesLonu = {659.625,1168.21,1330.25};
    calibrateExperiment(experiment_for_no_lonu_hist, energyValuesNoLonu);
    calibrateExperiment(experiment_for_lonu_hist, energyValuesLonu);

    TH1D* simulation_lonu_hist = readSimulationHist("separateDigi/LONU/A0167B00978C02265_digi_lonu_sim_regularCrystal_plate6cm_Co400kBq_Interval10usDecay4us.root","lonu_hist",experiment_for_lonu_hist);

    TH1D* simulation_no_lonu_hist = readSimulationHist("separateDigi/No_LONU/A0187B00978C02265_digi_no_lonu_sim_regularCrystal_plate6cm_Co380kBq_Interval10usDecay4us.root","no_lonu_hist",experiment_for_no_lonu_hist);

    TH1D* simulation_lonu_calibrated_hist = fillHistogramWithOther(experiment_for_no_lonu_hist, simulation_lonu_hist);
    //drawSimExp(simulation_lonu_hist, experiment_for_lonu_hist);
    drawTwoSimOneExp(simulation_lonu_calibrated_hist, simulation_no_lonu_hist, experiment_for_no_lonu_hist);
}

TH1D* readExperimentHist(TString fileName)
{
    TFile* experiment_file = new TFile(fileName,"READ");
    if (!experiment_file || experiment_file->IsZombie()) {
		std::cerr << "Error: Unable to open input file " << experiment_file->GetName() << std::endl;
        exit;
	}
    TH1D* experiment_hist = (TH1D*)experiment_file->Get("hist_original_spectrum");
    if(!experiment_hist)
    {
        std::cerr << "Error: Unable to find experiment histogram " << "in the experiment file." << std::endl;
    }
    return experiment_hist;
}

TH1D* readSimulationHist(TString fileName, TString histName, TH1D* experimental_hist)
{
    TH1D* simulation_hist = new TH1D(histName,histName,experimental_hist->GetNbinsX(),experimental_hist->GetXaxis()->GetXmin(),experimental_hist->GetXaxis()->GetXmax());
    TFile* simulation_file = new TFile(fileName,"READ");
    if (!simulation_file || simulation_file->IsZombie()) {
		std::cerr << "Error: Unable to open input file " << simulation_file->GetName() << std::endl;
        return simulation_hist;
    }
    TTree* simulation_tree = (TTree*)simulation_file->Get("er");
    if (!simulation_tree)
    {
        std::cerr << "Error: Unable to find simulation tree in the simulation file." << std::endl;
        return simulation_hist;
    }
    TClonesArray* gadastDigi = new TClonesArray("ERGadastCsIDigi");
    simulation_tree->SetBranchAddress("GadastCsIDigi",&gadastDigi);
    Long64_t totalEvents = simulation_tree->GetEntries();
    for(Long64_t nEvent = 0; nEvent < totalEvents; nEvent++)
    {
        simulation_tree->GetEntry(nEvent);
        Int_t nDigi = gadastDigi->GetEntriesFast();
        for(int i = 0; i < nDigi; i++){
            ERGadastCsIDigi* gadastDigiEvent = (ERGadastCsIDigi*)gadastDigi->At(i);
            Double_t edep = (Double_t)gadastDigiEvent->Edep();
            simulation_hist->Fill(edep*1000);
        }
    }
    return simulation_hist;
}
Double_t calculateSigma(Double_t a, Double_t b, Double_t c, Double_t edep){
	Double_t sigma = sqrt(a*a + pow(b*sqrt(edep),2) + pow(c*edep,2));
    return sigma;
}

void calibrateExperiment(TH1D* experiment_hist, std::vector<Double_t> energyValues)
{
    TF1* funcCs = experiment_hist->GetFunction("fitCs");
    TF1* funcCo = experiment_hist->GetFunction("fitCo");
    TGraph* graph_calibration = new TGraph();
    graph_calibration->SetPoint(0, funcCs->GetParameter(1),energyValues.at(0));
    graph_calibration->SetPoint(1, funcCo->GetParameter(1),energyValues.at(1));
    graph_calibration->SetPoint(2, funcCo->GetParameter(6),energyValues.at(2));
/*     graph_calibration->SetPoint(0, funcCs->GetParameter(1),659.597);
    graph_calibration->SetPoint(1, funcCo->GetParameter(1),1168.04);
    graph_calibration->SetPoint(2, funcCo->GetParameter(6),1330.18); */
    TF1* fitCalibration = new TF1("fitCalibration","[0]*x+[1]");
    //std::cout 
    graph_calibration->Fit("fitCalibration","Q");
    std::cout << "Calibration coefficients, x*" << fitCalibration->GetParameter(0) << " + " << fitCalibration->GetParameter(1) << std::endl;

/*     ROOT::Fit::BinData calibrationData(3,1);
    calibrationData.Add(funcCs->GetParameter(1),661.662);
    calibrationData.Add(funcCo->GetParameter(1),1173.240);
    calibrationData.Add(funcCo->GetParameter(6),1332.508);
    ROOT::Math::Polynomial linear(1);
    ROOT::Fit::Fitter fitter;
    fitter.Config().SetMinimizer("Minuit2","Migrad");
    ROOT::Fit::Chi2Function chi2(calibrationData,linear); */
    Double_t tangent = fitCalibration->GetParameter(0);
    Double_t offset = fitCalibration->GetParameter(1);
    TAxis* experiment_axis = experiment_hist->GetXaxis();
    experiment_axis->SetLimits(experiment_axis->GetXmin()*tangent + offset+0.5,experiment_axis->GetXmax()*tangent + offset+0.5);
    experiment_hist->SetStats(kFALSE);
	experiment_hist->GetXaxis()->SetTitle("Energy, keV");
	experiment_hist->GetYaxis()->SetTitle("Counts");
}

void printSigmas(Double_t a, Double_t b, Double_t c, Bool_t isLONU)
{
	std::vector<Double_t> sigmas(3,0);
	Double_t E_cs = 0.661083;
	Double_t E_co1 = 1.17246;
	Double_t E_co2 = 1.33309;
	sigmas[0] = sqrt(a*a + pow(b*sqrt(E_cs),2) + pow(c*E_cs,2));
	sigmas[1] = sqrt(a*a + pow(b*sqrt(E_co1),2) + pow(c*E_co1,2));
	sigmas[2] = sqrt(a*a + pow(b*sqrt(E_co2),2) + pow(c*E_co2,2));
    if(isLONU){
        std::cout << "Coefficients used in LONU simulation: " << std::endl;
    }
    else{
        std::cout << "Coefficients used in no LONU simulation: " << std::endl;
    }
	std::cout << "For given a,b,c = " << a << " " << b << " " << c << std::endl;
    std::cout << "Given sigmas: " << "sigma_cs = " << sigmas[0]*1e3 << ", sigma_co1 = " << sigmas[1]*1e3 << ", sigma_co2 = " << sigmas[2]*1e3 << std::endl;
    std::cout << "Given means: " << "mean_cs = " << E_cs*1e3 << ", mean_co1 = " << E_co1*1e3 << ", mean_co2 = " << E_co2*1e3 << std::endl << std::endl;
    
}

TH1D* fillHistogramWithOther(TH1D* calibration_hist, TH1D* values_hist)
{
    TH1D* final_hist = new TH1D(values_hist->GetName(),values_hist->GetTitle(),calibration_hist->GetNbinsX(),calibration_hist->GetXaxis()->GetXmin(),calibration_hist->GetXaxis()->GetXmax());
    for(int i = 1; i < calibration_hist->GetNbinsX(); i++)
    {
        final_hist->SetBinContent(i, values_hist->GetBinContent(i));
    }

    return final_hist;
}

void drawSimExp(TH1D* digitized_hist, TH1D* experiment_hist){
    if(digitized_hist->GetNbinsX() > 8000)
    {
        digitized_hist->Rebin(8);
    }
    if(experiment_hist->GetNbinsX() > 8000)
    {
        experiment_hist->Rebin(8);
    }
    digitized_hist->Draw();
	digitized_hist->GetXaxis()->SetRangeUser(1100.,1250.);
    experiment_hist->GetXaxis()->SetRangeUser(1100.,1250.);
	digitized_hist->Scale(experiment_hist->GetMaximum()/digitized_hist->GetMaximum(),"nosw2");
	digitized_hist->GetXaxis()->SetRangeUser(0.,3000.);	
	experiment_hist->GetXaxis()->SetRangeUser(0.,3000.);	
    experiment_hist->Draw("samehist");
    experiment_hist->SetLineColor(kRed);

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
	digitized_hist->Fit(fitCs,"QR");
	digitized_hist->Fit(fitCo,"QR+");
    digitized_hist->GetFunction("fitCo")->SetLineColor(kGreen);
    digitized_hist->GetFunction("fitCs")->SetLineColor(kGreen);
    std::cout << "Histogram name: " << digitized_hist->GetName() << std::endl;
	std::cout << "Simulation sigmas: " << "sigma_cs = " << digitized_hist->GetFunction("fitCs")->GetParameter("Cs_Sigma") << ", sigma_co1 = " << digitized_hist->GetFunction("fitCo")->GetParameter("1stCo_Sigma") << ", sigma_co2 = " << digitized_hist->GetFunction("fitCo")->GetParameter("2ndCo_Sigma") << std::endl;
	std::cout << "Simulation means: " << "mean_cs = " << digitized_hist->GetFunction("fitCs")->GetParameter("Cs_Mean") << ", mean_co1 = " << digitized_hist->GetFunction("fitCo")->GetParameter("1stCo_Mean") << ", mean_co2 = " << digitized_hist->GetFunction("fitCo")->GetParameter("2ndCo_Mean") << std::endl;


	experiment_hist->Fit(fitCs,"QR");
	experiment_hist->Fit(fitCo,"QR+");

	std::cout << "Experiment sigmas: " << "sigma_cs = " << experiment_hist->GetFunction("fitCs")->GetParameter("Cs_Sigma") << ", sigma_co1 = " << experiment_hist->GetFunction("fitCo")->GetParameter("1stCo_Sigma") << ", sigma_co2 = " << experiment_hist->GetFunction("fitCo")->GetParameter("2ndCo_Sigma") << std::endl;
	std::cout << "Experiment means: " << "mean_cs = " << experiment_hist->GetFunction("fitCs")->GetParameter("Cs_Mean") << ", mean_co1 = " << experiment_hist->GetFunction("fitCo")->GetParameter("1stCo_Mean") << ", mean_co2 = " << experiment_hist->GetFunction("fitCo")->GetParameter("2ndCo_Mean") << std::endl;

    Double_t cs_par[13];
    experiment_hist->GetFunction("fitCs")->GetParameters(cs_par);
	TF1 *backFcn = new TF1("backFcn", calculateLinearBackground, 600, 720, 2);
	backFcn->SetLineColor(kCyan);
	backFcn->SetParameters(&cs_par[3]);
	backFcn->Draw("same");

	Double_t co_par[13];
	experiment_hist->GetFunction("fitCo")->GetParameters(co_par);
	TF1 *CoBackFcn = new TF1("CoBackFcn", calculateLinearBackground, 1050,1450, 2);
	CoBackFcn->SetLineColor(kGreen);

	CoBackFcn->SetParameters(&co_par[3]);
	CoBackFcn->Draw("same");

	TLegend *legend=new TLegend(0.6,0.50,0.75,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(digitized_hist, "Simulation", "l");
    legend->AddEntry(experiment_hist, "Experiment", "l");
    legend->Draw();
    ;
}
void drawTwoSimOneExp(TH1D* digitized_lonu_hist, TH1D* digitized_no_lonu_hist, TH1D* experiment_hist){
    TCanvas* threeHistsCanvas = new TCanvas("twoSimOneExp","twoSimOneExp");
    if(digitized_lonu_hist->GetNbinsX() > 8000)
    {
        digitized_lonu_hist->Rebin(8);
    }
    if(digitized_no_lonu_hist->GetNbinsX() > 8000)
    {
        digitized_no_lonu_hist->Rebin(8);
    }
    if(experiment_hist->GetNbinsX() > 8000)
    {
        experiment_hist->Rebin(8);
    }
    digitized_lonu_hist->Draw();
    digitized_no_lonu_hist->Draw("same");
    digitized_lonu_hist->GetXaxis()->SetRangeUser(1100.,1250.);
    digitized_no_lonu_hist->GetXaxis()->SetRangeUser(1100.,1250.);
    experiment_hist->GetXaxis()->SetRangeUser(1100.,1250.);
    digitized_lonu_hist->Scale(experiment_hist->GetMaximum()/digitized_lonu_hist->GetMaximum(),"nosw2");
    digitized_no_lonu_hist->Scale(experiment_hist->GetMaximum()/digitized_no_lonu_hist->GetMaximum(),"nosw2");
    digitized_lonu_hist->GetXaxis()->SetRangeUser(0.,3000.);	
    experiment_hist->GetXaxis()->SetRangeUser(0.,3000.);	
    digitized_no_lonu_hist->GetXaxis()->SetRangeUser(0.,3000.);	
    experiment_hist->Draw("samehist");
    experiment_hist->SetLineColor(kRed);
    digitized_lonu_hist->SetLineColor(kGreen);
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

	digitized_lonu_hist->Fit(fitCs,"QR");
	digitized_lonu_hist->Fit(fitCo,"QR+");
    digitized_lonu_hist->GetFunction("fitCo")->SetLineColor(kGreen);
    digitized_lonu_hist->GetFunction("fitCs")->SetLineColor(kGreen);
    digitized_lonu_hist->GetFunction("fitCo")->SetLineWidth(0);
    digitized_lonu_hist->GetFunction("fitCs")->SetLineWidth(0);

    std::cout << "Histogram name: " << digitized_lonu_hist->GetName() << std::endl;
	std::cout << "Simulation sigmas: " << "sigma_cs = " << digitized_lonu_hist->GetFunction("fitCs")->GetParameter("Cs_Sigma") << ", sigma_co1 = " << digitized_lonu_hist->GetFunction("fitCo")->GetParameter("1stCo_Sigma") << ", sigma_co2 = " << digitized_lonu_hist->GetFunction("fitCo")->GetParameter("2ndCo_Sigma") << std::endl;
	std::cout << "Simulation means: " << "mean_cs = " << digitized_lonu_hist->GetFunction("fitCs")->GetParameter("Cs_Mean") << ", mean_co1 = " << digitized_lonu_hist->GetFunction("fitCo")->GetParameter("1stCo_Mean") << ", mean_co2 = " << digitized_lonu_hist->GetFunction("fitCo")->GetParameter("2ndCo_Mean") << std::endl;

	digitized_no_lonu_hist->Fit(fitCs,"QR");
	digitized_no_lonu_hist->Fit(fitCo,"QR+");
    digitized_no_lonu_hist->GetFunction("fitCo")->SetLineColor(kGreen);
    digitized_no_lonu_hist->GetFunction("fitCs")->SetLineColor(kGreen);
    digitized_no_lonu_hist->GetFunction("fitCo")->SetLineWidth(0);
    digitized_no_lonu_hist->GetFunction("fitCs")->SetLineWidth(0);

    std::cout << "Histogram name: " << digitized_no_lonu_hist->GetName() << std::endl;
	std::cout << "Simulation sigmas: " << "sigma_cs = " << digitized_no_lonu_hist->GetFunction("fitCs")->GetParameter("Cs_Sigma") << ", sigma_co1 = " << digitized_no_lonu_hist->GetFunction("fitCo")->GetParameter("1stCo_Sigma") << ", sigma_co2 = " << digitized_no_lonu_hist->GetFunction("fitCo")->GetParameter("2ndCo_Sigma") << std::endl;
	std::cout << "Simulation means: " << "mean_cs = " << digitized_no_lonu_hist->GetFunction("fitCs")->GetParameter("Cs_Mean") << ", mean_co1 = " << digitized_no_lonu_hist->GetFunction("fitCo")->GetParameter("1stCo_Mean") << ", mean_co2 = " << digitized_no_lonu_hist->GetFunction("fitCo")->GetParameter("2ndCo_Mean") << std::endl;


	experiment_hist->Fit(fitCs,"QR");
	experiment_hist->Fit(fitCo,"QR+");

    std::cout << "Histogram name: " << experiment_hist->GetName() << std::endl;
	std::cout << "Experiment sigmas: " << "sigma_cs = " << experiment_hist->GetFunction("fitCs")->GetParameter("Cs_Sigma") << ", sigma_co1 = " << experiment_hist->GetFunction("fitCo")->GetParameter("1stCo_Sigma") << ", sigma_co2 = " << experiment_hist->GetFunction("fitCo")->GetParameter("2ndCo_Sigma") << std::endl;
	std::cout << "Experiment means: " << "mean_cs = " << experiment_hist->GetFunction("fitCs")->GetParameter("Cs_Mean") << ", mean_co1 = " << experiment_hist->GetFunction("fitCo")->GetParameter("1stCo_Mean") << ", mean_co2 = " << experiment_hist->GetFunction("fitCo")->GetParameter("2ndCo_Mean") << std::endl;

    Double_t cs_par[13];
    experiment_hist->GetFunction("fitCs")->GetParameters(cs_par);
	TF1 *backFcn = new TF1("backFcn", calculateLinearBackground, 600, 720, 2);
	backFcn->SetLineColor(kCyan);
	backFcn->SetParameters(&cs_par[3]);
	backFcn->Draw("same");

	Double_t co_par[13];
	experiment_hist->GetFunction("fitCo")->GetParameters(co_par);
	TF1 *CoBackFcn = new TF1("CoBackFcn", calculateLinearBackground, 1050,1450, 2);
	CoBackFcn->SetLineColor(kGreen);

	CoBackFcn->SetParameters(&co_par[3]);
	CoBackFcn->Draw("same");


	TLegend *legend=new TLegend(0.6,0.50,0.75,0.7);
	legend->SetTextFont(72);
    legend->SetTextSize(0.03);
    legend->AddEntry(digitized_no_lonu_hist, "Simulation (no LONU)", "l");
    legend->AddEntry(digitized_lonu_hist, "Simulation (LONU)", "l");
    legend->AddEntry(experiment_hist, "Experiment", "l");
    legend->Draw();
    ;
}
void fitHistogram(TH1D* fit_hist)
{
    ;
}
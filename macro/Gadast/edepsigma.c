#include "TGraph.h"
#include "TF1.h"
#include "Fit/FitConfig.h"

void calculateSigma(Double_t a, Double_t b, Double_t c);

void edepsigma()
{
	/*TGraph* gr1 = new TGraph();
	gr1->SetPoint(0, 662.077*1e-3, 0.0423);
	gr1->SetPoint(1, 1174.76*1e-3, 0.03166);
	gr1->SetPoint(2, 1334.45*1e-3, 0.0308);
	gr1->Draw("A*");
	TF1 *sqrtfit = new TF1("sqrtfit","sqrt(pow([2]/x,2) + pow([0]/sqrt(x),2) + [1]*[1])");
	sqrtfit->SetParameter(0,0.001);
	sqrtfit->SetParameter(1,0.001);
	sqrtfit->SetParameter(2,0.001);
	gr1->Fit("sqrtfit");*/
	//ROOT::Math::MinimizerOptions::SetDefaultMinimizer("Minuit2");	
	//ROOT::Math::MinimizerOptions::SetDefaultStrategy(2);
	TGraph* gr2 = new TGraph();

	//Values are too high
/* 	gr2->SetPoint(0, 661.083*1e-3, 0.029831);
	gr2->SetPoint(1, 1172.46*1e-3, 0.037658);
	gr2->SetPoint(2, 1333.09*1e-3, 0.04023); */
	//
	gr2->SetPoint(0, 661.083*1e-3, 0.02524);
	gr2->SetPoint(1, 1172.46*1e-3, 0.03393);
	gr2->SetPoint(2, 1333.09*1e-3, 0.03738);
	gr2->Draw("A*");
		TF1 *sqrtfit2 = new TF1("sqrtfit2","sqrt([0]*[0] + pow(sqrt(x)*[1],2) + pow(x*[2],2))");
	sqrtfit2->SetParameter(0,0.001);
	sqrtfit2->SetParameter(1,0.001);
	sqrtfit2->SetParameter(2,0.001);
	//sqrtfit2->FixParameter(1,0.0260);
	gr2->Fit("sqrtfit2");
	//Reference values: 0.0025125, 0.0032457, 0.0035568
	//calculateSigma(0.0177,0.0279,0.0019); // Solid coefficients
	calculateSigma(0.0087,0.0259,0.0155); // Best coefficients
	calculateSigma(0.0107,0.0259,0.0141); //Closest to sigmas from fit of experimental function
	calculateSigma(0.0215,0.0055,0.0207); 
}

void calculateSigma(Double_t a, Double_t b, Double_t c){
	std::vector<Double_t> sigmas(3,0);
	Double_t E_cs = 0.661083;
	Double_t E_co1 = 1.17246;
	Double_t E_co2 = 1.33309;
	sigmas[0] = sqrt(a*a + pow(b*sqrt(E_cs),2) + pow(c*E_cs,2));
	sigmas[1] = sqrt(a*a + pow(b*sqrt(E_co1),2) + pow(c*E_co1,2));
	sigmas[2] = sqrt(a*a + pow(b*sqrt(E_co2),2) + pow(c*E_co2,2));
	std::cout << "For given a,b,c = " << a << " " << b << " " << c << std::endl << "sigma_cs = " << sigmas[0] << ", sigma_co1 = " << sigmas[1] << ", sigma_co2 = " << sigmas[2] << std::endl;
}
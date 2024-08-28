#if !defined(__CLING__)

#include <iostream>

#include "TStopwatch.h"
#include "TString.h"
#include "TDatabasePDG.h"

#include "FairRunSim.h"
#include "FairPrimaryGenerator.h"
#include "FairBoxGenerator.h"
#include "FairParRootFileIo.h"
#include "FairRunAna.h"

#include "ERCave.h"
#include "ERGadast.h"
#include "ERGadastDigitizer.h"

#endif

void digitization(int nEvents = 1,TString sim_file = "just_sim_test.root",TString par_file = "ParametersROOT/par_just_sim_test.root", TString digi_out_file = "digi_just_sim_test.root", int multiplicity = 4)
{
  nEvents = 3e7;
  sim_file = "sim_regularCrystal_plate6cm30mln.root";
  par_file = "ParametersROOT/par_sim_regularCrystal_plate6cm30mln.root";
    digi_out_file = "separateDigi/No_LONU/A0187B00978C02265_digi_no_lonu_sim_regularCrystal_plate6cm_Co380kBq_Interval10usDecay4us.root";
  TString parOutFile = "ParametersROOT/par_digi_test.root";
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // ------------------------------------------------------------------------
  // -----   Digitization run   -------------------------------------------
  FairRunAna *fRun= new FairRunAna();
  fRun->SetInputFile(sim_file);
  fRun->SetOutputFile(digi_out_file);
  // -----   GADAST Digitizer -------------------------------------------------
  Int_t verbose = 2; // 1 - only standard log print, 2 - print digi information 
  ERGadastDigitizer* digitizer = new ERGadastDigitizer(verbose);

  //Setting the seed for random generators
  digitizer->SetSeed(12345);

  //Structure for light output non-uniformity coefficients
  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> lc;
  //Values taken from the experiment
    std::vector<std::vector<std::vector<float>>> lc_deltaLOexp = { { { 0.9985703,	0.9978926,	0.9945173,	0.990211,	0.9889056,	1.013246,	1.016656 } } };
  lc[{1, 1}] = lc_deltaLOexp;
  digitizer->SetCsILC(1.);
  //Light output non-uniformity coefficients taken from the measurements for the crystal number 866 

  //Data for energy resolution from new 887 crystal measurement
  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> a;
  //std::vector<std::vector<std::vector<float>>> block_1_a = { { { 0.0215, 0.0215, 0.0215 }, { 0.0215, 0.0215, 0.0215 } },
                                                             //{ { 0.0215, 0.0215, 0.0215 }, { 0.0215, 0.0215, 0.0215 } } }; 
  std::vector<std::vector<std::vector<float>>> block_1_a(1, std::vector<std::vector<float> >(1, std::vector<float>(1, 0.0215)));  	                                                           
  /*for(int i = 0; i < 10000; i++){
	  for(int j = 0; j < 10000; j++){
		for(int k = 0; k < 10000; k++){
			block_1_a[i][j].push_back(0.0215);
}   */                                                     
  float a_exp = 0.0215;                                                  
  //a[{1, 1}] = a_exp;

  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> b;
  std::vector<std::vector<std::vector<float>>> block_1_b(1, std::vector<std::vector<float> >(1, std::vector<float>(1, 0.0055)));
  //std::vector<std::vector<std::vector<float>>> block_1_b = { { { 0.0055, 0.0055, 0.0055 }, { 0.0055, 0.0055, 0.0055 } },
															//{ { 0.0055, 0.0055, 0.0055 }, { 0.0055, 0.0055, 0.0055 } } };                                       
 
  /*for(int i = 0; i < 100; i++){
  block_1_b[0][0].push_back(0.0055);*/
 

  float b_exp = 0.0055;                                                              
  //b[{1, 1}] = block_1_b;

  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> c;
  std::vector<std::vector<std::vector<float>>> block_1_c(1, std::vector<std::vector<float> >(1, std::vector<float>(1, 0.0206)));
  //std::vector<std::vector<std::vector<float>>> block_1_c = { { { 0.0206, 0.0206, 0.0206 }, { 0.0206, 0.0206, 0.0206 } },
															//{ { 0.0206, 0.0206, 0.0206 }, { 0.0206, 0.0206, 0.0206 } } }; 															
  /*for(int i = 0; i < 100; i++){
  block_1_c[0][0].push_back(0.0206);*/
  														 
  float c_exp = 0.0207;                                                            
  //c[{1, 1}] = block_1_c;
  
  //digitizer->SetCsIEdepError(0.0107, 0.0279, 0.0098);
  digitizer->SetCsIEdepError(0.0187,0.00978,0.02265);

  digitizer->SetCsITimeError(0.);
  //digitizer->SetLaBrLC(1.);
  //digitizer->SetLaBrEdepError(0.0,0.04,0.02);
  //digitizer->SetLaBrTimeError(0.);

  //Shaping time, taken from the GADAST characterization experiment 
  const Double_t expShapingTime = 4.; //microseconds
  Double_t decayTime = 4.;
  Double_t intervalTime = 10.; //microseconds
  //Activity of caesium-137 source during the experiment
  Double_t activityCs = 350.14e3; //becquerel
  //Activity of cobalt-60 source during the experiment
  Double_t activityCo = 380.54e3; //becquerel
  digitizer->SetGammasMultiplicity(multiplicity);
  digitizer->SetDecayTime(decayTime);
  digitizer->SetSignalsInterval(intervalTime);
  digitizer->SetPoissonCs(expShapingTime*1e-6*activityCs);
  digitizer->SetPoissonCo(expShapingTime*1e-6*activityCo);
  fRun->AddTask(digitizer);
  // -----------Runtime DataBase info -------------------------------------
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();

  FairParRootFileIo*  parInput = new FairParRootFileIo();
  parInput->open(par_file.Data(), "UPDATE");
  rtdb->setFirstInput(parInput);
  //-------Set LOG verbosity  ----------------------------------------------- 
  FairLogger::GetLogger()->SetLogVerbosityLevel("HIGH");
  FairLogger::GetLogger()->SetLogScreenLevel("INFO");
  // -----   Initialise and run   --------------------------------------------
//  if(gSystem->AccessPathName())
  fRun->Init();
  fRun->Run(0, nEvents);
  // -----------Runtime DataBase output -------------------------------------
  parInput->close();
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo*  parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parOutFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();

  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  std::cout << std::endl << std::endl;
  std::cout << "Macro finished succesfully." << std::endl;
  std::cout << "Output file written:  "    << digi_out_file << std::endl;
  std::cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << std::endl;
  std::cout << std::endl;
  // ------------------------------------------------------------------------
}
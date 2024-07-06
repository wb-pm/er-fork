#if !defined(__CLING__)

#include <iostream>

#include "TStopwatch.h"
#include "TString.h"
#include "TDatabasePDG.h"

#include "FairRunSim.h"
#include "FairPrimaryGenerator.h"
#include "FairBoxGenerator.h"
#include "FairParRootFileIo.h"

#include "ERCave.h"
#include "ERGadast.h"
#include "ERGadastDigitizer.h"

#endif

void sim_digi(int nEvents = 1,TString geometry_file_name = "gadast_test2021.gdml", Double32_t theta_min = 0, 
Double32_t theta_max = 180, Double32_t phi_min = 0, Double32_t phi_max = 360, TString file_name = "sim_digi.root"){
  //---------------------Files-----------------------------------------------
  TString outFile= file_name;
  TString parFile= "par.root";
  // ------------------------------------------------------------------------

  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // ------------------------------------------------------------------------
 
  // -----   Create simulation run   ----------------------------------------
  FairRunSim* run = new FairRunSim();
  /** Select transport engine
  * TGeant3
  * TGeant4
  **/
  run->SetName("TGeant4");              // Transport engine
  run->SetOutputFile(outFile.Data());          // Output file
  // ------------------------------------------------------------------------
  
  // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  // ------------------------------------------------------------------------
  
  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo");       // Materials
  // ------------------------------------------------------------------------

  // -----   Create detectors  ----------------------------------------------	
  FairModule* cave= new ERCave("CAVE");
  cave->SetGeometryFileName("cave.geo");
  run->AddModule(cave);

  ERGadast* gadast= new ERGadast("ERGadast", kTRUE, 1);
  //gadast->SetStoreSteps();
  gadast->SetGeometryFileName(geometry_file_name);
  run->AddModule(gadast);
  // ------------------------------------------------------------------------
  Int_t verbose = 2; // 1 - only standard log print, 2 - print digi information 
  ERGadastDigitizer* digitizer = new ERGadastDigitizer(verbose);
  //digitizer->SetCsILC(1.);
  /*
  std::map<std::pair<size_t, size_t>, float> lc;
  lc[{0, 1}] = 1.;
  digitizer->SetCsILC(lc);
  */
  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> lc;
  float lc_test = 1.;
  std::vector<std::vector<std::vector<float>>> block_1 = { { { 0.9985703,	0.9978926,	0.9945173,	0.990211,	0.9889056,	1.013246,	1.016656 } } };
  lc[{1, 1}] = block_1;
  digitizer->SetCsILC(lc);
  //Light output non-uniformity coefficients taken from the measurements for the crystal number 866 
  //std::vector<std::vector<std::vector<float>>> block_1 = { { { 1., 1., 1. }, { 1., 1., 1. } },
                                                             //{ { 1., 1., 1. }, { 1., 1., 1. } } }; 
  //std::vector<std::vector<std::vector<float>>> block_1 = { { { 1. } } };                                                                                                                  
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
  float a_test = 0.0215;                                                  
  //a[{1, 1}] = a_test;

  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> b;
  std::vector<std::vector<std::vector<float>>> block_1_b(1, std::vector<std::vector<float> >(1, std::vector<float>(1, 0.0055)));
  //std::vector<std::vector<std::vector<float>>> block_1_b = { { { 0.0055, 0.0055, 0.0055 }, { 0.0055, 0.0055, 0.0055 } },
															//{ { 0.0055, 0.0055, 0.0055 }, { 0.0055, 0.0055, 0.0055 } } };                                       
 
  /*for(int i = 0; i < 100; i++){
  block_1_b[0][0].push_back(0.0055);*/
 

  float b_test = 0.0055;                                                              
  //b[{1, 1}] = block_1_b;

  std::map<std::pair<size_t, size_t>, std::vector<std::vector<std::vector<float>>>> c;
  std::vector<std::vector<std::vector<float>>> block_1_c(1, std::vector<std::vector<float> >(1, std::vector<float>(1, 0.0206)));
  //std::vector<std::vector<std::vector<float>>> block_1_c = { { { 0.0206, 0.0206, 0.0206 }, { 0.0206, 0.0206, 0.0206 } },
															//{ { 0.0206, 0.0206, 0.0206 }, { 0.0206, 0.0206, 0.0206 } } }; 															
  /*for(int i = 0; i < 100; i++){
  block_1_c[0][0].push_back(0.0206);*/
  														 
  float c_test = 0.0206;                                                            
  //c[{1, 1}] = block_1_c;
  
  digitizer->SetCsIEdepError(a_test, b_test, c_test);
  //digitizer->SetCsIEdepError(a, b, c);

  digitizer->SetCsITimeError(0.);
  digitizer->SetLaBrLC(1.);
  digitizer->SetLaBrEdepError(0.0,0.04,0.02);
  digitizer->SetLaBrTimeError(0.);

  Int_t multiplicity = 6;
  digitizer->SetGammasMultiplicity(multiplicity);
  digitizer->SetShapingTime(3.84);
  digitizer->SetSignalsInterval(4.);
  digitizer->SetPoissonCs(2.);
  digitizer->SetPoissonCo(4.);
  run->AddTask(digitizer);
	
  // -----   Create PrimaryGenerator   --------------------------------------
   FairPrimaryGenerator* primGen = new FairPrimaryGenerator();
  //Изотропно в ЛАБ системе
  Int_t pdgId = 22; // gamma
  Double_t mass = TDatabasePDG::Instance()->GetParticle(pdgId)->Mass();

  Double32_t kin_energy_Cs = .6617 * 1e-3; //GeV
  Double32_t momentum_Cs = kin_energy_Cs; //GeV
  
  FairBoxGenerator* Cs_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Cs_boxGen->SetThetaRange(theta_min, theta_max);
  Cs_boxGen->SetPRange(momentum_Cs, momentum_Cs);
  Cs_boxGen->SetPhiRange(phi_min,phi_max);
  Cs_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);
  //Cs_boxGen->SetBoxXYZ (0.,-10.,0.,-10.,0.);
  primGen->AddGenerator(Cs_boxGen);

  Double32_t kin_energy_Co1 = 1.173 * 1e-3;
  Double32_t momentum_Co1 = kin_energy_Co1;
 
  FairBoxGenerator* Co1_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Co1_boxGen->SetThetaRange(theta_min, theta_max);
  Co1_boxGen->SetPRange(momentum_Co1, momentum_Co1);
  Co1_boxGen->SetPhiRange(phi_min,phi_max);
  Co1_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);
  primGen->AddGenerator(Co1_boxGen);

  Double32_t kin_energy_Co2 = 1.3325 * 1e-3;
  Double32_t momentum_Co2 = kin_energy_Co2;
  
  FairBoxGenerator* Co2_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Co2_boxGen->SetThetaRange(theta_min, theta_max);
  Co2_boxGen->SetPRange(momentum_Co2, momentum_Co2);
  Co2_boxGen->SetPhiRange(phi_min,phi_max);
  Co2_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);
  primGen->AddGenerator(Co2_boxGen);
  
  /*Double32_t kin_energy_K40 = 1.461 * 1e-3;
  Double32_t momentum_K40 = kin_energy_K40;
  
  FairBoxGenerator* K40_boxGen = new FairBoxGenerator(pdgId, 500);
  K40_boxGen->SetThetaRange(theta_min, theta_max);
  K40_boxGen->SetPRange(kin_energy_K40, kin_energy_K40);
  K40_boxGen->SetPhiRange(phi_min,phi_max);
  K40_boxGen->SetBoxXYZ (-100.,-100.,100.,100.,depthK40);
  primGen->AddGenerator(K40_boxGen);*/  
  
  run->SetGenerator(primGen);
  // ------------------------------------------------------------------------
	
  //-------Set visualisation flag to true------------------------------------
  run->SetStoreTraj(kFALSE);
	
  //-------Set LOG verbosity  ----------------------------------------------- 
  FairLogger::GetLogger()->SetLogVerbosityLevel("HIGH");
  FairLogger::GetLogger()->SetLogScreenLevel("INFO");
  // -----   Initialize simulation run   ------------------------------------
  run->Init();
  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo* parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();

  rtdb->print();
  // ---------------------------------------------------------
  
  // -----   Run simulation  ------------------------------------------------
  run->Run(nEvents);

  //TString geometryName = "setup.root";
  //run->CreateGeometryFile(geometryName.Data());
  
  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  std::cout << std::endl << std::endl;
  std::cout << "Macro finished succesfully." << std::endl;
  std::cout << "Output file is sim_upd_lc.root" << std::endl;
  std::cout << "Parameter file is par_upd.root" << std::endl;
  std::cout << "Real time " << rtime << " s, CPU time " << ctime
		  << "s" << std::endl << std::endl;

}

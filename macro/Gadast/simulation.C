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

#endif

void simulation(int nEvents = 1,TString geometry_file_name = "gadast_test2021.gdml", Double32_t theta_min = 0, 
Double32_t theta_max = 180, Double32_t phi_min = 0, Double32_t phi_max = 360, TString file_name = "sim.root")
{
  //---------------------Files-----------------------------------------------
  TString outFile= file_name;
  TString parFile= "ParametersROOT/par_"+file_name;
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

  // -----   Create PrimaryGenerator   --------------------------------------
   FairPrimaryGenerator* primGen = new FairPrimaryGenerator();
  //Изотропно в ЛАБ системе
  Int_t multiplicity = 4;
  Int_t pdgId = 22; // gamma PID
  Double_t mass = TDatabasePDG::Instance()->GetParticle(pdgId)->Mass();

  Double32_t kin_energy_Cs = .6617 * 1e-3; //GeV
  Double32_t momentum_Cs = kin_energy_Cs; //GeV
  
  FairBoxGenerator* Cs_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Cs_boxGen->SetThetaRange(theta_min, theta_max);
  Cs_boxGen->SetPRange(momentum_Cs, momentum_Cs);
  Cs_boxGen->SetPhiRange(phi_min,phi_max);
  //Position on the top of the passive crystal, opposing the active one (sources on a holder)
  //Cs_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);

  Double32_t kin_energy_Co1 = 1.173 * 1e-3;
  Double32_t momentum_Co1 = kin_energy_Co1;
 
  FairBoxGenerator* Co1_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Co1_boxGen->SetThetaRange(theta_min, theta_max);
  Co1_boxGen->SetPRange(momentum_Co1, momentum_Co1);
  Co1_boxGen->SetPhiRange(phi_min,phi_max);
  //Co1_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);

  Double32_t kin_energy_Co2 = 1.3325 * 1e-3;
  Double32_t momentum_Co2 = kin_energy_Co2;
  
  FairBoxGenerator* Co2_boxGen = new FairBoxGenerator(pdgId, multiplicity);
  Co2_boxGen->SetThetaRange(theta_min, theta_max);
  Co2_boxGen->SetPRange(momentum_Co2, momentum_Co2);
  Co2_boxGen->SetPhiRange(phi_min,phi_max);
  //Co2_boxGen->SetBoxXYZ (0.,-1.875,0.,-1.875,3.95);
  TString sourcePlace = "Side";
  if(sourcePlace == "Side")
  {
    //Position that is opposing the side face of the active detector (sources on a holder)
    Cs_boxGen->SetBoxXYZ(0.,-5.,0.,-5.,-0.95);
    Co1_boxGen->SetBoxXYZ(0.,-5.,0.,-5.,-0.95);
    Co2_boxGen->SetBoxXYZ(0.,-5.,0.,-5.,-0.95);
  }
  else if(sourcePlace == "Front")
  {
    //Position that is opposing the front face of the active detector (sources on a holder)
    Cs_boxGen->SetBoxXYZ (10.,-16.4,10.,-16.4,-0.95);
    Co1_boxGen->SetBoxXYZ (10.,-16.4,10.,-16.4,-0.95);
    Co2_boxGen->SetBoxXYZ (10.,-16.4,10.,-16.4,-0.95);
  }
  else{
    LOG(ERROR) << "Unknown placement of sources!" << FairLogger::endl;
  }

  primGen->AddGenerator(Cs_boxGen);
  primGen->AddGenerator(Co1_boxGen);
  primGen->AddGenerator(Co2_boxGen);
 //Simulating background potassium-40 radiation 
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
  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  std::cout << std::endl << std::endl;
  std::cout << "Macro finished succesfully." << std::endl;
  std::cout << "Output file is " << outFile << std::endl;
  std::cout << "Parameter file is " << parFile << std::endl;
  std::cout << "Real time " << rtime << " s, CPU time " << ctime
		  << "s" << std::endl << std::endl;

}

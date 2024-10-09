#if !defined(__CLING__)

#include "TStopwatch.h"

#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairParRootFileIo.h"
#include "FairLogger.h"

#include "ERAlpideDigitizer.h"
#include "ERFootMuSiDigitizer.h"
#include "ERFootMuSiTrackFinder.h"
#include "ERFootMuSiVertexFinder.h"
#include "ERRunAna.h"
#endif

void digi(Int_t nEvents = 100000)
{
  //nEvents = 100000;
  TString appendName = "TestTracks_Alpide_3foot_ranges1000mm";
  TString sim_file = "sim/sim_" + appendName + ".root";
  TString par_file = "par/par_" + appendName + ".root";
  TString digi_file = "digi/digi_" + appendName + ".root";
  TString setup_file = "setup/setup_" + appendName + ".root";
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // -----   Digitization run   -------------------------------------------
  ERRunAna* fRun = ERRunAna::Instance();
  fRun->HoldEventsCount();
  fRun->SetGeomFile(setup_file);
  fRun->SetInputFile(sim_file);
  fRun->SetOutputFile(digi_file);
  // -----   Alpide digitizer   -------------------------------------------
  Int_t verbose = 2; // 1 - only standard log print, 2 - print digi information 
  ERAlpideDigitizer* AlpideDigitizer = new ERAlpideDigitizer();
  //Energy threshold based on the fact that we should lose 10% protons at max
  Double_t energyThreshold = 0.0135;

  AlpideDigitizer->SetEnergyThreshold(energyThreshold); //MeV
  fRun->AddTask(AlpideDigitizer);

  //  ------- FootMuSi Digitizer -------------------------------------------
  ERFootMuSiDigitizer* footMuSiDigitizer = new ERFootMuSiDigitizer(verbose);
  footMuSiDigitizer->SetSiElossThreshold(0.);
  footMuSiDigitizer->SetSiElossSigma(0.);
  footMuSiDigitizer->SetSiTimeSigma(0.);
  fRun->AddTask(footMuSiDigitizer);
  // -----   FootMuSi track finder   -------------------------------------------
  ERFootMuSiTrackFinder* FootMuSiTrackFinder = new ERFootMuSiTrackFinder(verbose);
  //Proton energy cuts
/*   FootMuSiTrackFinder->SetLowerEdepCut(0.02);
  FootMuSiTrackFinder->SetUpperEdepCut(0.15); */

  FootMuSiTrackFinder->SetAngleBetweenHitsCut(0.0035);
  FootMuSiTrackFinder->SetMaxDistanceToPixel(100);

  FootMuSiTrackFinder->SetHitStation("C7_1st_pair", "C7_1st_pair_SingleSi_SSD150_1_X", "C7_1st_pair_SingleSi_SSD150_2_Y");
  FootMuSiTrackFinder->SetHitStation("C7_2nd_pair", "C7_2nd_pair_SingleSi_SSD150_3_X", "C7_2nd_pair_SingleSi_SSD150_4_Y");
  FootMuSiTrackFinder->SetHitStation("C7_3rd_pair", "C7_3rd_pair_SingleSi_SSD150_5_X", "C7_3rd_pair_SingleSi_SSD150_6_Y");
  fRun->AddTask(FootMuSiTrackFinder);
  // ------   FootMuSi VertexFinder -----------------------------------------
  ERFootMuSiVertexFinder* FootMuSiVertexFinder = new ERFootMuSiVertexFinder(verbose);
  //FootMuSiVertexFinder->SetTrackDistanceCut(0.001);
  FootMuSiVertexFinder->SetTrackDistanceCut(100.);
  FootMuSiVertexFinder->SetVerticesMergeDistanceCut(0.001);
  fRun->AddTask(FootMuSiVertexFinder);
  // -----------Runtime DataBase info -------------------------------------
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();

  FairParRootFileIo* parInput = new FairParRootFileIo();
  parInput->open(par_file.Data(), "UPDATE");
  rtdb->setFirstInput(parInput);
  //-------Set LOG verbosity  ----------------------------------------------- 
  FairLogger::GetLogger()->SetLogVerbosityLevel("HIGH");
  FairLogger::GetLogger()->SetLogScreenLevel("DEBUG");
  // -----   Initialise and run   --------------------------------------------
  fRun->Init();
  fRun->Run(0, nEvents);
  // ------------------------------------------------------------------------
  rtdb->setOutput(parInput);
  rtdb->saveOutput();

  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  std::cout << std::endl << std::endl;
  std::cout << "Macro finished succesfully." << std::endl;
  std::cout << "Output file writen:  " << digi_file << std::endl;
  std::cout << "Parameter file writen " << par_file << std::endl;
  std::cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << std::endl;
  std::cout << std::endl;
  // ------------------------------------------------------------------------

}
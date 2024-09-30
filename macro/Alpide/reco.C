#if !defined(__CLING__)

#include "TString.h"
#include "TSystem.h"
#include "TStopwatch.h"

#include "FairRuntimeDb.h"
#include "FairParRootFileIo.h"

#include "ERRunAna.h"
#include "ERFootMuSiTrackFinder.h"
#include "ERFootMuSiVertexFinder.h"
#include "ERFootMuSiPID.h"
#include "ERFootMuSiMatcher.h"

#endif

void reco()
{
    //File paths
    TString appendName = "";
    TString inFile = "sim/sim.root" + appendName;
    TString outFile = "reco/reco.root" + appendName;
    TString parFile = "par/reco_par.root" + appendName;
    TString geoFile = "geo/setup_Alpide.root";
    //Open simulation
    TFile* file = TFile::Open(inFile.Data());
    TTree* tree = (TTree*)file->Get("er");
    Int_t nEvents = tree->GetEntriesFast();

  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // -----   Digitization run   ---------------------------------------------
  ERRunAna *run = ERRunAna::Instance();
  run->HoldEventsCount(); // forbid different entry number in the input and output file

  // run->SetUserCut("EventHeader.fTrigger==1");
  run->SetGeomFile(geoFile);
  run->SetInputFile(inFile);
  run->SetOutputFile(outFile);
  // ------------------------------------------------------------------------
  // ------- FootMuSi TrackFinder -------------------------------------------
Int_t verbose = 1; // 1 - only standard log print, 2 - print digi information 
ERFootMuSiTrackFinder* FootMuSiTrackFinder = new ERFootMuSiTrackFinder(verbose);
//FootMuSiTrackFinder->SetAngleBetweenHitsCut(0.002);
//Helium-3 energy cuts
/* FootMuSiTrackFinder->SetLowerEdepCut(0.2);
FootMuSiTrackFinder->SetUpperEdepCut(0.4); */
//Proton energy cuts
FootMuSiTrackFinder->SetLowerEdepCut(0.02);
FootMuSiTrackFinder->SetUpperEdepCut(0.15);
//Carbon-9 energy cuts
/* FootMuSiTrackFinder->SetLowerEdepCut(1.5);
FootMuSiTrackFinder->SetUpperEdepCut(6.); */

FootMuSiTrackFinder->SetAngleBetweenHitsCut(0.025);
//FootMuSiTrackFinder->SetAngleBetweenHitsCut(3.14);
FootMuSiTrackFinder->SetHitStation("C7_1st_pair", "C7_1st_pair_SingleSi_SSD150_1_X", "C7_1st_pair_SingleSi_SSD150_2_Y");
FootMuSiTrackFinder->SetHitStation("C7_2nd_pair", "C7_2nd_pair_SingleSi_SSD150_3_X", "C7_2nd_pair_SingleSi_SSD150_4_Y");
FootMuSiTrackFinder->SetHitStation("C7_3rd_pair", "C7_3rd_pair_SingleSi_SSD150_5_X", "C7_3rd_pair_SingleSi_SSD150_6_Y");
FootMuSiTrackFinder->SetHitStation("C7_4th_pair", "C7_4th_pair_SingleSi_SSD150_5_X", "C7_4th_pair_SingleSi_SSD150_6_Y");
run->AddTask(FootMuSiTrackFinder);
// ------   FootMuSi VertexFinder -----------------------------------------
ERFootMuSiVertexFinder* FootMuSiVertexFinder = new ERFootMuSiVertexFinder(verbose);
//FootMuSiVertexFinder->SetTrackDistanceCut(0.001);
FootMuSiVertexFinder->SetTrackDistanceCut(100.);
FootMuSiVertexFinder->SetVerticesMergeDistanceCut(0.001);
run->AddTask(FootMuSiVertexFinder);

FairLogger::GetLogger()->SetLogScreenLevel("DEBUG");
  // -----------Runtime DataBase info ---------------------------------------
FairRuntimeDb* rtdb = run->GetRuntimeDb();
FairParRootFileIo*  parIO = new FairParRootFileIo();
parIO->open(parFile.Data(), "UPDATE");
rtdb->print();
  
run->Init();
run->Run(0,nEvents);


  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  std::cout << std::endl << std::endl;
  std::cout << "Macro finished succesfully." << std::endl;
  std::cout << "Output file writen:  "    << outFile << std::endl;
  std::cout << "Parameter file writen " << parFile << std::endl;
  std::cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << std::endl;
  std::cout << std::endl;
  // ------------------------------------------------------------------------
}

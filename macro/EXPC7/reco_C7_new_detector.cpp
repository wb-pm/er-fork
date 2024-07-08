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
void reco_C7_new_detector()
{
  //---------------------Files-----------------------------------------------
  TString appendName = "twoProtons_cuts10meters_spreadBeam.root";
  TString inFile = "outputFootMuSi/CorrectedBeam/" + appendName;
  TString outFile = "outputFootMuSi/CorrectedBeam/reco_edepCutProtons_AngleCut0p025_verticiesDistanceCut_" + appendName;
  TString parFile = "parametersFootMuSi/par_" + appendName;

  TFile *file = TFile::Open(inFile.Data());
  TTree *tree = (TTree *)file->Get("er");
  Int_t nEvents = tree->GetEntriesFast();
//  nEvents = 500;
   TString geoFile = "outputFootMuSi/CorrectedBeam/setup_threeStraightPairs.root";
/*   TString geoFile = inFile;
  Ssiz_t p1 = geoFile.Last('/');
  geoFile.Insert(p1 + 1, "setup_"); */

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
FootMuSiTrackFinder->SetHitStation("C7_first_pair", "C7_first_pair_SingleSi_SSD150_1_X", "C7_first_pair_SingleSi_SSD150_2_Y");
FootMuSiTrackFinder->SetHitStation("C7_second_pair", "C7_second_pair_SingleSi_SSD150_3_X", "C7_second_pair_SingleSi_SSD150_4_Y");
FootMuSiTrackFinder->SetHitStation("C7_third_pair", "C7_third_pair_SingleSi_SSD150_5_X", "C7_third_pair_SingleSi_SSD150_6_Y");
run->AddTask(FootMuSiTrackFinder);
// ------   FootMuSi VertexFinder -----------------------------------------
ERFootMuSiVertexFinder* FootMuSiVertexFinder = new ERFootMuSiVertexFinder(verbose);
//FootMuSiVertexFinder->SetTrackDistanceCut(0.001);
FootMuSiVertexFinder->SetTrackDistanceCut(100.);
FootMuSiVertexFinder->SetVerticesMergeDistanceCut(0.001);
run->AddTask(FootMuSiVertexFinder);
  // ------------------------------------------------------------------------
// ------   FootMuSi Matcher -----------------------------------------
/* ERFootMuSiMatcher* FootMuSiMatcher = new ERFootMuSiMatcher(verbose);
run->AddTask(FootMuSiMatcher); */
  // ------   FootMuSi TrackPID -----------------------------------------
/* ERFootMuSiPID* FootMuSiPID = new ERFootMuSiPID(verbose);
Double_t normalizedThickness = 0.015; // [cm]

FootMuSiPID->SetParticle("C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y", 1000010010, "SSD150_1", {"SSD150_1","SSD150_2","SSD150_3","SSD150_4","SSD150_5","SSD150_6"}, normalizedThickness, {});
FootMuSiPID->SetParticle("C7_first_pair_SingleSi_SSD150_1_XC7_first_pair_SingleSi_SSD150_2_Y", 1000020030, "SSD150_1", {"SSD150_1","SSD150_2","SSD150_3","SSD150_4","SSD150_5","SSD150_6"}, normalizedThickness, {});
FootMuSiPID->SetEdepAccountingStrategy("1_X", ERFootMuSiPID::EdepAccountingStrategy::EdepFromXChannel);
run->AddTask(FootMuSiPID); */
  
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
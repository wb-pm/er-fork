#if !defined(__CLING__)


#include "ERALPIDE.h"

#include "TSystem.h"
#include "TStopwatch.h"

#include "FairPrimaryGenerator.h"
#include "FairParRootFileIo.h"

#include "ERRunSim.h"
#include "ERDecay7CEventHeader.h"
#include "ERCave.h"
#include "ERTarget.h"
#include "ERIonMixGenerator.h"
#include "ERDecay7C.h"
#endif

void sim(Int_t nEvents = 50)
{
    // File names
    TString workDirPath = gSystem->Getenv("VMCWORKDIR");
    TString outFile = "sim/sim.root";
    TString decayDatFile = workDirPath + "/input/generators/PureDecay7C.txt";
    TString parFile = "par/par.root";

    TString targetGeoFileName = workDirPath + "/geometry/target_9Be_5cm_geo.root";
    ;
    // -----   Timer   --------------------------------------------------------
    TStopwatch timer;
    timer.Start();
  // -----   Create simulation run   ----------------------------------------
  ERRunSim *run = new ERRunSim();
  /** Select transport engine
   * TGeant3
   * TGeant4
   *    **/
  run->SetName("TGeant4");            // Transport engine
  run->SetOutputFile(outFile.Data()); // Output file
  // ------------------------------------------------------------------------
  // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb *rtdb = run->GetRuntimeDb();
  //-------- Set MC event header --------------------------------------------
  ERDecay7CEventHeader *decayMCheader = new ERDecay7CEventHeader();
  run->SetMCEventHeader(decayMCheader);
  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo");
  // -----   Create cave  ----------------------------------------------
  FairModule *cave = new ERCave("CAVE");
  cave->SetGeometryFileName("cave_small.geo");
  run->AddModule(cave);
  // -----   Create target  -------------------------------------------------
  FairModule *target = new ERTarget("target", kTRUE, 1);
  target->SetGeometryFileName(targetGeoFileName);
  run->AddModule(target);
  // -----   Create ALPIDE detector  --------------------------------------------
  ERALPIDE *ALPIDE = new ERALPIDE("ERALPIDE",kTRUE,2);
  ALPIDE->SetGeometryFileName(workDirPath + "/geometry/ALPIDE_nochips.geo.root");
  ALPIDE->SetStoreSteps();
  run->AddModule(ALPIDE);
  //----------  Generate initial beam --------------------------------------------
  FairPrimaryGenerator *primGen = new FairPrimaryGenerator();

  Double_t kinE_MevPerNucleon = 600.;
  Double_t beamStartPosition = -10.;
  Int_t Z = 6, A = 9, Q = 6;
  TString ionName = "9C";
  ERIonMixGenerator *generator = new ERIonMixGenerator(ionName, Z, A, Q, 1);

  Double32_t kin_energy = kinE_MevPerNucleon * 1e-3 * A; // GeV
  generator->SetKinE(kin_energy);
  generator->SetPSigmaOverP(0.);
  generator->SetThetaSigma(0., 0.5); //for now there is a fixed 0 degree angle in the ERIonGenerator
  // generator->SetPhiRange(0, 45);
  //generator->SetBoxXYZ(0, 0, 0., 0., beamStartPosition);
  generator->SetRoundXY(2.,0.,0.,beamStartPosition); // задает ограничение размытия пятна пучка на мишени

  // generator->SpreadingOnTarget(); 				//Sets spreading of x and y coordinates on target (where z-position is zero)
  primGen->AddGenerator(generator);
  run->SetGenerator(primGen);
  // ------- Decayer --------------------------------------------------------

  ERDecayer *decayer = new ERDecayer();
  ERDecay7C *targetDecay = new ERDecay7C();

  TString interactionVol = "target9BeVol";

  Double_t target_thickness = 5.;

  targetDecay->SetInteractionVolumeName(interactionVol);
  targetDecay->SetMinStep(1e-2);
  targetDecay->SetDecayFile(decayDatFile.Data());
  // InteractionLength = 5-10 * MaxPathLength in cm
  // MaxPathLength = 105% target thickness in cm
  targetDecay->SetNuclearInteractionLength(target_thickness * 1.05 * 10);
  targetDecay->SetMaxPathLength(target_thickness * 1.05);

  decayer->AddDecay(targetDecay);
  run->SetDecayer(decayer);
  //-------Set visualisation flag to true------------------------------------
  run->SetStoreTraj(kFALSE);

  //-------Set LOG verbosity  -----------------------------------------------
  FairLogger::GetLogger()->SetLogScreenLevel("DEBUG"); // для отладки
  // -----   Initialize simulation run   ------------------------------------
  run->Init();
  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo *parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();

  TString setup_name = "geo/setup_alpide.root"; 
  run->CreateGeometryFile(setup_name);

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
       << "s" << std::endl
       << std::endl;
}
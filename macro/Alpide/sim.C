#if !defined(__CLING__)


#include "ERAlpide.h"

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
#include "ERFootMuSiSetup.h"
#include "ERFootMuSiGeoComponentSingleSi.h"
#include "ERFootMuSi.h"
#endif

void sim(Int_t nEvents = 100000)
{
  TString workDirPath = gSystem->Getenv("VMCWORKDIR");
  TString nameAppend = "UniformDecayerTest_Alpide_3foot_ranges1000mm";
  //Simulation output
  TString outFile = "sim/sim_"+nameAppend+".root";
  //Decay products file
  TString decayDatFile = workDirPath + "/input/generators/Decay7C.dat";
  //Output parameters
  TString parFile = "par/par_"+nameAppend+".root";
  //FOOT detector setup
  TString paramFileFootMuSi = workDirPath + "/db/footMuSi/footMuSiParts_7C.xml";
  //Target geometry
  TString targetGeoFileName = workDirPath + "/geometry/target_9Be_5cm_geo.root";
  //Output geometry setup
  TString setup_name = "setup/setup_"+nameAppend+".root";

  //-------Set LOG verbosity  -----------------------------------------------
  FairLogger::GetLogger()->SetLogScreenLevel("DEBUG"); // для отладки
  FairLogger::GetLogger()->SetLogVerbosityLevel("HIGH");
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // -----   Create simulation run   ----------------------------------------
  ERRunSim* run = new ERRunSim();
  /** Select transport engine
   * TGeant3
   * TGeant4
   *    **/
  run->SetName("TGeant4");            // Transport engine
  run->SetOutputFile(outFile.Data()); // Output file
  // ------------------------------------------------------------------------
  // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  //-------- Set MC event header --------------------------------------------
  ERDecay7CEventHeader* decayMCheader = new ERDecay7CEventHeader();
  run->SetMCEventHeader(decayMCheader);
  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo");
  Int_t detectorVerbosity = 2;
  // -----   Create cave  ----------------------------------------------
  FairModule* cave = new ERCave("CAVE");
  cave->SetGeometryFileName("cave_small.geo");
  run->AddModule(cave);
  // -----   Create target  -------------------------------------------------
  FairModule* target = new ERTarget("target", kTRUE, detectorVerbosity);
  target->SetGeometryFileName(targetGeoFileName);
  run->AddModule(target);
  // -----   Create Alpide detector  --------------------------------------------
  ERAlpide* Alpide = new ERAlpide("ERAlpide", kTRUE, detectorVerbosity);
  Alpide->SetGeometryFileName(workDirPath + "/geometry/Alpide_nochips.geo.root");
  //Alpide->SetStoreSteps();
  run->AddModule(Alpide);
  //----------  Create FOOT detector --------------------------------------------
  ERFootMuSiSetup* setupFootMuSi = ERFootMuSiSetup::Instance();
  setupFootMuSi->SetXMLParametersFile(paramFileFootMuSi);
  setupFootMuSi->SetGeoName("FootMuSiTmp");
  //----------  FOOT stations placement --------------------------------------------
  Double_t x, y, z_pair, z_stations, z;
  x = 0.;
  y = 0.;
  z = 17.;
  z_pair = 1.;
  z_stations = 7.;
  TVector3 fZeroRotation(0., 0., 0.);

  ERGeoSubAssembly* C7_1st_pair = new ERGeoSubAssembly("C7_1st_pair", TVector3(x, y, z), fZeroRotation);
  ERGeoSubAssembly* C7_2nd_pair = new ERGeoSubAssembly("C7_2nd_pair", TVector3(x, y, z + z_pair + z_stations), fZeroRotation);
  ERGeoSubAssembly* C7_3rd_pair = new ERGeoSubAssembly("C7_3rd_pair", TVector3(x, y, z + 2 * z_pair + 2 * z_stations), fZeroRotation);
  ERGeoSubAssembly* C7_4th_pair = new ERGeoSubAssembly("C7_4th_pair", TVector3(x, y, z + 3 * z_pair + 3 * z_stations), fZeroRotation);

  ERFootMuSiGeoComponentSingleSi* det_C7_X1 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_1", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi* det_C7_Y1 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_2", TVector3(0., 0., z_pair), TVector3(), "Y");
  ERFootMuSiGeoComponentSingleSi* det_C7_X2 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_3", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi* det_C7_Y2 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_4", TVector3(0., 0., z_pair), TVector3(), "Y");
  ERFootMuSiGeoComponentSingleSi* det_C7_X3 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_5", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi* det_C7_Y3 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_6", TVector3(0., 0., z_pair), TVector3(), "Y");
  ERFootMuSiGeoComponentSingleSi* det_C7_X4 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_7", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi* det_C7_Y4 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_8", TVector3(0., 0., z_pair), TVector3(), "Y");
  C7_1st_pair->AddComponent(det_C7_X1);
  C7_1st_pair->AddComponent(det_C7_Y1);
  C7_2nd_pair->AddComponent(det_C7_X2);
  C7_2nd_pair->AddComponent(det_C7_Y2);
  C7_3rd_pair->AddComponent(det_C7_X3);
  C7_3rd_pair->AddComponent(det_C7_Y3);
  C7_4th_pair->AddComponent(det_C7_X4);
  C7_4th_pair->AddComponent(det_C7_Y4);

  setupFootMuSi->AddSubAssembly(C7_1st_pair);
  setupFootMuSi->AddSubAssembly(C7_2nd_pair);
  setupFootMuSi->AddSubAssembly(C7_3rd_pair);
  //Currently working with 3 pairs
/*   setupFootMuSi->AddSubAssembly(C7_4th_pair); */
  // ------FootMuSi -------------------------------------------------------
  ERFootMuSi* footMuSi = new ERFootMuSi("ERFootMuSi", kTRUE, detectorVerbosity);
  run->AddModule(footMuSi);
  //-------------------------------------------------------------------------

  //----------  Generate initial beam --------------------------------------------
  FairPrimaryGenerator* primGen = new FairPrimaryGenerator();

  Double_t kinE_MevPerNucleon = 600.;
  Double_t beamStartPosition = -10.;
  Int_t Z = 6, A = 9, Q = 6;
  TString ionName = "9C";
  ERIonGenerator* generator9C = new ERIonGenerator(ionName, Z, A, Q, 1);

  Double32_t kin_energy = kinE_MevPerNucleon * 1e-3 * A; // GeV
  generator9C->SetKinE(kin_energy);
  generator9C->SetPSigmaOverP(0.);
  generator9C->SetThetaSigma(0., 0.5); //for now there is a fixed 0 degree angle in the ERIonGenerator
  // generator9C->SetPhiRange(0, 45);
  //generator9C->SetBoxXYZ(0, 0, 0., 0., beamStartPosition);
  generator9C->SetRoundXY(2., 0., 0., beamStartPosition); // задает ограничение размытия пятна пучка на мишени
  //generator9C->SetPDGType()

  // generator9C->SpreadingOnTarget(); 				//Sets spreading of x and y coordinates on target (where z-position is zero)
  primGen->AddGenerator(generator9C);
  run->SetGenerator(primGen);
  // ------- Decayer --------------------------------------------------------

  ERDecayer* decayer = new ERDecayer();
  ERDecay7C* targetDecay = new ERDecay7C();

  TString interactionVol = "target9BeVol";

  Double_t target_thickness = 5.;

  targetDecay->Set7CUniformExcitation(0.,20.);
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
  // -----   Initialize simulation run   ------------------------------------
  run->Init();
  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo* parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data(),"RECREATE");
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();

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
  //TODO: Strange error after the simulation is finished, check the reason
  // ***Error in `/opt/FairSoft/bin/root.exe': free(): invalid pointer: 0x0000000003749d90 ***

}
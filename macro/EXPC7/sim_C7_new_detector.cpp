#if !defined(__CLING__)
#include "TString.h"
#include "TSystem.h"
#include "TStopwatch.h"

#include "FairPrimaryGenerator.h"
#include "FairParRootFileIo.h"

#include "ERRunSim.h"
#include "ERCave.h"
#include "ERTarget.h"
#include "ERFootMuSi.h"
#include "ERFootMuSiSetup.h"
#include "ERFootMuSiGeoComponentSingleSi.h"
#include "ERFootMuSiDigitizer.h"
#include "ERIonMixGenerator.h"
#include "ERDecay7C.h"
#include "ERDecay7CEventHeader.h"

#endif

void sim_C7_new_detector(Int_t nEvents = 10000)
{
  Double_t beamStartPosition = -10.; // [cm]
  //now should create a simulation with spread beam
  TString appendName = "spread_beam_tracks_into_single_branch_twoprotons_1mm_cuts.root";
  TString outFile = "outputFootMuSi/" + appendName;
  TString decayDatFile = "input/PureDecay7C.txt";
  TString parFile = "parametersFootMuSi/par_" + appendName;
  TString workDirPath = gSystem->Getenv("VMCWORKDIR");

  TString paramFileFootMuSi = workDirPath + "/db/footMuSi/footMuSiParts_7C.xml";

  TString targetGeoFileName = workDirPath + "/geometry/target_9Be_5cm_geo.root";

  TString interactionVol = "target9BeVol";

  Double_t target_thickness = 5.;

  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // ------------------------------------------------------------------------
  // -----   Create simulation run   ----------------------------------------
  ERRunSim *run = new ERRunSim();
  /** Select transport engine
   * TGeant3
   * TGeant4exp1904_sim_digi.C
   **/
  run->SetName("TGeant4");            // Transport engine
  run->SetOutputFile(outFile.Data()); // Output file
  // ------------------------------------------------------------------------
  // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb *rtdb = run->GetRuntimeDb();
  //-------- Set MC event header --------------------------------------------
  ERDecay7CEventHeader *decayMCheader = new ERDecay7CEventHeader();
  run->SetMCEventHeader(decayMCheader);
  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo"); // Materials
  // -----   Create detectors  ----------------------------------------------
  FairModule *cave = new ERCave("CAVE");
  cave->SetGeometryFileName("cave_small.geo");
  run->AddModule(cave);

  Int_t verbose = 0;
  // -----   Create target  -------------------------------------------------
  FairModule *target = new ERTarget("target", kTRUE, 1);
  target->SetGeometryFileName(targetGeoFileName);
  run->AddModule(target);
  
  // Trying to implement the functionality of obtaining target thickness from the list of modules
  // TList* moduleList = (TList*)run->GetListOfModules();
  



  // -----  FootMuSi Setup ------------------------------------------------
  ERFootMuSiSetup *setupFootMuSi = ERFootMuSiSetup::Instance();
  setupFootMuSi->SetXMLParametersFile(paramFileFootMuSi);
  setupFootMuSi->SetGeoName("FootMuSiTmp");

  // ----- square telescope parameters ----------------------------------------------------
  Double_t x, y, z_pair, z_stations, z;
  x = 0.;
  y = 0.;
  z = 20.;
  z_pair = 1.;
  z_stations = 15.;
  TVector3 fZeroRotation(0., 0., 0.);

  ERGeoSubAssembly *C7_first_pair = new ERGeoSubAssembly("C7_first_pair", TVector3(x,y,z),fZeroRotation);
  ERGeoSubAssembly *C7_second_pair = new ERGeoSubAssembly("C7_second_pair", TVector3(x,y,z+z_pair+z_stations),fZeroRotation);
  ERGeoSubAssembly *C7_third_pair = new ERGeoSubAssembly("C7_third_pair", TVector3(x,y,z + 2*z_pair+2*z_stations),fZeroRotation);

  ERFootMuSiGeoComponentSingleSi *det_C7_X1 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_1", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi *det_C7_Y1 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_2",  TVector3(0., 0., z_pair), TVector3(), "Y");
  ERFootMuSiGeoComponentSingleSi *det_C7_X2 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_3", TVector3(0., 0.,0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi *det_C7_Y2 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_4", TVector3(0., 0., z_pair), TVector3(), "Y");
  ERFootMuSiGeoComponentSingleSi *det_C7_X3 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_5", TVector3(0., 0., 0.), TVector3(), "X");
  ERFootMuSiGeoComponentSingleSi *det_C7_Y3 = new ERFootMuSiGeoComponentSingleSi("SingleSi", "SingleSi_SSD150_6", TVector3(0., 0., z_pair), TVector3(), "Y");
  C7_first_pair->AddComponent(det_C7_X1);
  C7_first_pair->AddComponent(det_C7_Y1);
  C7_second_pair->AddComponent(det_C7_X2);
  C7_second_pair->AddComponent(det_C7_Y2);
  C7_third_pair->AddComponent(det_C7_X3);
  C7_third_pair->AddComponent(det_C7_Y3);

  setupFootMuSi->AddSubAssembly(C7_first_pair);
  setupFootMuSi->AddSubAssembly(C7_second_pair);
  setupFootMuSi->AddSubAssembly(C7_third_pair);
  // ------FootMuSi -------------------------------------------------------
  ERFootMuSi *footMuSi = new ERFootMuSi("ERFootMuSi", kTRUE, verbose);
  run->AddModule(footMuSi);
  //-------------------------------------------------------------------------
  FairPrimaryGenerator *primGen = new FairPrimaryGenerator();

  Double_t kinE_MevPerNucleon = 600.;

  Int_t Z = 6, A = 9, Q = 6;
  TString ionName = "9C";
  ERIonMixGenerator *generator = new ERIonMixGenerator(ionName, Z, A, Q, 1);

  Double32_t kin_energy = kinE_MevPerNucleon * 1e-3 * A; // GeV
  generator->SetKinE(kin_energy);
  generator->SetPSigmaOverP(0.);
  generator->SetThetaSigma(0., 0.5); //for now there is a fixed 0 degree angle in the ERIonGenerator
  // generator->SetPhiRange(0, 45);
  //generator->SetBoxXYZ(0, 0, 0., 0., beamStartPosition);
  generator->SetRoundXY(2.); // задает ограничение размытия пятна пучка на мишени

  // generator->SpreadingOnTarget(); 				//Sets spreading of x and y coordinates on target (where z-position is zero) and
  // reconstruct them to the beam start position (to settes z-coordinate) along momentum vector.
  // By default spreading of x and y coordinates implements on setted z-coordinate.

  primGen->AddGenerator(generator);
  run->SetGenerator(primGen);
  /////////////////////////////////////////////////////////////////////////////
  // ------- Decayer --------------------------------------------------------

  ERDecayer *decayer = new ERDecayer();
  ERDecay7C *targetDecay = new ERDecay7C();

  targetDecay->SetInteractionVolumeName(interactionVol);
  targetDecay->SetMinStep(1e-2);
  targetDecay->SetDecayFile(decayDatFile.Data());
  // InteractionLength = 5-10 * MaxPathLength in cm
  // MaxPathLength = 105% target thickness in cm
  targetDecay->SetNuclearInteractionLength(target_thickness * 1.05 * 10);
  targetDecay->SetMaxPathLength(target_thickness * 1.05);

  decayer->AddDecay(targetDecay);
  run->SetDecayer(decayer);
  //  ------- FootMuSi Digitizer -------------------------------------------
  ERFootMuSiDigitizer *footMuSiDigitizer = new ERFootMuSiDigitizer(verbose);
  footMuSiDigitizer->SetSiElossThreshold(0.);
  footMuSiDigitizer->SetSiElossSigma(0.);
  footMuSiDigitizer->SetSiTimeSigma(0.);
  run->AddTask(footMuSiDigitizer);
  //-------Set visualisation flag to true------------------------------------
  run->SetStoreTraj(kTRUE);

  //-------Set LOG verbosity  -----------------------------------------------
  //FairLogger::GetLogger()->SetLogScreenLevel("INFO");
  FairLogger::GetLogger()->SetLogScreenLevel("DEBUG"); // для отладки

  // -----   Initialize simulation run   ------------------------------------
  run->Init();
  //Int_t nSteps = -15000;
  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo *parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();

  TString setup_name = outFile;
  Ssiz_t p1 = setup_name.First("/");
  setup_name.Insert(p1 + 1, "setup_");
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
  TDatabasePDG *tdb = TDatabasePDG::Instance();
}
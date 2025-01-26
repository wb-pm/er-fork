//Simulation file for a standalone CsI(Tl) crystal of GADAST, scaled to a size of GADAST CsI(Tl) wall. Testing efficiency of the setup at 4 MeV.
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

void sim_one_crystal(int nEvents = 1e5, TString geometry_file_name = "gadast.gdml", Double32_t theta_min = 90,
    Double32_t theta_max = 90, Double32_t phi_min = 180, Double32_t phi_max = 180, TString file_postfix = "default.root")
{
    //---------------------Files-----------------------------------------------
    nEvents = 1e5;
    geometry_file_name = "gadast_single_crystal_large.gdml";
    file_postfix = "test.root";
    TString sim_file = "Efficiency_4MeV/sim_" + file_postfix;
    TString par_file = "Efficiency_4MeV/par_" + file_postfix;
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
    run->SetOutputFile(sim_file.Data());          // Output file
    // ------------------------------------------------------------------------

    // -----   Runtime database   ---------------------------------------------
    FairRuntimeDb* rtdb = run->GetRuntimeDb();
    // ------------------------------------------------------------------------

    // -----   Create media   -------------------------------------------------
    run->SetMaterials("media.geo");       // Materials
    // ------------------------------------------------------------------------

    // -----   Create detectors  ----------------------------------------------	
    FairModule* cave = new ERCave("CAVE");
    cave->SetGeometryFileName("cave.geo");
    run->AddModule(cave);

    ERGadast* gadast = new ERGadast("ERGadast", kTRUE, 1);
    //gadast->SetStoreSteps();
    gadast->SetGeometryFileName(geometry_file_name);
    run->AddModule(gadast);

    // -----   Create PrimaryGenerator   --------------------------------------
    FairPrimaryGenerator* primGen = new FairPrimaryGenerator();
    //Изотропно в ЛАБ системе
    Int_t multiplicity = 1;
    Int_t pdgId = 22; // gamma PID
    Double_t mass = TDatabasePDG::Instance()->GetParticle(pdgId)->Mass();

    Double32_t kin_energy_gamma = 4. * 1e-3; //GeV
    Double32_t momentum_gamma = kin_energy_gamma; //GeV

    FairBoxGenerator* gamma_box_gen = new FairBoxGenerator(pdgId, multiplicity);
    gamma_box_gen->SetThetaRange(theta_min, theta_max);
    gamma_box_gen->SetPRange(momentum_gamma, momentum_gamma);
    gamma_box_gen->SetPhiRange(phi_min, phi_max);
    //gamma_box_gen->SetBoxXYZ(20., 0., 20., 0., 0.);
    //The center of an edge detector
    gamma_box_gen->SetBoxXYZ(20., -15., 20., -15., -22.);
    gamma_box_gen->SetDebug(1);

    primGen->AddGenerator(gamma_box_gen);

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
    parOut->open(par_file.Data(), "RECREATE");
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
    std::cout << "Output file is " << sim_file << std::endl;
    std::cout << "Parameter file is " << par_file << std::endl;
    std::cout << "Real time " << rtime << " s, CPU time " << ctime
        << "s" << std::endl << std::endl;

}

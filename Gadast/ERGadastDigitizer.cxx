#include "ERGadastDigitizer.h"

#include "TVector3.h"
#include "TMath.h"

#include "FairRun.h"
#include "FairRunSim.h"
#include "FairRuntimeDb.h"
#include "FairEventHeader.h"

#include "ERGadastCsIPoint.h"
#include "ERGadastLaBrPoint.h"

#include "TH1.h"

using std::map;
using std::vector;
using std::make_tuple;
using std::tie;
using std::distance;

const Double_t edep_threshold = 0.0001;
//Things TODO:
//1) replace shuffle by two-component vector sorting
//2) Poisson lambda as a function of activity and time window
//3) investigate the possibilty of sampling (Poisson) the number of decays before simulation
// ----------------------------------------------------------------------------
ERGadastDigitizer::ERGadastDigitizer()
  : FairTask("ER Gadast Digitization scheme"),
  fSetup(NULL),
  fCsILC(1.),
  fCsIEdepErrorA(0.),
  fCsIEdepErrorB(0.),
  fCsIEdepErrorC(0.),
  fCsITimeErrorA(0.),
  fLaBrLC(1.),
  fLaBrEdepErrorA(0.),
  fLaBrEdepErrorB(0.),
  fLaBrEdepErrorC(0.),
  fLaBrTimeErrorA(0.),
  fCsIElossThreshold(0.),
  fLaBrElossThreshold(0.),
  fMtGenerator((std::random_device())())
{
}
// ----------------------------------------------------------------------------
ERGadastDigitizer::ERGadastDigitizer(Int_t verbose)
  : FairTask("ER Gadast Digitization scheme ", verbose),
  fSetup(NULL),
  fCsILC(1.),
  fCsIEdepErrorA(0.),
  fCsIEdepErrorB(0.),
  fCsIEdepErrorC(0.),
  fCsITimeErrorA(0.),
  fLaBrLC(1.),
  fLaBrEdepErrorA(0.),
  fLaBrEdepErrorB(0.),
  fLaBrEdepErrorC(0.),
  fLaBrTimeErrorA(0.),
  fCsIElossThreshold(0.),
  fLaBrElossThreshold(0.),
  fMtGenerator((std::random_device())())
{
}
// ----------------------------------------------------------------------------

ERGadastDigitizer::~ERGadastDigitizer()
{
  delete fSetup;
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(Float_t lc)
{
  fCsILCFun = [lc](BlockAddress, size_t, size_t, size_t) {return lc;};
  fCsILCGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(map<BlockAddress, float>& lc)
{
  fCsILCFun = [lc](BlockAddress address, size_t, size_t, size_t) {
    return lc.at(address);
    };
  fCsILCGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(map<BlockAddress, CoefficientMatrix>& lc)
{
  fCsILCFun = [&lc](BlockAddress address, size_t x, size_t y, size_t z) {
    //LOG(DEBUG) << "CsILCFun: wall=" << address.first << ", block=" << address.second << ", x cell=" << x << ", y cell=" << y << ", z cell=" << z << FairLogger::endl;
    return lc.at(address).at(x).at(y).at(z);
    };

  fCsILCGrid = [&lc](BlockAddress address) {
    //LOG(DEBUG) << "fCsILCGrid: wall=" << address.first << ", block=" << address.second << FairLogger::endl;
    const auto& matrix = lc.at(address);
    const size_t x_size = matrix.size();
    const size_t y_size = matrix.at(0).size();
    const size_t z_size = matrix.at(0).at(0).size();
    return make_tuple(x_size, y_size, z_size);
    };
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(Float_t a, Float_t b, Float_t c)
{
  fCsILCAFun = [a](BlockAddress, size_t, size_t, size_t) {return a;};
  fCsILCAGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
  fCsILCBFun = [b](BlockAddress, size_t, size_t, size_t) {return b;};
  fCsILCBGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
  fCsILCCFun = [c](BlockAddress, size_t, size_t, size_t) {return c;};
  fCsILCCGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(map<BlockAddress, float>& a,
  map<BlockAddress, float>& b,
  map<BlockAddress, float>& c) {
  fCsILCAFun = [a](BlockAddress address, size_t, size_t, size_t) {
    return a.at(address);
    };
  fCsILCAGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
  fCsILCBFun = [b](BlockAddress address, size_t, size_t, size_t) {
    return b.at(address);
    };
  fCsILCBGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
  fCsILCCFun = [c](BlockAddress address, size_t, size_t, size_t) {
    return c.at(address);
    };
  fCsILCCGrid = [](BlockAddress) {return make_tuple(1, 1, 1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(map<BlockAddress, CoefficientMatrix>& a,
  map<BlockAddress, CoefficientMatrix>& b,
  map<BlockAddress, CoefficientMatrix>& c) {
  fCsILCAFun = [&a](BlockAddress address, size_t x, size_t y, size_t z) {
    LOG(DEBUG) << "fCsILCAFun: wall=" << address.first << ", block=" << address.second
      << ", x cell=" << x << ", y cell=" << y << ", z cell=" << z << FairLogger::endl;
    return a.at(address).at(x).at(y).at(z);
    };

  fCsILCAGrid = [&a](BlockAddress address) {
    LOG(DEBUG) << "fCsILCAGrid: wall=" << address.first << ", block=" << address.second << FairLogger::endl;
    const auto& matrix = a.at(address);
    const size_t x_size = matrix.size();
    const size_t y_size = matrix.at(0).size();
    const size_t z_size = matrix.at(0).at(0).size();
    return make_tuple(x_size, y_size, z_size);
    };

  fCsILCBFun = [&b](BlockAddress address, size_t x, size_t y, size_t z) {
    LOG(DEBUG) << "fCsILCAFun: wall=" << address.first << ", block=" << address.second
      << ", x cell=" << x << ", y cell=" << y << ", z cell=" << z << FairLogger::endl;
    return b.at(address).at(x).at(y).at(z);
    };

  fCsILCBGrid = [&b](BlockAddress address) {
    LOG(DEBUG) << "fCsILCBGrid: wall=" << address.first << ", block=" << address.second << FairLogger::endl;
    const auto& matrix = b.at(address);
    const size_t x_size = matrix.size();
    const size_t y_size = matrix.at(0).size();
    const size_t z_size = matrix.at(0).at(0).size();
    return make_tuple(x_size, y_size, z_size);
    };

  fCsILCCFun = [&c](BlockAddress address, size_t x, size_t y, size_t z) {
    LOG(DEBUG) << "fCsILCAFun: wall=" << address.first << ", block=" << address.second
      << ", x cell=" << x << ", y cell=" << y << ", z cell=" << z << FairLogger::endl;
    return c.at(address).at(x).at(y).at(z);
    };

  fCsILCCGrid = [&c](BlockAddress address) {
    LOG(DEBUG) << "fCsILCAGrid: wall=" << address.first << ", block=" << address.second << FairLogger::endl;
    const auto& matrix = c.at(address);
    const size_t x_size = matrix.size();
    const size_t y_size = matrix.at(0).size();
    const size_t z_size = matrix.at(0).at(0).size();
    return make_tuple(x_size, y_size, z_size);
    };

}

// ----------------------------------------------------------------------------
void ERGadastDigitizer::SetParContainers()
{
  // Get run and runtime database
  FairRun* run = FairRun::Instance();
  if (!run) Fatal("SetParContainers", "No analysis run");

  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  if (!rtdb) Fatal("SetParContainers", "No runtime database");

  fDigiPar = (ERGadastDigiPar*)
    (rtdb->getContainer("ERGadastDigiPar"));
  if (fVerbose && fDigiPar) {
    LOG(INFO) << "ERGadastDigitizer::SetParContainers() " << FairLogger::endl;
    LOG(INFO) << "ERGadastDigiPar initialized! " << FairLogger::endl;
  }
}
// ----------------------------------------------------------------------------

//----------------------------------------------------------------------------
InitStatus ERGadastDigitizer::Init()
{
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if (!ioman) Fatal("Init", "No FairRootManager");

  fGadastCsIPoints = (TClonesArray*)ioman->GetObject("GadastCsIPoint");
  fGadastLaBrPoints = (TClonesArray*)ioman->GetObject("GadastLaBrPoint");

  // Register output arrays
  fGadastCsIDigi = new TClonesArray("ERGadastCsIDigi", 1000);
  fGadastLaBrDigi = new TClonesArray("ERGadastLaBrDigi", 1000);
  ioman->Register("GadastCsIDigi", "Digital response in Gadast CsI", fGadastCsIDigi, kTRUE);
  ioman->Register("GadastLaBrDigi", "Digital response in Gadast LaBr", fGadastLaBrDigi, kTRUE);
  fSetup = ERGadastSetup::Instance();
  if (!fSetup->Init()) {
    LOG(ERROR) << "Problems with ERGadastSetup initialization!" << FairLogger::endl;
  }
  return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
//----------------------------------------------------------------------------
//New Implementation with pile-up algorithm and Poisson distribution
void ERGadastDigitizer::Exec(Option_t* opt)
{
  FairRootManager* ioman = FairRootManager::Instance();
  if (ioman->GetEntryNr() % 10000 == 0) {
    LOG(INFO) << "Digitization of event number " << ioman->GetEntryNr() << std::endl;
  }
  // Reset entries in output arrays
  Reset();

  // Sort points by sensitive volumes
  // Map points by cells: pointsCsI[iWall][iBlock][iCell]
  map<Int_t, map<Int_t, map <Int_t, vector<Int_t> > > > pointsCsI;

  LOG(DEBUG) << "fGadastCsIPoints contains entries: " << fGadastCsIPoints->GetEntriesFast() << FairLogger::endl;

  for (Int_t iPoint = 0; iPoint < fGadastCsIPoints->GetEntriesFast(); iPoint++) {
    ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
    pointsCsI[point->GetWall()][point->GetBlock()][point->GetCell()].push_back(iPoint);
  }

  LOG(DEBUG) << "fGadastLaBrPoints contains entries: " << fGadastLaBrPoints->GetEntriesFast() << FairLogger::endl;
  // Map points by cells: pointsLaBr[iCell]
  map<Int_t, vector<Int_t> > pointsLaBr;
  for (Int_t iPoint = 0; iPoint < fGadastLaBrPoints->GetEntriesFast(); iPoint++) {
    ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
    pointsLaBr[point->GetCell()].push_back(iPoint);
  }
  //For the debugging purposes let's define a single seed for all of the random generators
  //Generating Poisson distribution values, to determine number of gammas left 
  std::poisson_distribution<int> distribution_Cs(fPoissonCs);
  std::poisson_distribution<int> distribution_Co(fPoissonCo);
  int events_poisson_Cs = distribution_Cs(fMtGenerator);
  int events_poisson_Co = distribution_Co(fMtGenerator);

  for (const auto& itWall : pointsCsI) {
    for (const auto& itBlock : itWall.second) {
      BlockAddress address = std::make_pair(itWall.first, itBlock.first);
      for (const auto& itCell : itBlock.second) {
        Double_t edep = 0.; // sum edep in cell
        Float_t edepSigma = 0.; // sum edep sigma in cell
        //TODO: Change writing this variable into the tree
        Double_t gaus4MeV = 0.; // edep in case of full energy deposition of 4 MeV gamma
        size_t x_countsLCA, y_countsLCA, z_countsLCA;
        tie(x_countsLCA, y_countsLCA, z_countsLCA) = fCsILCAGrid(address);
        //Since the resolution is uniform throughout the crystal, it doesn't make sense to output these values
/*           LOG(DEBUG) << "x_countsLCA: " << x_countsLCA << " y_countsLCA: " << y_countsLCA << " z_countsLCA: " << z_countsLCA << FairLogger::endl;
          LOG(DEBUG) << "x_binLCA: " << x_binLCA << " y_binLCA: " << y_binLCA << " z_binLCA: " << z_binLCA << FairLogger::endl; */
          //A matrix for all of the energy depositions, based on the fact in which part of the crystal it was deposited (and also by which gamma quantum). The size is determined 
        vector<vector<vector<vector<float> > > > separatedenergydeps(x_countsLCA, vector<vector<vector<float> > >(y_countsLCA, vector<vector<float> >(z_countsLCA, vector<float>(fMultiplicity * 3, 0.0))));
        vector<Double_t> energydeps(fMultiplicity * 3, 0.0);
        vector<Double_t> changedenergydeps(fMultiplicity * 3, 0.0);
        vector<Double_t> poissonenergydeps(fMultiplicity * 2, 0.0);
        vector<Double_t> finalenergydeps(fMultiplicity * 2, 0.0);
        Float_t time = std::numeric_limits<float>::max(); // first time in cell

        for (const auto iPoint : itCell.second) {
          ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
          if (point->GetTime() < time)
            time = point->GetTime();
          TVector3 pos;
          point->PositionIn(pos);

          //number of parts with different light collection (for each axis of the crystal)
          size_t x_countsLC, y_countsLC, z_countsLC;
          tie(x_countsLC, y_countsLC, z_countsLC) = fCsILCGrid(address);
          /*           LOG(DEBUG) << "x_countsLC: " << x_countsLC << " y_countsLC: " << y_countsLC << " z_countsLC: " << z_countsLC << FairLogger::endl; */
          size_t x_binLC, y_binLC, z_binLC;
          //part of the crystal with its own LC coefficient, where point energy deposition has occured
          tie(x_binLC, y_binLC, z_binLC) = fSetup->GetCsIMeshElement(&pos, x_countsLC, y_countsLC, z_countsLC);
          LOG(DEBUG) << "x_binLC: " << x_binLC << " y_binLC: " << y_binLC << " z_binLC: " << z_binLC << FairLogger::endl;

          size_t x_binLCA, y_binLCA, z_binLCA;
          tie(x_binLCA, y_binLCA, z_binLCA) = fSetup->GetCsIMeshElement(&pos, x_countsLCA, y_countsLCA, z_countsLCA);
          const float A = fCsILCAFun(address, x_binLCA, y_binLCA, z_binLCA);
          //          LOG(DEBUG) << "GetMotherID = " << point->GetMot0TrackID() << FairLogger::endl;
                    //Applying the light output non-uniformity
          separatedenergydeps.at(x_binLCA).at(y_binLCA).at(z_binLCA).at(point->GetParentGammaTrackID()) += fCsILCFun(address, x_binLC, y_binLC, z_binLC) * point->GetEnergyLoss();
          LOG(DEBUG) << "Point number " << iPoint << " GetParentGammaTrackID = " << point->GetParentGammaTrackID() << FairLogger::endl;
          LOG(DEBUG) << "Point number " << iPoint << " with energy deposition before LC: " << point->GetEnergyLoss() << FairLogger::endl;
          LOG(DEBUG) << "Point number " << iPoint << " with energy deposition after LC: " << fCsILCFun(address, x_binLC, y_binLC, z_binLC) * point->GetEnergyLoss() << FairLogger::endl;

          size_t x_countsLCB, y_countsLCB, z_countsLCB;
          tie(x_countsLCB, y_countsLCB, z_countsLCB) = fCsILCBGrid(address);
          size_t x_binLCB, y_binLCB, z_binLCB;
          tie(x_binLCB, y_binLCB, z_binLCB) = fSetup->GetCsIMeshElement(&pos, x_countsLCB, y_countsLCB, z_countsLCB);
          const float B = fCsILCBFun(address, x_binLCB, y_binLCB, z_binLCB);

          size_t x_countsLCC, y_countsLCC, z_countsLCC;
          tie(x_countsLCC, y_countsLCC, z_countsLCC) = fCsILCCGrid(address);
          size_t x_binLCC, y_binLCC, z_binLCC;
          tie(x_binLCC, y_binLCC, z_binLCC) = fSetup->GetCsIMeshElement(&pos, x_countsLCC, y_countsLCC, z_countsLCC);
          const float C = fCsILCCFun(address, x_binLCC, y_binLCC, z_binLCC);

        }
        //Applying Gaussian to all energy depositions, again based on the place of energy depositions
        for (auto ix = separatedenergydeps.begin(); ix != separatedenergydeps.end(); ++ix) {
          for (auto iy = ix->begin(); iy != ix->end(); ++iy) {
            for (auto iz = iy->begin(); iz != iy->end(); ++iz) {
              for (auto imult = iz->begin(); imult != iz->end(); ++imult) {
                if (*imult <= edep_threshold) {
                  continue;
                }
                else {
                  edepSigma = sqrt(pow(fCsILCAFun(address, distance(separatedenergydeps.begin(), ix), distance(ix->begin(), iy), distance(iy->begin(), iz)), 2) + pow(fCsILCBFun(address, distance(separatedenergydeps.begin(), ix), distance(ix->begin(), iy), distance(iy->begin(), iz)) * TMath::Sqrt(*imult), 2) + pow(fCsILCCFun(address, distance(separatedenergydeps.begin(), ix), distance(ix->begin(), iy), distance(iy->begin(), iz)) * *imult, 2));
                  LOG(DEBUG) << "The generated sigma of the Gaussian for CsI = " << edepSigma << ". The energy is " << *imult << FairLogger::endl;
                  gaus4MeV = *imult; 

                  *imult = gRandom->Gaus(*imult, edepSigma);
                  if(fabs(gaus4MeV - 4.) < 1e-7){
                    gaus4MeV = *imult;
                    std::cout << "Gaus energy deposition" << gaus4MeV << std::endl;
                  }
                  else
                  {
                    gaus4MeV = 0;
                  }

                  changedenergydeps[distance(iz->begin(), imult)] += *imult;
                }
              }
            }
          }
        }
        LOG(DEBUG) << "Changed energy depositions:" << FairLogger::endl;
        for (auto& i : changedenergydeps)
        {
          LOG(DEBUG) << i << ' ';
        }
        //Setting to 0 respective quantity of energy depositions (according to previously generated Poisson numbers)
        LOG(DEBUG) << "Poisson for caesium: " << events_poisson_Cs << ", for cobalt: " << events_poisson_Co << FairLogger::endl;
        for (int i = 0; i < fMultiplicity - events_poisson_Cs; i++)
        {
          changedenergydeps[i] = 0.;
        }
        for (int i = 0; i < fMultiplicity - events_poisson_Co; i++)
        {
          changedenergydeps[fMultiplicity + i] = 0.;
          changedenergydeps[fMultiplicity * 2 + i] = 0.;
        }

        //Considering here the fact that gammas from cobalt-60 are co-dependent, they are created simultaneously
        for (int i = 0; i < fMultiplicity; i++) {
          poissonenergydeps[i] = changedenergydeps[i];
          poissonenergydeps[fMultiplicity + i] = changedenergydeps[fMultiplicity + i] + changedenergydeps[fMultiplicity * 2 + i];
        }
        //Creating a vector of times passed between energy depositions registered by the detector		  		  
        std::uniform_real_distribution<> distime(0., fSignalsInterval); //interval of time in which the numbers are generated
        vector<Double_t> rndtime(fMultiplicity * 2, 0.);
        for (auto& i : rndtime)
        {
          i = distime(fMtGenerator);
        }
        //rndtime.front() = 0; //one of the energy depositions is set to take place at the beginning
        std::sort(rndtime.begin(), rndtime.end());
        LOG(DEBUG) << "Generated times, arranged in order: " << FairLogger::endl;
        for (auto& i : rndtime)
        {
          LOG(DEBUG) << i << ' ';
        }
        std::cout << FairLogger::endl;
        //Random shuffle of energy depositions (so that the order is not always Cs, Co1, Co2)
        std::shuffle(poissonenergydeps.begin(), poissonenergydeps.end(), fMtGenerator);
        //Changing the energy depositions according to the exponential decay based on "rndtime" vector and "fShapingTime" constant
        LOG(DEBUG) << "Shuffled energy depositions: " << FairLogger::endl;
        for (auto& i : poissonenergydeps)
        {
          LOG(DEBUG) << i << ' ';
        }
        std::cout << FairLogger::endl;
        for (int i = 0; i < fMultiplicity * 2; i++) {
          finalenergydeps[i] = poissonenergydeps[i];
        }
        for (int i = 1; i < fMultiplicity * 2; i++) {
          for (int j = 0; j < i; j++) {
            if (poissonenergydeps[i] >= edep_threshold)
            {
              finalenergydeps[i] += poissonenergydeps[j] * exp(-(rndtime[i] - rndtime[j]) / fDecayTime);
            }
          }
        }
        LOG(DEBUG) << "Set of final energy depositions: " << FairLogger::endl;
        for (auto& i : finalenergydeps)
        {
          LOG(DEBUG) << i << ' ';
        }
        edep = *std::max_element(finalenergydeps.begin(), finalenergydeps.end());
        std::cout << FairLogger::endl;
        LOG(DEBUG) << "Final energy deposition = " << edep << FairLogger::endl;
        if (edep <= edep_threshold)
          continue;
        Float_t timeSigma = TMath::Sqrt(fCsITimeErrorA / edep);
        time = gRandom->Gaus(time, timeSigma);

        AddCsIDigi(edep, gaus4MeV, itWall.first, itBlock.first, itCell.first, events_poisson_Cs, events_poisson_Co);
      }
    }
  }
  //Digitizing points in LaBr3 detectors
  for (const auto& itCell : pointsLaBr) {
    Float_t edep = 0; // sum edep in cell
    Float_t time = std::numeric_limits<float>::max(); // first time in cell
    for (const auto iPoint : itCell.second) {
      ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
      edep += point->GetEnergyLoss();
      if (point->GetTime() < time)
        time = point->GetTime();
    }
    Float_t edepSigma = sqrt(pow(fLaBrEdepErrorA, 2) + pow(fLaBrEdepErrorB * TMath::Sqrt(edep), 2) + pow(fLaBrEdepErrorC * edep, 2));
    edep = gRandom->Gaus(fLaBrLC * edep, edepSigma);
    if (edep < fLaBrElossThreshold)
      continue;
    Float_t timeSigma = TMath::Sqrt(fLaBrTimeErrorA / edep);
    time = gRandom->Gaus(time, timeSigma);

    AddLaBrDigi(edep, itCell.first);
  }
}
//----------------------------------------------------------------------------
void ERGadastDigitizer::Print(bool isFile, TString fileName)
{
  FairLogger* logger = FairLogger::GetLogger();
  if (isFile) {
    logger->SetLogVerbosityLevel("LOW");
    logger->SetLogToFile(kTRUE);
    logger->SetLogToScreen(kFALSE);
    logger->SetLogFileLevel("INFO");
    logger->SetLogFileName(fileName);
  }
  LOG(INFO) << "ERGadastDigitizer Parameters: " << FairLogger::endl
    << "fPoissonCs: " << fPoissonCs << FairLogger::endl
    << "fPoissonCo: " << fPoissonCo << FairLogger::endl
    << "fSeed: " << fSeed << FairLogger::endl
    << "fMultiplicity: " << fMultiplicity << FairLogger::endl
    << "fSignalsInterval: " << fSignalsInterval << FairLogger::endl
    << "fDecayTime: " << fDecayTime << FairLogger::endl
    << "fCsITimeErrorA: " << fCsITimeErrorA << FairLogger::endl
    << "fLaBrLC: " << fLaBrLC << FairLogger::endl
    << "fLaBrEdepErrorA: " << fLaBrEdepErrorA << FairLogger::endl
    << "fLaBrEdepErrorB: " << fLaBrEdepErrorB << FairLogger::endl
    << "fLaBrEdepErrorC: " << fLaBrEdepErrorC << FairLogger::endl
    << "fLaBrTimeErrorA: " << fLaBrTimeErrorA << FairLogger::endl
    << "fCsIElossThreshold: " << fCsIElossThreshold << FairLogger::endl
    << "fLaBrElossThreshold: " << fLaBrElossThreshold << FairLogger::endl
    << "fCsILC: " << fCsILCFun(BlockAddress(), 0, 0, 0) << FairLogger::endl;
  //if constexpr (std::is_same<decltype(fC))
  logger->SetLogToFile(kFALSE);
  logger->SetLogToScreen(kTRUE);
}
//----------------------------------------------------------------------------
void ERGadastDigitizer::Reset()
{
  if (fGadastCsIDigi) {
    fGadastCsIDigi->Delete();
  }
  if (fGadastLaBrDigi) {
    fGadastLaBrDigi->Delete();
  }
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERGadastDigitizer::Finish()
{
  LOG(INFO) << "========== Finish of ERGadastDigitizer ==================" << FairLogger::endl;
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERGadastCsIDigi* ERGadastDigitizer::AddCsIDigi(Float_t Edep, Float_t edep_sigma, Int_t wall, Int_t block, Int_t cell, Int_t Events_Poisson_Cs, Int_t Events_Poisson_Co)
{
  ERGadastCsIDigi* digi = new((*fGadastCsIDigi)[fGadastCsIDigi->GetEntriesFast()])
    ERGadastCsIDigi(fGadastCsIDigi->GetEntriesFast(), Edep, edep_sigma,wall, block, cell, Events_Poisson_Cs, Events_Poisson_Co);
  return digi;
}
// ----------------------------------------------------------------------------
ERGadastLaBrDigi* ERGadastDigitizer::AddLaBrDigi(Float_t Edep, Int_t cell)
{
  ERGadastLaBrDigi* digi = new((*fGadastLaBrDigi)[fGadastLaBrDigi->GetEntriesFast()])
    ERGadastLaBrDigi(fGadastLaBrDigi->GetEntriesFast(), Edep, cell);
  return digi;
}
ClassImp(ERGadastDigitizer)

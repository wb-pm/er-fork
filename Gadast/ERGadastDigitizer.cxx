#include "ERGadastDigitizer.h"

#include "TVector3.h"
#include "TMath.h"

#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FairEventHeader.h"

#include "ERGadastCsIPoint.h"
#include "ERGadastLaBrPoint.h"

#include "TH1.h"
using namespace std;

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
  fLaBrElossThreshold(0.)
{
}
// ----------------------------------------------------------------------------

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
  fLaBrElossThreshold(0.)
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

ERGadastDigitizer::~ERGadastDigitizer()
{
  delete fSetup;
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(Float_t lc)
{
  fCsILCFun = [lc](BlockAddress, size_t, size_t, size_t) {return lc;};
  fCsILCGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(std::map<BlockAddress, float>& lc)
{
  fCsILCFun = [lc](BlockAddress address, size_t, size_t, size_t) {
    return lc.at(address);
  };
  fCsILCGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsILC(std::map<BlockAddress, CoefficientMatrix>& lc)
{
  fCsILCFun = [&lc](BlockAddress address, size_t x, size_t y, size_t z) {
    LOG(DEBUG) << "CsILCFun: wall=" << address.first << ", block=" << address.second 
               << ", x cell=" << x << ", y cell=" << y << ", z cell=" << z << FairLogger::endl;
    return lc.at(address).at(x).at(y).at(z);
  };

  fCsILCGrid = [&lc](BlockAddress address) {
    LOG(DEBUG) << "fCsILCGrid: wall=" << address.first << ", block=" << address.second << FairLogger::endl;
    const auto& matrix = lc.at(address);
    const size_t x_size = matrix.size();
    const size_t y_size = matrix.at(0).size();
    const size_t z_size = matrix.at(0).at(0).size();
    return std::make_tuple(x_size, y_size, z_size);
  };
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(Float_t a, Float_t b, Float_t c)
{
  fCsILCAFun = [a](BlockAddress, size_t, size_t, size_t) {return a;};
  fCsILCAGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
  fCsILCBFun = [b](BlockAddress, size_t, size_t, size_t) {return b;};
  fCsILCBGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
  fCsILCCFun = [c](BlockAddress, size_t, size_t, size_t) {return c;};
  fCsILCCGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(std::map<BlockAddress, float>& a, 
                                        std::map<BlockAddress, float>& b,
                                        std::map<BlockAddress, float>& c) {
  fCsILCAFun = [a](BlockAddress address, size_t, size_t, size_t) {
    return a.at(address);
  };
  fCsILCAGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
  fCsILCBFun = [b](BlockAddress address, size_t, size_t, size_t) {
    return b.at(address);
  };
  fCsILCBGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
  fCsILCCFun = [c](BlockAddress address, size_t, size_t, size_t) {
    return c.at(address);
  };
  fCsILCCGrid = [](BlockAddress) {return std::make_tuple(1,1,1);};
}

// ----------------------------------------------------------------------------

void ERGadastDigitizer::SetCsIEdepError(std::map<BlockAddress, CoefficientMatrix>& a, 
                                        std::map<BlockAddress, CoefficientMatrix>& b,
                                        std::map<BlockAddress, CoefficientMatrix>& c) {
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
    return std::make_tuple(x_size, y_size, z_size);
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
    return std::make_tuple(x_size, y_size, z_size);
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
    return std::make_tuple(x_size, y_size, z_size);
  };

}

// ----------------------------------------------------------------------------
void ERGadastDigitizer::SetParContainers()
{
  // Get run and runtime database
  FairRun* run = FairRun::Instance();
  if ( ! run ) Fatal("SetParContainers", "No analysis run");

  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  if ( ! rtdb ) Fatal("SetParContainers", "No runtime database");

  fDigiPar = (ERGadastDigiPar*)
             (rtdb->getContainer("ERGadastDigiPar"));
  if ( fVerbose && fDigiPar ) {
    LOG(INFO) << "ERGadastDigitizer::SetParContainers() "<< FairLogger::endl;
    LOG(INFO) << "ERGadastDigiPar initialized! "<< FairLogger::endl;
  }
}
// ----------------------------------------------------------------------------

//----------------------------------------------------------------------------
InitStatus ERGadastDigitizer::Init()
{
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");
  
  fGadastCsIPoints = (TClonesArray*) ioman->GetObject("GadastCsIPoint");
  fGadastLaBrPoints = (TClonesArray*) ioman->GetObject("GadastLaBrPoint");
  
  // Register output arrays
  fGadastCsIDigi = new TClonesArray("ERGadastCsIDigi",1000);
  fGadastLaBrDigi = new TClonesArray("ERGadastLaBrDigi",1000);
  ioman->Register("GadastCsIDigi", "Digital response in Gadast CsI", fGadastCsIDigi, kTRUE);
  ioman->Register("GadastLaBrDigi", "Digital response in Gadast LaBr", fGadastLaBrDigi, kTRUE);

  fSetup = ERGadastSetup::Instance();
  if (!fSetup->Init()){
    std::cerr << "Problems with ERGadastSetup initialization!" << FairLogger::endl;
  }
  return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
//----------------------------------------------------------------------------
//New Implementation with pile-up algorithm and Poisson distribution
void ERGadastDigitizer::Exec(Option_t* opt)
{
  // Reset entries in output arrays
  Reset();

  // Sort points by sensentive volumes
  // Map points by cells: pointsCsI[iWall][iBlock][iCell]
  map<Int_t, map<Int_t, map <Int_t, vector<Int_t> > > > pointsCsI;
  
  LOG(DEBUG) << "fGadastCsIPoints contains entries: " << fGadastCsIPoints->GetEntriesFast() << FairLogger::endl;

  for (Int_t iPoint = 0; iPoint < fGadastCsIPoints->GetEntriesFast(); iPoint++){
    ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
    pointsCsI[point->GetWall()][point->GetBlock()][point->GetCell()].push_back(iPoint);
  }

  // Map points by cells: pointsLaBr[iCell]
  map<Int_t, vector<Int_t> > pointsLaBr;
  for (Int_t iPoint = 0; iPoint < fGadastLaBrPoints->GetEntriesFast(); iPoint++){
    ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
    pointsLaBr[point->GetCell()].push_back(iPoint);
  }
  
//Generating Poisson distribution numbers, to determine quantity of gammas left 
std::random_device dev_pos;
std::mt19937 rng_pos(dev_pos());
std::poisson_distribution<int> distribution_Cs(2.);
std::poisson_distribution<int> distribution_Co(4.);
int events_poisson_Cs = distribution_Cs(rng_pos);
//int events_poisson_Cs = 1;
int events_poisson_Co = distribution_Co(rng_pos);
//int events_poisson_Co = 1;

 for (const auto &itWall : pointsCsI){
    for (const auto &itBlock : itWall.second){
      BlockAddress address = std::make_pair(itWall.first, itBlock.first);
      for (const auto &itCell : itBlock.second){
        Double_t edep = 0.; // sum edep in cell
        Float_t edepSigma = 0.; // sum edep in cell
        Double_t energydep = 0.;
        size_t x_countsLCA, y_countsLCA, z_countsLCA;
        std::tie(x_countsLCA, y_countsLCA, z_countsLCA) = fCsILCAGrid(address);
        std::vector<std::vector<std::vector<std::vector<float> > > > separatedenergydeps(x_countsLCA, std::vector<std::vector<std::vector<float> > >(y_countsLCA, std::vector<std::vector<float> >(z_countsLCA, vector<float>(fMultiplicity*3,0))));
        LOG(INFO) << "x_countsLCA: " << x_countsLCA << " y_countsLCA: " << y_countsLCA << " z_countsLCA: " << z_countsLCA << FairLogger::endl;
		std::vector<Double_t> energydeps(fMultiplicity*3, 0.0);
		std::vector<Double_t> changedenergydeps(fMultiplicity*3, 0.0);
		std::vector<Double_t> poissonenergydeps(fMultiplicity*2, 0.0);
		std::vector<Double_t> finalenergydeps(fMultiplicity*2, 0.0);
        Float_t time = std::numeric_limits<float>::max(); // first time in cell

        for (const auto iPoint : itCell.second){
          ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
          if (point->GetTime() < time)
            time = point->GetTime();
          TVector3 pos;
          point->PositionIn(pos);
		  
		  
		  size_t x_countsLC, y_countsLC, z_countsLC;
          std::tie(x_countsLC, y_countsLC, z_countsLC) = fCsILCGrid(address);
           LOG(DEBUG) << "x_countsLC: " << x_countsLC << " y_countsLC: " << y_countsLC << " z_countsLC: " << z_countsLC << FairLogger::endl;
          size_t x_binLC, y_binLC, z_binLC;
          std::tie(x_binLC, y_binLC, z_binLC) = fSetup->GetCsIMeshElement(&pos, x_countsLC, y_countsLC, z_countsLC);
           LOG(DEBUG) << "x_binLC: " << x_binLC << " y_binLC: " << y_binLC << " z_binLC: " << z_binLC << FairLogger::endl;
          
          size_t x_binLCA, y_binLCA, z_binLCA;
          std::tie(x_binLCA, y_binLCA, z_binLCA) = fSetup->GetCsIMeshElement(&pos, x_countsLCA, y_countsLCA, z_countsLCA);
           LOG(DEBUG) << "x_binLCA: " << x_binLCA << " y_binLCA: " << y_binLCA << " z_binLCA: " << z_binLCA << FairLogger::endl;
          const float A = fCsILCAFun(address, x_binLCA, y_binLCA, z_binLCA);
          LOG(DEBUG) << "GetParentGammaTrackID = " << point->GetParentGammaTrackID() << FairLogger::endl;
          separatedenergydeps.at(x_binLCA).at(y_binLCA).at(z_binLCA).at(point->GetParentGammaTrackID()) += fCsILCFun(address, x_binLC, y_binLC, z_binLC)*point->GetEnergyLoss();

		  size_t x_countsLCB, y_countsLCB, z_countsLCB;
          std::tie(x_countsLCB, y_countsLCB, z_countsLCB) = fCsILCBGrid(address);
          size_t x_binLCB, y_binLCB, z_binLCB;
          std::tie(x_binLCB, y_binLCB, z_binLCB) = fSetup->GetCsIMeshElement(&pos, x_countsLCB, y_countsLCB, z_countsLCB);
          const float B = fCsILCBFun(address, x_binLCB, y_binLCB, z_binLCB);

		  size_t x_countsLCC, y_countsLCC, z_countsLCC;
          std::tie(x_countsLCC, y_countsLCC, z_countsLCC) = fCsILCCGrid(address);
          size_t x_binLCC, y_binLCC, z_binLCC;
          std::tie(x_binLCC, y_binLCC, z_binLCC) = fSetup->GetCsIMeshElement(&pos, x_countsLCC, y_countsLCC, z_countsLCC);
          const float C = fCsILCCFun(address, x_binLCC, y_binLCC, z_binLCC);
          
          //energydep = fCsILCFun(address, x_binLC, y_binLC, z_binLC) * point->GetEnergyLoss();
          //changedenergydeps[point->GetParentGammaTrackID()] += gRandom->Gaus(energydep, sqrt(pow(A, 2) + pow(B * TMath::Sqrt(energydep), 2) + pow(C * energydep, 2)));
		  //energydeps[point->GetParentGammaTrackID()] += fCsILCFun(address, x_binLC, y_binLC, z_binLC) * point->GetEnergyLoss();
		  
		  //Energy depositions, altered by the Gauss distribution
		  /*for(int i = 0; i < fMultiplicity*3; i++){
			  if (energydeps[i] <= 0.0001)
				{;}
			  else
		  {
			  changedenergydeps[i] = gRandom->Gaus(energydeps[i], sqrt(pow(A, 2) + pow(B * TMath::Sqrt(energydeps[i]), 2) + pow(C * energydeps[i], 2)));
			  //changedenergydeps[i] = gRandom->Gaus(energydeps[i], 0.11*energydeps[i]);
		  }
			  }   */
	    }
		for(auto ix = separatedenergydeps.begin(); ix != separatedenergydeps.end(); ++ix){
			for(auto iy = ix->begin(); iy != ix->end(); ++iy){
				for(auto iz = iy->begin(); iz != iy->end(); ++iz){
					for(auto imult = iz->begin(); imult != iz->end(); ++imult){
					if(*imult <= 0.0001){
						continue;
					}
					else{
					*imult = gRandom->Gaus(*imult, sqrt(pow(fCsILCAFun(address, std::distance(separatedenergydeps.begin(),ix), std::distance(ix->begin(), iy), std::distance(iy->begin(),iz)), 2) + pow(fCsILCBFun(address, std::distance(separatedenergydeps.begin(),ix), std::distance(ix->begin(), iy), std::distance(iy->begin(),iz)) * TMath::Sqrt(*imult), 2) + pow(fCsILCCFun(address, std::distance(separatedenergydeps.begin(),ix), std::distance(ix->begin(), iy), std::distance(iy->begin(),iz)) * *imult, 2)));
					changedenergydeps[std::distance(iz->begin(),imult)] += *imult;}
					}
				}
			}
		}
		  //Counters for gammas of each type, arriving to detector before applying Poisson algorithm
			int CsGammas_Before = 0;
			for(int i = 0; i < fMultiplicity; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					CsGammas_Before++;
				}	
			}
			
			int Co1Gammas_Before = 0;
			for(int i = fMultiplicity; i < fMultiplicity*2; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					Co1Gammas_Before++;
				}	
			}
						
			int Co2Gammas_Before = 0;
			for(int i = fMultiplicity*2; i < fMultiplicity*3; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					Co2Gammas_Before++;
				}	
			}
			//Setting to 0 respective quantity of energy depositions (according to previously generated Poisson numbers)
			for(int i = 0; i < fMultiplicity - events_poisson_Cs; i++)
			{
				changedenergydeps[i] = 0.;
			}
			for(int i = 0; i < fMultiplicity - events_poisson_Co; i++)
			{
				  changedenergydeps[fMultiplicity+i] = 0.;
				  changedenergydeps[fMultiplicity*2+i] = 0.;
			}		
					  
			int CsGammas_After = 0;  
			for(int i = 0; i < fMultiplicity; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					CsGammas_After++;
				}
				else{;}	
			}
		//Counters for gammas of each type, left in the detector after applying Poisson algorithm
			int Co1Gammas_After = 0;  
			for(int i = fMultiplicity; i < fMultiplicity*2; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					Co1Gammas_After++;
				}
				else{;}	
			}
		
			int Co2Gammas_After = 0;  
			for(int i = fMultiplicity*2; i < fMultiplicity*3; i++)
			{
				if (changedenergydeps[i] >=0.0001)
				{
					Co2Gammas_After++;
				}
				else{;}	
			}
			//Considering here the fact that gammas from cobalt-60 are co-dependent, they are created simultaneously
		  for(int i = 0; i < fMultiplicity; i++){
			  poissonenergydeps[i] = changedenergydeps[i];
			  poissonenergydeps[fMultiplicity+i] = changedenergydeps[fMultiplicity+i] + changedenergydeps[fMultiplicity*2+i];
		  }	  
		//Creating a vector of times passed between energy depositions registered by the detector		  		  
	    std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<> distime(0,1000); //interval of time in which the numbers are generated
		std::vector<Int_t> rndtime(fMultiplicity*2, 0);
		for(auto &i: rndtime)
		  {
			  i = distime(rng);
			  }
		rndtime.front() = 0; //one of the energy depositions is set to take place at the beginning
		std::sort(rndtime.begin(),rndtime.end());
		   
		Double_t shaping_time = 960.0; //shaping time constant
		//Random shuffle of energy depositions (so that the order is not always Cs, Co1, Co2)
	    std::random_device rd;
		std::mt19937 gen(rd());
		std::shuffle(poissonenergydeps.begin(),poissonenergydeps.end(), gen);
		//Changing the energy depositions according to the exponential decay based on "rndtime" vector and "shaping_time" constant
		for(int i = 0; i < fMultiplicity*2; i++){
			finalenergydeps[i] = poissonenergydeps[i];
		}
		for(int i = 1; i < fMultiplicity*2; i++){
			for(int j = 0; j < i; j++){
				finalenergydeps[i] += poissonenergydeps[j]*exp(-(rndtime[i]-rndtime[j])/shaping_time);
		}}
		edep = *std::max_element(finalenergydeps.begin(),finalenergydeps.end());
        if (edep <= 0.0001)
          continue;
        Float_t timeSigma = TMath::Sqrt(fCsITimeErrorA/edep);
        time = gRandom->Gaus(time, timeSigma);

        AddCsIDigi(edep, itWall.first, itBlock.first, itCell.first, events_poisson_Cs, events_poisson_Co, CsGammas_Before, CsGammas_After,
        Co1Gammas_Before, Co1Gammas_After, Co2Gammas_Before, Co2Gammas_After);
	  }
	    }
      }
  for (const auto &itCell : pointsLaBr){
    Float_t edep = 0; // sum edep in cell
    Float_t time = std::numeric_limits<float>::max(); // first time in cell
    for (const auto iPoint : itCell.second){
      ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
      edep += point->GetEnergyLoss();
      if (point->GetTime() < time)
        time = point->GetTime();
    }
    Float_t edepSigma = sqrt(pow(fLaBrEdepErrorA,2) + pow(fLaBrEdepErrorB*TMath::Sqrt(edep),2) + pow(fLaBrEdepErrorC*edep,2));
    edep = gRandom->Gaus(fLaBrLC*edep, edepSigma);
    if (edep < fLaBrElossThreshold)
      continue;
    Float_t timeSigma = TMath::Sqrt(fLaBrTimeErrorA/edep);
    time = gRandom->Gaus(time, timeSigma);

    AddLaBrDigi(edep,itCell.first);
  }
}
//----------------------------------------------------------------------------
//The basic digitizer
/*void ERGadastDigitizer::Exec(Option_t* opt)

{
  // Reset entries in output arrays
  Reset();

  // Sort points by sensentive volumes
  // Map points by cells: pointsCsI[iWall][iBlock][iCell]
  map<Int_t, map<Int_t, map <Int_t, vector<Int_t> > > > pointsCsI;
  for (Int_t iPoint = 0; iPoint < fGadastCsIPoints->GetEntriesFast(); iPoint++){
    ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
    pointsCsI[point->GetWall()][point->GetBlock()][point->GetCell()].push_back(iPoint);
  }

  // Map points by cells: pointsLaBr[iCell]
  map<Int_t, vector<Int_t> > pointsLaBr;
  for (Int_t iPoint = 0; iPoint < fGadastLaBrPoints->GetEntriesFast(); iPoint++){
    ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
    pointsLaBr[point->GetCell()].push_back(iPoint);
  }

  for (const auto &itWall : pointsCsI){
    for (const auto &itBlock : itWall.second){
      BlockAddress address = std::make_pair(itWall.first, itBlock.first);
      for (const auto &itCell : itBlock.second){
        Float_t edep = 0; // sum edep in cell
        Float_t edepSigma = 0; // sum edep in cell
        Float_t time = std::numeric_limits<float>::max(); // first time in cell
        for (const auto iPoint : itCell.second){
          ERGadastCsIPoint* point = (ERGadastCsIPoint*)fGadastCsIPoints->At(iPoint);
          if (point->GetTime() < time)
            time = point->GetTime();
          TVector3 pos;
          point->PositionIn(pos);

          size_t x_counts, y_counts, z_counts;
          std::tie(x_counts, y_counts, z_counts) = fCsILCGrid(address);
          size_t x_bin, y_bin, z_bin;
          std::tie(x_bin, y_bin, z_bin) = fSetup->GetCsIMeshElement(&pos, x_counts, y_counts, z_counts);
          edep += fCsILCFun(address, x_bin, y_bin, z_bin) * point->GetEnergyLoss();
          
          std::tie(x_counts, y_counts, z_counts) = fCsILCAGrid(address);
          std::tie(x_bin, y_bin, z_bin) = fSetup->GetCsIMeshElement(&pos, x_counts, y_counts, z_counts);
          const float A = fCsILCAFun(address, x_bin, y_bin, z_bin);

          std::tie(x_counts, y_counts, z_counts) = fCsILCBGrid(address);
          std::tie(x_bin, y_bin, z_bin) = fSetup->GetCsIMeshElement(&pos, x_counts, y_counts, z_counts);
          const float B = fCsILCBFun(address, x_bin, y_bin, z_bin);

          std::tie(x_counts, y_counts, z_counts) = fCsILCCGrid(address);
          std::tie(x_bin, y_bin, z_bin) = fSetup->GetCsIMeshElement(&pos, x_counts, y_counts, z_counts);
          const float C = fCsILCCFun(address, x_bin, y_bin, z_bin);
          
          edepSigma = sqrt(pow(A, 2) + pow(B * TMath::Sqrt(edep), 2) + pow(C * edep, 2));
        }
        
        edep = gRandom->Gaus(edep, edepSigma);
        if (edep < fCsIElossThreshold)
          continue;
        Float_t timeSigma = TMath::Sqrt(fCsITimeErrorA/edep);
        time = gRandom->Gaus(time, timeSigma);

        AddCsIDigi(edep, itWall.first, itBlock.first, itCell.first);
      }
    }
  }

  for (const auto &itCell : pointsLaBr){
    Float_t edep = 0; // sum edep in cell
    Float_t time = std::numeric_limits<float>::max(); // first time in cell
    for (const auto iPoint : itCell.second){
      ERGadastLaBrPoint* point = (ERGadastLaBrPoint*)fGadastLaBrPoints->At(iPoint);
      edep += point->GetEnergyLoss();
      if (point->GetTime() < time)
        time = point->GetTime();
    }
    Float_t edepSigma = sqrt(pow(fLaBrEdepErrorA,2) + pow(fLaBrEdepErrorB*TMath::Sqrt(edep),2) + pow(fLaBrEdepErrorC*edep,2));
    edep = gRandom->Gaus(fLaBrLC*edep, edepSigma);
    if (edep < fLaBrElossThreshold)
      continue;
    Float_t timeSigma = TMath::Sqrt(fLaBrTimeErrorA/edep);
    time = gRandom->Gaus(time, timeSigma);

    AddLaBrDigi(edep,itCell.first);
  }
}*/
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
  LOG(INFO) << "========== Finish of ERGadastDigitizer =================="<< FairLogger::endl;
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERGadastCsIDigi* ERGadastDigitizer::AddCsIDigi(Float_t Edep,Int_t wall,Int_t block, Int_t cell, Int_t Events_Poisson_Cs, 
  Int_t Events_Poisson_Co, Int_t CsGammas_Before, Int_t CsGammas_After, Int_t Co1Gammas_Before, Int_t Co1Gammas_After, 
  Int_t Co2Gammas_Before, Int_t Co2Gammas_After)
{
  ERGadastCsIDigi *digi = new((*fGadastCsIDigi)[fGadastCsIDigi->GetEntriesFast()])
							ERGadastCsIDigi(fGadastCsIDigi->GetEntriesFast(), Edep, wall, block, cell, Events_Poisson_Cs,
							Events_Poisson_Co, CsGammas_Before, CsGammas_After, Co1Gammas_Before, Co1Gammas_After, Co2Gammas_Before,
							Co2Gammas_After);
  return digi;
}
// ----------------------------------------------------------------------------
ERGadastLaBrDigi* ERGadastDigitizer::AddLaBrDigi(Float_t Edep, Int_t cell)
{
  ERGadastLaBrDigi *digi = new((*fGadastLaBrDigi)[fGadastLaBrDigi->GetEntriesFast()])
              ERGadastLaBrDigi(fGadastLaBrDigi->GetEntriesFast(), Edep, cell);
  return digi;
}
ClassImp(ERGadastDigitizer)

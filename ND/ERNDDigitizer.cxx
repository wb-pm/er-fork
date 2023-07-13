#include "ERNDDigitizer.h"

#include "TVector3.h"
#include "TGeoMatrix.h"
#include "TMath.h"
#include "TRandom3.h"

#include "FairRootManager.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

#include <limits>
#include <vector>
#include <map>

#include "ERDetectorList.h"
#include "ERNDPoint.h"
#include "ERBC404Point.h"

Int_t ERNDDigitizer::fEvent = 0;
// ----------------------------------------------------------------------------
ERNDDigitizer::ERNDDigitizer()
  : FairTask("ER ND Digi producing scheme")
,fNDPoints(NULL)
,fNDDigis(NULL)
,fEdepErrorNDA(0)
,fEdepErrorNDB(0)
,fEdepErrorNDC(0)
,fLYErrorNDA(0)
,fLYErrorNDB(0)
,fLYErrorNDC(0)
,fQuenchThresholdND(0)
,fLYThresholdND(0)
,fProbabilityNDB(0)
,fProbabilityNDC(0)

,fBC404Points(NULL)
,fBC404Digis(NULL)
,fEdepErrorBC404A(0)
,fEdepErrorBC404B(0)
,fEdepErrorBC404C(0)
,fLYErrorBC404A(0)
,fLYErrorBC404B(0)
,fLYErrorBC404C(0)
,fQuenchThresholdBC404(0)
,fLYThresholdBC404(0)
,fProbabilityBC404B(0)
,fProbabilityBC404C(0)
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERNDDigitizer::ERNDDigitizer(Int_t verbose)
  : FairTask("ER ND Digi producing scheme ", verbose)
,fNDPoints(NULL)
,fNDDigis(NULL)
,fEdepErrorNDA(0)
,fEdepErrorNDB(0)
,fEdepErrorNDC(0)
,fLYErrorNDA(0)
,fLYErrorNDB(0)
,fLYErrorNDC(0)
,fQuenchThresholdND(0)
,fLYThresholdND(0)
,fProbabilityNDB(0)
,fProbabilityNDC(0)

,fBC404Points(NULL)
,fBC404Digis(NULL)
,fEdepErrorBC404A(0)
,fEdepErrorBC404B(0)
,fEdepErrorBC404C(0)
,fLYErrorBC404A(0)
,fLYErrorBC404B(0)
,fLYErrorBC404C(0)
,fQuenchThresholdBC404(0)
,fLYThresholdBC404(0)
,fProbabilityBC404B(0)
,fProbabilityBC404C(0)
{
}
// -------------------------------------  ---------------------------------------

// ----------------------------------------------------------------------------
ERNDDigitizer::~ERNDDigitizer()
{
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERNDDigitizer::SetParContainers()
{
  // Get run and runtime database
  FairRun* run = FairRun::Instance();
  if ( ! run ) Fatal("SetParContainers", "No analysis run");

  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  if ( ! rtdb ) Fatal("SetParContainers", "No runtime database");
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
InitStatus ERNDDigitizer::Init()
{
  // Get input array
  FairRootManager* ioman = FairRootManager::Instance();
  if ( ! ioman ) Fatal("Init", "No FairRootManager");
  
  fNDPoints = (TClonesArray*) ioman->GetObject("NDPoint");
  fBC404Points = (TClonesArray*) ioman->GetObject("BC404Point");
  if (!fNDPoints)
    Fatal("Init", "Can`t find collection NDPoint!");
  if (!fBC404Points)
    Fatal("Init", "Can`t find collection BC404Point!");  

  // Register output array fNDDigis
  fNDDigis = new TClonesArray("ERNDDigi",10);
  fBC404Digis = new TClonesArray("ERBC404Digi",10);

  ioman->Register("NDDigi", "ND digi", fNDDigis, kTRUE);
  ioman->Register("BC404Digi", "BC404 digi", fBC404Digis, kTRUE);

  fSetup = ERNDSetup::Instance();
   
  return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
void ERNDDigitizer::Exec(Option_t* opt)
{
  
  LOG(DEBUG2) << "ERNDDigitizer event: " << fEvent++ << FairLogger::endl;
  Reset();

  //Sort points by crystalls
  std::map<Int_t, std::vector<Int_t>> pointsByCrystalND;
  for (Int_t iPoint = 0; iPoint < fNDPoints->GetEntriesFast(); iPoint++){
    ERNDPoint* point = (ERNDPoint*)fNDPoints->At(iPoint);
    pointsByCrystalND[point->StilbenNr()].push_back(iPoint);
  }

  std::map<Int_t, std::vector<Int_t>> pointsByHexBC404;
  for (Int_t iPoint = 0; iPoint < fBC404Points->GetEntriesFast(); iPoint++){
    ERBC404Point* point = (ERBC404Point*)fBC404Points->At(iPoint);
    pointsByHexBC404[point->HexNr()].push_back(iPoint);
  }


  //loop over crystall with points
  for (const auto &itCrystalND : pointsByCrystalND){
    Float_t edep = 0;   // sum edep in crystal
    Float_t edep_n1= 0; 
    Float_t edep_n2= 0; 
    Float_t edep_mis= 0;
    Float_t time = std::numeric_limits<float>::max();   // first time in crystall
    Float_t ly = 0.;    // sum ligth yield in crystall
    Float_t x_in = 0.;
    Float_t y_in = 0.;
    Float_t z_in = 0.;
    Int_t parentTrackID = -2;

    //loop over points in crysrall itCrystalND.first()
    for (const auto iPoint : itCrystalND.second){
      ERNDPoint* point = (ERNDPoint*)fNDPoints->At(iPoint);
      edep += point->GetEnergyLoss();
      ly += point->LightYield();
      if (point->GetTime() < time){	// time 1,2 - заполнять по parenttrackID case switch
        time = point->GetTime();
        //sonya:new variables x_in,y_in,z_in - enter point of neutron (proton in fact) in stilben
        x_in = point->GetXIn();
        y_in = point->GetYIn();
        z_in = point->GetZIn();
      }
      //if(point->GetMot0TrackID()==2)	printf("*********================\nPoint from 1st neutron\n");
      
      parentTrackID = point->GetParentTrackID();
     // printf("******** parent track id %i\n",parentTrackID);
      switch (parentTrackID)
      {
         case 3:         
            edep_n1+=point->GetEnergyLoss();
            break;
         case 4:
            edep_n2+=point->GetEnergyLoss();
            break;
         default:
            edep_mis+=point->GetEnergyLoss();
      }
    }
	
    Float_t edepSigma = sqrt(pow(fEdepErrorNDA,2) + pow(fEdepErrorNDB*TMath::Sqrt(edep),2) + pow(fEdepErrorNDC*edep,2));	
//    Float_t edepSigma = sqrt(pow(fEdepErrorA,2) + pow(fEdepErrorB*TMath::Sqrt(edep/1000.),2) + pow(fEdepErrorC*edep,2));
    edep = gRandom->Gaus(edep, edepSigma);

	/*fEdepErrorA [MeV], fEdepErrorB  [Sqrt(MeV)],  fEdepErrorC  [dimensionless], e.g. if fEdepErrorA = 0.01 MeV, fEdepErrorB = 0.02 MeV^0.5, fEdepErrorC= 0.03 for Edep=2.0 [MeV] sigma is equal Sqrt(0.01^2+(0.02*(2.0^0.5))^2+(0.03*2.0)^2) = 0.067 MeV
    The errors for LY are set in a similar way*/
    /*
    fEdepErrorB and fLYErrorB are expressed in per cent divided by square root of edep or LY,
    expressed in MeVlike it is usually done in detector description. e.g. for Edep=0.001 (i.e. 1 Mev)
    sigma is equal0.04*0.001Gev = 0.04 MeV
    */

    Float_t lySigma = sqrt(pow(fLYErrorNDA,2) + pow(fLYErrorNDB*TMath::Sqrt(ly),2) + pow(fLYErrorNDC*ly,2));
//    Float_t lySigma = sqrt(pow(fLYErrorA,2) + pow(fLYErrorB*TMath::Sqrt(ly/1000.),2) + pow(fLYErrorC*ly,2));
    ly = gRandom->Gaus(ly, lySigma);

    Float_t timeSigma = TMath::Sqrt(fTimeErrorNDA/ly);
    time = gRandom->Gaus(time, timeSigma);

    Float_t neutronProb = NeutronProbabilityND(edep,ly);
  
    AddNDDigi(itCrystalND.first,edep, edep_n1, edep_n2, edep_mis, parentTrackID, ly, time, neutronProb,x_in,y_in,z_in);	//sonya:new variables x_in,y_in,z_in - enter point of neutron (proton in fact) in stilben
  }

    for (const auto &itHexBC404 : pointsByHexBC404){
    Float_t edep = 0;   // sum edep in crystall
    Float_t time = std::numeric_limits<float>::max();   // first time in crystall
    Float_t ly = 0.;    // sum ligth yield in crystall
    Float_t x_in = 0.;
    Float_t y_in = 0.;
    Float_t z_in = 0.;
    Int_t parentTrackID = -2;

    //loop over points in crysrall itHexBC404.first()
    for (const auto iPoint : itHexBC404.second){
      ERBC404Point* point = (ERBC404Point*)fBC404Points->At(iPoint);
      edep += point->GetEnergyLoss();
      ly += point->LightYield();
      if (point->GetTime() < time){ // time 1,2 - заполнять по parenttrackID case switch
        time = point->GetTime();

        x_in = point->GetXIn();
        y_in = point->GetYIn();
        z_in = point->GetZIn();
      }
      
      parentTrackID = point->GetParentTrackID();

    }
  
    Float_t edepSigma = sqrt(pow(fEdepErrorBC404A,2) + pow(fEdepErrorBC404B*TMath::Sqrt(edep),2) + pow(fEdepErrorBC404C*edep,2));  
//    Float_t edepSigma = sqrt(pow(fEdepErrorA,2) + pow(fEdepErrorB*TMath::Sqrt(edep/1000.),2) + pow(fEdepErrorC*edep,2));
    edep = gRandom->Gaus(edep, edepSigma);

  /*fEdepErrorA [MeV], fEdepErrorB  [Sqrt(MeV)],  fEdepErrorC  [dimensionless], e.g. if fEdepErrorA = 0.01 MeV, fEdepErrorB = 0.02 MeV^0.5, fEdepErrorC= 0.03 for Edep=2.0 [MeV] sigma is equal Sqrt(0.01^2+(0.02*(2.0^0.5))^2+(0.03*2.0)^2) = 0.067 MeV
    The errors for LY are set in a similar way*/
    /*
    fEdepErrorB and fLYErrorB are expressed in per cent divided by square root of edep or LY,
    expressed in MeVlike it is usually done in detector description. e.g. for Edep=0.001 (i.e. 1 Mev)
    sigma is equal0.04*0.001Gev = 0.04 MeV
    */

    Float_t lySigma = sqrt(pow(fLYErrorBC404A,2) + pow(fLYErrorBC404B*TMath::Sqrt(ly),2) + pow(fLYErrorBC404C*ly,2));
//    Float_t lySigma = sqrt(pow(fLYErrorA,2) + pow(fLYErrorB*TMath::Sqrt(ly/1000.),2) + pow(fLYErrorC*ly,2));
    ly = gRandom->Gaus(ly, lySigma);

    Float_t timeSigma = TMath::Sqrt(fTimeErrorBC404A/ly);
    time = gRandom->Gaus(time, timeSigma);

    Float_t neutronProb = NeutronProbabilityBC404(edep,ly);
  
    AddBC404Digi(itHexBC404.first,edep, parentTrackID, ly, time, neutronProb,x_in,y_in,z_in); 
  }
  LOG(DEBUG) << "NDDigis count: " << fNDDigis->GetEntriesFast() << FairLogger::endl;

  LOG(DEBUG) << "BC404Digis count: " << fBC404Digis->GetEntriesFast() << FairLogger::endl;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void ERNDDigitizer::Reset()
{
  if (fNDDigis) {
    fNDDigis->Delete();
  }
  if (fBC404Digis) {
    fBC404Digis->Delete();
  }
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
void ERNDDigitizer::Finish()
{   
}
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
ERNDDigi* ERNDDigitizer::AddNDDigi(Int_t stilbenNb, Float_t edep, Float_t edep_n1, Float_t edep_n2, Float_t edep_mis, Int_t parentTrackID, Float_t ly,
                                 Float_t time,Float_t neutronProb,Float_t x_in,Float_t y_in,Float_t z_in)
{
  ERNDDigi *Digi = new((*fNDDigis)[fNDDigis->GetEntriesFast()])
              ERNDDigi(stilbenNb, edep, edep_n1, edep_n2, edep_mis, parentTrackID, ly, time, neutronProb,x_in,y_in,z_in);
  return Digi;
}
// ----------------------------------------------------------------------------
ERBC404Digi* ERNDDigitizer::AddBC404Digi(Int_t hexNr, Float_t edep, Int_t parentTrackID, Float_t ly,
                                 Float_t time,Float_t neutronProb,Float_t x_in,Float_t y_in,Float_t z_in)
{
  ERBC404Digi *Digi = new((*fBC404Digis)[fBC404Digis->GetEntriesFast()])
              ERBC404Digi(hexNr, edep, parentTrackID, ly, time, neutronProb,x_in,y_in,z_in);
  return Digi;
}
// ----------------------------------------------------------------------------
Float_t ERNDDigitizer::NeutronProbabilityND(Float_t edep, Float_t ly){
  Float_t neutronProb;
  Float_t quench = ly/edep;
  if ((ly > fLYThresholdND) && (quench < fQuenchThresholdND)){
    neutronProb = 1.;
  }
  if ((ly < fLYThresholdND) && (quench < fQuenchThresholdND)){
    neutronProb = fProbabilityNDB+(1-fProbabilityNDB)*(ly/fLYThresholdND);
  }
  if ((ly > fLYThresholdND) && (quench > fQuenchThresholdND)){
    neutronProb = 0.;
  }
  if ((ly < fLYThresholdND) && (quench > fQuenchThresholdND)){
    neutronProb = fProbabilityNDC*(1-ly/fLYThresholdND);
  }
  return neutronProb;
}
// ----------------------------------------------------------------------------
Float_t ERNDDigitizer::NeutronProbabilityBC404(Float_t edep, Float_t ly){
  Float_t neutronProb;
  Float_t quench = ly/edep;
  if ((ly > fLYThresholdBC404) && (quench < fQuenchThresholdBC404)){
    neutronProb = 1.;
  }
  if ((ly < fLYThresholdBC404) && (quench < fQuenchThresholdBC404)){
    neutronProb = fProbabilityBC404B+(1-fProbabilityBC404B)*(ly/fLYThresholdBC404);
  }
  if ((ly > fLYThresholdBC404) && (quench > fQuenchThresholdBC404)){
    neutronProb = 0.;
  }
  if ((ly < fLYThresholdBC404) && (quench > fQuenchThresholdBC404)){
    neutronProb = fProbabilityBC404C*(1-ly/fLYThresholdBC404);
  }
  return neutronProb;
}
//-----------------------------------------------------------------------------
ClassImp(ERNDDigitizer)

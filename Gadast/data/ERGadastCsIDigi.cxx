// -------------------------------------------------------------------------
// -----                       ERGadastCsIDigi source file                -----
// -----           Created 11/12/15  by V.Schetinin        			   -----
// -------------------------------------------------------------------------
#include "ERGadastCsIDigi.h"

#include <iostream>

#include "FairLogger.h"


// -----   Default constructor   -------------------------------------------
ERGadastCsIDigi::ERGadastCsIDigi()
  :fID(-1),
  fEdep(0.)
{
}

ERGadastCsIDigi::ERGadastCsIDigi(Int_t id, Float_t Edep,Int_t wall, Int_t block, Int_t cell, 
Int_t Events_Poisson_Cs, Int_t Events_Poisson_Co, Int_t CsGammas_Before, Int_t CsGammas_After,
Int_t Co1Gammas_Before, Int_t Co1Gammas_After, Int_t Co2Gammas_Before, Int_t Co2Gammas_After)
  :fID(id),
  fEdep(Edep),
  fWall(wall),
  fBlock(block),
  fCell(cell),
  fEvents_Poisson_Cs(Events_Poisson_Cs),
  fEvents_Poisson_Co(Events_Poisson_Co),
  fCsGammas_Before(CsGammas_Before),
  fCsGammas_After(CsGammas_After),
  fCo1Gammas_Before(Co1Gammas_Before),
  fCo1Gammas_After(Co1Gammas_After),
  fCo2Gammas_Before(Co2Gammas_Before),
  fCo2Gammas_After(Co2Gammas_After)
{
}

ERGadastCsIDigi::ERGadastCsIDigi(const ERGadastCsIDigi& right)
   :fID(right.fID),
   fEdep(right.fEdep),
   fWall(right.fWall),
   fBlock(right.fBlock),
   fCell(right.fCell),
   fEvents_Poisson_Cs(right.fEvents_Poisson_Cs),
   fEvents_Poisson_Co(right.fEvents_Poisson_Co),
   fCsGammas_Before(right.fCsGammas_Before),
   fCsGammas_After(right.fCsGammas_After),
   fCo1Gammas_Before(right.fCo1Gammas_Before),
   fCo1Gammas_After(right.fCo1Gammas_After),
   fCo2Gammas_Before(right.fCo2Gammas_Before),
   fCo2Gammas_After(right.fCo2Gammas_After)
{
}



// -----   Destructor   ----------------------------------------------------
ERGadastCsIDigi::~ERGadastCsIDigi()
{
}

// -----   Public method Print   -------------------------------------------
void ERGadastCsIDigi::Print(const Option_t* opt /* = 0 */) const
{
  LOG(INFO) << "ERGadastCsIDigi:  " << FairLogger::endl;
  LOG(INFO) << "    Edep : " << fEdep << FairLogger::endl;
  LOG(INFO) << "    Wall : " << fWall << FairLogger::endl;
  LOG(INFO) << "    Block : " << fBlock << FairLogger::endl;
  LOG(INFO) << "    Cell : " << fCell << FairLogger::endl;
}
// -------------------------------------------------------------------------

ClassImp(ERGadastCsIDigi)

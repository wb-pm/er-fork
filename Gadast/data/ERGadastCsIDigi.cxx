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

ERGadastCsIDigi::ERGadastCsIDigi(Int_t id, Float_t Edep,Float_t EdepSigma,Int_t wall, Int_t block, Int_t cell, 
Int_t Events_Poisson_Cs, Int_t Events_Poisson_Co)
  :fID(id),
  fEdep(Edep),
  fEdepSigma(EdepSigma),
  fWall(wall),
  fBlock(block),
  fCell(cell),
  fEvents_Poisson_Cs(Events_Poisson_Cs),
  fEvents_Poisson_Co(Events_Poisson_Co)
{
}

ERGadastCsIDigi::ERGadastCsIDigi(const ERGadastCsIDigi& right)
   :fID(right.fID),
   fEdep(right.fEdep),
   fEdepSigma(right.fEdepSigma),
   fWall(right.fWall),
   fBlock(right.fBlock),
   fCell(right.fCell),
   fEvents_Poisson_Cs(right.fEvents_Poisson_Cs),
   fEvents_Poisson_Co(right.fEvents_Poisson_Co)
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
  LOG(INFO) << "    EdepSigma : " << fEdepSigma << FairLogger::endl;
  LOG(INFO) << "    Wall : " << fWall << FairLogger::endl;
  LOG(INFO) << "    Block : " << fBlock << FairLogger::endl;
  LOG(INFO) << "    Cell : " << fCell << FairLogger::endl;
}
// -------------------------------------------------------------------------

ClassImp(ERGadastCsIDigi)

#if !defined(__CLING__)
#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairParRootFileIo.h"
#include "FairEventManager.h"
#include "FairMCTracks.h"
#include "FairMCPointDraw.h"
#endif

void eventDisplay()
{
  FairRunAna *fRun= new FairRunAna();
  
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo*  parIo1 = new FairParRootFileIo();
  parIo1->open("par_test.root");
  rtdb->setFirstInput(parIo1);
  //rtdb->print();
  
  fRun->SetInputFile("sim_test.root");
  fRun->SetOutputFile("EventDisplay.root");
  
  FairEventManager *fMan= new FairEventManager();
  FairMCTracks *Track =  new FairMCTracks ("Monte-Carlo Tracks");
  FairMCPointDraw *CsIPoints =   new FairMCPointDraw ("GadastCsIPoint",kOrange,  kFullSquare);
  FairMCPointDraw *LaBrPoints =   new FairMCPointDraw ("GadastLaBrPoint",kOrange,  kFullSquare);
  
  fMan->AddTask(Track);
  fMan->AddTask(CsIPoints);
  fMan->AddTask(LaBrPoints);
  
  fMan->Init();
}

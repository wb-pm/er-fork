#if !defined(__CLING__)
#include "FairEventManager.h"
#include "FairRunAna.h"
#include "FairRuntimeDb.h"
#include "FairParRootFileIo.h"
#include "FairMCTracks.h"
#include "FairMCPointDraw.h"
#endif
void eventDisplay()
{
  FairRunAna *fRun= new FairRunAna();
  
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo*  parIo1 = new FairParRootFileIo();
  parIo1->open("par/par_todo_correction.root"); 
  rtdb->setFirstInput(parIo1);

  fRun->SetInputFile("sim/sim_todo_correction.root");
  fRun->SetOutputFile("EventDisplay.root");
  
  FairEventManager *fMan= new FairEventManager();
  FairMCTracks *Track =  new FairMCTracks ("Monte-Carlo Tracks");
  FairMCPointDraw *AlpidePoints =   new FairMCPointDraw ("AlpidePoint",kOrange,  kFullSquare);
  
  fMan->AddTask(Track);
  fMan->AddTask(AlpidePoints);
  
  fMan->Init();
}
#include "ERDecayer.h"

#include <iostream>

#include "FairLogger.h"

using std::vector;

ERDecayer::ERDecayer(){
}

ERDecayer::~ERDecayer(){
}

Bool_t ERDecayer::Stepping(){
  for (vector<ERDecay*>::iterator it = fDecays.begin(); it != fDecays.end(); ++it){
    ERDecay* decay = (*it);
    if (!decay->Stepping())
      return kFALSE;
  }
  return kTRUE;
}

Bool_t ERDecayer::Init(){
  for (vector<ERDecay*>::iterator it = fDecays.begin(); it != fDecays.end(); ++it){
    ERDecay* decay = (*it);
    LOG(INFO) << "Decay " << decay->GetName() << " initialized!" << FairLogger::endl;
    if (!decay->Init())
      return kFALSE;
  }
  return kTRUE;
} 

void ERDecayer::BeginEvent(){
  for (vector<ERDecay*>::iterator it = fDecays.begin(); it != fDecays.end(); ++it){
    ERDecay* decay = (*it);
    decay->BeginEvent();
  }
}

void ERDecayer::FinishEvent(){
  for (vector<ERDecay*>::iterator it = fDecays.begin(); it != fDecays.end(); ++it){
    ERDecay* decay = (*it);
    decay->FinishEvent();
  }
}

void ERDecayer::AddDecay(ERDecay* decay) {
  LOG(INFO) << "Decay " << decay->GetName() << " added!" << FairLogger::endl;
  fDecays.push_back(decay);
}

ClassImp(ERDecayer)
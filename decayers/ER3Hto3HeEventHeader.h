#ifndef ER3Hto3HeEventHeader_H_
#define ER3Hto3HeEventHeader_H_

#include "TLorentzVector.h"
#include "TArrayI.h"

#include "ERDecayMCEventHeader.h"

class ER3Hto3HeEventHeader : public ERDecayMCEventHeader {
private:
  TLorentzVector fH3;
  TLorentzVector fH1;
  TLorentzVector fn1;
  TLorentzVector fHe3;
    
  Int_t fTrigger = 0;
  Int_t fTriggerPriority = 0;
  float fTime = -1.;
public:
  ER3Hto3HeEventHeader() : fTrigger(0), fTriggerPriority(0) {}
  void SetData(const TVector3& position, const TLorentzVector& H3,
               const TLorentzVector& H1, const TLorentzVector& He3,
               const TLorentzVector& n1,float time);
  
  void SetTrigger(Int_t trigger) { fTrigger = trigger; }
  
  Int_t GetTrigger() const {return fTrigger;}
  Int_t GetTriggerPriority() const {return fTriggerPriority;}
  TLorentzVector GetH3() const { return fH3; }
  TLorentzVector GetH1() const { return fH1; }
  TLorentzVector GetN1() const { return fn1; }
  TLorentzVector GetHe3() const { return fHe3; }

  void Clear();

  ClassDef(ER3Hto3HeEventHeader,1)
};

#endif

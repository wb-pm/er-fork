/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERDecay7CEventHeader_H
#define ERDecay7CEventHeader_H

#include "TLorentzVector.h"
#include "TArrayI.h"

#include "ERDecayMCEventHeader.h"

class ERDecay7CEventHeader : public ERDecayMCEventHeader {
private:
  TLorentzVector fC9;
  TLorentzVector fC7;
  TLorentzVector fHe3;
  TLorentzVector fp1;
  TLorentzVector fp2;
  TLorentzVector fp3;
  TLorentzVector fp4;
  
  Int_t fTrigger = 0;
  Int_t fTriggerPriority = 0;
  float fTime = -1.;
public:
  ERDecay7CEventHeader() : fTrigger(0), fTriggerPriority(0) {}
  void SetData(const TVector3& position, const TLorentzVector& C9,
               const TLorentzVector& C7,
               const TLorentzVector& He3, const TLorentzVector& p1,
               const TLorentzVector& p2, const TLorentzVector& p3,
               const TLorentzVector& p4, float time);
  
  void SetTrigger(Int_t trigger) { fTrigger = trigger; }
  
  Int_t GetTrigger() const {return fTrigger;}
  Int_t GetTriggerPriority() const {return fTriggerPriority;}
  TLorentzVector GetC9() const { return fC9; }
  TLorentzVector GetC7() const { return fC7; }
  TLorentzVector GetHe3() const { return fHe3; }
  TLorentzVector Getp1() const { return fp1; }
  TLorentzVector Getp2() const { return fp2; }
  TLorentzVector Getp3() const { return fp3; }
  TLorentzVector Getp4() const { return fp4; }

  void Clear();

  ClassDef(ERDecay7CEventHeader,1)
};

#endif

/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERDecay7CEventHeader.h"

#include "FairLogger.h"

void ERDecay7CEventHeader::SetData(const TVector3& position, const TLorentzVector& C9, 
                                    const TLorentzVector& C7,
                                    const TLorentzVector& He3, const TLorentzVector& p1,
                                    const TLorentzVector& p2,
                                    const TLorentzVector& p3, const TLorentzVector& p4,
                                    const float time) 
{
  fReactionPos = position;
  fC9 = C9;
  fC7 = C7;
  fHe3 = He3;
  fp1 = p1;
  fp2 = p2;
  fp3 = p3;
  fp4 = p4;
  fTime = time;
}
// -------------------------------------------------------------------------
void ERDecay7CEventHeader::Clear() {
  ERDecayMCEventHeader::Clear();
  fC9.SetXYZM(0, 0, 0, 0);
  fC7.SetXYZM(0, 0, 0, 0);
  fHe3.SetXYZM(0, 0, 0, 0);
  fp1.SetXYZM(0, 0, 0, 0);
  fp2.SetXYZM(0, 0, 0, 0);
  fp3.SetXYZM(0, 0, 0, 0);
  fp4.SetXYZM(0, 0, 0, 0);
  fTrigger = 0;
  fTriggerPriority = 0;
  fTime = -1.;
}
// -------------------------------------------------------------------------

ClassImp(ERDecay7CEventHeader)

// -----                      EREXP1811EventHeader source file              -----
// -----                  Created 03/16  by V. Schetinin               -----
// -------------------------------------------------------------------------
#include "ER3Hto3HeEventHeader.h"

#include "FairLogger.h"

void ER3Hto3HeEventHeader::SetData(const TVector3& position, const TLorentzVector& H3,
                                    const TLorentzVector& H1, const TLorentzVector& n1,
                                    const TLorentzVector& He3, float time) 
{
  fReactionPos = position;
  fH3 = H3;
  fH1 = H1;
  fn1 = n1;
  fHe3 = He3;
  fTime = time;
}
// -------------------------------------------------------------------------
void ER3Hto3HeEventHeader::Clear() {
  ERDecayMCEventHeader::Clear();
  fH3.SetXYZM(0, 0, 0, 0);
  fH1.SetXYZM(0, 0, 0, 0);
  fn1.SetXYZM(0, 0, 0, 0);
  fHe3.SetXYZM(0, 0, 0, 0);
  fTrigger = 0;
  fTriggerPriority = 0;
  fTime = -1.;
}
// -------------------------------------------------------------------------

ClassImp(ER3Hto3HeEventHeader)

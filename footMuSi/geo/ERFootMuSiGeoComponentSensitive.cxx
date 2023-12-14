/* ERQTelescopeCsIDigi and ERQTelescopeSiDigi removed
Vitaliy Schetinin authored and Vitaliy Schetinin committed on Aug 6, 2020 */
#include "ERFootMuSiGeoComponentSensitive.h"

#include <TXMLAttr.h>

//--------------------------------------------------------------------------------------------------
TString ERFootMuSiGeoComponentSensitive::GetBranchNamePrefix(
    SensitiveType sensitiveType, ERDataObjectType objectType) const {
  return TString("FootMuSi") + ERDataObjectTypeStr(objectType) + "_" + GetVolumeName();
}
//--------------------------------------------------------------------------------------------------
std::list<TString> ERFootMuSiGeoComponentSensitive::GetBranchNames(ERDataObjectType objectType) const {
  std::list<TString> branchNames;
  for (const auto orientation : GetOrientationsAroundZ()) {
    for (const auto channelSide : GetChannelSides()) {
      branchNames.push_back(GetBranchName(objectType, orientation, channelSide));
    }
  }
  return branchNames;
}
//--------------------------------------------------------------------------------------------------
void ERFootMuSiGeoComponentSensitive::FillTwoSidedChannelAttribute(const TList* attributes) {
  TIter next(attributes);
  while (auto* attr = static_cast<TXMLAttr*>(next())) {
    if (!strcasecmp("twoSidedChannel", attr->GetName()) && !strcasecmp("yes", attr->GetValue())) { 
      fHasTwoSidedChannel = true;
    }
  }
}
//--------------------------------------------------------------------------------------------------
ClassImp(ERFootMuSiGeoComponentSensitive)
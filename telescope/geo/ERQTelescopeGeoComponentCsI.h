/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERQTelescopeGeoComponentCsI_H
#define ERQTelescopeGeoComponentCsI_H

#include "ERTelescopeGeoComponentSensitive.h"

#include "TString.h"
#include "TVector3.h"

class ERQTelescopeGeoComponentCsI : public ERTelescopeGeoComponentSensitive {
public:
  ERQTelescopeGeoComponentCsI() = default;
  ERQTelescopeGeoComponentCsI(const TString& typeFromXML, const TString& id)
    : ERTelescopeGeoComponentSensitive(typeFromXML, id) {}
  ERQTelescopeGeoComponentCsI(const TString& typeFromXML, const TString& id, 
                              const TVector3& position, const TVector3& rotation)
    : ERTelescopeGeoComponentSensitive(typeFromXML, id, position, rotation) {}
  virtual ~ERQTelescopeGeoComponentCsI() = default;
  virtual void ConstructGeometryVolume(void);
  virtual TString GetBranchName(ERDataObjectType object, 
                                OrientationAroundZ orientationAroundZ = OrientationAroundZ::Default,
                                ChannelSide side = ChannelSide::None) const;
  virtual std::list<OrientationAroundZ> GetOrientationsAroundZ() const;
  virtual std::list<ChannelSide> GetChannelSides() const;
  virtual Int_t GetChannelFromSensitiveNodePath(
    const TString& path, OrientationAroundZ orientation = OrientationAroundZ::Default) const;
private:
  virtual void ParseXmlParameters();
  Int_t    fCubesCountX = 0;
  Int_t    fCubesCountY = 0;
  Double_t fSplitSize = 0.;
  Double_t fDeadLayer = 0.;
  ClassDef(ERQTelescopeGeoComponentCsI,1)
};
#endif

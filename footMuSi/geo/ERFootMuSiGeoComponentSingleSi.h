/* July 31, 2020 at 7:20 AM

Track finding for R telescope */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSiGeoComponentSingleSi_H
#define ERFootMuSiGeoComponentSingleSi_H

#include "ERFootMuSiGeoComponentSensitive.h"

#include "TString.h"
#include "TVector3.h"

class ERFootMuSiGeoComponentSingleSi : public ERFootMuSiGeoComponentSensitive {
public:
  ERFootMuSiGeoComponentSingleSi() = default;
  ERFootMuSiGeoComponentSingleSi(const TString& typeFromXML, const TString& id,
                                   const TString& orientAroundZ); 
  ERFootMuSiGeoComponentSingleSi(const TString& typeFromXML, const TString& id, 
                                   const TVector3& position, const TVector3& rotation,
                                   const TString& orientAroundZ);
  virtual TString GetBranchName(ERDataObjectType object, 
                                OrientationAroundZ orientationAroundZ = OrientationAroundZ::Default,
                                ChannelSide side = ChannelSide::None) const;
  virtual std::list<OrientationAroundZ> GetOrientationsAroundZ() const;
  virtual std::list<ChannelSide> GetChannelSides() const;
  virtual Int_t GetChannelFromSensitiveNodePath( const TString& path, OrientationAroundZ orientation = OrientationAroundZ::Default) const;
  virtual void ConstructGeometryVolume(void);
protected:
  virtual void ParseXmlParameters();
  OrientationAroundZ fOrientAroundZ = OrientationAroundZ::Default;
  Double_t fDeadLayerThicknessFrontSide = 0.;
  Double_t fDeadLayerThicknessBackSide = 0.;
  Int_t    fStripCount = 0;
  Double_t fSensX = 0.;
  Double_t fSensY = 0.;
  Double_t fSensZ = 0.;
  ClassDef(ERFootMuSiGeoComponentSingleSi,1)
};
#endif

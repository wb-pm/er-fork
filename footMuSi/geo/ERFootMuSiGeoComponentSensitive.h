/* Radial telescopes: Simulation of single station
Vitaliy Schetinin authored and Vitaliy Schetinin committed on Jul 26, 2020  */
/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERFootMuSiGeoComponentSensitive_H
#define ERFootMuSiGeoComponentSensitive_H

#include "TList.h"

#include "ERGeoComponent.h"

class ERFootMuSiGeoComponentSensitive : public ERGeoComponent {
public:
  ERFootMuSiGeoComponentSensitive() = default;
  ERFootMuSiGeoComponentSensitive(const TString& typeFromXML, const TString& id)
    : ERGeoComponent(typeFromXML, id) {}
  ERFootMuSiGeoComponentSensitive(const TString& typeFromXML, const TString& id, 
                           const TVector3& position, const TVector3& rotation)
    : ERGeoComponent(typeFromXML, id, position, rotation) {}
  virtual ~ERFootMuSiGeoComponentSensitive() = default;
  Bool_t HasTwoSidedChannel() const { return fHasTwoSidedChannel; }
  virtual std::list<TString> GetBranchNames(ERDataObjectType object) const;
  virtual TString GetBranchName(ERDataObjectType object, 
                                OrientationAroundZ orientationAroundZ = OrientationAroundZ::Default,
                                ChannelSide side = ChannelSide::None) const = 0;
  virtual std::list<OrientationAroundZ> GetOrientationsAroundZ() const = 0;
  virtual std::list<ChannelSide> GetChannelSides() const = 0;
  virtual Int_t GetChannelFromSensitiveNodePath(
      const TString& path, OrientationAroundZ orientation = OrientationAroundZ::Default) const = 0;
protected:
  TString GetBranchNamePrefix(SensitiveType sensitiveType, ERDataObjectType object) const;
  void FillTwoSidedChannelAttribute(const TList* attributes);
  TString  fMedia;
  Double_t fSizeX = 0.;
  Double_t fSizeY = 0.;
  Double_t fSizeZ = 0.;
  Bool_t fHasTwoSidedChannel = false;
  ClassDef(ERFootMuSiGeoComponentSensitive,1)
};

#endif

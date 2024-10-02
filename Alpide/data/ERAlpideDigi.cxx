/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include "ERAlpideDigi.h"

// -----   Default constructor (not to be used)  -------------------------------------------
ERAlpideDigi::ERAlpideDigi()
  :fID(-1),
  fPixelNoX(-1),
  fPixelNoY(-1),
  fEdep(-1),
  fChipID(-1)
{
}
// -----   Constructor with parameters   -----------------------------------
ERAlpideDigi::ERAlpideDigi(Int_t ID, Int_t pixelNoX, Int_t pixelNoY,Double_t edep, Int_t chipID)
  :fID(ID),
  fPixelNoX(pixelNoX),
  fPixelNoY(pixelNoY),
  fEdep(edep),
  fChipID(chipID)
{
}
// -----   Copy constructor   -----------------------------------
ERAlpideDigi::ERAlpideDigi(const ERAlpideDigi& right)
  :fID(right.fID),
  fPixelNoX(right.fPixelNoX),
  fPixelNoY(right.fPixelNoY),
  fEdep(right.fEdep),
  fChipID(right.fChipID)
{
}
// -----   Destructor   -----------------------------------
ERAlpideDigi::~ERAlpideDigi()
{
}
ClassImp(ERAlpideDigi)

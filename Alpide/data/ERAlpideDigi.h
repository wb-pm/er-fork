/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERAlpideDigi_H
#define ERAlpideDigi_H


#include "FairMultiLinkedData.h"

/** @class ERAlpideDigitizer
 ** @brief The data class of Alpide pixel detector response 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
**/

class ERAlpideDigi : public FairMultiLinkedData
{
public:

  /** Default constructor **/
    ERAlpideDigi();
  /** Constructor with parameters **/
    ERAlpideDigi(Int_t fID, Int_t pixelNoX, Int_t pixelNoY, Double_t edep, Int_t chipID);
  /** Copy constructor **/
    ERAlpideDigi(const ERAlpideDigi&);

  /** Destructor **/
    ~ERAlpideDigi();

protected:
//Index of digi in the collection
    Int_t fID;
    Int_t fPixelNoX;
    Int_t fPixelNoY;
    // ID of the chip where the pixel is located
    Int_t fChipID;

    Double_t fEdep;
    // Energy below which pixels are not activated

ClassDef(ERAlpideDigi, 1);
};

#endif

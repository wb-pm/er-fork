/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERAlpideDigitizer_H
#define ERAlpideDigitizer_H

#include "FairTask.h"

#include "ERAlpideSetup.h"
#include "ERAlpideDigi.h"

/** @class ERAlpideDigitizer
 ** @brief The class for Alpide pixel detector response simulation
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
**/

class ERAlpideDigitizer : public FairTask
{
public:
    ERAlpideDigitizer();
    ~ERAlpideDigitizer();
  /** Virtual method Init **/
  virtual InitStatus Init();

  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  /** Virtual method Finish **/
  virtual void Finish();

  /** Virtual method Reset **/
  virtual void Reset();

  /** Modifiers **/
  void SetEnergyThreshold(Double_t energyThreshold){fEnergyThreshold = energyThreshold;}
protected:

    TClonesArray* fAlpidePoints = nullptr;

    TClonesArray* fAlpideDigis = nullptr;

    ERAlpideSetup* fAlpideSetup = nullptr;

    Double_t fEnergyThreshold; //! Energy threshold for activating a pixel
  
    ERAlpideDigi* AddAlpideDigi(Int_t pixelNoX, Int_t pixelNoY, Double_t pixelZ, Double_t edep, Int_t chipID = -1);
private:
  virtual void SetParContainers();

    ClassDef(ERAlpideDigitizer, 1);
};


#endif

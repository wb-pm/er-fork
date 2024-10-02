/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#include <map>

#include "ERAlpideDigitizer.h"

#include "TClonesArray.h"

#include "FairTask.h"
#include "FairLogger.h"
#include "FairRun.h"

#include "ERAlpidePoint.h"
 // ----------------------------------------------------------------------------

ERAlpideDigitizer::ERAlpideDigitizer()
    : FairTask("ERAlpide digitization scheme")
{

}
// ----------------------------------------------------------------------------

ERAlpideDigitizer::~ERAlpideDigitizer()
{
    delete fAlpideSetup;
}
// ----------------------------------------------------------------------------
void ERAlpideDigitizer::SetParContainers()
{
    // Get run and runtime database
    FairRun* run = FairRun::Instance();
    if (!run)
        LOG(FATAL) << "No analysis run!" << FairLogger::endl;

    FairRuntimeDb* rtdb = run->GetRuntimeDb();
    if (!rtdb)
        LOG(FATAL) << "No runtime database!" << FairLogger::endl;
}
// ----------------------------------------------------------------------------
InitStatus ERAlpideDigitizer::Init()
{
    FairRootManager* ioman = FairRootManager::Instance();
    if (!ioman)
        LOG(FATAL) << "No FairRootManager" << FairLogger::endl;

    fAlpidePoints = (TClonesArray*)ioman->GetObject("AlpidePoint");


    //register output array

    fAlpideDigis = new TClonesArray("ERAlpideDigi", 1000);

    ioman->Register("AlpideDigi", "Digital response in Alpide", fAlpideDigis, kTRUE);

    fAlpideSetup = ERAlpideSetup::Instance();
    if (!fAlpideSetup->Init()) {
        LOG(ERROR) << "Problems with ERAlpideSetup initialization!" << FairLogger::endl;
    }
    return kSUCCESS;
}
// -------------------------------------------------------------------------

// -----   Public method Exec   --------------------------------------------
void ERAlpideDigitizer::Exec(Option_t* opt)
{
    // Reset entries in output arrays
    Reset();

    // Temporary map for summing up energies
    std::map<std::pair<Int_t,Int_t>, Double_t> pixelEnergyMap;
    // Going through the points
    for (Int_t iAlpidePoint = 0; iAlpidePoint < fAlpidePoints->GetEntriesFast(); iAlpidePoint++)
    {
        ERAlpidePoint* point = (ERAlpidePoint*)fAlpidePoints->At(iAlpidePoint);
        pixelEnergyMap[{point->GetPixelNoX(),point->GetPixelNoY()}] += point->GetELoss();

        LOG(DEBUG) << "Current point number: " << iAlpidePoint << " with pixel number X = " << point->GetPixelNoX() << " and Y = " << point->GetPixelNoY() << FairLogger::endl << ", total energy deposition " << pixelEnergyMap[{point->GetPixelNoX(),point->GetPixelNoY()}] << FairLogger::endl;
    }
    for (const auto& pixel : pixelEnergyMap) {
        Int_t pixelX = pixel.first.first;
        Int_t pixelY = pixel.first.second;
        Double_t totalEnergy = pixel.second;
        if (totalEnergy >= fEnergyThreshold) {
            AddAlpideDigi(pixelX,pixelY,totalEnergy);
        } 
    }
}
//----------------------------------------------------------------------------
void ERAlpideDigitizer::Reset()
{
    if (fAlpideDigis) {
        fAlpideDigis->Delete();
    }
}
// ----------------------------------------------------------------------------
void ERAlpideDigitizer::Finish()
{
    LOG(INFO) << "========== Finish of ERAlpideDigitizer ==================" << FairLogger::endl;
}
// ----------------------------------------------------------------------------
ERAlpideDigi* ERAlpideDigitizer::AddAlpideDigi(Int_t pixelNoX, Int_t pixelNoY, Double_t edep, Int_t chipID)
{
    ERAlpideDigi* digi = new((*fAlpideDigis)[fAlpideDigis->GetEntriesFast()])
        ERAlpideDigi(fAlpideDigis->GetEntriesFast(), pixelNoX, pixelNoY, edep, chipID);
    return digi;
}
// ----------------------------------------------------------------------------
ClassImp(ERAlpideDigitizer)
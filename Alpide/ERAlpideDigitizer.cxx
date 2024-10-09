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
    LOG(INFO) << "[ERAlpideDigitizer]------------Started--------------------------------------"
        << FairLogger::endl;
    // Reset entries in output arrays
    Reset();

    // Temporary map for summing up energies
    std::map<std::pair<Int_t,Int_t>, Double_t> pixelEnergyMap;
    // TODO: maybe figure out a better way for treating the z coordinate
    Double_t pixelZ;
    // Going through the points and summing them by pixels
    for (Int_t iAlpidePoint = 0; iAlpidePoint < fAlpidePoints->GetEntriesFast(); iAlpidePoint++)
    {
        ERAlpidePoint* point = (ERAlpidePoint*)fAlpidePoints->At(iAlpidePoint);
        pixelEnergyMap[{point->GetPixelNoX(),point->GetPixelNoY()}] += point->GetEnergyLoss();
        pixelZ = point->GetZIn();
        point->Print();
    }
    for (const auto& pixel : pixelEnergyMap) {
        Int_t pixelNoX = pixel.first.first;
        Int_t pixelNoY = pixel.first.second;
        Double_t totalEnergy = pixel.second;
        if (totalEnergy >= fEnergyThreshold) {
            AddAlpideDigi(pixelNoX,pixelNoY,pixelZ, totalEnergy);
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
    LOG(INFO) << "[ERAlpideDigitizer]------------Finished--------------------------------------"
    << "The number of digis is: " << fAlpideDigis->GetEntriesFast() << FairLogger::endl;
}
// ----------------------------------------------------------------------------
ERAlpideDigi* ERAlpideDigitizer::AddAlpideDigi(Int_t pixelNoX, Int_t pixelNoY, Double_t pixelZ, Double_t edep, Int_t chipID)
{
    ERAlpideDigi* digi = new((*fAlpideDigis)[fAlpideDigis->GetEntriesFast()])
        ERAlpideDigi(fAlpideDigis->GetEntriesFast(), pixelNoX, pixelNoY, pixelZ, edep, chipID);
    return digi;
}
// ----------------------------------------------------------------------------
ClassImp(ERAlpideDigitizer)
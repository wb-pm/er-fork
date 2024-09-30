/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERAlpideSetup.h"

#include "TMath.h"
#include "TGeoManager.h"
#include "TGeoMatrix.h"
#include "TGeoNode.h"
#include "TGeoCompositeShape.h"
#include "TGeoBoolNode.h"

#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

ERAlpideSetup* ERAlpideSetup::fInstance = NULL;
TGeoPhysicalNode* ERAlpideSetup::fAlpideNode;
//----------------------------------------------------------------------------
ERAlpideSetup* ERAlpideSetup::Instance(){
    if (fInstance == NULL)
        return new ERAlpideSetup();
    else
        return fInstance;
}

ERAlpideSetup::ERAlpideSetup()
{
	FairRun* run = FairRun::Instance();
    if ( ! run ) 
    {LOG(FATAL) << "ERAlpideSetup: No analysis run" << FairLogger::endl;}

    FairRuntimeDb* rtdb = run->GetRuntimeDb();
    if ( ! rtdb ) 
    {LOG(FATAL) << "ERAlpideSetup: No runtime database" << FairLogger::endl;}

}
//----------------------------------------------------------------------------
Bool_t ERAlpideSetup::Init(){
	// --- Get cave (top node)
	TGeoManager* geo = gGeoManager;
	if (!gGeoManager){
        LOG(FATAL) << "ERAlpideSetup: Can't find gGeoManager" << FairLogger::endl;
		return kFALSE;
	}
	LOG(INFO) << "Reading geometry from TGeoManager " << geo->GetName() << FairLogger::endl;
  	geo->CdTop();
  	TGeoNode* cave = geo->GetCurrentNode();
  	 // --- Get top Alpide node
	TGeoNode* Alpide = NULL;
	for (Int_t iNode = 0; iNode < cave->GetNdaughters(); iNode++) {
		TString name = cave->GetDaughter(iNode)->GetName();
		if ( name.Contains("Alpide", TString::kIgnoreCase) ) {
			Alpide = cave->GetDaughter(iNode);
  			geo->CdDown(iNode);
  			LOG(INFO) << "Alpide top node is " << Alpide->GetName() << FairLogger::endl;
		  	break;
		}
	}

	if ( ! Alpide ) {
		LOG(FATAL) << "No top Alpide node found in geometry!" << FairLogger::endl;
		return kFALSE;
	}

  	// --- Create physical node for sts
    TString path = cave->GetName();
    path = path + "/" + Alpide->GetName();
    fAlpideNode = new TGeoPhysicalNode(path);
    
    return kTRUE;
}
//----------------------------------------------------------------------------
ERAlpideSetup::~ERAlpideSetup()
{
}

ClassImp(ERAlpideSetup)
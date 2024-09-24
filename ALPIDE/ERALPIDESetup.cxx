/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERALPIDESetup.h"

#include "TMath.h"
#include "TGeoManager.h"
#include "TGeoMatrix.h"
#include "TGeoNode.h"
#include "TGeoCompositeShape.h"
#include "TGeoBoolNode.h"

#include "FairRun.h"
#include "FairRuntimeDb.h"
#include "FairLogger.h"

ERALPIDESetup* ERALPIDESetup::fInstance = NULL;
TGeoPhysicalNode* ERALPIDESetup::fALPIDENode;
//----------------------------------------------------------------------------
ERALPIDESetup* ERALPIDESetup::Instance(){
    if (fInstance == NULL)
        return new ERALPIDESetup();
    else
        return fInstance;
}

ERALPIDESetup::ERALPIDESetup()
{
	FairRun* run = FairRun::Instance();
    if ( ! run ) 
    {LOG(FATAL) << "ERALPIDESetup: No analysis run" << FairLogger::endl;}

    FairRuntimeDb* rtdb = run->GetRuntimeDb();
    if ( ! rtdb ) 
    {LOG(FATAL) << "ERALPIDESetup: No runtime database" << FairLogger::endl;}

}
//----------------------------------------------------------------------------
Bool_t ERALPIDESetup::Init(){
	// --- Get cave (top node)
	TGeoManager* geo = gGeoManager;
	if (!gGeoManager){
        LOG(FATAL) << "ERALPIDESetup: Can't find gGeoManager" << FairLogger::endl;
		return kFALSE;
	}
	LOG(INFO) << "Reading geometry from TGeoManager " << geo->GetName() << FairLogger::endl;
  	geo->CdTop();
  	TGeoNode* cave = geo->GetCurrentNode();
  	 // --- Get top ALPIDE node
	TGeoNode* ALPIDE = NULL;
	for (Int_t iNode = 0; iNode < cave->GetNdaughters(); iNode++) {
		TString name = cave->GetDaughter(iNode)->GetName();
		if ( name.Contains("ALPIDE", TString::kIgnoreCase) ) {
			ALPIDE = cave->GetDaughter(iNode);
  			geo->CdDown(iNode);
  			LOG(INFO) << "ALPIDE top node is " << ALPIDE->GetName() << FairLogger::endl;
		  	break;
		}
	}

	if ( ! ALPIDE ) {
		LOG(FATAL) << "No top ALPIDE node found in geometry!" << FairLogger::endl;
		return kFALSE;
	}

  	// --- Create physical node for sts
    TString path = cave->GetName();
    path = path + "/" + ALPIDE->GetName();
    fALPIDENode = new TGeoPhysicalNode(path);
    
    return kTRUE;
}
//----------------------------------------------------------------------------
ERALPIDESetup::~ERALPIDESetup()
{
}

ClassImp(ERALPIDESetup)
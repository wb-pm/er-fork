/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERALPIDESetup_H
#define ERALPIDESetup_H

#include "TGeoPhysicalNode.h"

/** @class ERALPIDESetup
 ** @brief Class for initializing ALPIDE geometry 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
**/

class ERALPIDESetup
{
public:
	static ERALPIDESetup* Instance();
	static Bool_t Init();
	ERALPIDESetup();
    ~ERALPIDESetup();
private:
	static ERALPIDESetup* fInstance;
	static TGeoPhysicalNode* fALPIDENode;
};

#endif


/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERAlpideSetup_H
#define ERAlpideSetup_H

#include "TGeoPhysicalNode.h"

/** @class ERAlpideSetup
 ** @brief Class for reading Alpide geometry 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
 **
**/

class ERAlpideSetup
{
public:
	static ERAlpideSetup* Instance();
	static Bool_t Init();
	ERAlpideSetup();
    ~ERAlpideSetup();
private:
	static ERAlpideSetup* fInstance;
	static TGeoPhysicalNode* fAlpideNode;
};

#endif


/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERAlpideGeoPar_H
#define ERAlpideGeoPar_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

/** @class ERAlpideGeoPar
 ** @brief 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
**/

class ERAlpideGeoPar : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    ERAlpideGeoPar(const char* name="ERAlpideGeoPar",
                           const char* title="Alpide Geometry Parameters",
                           const char* context="TestDefaultContext");
    ~ERAlpideGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    ERAlpideGeoPar(const ERAlpideGeoPar&);
    ERAlpideGeoPar& operator=(const ERAlpideGeoPar&);

    ClassDef(ERAlpideGeoPar,1)
};

#endif

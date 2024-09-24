/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/

#ifndef ERALPIDEGeoPar_H
#define ERALPIDEGeoPar_H

#include "FairParGenericSet.h"

class TObjArray;
class FairParamList;

/** @class ERALPIDEGeoPar
 ** @brief 
 ** @author B.Khamidullin <khamidullinbr@jinr.ru>
 ** @version 1.0
**/

class ERALPIDEGeoPar : public FairParGenericSet
{
  public:

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoSensNodes;

    /** List of FairGeoNodes for sensitive  volumes */
    TObjArray*      fGeoPassNodes;

    ERALPIDEGeoPar(const char* name="ERALPIDEGeoPar",
                           const char* title="ALPIDE Geometry Parameters",
                           const char* context="TestDefaultContext");
    ~ERALPIDEGeoPar(void);
    void clear(void);
    void putParams(FairParamList*);
    Bool_t getParams(FairParamList*);
    TObjArray* GetGeoSensitiveNodes() {return fGeoSensNodes;}
    TObjArray* GetGeoPassiveNodes()   {return fGeoPassNodes;}

  private:
    ERALPIDEGeoPar(const ERALPIDEGeoPar&);
    ERALPIDEGeoPar& operator=(const ERALPIDEGeoPar&);

    ClassDef(ERALPIDEGeoPar,1)
};

#endif

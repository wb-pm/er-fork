/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#ifndef ERFootMuSiVertex_H
#define ERFootMuSiVertex_H

#include "TObject.h"

class ERFootMuSiVertex : public TObject{
public:
	ERFootMuSiVertex();
	ERFootMuSiVertex(Float_t x, Float_t y, Float_t z);
	
	void AddTrack(Int_t id);

	Int_t TrackNb() const {return fTracksNb;}
	Int_t Track(Int_t id) const;
	Float_t X() const {return fX;}
	Float_t Y() const {return fY;}
	Float_t Z() const {return fZ;}

	void SetX(Float_t x){fX = x;}
	void SetY(Float_t y){fY = y;}
	void SetZ(Float_t z){fZ = z;}

private:
	Int_t fTracksID[3];
	Int_t fTracksNb;
	Float_t fX, fY, fZ;

	ClassDef(ERFootMuSiVertex, 1)
};
#endif

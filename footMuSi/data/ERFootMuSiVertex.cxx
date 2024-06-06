/********************************************************************************
 *              Copyright (C) Joint Institute for Nuclear Research              *
 *                                                                              *
 *              This software is distributed under the terms of the             *
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
#include "ERFootMuSiVertex.h"

#include <iostream>


ERFootMuSiVertex::ERFootMuSiVertex():
	fTracksNb(0)
{

}

ERFootMuSiVertex::ERFootMuSiVertex(Double_t x, Double_t y, Double_t z):
	fTracksNb(0), fX(x), fY(y), fZ(z)
{

}

ERFootMuSiVertex::ERFootMuSiVertex(const ERFootMuSiVertex& right):
	fTracksNb(right.fTracksNb), fX(right.fX), fY(right.fY), fZ(right.fZ)
{

}

// -----   Destructor   ----------------------------------------------------
ERFootMuSiVertex::~ERFootMuSiVertex()
{
}
// -------------------------------------------------------------------------

void ERFootMuSiVertex::AddTrack(Int_t id){
	Bool_t founded = kFALSE;
	for (Int_t iTrack = 0; iTrack < fTracksNb; iTrack++){
		if (fTracksID[iTrack] == id){
			founded = kTRUE;
		}
	}
	if (fTracksNb < 3){
		if (!founded)
			fTracksID[fTracksNb++] = id;
	}
	
	if (fTracksNb > 3){ 
		std::cerr << "Big track count in vertex!" << std::endl;
	}
}

Int_t ERFootMuSiVertex::Track(Int_t id) const{
	if (id >= fTracksNb){
		std::cerr << "There is no such number of tracks!" << std::endl;
	}
	return fTracksID[id];
}

ClassImp(ERFootMuSiVertex)
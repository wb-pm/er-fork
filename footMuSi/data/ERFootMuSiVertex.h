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
#include "ERFootMuSiTrack.h"

class ERFootMuSiVertex : public TObject{
public:

/* Default constructor */
	ERFootMuSiVertex();
/* Copy constructor */
	ERFootMuSiVertex(const ERFootMuSiVertex&);
/* Constructor with arguments */
	ERFootMuSiVertex(Double_t x, Double_t y, Double_t z);

/* Destructor */
	virtual ~ERFootMuSiVertex();

	void AddTrack(Int_t id);
/* 	void AddTrack(ERFootMuSiTrack track); */

	Int_t TrackNb() const {return fTracksNb;}
	Int_t Track(Int_t id) const;
	Double_t X() const {return fX;}
	Double_t Y() const {return fY;}
	Double_t Z() const {return fZ;}

	void SetX(Double_t x){fX = x;}
	void SetY(Double_t y){fY = y;}
	void SetZ(Double_t z){fZ = z;}
	void AddTrackDistance(Double_t trackDistance){fTrackDistance = trackDistance;}
	void AddDistanceBetweenVertices(Double_t distanceBetweenVertices){fDistanceBetweenVertices = distanceBetweenVertices;}

  Double_t GetVerticesDistance(){return fDistanceBetweenVertices;}
private:
/* 	std::vector<ERFootMuSiTrack> fTracks; */
	Int_t fTracksID[3];
	Int_t fTracksNb;
	Double_t fX, fY, fZ;
	Double_t fTrackDistance;
	Double_t fDistanceBetweenVertices;

	ClassDef(ERFootMuSiVertex, 1)
};
#endif

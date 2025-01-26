// -------------------------------------------------------------------------
// -----                      ERGadastCsIDigi header file             -----
// -----                  Created 03/15  by V. Schetinin               -----
// -------------------------------------------------------------------------

#ifndef ERGadastCsIDigi_H
#define ERGadastCsIDigi_H


#include "TObject.h"
#include "TVector3.h"

#include "FairMultiLinkedData.h"

class ERGadastCsIDigi : public FairMultiLinkedData
{
 public:
  /** Default constructor **/
  ERGadastCsIDigi();
  
  /** Constructor with arguments
   **/
  ERGadastCsIDigi(Int_t id, Float_t Edep,Float_t EdepSigma, Int_t wall, Int_t block, Int_t cell, 
Int_t Events_Poisson_Cs, Int_t Events_Poisson_Co);
                   
  /** Copy constructor **/
  ERGadastCsIDigi(const ERGadastCsIDigi&);

  /** Destructor **/
  virtual ~ERGadastCsIDigi();

  ERGadastCsIDigi& operator=(const ERGadastCsIDigi&) { return *this; }

  /** Output to screen **/
  virtual void Print(const Option_t* opt = 0) const;

  /* Accessors */
  Int_t ID () const {return fID;}
  Float_t Edep() const {return fEdep;}
  Float_t EdepSigma() const {return fEdepSigma;}
  
 protected:
  Int_t fID;
  Float_t fEdep, fEdepSigma;
  Int_t fWall, fBlock, fCell;
  Int_t fEvents_Poisson_Cs, fEvents_Poisson_Co;
  
  ClassDef(ERGadastCsIDigi,1)
};

#endif

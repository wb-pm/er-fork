#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TROOT.h"
#include "TH1D.h"
#include "TCut.h"

#include <iostream>
//A small script for calculating the geometrical efficiency of the C7 experiment setup
/* const Double_t fromTargetToAlpide =  // cm
const Double_t fromAlpideToFirstFOOT = 12// cm
const Double_t betweenFOOTPairs // cm */
const Double_t distanceLastFoot = 55.;
const Double_t distanceAlpide = 10.;
const Double_t massC7 = 6.5615; //GeV 

TTree* treeEventHeader = nullptr;

void setReactionPosAliases();
void setMomentumAliases();
void setEnergyAliases();
void setMassAliases();
void setAngleAliases();

void drawMomentumProjectionAlpide();
void drawMomentumProjectionLastFoot();
void drawMasses();
void drawAnglesLab();
void drawConservationLaws();
void drawRectangle();
void drawPresentationPics();
void geoEff()
{
    TFile* fileEventHeader = new TFile("../sim/sim_KinematicsTest500AMeV_1cmSpread.root");
    treeEventHeader = (TTree*)fileEventHeader->Get("er");

    setReactionPosAliases();
    setMomentumAliases();
    setEnergyAliases();
    setMassAliases();

/*     drawMomentumProjectionAlpide(); */
    drawMomentumProjectionLastFoot();
    drawPresentationPics();
/*     drawMasses();
//    drawEnergies();
    drawAnglesLab(); */
}

void setReactionPosAliases()
{
    //Reaction position aliases
    treeEventHeader->SetAlias("reactionX", "MCEventHeader.ERDecayMCEventHeader.fReactionPos.X()");
    treeEventHeader->SetAlias("reactionZ", "MCEventHeader.ERDecayMCEventHeader.fReactionPos.Z()");
    treeEventHeader->SetAlias("reactionY", "MCEventHeader.ERDecayMCEventHeader.fReactionPos.Y()");
}

void setMomentumAliases()
{
    //First proton momentum aliases
    treeEventHeader->SetAlias("p1Px", "MCEventHeader.fp1.Px()");
    treeEventHeader->SetAlias("p1Py", "MCEventHeader.fp1.Py()");
    treeEventHeader->SetAlias("p1Pz", "MCEventHeader.fp1.Pz()");
    //Second proton momentum aliases
    treeEventHeader->SetAlias("p2Px", "MCEventHeader.fp2.Px()");
    treeEventHeader->SetAlias("p2Py", "MCEventHeader.fp2.Py()");
    treeEventHeader->SetAlias("p2Pz", "MCEventHeader.fp2.Pz()");
    //Third proton momentum aliases
    treeEventHeader->SetAlias("p3Px", "MCEventHeader.fp3.Px()");
    treeEventHeader->SetAlias("p3Py", "MCEventHeader.fp3.Py()");
    treeEventHeader->SetAlias("p3Pz", "MCEventHeader.fp3.Pz()");
    //Fourth proton momentum aliases
    treeEventHeader->SetAlias("p4Px", "MCEventHeader.fp4.Px()");
    treeEventHeader->SetAlias("p4Py", "MCEventHeader.fp4.Py()");
    treeEventHeader->SetAlias("p4Pz", "MCEventHeader.fp4.Pz()");
    //Helium-3 momentum aliases
    treeEventHeader->SetAlias("He3Px", "MCEventHeader.fHe3.Px()");
    treeEventHeader->SetAlias("He3Py", "MCEventHeader.fHe3.Py()");
    treeEventHeader->SetAlias("He3Pz", "MCEventHeader.fHe3.Pz()");
    //Carbon-7 momentum aliases
    treeEventHeader->SetAlias("C7Px", "MCEventHeader.fC7.Px()");
    treeEventHeader->SetAlias("C7Py", "MCEventHeader.fC7.Py()");
    treeEventHeader->SetAlias("C7Pz", "MCEventHeader.fC7.Pz()");
    //Carbon-9 momentum aliases
    treeEventHeader->SetAlias("C9Px", "MCEventHeader.fC9.Px()");
    treeEventHeader->SetAlias("C9Py", "MCEventHeader.fC9.Py()");
    treeEventHeader->SetAlias("C9Pz", "MCEventHeader.fC9.Pz()");

}

void setEnergyAliases()
{
    //Set aliases for energies
    treeEventHeader->SetAlias("p1T","MCEventHeader.fp1.T()");
    treeEventHeader->SetAlias("p2T","MCEventHeader.fp2.T()");
    treeEventHeader->SetAlias("p3T","MCEventHeader.fp3.T()");
    treeEventHeader->SetAlias("p4T","MCEventHeader.fp4.T()");

    treeEventHeader->SetAlias("He3T","MCEventHeader.fHe3.T()");
    treeEventHeader->SetAlias("C7T","MCEventHeader.fC7.T()");
    treeEventHeader->SetAlias("C9T","MCEventHeader.fC9.T()");

}

void setMassAliases()
{
    treeEventHeader->SetAlias("p1M","MCEventHeader.fp1.M()");
    treeEventHeader->SetAlias("p2M","MCEventHeader.fp2.M()");
    treeEventHeader->SetAlias("p3M","MCEventHeader.fp3.M()");
    treeEventHeader->SetAlias("p4M","MCEventHeader.fp4.M()");

    treeEventHeader->SetAlias("He3M","MCEventHeader.fHe3.M()");
    treeEventHeader->SetAlias("C7M","MCEventHeader.fC7.M()");
    treeEventHeader->SetAlias("C9M","MCEventHeader.fC9.M()");
}


void drawMomentumProjectionAlpide()
{
    // Projection of decay particles to the plane of Alpide (10 cm)
    TString nameCanvas = Form("MomentumProjectionAlpide, %s", treeEventHeader->GetName());
    TCanvas* cMomentumProjection = new TCanvas(nameCanvas, nameCanvas);
    cMomentumProjection->Divide(3, 2);

    cMomentumProjection->cd(1);
    TString P1momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(p1Px/p1Pz):reactionY + (%f - reactionZ)*(p1Py/p1Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(P1momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();

    cMomentumProjection->cd(2);
    TString P2momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(p2Px/p2Pz):reactionY + (%f - reactionZ)*(p2Py/p2Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(P2momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();

    cMomentumProjection->cd(3);
    TString P3momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(p3Px/p3Pz):reactionY + (%f - reactionZ)*(p3Py/p3Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(P3momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();

    cMomentumProjection->cd(4);
    TString P4momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(p4Px/p4Pz):reactionY + (%f - reactionZ)*(p4Py/p4Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(P4momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();

    cMomentumProjection->cd(5);
    TString He3momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(He3Px/He3Pz):reactionY + (%f - reactionZ)*(He3Py/He3Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(He3momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();

    cMomentumProjection->cd(6);
    TString C9momentumProjectionAlpide = Form("reactionX + (%f - reactionZ)*(C9Px/C9Pz):reactionY + (%f - reactionZ)*(C9Py/C9Pz)", distanceAlpide, distanceAlpide);
    treeEventHeader->Draw(C9momentumProjectionAlpide, "", "colz");
    cMomentumProjection->Update();
}

void drawMomentumProjectionLastFoot()
{
    // Projection of decay particles to the plane of the last FOOT (55 cm) 
    TString nameCanvas = Form("MomentumProjectionLastFoot, %s", treeEventHeader->GetName());
    TCanvas* cMomentumProjection = new TCanvas(nameCanvas, nameCanvas);
    cMomentumProjection->Divide(4,2);

    TCut decayEnergyCut = Form("(C7M - %f) < 0.01",massC7);
    TString P1momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p1Py/p1Pz):reactionX + (%f - reactionZ)*(p1Px/p1Pz)", distanceLastFoot, distanceLastFoot);
    TCut p1InSquare = Form("((reactionY + (%f - reactionZ)*(p1Py/p1Pz)) < 5) && ((reactionY + (%f - reactionZ)*(p1Py/p1Pz)) > -5) && ((reactionX + (%f - reactionZ)*(p1Px/p1Pz)) < 5) && ((reactionX + (%f - reactionZ)*(p1Px/p1Pz))) > -5",distanceLastFoot,distanceLastFoot,distanceLastFoot,distanceLastFoot); 
    cMomentumProjection->cd(1);
    Double_t pAllEvents = treeEventHeader->Draw(P1momentumProjectionLastFoot, "p1M > 0." && decayEnergyCut, "colz");
    std::cout << "All events for the cut " << decayEnergyCut << " " << pAllEvents << std::endl;
    drawRectangle();
    cMomentumProjection->cd(2);
    Double_t p1EventsInSquare = treeEventHeader->Draw(P1momentumProjectionLastFoot,"p1M > 0." && p1InSquare && decayEnergyCut,"colz");
    drawRectangle();
    std::cout << "Geometrical efficiency of detecting first proton = " << p1EventsInSquare/pAllEvents << std::endl;
    cMomentumProjection->Update();

    cMomentumProjection->cd(3);
    TString p2momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p2Py/p2Pz):reactionX + (%f - reactionZ)*(p2Px/p2Pz)", distanceLastFoot, distanceLastFoot);
    TCut p2InSquare = Form("((reactionY + (%f - reactionZ)*(p2Py/p2Pz)) < 5) && ((reactionY + (%f - reactionZ)*(p2Py/p2Pz)) > -5) && ((reactionX + (%f - reactionZ)*(p2Px/p2Pz)) < 5) && ((reactionX + (%f - reactionZ)*(p2Px/p2Pz))) > -5",distanceLastFoot,distanceLastFoot,distanceLastFoot,distanceLastFoot); 
    Double_t p2EventsInSquare = treeEventHeader->Draw(p2momentumProjectionLastFoot,"p2M > 0." && p2InSquare && decayEnergyCut,"colz");
    drawRectangle();
    std::cout << "Geometrical efficiency of detecting second proton = " << p2EventsInSquare/pAllEvents << std::endl;
    cMomentumProjection->Update();

    cMomentumProjection->cd(4);
    TString p3momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p3Py/p3Pz):reactionX + (%f - reactionZ)*(p3Px/p3Pz)", distanceLastFoot, distanceLastFoot);
    TCut p3InSquare = Form("((reactionY + (%f - reactionZ)*(p3Py/p3Pz)) < 5) && ((reactionY + (%f - reactionZ)*(p3Py/p3Pz)) > -5) && ((reactionX + (%f - reactionZ)*(p3Px/p3Pz)) < 5) && ((reactionX + (%f - reactionZ)*(p3Px/p3Pz))) > -5",distanceLastFoot,distanceLastFoot,distanceLastFoot,distanceLastFoot); 
    Double_t p3EventsInSquare = treeEventHeader->Draw(p3momentumProjectionLastFoot,"p3M > 0." && p3InSquare && decayEnergyCut,"colz");
    drawRectangle();
    std::cout << "Geometrical efficiency of detecting third proton = " << p3EventsInSquare/pAllEvents << std::endl;
    cMomentumProjection->Update();

    cMomentumProjection->cd(5);
    TString p4momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p4Py/p4Pz):reactionX + (%f - reactionZ)*(p4Px/p4Pz)", distanceLastFoot, distanceLastFoot);
    TCut p4InSquare = Form("((reactionY + (%f - reactionZ)*(p4Py/p4Pz)) < 5) && ((reactionY + (%f - reactionZ)*(p4Py/p4Pz)) > -5) && ((reactionX + (%f - reactionZ)*(p4Px/p4Pz)) < 5) && ((reactionX + (%f - reactionZ)*(p4Px/p4Pz))) > -5",distanceLastFoot,distanceLastFoot,distanceLastFoot,distanceLastFoot); 
    Double_t p4EventsInSquare = treeEventHeader->Draw(p4momentumProjectionLastFoot,"p4M > 0." && p4InSquare && decayEnergyCut,"colz");
    drawRectangle();
    std::cout << "Geometrical efficiency of detecting fourth proton = " << p4EventsInSquare/pAllEvents << std::endl;
    cMomentumProjection->Update();

    cMomentumProjection->cd(6);

    Double_t allpEventsInSquare = treeEventHeader->Draw(P1momentumProjectionLastFoot,"p1M > 0." && p1InSquare && p2InSquare && p3InSquare && p4InSquare && decayEnergyCut,"goff");
    std::cout << "Geometrical efficiency of detecting all protons = " << allpEventsInSquare/pAllEvents << std::endl;
    std::cout << "Geometrical efficiency by multiplying " << (p1EventsInSquare/pAllEvents)*(p2EventsInSquare/pAllEvents)*(p3EventsInSquare/pAllEvents)*(p4EventsInSquare/pAllEvents) << std::endl;
    drawRectangle();

    cMomentumProjection->cd(7);
    TString decayEnergy = Form("(C7M - %f)",massC7);
    Double_t DecayCutEvents = treeEventHeader->Draw(decayEnergy, "p1M > 0.", "");
    Double_t DecayCutEvents2 = treeEventHeader->Draw(decayEnergy, "p1M > 0." && p1InSquare && p2InSquare && p3InSquare && p4InSquare, "same");
/*     cMomentumProjection->cd(2);
    TString P2momentumProjectionLastFoot = Form("reactionX + (%f - reactionZ)*(p2Px/p2Pz):reactionY + (%f - reactionZ)*(p2Py/p2Pz)", distanceLastFoot, distanceLastFoot);
    treeEventHeader->Draw(P2momentumProjectionLastFoot, "p2M > 0.", "colz");
    drawRectangle();
    cMomentumProjection->Update();

    cMomentumProjection->cd(3);
    TString P3momentumProjectionLastFoot = Form("reactionX + (%f - reactionZ)*(p3Px/p3Pz):reactionY + (%f - reactionZ)*(p3Py/p3Pz)", distanceLastFoot, distanceLastFoot);
    treeEventHeader->Draw(P3momentumProjectionLastFoot, "p3M > 0.", "colz");
    drawRectangle();
    cMomentumProjection->Update();

    cMomentumProjection->cd(4);
    TString P4momentumProjectionLastFoot = Form("reactionX + (%f - reactionZ)*(p4Px/p4Pz):reactionY + (%f - reactionZ)*(p4Py/p4Pz)", distanceLastFoot, distanceLastFoot);
    treeEventHeader->Draw(P4momentumProjectionLastFoot, "p4M > 0.", "colz");
    drawRectangle();
    cMomentumProjection->Update();

    cMomentumProjection->cd(5);
    TString He3momentumProjectionLastFoot = Form("reactionX + (%f - reactionZ)*(He3Px/He3Pz):reactionY + (%f - reactionZ)*(He3Py/He3Pz)", distanceLastFoot, distanceLastFoot);
    treeEventHeader->Draw(He3momentumProjectionLastFoot, "He3M > 0.", "colz");
    drawRectangle();
    cMomentumProjection->Update();

    cMomentumProjection->cd(6);
    TString C9momentumProjectionLastFoot = Form("reactionX + (%f - reactionZ)*(C9Px/C9Pz):reactionY + (%f - reactionZ)*(C9Py/C9Pz)", distanceLastFoot, distanceLastFoot);
    treeEventHeader->Draw(C9momentumProjectionLastFoot, "C9M > 0.", "colz");
    drawRectangle();
    cMomentumProjection->Update(); */
}
void drawMasses()
{   //Masses of the products
    TString nameCanvas = Form("Masses, %s", treeEventHeader->GetName());
    TCanvas* cMasses = new TCanvas(nameCanvas, nameCanvas);
    cMasses->Divide(4,2);

    cMasses->cd(1);
    treeEventHeader->Draw("p1M","p1M > 0.","");
    cMasses->Update();

    cMasses->cd(2);
    treeEventHeader->Draw("p2M","p2M > 0.","");
    cMasses->Update();

    cMasses->cd(3);
    treeEventHeader->Draw("p3M","p3M > 0.","");
    cMasses->Update();

    cMasses->cd(4);
    treeEventHeader->Draw("p4M","p4M > 0.","");
    cMasses->Update();

    cMasses->cd(5);
    treeEventHeader->Draw("He3M","He3M > 0.","");
    cMasses->Update();

    cMasses->cd(6);
    treeEventHeader->Draw("C7M","C7M > 0.","");
    cMasses->Update();

    cMasses->cd(7);
    TString decayEnergy = Form("C7M - %f",massC7);
    treeEventHeader->Draw(decayEnergy,"C7M > 0.","");
    cMasses->Update();

    cMasses->cd(8);
    treeEventHeader->Draw("C9M","C9M > 0.","");
    cMasses->Update();
}

void drawAnglesLab()
{
    TString nameCanvas = Form("AnglesLab, %s", treeEventHeader->GetName());
    TCanvas* cAnglesLab = new TCanvas(nameCanvas, nameCanvas);
    cAnglesLab->Divide(3,2);

    cAnglesLab->cd(1);
    treeEventHeader->Draw("MCEventHeader.fp1.Theta()*TMath::RadToDeg()", "p1M > 0.", "");
    drawRectangle();
    cAnglesLab->Update();

    cAnglesLab->cd(2);
    treeEventHeader->Draw("MCEventHeader.fp2.Theta()*TMath::RadToDeg()", "p2M > 0.", "");
    drawRectangle();
    cAnglesLab->Update();

    cAnglesLab->cd(3);
    treeEventHeader->Draw("MCEventHeader.fp3.Theta()*TMath::RadToDeg()", "p3M > 0.", "");
    drawRectangle();
    cAnglesLab->Update();

    cAnglesLab->cd(4);
    treeEventHeader->Draw("MCEventHeader.fp4.Theta()*TMath::RadToDeg()", "p4M > 0.", "");
    drawRectangle();
    cAnglesLab->Update();

    cAnglesLab->cd(5);
    treeEventHeader->Draw("MCEventHeader.fHe3.Theta()*TMath::RadToDeg()", "He3M > 0.", "");
    drawRectangle();
    cAnglesLab->Update();

    cAnglesLab->cd(6);
    treeEventHeader->Draw("MCTrack.fStartY:MCTrack.fStartX", "C9M > 0.", "colz");
    cAnglesLab->Update();
}

void drawConservationLaws()
{
    TString nameCanvas = Form("ConversationLaws, %s", treeEventHeader->GetName());
    TCanvas* cAnglesLab = new TCanvas(nameCanvas, nameCanvas);
    cAnglesLab->Divide(3,2);
}

void drawPresentationPics()
{
    TString nameCanvas = Form("Detector Efficiency, %s", treeEventHeader->GetName());
    TCanvas* cDetectorEfficiency = new TCanvas(nameCanvas, nameCanvas);
    cDetectorEfficiency->Divide(4,2);

    cDetectorEfficiency->cd(1);
    TCut decayEnergyCut = Form("(C7M - %f) < 0.01",massC7);
    TString P1momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p1Py/p1Pz):reactionX + (%f - reactionZ)*(p1Px/p1Pz)", distanceLastFoot, distanceLastFoot);
    TCut p1InSquare = Form("((reactionY + (%f - reactionZ)*(p1Py/p1Pz)) < 5) && ((reactionY + (%f - reactionZ)*(p1Py/p1Pz)) > -5) && ((reactionX + (%f - reactionZ)*(p1Px/p1Pz)) < 5) && ((reactionX + (%f - reactionZ)*(p1Px/p1Pz))) > -5",distanceLastFoot,distanceLastFoot,distanceLastFoot,distanceLastFoot); 
    Double_t pAllEvents = treeEventHeader->Draw(P1momentumProjectionLastFoot, "p1M > 0." && decayEnergyCut, "colz");
    std::cout << "All events for the cut " << decayEnergyCut << " " << pAllEvents << std::endl;
    drawRectangle();

}

void drawRectangle(){
TLine *line1 = new TLine(-5, -5, 5, -5);
TLine *line2 = new TLine(5, -5, 5, 5);
TLine *line3 = new TLine(5, 5, -5, 5);
TLine *line4 = new TLine(-5, 5, -5, -5);

// Set line attributes (optional)
line1->SetLineColor(kRed);
line1->SetLineWidth(4);
line2->SetLineColor(kRed);
line2->SetLineWidth(4);
line3->SetLineColor(kRed);
line3->SetLineWidth(4);
line4->SetLineColor(kRed);
line4->SetLineWidth(4);

// Draw lines
line1->Draw();
line2->Draw();
line3->Draw();
line4->Draw();
}
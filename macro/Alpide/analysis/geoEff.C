#include "TFile.h"
#include "TLine.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TROOT.h"
#include "TH1D.h"
#include "TCut.h"
#include "TStyle.h"
#include "TMath.h"

#include <iostream>
//TODO: Make organized code, make cuts global
//A small script for reading and analyzing trees of C7 simulation with both Alpide and FOOT
/* const Double_t fromTargetToAlpide =  // cm
const Double_t fromAlpideToFirstFOOT = 12// cm
const Double_t betweenFOOTPairs // cm */

/* TString formCoordinateX(Double_t coordinateZ, const char* particle)
{
    return Form("(reactionX + (%1$f - reactionZ)*(%2$sPx/%2$sPz))", coordinateZ, particle);
}

TString formCoordinateY(Double_t coordinateZ, const char* particle)
{
    return Form("(reactionX + (%1$f - reactionZ)*(%2$sPx/%2$sPz))", coordinateZ, particle);
}

//Very convoluted way of writing down a condition for a particle to be in a detector
TCut messy_cut_particleInDetector = Form("%1$s < %3$f && %1$s > -%3$f && %2$s < %3$f && %2$s > -%3$f", formCoordinateX(distanceLastFoot, "p1").Data(), formCoordinateY(distanceLastFoot, "p1").Data(), detectorHalfSize);

//Looks a bit more readable than previous version, but still might be confusing
TCut getParticleInSquareDetectorCut(Double_t coordinateZ, TString particle, Double_t detectorSize)
{
    return Form("((reactionY + (%1$f - reactionZ)*(%2$sPy/%2$sPz)) < %3$f) && ((reactionY + (%1$f - reactionZ)*(%2$sPy/%2$sPz)) > -%3$f) && ((reactionX + (%1$f - reactionZ)*(%2$sPx/%2$sPz)) < %3$f) && ((reactionX + (%1$f - reactionZ)*(%2$sPx/%2$sPz)) > -%3$f))", coordinateZ, particle.Data(), detectorSize);
} */
const Double_t distanceWindowToAlpide = 2.05; //cm
const Double_t distanceTargetCenterToWindow = 5.55 / 2; //cm
const Double_t distanceAlpideToTargetCenter = distanceWindowToAlpide + distanceTargetCenterToWindow; //cm
const Double_t distanceBetweenFootPair = 11.1;
const Double_t distanceFirstFootToAlpide = 12.5;
const Double_t distancePreLastFoot = distanceAlpideToTargetCenter + distanceBetweenFootPair * 2 + distanceFirstFootToAlpide; //cm
const Double_t distanceLastFoot = distanceAlpideToTargetCenter + distanceBetweenFootPair * 3 + distanceFirstFootToAlpide; //cm
const Double_t massC7 = 6.5615; //GeV, sum of four protons and helium-3
const Double_t detectorHalfSize = 5.; //cm

TTree* treeEventHeader = nullptr;

TString P1momentumProjectionAlpide = Form("reactionY + (%f - reactionZ)*(p1Py/p1Pz):reactionX + (%f - reactionZ)*(p1Px/p1Pz)", distanceAlpideToTargetCenter, distanceAlpideToTargetCenter);
TString P2momentumProjectionAlpide = Form("reactionY + (%f - reactionZ)*(p2Py/p2Pz):reactionX + (%f - reactionZ)*(p2Px/p2Pz)", distanceAlpideToTargetCenter, distanceAlpideToTargetCenter);
TString P3momentumProjectionAlpide = Form("reactionY + (%f - reactionZ)*(p3Py/p3Pz):reactionX + (%f - reactionZ)*(p3Px/p3Pz)", distanceAlpideToTargetCenter, distanceAlpideToTargetCenter);
TString P4momentumProjectionAlpide = Form("reactionY + (%f - reactionZ)*(p4Py/p4Pz):reactionX + (%f - reactionZ)*(p4Px/p4Pz)", distanceAlpideToTargetCenter, distanceAlpideToTargetCenter);

TString p1momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(p1Py/p1Pz):reactionX + (%f - reactionZ)*(p1Px/p1Pz)", distanceLastFoot, distanceLastFoot);
TString p2momentumProjectionLastFoot = Form("reactionY + (%1$f - reactionZ)*(p2Py/p2Pz):reactionX + (%1$f - reactionZ)*(p2Px/p2Pz)", distanceLastFoot);
TString p3momentumProjectionLastFoot = Form("reactionY + (%1$f - reactionZ)*(p3Py/p3Pz):reactionX + (%1$f - reactionZ)*(p3Px/p3Pz)", distanceLastFoot);
TString p4momentumProjectionLastFoot = Form("reactionY + (%1$f - reactionZ)*(p4Py/p4Pz):reactionX + (%1$f - reactionZ)*(p4Px/p4Pz)", distanceLastFoot);

TCut cut_decayEnergy = Form("(C7M - %f) < 0.01", massC7);
TCut cut_decayEnergyMoreThan0 = Form("(C7M - %f) > 0.", massC7);
TString decayEnergy = Form("(C7M - %f)*1000", massC7);


TCut cut_p1InLastFoot = Form("((reactionY + (%1$f - reactionZ)*(p1Py/p1Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p1Py/p1Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p1Px/p1Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p1Px/p1Pz))) > -5", distanceLastFoot);
TCut cut_p2InLastFoot = Form("((reactionY + (%1$f - reactionZ)*(p2Py/p2Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p2Py/p2Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p2Px/p2Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p2Px/p2Pz))) > -5", distanceLastFoot);
TCut cut_p3InLastFoot = Form("((reactionY + (%1$f - reactionZ)*(p3Py/p3Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p3Py/p3Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p3Px/p3Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p3Px/p3Pz))) > -5", distanceLastFoot);
TCut cut_p4InLastFoot = Form("((reactionY + (%1$f - reactionZ)*(p4Py/p4Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p4Py/p4Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p4Px/p4Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p4Px/p4Pz))) > -5", distanceLastFoot);
TCut cut_He3InLastFoot = Form("((reactionY + (%1$f - reactionZ)*(He3Py/He3Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(He3Py/He3Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(He3Px/He3Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(He3Px/He3Pz))) > -5", distanceLastFoot);

TCut cut_p1InDetector45cm = Form("((reactionY + (%1$f - reactionZ)*(p1Py/p1Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p1Py/p1Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p1Px/p1Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p1Px/p1Pz))) > -5", distancePreLastFoot);
TCut cut_p2InDetector45cm = Form("((reactionY + (%1$f - reactionZ)*(p2Py/p2Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p2Py/p2Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p2Px/p2Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p2Px/p2Pz))) > -5", distancePreLastFoot);
TCut cut_p3InDetector45cm = Form("((reactionY + (%1$f - reactionZ)*(p3Py/p3Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p3Py/p3Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p3Px/p3Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p3Px/p3Pz))) > -5", distancePreLastFoot);
TCut cut_p4InDetector45cm = Form("((reactionY + (%1$f - reactionZ)*(p4Py/p4Pz)) < 5) && ((reactionY + (%1$f - reactionZ)*(p4Py/p4Pz)) > -5) && ((reactionX + (%1$f - reactionZ)*(p4Px/p4Pz)) < 5) && ((reactionX + (%1$f - reactionZ)*(p4Px/p4Pz))) > -5", distancePreLastFoot);


void setReactionPosAliases();
void setMomentumAliases();
void setEnergyAliases();
void setMassAliases();
void setAngleAliases();

void drawMomentumProjectionAlpide();
void drawMomentumProjectionLastFoot();
void drawMomentumProjectionLastFootInitialFunc();
void drawMasses();
void drawAnglesLab();
void drawConservationLaws();
void drawSquare();
void drawRectangle();
void drawPresentationPics();
void drawReportCanvases();
void geoEff()
{
    gStyle->SetOptStat(kFALSE);
    TString fileName = "../sim/sim_KinematicsTest500AMeV_1cmSpread.root";
    TFile* fileEventHeader = new TFile(fileName);
    treeEventHeader = (TTree*)fileEventHeader->Get("er");

    setReactionPosAliases();
    setMomentumAliases();
    setEnergyAliases();
    setMassAliases();
    setAngleAliases();
    drawReportCanvases();
    //drawMomentumProjectionAlpide();
    //drawMomentumProjectionLastFoot();
    //drawPresentationPics();
    // drawMomentumProjectionLastFootInitialFunc();
    //  drawMasses();
  //    drawEnergies();
    //  drawAnglesLab();
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
    treeEventHeader->SetAlias("p1T", "MCEventHeader.fp1.T()");
    treeEventHeader->SetAlias("p2T", "MCEventHeader.fp2.T()");
    treeEventHeader->SetAlias("p3T", "MCEventHeader.fp3.T()");
    treeEventHeader->SetAlias("p4T", "MCEventHeader.fp4.T()");

    treeEventHeader->SetAlias("He3T", "MCEventHeader.fHe3.T()");
    treeEventHeader->SetAlias("C7T", "MCEventHeader.fC7.T()");
    treeEventHeader->SetAlias("C9T", "MCEventHeader.fC9.T()");

}

void setMassAliases()
{
    treeEventHeader->SetAlias("p1M", "MCEventHeader.fp1.M()");
    treeEventHeader->SetAlias("p2M", "MCEventHeader.fp2.M()");
    treeEventHeader->SetAlias("p3M", "MCEventHeader.fp3.M()");
    treeEventHeader->SetAlias("p4M", "MCEventHeader.fp4.M()");

    treeEventHeader->SetAlias("He3M", "MCEventHeader.fHe3.M()");
    treeEventHeader->SetAlias("C7M", "MCEventHeader.fC7.M()");
    treeEventHeader->SetAlias("C9M", "MCEventHeader.fC9.M()");
}


void setAngleAliases()
{
    treeEventHeader->SetAlias("p1ThetaDeg", "MCEventHeader.fp1.Theta()*TMath::RadToDeg()");
    treeEventHeader->SetAlias("p2ThetaDeg", "MCEventHeader.fp2.Theta()*TMath::RadToDeg()");
    treeEventHeader->SetAlias("p3ThetaDeg", "MCEventHeader.fp3.Theta()*TMath::RadToDeg()");
    treeEventHeader->SetAlias("p4ThetaDeg", "MCEventHeader.fp4.Theta()*TMath::RadToDeg()");

    treeEventHeader->SetAlias("He3ThetaDeg", "MCEventHeader.fHe3.Theta()*TMath::RadToDeg()");
    treeEventHeader->SetAlias("C7ThetaDeg", "MCEventHeader.fC7.Theta()*TMath::RadToDeg()");
    treeEventHeader->SetAlias("C9ThetaDeg", "MCEventHeader.fC9.Theta()*TMath::RadToDeg()");
    ;
}

void drawMasses()
{   //Masses of the products
    TString nameCanvas = Form("Masses, %s", treeEventHeader->GetName());
    TCanvas* cMasses = new TCanvas(nameCanvas, nameCanvas);
    cMasses->Divide(4, 2);

    cMasses->cd(1);
    treeEventHeader->Draw("p1M", "p1M > 0.", "");
    cMasses->Update();

    cMasses->cd(2);
    treeEventHeader->Draw("p2M", "p2M > 0.", "");
    cMasses->Update();

    cMasses->cd(3);
    treeEventHeader->Draw("p3M", "p3M > 0.", "");
    cMasses->Update();

    cMasses->cd(4);
    treeEventHeader->Draw("p4M", "p4M > 0.", "");
    cMasses->Update();

    cMasses->cd(5);
    treeEventHeader->Draw("He3M", "He3M > 0.", "");
    cMasses->Update();

    cMasses->cd(6);
    treeEventHeader->Draw("C7M", "C7M > 0.", "");
    cMasses->Update();

    cMasses->cd(7);
    treeEventHeader->Draw(decayEnergy, "C7M > 0.", "");
    cMasses->Update();

    cMasses->cd(8);
    treeEventHeader->Draw("C9M", "C9M > 0.", "");
    cMasses->Update();
}

void drawAnglesLab()
{
    TString nameCanvas = Form("AnglesLab, %s", treeEventHeader->GetName());
    TCanvas* cAnglesLab = new TCanvas(nameCanvas, nameCanvas);
    cAnglesLab->Divide(3, 2);

    cAnglesLab->cd(1);
    treeEventHeader->Draw("MCEventHeader.fp1.Theta()*TMath::RadToDeg()", "p1M > 0.", "");
    cAnglesLab->Update();

    cAnglesLab->cd(2);
    treeEventHeader->Draw("MCEventHeader.fp2.Theta()*TMath::RadToDeg()", "p2M > 0.", "");
    cAnglesLab->Update();

    cAnglesLab->cd(3);
    treeEventHeader->Draw("MCEventHeader.fp3.Theta()*TMath::RadToDeg()", "p3M > 0.", "");
    cAnglesLab->Update();

    cAnglesLab->cd(4);
    treeEventHeader->Draw("MCEventHeader.fp4.Theta()*TMath::RadToDeg()", "p4M > 0.", "");
    cAnglesLab->Update();

    cAnglesLab->cd(5);
    treeEventHeader->Draw("MCEventHeader.fHe3.Theta()*TMath::RadToDeg()", "He3M > 0.", "");
    cAnglesLab->Update();

    cAnglesLab->cd(6);
    treeEventHeader->Draw("MCTrack.fStartY:MCTrack.fStartX", "C9M > 0.", "goff");
    cAnglesLab->Update();
}

void drawConservationLaws()
{
    TString nameCanvas = Form("ConservationLaws, %s", treeEventHeader->GetName());
    TCanvas* cAnglesLab = new TCanvas(nameCanvas, nameCanvas);
    cAnglesLab->Divide(3, 2);
}

void drawPresentationPics()
{
    TString nameCanvas = Form("Detector Efficiency, %s", treeEventHeader->GetName());
    TCanvas* cDetectorEfficiency = new TCanvas(nameCanvas, nameCanvas);
    cDetectorEfficiency->Divide(2, 2);

    cDetectorEfficiency->cd(1);
    gPad->Divide(2, 1);
    cDetectorEfficiency->cd(1)->cd(1);
    Double_t EventsLastFootEnergyCut = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_decayEnergy, "colz");
    TH1D* hLastFootEnergyCut = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootEnergyCut->SetName("hLastFootEnergyCut");
    hLastFootEnergyCut->SetTitle("L = 55 cm, E* in (0.,10.) MeV, proton");
    hLastFootEnergyCut->GetXaxis()->SetTitle("x (cm)");
    hLastFootEnergyCut->GetYaxis()->SetTitle("y (cm)");
    drawSquare();
    cDetectorEfficiency->cd(1)->cd(2);
    Double_t EventsLastFootNoEnergyCut = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0.", "colz");
    TH1D* hLastFootNoEnergyCut = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootNoEnergyCut->SetName("hLastFootNoEnergyCut");
    hLastFootNoEnergyCut->SetTitle("L = 55 cm, E* in (0.,20.) MeV, proton");
    hLastFootNoEnergyCut->GetXaxis()->SetTitle("x (cm)");
    hLastFootNoEnergyCut->GetYaxis()->SetTitle("y (cm)");
    drawSquare();

    cDetectorEfficiency->cd(2);
    gPad->Divide(2, 1);
    cDetectorEfficiency->cd(2)->cd(1);
    TString P1momentumProjectionSecondToLastFoot = Form("reactionY + (%f - reactionZ)*(p1Py/p1Pz):reactionX + (%f - reactionZ)*(p1Px/p1Pz)", distancePreLastFoot, distancePreLastFoot);
    Double_t EventsSecondToLastFootEnergyCut = treeEventHeader->Draw(P1momentumProjectionSecondToLastFoot, "p1M > 0." && cut_decayEnergy, "colz");
    TH1D* hSecondToLastFoot = (TH1D*)gPad->GetPrimitive("htemp");
    hSecondToLastFoot->SetName("hSecondToLastFoot");
    hSecondToLastFoot->SetTitle("L = 45 cm, E* in (0.,10.) MeV, proton");
    hSecondToLastFoot->GetXaxis()->SetTitle("x (cm)");
    hSecondToLastFoot->GetYaxis()->SetTitle("y (cm)");
    drawSquare();

    cDetectorEfficiency->cd(2)->cd(2);
    Double_t EventsSecondToLastFootNoEnergyCut = treeEventHeader->Draw(P1momentumProjectionSecondToLastFoot, "p1M > 0.", "colz");
    TH1D* hSecondToLastFootNoEnergyCut = (TH1D*)gPad->GetPrimitive("htemp");
    hSecondToLastFootNoEnergyCut->SetName("hSecondToLastFootNoEnergyCut");
    hSecondToLastFootNoEnergyCut->SetTitle("L = 45 cm, E* in (0.,20.) MeV, proton");
    hSecondToLastFootNoEnergyCut->GetXaxis()->SetTitle("x (cm)");
    hSecondToLastFootNoEnergyCut->GetYaxis()->SetTitle("y (cm)");
    drawSquare();

    cDetectorEfficiency->cd(3);
    Double_t DecayCutEvents = treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_decayEnergyMoreThan0, "");
    TH1D* hExcitationNoCut = (TH1D*)gPad->GetPrimitive("htemp");
    hExcitationNoCut->SetName("hExcitationNoCut");
    hExcitationNoCut->SetLineColor(kGreen);
    hExcitationNoCut->SetLineWidth(3);
    hExcitationNoCut->SetTitle("L = 55 cm, 4p coincidence");
    hExcitationNoCut->GetXaxis()->SetTitle("E* (MeV)");
    hExcitationNoCut->GetYaxis()->SetTitle("Counts");
    Double_t DecayCutEvents55cm = treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_p1InLastFoot && cut_p2InLastFoot && cut_p3InLastFoot && cut_p4InLastFoot, "same");
    TH1D* hExcitationCut = (TH1D*)gPad->GetPrimitive("htemp");
    hExcitationCut->SetName("hExcitationCut");
    hExcitationCut->SetLineWidth(3);

    cDetectorEfficiency->cd(4);
    Double_t DecayCutEvents2 = treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_decayEnergyMoreThan0, "");
    TH1D* hExcitation45cmNoCut = (TH1D*)gPad->GetPrimitive("htemp");
    hExcitation45cmNoCut->SetName("hExcitation45cmNoCut");
    hExcitation45cmNoCut->SetLineColor(kGreen);
    hExcitation45cmNoCut->SetTitle("L = 45 cm, 4p coincidence");
    hExcitation45cmNoCut->GetXaxis()->SetTitle("E* (MeV)");
    hExcitation45cmNoCut->GetYaxis()->SetTitle("Counts");
    hExcitation45cmNoCut->SetLineWidth(3);
    Double_t DecayCutEvents45cm = treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_p1InDetector45cm && cut_p2InDetector45cm && cut_p3InDetector45cm && cut_p4InDetector45cm, "same");
    TH1D* hExcitation45cmCut = (TH1D*)gPad->GetPrimitive("htemp");
    hExcitation45cmCut->SetName("hExcitation45cmCut");
    hExcitation45cmCut->SetLineWidth(3);
}

void drawSquare() {
    TLine* line1 = new TLine(-5, -5, 5, -5);
    TLine* line2 = new TLine(5, -5, 5, 5);
    TLine* line3 = new TLine(5, 5, -5, 5);
    TLine* line4 = new TLine(-5, 5, -5, -5);

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
void drawRectangle()
{
    TLine* line1 = new TLine(-4.5, -3, 4.5, -3);
    TLine* line2 = new TLine(4.5, -3, 4.5, 3);
    TLine* line3 = new TLine(4.5, 3, -4.5, 3);
    TLine* line4 = new TLine(-4.5, 3, -4.5, -3);

    // Set line attributes (optional)
    line1->SetLineColor(kRed);
    line1->SetLineWidth(4);
    line1->SetLineStyle(9);
    line2->SetLineColor(kRed);
    line2->SetLineWidth(4);
    line2->SetLineStyle(9);
    line3->SetLineColor(kRed);
    line3->SetLineWidth(4);
    line3->SetLineStyle(9);
    line4->SetLineColor(kRed);
    line4->SetLineWidth(4);
    line4->SetLineStyle(9);

    // Draw lines
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line4->Draw();
}

void drawReportCanvases()
{

    TFile* canvasesReport = new TFile("canvasesReport.root", "RECREATE");

    TCanvas* canvasReactionYvsReactionX = new TCanvas("canvasReactionYvsReactionX", "canvasReactionYvsReactionX", 900, 900);
    canvasReactionYvsReactionX->cd();
    treeEventHeader->Draw("reactionY:reactionX", "He3M > 0", "colz");
    TH1D* hReactionXvsReactionY = (TH1D*)gPad->GetPrimitive("htemp");
    hReactionXvsReactionY->SetName("hReactionXvsReactionY");
    hReactionXvsReactionY->SetTitle("Reaction Position X-Y distribution");
    hReactionXvsReactionY->GetXaxis()->SetTitle("x (cm)");
    hReactionXvsReactionY->GetYaxis()->SetTitle("y (cm)");
    canvasReactionYvsReactionX->SetLeftMargin(0.11);
    canvasReactionYvsReactionX->SetRightMargin(0.11);

    TCanvas* canvasReactionX = new TCanvas("canvasReactionX", "canvasReactionX", 900, 900);
    canvasReactionX->cd();
    treeEventHeader->Draw("reactionX", "He3M > 0", "");
    TH1D* hReactionX = (TH1D*)gPad->GetPrimitive("htemp");
    hReactionX->SetName("hReactionX");
    hReactionX->SetTitle("Reaction Position X distribution");
    hReactionX->GetXaxis()->SetTitle("x (cm)");
    hReactionX->GetYaxis()->SetTitle("Counts");
    canvasReactionX->SetLeftMargin(0.12);
    canvasReactionX->SetRightMargin(0.08);

    TCanvas* canvasReactionY = new TCanvas("canvasReactionY", "canvasReactionY", 900, 900);
    canvasReactionY->cd();
    treeEventHeader->Draw("reactionY", "He3M > 0", "");
    TH1D* hReactionY = (TH1D*)gPad->GetPrimitive("htemp");
    hReactionY->SetName("hReactionY");
    hReactionY->SetTitle("Reaction Position Y distribution");
    hReactionY->GetXaxis()->SetTitle("y (cm)");
    hReactionY->GetYaxis()->SetTitle("Counts");
    canvasReactionY->SetLeftMargin(0.12);
    canvasReactionY->SetRightMargin(0.08);

    TCanvas* canvasReactionZ = new TCanvas("canvasReactionZ", "canvasReactionZ", 900, 900);
    canvasReactionZ->cd();
    treeEventHeader->Draw("reactionZ", "He3M > 0", "");
    TH1D* hReactionZ = (TH1D*)gPad->GetPrimitive("htemp");
    hReactionZ->SetName("hReactionZ");
    hReactionZ->SetTitle("Reaction Position Z distribution");
    hReactionZ->GetXaxis()->SetTitle("z (cm)");
    hReactionZ->GetYaxis()->SetTitle("Counts");
    canvasReactionZ->SetLeftMargin(0.12);
    canvasReactionZ->SetRightMargin(0.08);

    TCanvas* canvasAlpide = new TCanvas("canvasAlpide", "canvasAlpide", 900, 450);
    canvasAlpide->Divide(2, 1);

    canvasAlpide->cd(1);
    treeEventHeader->Draw(P1momentumProjectionAlpide, "p1M > 0", "colz");
    TH1D* hAlpideP1 = (TH1D*)gPad->GetPrimitive("htemp");
    hAlpideP1->SetName("hAlpideP1");
    hAlpideP1->SetTitle("Alpide, 4.8 cm, P1");
    hAlpideP1->GetXaxis()->SetTitle("x (cm)");
    hAlpideP1->GetYaxis()->SetTitle("y (cm)");
    hAlpideP1->GetXaxis()->SetRangeUser(-3., 3.);
    hAlpideP1->GetYaxis()->SetRangeUser(-3., 3.);
    gPad->SetRightMargin(0.11);
    gPad->SetLeftMargin(0.12);
    //drawRectangle();
    canvasAlpide->Update();

    canvasAlpide->cd(0);
    treeEventHeader->Draw(P2momentumProjectionAlpide, "p2M > 0", "goff");
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hAlpideP2 = (TH1D*)gPad->GetPrimitive("htemp");
        hAlpideP2->SetName("hAlpideP2");
        hAlpideP2->SetTitle("Alpide, 4.8 cm, P2");
        hAlpideP2->GetXaxis()->SetTitle("x (cm)");
        hAlpideP2->GetYaxis()->SetTitle("y (cm)");
        hAlpideP2->GetXaxis()->SetRangeUser(-3., 3.);
        hAlpideP2->GetYaxis()->SetRangeUser(-3., 3.);
        gPad->SetRightMargin(0.11);
    }
    canvasAlpide->Update();

    canvasAlpide->cd(0);
    treeEventHeader->Draw(P3momentumProjectionAlpide, "p3M > 0", "goff");
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hAlpideP3 = (TH1D*)gPad->GetPrimitive("htemp");
        hAlpideP3->SetName("hAlpideP3");
        hAlpideP3->SetTitle("Alpide, 4.8 cm, P3");
        hAlpideP3->GetXaxis()->SetTitle("x (cm)");
        hAlpideP3->GetYaxis()->SetTitle("y (cm)");
        hAlpideP3->GetXaxis()->SetRangeUser(-3., 3.);
        hAlpideP3->GetYaxis()->SetRangeUser(-3., 3.);
        gPad->SetRightMargin(0.11);
    }
    canvasAlpide->Update();

    canvasAlpide->cd(0);
    treeEventHeader->Draw(P4momentumProjectionAlpide, "p4M > 0", "goff");
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hAlpideP4 = (TH1D*)gPad->GetPrimitive("htemp");
        hAlpideP4->SetName("hAlpideP4");
        hAlpideP4->SetTitle("Alpide, 4.8 cm, P4");
        hAlpideP4->GetXaxis()->SetTitle("x (cm)");
        hAlpideP4->GetYaxis()->SetTitle("y (cm)");
        hAlpideP4->GetXaxis()->SetRangeUser(-3., 3.);
        hAlpideP4->GetYaxis()->SetRangeUser(-3., 3.);
        gPad->SetRightMargin(0.11);
    }
    canvasAlpide->Update();

    canvasAlpide->cd(2);
    TString He3momentumProjectionAlpide = Form("reactionY + (%f - reactionZ)*(He3Py/He3Pz):reactionX + (%f - reactionZ)*(He3Px/He3Pz)", distanceAlpideToTargetCenter, distanceAlpideToTargetCenter);
    treeEventHeader->Draw(He3momentumProjectionAlpide, "He3M > 0", "colz");
    TH1D* hAlpideHe3 = (TH1D*)gPad->GetPrimitive("htemp");
    hAlpideHe3->SetName("hAlpideHe3");
    hAlpideHe3->SetTitle("Alpide, 4.8 cm, He3");
    hAlpideHe3->GetXaxis()->SetTitle("x (cm)");
    hAlpideHe3->GetYaxis()->SetTitle("y (cm)");
    hAlpideHe3->GetXaxis()->SetRangeUser(-3., 3.);
    hAlpideHe3->GetYaxis()->SetRangeUser(-3., 3.);
    gPad->SetRightMargin(0.11);
    gPad->SetLeftMargin(0.12);
    canvasAlpide->Update();

    TCanvas* canvasLastFoot = new TCanvas("canvasLastFoot", "canvasLastFoot", 900, 900);
    canvasLastFoot->Divide(2, 2);

    canvasLastFoot->cd(1);
    Double_t allEvents = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0.", "colz");
    drawSquare();
    TH1D* hLastFootP1 = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootP1->SetName("hLastFootP1");
    hLastFootP1->SetTitle(Form("LastFoot, %.1f cm, P1", distanceLastFoot));
    hLastFootP1->GetXaxis()->SetTitle("x (cm)");
    hLastFootP1->GetYaxis()->SetTitle("y (cm)");
    hLastFootP1->GetXaxis()->SetRangeUser(-9.,9.);
    hLastFootP1->GetYaxis()->SetRangeUser(-9.,9.);
    gPad->SetRightMargin(0.13);

    Double_t allEventsInLastFoot = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_p1InLastFoot, "goff");
    std::cout << "All events: " << allEvents << std::endl;
    std::cout << "Geometrical efficiency of detecting first proton = " << allEventsInLastFoot / allEvents << std::endl;
    canvasLastFoot->Update();

    canvasLastFoot->cd(0);
    Double_t p2EventsInSquare = treeEventHeader->Draw(p2momentumProjectionLastFoot, "p2M > 0.", "goff");
    drawSquare();
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hLastFootP2 = (TH1D*)gPad->GetPrimitive("htemp");
        hLastFootP2->SetName("hLastFootP2");
        hLastFootP2->SetTitle(Form("LastFoot, %.1f cm, P2", distanceLastFoot));
        hLastFootP2->GetXaxis()->SetTitle("x (cm)");
        hLastFootP2->GetYaxis()->SetTitle("y (cm)");
        gPad->SetRightMargin(0.12);
    }
    Double_t p2EventsInLastFoot = treeEventHeader->Draw(p2momentumProjectionLastFoot, "p2M > 0." && cut_p2InLastFoot, "goff");
    std::cout << "Geometrical efficiency of detecting second proton = " << p2EventsInLastFoot / allEvents << std::endl;
    canvasLastFoot->Update();

    canvasLastFoot->cd(0);
    Double_t p3EventsInSquare = treeEventHeader->Draw(p3momentumProjectionLastFoot, "p3M > 0.", "goff");
    drawSquare();
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hLastFootP3 = (TH1D*)gPad->GetPrimitive("htemp");
        hLastFootP3->SetName("hLastFootP3");
        hLastFootP3->SetTitle(Form("LastFoot, %.1f cm, P3", distanceLastFoot));
        hLastFootP3->GetXaxis()->SetTitle("x (cm)");
        hLastFootP3->GetYaxis()->SetTitle("y (cm)");
        gPad->SetRightMargin(0.12);
    }
    Double_t p3EventsInLastFoot = treeEventHeader->Draw(p3momentumProjectionLastFoot, "p3M > 0." && cut_p3InLastFoot, "goff");
    std::cout << "Geometrical efficiency of detecting third proton = " << p3EventsInLastFoot / allEvents << std::endl;
    canvasLastFoot->Update();

    canvasLastFoot->cd(0);
    Double_t p4EventsInSquare = treeEventHeader->Draw(p4momentumProjectionLastFoot, "p4M > 0.", "goff");
    drawSquare();
    if ((TH1D*)gPad->GetPrimitive("htemp")) {
        TH1D* hLastFootP4 = (TH1D*)gPad->GetPrimitive("htemp");
        hLastFootP4->SetName("hLastFootP4");
        hLastFootP4->SetTitle("LastFoot, 50.6 cm, P4");
        hLastFootP4->GetXaxis()->SetTitle("x (cm)");
        hLastFootP4->GetYaxis()->SetTitle("y (cm)");
        gPad->SetRightMargin(0.12);
    }
    Double_t p4EventsInLastFoot = treeEventHeader->Draw(p4momentumProjectionLastFoot, "p4M > 0." && cut_p4InLastFoot, "goff");
    std::cout << "Geometrical efficiency of detecting fourth proton = " << p4EventsInLastFoot / allEvents << std::endl;
    canvasLastFoot->Update();

    canvasLastFoot->cd(2);
    Double_t threepEventsInSquare = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_p2InLastFoot && cut_p3InLastFoot && cut_p4InLastFoot, "colz");
    std::cout << "Geometrical efficiency of detecting three protons (p2,p3,p4) = " << threepEventsInSquare / allEvents << std::endl;
    drawSquare();
    TH1D* hLastFootP1ProtonsCoincidence = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootP1ProtonsCoincidence->SetName("hLastFootP1ProtonsCoincidence");
    hLastFootP1ProtonsCoincidence->SetTitle("LastFoot, 50.6 cm, P1 - ProtonsCoincidence");
    hLastFootP1ProtonsCoincidence->GetXaxis()->SetTitle("x (cm)");
    hLastFootP1ProtonsCoincidence->GetYaxis()->SetTitle("y (cm)");
    hLastFootP1ProtonsCoincidence->GetXaxis()->SetRangeUser(-9.,9.);
    hLastFootP1ProtonsCoincidence->GetYaxis()->SetRangeUser(-9.,9.);
    gPad->SetRightMargin(0.13);
    canvasLastFoot->Update();

    canvasLastFoot->cd(3);
    TString He3momentumProjectionLastFoot = Form("reactionY + (%f - reactionZ)*(He3Py/He3Pz):reactionX + (%f - reactionZ)*(He3Px/He3Pz)", distanceLastFoot, distanceLastFoot);
    Double_t He3Events = treeEventHeader->Draw(He3momentumProjectionLastFoot, "He3M > 0.", "colz");
    drawSquare();
    TH1D* hLastFootHe3 = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootHe3->SetName("hLastFootHe3");
    hLastFootHe3->SetTitle("LastFoot, 50.6 cm, He3");
    hLastFootHe3->GetXaxis()->SetTitle("x (cm)");
    hLastFootHe3->GetYaxis()->SetTitle("y (cm)");
    hLastFootHe3->GetXaxis()->SetRangeUser(-9.,9.);
    hLastFootHe3->GetYaxis()->SetRangeUser(-9.,9.);
    gPad->SetRightMargin(0.13);
    Double_t He3EventsInLastFoot = treeEventHeader->Draw(He3momentumProjectionLastFoot, "He3M > 0." && cut_He3InLastFoot, "goff");
    std::cout << "Geometrical efficiency of detecting helium-3 = " << He3EventsInLastFoot / allEvents << std::endl;
    canvasLastFoot->Update();

    canvasLastFoot->cd(4);
    Double_t He3EventsProtonsInSquare = treeEventHeader->Draw(He3momentumProjectionLastFoot, "He3M > 0." && cut_p1InLastFoot && cut_p2InLastFoot && cut_p3InLastFoot && cut_p4InLastFoot, "colz");
    drawSquare();
    TH1D* hLastFootHe3ProtonsCoincidence = (TH1D*)gPad->GetPrimitive("htemp");
    hLastFootHe3ProtonsCoincidence->SetName("hLastFootHe3ProtonsCoincidence");
    hLastFootHe3ProtonsCoincidence->SetTitle("LastFoot, 50.6 cm, He3 - ProtonsCoincidence");
    hLastFootHe3ProtonsCoincidence->GetXaxis()->SetTitle("x (cm)");
    hLastFootHe3ProtonsCoincidence->GetYaxis()->SetTitle("y (cm)");
    hLastFootHe3ProtonsCoincidence->GetXaxis()->SetRangeUser(-9.,9.);
    hLastFootHe3ProtonsCoincidence->GetYaxis()->SetRangeUser(-9.,9.);
    gPad->SetRightMargin(0.13);

    TCanvas* canvasBeamSpread = new TCanvas("canvasBeamSpread", "canvasBeamSpread", 900, 900);
    canvasBeamSpread->cd();
    treeEventHeader->Draw("MCTrack.fStartY:MCTrack.fStartX", "MCTrack.fMotherId == -1", "colz");
    TH1D* hC9BeamSpreadXY = (TH1D*)gPad->GetPrimitive("htemp");
    hC9BeamSpreadXY->SetName("hC9BeamSpreadXY");
    hC9BeamSpreadXY->SetTitle("C9 Beam X-Y spread");
    hC9BeamSpreadXY->GetXaxis()->SetTitle("x (cm)");
    hC9BeamSpreadXY->GetYaxis()->SetTitle("y (cm)");
    canvasBeamSpread->SetLeftMargin(0.11);
    canvasBeamSpread->SetRightMargin(0.11);

    TCanvas* canvasBeamX = new TCanvas("canvasBeamX", "canvasBeamX", 900, 900);
    canvasBeamX->cd();
    treeEventHeader->Draw("MCTrack.fStartX", "MCTrack.fMotherId == -1", "");
    TH1D* hC9BeamX = (TH1D*)gPad->GetPrimitive("htemp");
    hC9BeamX->SetName("hC9BeamX");
    hC9BeamX->SetTitle("C9 Beam X distribution");
    hC9BeamX->GetXaxis()->SetTitle("x (cm)");
    hC9BeamX->GetYaxis()->SetTitle("Counts");
    canvasBeamX->SetLeftMargin(0.12);
    canvasBeamX->SetRightMargin(0.08);

    TCanvas* canvasBeamY = new TCanvas("canvasBeamY", "canvasBeamY", 900, 900);
    canvasBeamY->cd();
    treeEventHeader->Draw("MCTrack.fStartY", "MCTrack.fMotherId == -1", "");
    TH1D* hC9BeamY = (TH1D*)gPad->GetPrimitive("htemp");
    hC9BeamY->SetName("hC9BeamY");
    hC9BeamY->SetTitle("C9 Beam Y distribution");
    hC9BeamY->GetXaxis()->SetTitle("y (cm)");
    hC9BeamY->GetYaxis()->SetTitle("Counts");
    canvasBeamY->SetLeftMargin(0.12);
    canvasBeamY->SetRightMargin(0.08);

    TCanvas* canvasExcitationEnergy = new TCanvas("canvasExcitationEnergy", "canvasExcitationEnergy", 1200, 600);
    canvasExcitationEnergy->Divide(2,1);
    canvasExcitationEnergy->cd(1);
    treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_decayEnergyMoreThan0, "");
    TH1D* hE0to20MeV = (TH1D*)gPad->GetPrimitive("htemp");
    hE0to20MeV->SetName("hE0to20MeV");
    hE0to20MeV->SetTitle("Excitation energy distribution");
    hE0to20MeV->SetLineColor(kGreen);
    hE0to20MeV->SetLineWidth(3);
    hE0to20MeV->GetXaxis()->SetTitle("E* (MeV)");
    hE0to20MeV->GetYaxis()->SetTitle("Counts");
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(0.08);
    canvasExcitationEnergy->Update();

    treeEventHeader->Draw(decayEnergy, "p1M > 0." && cut_decayEnergyMoreThan0 && cut_p1InLastFoot && cut_p2InLastFoot && cut_p3InLastFoot && cut_p4InLastFoot, "same");
    TH1D* hE0to20MeVLastFoot = (TH1D*)gPad->GetPrimitive("htemp");
    hE0to20MeVLastFoot->SetName("hE0to20MeVLastFoot");
    hE0to20MeVLastFoot->SetTitle("Excitation energy distribution (4p coincidence)");
    hE0to20MeVLastFoot->GetXaxis()->SetTitle("E* (MeV)");
    hE0to20MeVLastFoot->GetYaxis()->SetTitle("Counts");
    TLine* line10MeV = new TLine(10.,0,10.,hE0to20MeVLastFoot->GetMaximum());
    line10MeV->Draw();
    gPad->SetLeftMargin(0.12);
    gPad->SetRightMargin(0.08);
    canvasExcitationEnergy->Update();

    canvasExcitationEnergy->cd(0);
    Double_t eventsE0to20MeVLastFoot = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_decayEnergyMoreThan0, "goff");
    if((TH1D*)gPad->GetPrimitive("htemp"))
{
    TH1D* hE0to20MeVLastFoot2 = (TH1D*)gPad->GetPrimitive("htemp");
    hE0to20MeVLastFoot2->SetName("hE0to20MeVLastFoot2");
    hE0to20MeVLastFoot2->SetTitle("Projection of one proton at last FOOT");
    hE0to20MeVLastFoot2->GetXaxis()->SetTitle("x (cm)");
    hE0to20MeVLastFoot2->GetYaxis()->SetTitle("y (cm)");
    hE0to20MeVLastFoot2->GetXaxis()->SetRangeUser(-9.,9.);
    hE0to20MeVLastFoot2->GetYaxis()->SetRangeUser(-9.,9.);
    gPad->SetRightMargin(0.13);
    drawSquare();
    canvasExcitationEnergy->Update();
}

    canvasExcitationEnergy->cd(2);
    Double_t eventsE0to10MeVLastFoot = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy, "colz");
    TH1D* hE0to10MeVLastFoot2 = (TH1D*)gPad->GetPrimitive("htemp");
    hE0to10MeVLastFoot2->SetName("hE0to10MeVLastFoot2");
    hE0to10MeVLastFoot2->SetTitle("Projection of one proton at last FOOT (E* < 10 MeV)");
    hE0to10MeVLastFoot2->GetXaxis()->SetTitle("x (cm)");
    hE0to10MeVLastFoot2->GetYaxis()->SetTitle("y (cm)");
    hE0to10MeVLastFoot2->GetXaxis()->SetRangeUser(-9.,9.);
    hE0to10MeVLastFoot2->GetYaxis()->SetRangeUser(-9.,9.);

    gPad->SetRightMargin(0.13);
    drawSquare();
    canvasExcitationEnergy->Update();

    canvasExcitationEnergy->cd(0);
    Double_t p1eventsE0to10MeVLastFoot = treeEventHeader->Draw(p1momentumProjectionLastFoot, "p1M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy && cut_p1InLastFoot, "goff");

    Double_t p2eventsE0to10MeVLastFoot = treeEventHeader->Draw(p2momentumProjectionLastFoot, "p2M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy && cut_p2InLastFoot, "goff");

    Double_t p3eventsE0to10MeVLastFoot = treeEventHeader->Draw(p3momentumProjectionLastFoot, "p3M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy && cut_p3InLastFoot, "goff");

    Double_t p4eventsE0to10MeVLastFoot = treeEventHeader->Draw(p4momentumProjectionLastFoot, "p4M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy && cut_p4InLastFoot, "goff");

    Double_t He3eventsE0to10MeVLastFoot = treeEventHeader->Draw(He3momentumProjectionLastFoot, "He3M > 0." && cut_decayEnergyMoreThan0 && cut_decayEnergy && cut_He3InLastFoot, "goff");

    Double_t allParticlesInE0to10MeVLastFoot = treeEventHeader->Draw(p1momentumProjectionLastFoot,"p1M > 0." && cut_decayEnergyMoreThan0 &&cut_decayEnergy && cut_p1InLastFoot && cut_p2InLastFoot && cut_p3InLastFoot && cut_p4InLastFoot,"goff");

    std::cout << "All events (no excitation energy cut): " << eventsE0to20MeVLastFoot << std::endl;
    std::cout << "Events with excitation energy cut E < 10 MeV: " << eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Geometrical efficiency of detecting first proton = " << p1eventsE0to10MeVLastFoot / eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Geometrical efficiency of detecting second proton = " << p2eventsE0to10MeVLastFoot / eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Geometrical efficiency of detecting third proton = " << p3eventsE0to10MeVLastFoot / eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Geometrical efficiency of detecting fourth proton = " << p4eventsE0to10MeVLastFoot / eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Geometrical efficiency of detecting He3 = " << He3eventsE0to10MeVLastFoot / eventsE0to10MeVLastFoot << std::endl;
    std::cout << "Overall geometrical efficiency = " << allParticlesInE0to10MeVLastFoot/eventsE0to10MeVLastFoot << std::endl;

    canvasesReport->WriteObject(canvasReactionYvsReactionX, "canvasReactionYvsReactionX");
    canvasesReport->WriteObject(canvasReactionX, "canvasReactionX");
    canvasesReport->WriteObject(canvasReactionY, "canvasReactionY");
    canvasesReport->WriteObject(canvasReactionZ, "canvasReactionZ");
    canvasesReport->WriteObject(canvasAlpide, "canvasAlpide");
    canvasesReport->WriteObject(canvasLastFoot, "canvasLastFoot");
    canvasesReport->WriteObject(canvasBeamSpread, "canvasBeamSpread");
    canvasesReport->WriteObject(canvasBeamX, "canvasBeamX");
    canvasesReport->WriteObject(canvasBeamY, "canvasBeamY");
    canvasesReport->WriteObject(canvasExcitationEnergy,"canvasExcitationEnergy");
}
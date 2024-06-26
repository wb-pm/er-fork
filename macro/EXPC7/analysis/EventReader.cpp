#if !defined(__CLING__)
#include <iostream>

#include "TClassTable.h"
#include "TSystem.h"
#include "TTree.h"
#include "TFile.h"
#include "Event.h"
#include "TH1D.h"
#include "TBrowser.h"

//#include "ERDecay7CEventHeader.h"
#include "ERFootMuSiTrack.h"
#include "TLorentzVector.h"
#include "ERMCTrack.h"
#include "ERFootMuSiVertex.h"
//#include "FootMuSi_C7_Reco_Tree_Structure.h"

#endif
//Looping over the events from a tree
void EventReader()
{
    TFile* simulation = nullptr;
    TTree* simulation_tree = nullptr;
    TFile* reconstruction = nullptr; 
    TTree* reconstruction_tree = nullptr;
    TFile* outFile = nullptr;
    TTree* output_tree = nullptr;
    Bool_t isProton = true;
    if (isProton)
    {
        simulation = new TFile("../outputFootMuSi/CorrectedBeam/twoProtons_cuts10meters_spreadBeam.root");
        simulation_tree = (TTree*)simulation->Get("er");
        reconstruction = new TFile("../outputFootMuSi/CorrectedBeam/reco_edepCutProtons_AngleCut0p025_twoProtons_cuts10meters_spreadBeam.root");
        reconstruction_tree = (TTree*)reconstruction->Get("er"); 
    outFile = new TFile("selectedTrees/twoProtonsVertexQA.root", "RECREATE");
    output_tree = new TTree("output_tree","output_tree");
    }
    else {
         simulation = new TFile("../outputFootMuSi/CorrectedBeam/singleHelium_cuts10meters_spreadBeam.root");
         simulation_tree = (TTree*)simulation->Get("er");
        reconstruction = new TFile("../outputFootMuSi/CorrectedBeam/reco_edepCutHelium_noAngleCut_singleHelium_cuts10meters_spreadBeam.root");
        reconstruction_tree = (TTree*)reconstruction->Get("er");
    outFile = new TFile("selectedTrees/He3TrackQA.root", "RECREATE");
    output_tree = new TTree("output_tree", "output_tree");
    }


    ERDecay7CEventHeader* decay_event_header = new ERDecay7CEventHeader();
    Double_t C7_invariant_mass;
    TVector3* C9FirstHit = nullptr, *C9SecondHit = nullptr, *reactionPosition = nullptr;
    Double_t deltaX = 0., deltaY = 0., deltaZ = 0., deltaOtherZ = 0., reactionZ = 0.;
    UInt_t uniqueID;
    TLorentzVector* C7_reco = new TLorentzVector();
    TClonesArray* footMuSiTracks = new TClonesArray("ERFootMuSiTrack");
    TClonesArray* footMuSiVerticies = new TClonesArray("ERFootMuSiVertex");
    TClonesArray* mcTrack = new TClonesArray("ERMCTrack");
    reconstruction_tree->SetBranchAddress("MCEventHeader.", &decay_event_header);
    reconstruction_tree->SetBranchAddress("FootMuSiTrack", &footMuSiTracks);
    reconstruction_tree->SetBranchAddress("FootMuSiVertex",&footMuSiVerticies);
    simulation_tree->SetBranchAddress("MCTrack", &mcTrack);
    /* output_tree->Branch("C7_reco", &C7_reco);
    output_tree->Branch("C7_invariant_mass", &C7_invariant_mass, "C7_invariant_mass/D"); */
    output_tree->Branch("deltaX", &deltaX, "deltaX/D");
    output_tree->Branch("deltaY", &deltaY, "deltaY/D");
    output_tree->Branch("deltaZ", &deltaZ, "deltaZ/D");
    output_tree->Branch("deltaOtherZ",&deltaOtherZ,"deltaOtherZ/D");
    output_tree->Branch("reactionZ", &reactionZ, "reactionZ/D");
    Long64_t totalEvents = reconstruction_tree->GetEntries();
    for (Long64_t eventNumber = 0; eventNumber < totalEvents; eventNumber++) {

        reconstruction_tree->GetEntry(eventNumber);
        simulation_tree->GetEntry(eventNumber);
        Int_t nTracks = footMuSiTracks->GetEntriesFast();
        Int_t nVerticies = footMuSiVerticies->GetEntriesFast();
        if (nTracks != 4) //number of tracks from two protons
        {
            continue;
        }
        for (int i = 0; i < nVerticies; i++)
        {
            ERFootMuSiVertex* footMuSiVertex = (ERFootMuSiVertex*)footMuSiVerticies->At(i); 
/*             ERMCTrack* c9MCTrack = (ERMCTrack*)mcTrack->At(i);
            ERFootMuSiTrack* footMuSiTrack = (ERFootMuSiTrack*)footMuSiTracks->At(i);

            Double_t tangentXZ = (footMuSiTrack->GetSecondHit().X() - footMuSiTrack->GetFirstHit().X()) / (footMuSiTrack->GetSecondHit().Z() - footMuSiTrack->GetFirstHit().Z());
            Double_t interceptXZ = (footMuSiTrack->GetFirstHit().X() + footMuSiTrack->GetSecondHit().X() - tangentXZ * (footMuSiTrack->GetFirstHit().Z() + footMuSiTrack->GetSecondHit().Z())) / 2;
            Double_t tangentYZ = (footMuSiTrack->GetThirdHit().Y() - footMuSiTrack->GetFirstHit().Y()) / (footMuSiTrack->GetThirdHit().Z() - footMuSiTrack->GetFirstHit().Z());
            Double_t interceptYZ = (footMuSiTrack->GetFirstHit().Y() + footMuSiTrack->GetThirdHit().Y() - tangentYZ * (footMuSiTrack->GetFirstHit().Z() + footMuSiTrack->GetThirdHit().Z())) / 2; */
            TVector3 reactionPos = decay_event_header->GetReactionPos();
            if(isProton)
            {
                deltaX = footMuSiVertex->X() - reactionPos.X();
                deltaY = footMuSiVertex->Y() - reactionPos.Y();
                deltaZ = footMuSiVertex->Z() - reactionPos.Z();
/*                      deltaX = (tangentXZ*c9MCTrack->GetStartZ()+interceptXZ)-c9MCTrack->GetStartX();
                    deltaY = (tangentYZ*c9MCTrack->GetStartZ()+interceptYZ)-c9MCTrack->GetStartY();
                    deltaZ = ((c9MCTrack->GetStartY()-interceptYZ)/tangentYZ) - c9MCTrack->GetStartZ();
                    deltaOtherZ = (footMuSiTrack->GetThirdHit().Y()-interceptYZ)/tangentYZ - footMuSiTrack->GetThirdHit().Z();
                    reactionZ = c9MCTrack->GetStartZ();  */

            }
            else{
/*             deltaX = (tangentXZ * reactionPos.Z() + interceptXZ) - reactionPos.X();
            deltaY = (tangentYZ * reactionPos.Z() + interceptYZ) - reactionPos.Y();
            deltaZ = (reactionPos.Y() - interceptYZ) / tangentYZ - reactionPos.Z();
            reactionZ = reactionPos.Z(); */

            }
        output_tree->Fill();
        }
        /*     TLorentzVector carbon_7 = decay_event_header->GetC7();
            TLorentzVector carbon_9 = decay_event_header->GetC9();
            TLorentzVector helium_3 = decay_event_header->GetHe3();
            TLorentzVector proton_no1 = decay_event_header->Getp1();
            TLorentzVector proton_no2 = decay_event_header->Getp2();
            TLorentzVector proton_no3 = decay_event_header->Getp3();
            TLorentzVector proton_no4 = decay_event_header->Getp4();
            *C7_reco = proton_no1 + proton_no2+ proton_no3+ proton_no4 + helium_3;
            C7_invariant_mass = sqrt(pow((helium_3.E()+proton_no1.E()+proton_no2.E()+proton_no3.E()+proton_no4.E()),2)-pow(helium_3.P()+proton_no1.P()+proton_no2.P()+proton_no3.P()+proton_no4.P(),2)) - (helium_3.M()+proton_no1.M() + proton_no2.M()+proton_no3.M()+proton_no4.M()); */
    }

    outFile->cd();
    output_tree->Write();

    /* simulation->cd();
    simulation->Close(); */

    TBrowser* tb = new TBrowser();

}
#if !defined(__CLING__)
#include <iostream>

#include "TClassTable.h"
#include "TSystem.h"
#include "TTree.h"
#include "TFile.h"
#include "Event.h"
#include "TH1D.h"

#include "ERDecay7CEventHeader.h"
#endif
void EventReader()
{
TFile *simulation = new TFile("../output/sim_thintarget.root");
TTree *simulation_tree = (TTree*)simulation->Get("er");

TFile *outFile = new TFile("../output/sim_thintarget_out.root", "RECREATE");
TTree *output_tree = new TTree("output_tree","output_tree");
ERDecay7CEventHeader* decay_event_header = new ERDecay7CEventHeader();
Double_t C7_invariant_mass;
TLorentzVector* C7_reco = new TLorentzVector();
output_tree->Branch("C7_reco", &C7_reco);
output_tree->Branch("C7_invariant_mass", &C7_invariant_mass, "C7_invariant_mass/D");
simulation_tree->SetBranchAddress("MCEventHeader.",&decay_event_header);
Long64_t totalEvents = simulation_tree->GetEntries();
for (Long64_t eventNumber = 0; eventNumber < totalEvents; ++eventNumber) {
    simulation_tree->GetEntry(eventNumber);
    TLorentzVector carbon_7 = decay_event_header->GetC7();
    TLorentzVector carbon_9 = decay_event_header->GetC9();
    TLorentzVector helium_3 = decay_event_header->GetHe3();
    TLorentzVector proton_no1 = decay_event_header->Getp1();
    TLorentzVector proton_no2 = decay_event_header->Getp2();
    TLorentzVector proton_no3 = decay_event_header->Getp3();
    TLorentzVector proton_no4 = decay_event_header->Getp4();
    *C7_reco = proton_no1 + proton_no2+ proton_no3+ proton_no4 + helium_3;
    C7_invariant_mass = sqrt(pow((helium_3.E()+proton_no1.E()+proton_no2.E()+proton_no3.E()+proton_no4.E()),2)-pow(helium_3.P()+proton_no1.P()+proton_no2.P()+proton_no3.P()+proton_no4.P(),2)) - (helium_3.M()+proton_no1.M() + proton_no2.M()+proton_no3.M()+proton_no4.M());
    output_tree->Fill();
}

outFile->cd();
output_tree->Write();
outFile->Close();

simulation->cd();
simulation->Close();

}
void draw_sim_digi()
{
    TTree *er = new TTree();
    TFile *f = new TFile("sim_digi.root");
    f->GetObject("er",er);
    
    TCanvas *c1 = new TCanvas();
    
    c1->cd();
    er->Draw("TelescopeDigi_Telescope_proton_SingleSi_R1_X.fEdep+ TelescopeDigi_Telescope_proton_SingleSi_Phi1_Y.fEdep: TelescopeDigi_Telescope_proton_SingleSi_R1_X.fEdep+ TelescopeDigi_Telescope_proton_SingleSi_Phi1_Y.fEdep+ TelescopeDigi_Telescope_proton_SingleSi_R1_X.fEdep+ TelescopeDigi_Telescope_proton_SingleSi_Phi2_Y.fEdep", "");
}

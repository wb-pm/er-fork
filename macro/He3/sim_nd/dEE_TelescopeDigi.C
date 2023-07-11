Int_t dEE_TelescopeDigi()
{
    TTree *er = new TTree();
    TFile *f = new TFile("sim_digi.root");
    f->GetObject("er",er);
    
    TCanvas *c1 = new TCanvas();
    
    c1->cd();
    er->Draw(
        "TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fEdep:TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fEdep+TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fEdep+TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fEdep+TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fEdep+TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fEdep", "");
    
     TCanvas *c2 = new TCanvas();
     c2->cd();
     er->Draw("(MCTrack.fEnergy-MCTrack.fMass)*1000:MCTrack.fTheta*TMath::RadToDeg()","MCTrack.fPdgCode==1000020030");
    return 0;
}

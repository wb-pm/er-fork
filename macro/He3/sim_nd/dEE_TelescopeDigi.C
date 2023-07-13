Int_t dEE_TelescopeDigi()
{
    TTree *er = new TTree();
    TFile *f = new TFile("sim_digi.root");
    f->GetObject("er",er);
    
    //TCanvas *c1 = new TCanvas();
    
    //c1->cd();
    //er->Draw("TelescopeDigi_Telescope_he8_SingleSi_SSD20_X.fEdep:TelescopeDigi_Telescope_he8_SingleSi_SSD20_1_Y.fEdep+ TelescopeDigi_Telescope_he8_SingleSi_SSD20_2_Y.fEdep+ TelescopeDigi_Telescope_he8_SingleSi_SSD20_3_Y.fEdep+ TelescopeDigi_Telescope_he8_SingleSi_SSD20_4_Y.fEdep+ TelescopeDigi_Telescope_he8_SingleSi_SSD20_5_Y.fEdep", "");
    
     TCanvas *c2 = new TCanvas();
     c2->cd();
     er->Draw("(MCEventHeader.fn1.fE-MCEventHeader.fn1.M())*1000:MCEventHeader.fn1.Theta()*TMath::RadToDeg()","MCEventHeader.fn1.fE>0.001");
     er->Draw("(MCEventHeader.fHe3.fE-MCEventHeader.fHe3.M())*1000/3.:MCEventHeader.fHe3.Theta()*TMath::RadToDeg()","MCEventHeader.fHe3.fE>0.001","same");
     
    return 0;
}

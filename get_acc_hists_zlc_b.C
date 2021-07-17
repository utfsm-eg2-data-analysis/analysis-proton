void get_acc_hists_zlc_b(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "hists_zlc_b_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString outf_name = "acc_hists_zlc_b_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc = new TH1F("hist_acc", "hist_acc", 20, 0.3, 1.2);
  
  TString hist_Rec_name = "hist_Rec";
  TString hist_Gen_name = "hist_Gen";
  TH1F *hist_Rec = (TH1F*) hists_f->Get(hist_Rec_name);
  TH1F *hist_Gen = (TH1F*) hists_f->Get(hist_Gen_name);
  hist_Rec->Sumw2();
  hist_Gen->Sumw2();
  hist_acc->Divide(hist_Rec,hist_Gen,1,1,"B");
  hists_f->Close();
  outf->Write();
  outf->Close();
}

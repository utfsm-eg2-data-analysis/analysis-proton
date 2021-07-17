void get_acc_ratio_hists_zlc_b(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "acc_hists_zlc_b_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString infile_D = "acc_hists_zlc_b_D.root";
  TFile *hists_f_D = TFile::Open(infile_D);

  TString outf_name = "acc_ratio_hists_zlc_b_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc_ratio = new TH1F("hist_acc_ratio", "hist_acc_ratio",20,0.3,1.2);

  TString hist_name = "hist_acc";
  TH1F *hist_D = (TH1F*) hists_f_D->Get(hist_name);
  TH1F *hist_targ = (TH1F*) hists_f->Get(hist_name);
  //hist_D->Sumw2();
  //hist_targ->Sumw2();
  hist_acc_ratio->Divide(hist_targ,hist_D);

  hists_f->Close();
  hists_f_D->Close();
  outf->Write();
  outf->Close();
}

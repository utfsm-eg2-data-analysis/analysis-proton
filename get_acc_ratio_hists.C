void get_acc_ratio_hists(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "acc_hists_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString infile_D = "acc_hists_D.root";
  TFile *hists_f_D = TFile::Open(infile_D);

  TString outf_name = "acc_ratio_hists_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc_ratio_11 = new TH1F("hist_acc_ratio_11", "hist_acc_ratio_11", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_12 = new TH1F("hist_acc_ratio_12", "hist_acc_ratio_12", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_13 = new TH1F("hist_acc_ratio_13", "hist_acc_ratio_13", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_21 = new TH1F("hist_acc_ratio_21", "hist_acc_ratio_21", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_22 = new TH1F("hist_acc_ratio_22", "hist_acc_ratio_22", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_23 = new TH1F("hist_acc_ratio_23", "hist_acc_ratio_23", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_31 = new TH1F("hist_acc_ratio_31", "hist_acc_ratio_31", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_32 = new TH1F("hist_acc_ratio_32", "hist_acc_ratio_32", 50, 0.0, 1.25);
  TH1F *hist_acc_ratio_33 = new TH1F("hist_acc_ratio_33", "hist_acc_ratio_33", 50, 0.0, 1.25);

  TH1* hists_acc_ratio[9]={hist_acc_ratio_11,hist_acc_ratio_12,hist_acc_ratio_13,hist_acc_ratio_21,hist_acc_ratio_22,hist_acc_ratio_23,hist_acc_ratio_31,hist_acc_ratio_32,hist_acc_ratio_33};
  
  Int_t n=0;
 for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
	TString hist_name = "hist_acc_"+TString(Form("%i",i))+TString(Form("%i",j));
	TH1F *hist_D = (TH1F*) hists_f_D->Get(hist_name);
	TH1F *hist_targ = (TH1F*) hists_f->Get(hist_name);
        //hist_D->Sumw2();
	//hist_targ->Sumw2();
	hists_acc_ratio[n]->Divide(hist_targ,hist_D);
        n+=1;
      };
    };
    hists_f->Close();
    hists_f_D->Close();
    outf->Write();
    outf->Close();
}

void get_acc_ratio_hists_Pt2Zh(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "acc_hists_Pt2Zh_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString infile_D = "acc_hists_Pt2Zh_D.root";
  TFile *hists_f_D = TFile::Open(infile_D);

  TString outf_name = "acc_ratio_hists_Pt2Zh_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc_ratio_1 = new TH1F("hist_acc_ratio_1", "hist_acc_ratio_1", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_2 = new TH1F("hist_acc_ratio_2", "hist_acc_ratio_2", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_3 = new TH1F("hist_acc_ratio_3", "hist_acc_ratio_3", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_4 = new TH1F("hist_acc_ratio_4", "hist_acc_ratio_4", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_5 = new TH1F("hist_acc_ratio_5", "hist_acc_ratio_5", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_6 = new TH1F("hist_acc_ratio_6", "hist_acc_ratio_6", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_7 = new TH1F("hist_acc_ratio_7", "hist_acc_ratio_7", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_8 = new TH1F("hist_acc_ratio_8", "hist_acc_ratio_8", 30, 0.0, 2.0);
  TH1F *hist_acc_ratio_9 = new TH1F("hist_acc_ratio_9", "hist_acc_ratio_9", 30, 0.0, 2.0);

  TH1* hists_acc_ratio[9]={hist_acc_ratio_1,hist_acc_ratio_2,hist_acc_ratio_3,hist_acc_ratio_4,hist_acc_ratio_5,hist_acc_ratio_6,hist_acc_ratio_7,hist_acc_ratio_8,hist_acc_ratio_9};
  
  Int_t n=0;
 for(int i=1; i<=9; i++){
	TString hist_name = "hist_acc_"+TString(Form("%i",i));
	TH1F *hist_D = (TH1F*) hists_f_D->Get(hist_name);
	TH1F *hist_targ = (TH1F*) hists_f->Get(hist_name);
        //hist_D->Sumw2();
	//hist_targ->Sumw2();
	hists_acc_ratio[n]->Divide(hist_targ,hist_D);
        n+=1;
    };
    hists_f->Close();
    hists_f_D->Close();
    outf->Write();
    outf->Close();
}

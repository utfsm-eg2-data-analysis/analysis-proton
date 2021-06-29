void get_acc_hists_Pt2Zh(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "hists_Pt2Zh_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString outf_name = "acc_hists_Pt2Zh_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc_1 = new TH1F("hist_acc_1", "hist_acc_1", 30, 0.0, 2.0);
  TH1F *hist_acc_2 = new TH1F("hist_acc_2", "hist_acc_2", 30, 0.0, 2.0);
  TH1F *hist_acc_3 = new TH1F("hist_acc_3", "hist_acc_3", 30, 0.0, 2.0);
  TH1F *hist_acc_4 = new TH1F("hist_acc_4", "hist_acc_4", 30, 0.0, 2.0);
  TH1F *hist_acc_5 = new TH1F("hist_acc_5", "hist_acc_5", 30, 0.0, 2.0);
  TH1F *hist_acc_6 = new TH1F("hist_acc_6", "hist_acc_6", 30, 0.0, 2.0);
  TH1F *hist_acc_7 = new TH1F("hist_acc_7", "hist_acc_7", 30, 0.0, 2.0);
  TH1F *hist_acc_8 = new TH1F("hist_acc_8", "hist_acc_8", 30, 0.0, 2.0);
  TH1F *hist_acc_9 = new TH1F("hist_acc_9", "hist_acc_9", 30, 0.0, 2.0);

  TH1* hists_acc[9]={hist_acc_1,hist_acc_2,hist_acc_3,hist_acc_4,hist_acc_5,hist_acc_6,hist_acc_7,hist_acc_8,hist_acc_9};

  Int_t n=0;
 for(int i=1; i<=9; i++){
	TString hist_Rec_name = "hist_Rec_"+TString(Form("%i",i));
	TString hist_Gen_name = "hist_Gen_"+TString(Form("%i",i));
	TH1F *hist_Rec = (TH1F*) hists_f->Get(hist_Rec_name);
	TH1F *hist_Gen = (TH1F*) hists_f->Get(hist_Gen_name);
	hist_Rec->Sumw2();
	hist_Gen->Sumw2();
	hists_acc[n]->Divide(hist_Rec,hist_Gen,1,1,"B");
        n+=1;
    };
    hists_f->Close();
    outf->Write();
    outf->Close();
}

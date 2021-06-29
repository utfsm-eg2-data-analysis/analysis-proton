void get_acc_hists(TString tar){

TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  TString infile = "hists_"+targ+".root";
  TFile *hists_f = TFile::Open(infile);

  TString outf_name = "acc_hists_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");

  TH1F *hist_acc_11 = new TH1F("hist_acc_11", "hist_acc_11", 50, 0.0, 1.25);
  TH1F *hist_acc_12 = new TH1F("hist_acc_12", "hist_acc_12", 50, 0.0, 1.25);
  TH1F *hist_acc_13 = new TH1F("hist_acc_13", "hist_acc_13", 50, 0.0, 1.25);
  TH1F *hist_acc_21 = new TH1F("hist_acc_21", "hist_acc_21", 50, 0.0, 1.25);
  TH1F *hist_acc_22 = new TH1F("hist_acc_22", "hist_acc_22", 50, 0.0, 1.25);
  TH1F *hist_acc_23 = new TH1F("hist_acc_23", "hist_acc_23", 50, 0.0, 1.25);
  TH1F *hist_acc_31 = new TH1F("hist_acc_31", "hist_acc_31", 50, 0.0, 1.25);
  TH1F *hist_acc_32 = new TH1F("hist_acc_32", "hist_acc_32", 50, 0.0, 1.25);
  TH1F *hist_acc_33 = new TH1F("hist_acc_33", "hist_acc_33", 50, 0.0, 1.25);

  TH1* hists_acc[9]={hist_acc_11,hist_acc_12,hist_acc_13,hist_acc_21,hist_acc_22,hist_acc_23,hist_acc_31,hist_acc_32,hist_acc_33};
  
  Int_t n=0;
 for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
	TString hist_Rec_name = "hist_Rec_"+TString(Form("%i",i))+TString(Form("%i",j));
	TString hist_Gen_name = "hist_Gen_"+TString(Form("%i",i))+TString(Form("%i",j));
	TH1F *hist_Rec = (TH1F*) hists_f->Get(hist_Rec_name);
	TH1F *hist_Gen = (TH1F*) hists_f->Get(hist_Gen_name);
	hist_Rec->Sumw2();
	hist_Gen->Sumw2();
	hists_acc[n]->Divide(hist_Rec,hist_Gen,1,1,"B");
        n+=1;
      };
    };
    hists_f->Close();
    outf->Write();
    outf->Close();
}

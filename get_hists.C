/* Receive all Rec&Gen Trees for a target (like in add_Trees), add all the corresponding leaves to a histogram (instead of another Tree) with the sqrt() errors. Then divide the histrograms with Binomial errors*/

void get_hists(TString tar){

  TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };
  TString outf_name = "hists_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");


  TH1F *hist_Rec_11 = new TH1F("hist_Rec_11", "hist_Rec_11", 50, 0.0, 1.25);
  TH1F *hist_Rec_12 = new TH1F("hist_Rec_12", "hist_Rec_12", 50, 0.0, 1.25);
  TH1F *hist_Rec_13 = new TH1F("hist_Rec_13", "hist_Rec_13", 50, 0.0, 1.25);
  TH1F *hist_Rec_21 = new TH1F("hist_Rec_21", "hist_Rec_21", 50, 0.0, 1.25);
  TH1F *hist_Rec_22 = new TH1F("hist_Rec_22", "hist_Rec_22", 50, 0.0, 1.25);
  TH1F *hist_Rec_23 = new TH1F("hist_Rec_23", "hist_Rec_23", 50, 0.0, 1.25);
  TH1F *hist_Rec_31 = new TH1F("hist_Rec_31", "hist_Rec_31", 50, 0.0, 1.25);
  TH1F *hist_Rec_32 = new TH1F("hist_Rec_32", "hist_Rec_32", 50, 0.0, 1.25);
  TH1F *hist_Rec_33 = new TH1F("hist_Rec_33", "hist_Rec_33", 50, 0.0, 1.25);
  TH1F *hist_Gen_11 = new TH1F("hist_Gen_11", "hist_Gen_11", 50, 0.0, 1.25);
  TH1F *hist_Gen_12 = new TH1F("hist_Gen_12", "hist_Gen_12", 50, 0.0, 1.25);
  TH1F *hist_Gen_13 = new TH1F("hist_Gen_13", "hist_Gen_13", 50, 0.0, 1.25);
  TH1F *hist_Gen_21 = new TH1F("hist_Gen_21", "hist_Gen_21", 50, 0.0, 1.25);
  TH1F *hist_Gen_22 = new TH1F("hist_Gen_22", "hist_Gen_22", 50, 0.0, 1.25);
  TH1F *hist_Gen_23 = new TH1F("hist_Gen_23", "hist_Gen_23", 50, 0.0, 1.25);
  TH1F *hist_Gen_31 = new TH1F("hist_Gen_31", "hist_Gen_31", 50, 0.0, 1.25);
  TH1F *hist_Gen_32 = new TH1F("hist_Gen_32", "hist_Gen_32", 50, 0.0, 1.25);
  TH1F *hist_Gen_33 = new TH1F("hist_Gen_33", "hist_Gen_33", 50, 0.0, 1.25);

  TH1F* hists_Rec[9]={hist_Rec_11,hist_Rec_12,hist_Rec_13,hist_Rec_21,hist_Rec_22,hist_Rec_23,hist_Rec_31,hist_Rec_32,hist_Rec_33};
  TH1F* hists_Gen[9]={hist_Gen_11,hist_Gen_12,hist_Gen_13,hist_Gen_21,hist_Gen_22,hist_Gen_23,hist_Gen_31,hist_Gen_32,hist_Gen_33};
  
  Double_t Rec, Gen; 
  Double_t rec_t, gen_t;
  Int_t skip_count=0;
  Int_t n;
  for(int k=1; k<=50; k++){
    n=0;
    for(int i=1; i<=3; i++){
      for(int j=1; j<=3; j++){
	Rec=0;
	Gen=0;
	for(int l=1; l<=25; l++){
	  if(l==5){ //only for Pb (i==3&&j==&&l==3) and C (l==5)
	   printf("Skip\n");
	   skip_count+=1;
	  }else{
	  TString run;
	  if(l<10){
	    run = "0"+TString(Form("%i",l));
	  }else{
	    run = TString(Form("%i",l));
	  };
	  TString tree_f = "/lustre19/expphy/volatile/clas/claseg2/jpgarces/Acceptance_out/"+targ+"/Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j))+".root";
	  //TString tree_f ="Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j))+".root";
	  TString tree_name = "Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j));
	  TString rec_st = "Rec_"+TString(Form("%i",i))+TString(Form("%i",j));
	  TString gen_st = "Gen_"+TString(Form("%i",i))+TString(Form("%i",j));
	  TFile *tree_file = TFile::Open(tree_f);
	  TTree *RG_Tree = (TTree*) tree_file->Get(tree_name);
	  RG_Tree->SetBranchAddress(rec_st,&rec_t);
	  RG_Tree->SetBranchAddress(gen_st,&gen_t);
	  RG_Tree->GetBranch(rec_st)->GetEntry(k);
	  RG_Tree->GetBranch(gen_st)->GetEntry(k);
	  Rec+=rec_t;
	  Gen+=gen_t;
	  tree_file->Close();
	  };
	};
	printf("Rec:%f\n",Rec);
	printf("Gen:%f\n",Gen);
	hists_Rec[n]->SetBinContent(k,Rec);
	hists_Gen[n]->SetBinContent(k,Gen);
	//hists_Rec[n]->SetBinError(k,TMath::sqrt(Rec)); //No need to use SetBinError since the errors are set as sqrt() of the bin content by default
	//hists_Gen[n]->SetBinError(k,TMath::sqrt(Gen));
        n+=1;
      };
    };
  };
  //printf("Skip Count: %i",skip_count);
  outf->Write();
  outf->Close();
}

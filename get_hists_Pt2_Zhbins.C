/* Receive all Rec&Gen Trees for a target (like in add_Trees), add all the corresponding leaves to a histogram (instead of another Tree) with the sqrt() errors. Then divide the histrograms with Binomial errors*/

void get_hists_Pt2_Zhbins(TString tar){

  TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };
  TString outf_name = "hists_Pt2Zh_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");


  TH1F *hist_Rec_1 = new TH1F("hist_Rec_1", "hist_Rec_1", 30, 0.0, 2.0);
  TH1F *hist_Rec_2 = new TH1F("hist_Rec_2", "hist_Rec_2", 30, 0.0, 2.0);
  TH1F *hist_Rec_3 = new TH1F("hist_Rec_3", "hist_Rec_3", 30, 0.0, 2.0);
  TH1F *hist_Rec_4 = new TH1F("hist_Rec_4", "hist_Rec_4", 30, 0.0, 2.0);
  TH1F *hist_Rec_5 = new TH1F("hist_Rec_5", "hist_Rec_5", 30, 0.0, 2.0);
  TH1F *hist_Rec_6 = new TH1F("hist_Rec_6", "hist_Rec_6", 30, 0.0, 2.0);
  TH1F *hist_Rec_7 = new TH1F("hist_Rec_7", "hist_Rec_7", 30, 0.0, 2.0);
  TH1F *hist_Rec_8 = new TH1F("hist_Rec_8", "hist_Rec_8", 30, 0.0, 2.0);
  TH1F *hist_Rec_9 = new TH1F("hist_Rec_9", "hist_Rec_9", 30, 0.0, 2.0);
  TH1F *hist_Gen_1 = new TH1F("hist_Gen_1", "hist_Gen_1", 30, 0.0, 2.0);
  TH1F *hist_Gen_2 = new TH1F("hist_Gen_2", "hist_Gen_2", 30, 0.0, 2.0);
  TH1F *hist_Gen_3 = new TH1F("hist_Gen_3", "hist_Gen_3", 30, 0.0, 2.0);
  TH1F *hist_Gen_4 = new TH1F("hist_Gen_4", "hist_Gen_4", 30, 0.0, 2.0);
  TH1F *hist_Gen_5 = new TH1F("hist_Gen_5", "hist_Gen_5", 30, 0.0, 2.0);
  TH1F *hist_Gen_6 = new TH1F("hist_Gen_6", "hist_Gen_6", 30, 0.0, 2.0);
  TH1F *hist_Gen_7 = new TH1F("hist_Gen_7", "hist_Gen_7", 30, 0.0, 2.0);
  TH1F *hist_Gen_8 = new TH1F("hist_Gen_8", "hist_Gen_8", 30, 0.0, 2.0);
  TH1F *hist_Gen_9 = new TH1F("hist_Gen_9", "hist_Gen_9", 30, 0.0, 2.0);

  TH1* hists_Rec[9]={hist_Rec_1,hist_Rec_2,hist_Rec_3,hist_Rec_4,hist_Rec_5,hist_Rec_6,hist_Rec_7,hist_Rec_8,hist_Rec_9};
  TH1* hists_Gen[9]={hist_Gen_1,hist_Gen_2,hist_Gen_3,hist_Gen_4,hist_Gen_5,hist_Gen_6,hist_Gen_7,hist_Gen_8,hist_Gen_9};
  
  Double_t Rec, Gen; 
  Double_t rec_t, gen_t;
  Int_t skip_count=0;
  Int_t n;
  for(int k=1; k<=30; k++){
    n=0;
    for(int i=1; i<=9; i++){
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
	  TString tree_f = "/lustre19/expphy/volatile/clas/claseg2/jpgarces/Acceptance_out/Pt2Zh/"+targ+"/Tree_Pt2Zh_" + targ +"_"+ run +"_"+TString(Form("%i",i))+".root";
	  //TString tree_f ="Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j))+".root";
	  TString tree_name = "Tree_Pt2Zh_" + targ +"_"+ run +"_"+TString(Form("%i",i));
	  TString rec_st = "Rec_"+TString(Form("%i",i));
	  TString gen_st = "Gen_"+TString(Form("%i",i));
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
  //printf("Skip Count: %i",skip_count);
  outf->Write();
  outf->Close();
}

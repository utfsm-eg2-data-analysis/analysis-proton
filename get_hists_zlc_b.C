/* Receive all Rec&Gen Trees for a target (like in add_Trees), add all the corresponding leaves to a histogram (instead of another Tree) with the sqrt() errors. Then divide the histrograms with Binomial errors*/

void get_hists_zlc_b(TString tar){

  TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };
  TString outf_name = "hists_zlc_b_"+targ+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");


  TH1F *hist_Rec = new TH1F("hist_Rec", "hist_Rec", 20, 0.3, 1.2);
  
  TH1F *hist_Gen = new TH1F("hist_Gen", "hist_Gen", 20, 0.3, 1.2);
  
  Double_t Rec, Gen; 
  Double_t rec_t, gen_t;
  Int_t skip_count=0;
  for(int k=1; k<=20; k++){
	Rec=0;
	Gen=0;
	for(int l=1; l<=25; l++){
	  //if(l==5){ //only for Pb (i==3&&j==&&l==3) and C (l==5)
	  //printf("Skip\n");
	  //skip_count+=1;
	  //}else{
	  TString run;
	  if(l<10){
	    run = "0"+TString(Form("%i",l));
	  }else{
	    run = TString(Form("%i",l));
	  };
	  TString tree_f = "/lustre19/expphy/volatile/clas/claseg2/jpgarces/Acceptance_out/zlc/"+targ+"/Tree_" + targ +"_"+ run +"_zlc_b.root";
	  //TString tree_f ="Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j))+".root";
	  TString tree_name = "Tree_" + targ +"_"+ run +"_zlc_b";
	  TString rec_st = "Rec";
	  TString gen_st = "Gen";
	  TFile *tree_file = TFile::Open(tree_f);
	  TTree *RG_Tree = (TTree*) tree_file->Get(tree_name);
	  RG_Tree->SetBranchAddress(rec_st,&rec_t);
	  RG_Tree->SetBranchAddress(gen_st,&gen_t);
	  RG_Tree->GetBranch(rec_st)->GetEntry(k);
	  RG_Tree->GetBranch(gen_st)->GetEntry(k);
	  Rec+=rec_t;
	  Gen+=gen_t;
	  tree_file->Close();
	  //};
	};
	printf("Rec:%f\n",Rec);
	printf("Gen:%f\n",Gen);
	hist_Rec->SetBinContent(k,Rec);
	hist_Gen->SetBinContent(k,Gen);
	//hists_Rec[n]->SetBinError(k,TMath::sqrt(Rec)); //No need to use SetBinError since the errors are set as sqrt() of the bin content by default
	//hists_Gen[n]->SetBinError(k,TMath::sqrt(Gen));
  };
  //printf("Skip Count: %i",skip_count);
  outf->Write();
  outf->Close();
}

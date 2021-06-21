void add_trees(TString tar){

  TString targ;
  
  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  /*else if(tar=='A'){
    targ = "C";
    }*/

  TString out_tree = "A_Tree_"+targ;
  TString outf_name = out_tree+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");
  TTree *A_Tree = new TTree(out_tree,"Acceptance");
 
  Double_t acc_11,acc_12,acc_13,acc_21,acc_22,acc_23,acc_31,acc_32,acc_33;
  Double_t* acc[3][3]={{&acc_11,&acc_12,&acc_13},{&acc_21,&acc_22,&acc_23},{&acc_31,&acc_32,&acc_33}};

  for(int i=1; i<=3; i++){
    for(int j=1; j<=3; j++){
      TString branch = "acc_"+TString(Form("%i",i))+TString(Form("%i",j));
      TString type = branch + "/D";
      A_Tree->Branch(branch,acc[i-1][j-1],type);
    };
  };

  Double_t Rec, Gen; 
  Double_t rec_t, gen_t;
  Int_t skip_count=0;
  for(int k=1; k<=50; k++){
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
	  TString tree_name = "Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j));
	  //TString tree_name = "Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j));
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
	  };
	};
	printf("Rec:%f\n",Rec);
	printf("Gen:%f\n",Gen);
	*(acc[i-1][j-1])=(Rec/Gen);
      };
    };
    A_Tree->Fill();
  };
  printf("Skip Count: %i",skip_count);
  outf->Write();
  outf->Close();
}

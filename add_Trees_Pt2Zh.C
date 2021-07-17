void add_Trees_Pt2Zh(TString tar){

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

  TString out_tree = "A_Tree_"+targ+"_Pt2Zh";
  TString outf_name = out_tree+".root";
  TFile *outf = new TFile(outf_name,"RECREATE");
  TTree *A_Tree = new TTree(out_tree,"Acceptance");
 
  Double_t acc_1,acc_2,acc_3,acc_4,acc_5,acc_6,acc_7,acc_8,acc_9;
  Double_t* acc[9]={&acc_1,&acc_2,&acc_3,&acc_4,&acc_5,&acc_6,&acc_7,&acc_8,&acc_9};

  for(int i=0; i<9; i++){
      TString branch = "acc_"+TString(Form("%i",i));
      TString type = branch + "/D";
      A_Tree->Branch(branch,acc[i],type);
  };

  Double_t Rec, Gen; 
  Double_t rec_t, gen_t;
  Int_t skip_count=0;
  for(int k=1; k<=30; k++){
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
	  TString tree_name = "Tree_Pt2Zh_" + targ +"_"+ run +"_"+TString(Form("%i",i));
	  //TString tree_name = "Tree_" + targ +"_"+ run +"_"+TString(Form("%i",i))+TString(Form("%i",j));
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
	*(acc[i-1])=(Rec/Gen);
    };
    A_Tree->Fill();
  };
  printf("Skip Count: %i",skip_count);
  outf->Write();
  outf->Close();
}

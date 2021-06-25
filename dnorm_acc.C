void dnorm_acc(){
  TFile *outf = new TFile("A_Tree.root","RECREATE");

  TString tree_names[4]={"A_Tree_D","A_Tree_C","A_Tree_Fe","A_Tree_Pb"};
  
  TTree *A_Tree_C_N = new TTree("A_Tree_C_N","Normalized acceptance for Carbon");
  TTree *A_Tree_Fe_N = new TTree("A_Tree_Fe_N","Normalized acceptance for Iron");
  TTree *A_Tree_Pb_N = new TTree("A_Tree_Pb_N","Normalized acceptance for Lead");

  TTree* Trees[3]={A_Tree_C_N,A_Tree_Fe_N,A_Tree_Pb_N};

  //TString tree_files[4] = {"/u/home/jpgarces/A_Tree_D.root","/u/home/jpgarces/A_Tree_C.root","/u/home/jpgarces/A_Tree_Fe.root","/u/home/jpgarces/A_Tree_Pb.root"};
  TString tree_files[4] = {"A_Tree_D.root","A_Tree_C.root","A_Tree_Fe.root","A_Tree_Pb.root"};

  Double_t n_acc_11,n_acc_12,n_acc_13,n_acc_21,n_acc_22,n_acc_23,n_acc_31,n_acc_32,n_acc_33;
  Double_t* n_acc[3][3]={{&n_acc_11,&n_acc_12,&n_acc_13},{&n_acc_21,&n_acc_22,&n_acc_23},{&n_acc_31,&n_acc_32,&n_acc_33}};

  Double_t acc_D, acc_targ, acc_N;

  TFile *tree_file_D = TFile::Open(tree_files[0]);
  TFile *tree_file_C = TFile::Open(tree_files[1]);
  TFile *tree_file_Fe = TFile::Open(tree_files[2]);
  TFile *tree_file_Pb = TFile::Open(tree_files[3]);
  TFile* files[4]={tree_file_D,tree_file_C,tree_file_Fe,tree_file_Pb};
  TTree *A_Tree_D = (TTree*) files[0]->Get(tree_names[0]);
  
for(int l=1; l<4; l++){
  TTree *A_Tree_targ = (TTree*) files[l]->Get(tree_names[l]);
  for(int k=1; k<=50; k++){
    for(int i=1; i<=3; i++){
      for(int j=1; j<=3; j++){
	if(k==1){
	  TString branch = "n_acc_"+TString(Form("%i",i))+TString(Form("%i",j));
	  TString type = branch + "/D";
	  Trees[l-1]->Branch(branch,n_acc[i-1][j-1],type);
	};
	  TString acc_st = "acc_"+TString(Form("%i",i))+TString(Form("%i",j));
	  A_Tree_D->SetBranchAddress(acc_st,&acc_D);
	  A_Tree_targ->SetBranchAddress(acc_st,&acc_targ);
	  A_Tree_targ->GetBranch(acc_st)->GetEntry(k);
	  A_Tree_D->GetBranch(acc_st)->GetEntry(k);
	  printf("%f\n",acc_targ);
	  printf("%f\n",acc_D);
	  *(n_acc[i-1][j-1])=(acc_targ/acc_D);
      };
    };
    Trees[l-1]->Fill();
  };
};
  outf->Write();
  outf->Close();
}

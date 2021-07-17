void plot_1d_zlc_b(TString tar,Int_t r){

  TString targ;

  if(tar=='F'){
    targ = "Fe";
  }else if(tar=='P'){
    targ = "Pb";
  }else{
    targ = tar;
  };

  /* Cuts */
  TCut cut1 = "P>0.5";
  TCut cut2 = "P<3";
  TCut cut3 = "pid==2212";
  TCut cut4 = "Q2>1";
  TCut cut5 = "W>2";
  TCut cut6 = "Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))<(-0.00218+3*0.01002)";
  TCut cut7 = "Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))>(-0.00218-3*0.01002)";
  TCut cut8="Yb<=0.85";
  TCut cut1_mc = "mc_P>0.5";
  TCut cut2_mc = "mc_P<3";
  TCut cut3_mc = "mc_pid==2212";
  TCut cut4_mc = "mc_Q2>1";
  TCut cut5_mc = "mc_W>2";
  TCut cut6_mc = "mc_Betta-(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz))/(TMath::Sqrt(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)*TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)+0.938272*0.938272))<(-0.00218+3*0.01002)";
  TCut cut7_mc = "mc_Betta-(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz))/(TMath::Sqrt(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)*TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)+0.938272*0.938272))>(-0.00218-3*0.01002)";
  TCut cut8_mc="mc_Yb<=0.85";

  /* Bins */

Double_t cuts_zlc_b[20] = {0.300000,0.345000,0.390000,0.435000,0.480000,0.525000,0.570000,0.615000,0.660000,0.705000,0.750000,0.795000,0.840000,0.885000,0.930000,0.975000,1.020000,1.065000,1.110000,1.155000};

Double_t cuts_zlc_t[20] ={0.345000,0.390000,0.435000,0.480000,0.525000,0.570000,0.615000,0.660000,0.705000,0.750000,0.795000,0.840000,0.885000,0.930000,0.975000,1.020000,1.065000,1.110000,1.155000,1.200000};



/* ------ end of Cut info ---- */

/* Histograms to extract data and Tree to save data */
//Double_t Rec_count=0;                                                                              
//Double_t Gen_count=0;                                                                              

TString run;

if (r<10){
  run = "0"+TString(Form("%i",r));
};

if (r >= 10){
  run = TString(Form("%i",r));
};

TString infile = "/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/"+targ+"/pruned"+targ+"_"+run+".root";
//TString infile="prunedC_all.root";
//TString infile="prunedD_01.root";                                                                 
TFile *f1 = TFile::Open(infile); /* Open file where the tree is located */
TTree* ntuple_sim = (TTree*) f1->Get("ntuple_sim"); /* Read tree */

TString tree_name = "Tree_" + targ +"_"+ run +"_zlc_b";
TString outf_name =tree_name+".root";
TFile *outf = new TFile(outf_name,"RECREATE"); /* Save output plots in a root file */

 TH1F *zlc_Gen = new TH1F("zlc_Gen","zlc_Gen",20,0.3,1.2);
 TH1F *zlc_Rec = new TH1F("zlc_Rec","zlc_Rec",20,0.3,1.2);

 TTree *RG_Tree = new TTree(tree_name,"Rec and Gen entries");

 Double_t Rec;
 Double_t Gen;

 TString branch_R = "Rec";
 TString branch_G = "Gen";

 TString type_R = branch_R+"/D";
 TString type_G = branch_G+"/D";


 RG_Tree->Branch(branch_R,&Rec,type_R);
 RG_Tree->Branch(branch_G,&Gen,type_G);

 Float_t Nu, Q2, P, W, Betta, Px, Py, Pz, Yb, pid, zlc, d_Betta;
 Float_t mc_Nu, mc_Q2, mc_P, mc_W, mc_Betta, mc_Px, mc_Py, mc_Pz, mc_Yb, mc_pid, mc_zlc, d_mc_Betta;

 Int_t counter_rec, counter_gen;

 ntuple_sim->SetBranchAddress("Nu",&Nu);
 ntuple_sim->SetBranchAddress("Q2",&Q2);
 ntuple_sim->SetBranchAddress("Pz",&Pz);
 ntuple_sim->SetBranchAddress("P",&P);
 ntuple_sim->SetBranchAddress("W",&W);
 ntuple_sim->SetBranchAddress("Betta",&Betta);
 ntuple_sim->SetBranchAddress("Px",&Px);
 ntuple_sim->SetBranchAddress("Py",&Py);
 ntuple_sim->SetBranchAddress("Pz",&Pz);
 ntuple_sim->SetBranchAddress("Yb",&Yb);
 ntuple_sim->SetBranchAddress("pid",&pid);
 ntuple_sim->SetBranchAddress("mc_Nu",&mc_Nu);
 ntuple_sim->SetBranchAddress("mc_Q2",&mc_Q2);
 ntuple_sim->SetBranchAddress("mc_Pz",&mc_Pz);
 ntuple_sim->SetBranchAddress("mc_P",&mc_P);
 ntuple_sim->SetBranchAddress("mc_W",&mc_W);
 ntuple_sim->SetBranchAddress("mc_Betta",&mc_Betta);
 ntuple_sim->SetBranchAddress("mc_Px",&mc_Px);
 ntuple_sim->SetBranchAddress("mc_Py",&mc_Py);
 ntuple_sim->SetBranchAddress("mc_Pz",&mc_Pz);
 ntuple_sim->SetBranchAddress("mc_Yb",&mc_Yb);
 ntuple_sim->SetBranchAddress("mc_pid",&mc_pid);

 
 for(int k=1; k<=20; k++){
   counter_rec=0;
   counter_gen=0;
   for(int i=0;i<ntuple_sim->GetEntries();i++){
     ntuple_sim->GetEntry(i);
     zlc=(TMath::Sqrt(0.938272*0.938272+P*P)+Pz)/(0.938272+2*Nu);
     mc_zlc=(TMath::Sqrt(0.938272*0.938272+mc_P*mc_P)+mc_Pz)/(0.938272+2*mc_Nu);
     d_Betta=Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272));
     d_mc_Betta=mc_Betta-(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz))/(TMath::Sqrt(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)*TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)+0.938272*0.938272));
     if(P>0.5&&P<3.0&&pid==2212&&Q2>1&&W>2&&Yb<=0.85&&d_Betta<(-0.00218+3*0.01002)&&d_Betta>(-0.00218-3*0.01002)&&cuts_zlc_b[k-1]<=zlc&&zlc<cuts_zlc_t[k-1]){
       counter_rec+=1;
     }
     if(mc_P>0.5&&mc_P<3.0&&mc_pid==2212&&mc_Q2>1&&mc_W>2&&mc_Yb<=0.85&&d_mc_Betta<(-0.00218+3*0.01002)&&d_mc_Betta>(-0.00218-3*0.01002)&&cuts_zlc_b[k-1]<=mc_zlc&&mc_zlc<cuts_zlc_t[k-1]){
       counter_gen+=1;
     }
   }
   Rec=counter_rec;
   Gen=counter_gen;
   RG_Tree->Fill();
 }

 /* Export plots */
 outf->Write();
 outf->Close(); /* (i) root plot_out.root; (ii) new TBrowser */
}

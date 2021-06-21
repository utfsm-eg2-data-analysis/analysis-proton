/* USE THIS SCRIPT CREATE THE HISTOGRAMS FROM THE TREES STORED AT THE JLAB CLUSTER  */

/* The output root file that we obtain from here is what we import to our personal computer */

/* root -l -q plot_jlab_bins.C('D',1,2,1) */

void plot_jlab_bins(TString tar,Int_t r,Int_t a,Int_t b){

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
  TCut cuts_Q2_b[3] = {"1.0<=Q2","1.3<Q2", "1.8<Q2"};
  TCut cuts_Q2_t[3] = {"Q2<=1.3","Q2<=1.8","Q2<=4.10"};

  TCut cuts_Nu_b[3] = {"2.20<=Nu","3.20<Nu", "3.7<Nu"};
  TCut cuts_Nu_t[3] = {"Nu<=3.20","Nu<=3.7","Nu<=4.2"};

  TCut cuts_Zh_b[50] = {"0.000000<=Zh","0.025000<Zh","0.050000<Zh","0.075000<Zh","0.100000<Zh","0.125000<Zh","0.150000<Zh","0.175000<Zh","0.200000<Zh","0.225000<Zh","0.250000<Zh","0.275000<Zh","0.300000<Zh","0.325000<Zh","0.350000<Zh","0.375000<Zh","0.400000<Zh","0.425000<Zh","0.450000<Zh","0.475000<Zh","0.500000<Zh","0.525000<Zh","0.550000<Zh","0.575000<Zh","0.600000<Zh","0.625000<Zh","0.650000<Zh","0.675000<Zh","0.700000<Zh","0.725000<Zh","0.750000<Zh","0.775000<Zh","0.800000<Zh","0.825000<Zh","0.850000<Zh","0.875000<Zh","0.900000<Zh","0.925000<Zh","0.950000<Zh","0.975000<Zh","1.000000<Zh","1.025000<Zh","1.050000<Zh","1.075000<Zh","1.100000<Zh","1.125000<Zh","1.150000<Zh","1.175000<Zh","1.200000<Zh","1.225000<Zh"};

  TCut cuts_Zh_t[50] = {"Zh<=0.025000","Zh<=0.050000","Zh<=0.075000","Zh<=0.100000","Zh<=0.125000","Zh<=0.150000","Zh<=0.175000","Zh<=0.200000","Zh<=0.225000","Zh<=0.250000","Zh<=0.275000","Zh<=0.300000","Zh<=0.325000","Zh<=0.350000","Zh<=0.375000","Zh<=0.400000","Zh<=0.425000","Zh<=0.450000","Zh<=0.475000","Zh<=0.500000","Zh<=0.525000","Zh<=0.550000","Zh<=0.575000","Zh<=0.600000","Zh<=0.625000","Zh<=0.650000","Zh<=0.675000","Zh<=0.700000","Zh<=0.725000","Zh<=0.750000","Zh<=0.775000","Zh<=0.800000","Zh<=0.825000","Zh<=0.850000","Zh<=0.875000","Zh<=0.900000","Zh<=0.925000","Zh<=0.950000","Zh<=0.975000","Zh<=1.000000","Zh<=1.025000","Zh<=1.050000","Zh<=1.075000","Zh<=1.100000","Zh<=1.125000","Zh<=1.150000","Zh<=1.175000","Zh<=1.200000","Zh<=1.225000","Zh<=1.250000"};

TCut cuts_Q2_b_mc[3] = {"1.0<=mc_Q2","1.3<mc_Q2", "1.8<mc_Q2"};
TCut cuts_Q2_t_mc[3] = {"mc_Q2<=1.3","mc_Q2<=1.8","mc_Q2<=4.10"};

TCut cuts_Nu_b_mc[3] = {"2.20<=mc_Nu","3.20<mc_Nu", "3.7<mc_Nu"};
TCut cuts_Nu_t_mc[3] = {"mc_Nu<=3.20","mc_Nu<=3.7","mc_Nu<=4.2"};

TCut cuts_Zh_b_mc[50] = {"0.000000<=mc_Zh","0.025000<mc_Zh","0.050000<mc_Zh","0.075000<mc_Zh","0.100000<mc_Zh","0.125000<mc_Zh","0.150000<mc_Zh","0.175000<mc_Zh","0.200000<mc_Zh","0.225000<mc_Zh","0.250000<mc_Zh","0.275000<mc_Zh","0.300000<mc_Zh","0.325000<mc_Zh","0.350000<mc_Zh","0.375000<mc_Zh","0.400000<mc_Zh","0.425000<mc_Zh","0.450000<mc_Zh","0.475000<mc_Zh","0.500000<mc_Zh","0.525000<mc_Zh","0.550000<mc_Zh","0.575000<mc_Zh","0.600000<mc_Zh","0.625000<mc_Zh","0.650000<mc_Zh","0.675000<mc_Zh","0.700000<mc_Zh","0.725000<mc_Zh","0.750000<mc_Zh","0.775000<mc_Zh","0.800000<mc_Zh","0.825000<mc_Zh","0.850000<mc_Zh","0.875000<mc_Zh","0.900000<mc_Zh","0.925000<mc_Zh","0.950000<mc_Zh","0.975000<mc_Zh","1.000000<mc_Zh","1.025000<mc_Zh","1.050000<mc_Zh","1.075000<mc_Zh","1.100000<mc_Zh","1.125000<mc_Zh","1.150000<mc_Zh","1.175000<mc_Zh","1.200000<mc_Zh","1.225000<mc_Zh"};
 
TCut cuts_Zh_t_mc[50] = {"mc_Zh<=0.025000","mc_Zh<=0.050000","mc_Zh<=0.075000","mc_Zh<=0.100000","mc_Zh<=0.125000","mc_Zh<=0.150000","mc_Zh<=0.175000","mc_Zh<=0.200000","mc_Zh<=0.225000","mc_Zh<=0.250000","mc_Zh<=0.275000","mc_Zh<=0.300000","mc_Zh<=0.325000","mc_Zh<=0.350000","mc_Zh<=0.375000","mc_Zh<=0.400000","mc_Zh<=0.425000","mc_Zh<=0.450000","mc_Zh<=0.475000","mc_Zh<=0.500000","mc_Zh<=0.525000","mc_Zh<=0.550000","mc_Zh<=0.575000","mc_Zh<=0.600000","mc_Zh<=0.625000","mc_Zh<=0.650000","mc_Zh<=0.675000","mc_Zh<=0.700000","mc_Zh<=0.725000","mc_Zh<=0.750000","mc_Zh<=0.775000","mc_Zh<=0.800000","mc_Zh<=0.825000","mc_Zh<=0.850000","mc_Zh<=0.875000","mc_Zh<=0.900000","mc_Zh<=0.925000","mc_Zh<=0.950000","mc_Zh<=0.975000","mc_Zh<=1.000000","mc_Zh<=1.025000","mc_Zh<=1.050000","mc_Zh<=1.075000","mc_Zh<=1.100000","mc_Zh<=1.125000","mc_Zh<=1.150000","mc_Zh<=1.175000","mc_Zh<=1.200000","mc_Zh<=1.225000","mc_Zh<=1.250000"};


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
TFile *f1 = TFile::Open(infile); /* Open file where the tree is located */
TTree* ntuple_sim = (TTree*) f1->Get("ntuple_sim"); /* Read tree */
 
TString tree_name = "Tree_" + targ +"_"+ run +"_"+TString(Form("%i",a))+TString(Form("%i",b));
TString outf_name =tree_name+".root";
TFile *outf = new TFile(outf_name,"RECREATE"); /* Save output plots in a root file */

 TH1F *Zh_Gen = new TH1F("Zh_Gen","Zh_Gen",50,0.0,1.25);
 TH1F *Zh_Rec = new TH1F("Zh_Rec","Zh_Rec",50,0.0,1.25);

 TTree *RG_Tree = new TTree(tree_name,"Rec and Gen entries");

 Double_t Rec;
 Double_t Gen;

 TString branch_R = "Rec_"+TString(Form("%i",a))+TString(Form("%i",b));
 TString branch_G = "Gen_"+TString(Form("%i",a))+TString(Form("%i",b));

 TString type_R = branch_R+"/D";
 TString type_G = branch_G+"/D";


 RG_Tree->Branch(branch_R,&Rec,type_R);
 RG_Tree->Branch(branch_G,&Gen,type_G);

 
 for(int k=1; k<=50; k++){
   ntuple_sim->Draw("Zh>>Zh_Rec",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7&&cut8&&cuts_Q2_b[a-1]&&cuts_Q2_t[a-1]&&cuts_Nu_b[b-1]&&cuts_Nu_t[b-1]&&cuts_Zh_b[k-1]&&cuts_Zh_t[k-1]);
      
   ntuple_sim->Draw("mc_Zh>>Zh_Gen",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc&&cut8_mc&&cuts_Q2_b_mc[a-1]&&cuts_Q2_t_mc[a-1]&&cuts_Nu_b_mc[b-1]&&cuts_Nu_t_mc[b-1]&&cuts_Zh_b_mc[k-1]&&cuts_Zh_t_mc[k-1]);

   Rec=(Zh_Rec->GetEntries());
   Gen=(Zh_Gen->GetEntries());
      
   Zh_Gen->Reset();
   Zh_Rec->Reset();
   RG_Tree->Fill();
 };
 
 /* Export plots */
 outf->Write();
 outf->Close(); /* (i) root plot_out.root; (ii) new TBrowser */ 
}

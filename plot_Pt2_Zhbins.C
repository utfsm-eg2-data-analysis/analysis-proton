void plot_Pt2_Zhbins(TString tar,Int_t r,Int_t a){

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
  TCut cuts_Zh_b[9] = {"0.300000<=Zh","0.400000<Zh","0.500000<Zh","0.600000<Zh","0.700000<Zh","0.800000<Zh","0.900000<Zh","1.000000<Zh","1.100000<Zh"};
  TCut cuts_Zh_t[9] = {"Zh<=0.400000","Zh<=0.500000","Zh<=0.600000","Zh<=0.700000","Zh<=0.800000","Zh<=0.900000","Zh<=1.000000","Zh<=1.100000","Zh<=1.200000"};

  TCut cuts_Pt2_b[30] = {"0.000000<=Pt2","0.066667<=Pt2","0.133334<=Pt2","0.200001<=Pt2","0.266668<=Pt2","0.333335<=Pt2","0.400002<=Pt2","0.466669<=Pt2","0.533336<=Pt2","0.600003<=Pt2","0.666670<=Pt2","0.733337<=Pt2","0.800004<=Pt2","0.866671<=Pt2","0.933338<=Pt2","1.000005<=Pt2","1.066672<=Pt2","1.133339<=Pt2","1.200006<=Pt2","1.266673<=Pt2","1.333340<=Pt2","1.400007<=Pt2","1.466674<=Pt2","1.533341<=Pt2","1.600008<=Pt2","1.666675<=Pt2","1.733342<=Pt2","1.800009<=Pt2","1.866676<=Pt2","1.933343<=Pt2"};

  TCut cuts_Pt2_t[30] = {"Pt2<=0.066667","Pt2<=0.133334","Pt2<=0.200001","Pt2<=0.266668","Pt2<=0.333335","Pt2<=0.400002","Pt2<=0.466669","Pt2<=0.533336","Pt2<=0.600003","Pt2<=0.666670","Pt2<=0.733337","Pt2<=0.800004","Pt2<=0.866671","Pt2<=0.933338","Pt2<=1.000005","Pt2<=1.066672","Pt2<=1.133339","Pt2<=1.200006","Pt2<=1.266673","Pt2<=1.333340","Pt2<=1.400007","Pt2<=1.466674","Pt2<=1.533341","Pt2<=1.600008","Pt2<=1.666675","Pt2<=1.733342","Pt2<=1.800009","Pt2<=1.866676","Pt2<=1.933343","Pt2<=2.000010"};

TCut cuts_Zh_b_mc[9] = {"0.300000<=mc_Zh","0.400000<mc_Zh","0.500000<mc_Zh","0.600000<mc_Zh","0.700000<mc_Zh","0.800000<mc_Zh","0.900000<mc_Zh","1.000000<mc_Zh","1.100000<mc_Zh"};
TCut cuts_Zh_t_mc[9] = {"mc_Zh<=0.400000","mc_Zh<=0.500000","mc_Zh<=0.600000","mc_Zh<=0.700000","mc_Zh<=0.800000","mc_Zh<=0.900000","mc_Zh<=1.000000","mc_Zh<=1.100000","mc_Zh<=1.200000"};

TCut cuts_Pt2_b_mc[30] = {"0.000000<=mc_Pt2","0.066667<=mc_Pt2","0.133334<=mc_Pt2","0.200001<=mc_Pt2","0.266668<=mc_Pt2","0.333335<=mc_Pt2","0.400002<=mc_Pt2","0.466669<=mc_Pt2","0.533336<=mc_Pt2","0.600003<=mc_Pt2","0.666670<=mc_Pt2","0.733337<=mc_Pt2","0.800004<=mc_Pt2","0.866671<=mc_Pt2","0.933338<=mc_Pt2","1.000005<=mc_Pt2","1.066672<=mc_Pt2","1.133339<=mc_Pt2","1.200006<=mc_Pt2","1.266673<=mc_Pt2","1.333340<=mc_Pt2","1.400007<=mc_Pt2","1.466674<=mc_Pt2","1.533341<=mc_Pt2","1.600008<=mc_Pt2","1.666675<=mc_Pt2","1.733342<=mc_Pt2","1.800009<=mc_Pt2","1.866676<=mc_Pt2","1.933343<=mc_Pt2"};
 
TCut cuts_Pt2_t_mc[30] = {"mc_Pt2<=0.066667","mc_Pt2<=0.133334","mc_Pt2<=0.200001","mc_Pt2<=0.266668","mc_Pt2<=0.333335","mc_Pt2<=0.400002","mc_Pt2<=0.466669","mc_Pt2<=0.533336","mc_Pt2<=0.600003","mc_Pt2<=0.666670","mc_Pt2<=0.733337","mc_Pt2<=0.800004","mc_Pt2<=0.866671","mc_Pt2<=0.933338","mc_Pt2<=1.000005","mc_Pt2<=1.066672","mc_Pt2<=1.133339","mc_Pt2<=1.200006","mc_Pt2<=1.266673","mc_Pt2<=1.333340","mc_Pt2<=1.400007","mc_Pt2<=1.466674","mc_Pt2<=1.533341","mc_Pt2<=1.600008","mc_Pt2<=1.666675","mc_Pt2<=1.733342","mc_Pt2<=1.800009","mc_Pt2<=1.866676","mc_Pt2<=1.933343","mc_Pt2<=2.000010"};


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
 
TString tree_name = "Tree_Pt2Zh_"+ targ +"_"+ run +"_"+TString(Form("%i",a));
TString outf_name =tree_name+".root";
TFile *outf = new TFile(outf_name,"RECREATE"); /* Save output plots in a root file */

 TH1F *Pt2_Gen = new TH1F("Pt2_Gen","Pt2_Gen",30,0.0,2.0);
 TH1F *Pt2_Rec = new TH1F("Pt2_Rec","Pt2_Rec",30,0.0,2.0);

 TTree *RG_Tree = new TTree(tree_name,"Rec and Gen entries");

 Double_t Rec;
 Double_t Gen;

 TString branch_R = "Rec_"+TString(Form("%i",a));
 TString branch_G = "Gen_"+TString(Form("%i",a));

 TString type_R = branch_R+"/D";
 TString type_G = branch_G+"/D";


 RG_Tree->Branch(branch_R,&Rec,type_R);
 RG_Tree->Branch(branch_G,&Gen,type_G);

 
 for(int k=1; k<=30; k++){
   ntuple_sim->Draw("Pt2>>Pt2_Rec",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7&&cut8&&cuts_Zh_b[a-1]&&cuts_Zh_t[a-1]&&cuts_Pt2_b[k-1]&&cuts_Pt2_t[k-1]);
      
   ntuple_sim->Draw("mc_Pt2>>Pt2_Gen",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc&&cut8_mc&&cuts_Zh_b_mc[a-1]&&cuts_Zh_t_mc[a-1]&&cuts_Pt2_b_mc[k-1]&&cuts_Pt2_t_mc[k-1]);

   Rec=(Pt2_Rec->GetEntries());
   Gen=(Pt2_Gen->GetEntries());
      
   Pt2_Gen->Reset();
   Pt2_Rec->Reset();
   RG_Tree->Fill();
 };
 
 /* Export plots */
 outf->Write();
 outf->Close(); /* (i) root plot_out.root; (ii) new TBrowser */ 
}

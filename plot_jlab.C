/* USE THIS SCRIPT CREATE THE HISTOGRAMS FROM THE TREES STORED AT THE JLAB CLUSTER  */

/* The output root file that we obtain from here is what we import to our personal computer */

/* root -l -q plot.C */

void plot_jlab(){
  /* Constructors */
  TFile *f1 = TFile::Open("/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/Pb/prunedPb_merged.root"); /* Open file where the tree is located */
  TTree* ntuple_sim = (TTree*) f1->Get("ntuple_sim"); /* Read tree */
  //TH1F *Gen = new TH1F("Gen","P vs Count (Q2>1, W>2, Beta)"); /*Create histograms */
  //TH1F *Rec = new TH1F("Rec","P vs Count (Q2>1, W>2, Beta)");
  TFile *outf = new TFile("all_100bins_Pb.root","RECREATE"); /* Save output plots in a root file */

  //Cuts
  TCut cut1 = "P>0.5";
  TCut cut2 = "P<3";
  TCut cut3 = "pid==2212";
  TCut cut4 = "Q2>1";
  TCut cut5 = "W>2";
  TCut cut6 = "Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))<(-0.00218+3*0.01002)";
  TCut cut7 = "Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))>(-0.00218-3*0.01002)";
  TCut cut1_mc = "mc_P>0.5";
  TCut cut2_mc = "mc_P<3";
  TCut cut3_mc = "mc_pid==2212";
  TCut cut4_mc = "mc_Q2>1";
  TCut cut5_mc = "mc_W>2";
  TCut cut6_mc = "mc_Betta-(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz))/(TMath::Sqrt(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)*TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)+0.938272*0.938272))<(-0.00218+3*0.01002)";
  TCut cut7_mc = "mc_Betta-(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz))/(TMath::Sqrt(TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)*TMath::Sqrt(mc_Px*mc_Px+mc_Py*mc_Py+mc_Pz*mc_Pz)+0.938272*0.938272))>(-0.00218-3*0.01002)";
 
  /* Draw Tree histograms with cuts */
  ntuple_sim->Draw("mc_P>>P_Gen(100,0,5)",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc);

  ntuple_sim->Draw("P>>P_Rec(100,0,5)",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7);

  ntuple_sim->Draw("mc_Zh>>Zh_Gen(100,0,1.5)",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc);

  ntuple_sim->Draw("Zh>>Zh_Rec(100,0,1.5)",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7);

  ntuple_sim->Draw("mc_Q2>>Q2_Gen(100,0,5)",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc);

  ntuple_sim->Draw("Q2>>Q2_Rec(100,0,5)",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7);

  ntuple_sim->Draw("mc_W>>W_Gen(100,1.5,3.5)",cut1_mc&&cut2_mc&&cut3_mc&&cut4_mc&&cut5_mc&&cut6_mc&&cut7_mc);

  ntuple_sim->Draw("W>>W_Rec(100,1.5,3.5)",cut1&&cut2&&cut3&&cut4&&cut5&&cut6&&cut7);
 
  /* Export plots */
  outf->Write();
  outf->Close(); /* (i) root plot_out.root; (ii) new TBrowser */ 
}

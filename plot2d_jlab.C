void plot2d_jlab(){
  TFile *f1 = TFile::Open("/lustre19/expphy/volatile/clas/claseg2/jpgarces/GST_out/Pb/prunedPb_merged.root"); /* Open file where the tree is located */
  TTree* ntuple_sim = (TTree*) f1->Get("ntuple_sim"); /* Read tree */
  TFile *outf = new TFile("PvsPhi_Pb.root","RECREATE"); /* Save output plots in a root file */

  ntuple_sim->Draw("P:PhiLab>>Rec(1500,-30,330,1500,0,3.5)","P>0.5&&P<3&&pid==2212&&Q2>1&&W>2&&Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))<(-0.00218+3*0.01002)&&Betta-(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz))/(TMath::Sqrt(TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)*TMath::Sqrt(Px*Px+Py*Py+Pz*Pz)+0.938272*0.938272))>(-0.00218-3*0.01002)");
  /* Export plots */
  outf->Write();
  outf->Close(); /* (i) root plot_out.root; (ii) new TBrowser */ 
}

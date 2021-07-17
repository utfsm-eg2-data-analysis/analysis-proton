#include <iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TStyle.h"

using namespace std;

void plot_analysis_bins_werrors_Pt2Zh(/*TString tar,Int_t a, Int_t b*/){

  /*TString targ;
  
if(tar=='F'){
  targ = "Fe";
}else if(tar=='P'){
  targ = "Pb";
}else{
  targ = tar;
  };*/
  
/* Constructors */
TLine *l = new TLine(0.0,1.0,2.0,1.0);
//ADD THE OTHER LINES!!
TLegend *legend = new TLegend(0.65,0.7,0.85,0.85);
TCanvas *c1 = new TCanvas();
c1->Divide(3,3);

legend->SetBorderSize(0); /* No box around legends */

/* Extract info from Tree and plot */


//Double_t acc;

TString targets[4]={"D","C","Fe","Pb"};
TString targ;
Int_t colors[4]={206,214,209,94};
Int_t markers[4]={20,21,22,23};

l->SetLineStyle(2);
l->SetLineWidth(2);
l->SetLineColor(colors[0]);

 
Int_t n=1;
 
for(int i=1; i<=9; i++){
    for(int k=1;k<4;k++){
       targ=targets[k];
       TString hist_file_name = "/home/juan/analysis-proton/Histograms/acc_ratio_hists_Pt2Zh_"+targ;
       TString outf_name = hist_file_name+".root";
       TFile *outf = TFile::Open(outf_name);
       TString hist_name = "hist_acc_ratio_"+TString(Form("%i",i));
       TH1F *hist = (TH1F*) outf->Get(hist_name);
     /* Plot in one of the 9 panels */
     c1->cd(n);
     hist->SetMarkerStyle(markers[k]);
     hist->GetXaxis()->SetTitle("Pt2");
     hist->GetYaxis()->SetTitle("Acceptance Ratio");
     hist->GetYaxis()->SetMaxDigits(3); //Number of digits before 10^()
     hist->GetXaxis()->SetMaxDigits(3);
     hist->GetXaxis()->SetRangeUser(0.0,2.0);
     hist->GetYaxis()->SetRangeUser(0.3,1.8);
     hist->GetXaxis()->CenterTitle(kTRUE);
     hist->GetYaxis()->CenterTitle(kTRUE);
     hist->SetTitle("");
     hist->GetXaxis()->SetTitleSize(0.06);
     hist->GetYaxis()->SetTitleSize(0.06);
     hist->GetXaxis()->SetLabelSize(0.04);
     hist->GetYaxis()->SetLabelSize(0.04);
     hist->GetXaxis()->SetNdivisions(20);
     hist->SetMarkerColor(colors[k]);
     if(n==1){
      legend->AddEntry(hist,targ);
     };
     if(k==1){
       hist->Draw("PE1");
     }else{
       hist->Draw("SAME");
     };
     };
     //outf->Close();
    l->Draw("SAME");
    if(n==1){
       legend->Draw("SAME");
     };  
    n+=1;
 };




 
/*Double_t A_array[50]={};
     TString branch = "acc_"+TString(Form("%i",a))+TString(Form("%i",b));
     A_Tree->SetBranchAddress(branch,&acc);
     Int_t entries = (Int_t) A_Tree->GetEntries();
     for(int k=0; k<entries; k++){
       A_Tree->GetEntry(k);
       if(!(isnan(acc))){
	 A_array[k]=acc;
	 printf("%f\n",A_array[k]);
       }else{
       A_array[k]=0.0;
       printf("%f\n",A_array[k]);};
     };
     TGraph* g = new TGraph(50,Zh_Xaxis,A_array);
     g->SetMarkerStyle(21);
     g->GetXaxis()->SetTitle("Zh");
     g->GetYaxis()->SetTitle("Acceptance");
     g->GetYaxis()->SetMaxDigits(3); //Number of digits before 10^()
     g->GetXaxis()->SetMaxDigits(3);
     g->GetXaxis()->SetLimits(0.0,1.30);
     g->GetYaxis()->SetLimits(0.0,1.0);
     g->GetXaxis()->CenterTitle(kTRUE);
     g->GetYaxis()->CenterTitle(kTRUE);
     g->SetTitle("");
     g->GetXaxis()->SetTitleSize(0.06);
     g->GetYaxis()->SetTitleSize(0.06);
     g->GetXaxis()->SetLabelSize(0.04);
     g->GetYaxis()->SetLabelSize(0.04);
     g->GetXaxis()->SetNdivisions(20);
     g->Draw("AP");
     l->Draw("SAME");
     legend->AddEntry(g,"Deuterium");
     legend->Draw("SAME");*/



/* Export plots */
/*c1->Print("PvsCount_D.pdf");*/   /* for a paper plot use .tex */
}

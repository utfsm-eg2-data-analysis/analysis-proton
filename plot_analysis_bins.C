#include <iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TStyle.h"

using namespace std;

void plot_analysis_bins(/*TString tar,Int_t a, Int_t b*/){

  /*TString targ;
  
if(tar=='F'){
  targ = "Fe";
}else if(tar=='P'){
  targ = "Pb";
}else{
  targ = tar;
  };*/
  
/* Constructors */
TLine *l_D = new TLine(0.0,0.1911,1.3,0.1911);
TLine *l_C = new TLine(0.0,0.1923,1.3,0.1923);
TLine *l_Fe = new TLine(0.0,0.1897,1.3,0.1897);
TLine *l_Pb = new TLine(0.0,0.1891,1.3,0.1891);
//ADD THE OTHER LINES!!
TLegend *legend = new TLegend(0.65,0.7,0.85,0.85);
TCanvas *c1 = new TCanvas();
c1->Divide(3,3);

/* Zh values (X axis) */
Double_t Zh_bins[51] = {0.000000,0.025000,0.050000,0.075000,0.100000,0.125000,0.150000,0.175000,0.200000,0.225000,0.250000,0.275000,0.300000,0.325000,0.350000,0.375000,0.400000,0.425000,0.450000,0.475000,0.500000,0.525000,0.550000,0.575000,0.600000,0.625000,0.650000,0.675000,0.700000,0.725000,0.750000,0.775000,0.800000,0.825000,0.850000,0.875000,0.900000,0.925000,0.950000,0.975000,1.000000,1.025000,1.050000,1.075000,1.100000,1.125000,1.150000,1.175000,1.200000,1.225000,1.250000};

Double_t Zh_Xaxis[50]={};

for(int i=0; i<50; i++){
  Zh_Xaxis[i]=(Zh_bins[i+1]+Zh_bins[i])/2.0;
 };

legend->SetBorderSize(0); /* No box around legends */

/* Extract info from Tree and plot */

Double_t acc_11,acc_12,acc_13,acc_21,acc_22,acc_23,acc_31,acc_32,acc_33;

Double_t* acc[3][3]={{&acc_11,&acc_12,&acc_13},{&acc_21,&acc_22,&acc_23},{&acc_31,&acc_32,&acc_33}};

//Double_t acc;

TString targets[4]={"D","C","Fe","Pb"};
TString targ;
Int_t colors[4]={206,214,209,94};
Int_t markers[4]={20,21,22,23};

l_D->SetLineStyle(2);
l_D->SetLineWidth(2);
l_D->SetLineColor(colors[0]);
l_C->SetLineStyle(2);
l_C->SetLineWidth(2);
l_C->SetLineColor(colors[1]);
l_Fe->SetLineStyle(2);
l_Fe->SetLineWidth(2);
l_Fe->SetLineColor(colors[2]);
l_Pb->SetLineStyle(2);
l_Pb->SetLineWidth(2);
l_Pb->SetLineColor(colors[3]);

 
Int_t n=1;
 
for(int i=1; i<=3; i++){
  for(int j=1; j<=3; j++){
    TGraph *g[4];
    TMultiGraph *mg = new TMultiGraph();
    for(int k=0;k<4;k++){
       targ=targets[k];
       TString tree_name = "A_Tree_"+targ;
       TString outf_name = tree_name+".root";
       TFile *outf = TFile::Open(outf_name);
       TTree *A_Tree = (TTree*) outf->Get(tree_name);
        /* Obtain array spanning the 50 Zh bins for one of the 9 Q2xNu bins (excluding NaN values)  */
       Double_t A_array[50]={};
       TString branch = "acc_"+TString(Form("%i",i))+TString(Form("%i",j));
       A_Tree->SetBranchAddress(branch,acc[i-1][j-1]);
       Int_t entries = (Int_t) A_Tree->GetEntries();
       for(int l=0; l<entries; l++){
         A_Tree->GetEntry(l);
         if(!(isnan(*(acc[i-1][j-1])))){
	   A_array[l]=*(acc[i-1][j-1]);
	   printf("%f\n",A_array[l]);
         }else{
         A_array[l]=0.0;
         printf("%f\n",A_array[l]);
	 };
       };
     /* Plot in one of the 9 panels */
     c1->cd(n);
     g[k]= new TGraph(50,Zh_Xaxis,A_array);
     //TGraph* g = new TGraph(50,Zh_Xaxis,A_array);
     g[k]->SetMarkerStyle(markers[k]);
     g[k]->GetXaxis()->SetTitle("Zh");
     g[k]->GetYaxis()->SetTitle("Acceptance");
     g[k]->GetYaxis()->SetMaxDigits(3); //Number of digits before 10^()
     g[k]->GetXaxis()->SetMaxDigits(3);
     g[k]->GetXaxis()->SetLimits(0.0,1.30);
     g[k]->GetYaxis()->SetLimits(0.0,1.0);
     g[k]->GetXaxis()->CenterTitle(kTRUE);
     g[k]->GetYaxis()->CenterTitle(kTRUE);
     g[k]->SetTitle("");
     g[k]->GetXaxis()->SetTitleSize(0.06);
     g[k]->GetYaxis()->SetTitleSize(0.06);
     g[k]->GetXaxis()->SetLabelSize(0.04);
     g[k]->GetYaxis()->SetLabelSize(0.04);
     g[k]->GetXaxis()->SetNdivisions(20);
     g[k]->SetMarkerColor(colors[k]);
     if(n==1){
      legend->AddEntry(g[k],targ);
     };
     //g[k]->Draw("AP");
     outf->Close();
     mg->Add(g[k]);
    };
    
    //TString title = TString(Form("%i",i))+TString(Form("%i",j));
     //mg->GetXaxis()->SetTitle(title);
     mg->GetXaxis()->SetTitle("Zh");
     mg->GetYaxis()->SetTitle("Acceptance");
     mg->GetYaxis()->SetMaxDigits(3); //Number of digits before 10^()
     mg->GetXaxis()->SetMaxDigits(3);
     mg->GetXaxis()->SetLimits(0.0,1.30);
     mg->GetYaxis()->SetLimits(0.0,1.0);
     mg->GetXaxis()->CenterTitle(kTRUE);
     mg->GetYaxis()->CenterTitle(kTRUE);
     mg->SetTitle("");
     mg->GetXaxis()->SetTitleSize(0.06);
     mg->GetYaxis()->SetTitleSize(0.06);
     mg->GetXaxis()->SetLabelSize(0.04);
     mg->GetYaxis()->SetLabelSize(0.04);
     mg->GetXaxis()->SetNdivisions(20);
    mg->Draw("AP");
    l_D->Draw("SAME");
    l_C->Draw("SAME");
    l_Fe->Draw("SAME");
    l_Pb->Draw("SAME");
    if(n==1){
       legend->Draw("SAME");
     };  
    n+=1;
  };
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

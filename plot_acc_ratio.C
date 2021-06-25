void plot_acc_ratio(){

/* Constructors */
TLine *l = new TLine(0.15,1.0,1.3,1.0);
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

Double_t n_acc_11,n_acc_12,n_acc_13,n_acc_21,n_acc_22,n_acc_23,n_acc_31,n_acc_32,n_acc_33;

Double_t* n_acc[3][3]={{&n_acc_11,&n_acc_12,&n_acc_13},{&n_acc_21,&n_acc_22,&n_acc_23},{&n_acc_31,&n_acc_32,&n_acc_33}};

//Double_t acc;

TString targets[3]={"C","Fe","Pb"};
TString targ;
Int_t colors[4]={206,214,209,94};
Int_t markers[4]={20,21,22,23};

l->SetLineStyle(2);
l->SetLineWidth(2);
l->SetLineColor(colors[3]);

TFile *outf = TFile::Open("A_Tree.root");
TTree *A_Tree_C_N = (TTree*) outf->Get("A_Tree_C_N");
TTree *A_Tree_Fe_N = (TTree*) outf->Get("A_Tree_Fe_N");
TTree *A_Tree_Pb_N = (TTree*) outf->Get("A_Tree_Pb_N");

TTree* Trees[3]={A_Tree_C_N,A_Tree_Fe_N,A_Tree_Pb_N};
 
Int_t n=1;
 
for(int i=1; i<=3; i++){
  for(int j=1; j<=3; j++){
    TGraph *g[3];
    TMultiGraph *mg = new TMultiGraph();
    for(int k=0;k<3;k++){
       targ=targets[k];
        /* Obtain array spanning the 50 Zh bins for one of the 9 Q2xNu bins (excluding NaN values)  */
       Double_t A_array[50]={};
       TString branch = "n_acc_"+TString(Form("%i",i))+TString(Form("%i",j));
       Trees[k]->SetBranchAddress(branch,n_acc[i-1][j-1]);
       Int_t entries = (Int_t) Trees[k]->GetEntries();
       for(int l=0; l<entries; l++){
         Trees[k]->GetEntry(l);
         if(!(isnan(*(n_acc[i-1][j-1])))){
	   A_array[l]=*(n_acc[i-1][j-1]);
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
     //g[k]->GetXaxis()->SetLimits(0.0,1.30);
     //g[k]->GetYaxis()->SetLimits(0.75,1.5);
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
     mg->Add(g[k]);
    };
    
    //TString title = TString(Form("%i",i))+TString(Form("%i",j));
     //mg->GetXaxis()->SetTitle(title);
     mg->GetXaxis()->SetTitle("Zh");
     mg->GetYaxis()->SetTitle("Acceptance");
     mg->GetYaxis()->SetMaxDigits(3); //Number of digits before 10^()
     mg->GetXaxis()->SetMaxDigits(3);
     //mg->GetXaxis()->SetLimits(0.0,1.30);
     //mg->GetYaxis()->SetLimits(0.75,1.5);
     mg->GetXaxis()->SetRangeUser(0.15,1.30);
     mg->GetYaxis()->SetRangeUser(0.75,1.3);
     mg->GetXaxis()->CenterTitle(kTRUE);
     mg->GetYaxis()->CenterTitle(kTRUE);
     mg->SetTitle("");
     mg->GetXaxis()->SetTitleSize(0.06);
     mg->GetYaxis()->SetTitleSize(0.06);
     mg->GetXaxis()->SetLabelSize(0.04);
     mg->GetYaxis()->SetLabelSize(0.04);
     mg->GetXaxis()->SetNdivisions(240);
    mg->Draw("AP");
    l->Draw("SAME");
    if(n==1){
       legend->Draw("SAME");
     };  
    n+=1;
  };
};
 outf->Close();
}

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
//#include "TEvent.h"
#include "TTree.h"
#include "TChain.h"
#include "math.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
using namespace std;

double factorial(int number) {

  if (number==0) return 1;

  int n;
  double factorial=number;
  for (n=number;n>1;n--) {
      factorial*=(n-1);
  }

  return factorial;

}

int main() {

  ofstream outfile("data.dat",ios::app);

  double thres[2];//E0&E1 threshold
  thres[0] = 3.0;//MeV
  thres[1] = 1.0;//MeV
/*
  struct Data_Event {
    Float_t E_tot;
    Float_t E_det[10];
    Int_t E_detnum[10];
    Int_t Mult;
  };
*/

  struct Data_Event {
    Float_t sum;
    Float_t esort[10];
    Float_t ecal[30];
    Int_t Mult;
  };

  struct Data_Run {
    Int_t Event;
    Int_t Run;
    Float_t cascade[5];
  };

  Data_Event data_event;
  Data_Run data_run;

  TH2F *h_E0E1_exp = new TH2F("E0E1 exp","E0E1 exp", 10, 0, 10,10,0,10);

  h_E0E1_exp->Fill(5.7942141,2.1531647,1);
  h_E0E1_exp->Fill(5.5396409,1.4210408,1);
  h_E0E1_exp->Fill(6.8509925,2.1205009,1);
  h_E0E1_exp->Fill(3.0427775,0.6034525,1);
  h_E0E1_exp->Fill(4.6204313,0.3339239,1);
  h_E0E1_exp->Fill(7.3000341,0.7483313,1);
  h_E0E1_exp->Fill(6.1844674,0.3451892,1);
  h_E0E1_exp->Fill(3.4176843,1.6911579,1);
  h_E0E1_exp->Fill(6.3260899,0.5141713,1);
  h_E0E1_exp->Fill(6.3805602,-1,1);
  h_E0E1_exp->Fill(3.6515984,2.5219102,1);
  h_E0E1_exp->Fill(4.8401079,0.5048672,1);
  h_E0E1_exp->Fill(5.2212572,1.3441240,1);
  h_E0E1_exp->Fill(5.1492975,0.9415238,1);
  h_E0E1_exp->Fill(3.4521879,2.1534214,1);
  h_E0E1_exp->Fill(4.7668824,1.5463524,1);
  h_E0E1_exp->Fill(4.009594,0.4923208,1);
  h_E0E1_exp->Fill(6.4873496,-1,1);
  h_E0E1_exp->Fill(6.9765568,0.7583379,1);
  h_E0E1_exp->Fill(4.3125047,2.3427824,1);
  h_E0E1_exp->Fill(6.1188627,0.6993079,1);
  h_E0E1_exp->Fill(5.4033807,1.6400611,1);
  h_E0E1_exp->Fill(5.5635054,1.0026431,1);
  h_E0E1_exp->Fill(5.4140218,0.2617883,1);
  h_E0E1_exp->Fill(3.3781208,3.0020874,1);

  int low, high;

  std::cout << "enter low & high run numbers:" << std::endl;
//2754
  std::cin >> low >> high;
  std::cout << std::endl;

  for (int j=low; j<=high; j++) {//loops through low to high run numbers/files

    if (j==1015) continue;

    TH2F *h_E0E1_sim = new TH2F("E0E1 sim","E0E1 sim",10,0,10,10,0,10);

    char FileName[30];
    sprintf(FileName,"$(pwd)/38K/Run_%i.root",j);

    TChain *c_event = new TChain("Event");
    c_event->AddFile(FileName);
    c_event->SetBranchAddress("Events",&data_event);

    TChain *c_run = new TChain("Run");
    c_run->AddFile(FileName);
    c_run->SetBranchAddress("Run",&data_run);

    int nentries = (int)c_event->GetEntries();

    int n_gamma = 0;

    c_run->GetEntry(0);

    for (int i=0; i<5; i++) {
      if (data_run.cascade[i]>0.05) {
        n_gamma+=1;
      }
    }

    int effcount=0;

    for (int i=0; i<nentries; i++) {
      c_event->GetEntry(i);
      if (data_event.esort[0]>thres[0]) effcount+=1;
//      if (data_event.E_det[0]>thres[0]) effcount+=1;

      if (data_event.esort[0]>thres[0] || data_event.esort[1]>thres[1]) {
//      if (data_event.E_det[0]>thres[0] || data_event.E_det[1]>thres[1]) {
//        cout << data_event.Mult << endl;
        h_E0E1_sim->Fill(data_event.esort[0],data_event.esort[1],1);
//        h_E0E1_sim->Fill(data_event.E_det[0],data_event.E_det[1],1);
      }

    }

    double eff = double(effcount)/double(nentries);

    c_run->GetEntry(0);

    double lnL = 0;
    double chi2 = 0;

    double norm = h_E0E1_exp->Integral() / h_E0E1_sim->Integral();//normalize sim to exp

/*
    for (int i=1; i<=10; i++) {//calculates liklihood for each bin and sums them
      for (int k=1; k<=10; k++) {//calculates liklihood for each bin and sums them

        double norm = h_multexp->Integral()/h_multnew->Integral();

        double Xi = h_E0E1_exp->GetBinContent(k,i);//exp data
        double Ni = h_E0E1_sim->GetBinContent(k,i)*norm;//sim data

        if (pow(Ni,Xi) * pow(2.71828,Ni*(-1.)) / factorial(int(Xi))<=0) {//exits if liklihood=nan
          lnL = 1000;//==nan
//          k--;
          break;
        }

        double lnL_temp = log( pow(Ni,Xi) * pow(2.71828,Ni*(-1.)) / factorial(int(Xi)) );

        lnL += lnL_temp;

//        std::cout << i << "\t" <<  Ni << "\t" << Xi << "\t" << lnL_temp << std::endl;

      }

      std::cout << j << "\t" << n_gamma << "\t" << eff << "\t" << (-2)*lnL << std::endl;
      outfile   << j << "\t" << n_gamma << "\t" << eff << "\t" << (-2)*lnL << std::endl;
*/


    for (int i=1; i<=10; i++) {//calculates chi2 for each multiplicity bin and sums them
      for (int k=1; k<=10; k++) {//calculates chi2 for each multiplicity bin and sums them

        double Xi = h_E0E1_exp->GetBinContent(k,i);//exp data
        double Ni = h_E0E1_sim->GetBinContent(k,i)*norm;//sim data

        double chi2_temp = pow(Xi-Ni,2)/Xi;
        if (Xi==0) chi2_temp = 1;

        chi2 += chi2_temp;

//        std::cout << k << "\t" << i << "\t" <<  Ni << "\t" << Xi << "\t" << chi2_temp << std::endl;
      }
    }

    std::cout << j << "\t" << n_gamma << "\t" << eff << "\t" << chi2 << std::endl;
    outfile   << j << "\t" << n_gamma << "\t" << eff << "\t" << chi2 << std::endl;

//

    delete c_event;
    delete h_E0E1_sim;

  }

}

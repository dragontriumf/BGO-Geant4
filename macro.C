{

//  string filename = "18F_1.5_4.4.root";

  TFile* file = TFile::Open("19Ne_1.5_5.2.root","UPDATE");

  TFolder* folder = (TFolder*)file->FindObjectAny("singles");

  TH1* IC0 = (TH1*)file->FindObjectAny("IC0");
  TH1* IC1 = (TH1*)file->FindObjectAny("IC1");
  TH1* IC2 = (TH1*)file->FindObjectAny("IC2");
  TH1* IC3 = (TH1*)file->FindObjectAny("IC3");

  IC0->Fit("gaus");
  IC1->Fit("gaus");
  IC2->Fit("gaus");
  IC3->Fit("gaus");

}

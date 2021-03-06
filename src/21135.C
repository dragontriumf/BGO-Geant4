{

  TFile* f1 = TFile::Open("kom21135.root");

  double ictot_min = 770.;
  double ictot_max = 1100.;

  double tof_min = 950.;
  double tof_max = 1200.;
//BGO eff
  TCutG *c_ICvsTOF = new TCutG("c_ICvsTOF",5);
  c_ICvsTOF->SetVarX("IC_0+IC_1");
  c_ICvsTOF->SetVarY("MCP_TOF");
  c_ICvsTOF->SetTitle("Graph");
  c_ICvsTOF->SetFillColor(1);
  c_ICvsTOF->SetPoint(0,700.,tof_min);
  c_ICvsTOF->SetPoint(1,ictot_max,tof_min);
  c_ICvsTOF->SetPoint(2,ictot_max,tof_max);
  c_ICvsTOF->SetPoint(3,ictot_min,tof_max);
  c_ICvsTOF->SetPoint(4,700.,tof_min);

  ictot_min = 400.;
  ictot_max = 1000.;

  tof_min = 950.;
  tof_max = 1250.;
//recoil ROI
  TCutG *c1_ICvsTOF = new TCutG("c1_ICvsTOF",5);
  c1_ICvsTOF->SetVarX("IC_0+IC_1");
  c1_ICvsTOF->SetVarY("MCP_TOF");
  c1_ICvsTOF->SetTitle("Graph");
  c1_ICvsTOF->SetFillColor(1);
  c1_ICvsTOF->SetPoint(0,ictot_min,tof_min);
  c1_ICvsTOF->SetPoint(1,ictot_max,tof_min);
  c1_ICvsTOF->SetPoint(2,ictot_max,tof_max);
  c1_ICvsTOF->SetPoint(3,ictot_min,tof_max);
  c1_ICvsTOF->SetPoint(4,ictot_min,tof_min);

  TCanvas* c0 = new TCanvas("c0", "c0", 750, 540);
  SingleEvents->Draw("MCP_TOF:IC_0+IC_1>>h1","MCP_TOF<2200");
  CoincidenceEvents->Draw("MCP_TOF:IC_0+IC_1>>h2","","SAME*");
//  c_ICvsTOF->Draw();
//  cout << SingleEvents->GetEntries("c_ICvsTOF") << endl;
//  cout << CoincidenceEvents->GetEntries("c_ICvsTOF") << endl;
//  cout << c_ICvsTOF->IntegralHist(h2)/c_ICvsTOF->IntegralHist(h1) << endl;
//  c1_ICvsTOF->Draw();
//  cout << c1_ICvsTOF->IntegralHist(h2) << endl;
  c0->Update();
/*
  TCanvas* c1 = new TCanvas("c1", "c1", 750, 540);
  SingleEvents->Draw("MCP_TOF>>h1","MCP_TOF<2200");
  c1->Update();
*/
/*
  TCanvas* c1 = new TCanvas("c1", "c1", 750, 540);
  SingleEvents->Draw("MCP_TOF","c_ICvsTOF");

  TCanvas* c2 = new TCanvas("c2", "c2", 750, 540);
  CoincidenceEvents->Draw("MCP_TOF","c_ICvsTOF");

  TCanvas* c8 = new TCanvas("c8", "c8", 750, 540);
  SingleEvents->Draw("IC_1:IC_0","c_ICvsTOF");
  CoincidenceEvents->Draw("IC_1:IC_0","c_ICvsTOF","SAME*");
//  CoincidenceEvents->Draw("MCP_TOF");
  c8->Update();
*/

  TCanvas* c9 = new TCanvas("c9", "c9", 750, 540);
  CoincidenceEvents->Draw("IC_1+IC_0","IC_1+IC_0>0");
  c9->Update();

}

{

  TCanvas *c3 = new TCanvas("c3","c3",800, 600);

  ifstream infile("mult.dat");
//  infile.open("data.dat");

  int n_gamma,i[5], filenum;
  double eff, L;

  i[0]=0;
  i[1]=0;
  i[2]=0;
  i[3]=0;
  i[4]=0;

  TMultiGraph *mg = new TMultiGraph();

  TGraph* g1 = new TGraph(); g1->SetMarkerColor(1); g1->SetFillStyle(0); g1->SetLineColor(0); g1->SetMarkerStyle(6); g1->SetTitle("1");
  TGraph* g2 = new TGraph(); g2->SetMarkerColor(2); g2->SetFillStyle(0); g2->SetLineColor(0); g2->SetMarkerStyle(6); g2->SetTitle("2");
  TGraph* g3 = new TGraph(); g3->SetMarkerColor(3); g3->SetFillStyle(0); g3->SetLineColor(0); g3->SetMarkerStyle(6); g3->SetTitle("3");
  TGraph* g4 = new TGraph(); g4->SetMarkerColor(4); g4->SetFillStyle(0); g4->SetLineColor(0); g4->SetMarkerStyle(6); g4->SetTitle("4");
  TGraph* g5 = new TGraph(); g5->SetMarkerColor(7); g5->SetFillStyle(0); g5->SetLineColor(0); g5->SetMarkerStyle(6); g5->SetTitle("5");

  while (!infile.eof()) {

    infile >> filenum; infile >> n_gamma; infile >> eff; infile >> L;

    cout << filenum << "\t" << n_gamma << "\t" << eff << "\t" << L << endl;

    if (n_gamma==1) {g1->SetPoint(i[0],eff,L); i[0]++;}
    if (n_gamma==2) {g2->SetPoint(i[1],eff,L); i[1]++;}
    if (n_gamma==3) {g3->SetPoint(i[2],eff,L); i[2]++;}
    if (n_gamma==4) {g4->SetPoint(i[3],eff,L); i[3]++;}
    if (n_gamma==5) {g5->SetPoint(i[4],eff,L); i[4]++;}

  }

  mg->Add(g1);
  mg->Add(g2);
  mg->Add(g3);
  mg->Add(g4);
  mg->Add(g5);

  mg->Draw("ap");

  c3->BuildLegend();

}


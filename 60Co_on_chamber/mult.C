{

  Event->Draw("Mult>>h(5,0,5)","Mult==1 && esort[0]>0.728");
  cout << "1" << "\t" << h->Integral() << endl;
  Event->Draw("Mult>>h(5,0,5)","Mult==2 && esort[0]>0.728");
  cout << "2" << "\t" << h->Integral() << endl;
  Event->Draw("Mult>>h(5,0,5)","Mult==3 && esort[0]>0.728");
  cout << "3" << "\t" << h->Integral() << endl;
  Event->Draw("Mult>>h(5,0,5)","Mult==4 && esort[0]>0.728");
  cout << "4" << "\t" << h->Integral() << endl;
  Event->Draw("Mult>>h(5,0,5)","Mult==5 && esort[0]>0.728");
  cout << "5" << "\t" << h->Integral() << endl;



  Event->Draw("sum>>h(5,0,5)","esort[0]>0.728");
  cout << "tot events: " << "\t" << h->Integral() << endl;


  Event->Draw("esort[0]>>h(5,0,5)","ecal[0]>0.728");
  cout << "0" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[1]>0.728");
  cout << "1" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[2]>0.728");
  cout << "2" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[3]>0.728");
  cout << "3" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[4]>0.728");
  cout << "4" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[5]>0.728");
  cout << "5" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[6]>0.728");
  cout << "6" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[7]>0.728");
  cout << "7" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[8]>0.728");
  cout << "8" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[9]>0.728");
  cout << "9" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[10]>0.728");
  cout << "10" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[11]>0.728");
  cout << "11" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[12]>0.728");
  cout << "12" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[13]>0.728");
  cout << "13" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[14]>0.728");
  cout << "14" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[15]>0.728");
  cout << "15" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[16]>0.728");
  cout << "16" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[17]>0.728");
  cout << "17" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[18]>0.728");
  cout << "18" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[19]>0.728");
  cout << "19" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[20]>0.728");
  cout << "20" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[21]>0.728");
  cout << "21" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[22]>0.728");
  cout << "22" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[23]>0.728");
  cout << "23" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[24]>0.728");
  cout << "24" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[25]>0.728");
  cout << "25" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[26]>0.728");
  cout << "26" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[27]>0.728");
  cout << "27" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[28]>0.728");
  cout << "28" << "\t" << h->Integral() << endl;
  Event->Draw("esort[0]>>h(5,0,5)","ecal[29]>0.728");
  cout << "29" << "\t" << h->Integral() << endl;

}

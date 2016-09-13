#ifndef CascadeGenerator_h
#define CascadeGenerator_h 1

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <vector>
#include "G4UImanager.hh"
#include "InputManager.hh"

class CascadeGenerator {

  public:

  CascadeGenerator(InputManager* InMgr);
 ~CascadeGenerator();
  void GenerateCascade();
  bool GenerateCascadeCustom();
  std::vector<double> GetCascade();
  void SetCascade();
  bool GetEnd() {return end;};
  void EndOfRun() {N_run++;};
  int GetRun() {return N_run;};
  double GetGammaE();

  private:

  InputManager* InMgr;

  std::vector<double> E_array;//energy array
  std::vector<double> gamma_array;//temp cascade array
  std::vector<double> gammatot_array;//total cascade array
  std::vector<double>::iterator it;
  std::vector<int> point_array;//permitation of cascade

  std::vector<double> cascade;//energy array for specific cascade

  int n_gamma;//no. of gammas
  int n_bin;//no. of energy bins

  int count;//no. of permitation

  int N_run;//run number
  int run_end;//last run number

  double E_x;//energy of excited state
  double dE;

  bool custom;//true when custom cascade used
  bool end;//=true when all cascades simulated

};

#endif

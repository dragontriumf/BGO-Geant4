#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "CascadeGenerator.hh"
#include "DAQManager.hh"

class G4Run;

class RunAction : public G4UserRunAction {

public:
  RunAction(CascadeGenerator* CasGen, DAQManager* DAQMgr);
  virtual ~RunAction();

  void BeginOfRunAction(const G4Run*);
  void EndOfRunAction(const G4Run*);
    
  void fillPerEvent(G4double, G4double, G4double, G4double); 
  void ETotLikelihood();
  void E01Likelihood();
  void MultLikelihood();

private:
  G4double sumEAbs, sum2EAbs;
  G4double sumEGap, sum2EGap;
    
  G4double sumLAbs, sum2LAbs;
  G4double sumLGap, sum2LGap;    

  CascadeGenerator* CasGen;
  DAQManager* DAQMgr;

};

#endif


#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4UnitsTable.hh"
#include "DAQManager.hh"

#include "RunAction.hh"
#include "EventActionMessenger.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>
#include "TH1.h"
#include "TH2.h"
#include <vector>
#include <algorithm>

//class RunAction;
//class EventActionMessenger;

class G4Event;

class EventAction : public G4UserEventAction {

  public:

  EventAction(DAQManager* DAQMgr);
 ~EventAction();

  void BeginOfEventAction(const G4Event*);
  void EndOfEventAction(const G4Event*);                     
//  void SetPrintModulo(G4int val)  {printModulo = val;};

  int GetCoinc() {return coinc;};
  void SetCoinc(int in) {coinc = in;};

  private:

//  RunAction*  runAct;
  G4int     printModulo;
//  EventActionMessenger*  eventMessenger;
  int coinc;//no of coincident events this run

  DAQManager* DAQMgr;

};

#endif

    

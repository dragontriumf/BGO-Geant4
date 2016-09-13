#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "TrackerSD.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "InputManager.hh"
#include "CascadeGenerator.hh"
#include "DAQManager.hh"
#include "TFile.h"

//----- C++ source codes: main() function for visualization
#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main (int argc,char** argv) {     

  if (argc<2) {// argc should be more than 1 for correct execution
    cerr << "Error in <main>: program " << argv[0] << " requires config filename argument" << endl;
    exit(1);
  }

  InputManager* InMgr = new InputManager();

  std::vector<string> filename;
  std::vector<string>::iterator it;

  for (int i=1; i<argc; i++) {
    filename.push_back(argv[i]);//config input filename(s)
  }

  for (it=filename.begin(); it!=filename.end(); it++) {
    InMgr->ReadFile(it->c_str());
  }

  CascadeGenerator* CasGen = new CascadeGenerator(InMgr);
  DAQManager* DAQMgr = new DAQManager(InMgr, CasGen);

//  construct the default run manager
  G4RunManager* runManager = new G4RunManager;

//  Instantiation and initialization of the Visualization Manager
  #ifdef G4VIS_USE
//  visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
  #endif

//  set mandatory initialization classes
  G4VUserDetectorConstruction* detector = new DetectorConstruction(DAQMgr,InMgr);
  runManager->SetUserInitialization(detector);

  runManager->SetUserInitialization(new PhysicsList);
//  runManager->SetUserInitialization(physics);

//  set mandatory user action class

//  initialize G4 kernel
  runManager->Initialize();

  G4VUserPrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction(CasGen);
  runManager->SetUserAction(gen_action);

  G4UserRunAction* run_action = new RunAction(CasGen,DAQMgr);  
  runManager->SetUserAction(run_action);

  G4UserEventAction* event_action = new EventAction(DAQMgr);
  runManager->SetUserAction(event_action);

// Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  #ifdef G4UI_USE
  G4UIExecutive * ui = new G4UIExecutive(argc,argv);
  #ifdef G4VIS_USE

  bool viewer;
  InMgr->GetVariable("viewer",viewer);
  if (viewer == true) UImanager->ApplyCommand("/control/execute vis.mac");   

  char beamOn[30];
  int N_events;
  InMgr->GetVariable("N_events",N_events);
  sprintf(beamOn,"/run/beamOn %i", N_events);

  for (bool end=false; end!=true; end=CasGen->GetEnd()) {
    UImanager->ApplyCommand(beamOn);
  }


  #endif
  ui->SessionStart();
  delete ui;
  #endif

   // Job termination
  #ifdef G4VIS_USE
 //  delete visManager;
  #endif

   // job termination   

  delete DAQMgr;

  delete runManager;

  return 0;
   
}

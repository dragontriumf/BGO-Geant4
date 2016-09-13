#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Paraboloid.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Trd.hh"
#include "G4Polyhedra.hh"
#include "G4NistManager.hh"
#include "G4SDManager.hh"
#include "G4ChordFinder.hh"
#include "G4EllipticalTube.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"
#include "G4VSensitiveDetector.hh"
#include "G4SDManager.hh"
#include "TrackerSD.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UserLimits.hh"
#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"
#include "DAQManager.hh"
#include "InputManager.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4MaterialPropertiesTable.hh"

#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"

class G4Tubs;
class G4Box;
class G4Trd;
class G4Polyhedra;

class DetectorConstruction : public G4VUserDetectorConstruction {

  public:

  DetectorConstruction(DAQManager* DAQMgr, InputManager* InMgr);
 ~DetectorConstruction();

  void Single();

  void ConstructRegular();

  G4VPhysicalVolume* Construct();

  TrackerSD* aTrackerSD;

  private:
    
  G4VPhysicalVolume* ConstructDetector();
  DAQManager* DAQMgr;
  InputManager* InMgr;

  G4LogicalVolume* expHall_log;
  G4Material* target;
  G4Material* BGO;
    
};

#endif


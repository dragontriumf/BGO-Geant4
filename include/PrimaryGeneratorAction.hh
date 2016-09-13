#include "G4ios.hh"
#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "CascadeGenerator.hh"
#include <vector>

class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction(CascadeGenerator* CasGen);
    ~PrimaryGeneratorAction();
 private:

    G4double Ed;
    G4double E0;
    G4int level0;

  public:
    void GeneratePrimaries(G4Event* anEvent);
    void GammaDecay(G4Event* anEvent);
    void IonBeam(G4Event* anEvent);
    void BreitWigner();

  private:
    G4ParticleGun* particleGun;
    CascadeGenerator* CasGen;
    
};

#endif



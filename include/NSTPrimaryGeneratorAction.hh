#ifndef NSTPrimaryGeneratorAction_h
#define NSTPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Box;


class NSTPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    NSTPrimaryGeneratorAction();    
    ~NSTPrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  
  private:
    G4ParticleGun*  fParticleGun {nullptr}; // pointer a to G4 gun class
    G4Box*          fEnvelopeBox {nullptr};
};


#endif

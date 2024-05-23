using namespace std;


#include "NSTPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4Geantino.hh"
#include "G4IonTable.hh"



NSTPrimaryGeneratorAction::NSTPrimaryGeneratorAction()
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName="neutron");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(5*MeV);
}

NSTPrimaryGeneratorAction::~NSTPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void NSTPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  
   
  CLHEP::HepRandom::setTheEngine(new CLHEP::MTwistEngine);
  CLHEP::HepRandom::setTheSeed((unsigned)clock());  
  
  
  G4double x0 = 0;
  G4double y0 = 0;
  G4double z0 = 8*m;
  
  G4int numPhotons = 1;

  G4double phimax = 1.1*CLHEP::pi;
  G4double phimin = 0.9*CLHEP::pi;
  
  G4double phi = phimin + (phimax - phimin) * G4UniformRand();
  
  G4double thetamin = 1.4*CLHEP::pi;
  G4double thetamax = 1.6*CLHEP::pi;
  
  G4double theta2 = thetamax + (thetamin - thetamax) * G4UniformRand();

  G4double py = sin(theta2) * sin(phi);
  G4double px = cos(theta2);
  
  G4double Emax = 10 ;
  G4double Emin = 0 ;
  G4double energy = Emin + (Emax - Emin) * G4UniformRand();
 
  
  //fParticleGun->SetParticleEnergy(energy);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(px,py,-1));
  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  fParticleGun->GeneratePrimaryVertex(anEvent);

  }


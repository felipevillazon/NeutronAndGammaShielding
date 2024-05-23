#ifndef NSTPHYSICS_HH
#define NSTPHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

class NSTPhysicsList : public G4VModularPhysicsList
{
public:
     NSTPhysicsList();
     ~NSTPhysicsList();
};

#endif 

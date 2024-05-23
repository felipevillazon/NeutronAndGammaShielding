#ifndef NSTEVENTACTION_HH
#define NSTEVENTACTION_HH 1

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "NSTRunAction.hh"


class NSTEventAction : public G4UserEventAction
{
public:
	NSTEventAction(NSTRunAction*);
	~NSTEventAction();
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
	void AddEdep(G4double edep) {fEdep += edep;}  // function that will add the energy 
    

private:
  
    G4double fEdep;	// double definition of variable fEdep
   
	
};


#endif




#ifndef NSTSTEPPING_HH
#define NSTSTEPPING_HH


#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "NSTDetectorConstruction.hh"
#include "NSTEventAction.hh"

class NSTSteppingAction: public G4UserSteppingAction
{
public:
	NSTSteppingAction(NSTEventAction* eventAction);
	~NSTSteppingAction();
	
	virtual void UserSteppingAction(const G4Step*);
	
private:
	NSTEventAction * fEventAction;	

};

#endif                                               

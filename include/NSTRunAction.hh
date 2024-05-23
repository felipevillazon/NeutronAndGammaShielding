#ifndef NSTRUNACTION_HH
#define NSTRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4RootAnalysisManager.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"

class NSTRunAction : public G4UserRunAction
{
public:
	NSTRunAction();
	~NSTRunAction();
	
	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
};


#endif

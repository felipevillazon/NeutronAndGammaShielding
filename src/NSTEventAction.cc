#include "NSTEventAction.hh"
#include "G4AnalysisManager.hh"

NSTEventAction::NSTEventAction(NSTRunAction*)
{
	fEdep = 0. ;   
}

NSTEventAction::~NSTEventAction()
{}

void NSTEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0. ; 
}

void NSTEventAction::EndOfEventAction(const G4Event*)
{	
	G4cout << "Energy deposition: " << fEdep << G4endl;  
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleDColumn(3,0, fEdep);  // filling the tuple with the energy creating a second row of data
	
	man->AddNtupleRow(3); // adding it to row 1
}

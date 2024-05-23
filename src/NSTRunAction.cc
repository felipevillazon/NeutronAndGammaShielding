#include "NSTRunAction.hh"

NSTRunAction::NSTRunAction(){}

NSTRunAction::~NSTRunAction(){}

void NSTRunAction::BeginOfRunAction(const G4Run* run)
{
	 G4AnalysisManager *man = G4AnalysisManager::Instance();
	 
	 G4int runID = run->GetRunID();
	 
	 std::stringstream strRunID;
	 strRunID << runID;
	 
	 man->OpenFile("output" +strRunID.str()+ ".root");
	 
	 // Tuple for neutron information recorded in the sensitive volume
	 man->CreateNtuple("Hits", "Hits");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("initial_Energy");
	 man->CreateNtupleDColumn("final_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->FinishNtuple(0);
	 
	 // Tuple for the neutron information recorded in the tested material
	 man->CreateNtuple("Scoring", "Scoring");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("Kinetic_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->FinishNtuple(1);
	 
	 // Tuple for secondary particles information recorded in the sensitive volume
	 man->CreateNtuple("Hits", "Secondaries");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("initial_Energy");
	 man->CreateNtupleDColumn("final_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->CreateNtupleSColumn("Particle_Name");
	 man->FinishNtuple(2);
	 
	 
	 man->CreateNtuple("dep_neutron", "energy");
	 man->CreateNtupleDColumn("energy");
	 man->FinishNtuple(3);
	 
	 man->CreateNtuple("captured", "distance");
	 man->CreateNtupleDColumn("distance");
	 man->FinishNtuple(4);
	 
	 
	 
	 
}

void NSTRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->Write();
	man->CloseFile();
}

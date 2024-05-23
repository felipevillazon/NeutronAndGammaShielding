#include "NSTSteppingAction.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4Neutron.hh"
#include "G4AnalysisManager.hh"

NSTSteppingAction::NSTSteppingAction(NSTEventAction *eventAction)
{
	fEventAction = eventAction;

}

NSTSteppingAction::~NSTSteppingAction()
{}

void NSTSteppingAction::UserSteppingAction(const G4Step *step)
{


	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
	
	const NSTDetectorConstruction *detectorConstruction = static_cast<const NSTDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	
	G4LogicalVolume *fMaterialVolume = detectorConstruction->GetMaterialVolume();
	
	G4Track *track = step->GetTrack();
	
	G4ParticleDefinition* particle = track->GetDefinition();
	
	G4String processName = track->GetStep()->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
	
	
	if (particle == G4Neutron::NeutronDefinition()){

	//if (volume == fMaterialVolume) {
        // collect energy deposited in this step
        G4double edep = step->GetTotalEnergyDeposit();
        //G4cout << "E = " << edep << G4endl;
        //G4cout << "processID: " << processName << G4endl;
        fEventAction->AddEdep(edep);
        //return;}
        
        
        
        if (processName == "nCapture") {
        
        // Calculate the distance travelled by the neutron before capture
        G4double distance = track->GetTrackLength();
       
        G4cout << distance << G4endl;
       
       	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleDColumn(4,0, distance);  // filling the tuple with the energy creating a second row of data
	
	man->AddNtupleRow(4);
       }
       }
       
       
      
};
	

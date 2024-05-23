#include "NSTSensitiveDetector.hh"
#include "G4Neutron.hh"
#include "G4Gamma.hh"

NSTSensitiveDetector::NSTSensitiveDetector(G4String name): G4VSensitiveDetector(name)
{}


NSTSensitiveDetector::~NSTSensitiveDetector(){}

G4bool NSTSensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *R0hist)
{
	G4Track *track = aStep->GetTrack();  // to keep track of the photon
	
	track->SetTrackStatus(fStopAndKill);  //  once the photons enter the detectors, the track is no propagated any further
	
	
	G4ParticleDefinition* particle = track->GetDefinition();

      
        if (particle == G4Neutron::NeutronDefinition()){
        
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();  // We define presetep when the photon get inot the detector
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();  // Post step when the photon go out of the detector
	
	G4ThreeVector posPhoton = preStepPoint->GetPosition();    // We find the position of the photon when it gets into the detector
	 
	G4double initialEnergy = track->GetVertexKineticEnergy();
	
	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	
	G4int copyNo = touchable->GetCopyNumber();
	
	G4VPhysicalVolume *physVol = touchable->GetVolume();

	
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	
	G4double finalEnergy = postStepPoint->GetKineticEnergy();
	
	G4double time = preStepPoint->GetLocalTime();

	
	
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0,0,evt);
	man->FillNtupleDColumn(0,1,initialEnergy);
	man->FillNtupleDColumn(0,2,finalEnergy);
	man->FillNtupleDColumn(0,3,time);
	man->AddNtupleRow(0);
	
	}	
	
	if (particle != G4Neutron::NeutronDefinition()){
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();  // We define presetep when the photon get inot the detector
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();  // Post step when the photon go out of the detector
	
	G4ThreeVector posPhoton = preStepPoint->GetPosition();    // We find the position of the photon when it gets into the detector
	 
	//G4cout << "Photon Position in PMT: " << posPhoton << G4endl;   // printing the position of the photon and a text  
	
	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
	
	G4int copyNo = touchable->GetCopyNumber();
	
	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector = physVol->GetTranslation();
	
	//G4cout << "Detector position " << posDetector << G4endl;
	//G4cout << "Detector number: " << copyNo << G4endl;
	
	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	
	G4double finalEnergy = postStepPoint->GetKineticEnergy();
	
	G4double initialEnergy = track->GetVertexKineticEnergy();
	
	
	//G4cout << "Nuetron Energy Sensitive Detector: " << photonEnergy << " [MeV]" << G4endl;
	
	G4double time = preStepPoint->GetLocalTime();
	
	//G4cout << "Time: " << time << G4endl;
	
	G4String particleName = aStep->GetTrack()->GetDefinition()->GetParticleName();
	
	// G4cout << "ID" << particleName << G4endl;
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(2,0,evt);
	man->FillNtupleDColumn(2,1,initialEnergy);
	man->FillNtupleDColumn(2,2,finalEnergy);
	man->FillNtupleDColumn(2,3,time);
	man->FillNtupleSColumn(2,4,particleName);
	man->AddNtupleRow(2);
	
	}	
	
  return true;	
}	

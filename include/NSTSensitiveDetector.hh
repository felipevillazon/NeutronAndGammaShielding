#ifndef NSTSENSTIVEDETECTOR_HH
#define NSTSENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4String.hh"
#include "G4TouchableHistory.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"

class NSTSensitiveDetector : public G4VSensitiveDetector
{
public:
	NSTSensitiveDetector(G4String);
	~NSTSensitiveDetector();
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif

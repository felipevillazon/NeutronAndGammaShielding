#ifndef NSTSENSITIVEVOLUME_HH
#define NSTSENSITIVEVOLUME_HH

#include "G4VSensitiveDetector.hh"
#include "G4String.hh"
#include "G4TouchableHistory.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"

class NSTSensitiveVolume : public G4VSensitiveDetector
{
public:
	NSTSensitiveVolume(G4String);
	~NSTSensitiveVolume();
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif

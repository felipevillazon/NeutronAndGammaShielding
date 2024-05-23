#ifndef NSTDetectorMessenger_h
#define NSTDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class NSTDetectorConstruction;

class G4UIcmdWithABool;
class G4UIcmdWithADouble;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcmdWith3VectorAndUnit;
class G4UIcommand;
class G4UIdirectory;

class NSTDetectorMessenger : public G4UImessenger
{
 public:
  NSTDetectorMessenger(NSTDetectorConstruction*);
  ~NSTDetectorMessenger();

  void SetNewValue(G4UIcommand*, G4String) override;

 private:
  NSTDetectorConstruction* fNSTDetector;
  G4UIdirectory* fDetectorDir;

  G4UIcmdWithADoubleAndUnit* fThicknessCmd;
  
  G4UIcommand* fDefaultsCmd;

};

#endif	

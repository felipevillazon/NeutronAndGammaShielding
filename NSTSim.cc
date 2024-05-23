
#include "NSTDetectorConstruction.hh"
#include "NSTActionInitialization.hh"
#include "NSTPhysics.hh"


#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "QBBC.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "Randomize.hh"
#include "QGSP_BERT.hh"
#include "Shielding.hh"
#include "G4StepLimiterPhysics.hh"

//#include "G4VisAttributes.hh"
//#include "G4Colour.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
  // Detect interactive mode (if no arguments) and define UI session
  //
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // Choose the Random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
  
  // Construct the default run manager
  //
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
#else
  G4RunManager* runManager = new G4RunManager;
#endif

  // Set mandatory initialization classes
  //
  // Detector construction
  runManager->SetUserInitialization(new NSTDetectorConstruction());
  //runManager->SetUserInitialization(new NSTPhysicsList());
  // Physics list
  //G4VModularPhysicsList* physicsList = new QBBC;
  //physicsList->SetVerboseLevel(1);
  //runManager->SetUserInitialization(physicsList);
  
  G4VModularPhysicsList* physics = new Shielding();
  
  physics->RegisterPhysics(new G4StepLimiterPhysics());
  runManager->SetUserInitialization(physics);
    
  // User action initialization
  runManager->SetUserInitialization(new NSTActionInitialization());
  
  
 

  // Initialize visualization
  //
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  
  /*/UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/open OI");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/geometry/set/colour Envelope 0 0 0 1 .3");
  UImanager->ApplyCommand("/vis/geometry/set/colour shield 0 1 1 1 0.4");
  UImanager->ApplyCommand("/vis/geometry/set/colour PMT 0 0.5 0 0.5 0.9");
  //UImanager->ApplyCommand("/vis/geometry/set/colour PMT2 0 0.5 0 0.5 0.9");
  //UImanager->ApplyCommand("/vis/geometry/set/colour GXe 0 1 0.5 0.0 0.5");*/

  // Process macro or start UI session
  //
  if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !
  
  //vis/geometry/set/colour Envelope 0 0 0 1 .3
  //vis/geometry/set/colour shield 0 1 1 1 .3
  //vis/geometry/set/colour Envelope 0 0 0 1 .3
  
  delete visManager;
  delete runManager;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

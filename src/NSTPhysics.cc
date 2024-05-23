#include "NSTPhysics.hh"
#include "G4IonElasticPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4HadronPhysicsQGSP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4NuclideTable.hh"
#include "G4HadronPhysicsFTFP_BERT_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_HP.hh"
#include "G4HadronPhysicsQGSP_BIC_AllHP.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4HadronPhysicsINCLXX.hh"
#include "G4IonElasticPhysics.hh"
#include "G4IonPhysicsXS.hh"
#include "G4IonPhysicsPHP.hh"
#include "G4IonINCLXXPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4Neutron.hh"
#include "G4ProcessManager.hh"
#include "G4HadronicInteraction.hh"
#include "FTFP_BERT_HP.hh"

NSTPhysicsList::NSTPhysicsList()
{
   RegisterPhysics (new G4EmStandardPhysics());
   RegisterPhysics (new G4HadronPhysicsQGSP_BERT_HP());
   RegisterPhysics (new G4HadronElasticPhysics());
   RegisterPhysics (new G4HadronPhysicsQGSP_BERT());
   
   //RegisterPhysics (new G4HadronPhysicsQGSP_BIC_HP());
   //RegisterPhysics (new G4IonPhysics());
   //RegisterPhysics (new G4IonElasticPhysics());
   //RegisterPhysics (new G4IonPhysicsXS());
   //RegisterPhysics (new G4DecayPhysics());
   //RegisterPhysics (new G4RadioactiveDecayPhysics());


}

NSTPhysicsList::~NSTPhysicsList()
{}
   

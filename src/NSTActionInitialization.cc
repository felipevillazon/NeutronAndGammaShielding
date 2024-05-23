#include "NSTActionInitialization.hh"
#include "NSTPrimaryGeneratorAction.hh"
#include "NSTRunAction.hh"
#include "NSTEventAction.hh"
#include "NSTSteppingAction.hh"


NSTActionInitialization::NSTActionInitialization(){}
NSTActionInitialization::~NSTActionInitialization(){}

void NSTActionInitialization::Build() const
{
  
  
  SetUserAction(new NSTPrimaryGeneratorAction);
  
  NSTRunAction *runAction = new NSTRunAction();
  SetUserAction(runAction);
  
  NSTEventAction *eventAction = new NSTEventAction(runAction);
  SetUserAction(eventAction);
  
  NSTSteppingAction *steppingAction = new NSTSteppingAction(eventAction);
  SetUserAction(steppingAction);
 
}  

 

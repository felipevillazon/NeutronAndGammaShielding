#ifndef NSTActionInitialization_h
#define NSTActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "NSTRunAction.hh"



class NSTActionInitialization : public G4VUserActionInitialization
{
  public:
  NSTActionInitialization();
  ~NSTActionInitialization();
  
  virtual void Build() const;
};



#endif

    

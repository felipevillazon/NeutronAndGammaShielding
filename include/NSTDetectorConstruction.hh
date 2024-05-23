#ifndef NSTDetectorConstruction_h
#define NSTDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "NSTSensitiveDetector.hh"
#include "NSTSensitiveVolume.hh"
#include "NSTDetectorMessenger.hh"
#include "G4NistManager.hh"

#include <map>
#include <vector>	

using std::vector;
using std::map;

/// Detector construction class to define materials and geometry.


class NSTDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
	
	NSTDetectorConstruction();
	~NSTDetectorConstruction();
	
        
        G4LogicalVolume * GetWorldVolume() const { return fWorldVolume; }
        
        G4LogicalVolume * GetMaterialVolume() const { return fMaterialVolume; }
        
        void SetDefaults();



  void SetThickness(G4double k);
  G4double GetThickness() const { return fThickness; }


  
  virtual G4VPhysicalVolume *Construct();

 
  private:
       
        NSTDetectorMessenger* fDetectorMessenger;
        
	virtual void ConstructSDandField();
	
	void DefinedMaterials();
	
	G4LogicalVolume* fMaterialVolume;
	G4LogicalVolume* fWorldVolume;
	
	
	//~~~~~~~MATERIALS~~~~~~~//
	
	G4Element* H;
	G4Element* C;
	G4Element* N;
	G4Element* O;
	G4Element* F;
	G4Element* Cr;
	G4Element* Mn;
	G4Element* Fe;
	G4Element* Ni;
	G4Element* Cu;
	G4Element* Si;
	G4Element* Xe;
	G4Element* Al;
	G4Element* Ti;
	G4Element* Mo;
	G4Element* Co;
	G4Element *Na;
	G4Element *P;
	G4Element *S;
	G4Element *K;
	G4Element *Ca;
	G4Element *Mg;
	G4Element *Ga;
	G4Element *B;
	
	G4Material* Vacuum;
	G4Material* Air;
	G4Material* SS304LSteel;
	G4Material* PMMA;
	G4Material* SiOil;
	G4Material* Iron;
	G4Material* StandardConcrete;
	G4Material* Graphite;
	G4Material* LAB;
	G4Material* PXE;
	G4Material* DIN;
	G4Material* Gd3;
	G4Material* THF;
	G4Material* PPO;
	G4Material* bisMSB;
	G4Material* STEREOLS;
	G4Material* Boron;
	G4Material* TPTMTS;
	G4Material* PPTMTS;
	G4Material* PM100_500_cS;
	G4Material* PMDM50;
	G4Material* DPDM20;
	
	//------VARIABLES-----//
	
	G4double fThickness;
	G4Material* tmaterial;

        //-----TESTED MATERIAL GEOMETRY----//
        
	G4Box* TMaterialBox;
	G4LogicalVolume* TMaterialLogical;
	G4VPhysicalVolume* TMaterialPhysical;
	
	//-----SENSITIVE DETECTOR------//
	
	G4Box* SDBox;
	G4LogicalVolume* SDLogical;
	G4VPhysicalVolume* SDPhysical;
	
	
	
	


};

#endif


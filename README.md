# NeutronAndGammaShielding
This is a geant4 simulation implemented to study the properties of different materials as possible neutron and/or gamma shielding. Several materials have been already implemented but the user can freely implement as much as they want.

The experiment is basically a particle gun that shoots a given amount of particles toward a material. Right behind this material, we have placed a sensitive detector that collects the surviving particles. We also study the physics happening in the material.

The output is a root file that can be used for further analysis, typically using root or uproot in python.

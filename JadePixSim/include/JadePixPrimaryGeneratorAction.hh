//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// The code was written by :
//  ^Claudio Andenna  claudio.andenna@ispesl.it, claudio.andenna@iss.infn.it
//      *Barbara Caccia barbara.caccia@iss.it
//      with the support of Pablo Cirrone (LNS, INFN Catania Italy)
//  with the contribute of Alessandro Occhigrossi*
//
// ^INAIL DIPIA - ex ISPESL and INFN Roma, gruppo collegato Sanità, Italy
// *Istituto Superiore di Sanità and INFN Roma, gruppo collegato Sanità, Italy
//  Viale Regina Elena 299, 00161 Roma (Italy)
//  tel (39) 06 49902246
//  fax (39) 06 49387075
//
// more information:
// http://g4advancedexamples.lngs.infn.it/Examples/medical-linac
//
//*******************************************************//


#ifndef JadePixPrimaryGeneratorActionH
#define JadePixPrimaryGeneratorActionH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "JadePixPrimaryGeneratorActionMessenger.hh"
#include "G4String.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include <vector>

class JadePixPrimaryGeneratorActionMessenger;

enum SourceType {
  _ParticleGun = 0,
  _GeneralParticleSource
};

class JadePixPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    JadePixPrimaryGeneratorAction(SourceType);
    ~JadePixPrimaryGeneratorAction();
    
    void GeneratePrimaries(G4Event* anEvent);

    //void SetParticleType(G4String ptype) {m_particleType = ptype;};
    //G4String GetParticleType() {return m_particleType;};

    void SetGunEnergy(G4double energy) {m_gunEnergy = energy;};
    G4double GetGunEnergy() {return m_gunEnergy;};

    void SetGunPosXYSpread(G4double xyspread) {m_gunPosXYSpread = xyspread;};
    G4double GetGunPosXYSpread() {return m_gunPosXYSpread;};

    void SetGunPosZ(G4double posz) {m_gunPosZ = posz;};
    G4double GetGunPosZ() {return m_gunPosZ;};


  private:
    G4ParticleGun* fParticleGun;
    G4GeneralParticleSource* fParticleSource;
    JadePixPrimaryGeneratorActionMessenger* m_PrimaryGeneratorActionMessenger;
    SourceType m_particleType;
    std::vector<G4ThreeVector> m_primaryParticlePos;
    G4double m_gunPosXYSpread;
    G4double m_gunPosZ;
    G4double m_gunEnergy;
};

#endif

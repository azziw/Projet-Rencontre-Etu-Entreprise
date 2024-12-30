#include <iostream>
#include <string>
#include <vector>

#include "etudiant.hpp"
#include "ExperiencePro.hpp"

using namespace std;

// Ajout d'un diplome
void Etudiant::addDiplome(Diplome D){
    listeDiplomes.push_back(D);
    D->listeDiplomes.push_back(this); 
}

// Ajout d'une Experience
void Etudiant::addExperience(ExperiencePro E){
    listeExperience.push_back(E);
    E->listeExperience.push_back(this); 
}

// Ajout d'un Rendez-Vous
void Etudiant::addRendezVous(RendezVous R){
    rendezVous.push_back(R);
    R->rendezVous.push_back(this); 
};

// getCV() !!


void Etudiant::setNumeroEtudiant(int num){
    numeroEtudiant = num;
};





# include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "ExperiencePro.hpp"

// Ajout d'un diplome
void ExperiencePro::addEtudiant(Etudiant etu){
    listeExperience.push_back(etu);
    etu->listeExperience.push_back(this); 
}
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

date ExperiencePro::getDateDebut() const{
    return dateDebut;
}

date ExperiencePro::getDateFin() const{
    return dateFin;
}

string ExperiencePro::getNomEnt() const{
    return nomEntreprise;
}

string ExperiencePro::getFonction() const{
    return fonctionOccupee;
}

Etudiant ExperiencePro::getEtudiant() const{
    return etudiant;
}

void ExperiencePro::setDateDebut(date d){
    dateDebut = d;
}

void ExperiencePro::setDateFin(date d){
    dateFin = d;
}

void ExperiencePro::setNomEnt(string nom){
    nomEntreprise = nom;
}

void ExperiencePro::setFonction(string fonc){
    fonctionOccupee = fonc;
}

void ExperiencePro::setEtudiant(Etudiant etu){
    etudiant = etu;
}

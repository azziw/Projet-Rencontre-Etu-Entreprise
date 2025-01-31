# include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "ExperiencePro.hpp"

// ---- METHODES ---- //

void ExperiencePro::Affiche() const{
    cout << "Du " << dateDebut->toString() << " au " << dateFin->toString() << " : " << fonctionOccupee << " chez " << nomEntreprise << endl;
}

// ---- GETTERS ---- //

Date* ExperiencePro::getDateDebut() const{
    return dateDebut;
}

Date* ExperiencePro::getDateFin() const{
    return dateFin;
}

string ExperiencePro::getNomEnt() const{
    return nomEntreprise;
}

string ExperiencePro::getFonction() const{
    return fonctionOccupee;
}

Etudiant* ExperiencePro::getEtudiant() const{
    return etudiant;
}


// ---- SETTERS ---- //


void ExperiencePro::setDateDebut(Date* d){
    dateDebut = d;
}

void ExperiencePro::setDateFin(Date* d){
    dateFin = d;
}

void ExperiencePro::setNomEnt(string nom){
    nomEntreprise = nom;
}

void ExperiencePro::setFonction(string fonc){
    fonctionOccupee = fonc;
}

void ExperiencePro::setEtudiant(Etudiant* etu){
    etudiant = etu;
    etu->addExperience(this);
}

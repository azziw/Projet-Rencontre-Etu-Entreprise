#include <iostream>
#include <string>
#include <vector>

#include "Etudiant.hpp"
#include "ExperiencePro.hpp"

using namespace std;

// Ajout d'un diplome 
void Etudiant::addDiplome(Diplome* D){
    listeDiplomes.push_back(D);
}

// Ajout d'une Experience
void Etudiant::addExperience(ExperiencePro* E){
    listeExperience.push_back(E);
}

// Ajout d'un Rendez-Vous
void Etudiant::addRendezVous(RendezVous* R){
    rendezVous.push_back(R);
};

// getCV() !!


void Etudiant::setNumeroEtudiant(int num){
    numeroEtudiant = num;
};


int Etudiant::getNumeroEtudiant() const {
    return numeroEtudiant;
}


string Etudiant::getNomEtudiant() const {
    return nom;
}

string Etudiant::getPrenomEtudiant() const{
    return prenom;
}

string Etudiant::getAdresseEtudiant() const{
    return adresse;
}

string Etudiant::getNumeroTel() const{
    return numeroTel;
}

InscriptionActuelle Etudiant::getDiplomeActuel() const{
    return *diplomeActuel;
}

void Etudiant::setNumeroEtudiant(int num){
    numeroEtudiant = num;
}

void Etudiant::setNomEtudiant(string Nom){
    nom = Nom;
}

void Etudiant::setPrenomEtudiant(string Prenom){
    prenom = Prenom;
}

void Etudiant::setAdresseEtudiant(string Adresse){
    adresse = Adresse;
}

void Etudiant::setNumeroTel(string tel){
    numeroTel = tel;
}

void Etudiant::setDiplomeActuel(InscriptionActuelle* Inscription){
    diplomeActuel = Inscription;
}

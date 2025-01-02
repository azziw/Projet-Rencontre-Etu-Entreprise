#include <iostream>
#include <string>
#include <vector>

#include "Etudiant.hpp"
#include "ExperiencePro.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Entreprise.hpp"

using namespace std;


bool Etudiant::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if((*iT)->getDate() == rdv->getDate())
        {
            //Alors je regarde si le rendez-vous est au milieu du créneau d'un rendez-vous existant
            
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            if ((*iT)->getHeureDebut() < rdv->getHeureFin() && rdv->getHeureDebut() < (*iT)->getHeureFin()) 
            {
                return false;
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return true;
}

void Etudiant::addRendezVous(RendezVous* rdv)
{
    if(checkDispo(rdv))
    {
        ensRendezVous.push_back(rdv);
    }
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau n'est pas disponible." << endl;
    }
}


void Etudiant::setRendezVous(Entreprise* ent, Date* date, Heure* heureDebut, Heure* heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, this, ent);

    if(checkDispo(rdv))
    {
        ensRendezVous.push_back(rdv);
        ent->addRendezVous(rdv);   
    }
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau n'est pas disponible." << endl;
    }
}

void Etudiant::AfficheRdv()
{
    vector<RendezVous *>::iterator iT;

    cout << "L'etudiant " << nom << " a les rendez-vous suivants:" << endl;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        (*iT)->Affiche();
    }
}


// Ajout d'un diplome 
void Etudiant::addDiplome(Diplome* D){
    ensDiplomes.push_back(D);
}

// Ajout d'une Experience
void Etudiant::addExperience(ExperiencePro* E){
    ensExperience.push_back(E);
}

// getCV() !!


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

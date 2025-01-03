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


RendezVous* Etudiant::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if(*(*iT)->getDate() == *rdv->getDate())
        {
            //Alors je regarde si le rendez-vous est au milieu du créneau d'un rendez-vous existant
            
            //Si le rendez-vous est pendant un autre rendez-vous
            if (*(*iT)->getHeureDebut() < *rdv->getHeureFin() && *rdv->getHeureDebut() < *(*iT)->getHeureFin()) 
            {
                return *iT;
            }
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            if (*(*iT)->getHeureDebut() == *rdv->getHeureFin() && *rdv->getHeureDebut() == *(*iT)->getHeureFin()) 
            {
                return *iT;
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return nullptr;
}

void Etudiant::addRendezVous(RendezVous* rdv)
{
    RendezVous* conflitEtu = checkDispo(rdv); //On regarde si il y a un conflit avec les rendez-vous de l'etudiant

    Entreprise* entrepriseConcerne = rdv->getEntreprise();
    RendezVous* conflitEnt = entrepriseConcerne->checkDispo(rdv); // On regarde si il y a un conflit avec l'entreprise concernée

    cout << endl;

    //Si il n'y a pas de conflit pour l'etudiant
    if(conflitEtu == nullptr)
    {
        //Si il n'y a pas de conflit pour l'entreprise concernée
        if(conflitEnt == nullptr)
        {
            cout << "Créneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
            entrepriseConcerne->addRendezVous(rdv);
        }
        //Si il n'y a pas de conflit pour l'etudiant mais qu'il y en a un pour l'entreprise
        else
        {
            cout << "Créneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
        }
    }
    //Si il y a un conflit pour l'etudiant
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau du " << rdv->getDate()->toString() << " de " <<
        rdv->getHeureDebut()->toString() << " à " << rdv->getHeureFin()->toString() << " n'est pas disponible." << endl <<
        "Celui-ci est en conflit avec le rdv de: " << conflitEtu->toString() << endl << //erreur on affiche que le créneau n'est pas dispo
        "Veuillez Réessayer!" << endl;
    }
}


bool Etudiant::checkExistence(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        if((*iT) == rdv)
        {
            return true;
        }
    }
    return false;
}


void Etudiant::setRendezVous(Entreprise* ent, Date* date, Heure* heureDebut, Heure* heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, this, ent);

    cout << endl;

    addRendezVous(rdv);
}


void Etudiant::removeRendezVous(RendezVous* rdv, bool called)
{
    cout << endl;

    Entreprise* entrepriseConcerne = rdv->getEntreprise();

    RendezVous* conflitEtu = checkDispo(rdv); //On regarde si il y a un conflit avec les rendez-vous de l'etudiant
    bool exist = checkExistence(rdv); //permet de vérifier si le rendez-vous existe dans la liste de rendez-vous

    //si il n'existe pas, c'est qu'on essaie de supprier un rendez-vous qui n'as jamais été ajouté.
    if(!exist)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", celui-ci n'existe pas pour " << nom << endl;
        return;
    }

    //Si on trouve ne trouve pas le rendez-vous
    if(conflitEtu == nullptr)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", il n'est pas programmé pour " << nom << endl; 
    }
    //On trouve le rendez-vous
    else
    {
        vector<RendezVous*>::iterator iT;

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            if((*iT) == rdv)
            {
                ensRendezVous.erase(iT);
                cout << "Le rendez-vous " << rdv->toString() << " a été supprimé de " << nom << " avec succès." << endl;
                if(called != true)
                {
                    entrepriseConcerne->removeRendezVous(rdv, true); // On enlève aussi le rendez-vous pour l'entreprise
                }
                return;
            }
        }
    }
}



void Etudiant::AfficheRdv()
{
    vector<RendezVous *>::iterator iT;

    cout << endl;

    //Si l'ensemble est vide on ne le parcours pas.
    if (ensRendezVous.empty())
    {
        cout << "Aucun rendez-vous n'est planifié pour l'etudiant " << nom << endl;
    }
    else
        {
        cout << "L'etudiant " << nom << " a les rendez-vous suivants:" << endl;

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            (*iT)->Affiche();
        }
    }
}


void Etudiant::Affiche() const
{
    cout << "Etudiant n°" << numeroEtudiant << ": " << nom << " " << prenom << " habite " << adresse << " et peut être joint au " << numeroTel << endl;

    cout << "Il est inscrit en " << diplomeActuel->getDiplome()->getNom() << " depuis le " << diplomeActuel->getDate()->toString() << " et est en " << diplomeActuel->getAnnee() << " année." << endl;
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

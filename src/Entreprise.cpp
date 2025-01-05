#include <iostream>
#include <algorithm>

using namespace std;

#include "Entreprise.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Etudiant.hpp"

// ---- METHODES ---- //

// Permet de verifier si un rendez-vous est disponible à l'insertion
RendezVous* Entreprise::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if(*(*iT)->getDate() == *rdv->getDate())
        {
            //Alors je regarde si le rendez-vous est au milieu du creneau d'un rendez-vous existant
            
            //Si le rendez-vous est pendant un autre rendez-vous
            if (*(*iT)->getHeureDebut() < *rdv->getHeureFin() && *rdv->getHeureDebut() < *(*iT)->getHeureFin()) 
            {
                return *iT;
            }
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            // on suppose que les rendez-vous peuvent commencer à la même heure que lorsque l'un des rendez-vous se termine (ex: 10h-11h et 11h-12h)
            if (*(*iT)->getHeureDebut() == *rdv->getHeureFin()) 
            {
                return *iT;
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return nullptr;
}

// ajoute un rendez-vous à l'entreprise et à l'etudiant correspondant.
void Entreprise::addRendezVous(RendezVous* rdv)
{
    RendezVous* conflitEnt = checkDispo(rdv); //On regarde si il y a un conflit avec les rendez-vous de l'entreprise

    Etudiant* etudiantConcerne = rdv->getEtudiant();
    RendezVous* conflitEtu = etudiantConcerne->checkDispo(rdv); // On regarde si il y a un conflit avec l'etudiant concerne

    cout << endl;

    //Si il n'y a pas de conflit pour l'entreprise
    if(conflitEnt == nullptr)
    {
        //Si il n'y a pas de conflit pour l'etudiant concerne
        if(conflitEtu == nullptr)
        {
            cout << "Creneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
            etudiantConcerne->addRendezVous(rdv);
        }
        //Si il n'y a pas de conflit pour l'entreprise mais qu'il y en a un pour l'etudiant
        else
        {
            cout << "Creneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
        }
    }
    //Si il y a un conflit pour l'entreprise
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le creneau du " << rdv->getDate()->toString() << " de " <<
        rdv->getHeureDebut()->toString() << " à " << rdv->getHeureFin()->toString() << " n'est pas disponible." << endl <<
        "Celui-ci est en conflit avec le rdv de: " << conflitEnt->toString() << endl << //erreur on affiche que le creneau n'est pas dispo
        "Veuillez Reessayer!" << endl;
    }
}

// Verifie si un rendez-vous existe dejà //
bool Entreprise::checkExistence(RendezVous* rdv)
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

// Permet d'enlever un rendez-vous existant 
void Entreprise::removeRendezVous(RendezVous* rdv, bool called)
{
    cout << endl;

    Etudiant* etudiantConcerne = rdv->getEtudiant();

    RendezVous* conflitEnt = checkDispo(rdv); //on regarde si il y a un conflit avec les rendez-vous de l'entreprise
    bool exist = checkExistence(rdv); //permet de verifier si le rendez-vous existe dans la liste de rendez-vous

    //si il n'existe pas, c'est qu'on essaie de supprier un rendez-vous qui n'as jamais ete ajoute.
    if(!exist)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", celui-ci n'existe pas pour " << nom << endl;
        return;
    }

    //Si on trouve ne trouve pas le rendez-vous
    if(conflitEnt == nullptr)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", il n'est pas programme pour " << nom << endl; 
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
                cout << "Le rendez-vous " << rdv->toString() << " a ete supprime de " << nom << " avec succès." << endl;
                if(called != true)
                {
                    etudiantConcerne->removeRendezVous(rdv, true); // On enlève aussi le rendez-vous pour l'etudiant
                }
                return;
            }
        }
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", il n'est pas programme pour " << nom << endl; 
    }
}

// Affiche les rendez-vous d'une entreprise tries par date
void Entreprise::AfficheRdv()
{
    vector<RendezVous *>::iterator iT;

    cout << endl;

    //Si l'ensemble est vide on ne le parcours pas.
    if (ensRendezVous.empty())
    {
        cout << "Aucun rendez-vous n'est planifie pour l'entreprise " << nom << endl;
    }
    else
    {
        cout << "L'entreprise " << nom << " a les rendez-vous suivants:" << endl;

        sort(ensRendezVous.begin(), ensRendezVous.end(), [](RendezVous* a, RendezVous* b) {
            return *a < *b;
        });

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            (*iT)->Affiche();
        }
    }
}

// ---- GETTERS ---- /

string Entreprise::getNom() const
{
    return nom;
}

string Entreprise::getAdresse() const
{
    return adresse;
}

string Entreprise::getNomContact() const
{
    return nomContact;
}

string Entreprise::getTelephoneContact() const
{
    return telephoneContact;
}

vector<RendezVous *> Entreprise::getRendezVous() const
{
    return ensRendezVous;
}

// ---- SETTERS ---- //

void Entreprise::setRendezVous(Etudiant* etu, Date* date, Heure* heureDebut, Heure* heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, etu, this);

    cout << endl;

    addRendezVous(rdv);
}

void Entreprise::setNom(string Nom)
{
    nom = Nom;
}

void Entreprise::setAdresse(string Adresse)
{
    adresse = Adresse;
}

void Entreprise::setNomContact(string NomContact)
{
    nomContact = NomContact;
}

void Entreprise::setTelephoneContact(string tel)
{
    telephoneContact = tel;
}

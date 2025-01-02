#include <iostream>

using namespace std;

#include "Entreprise.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Etudiant.hpp"

RendezVous* Entreprise::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if((*iT)->getDate() == rdv->getDate())
        {
            //Alors je regarde si le rendez-vous est au milieu du créneau d'un rendez-vous existant
            
            //Si le rendez-vous est pendant un autre rendez-vous
            if ((*iT)->getHeureDebut() < rdv->getHeureFin() && rdv->getHeureDebut() < (*iT)->getHeureFin()) 
            {
                return *iT;
            }
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            if ((*iT)->getHeureDebut() == rdv->getHeureFin() && rdv->getHeureDebut() == (*iT)->getHeureFin()) 
            {
                return *iT;
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return nullptr;
}


// AJOUTER AUSSI A ETUDIANT ?? SINON EXPLIQUER POURQUOI ON NE LE FAIT PAS (DEJA LE CAS VIA SETRDV)

void Entreprise::addRendezVous(RendezVous* rdv)
{

    cout << endl;

    if(checkDispo(rdv) == nullptr)
    {
        cout << "Créneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << endl;
        ensRendezVous.push_back(rdv);
    }
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau n'est pas disponible." << endl;
    }
}

void Entreprise::removeRendezVous(RendezVous* rdv)
{

    cout << endl;

    if(checkDispo(rdv) == nullptr)
    {
        cerr << "Le rendez-vous entre " << rdv->toString() << " n'est pas programmé pour " << nom << endl; 
    }
    else
    {
        vector<RendezVous*>::iterator iT;

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            if((*iT) == rdv)
            {
                ensRendezVous.erase(iT);
                cout << "Le rendez-vous " << rdv->toString() << " a été supprimé avec succès." << endl;
                return;
            }
        }
    }
}

void Entreprise::setRendezVous(Etudiant* etu, Date* date, Heure* heureDebut, Heure* heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, etu, this);

    cout << endl;

    RendezVous* conflitRdv = checkDispo(rdv); //On stocke le rdv pour l'afficher en cas de conflit

    if(conflitRdv == nullptr)
    {
        cout << "Créneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << endl;
        ensRendezVous.push_back(rdv);
        etu->addRendezVous(rdv);   
    }
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau du " << date->toString() << " de " <<
        heureDebut->toString() << " à " << heureFin->toString() << " n'est pas disponible." << endl <<
        "Celui-ci est en conflit avec le rdv de: " << conflitRdv->toString() << endl << //erreur on affiche que le créneau n'est pas dispo
        "Veuillez Réessayer!" << endl;
    }
}



void Entreprise::AfficheRdv()
{
    vector<RendezVous *>::iterator iT;

    cout << endl;
    cout << "L'entreprise " << nom << " a les rendez-vous suivants:" << endl;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        (*iT)->Affiche();
    }
}

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

#include <iostream>

using namespace std;

#include "Entreprise.hpp"

bool Entreprise::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if((*iT)->getDate().tm_year == rdv->getDate().tm_year &&
            (*iT)->getDate().tm_mon == rdv->getDate().tm_mon &&
            (*iT)->getDate().tm_mday == rdv->getDate().tm_mday)
        {
            //Alors je regarde si le rendez-vous est au milieu du créneau d'un rendez-vous existant
            
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            if((*iT)->getHeureDebut().tm_hour == rdv->getHeureDebut().tm_hour)
            {
                //Je regarde les minutes et je vérifie qu'elles ne se chevauchent pas
                if((*iT)->getHeureDebut().tm_min <= rdv->getHeureDebut().tm_min && 
                (*iT)->getHeureFin().tm_min >= rdv->getHeureDebut().tm_min)
                {
                    return false;
                }
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return true;
}

void Entreprise::addRendezVous(RendezVous* rdv)
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

void Entreprise::setRendezVous(Etudiant* etu, tm date, tm heureDebut, tm heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, *etu, *this);

    if(checkDispo(rdv))
    {
        ensRendezVous.push_back(rdv);
        etu->addRendezVous(*rdv);   
    }
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le créneau n'est pas disponible." << endl;
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

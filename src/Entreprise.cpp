#include <iostream>

using namespace std;

#include "Entreprise.hpp"


bool Entreprise::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = rendezVous.begin(); iT != rendezVous.end(); iT++)
    {
        if((*iT)->getDate().tm_year == rdv->getDate().tm_year &&
            (*iT)->getDate().tm_mon == rdv->getDate().tm_mon &&
            (*iT)->getDate().tm_mday == rdv->getDate().tm_mday)
        {
            if(*iT)->getDate()
        }
        else
        {
            return false;
        }
    }
}

void Entreprise::addRendezVous(RendezVous* rdv)
{
    rendezVous.push_back(rdv);
}

void Entreprise::setRendezVous(Etudiant* etu, tm date, tm heureDebut, tm heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, *etu, *this);

    rendezVous.push_back(rdv);

    etu->addRendezVous(*rdv);
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

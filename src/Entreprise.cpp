#include <iostream>

using namespace std;

#include "Entreprise.hpp"


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

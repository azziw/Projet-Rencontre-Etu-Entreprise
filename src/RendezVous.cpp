#include <iostream>

using namespace std;

#include "RendezVous.hpp"
#include "Etudiant.hpp"
#include "Entreprise.hpp"
#include "Date.hpp"
#include "Heure.hpp"

// ---- METHODES ---- //

void RendezVous::Affiche()
{
    cout << "Rdv entre: " << etudiant->getNomEtudiant() << " et " << entreprise->getNom() << " le " << date->toString() << " de " << heureDebut->toString() << " à " << heureFin->toString() << endl;
}

string RendezVous::toString()
{
    return etudiant->getNomEtudiant() + " et " + entreprise->getNom() + " le " + date->toString() + " de " + heureDebut->toString() + " à " + heureFin->toString();
}

// ---- GETTERS ET SETTERS ---- //

// GETTERS //

Date* RendezVous::getDate() const
{
    return date;
}

Heure* RendezVous::getHeureDebut() const
{
    return heureDebut;
}

Heure* RendezVous::getHeureFin() const
{
    return heureFin;
}

Etudiant* RendezVous::getEtudiant() const
{
    return etudiant;
}

Entreprise* RendezVous::getEntreprise() const
{
    return entreprise;
}

Rencontre* RendezVous::getRencontre() const
{
    return rencontre;
}

// SETTERS //

void RendezVous::setDate(Date* Date)
{
    date = Date;
}

void RendezVous::setHeureDebut(Heure* HeureD)
{
    heureDebut = HeureD;
}

void RendezVous::setHeureFin(Heure* HeureF)
{
    heureFin = HeureF;
}

void RendezVous::setEtudiant(Etudiant* etu)
{
    etudiant = etu;
}

void RendezVous::setEntreprise(Entreprise* ent)
{
    entreprise = ent;
}

void RendezVous::setRencontre(Rencontre* ren)
{
    rencontre = ren;
}

// ---- OPERATEURS ---- //

bool RendezVous::operator<(const RendezVous& other) const {
    if (*date != *other.date) return *date < *other.date;
    return *heureDebut < *other.heureDebut;
}
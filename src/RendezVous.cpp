#include <iostream>

using namespace std;

#include "RendezVous.hpp"
#include "Etudiant.hpp"
#include "Entreprise.hpp"
#include "Date.hpp"
#include "Heure.hpp"

void RendezVous::Affiche()
{
    cout << "Rendez-Vous entre: " << etudiant->getNomEtudiant() << " et " << entreprise->getNom() << " Le " << date->toString() << " de" << heureDebut->toString() << " à " << heureFin->toString() << endl;
}

Date RendezVous::getDate() const
{
    return *date;
}

Heure RendezVous::getHeureDebut() const
{
    return *heureDebut;
}

Heure RendezVous::getHeureFin() const
{
    return *heureFin;
}

Etudiant RendezVous::getEtudiant() const
{
    return *etudiant;
}

Entreprise RendezVous::getEntreprise() const
{
    return *entreprise;
}

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

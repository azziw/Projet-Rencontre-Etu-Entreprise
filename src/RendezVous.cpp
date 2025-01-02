#include <iostream>

using namespace std;

#include "RendezVous.hpp"

void RendezVous::Affiche()
{
    cout << "Rendez-Vous entre: " << etudiant->getNomEtudiant() << " et " << entreprise->getNom() << " Le " << date << " de" << heureDebut << " à " << heureFin << endl;
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

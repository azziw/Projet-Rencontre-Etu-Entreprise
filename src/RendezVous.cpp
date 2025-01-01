#include <iostream>

using namespace std;

#include "RendezVous.hpp"

tm RendezVous::getDate() const
{
    return date;
}

tm RendezVous::getHeureDebut() const
{
    return heureDebut;
}

tm RendezVous::getHeureFin() const
{
    return heureFin;
}

Etudiant RendezVous::getEtudiant() const
{
    return etudiant;
}

Entreprise RendezVous::getEntreprise() const
{
    return entreprise;
}

void RendezVous::setDate(tm Date)
{
    date = Date;
}

void RendezVous::setHeureDebut(tm HeureD)
{
    heureDebut = HeureD;
}

void RendezVous::setHeureFin(tm HeureF)
{
    heureFin = HeureF;
}

void RendezVous::setEtudiant(Etudiant etu)
{
    etudiant = etu;
}

void RendezVous::setEntreprise(Entreprise ent)
{
    entreprise = ent;
}

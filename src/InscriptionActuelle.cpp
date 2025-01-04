#include <iostream>

using namespace std;

#include "InscriptionActuelle.hpp"
#include "Etudiant.hpp"


// ---- GETTERS ET SETTERS ---- //

// GETTERS //

Diplome* InscriptionActuelle::getDiplome() const
{
    return diplome;
}

Date* InscriptionActuelle::getDate() const
{
    return datePremiereInscription;
}

int InscriptionActuelle::getAnnee() const 
{
    return numeroAnnee;
}

// SETTERS //

void InscriptionActuelle::setEtudiant(Etudiant* etu)
{
    etu->setDiplomeActuel(this);
}

void InscriptionActuelle::setDiplome(Diplome* nouveauDiplome)
{
    diplome = nouveauDiplome;
}

void InscriptionActuelle::setDate(Date* date)
{
    datePremiereInscription = date;
}

void InscriptionActuelle::setAnnee(int annee)
{
    numeroAnnee = annee;
}


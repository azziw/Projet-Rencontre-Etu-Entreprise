#include <iostream>

using namespace std;

#include "InscriptionActuelle.hpp"


Diplome InscriptionActuelle::getDiplome() const
{
    return *diplome;
}

Date InscriptionActuelle::getDate() const
{
    return *datePremiereInscription;
}

int InscriptionActuelle::getAnnee() const 
{
    return numeroAnnee;
}

void InscriptionActuelle::setDiplome(Diplome* nouveauDiplome)
{
    diplome = nouveauDiplome;
    // FAIRE ETUDIANT MISE A JOUR
}

void InscriptionActuelle::setDate(Date* date)
{
    datePremiereInscription = date;
}

void InscriptionActuelle::setAnnee(int annee)
{
    numeroAnnee = annee;
}
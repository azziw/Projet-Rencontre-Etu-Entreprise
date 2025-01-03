#include <iostream>

using namespace std;

#include "Rencontre.hpp"


void Rencontre::AfficheRdv()
{
    cout << "\033[4mLes rendez-vous de la rencontre " << nom << " sont :\033[0m" << endl;

    vector<RendezVous *>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        (*iT)->Affiche();
    }

}

string Rencontre::getNom() const
{
    return nom;
}

string Rencontre::getLieu() const
{
    return Lieu;
}

Date* Rencontre::getDate() const
{
    return date;
}

void Rencontre::setNom(string Nom)
{
    nom = Nom;
}

void Rencontre::setLieu(string lieu)
{
    Lieu = lieu;
}

void Rencontre::setDate(Date* Date)
{
    date = Date;
}
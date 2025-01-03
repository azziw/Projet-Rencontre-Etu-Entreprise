#ifndef RENCONTRE_HPP
#define RENCONTRE_HPP

#include <iostream>

#include "Date.hpp"
#include "RendezVous.hpp"

using namespace std;

class Rencontre
{
    private:
        string nom;
        string Lieu;
        Date* date;
        vector<RendezVous *> ensRendezVous;
    public:
        Rencontre(string Nom, string lieu, Date* Date)
        {
            nom = Nom;
            Lieu = lieu;
            date = Date;
        }

        string getNom() const;
        string getLieu() const;
        Date* getDate() const;
        void setNom(string Nom);
        void setLieu(string lieu);
        void setDate(Date* Date);
        void AfficheRdv();
};

#endif
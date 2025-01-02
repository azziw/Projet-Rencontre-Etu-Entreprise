#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include <iostream>

#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "Date.hpp"
#include "Heure.hpp"

using namespace std;

class RendezVous
{
    private:
        Date* date;
        Heure* heureDebut;
        Heure* heureFin;
        Etudiant* etudiant;
        Entreprise* entreprise;

    public:

        RendezVous(Date* Date, Heure* HeureD, Heure* HeureF, Etudiant* etu, Entreprise* ent)
        {
            date = Date;
            heureDebut = HeureD;
            heureFin = HeureF;
            etudiant = etu;
            entreprise = ent;
        }

        Date getDate() const;
        Heure getHeureDebut() const;
        Heure getHeureFin() const;
        Etudiant getEtudiant() const;
        Entreprise getEntreprise() const;

        void setDate(Date* Date);
        void setHeureDebut(Heure* HeureD);
        void setHeureFin(Heure* HeureF);
        void setEtudiant(Etudiant* etu);
        void setEntreprise(Entreprise* ent);
        void Affiche();
};

#endif
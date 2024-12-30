#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include <iostream>

#include "Entreprise.hpp"
#include "Etudiant.hpp"

using namespace std;

class RendezVous
{
    private:
        tm date;
        tm heureDebut;
        tm heureFin;
        Etudiant etudiant;
        Entreprise entreprise;

    public:

        RendezVous(tm Date, tm HeureD, tm HeureF, Etudiant etu, Entreprise ent)
        {
            date = Date;
            heureDebut = HeureD;
            heureFin = HeureF;
            etudiant = etu;
            entreprise = ent;
        }

        tm getDate() const;
        tm getHeureDebut() const;
        tm getHeureFin() const;
        Etudiant getEtudiant() const;
        Entreprise getEntreprise() const;

        void setDate(tm Date);
        void setHeureDebut(tm HeureD);
        void setHeureFin(tm HeureF);
        void setEtudiant(Etudiant etu);
        void setEntreprise(Entreprise ent);
        void Affiche();
};

#endif
#ifndef GESTIONENTREPRISE_HPP
#define GESTIONENTREPRISE_HPP

#include <iostream>

#include "Entreprise.hpp"
#include "Date.hpp"

using namespace std;

class GestionEntreprise
{
    private:
        vector<Entreprise *> ensEntreprises;
    public:
        GestionEntreprise(){}


    // ---- METHODES ---- //

        void AfficheRdv();
        void AfficheEntreprises();
        void removeRendezVousEtudiant(Etudiant* etu);
        void addEntreprise(Entreprise* ent);
        void removeRendezVous();

        Entreprise* getEntreprise(string nom);
};

#endif
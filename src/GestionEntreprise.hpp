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

        void AfficheRdv();
        void addEntreprise(Entreprise* ent);
};

#endif
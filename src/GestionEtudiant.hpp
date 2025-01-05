#ifndef GESTIONETUDIANT_HPP
#define GESTIONETUDIANT_HPP

#include <iostream>

#include "Etudiant.hpp"
#include "Date.hpp"

using namespace std;

class GestionEtudiant
{
    private:
        vector<Etudiant *> ensEtudiant;
    public:
        GestionEtudiant(){}

    // ---- METHODES ---- //

        void AfficheRdv();
        void addEtudiant(Etudiant* etu);
        void AfficheEtudiants();
        Etudiant* getEtudiant(int numEtu);
};

#endif
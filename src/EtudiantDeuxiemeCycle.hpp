#ifndef ETUDIANTDEUXIEMECYCLE_HPP
#define ETUDIANTDEUXIEMECYCLE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Etudiant.hpp"

using namespace std;

class EtudiantDeuxiemeCycle : public Etudiant {
    string NomDisciplinePrincipale;

    public:
        // Constructeur
        EtudiantDeuxiemeCycle(int numEtu, string Nom, string Prenom, string Addr, string Telephone, InscriptionActuelle* diplome ,string NomDiscipline)
            : Etudiant(numEtu, Nom, Prenom, Addr, Telephone, diplome)
        {
            NomDisciplinePrincipale = NomDiscipline;
        }


// ---- METHODES ---- //

        void Affiche() const;

// ---- GETTERS ----- //

        string getNomDiscipline() const;

// ---- SETTERS ----- //

        void setNomDiscipline(string nom);

};

#endif
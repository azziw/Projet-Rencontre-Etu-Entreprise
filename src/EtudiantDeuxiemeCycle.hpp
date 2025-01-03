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

        void Affiche() const;

        string getNomDiscipline() const;

        void setNomDiscipline(string nom);

};

#endif
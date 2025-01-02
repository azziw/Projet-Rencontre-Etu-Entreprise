#ifndef ETUDIANTDEUXIEMECYCLE_HPP
#define ETUDIANTDEUXIEMECYCLE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "etudiant.hpp"

using namespace std;

class EtudiantDeuxiemeCycle : public Etudiant {
    string NomDisciplinePrincipale;

    public:
        // Constructeur
        EtudiantDeuxiemeCycle(int numEtu, string Nom, string Prenom, string Addr, string Telephone, string NomDiscipline)
            : Etudiant(numEtu, Nom, Prenom, Addr, Telephone)
        {
            NomDisciplinePrincipale = NomDiscipline;
        }

        string getNomDiscipline() const;

        void setNomDiscipline(string nom);

};

#endif
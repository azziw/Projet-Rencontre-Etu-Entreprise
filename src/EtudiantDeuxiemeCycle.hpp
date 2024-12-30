# include <iostream>
#include <string>
#include <vector>

#include "etudiant.hpp"

using namespace std;


class EtudiantDeuxiemeCycle : public Etudiant {
    string NomDisciplinePrincipale;

    public:
        // Constructeur
        EtudiantDeuxiemeCycle(string NomDiscipline){
            NomDisciplinePrincipale = NomDiscipline;
        }

};
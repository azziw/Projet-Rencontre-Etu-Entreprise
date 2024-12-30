# include <iostream>
#include <string>
#include <vector>

#include "etudiant.hpp"

using namespace std;


class EtudiantPremierCycle : public Etudiant {
    string SerieBac;
    string anneeObtentionBac;
    string lieuObtentionBac;

    public: 
        // Constructeur
        EtudiantPremierCycle(string Serie,string annee,string lieu){
            SerieBac = Serie;
            anneeObtentionBac = annee;
            lieuObtentionBac = lieu;
        };



};
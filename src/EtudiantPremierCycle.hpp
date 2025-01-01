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

        string getSerie() const;
        string getAnneeBac() const;
        string getLieuBac() const;

        void setSerie(string s);
        void setAnneeBac(string annee);
        void setLieuBac(string Lieu);

};
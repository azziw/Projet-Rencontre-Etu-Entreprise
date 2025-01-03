#ifndef ETUDIANTPREMIERCYCLE_HPP
#define ETUDIANTPREMIERCYCLE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Etudiant.hpp"

using namespace std;

class EtudiantPremierCycle : public Etudiant {
    string SerieBac;
    string anneeObtentionBac;
    string lieuObtentionBac;

    public: 
        EtudiantPremierCycle(int numEtu, string Nom, string Prenom, string Addr, string Telephone, InscriptionActuelle* diplome, string Serie, string annee, string lieu) 
            : Etudiant(numEtu, Nom, Prenom, Addr, Telephone, diplome)
        {
            SerieBac = Serie;
            anneeObtentionBac = annee;
            lieuObtentionBac = lieu;
        };

        string getSerie() const;
        string getAnneeBac() const;
        string getLieuBac() const;

        void Affiche() const;
        void setSerie(string s);
        void setAnneeBac(string annee);
        void setLieuBac(string Lieu);

};

#endif
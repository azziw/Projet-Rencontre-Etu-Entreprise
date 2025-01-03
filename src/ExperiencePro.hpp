#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Etudiant.hpp"
#include "Date.hpp"

class ExperiencePro {
    Date* dateDebut;
    Date* dateFin;
    string nomEntreprise;
    string fonctionOccupee;
    Etudiant* etudiant;

    public : 
        //Constructeur
        ExperiencePro(Date* deb, Date* fin, string nomEnt, string fonc, Etudiant* etu){
            dateDebut = deb;
            dateFin = fin;
            nomEntreprise = nomEnt;
            fonctionOccupee = fonc;
            etudiant = etu;
        }

        void Affiche() const;

        Date getDateDebut() const;
        Date getDateFin() const;
        string getNomEnt() const;
        string getFonction() const;
        Etudiant getEtudiant() const;

        void setDateDebut(Date* d);
        void setDateFin(Date* d);
        void setNomEnt(string nom);
        void setFonction(string fonc);
        void setEtudiant(Etudiant* etu);

};
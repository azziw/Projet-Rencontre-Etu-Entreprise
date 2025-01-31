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
        ExperiencePro(Date* deb, Date* fin, string nomEnt, string fonc){
            dateDebut = deb;
            dateFin = fin;
            nomEntreprise = nomEnt;
            fonctionOccupee = fonc;
        }

// ---- METHODES ----- //

        void Affiche() const;

// ---- GETTERS ---- //

        Date* getDateDebut() const;
        Date* getDateFin() const;
        string getNomEnt() const;
        string getFonction() const;
        Etudiant* getEtudiant() const;


// ---- SETTERS ---- //

        void setDateDebut(Date* d);
        void setDateFin(Date* d);
        void setNomEnt(string nom);
        void setFonction(string fonc);
        void setEtudiant(Etudiant* etu);

};
# include <iostream>
#include <string>
#include <vector>

using namespace std;

class ExperiencePro {
    date dateDebut;
    date dateFin;
    string nomEntreprise;
    string fonctionOccupee;
    Etudiant etudiant;

    public : 
        //Constructeur
        ExperiencePro(date deb, date fin, string nomEnt, string fonc,Etudiant etu){
            dateDebut = deb;
            dateFin = fin;
            nomEntreprise = nomEnt;
            fonctionOccupee = fonc;
            etudiant = etu;
        }

        // Ajout d'un etudiant 
        void addEtudiant(Etudiant etu);

        date getDateDebut() const;
        date getDateFin() const;
        string getNomEnt() const;
        string getFonction() const;
        Etudiant getEtudiant() const;

        void setDateDebut(date d);
        void setDateFin(date d);
        void setNomEnt(string nom);
        void setFonction(string fonc);
        void setEtudiant(Etudiant etu);




}
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



}
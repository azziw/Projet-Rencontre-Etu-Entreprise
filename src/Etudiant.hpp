# include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "InscriptionActuelle.hpp"
#include "ExperiencePro.hpp"
#include "Diplome.hpp"


class Etudiant {
    private : 
        int numeroEtudiant;
        string nom;
        string prenom;
        string adresse;
        string numeroTel;
        InscriptionActuelle* diplomeActuel;
        vector<ExperiencePro *> listeExperience;
        vector<RendezVous *> rendezVous;
        vector<Diplome *> listeDiplomes;

    public: 
        // Constructeur 
        Etudiant(int numEtu, string Nom, string Prenom, string Addr, string Telephone){
            numeroEtudiant = numEtu;
            nom = Nom;
            prenom = Prenom;
            adresse = Addr;
            numeroTel = Telephone;
        }

        // Ajout d'un Diplome 
        void addDiplome(Diplome D);

        // Ajout d'une experience
        void addExperience(ExperiencePro E);

        // Ajout d'un rendez vous
        void addRendezVous(RendezVous R);

        //getCV();


        int getNumeroEtudiant() const;
        string getNomEtudiant() const;
        string getPrenomEtudiant() const;
        string getAdresseEtudiant() const;
        string getNumeroTel() const;
        InscriptionActuelle getDiplomeActuel() const;

        void setNumeroEtudiant(int num);
        void setNomEtudiant(string Nom);
        void setPrenomEtudiant(string Prenom);
        void setAdresseEtudiant(string Adresse);
        void setNumeroTel(string tel);
        void setDiplomeActuel(InscriptionActuelle Inscription);

        

};

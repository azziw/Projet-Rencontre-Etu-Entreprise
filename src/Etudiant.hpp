#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Diplome.hpp"
#include "InscriptionActuelle.hpp"

//on fait des déclarations anticipées pour éviter des inclusions circulaires
class RendezVous;
class InscriptionActuelle;
class ExperiencePro;
class Diplome;
class Entreprise;
class Date;
class Heure;

class Etudiant {
    private : 
        int numeroEtudiant;
        string nom;
        string prenom;
        string adresse;
        string numeroTel;
        InscriptionActuelle* diplomeActuel;
        vector<ExperiencePro *> ensExperience;
        vector<RendezVous *> ensRendezVous;
        vector<Diplome *> ensDiplomes;

    public: 
        Etudiant(int numEtu, string Nom, string Prenom, string Addr, string Telephone){
            numeroEtudiant = numEtu;
            nom = Nom;
            prenom = Prenom;
            adresse = Addr;
            numeroTel = Telephone;
        }

        void addDiplome(Diplome* D);
        void addExperience(ExperiencePro* E);
        
        void AfficheRdv();
        RendezVous* checkDispo(RendezVous* rdv);
        void addRendezVous(RendezVous* R);
        void removeRendezVous(RendezVous* rdv, bool called = false);
        bool checkExistence(RendezVous* rdv);
        //getCV();

        int getNumeroEtudiant() const;
        string getNomEtudiant() const;
        string getPrenomEtudiant() const;
        string getAdresseEtudiant() const;
        string getNumeroTel() const;
        InscriptionActuelle getDiplomeActuel() const;

        void setRendezVous(Entreprise* etu, Date* date, Heure* heureDebut, Heure* heureFin);
        void setNumeroEtudiant(int num);
        void setNomEtudiant(string Nom);
        void setPrenomEtudiant(string Prenom);
        void setAdresseEtudiant(string Adresse);
        void setNumeroTel(string tel);
        void setDiplomeActuel(InscriptionActuelle* Inscription);
};

#endif
#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

#include <iostream>
#include <string>
#include <vector>

class RendezVous;
class Etudiant;
class Date;
class Heure;

using namespace std;

class Entreprise
{
    private:
        string nom;
        string adresse;
        string nomContact;
        string telephoneContact;
        vector<RendezVous *> ensRendezVous;

    public:
        Entreprise(string Nom, string Adresse, string NomC, string tel)
        {
            nom = Nom;
            adresse = Adresse;
            nomContact = NomC;
            telephoneContact = tel;
        }

// ---- METHODES ---- //

        void AfficheRdv();
        RendezVous* checkDispo(RendezVous* rdv);
        void addRendezVous(RendezVous* rdv);
        void removeRendezVous(RendezVous* rdv, bool call = false);
        bool checkExistence(RendezVous* rdv);

// ---- GETTERS ET SETTERS ---- //

    // GETTERS //
        string getNom() const;
        string getAdresse() const;
        string getNomContact() const;
        string getTelephoneContact() const;
        vector<RendezVous *> getRendezVous() const;

    // SETTERS //
        void setNom(string Nom);
        void setAdresse(string Adresse);
        void setNomContact(string NomContact);
        void setTelephoneContact(string telContact);
        void setRendezVous(Etudiant* etu, Date* date, Heure* heureDebut, Heure* heureFin);
        
};

#endif
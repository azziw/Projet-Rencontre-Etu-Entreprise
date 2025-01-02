#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

#include <iostream>

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

        string getNom() const;
        string getAdresse() const;
        string getNomContact() const;
        string getTelephoneContact() const;

        void setNom(string Nom);
        void setAdresse(string Adresse);
        void setNomContact(string NomContact);
        void setTelephoneContact(string telContact);
        
        void addRendezVous(RendezVous* rdv);
        void setRendezVous(Etudiant* etu, Date* date, Heure* heureDebut, Heure* heureFin);
        bool checkDispo(RendezVous* rdv);
};

#endif
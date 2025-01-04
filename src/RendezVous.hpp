#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include <iostream>

//on fait des déclarations anticipées pour éviter des inclusions circulaires entre etudiant.hpp et rendezVous.hpp
class Entreprise;
class Etudiant;
class Date;
class Heure;
class Rencontre;

using namespace std;

class RendezVous
{
    private:
        Date* date;
        Heure* heureDebut;
        Heure* heureFin;
        Etudiant* etudiant;
        Entreprise* entreprise;
        Rencontre* rencontre;

    public:

        RendezVous(Date* Date, Heure* HeureD, Heure* HeureF, Etudiant* etu, Entreprise* ent)
        {
            date = Date;
            heureDebut = HeureD;
            heureFin = HeureF;
            etudiant = etu;
            entreprise = ent;
        }

// ---- METHODES ---- //

        void Affiche();
        string toString();

// ---- GETTERS ET SETTERS ---- //

    // GETTERS //

        Date* getDate() const;
        Heure* getHeureDebut() const;
        Heure* getHeureFin() const;
        Etudiant* getEtudiant() const;
        Entreprise* getEntreprise() const;
        Rencontre* getRencontre() const;

    // SETTERS //

        void setDate(Date* Date);
        void setHeureDebut(Heure* HeureD);
        void setHeureFin(Heure* HeureF);
        void setEtudiant(Etudiant* etu);
        void setEntreprise(Entreprise* ent);
        void setRencontre(Rencontre* ren);

// ---- OPERATEURS ---- //

        bool operator<(const RendezVous& other) const;
};

#endif
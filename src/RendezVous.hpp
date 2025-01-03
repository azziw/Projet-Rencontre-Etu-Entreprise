#ifndef RENDEZVOUS_HPP
#define RENDEZVOUS_HPP

#include <iostream>

//on fait des déclarations anticipées pour éviter des inclusions circulaires entre etudiant.hpp et rendezVous.hpp
class Entreprise;
class Etudiant;
class Date;
class Heure;

using namespace std;

class RendezVous
{
    private:
        Date* date;
        Heure* heureDebut;
        Heure* heureFin;
        Etudiant* etudiant;
        Entreprise* entreprise;

    public:

        RendezVous(Date* Date, Heure* HeureD, Heure* HeureF, Etudiant* etu, Entreprise* ent)
        {
            date = Date;
            heureDebut = HeureD;
            heureFin = HeureF;
            etudiant = etu;
            entreprise = ent;
        }

        Date* getDate() const;
        Heure* getHeureDebut() const;
        Heure* getHeureFin() const;
        Etudiant* getEtudiant() const;
        Entreprise* getEntreprise() const;

        void setDate(Date* Date);
        void setHeureDebut(Heure* HeureD);
        void setHeureFin(Heure* HeureF);
        void setEtudiant(Etudiant* etu);
        void setEntreprise(Entreprise* ent);
        void Affiche();
        string toString();

        bool operator<(const RendezVous& other) const;
};

#endif
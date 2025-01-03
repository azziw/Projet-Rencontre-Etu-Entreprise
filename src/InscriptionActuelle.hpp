#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <iostream>

using namespace std;

#include "Diplome.hpp"
#include "Date.hpp"

class InscriptionActuelle
{
    private:
        Diplome* diplome;
        Date* datePremiereInscription;
        int numeroAnnee;

    public:
        InscriptionActuelle(Diplome* Diplome, Date* date, int annee)
        {
            diplome = Diplome;
            datePremiereInscription = date;
            numeroAnnee = annee;
        }

        Diplome getDiplome() const;
        Date getDate() const;
        int getAnnee() const;

        void setDiplome(Diplome* nouveauDiplome);
        void setDate(Date* date);
        void setAnnee(int annee);

        void setEtudiant(Etudiant* etu);

};

#endif
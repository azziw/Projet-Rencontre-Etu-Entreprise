#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <iostream>

using namespace std;

#include "Diplome.hpp"

class InscriptionActuelle
{
    private:
        Diplome diplome;
        tm datePremiereInscription;
        int numeroAnnee;

    public:
        InscriptionActuelle(Diplome Diplome, tm date, int annee)
        {
            diplome = Diplome;
            datePremiereInscription = date;
            numeroAnnee = annee;
        }

        Diplome getDiplome() const;
        tm getDate() const;
        int getAnnee() const;

        void setDiplome(Diplome nouveauDiplome);
        void setDate(tm date);
        void setAnnee(int annee);

};

#endif
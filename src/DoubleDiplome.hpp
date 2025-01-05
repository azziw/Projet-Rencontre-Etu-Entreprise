#ifndef DOUBLEDIPLOME_HPP
#define DOUBLEDIPLOME_HPP

#include <iostream>

using namespace std;

#include "Diplome.hpp"

class DoubleDiplome : public Diplome {

    private:
        Diplome* diplome1;
        Diplome* diplome2;

    public:
        //Construction d'un nouveau Diplome à partir de deux Diplomes
        DoubleDiplome(Diplome* D1, Diplome* D2) 
            : Diplome( // Appel au constructeur de Diplome 
                D1->getCode() + "-" + D2->getCode(), //on genère un code combine des deux codes des diplomes
                D1->getNom() + "-" + D2->getNom(), //on genère un nom combine des deux noms des diplomes
                D1->getDate(), 
                D1->getLieu()), 
            diplome1(D1), 
            diplome2(D2) 
        {}

// ---- METHODES ---- //

        void Affiche() const;

// ---- GETTERS ET SETTERS ---- //

    // GETTERS //
        Diplome* getDiplome1() const;
        Diplome* getDiplome2() const;

    // SETTERS //
        void setDiplome1(Diplome* D1);
        void setDiplome2(Diplome* D2);
};

#endif
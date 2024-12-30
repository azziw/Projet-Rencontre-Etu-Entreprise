#ifndef DOUBLEDIPLOME_HPP
#define DOUBLEDIPLOME_HPP

#include <iostream>

using namespace std;

#include "Diplome.hpp"


class DoubleDiplome : public Diplome {

    private:
        Diplome diplome1;
        Diplome diplome2;

    public:
        //Construction d'un nouveau Diplome
        DoubleDiplome(Diplome D1, Diplome D2) 
            : Diplome( // Appel au constructeur de Diplome 
                D1.getCode() + "-" + D2.getCode(), //Nouveau code combiné des deuxDiplomes
                D1.getNom() + "-" + D2.getNom(), //Nouveau nom pour le double Diplome
                D1.getDate(), 
                D1.getLieu()), 
            diplome1(D1), 
            diplome2(D2) 
        {}

        void afficher() const;
        Diplome getDiplome1() const;
        Diplome getDiplome2() const;

};

#endif
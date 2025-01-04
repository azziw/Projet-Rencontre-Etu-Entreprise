#include <iostream>

using namespace std;

#include "DoubleDiplome.hpp"

// METHODES //

void DoubleDiplome::afficher() const {
    cout << "Double Diplome:" << endl;
    Diplome::Affiche();
}

// GETTERS //

Diplome* DoubleDiplome::getDiplome1() const {
    return diplome1; 
}

Diplome* DoubleDiplome::getDiplome2() const {
     return diplome2; 
}


// SETTERS //

void DoubleDiplome::setDiplome1(Diplome* D1)
{
    diplome1 = D1;
    this->setCode(D1->getCode() + '-' + diplome2->getCode());
    this->setNom(D1->getNom() + "-" + diplome2->getNom());
    // On ne change pas la date où le lieu car ils restent les mêmes
}

void DoubleDiplome::setDiplome2(Diplome* D2)
{
    diplome2 = D2;
    this->setCode(diplome1->getCode() + '-' + D2->getCode());
    this->setNom(diplome1->getNom() + "-" + D2->getNom());
    // On ne change pas la date où le lieu car ils restent les mêmes
}
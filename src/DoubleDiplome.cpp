#include <iostream>

using namespace std;

#include "DoubleDiplome.hpp"

void DoubleDiplome::afficher() const {
    cout << "Double Diplome:" << endl;
    Diplome::afficher();
}

Diplome DoubleDiplome::getDiplome1() const {
    return diplome1; 
}

Diplome DoubleDiplome::getDiplome2() const {
     return diplome2; 
}
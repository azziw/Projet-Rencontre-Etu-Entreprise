#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

#include <iostream>

#include "RendezVous.hpp"

using namespace std;

class Entreprise
{
    private:
        string nom;
        string adresse;
        string nomContact;
        string telephoneContact;
        vector<RendezVous> rendezVous;
};

#endif
#include <iostream>
#include <iomanip> // utilisé pour setw et setfill
#include <sstream> // utilisé pour stringstream

using namespace std;

#include "Heure.hpp"

string Heure::toString() const {
    stringstream s; // utilisé pour concatener les chaines correctement
    s << setw(2) << setfill('0') << heures << "h" << setw(2) << setfill('0') << minutes;
    return s.str();
}

int Heure::tempsTotal() const
{
    //temps total en minutes
    return heures*60 + minutes;
}

void Heure::Affiche() const
{
    //setw définit la largeur minimale a afficher a 2 caractères et setfill définit le remplissage comme des 0
    // si la valeur pour l'heure ou les minutes inscrite est 8 par exemple cela deviendra 08.
    cout << setw(2) << setfill('0') << heures << ":" << setw(2) << setfill('0') << minutes << endl;
}

bool Heure::operator< (const Heure& heure2) const 
{
    return tempsTotal() < heure2.tempsTotal();
}

bool Heure::operator== (const Heure& heure2) const {
return heures == heure2.heures && minutes == heure2.minutes;
}
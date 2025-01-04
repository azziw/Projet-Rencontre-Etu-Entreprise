#include <iostream>
#include <iomanip> // utilisé pour setw et setfill
#include <sstream> // utilisé pour stringstream

using namespace std;

#include "Date.hpp"

// ------ METHODES ------ //

string Date::toString() const 
{
    stringstream s; // utilisé pour concatener les chaines correctement
    s << setw(2) << setfill('0') << jour << "/" << setw(2) << setfill('0') << mois << "/" << setw(2) << setfill('0') << annee;
    return s.str();
}

void Date::Affiche() const
{
    //setw définit la largeur minimale a afficher a 2 caractères et setfill définit le remplissage comme des 0
    //si la valeur pour le jour ou le mois inscrite est 8 par exemple cela deviendra 08.
    cout << setw(2) << setfill('0') << jour << "/" << setw(2) << setfill('0') << mois << "/" << annee << endl;
}

// ------ GETTERS ET SETTERS ------ //

int Date::getAnnee() const
{
    return annee;
}

int Date::getMois() const
{
    return mois;
}

int Date::getJour() const
{
    return jour;
}

void Date::setAnnee(int A)
{
    annee = A;
}

void Date::setMois(int M)
{
    mois = M;
}

void Date::setJour(int J)
{
    jour = J;
}


// ------ OPERATEURS ------ //

bool Date::operator< (const Date& date2) const 
{
    if(annee == date2.annee)
    {
        if(mois == date2.mois)
        {
            return jour < date2.jour;
        }
        else
        {
            return mois < date2.mois;
        }
    }
    else
    {
        return annee < date2.annee;
    }
}

bool Date::operator== (const Date& date2) const 
{
    return annee == date2.annee && mois == date2.mois && jour == date2.jour;
}

bool Date::operator!=(const Date& date2) const 
{
    return !(*this == date2); 
}
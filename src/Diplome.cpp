#include <iostream>

using namespace std;

#include "Diplome.hpp"
#include "Date.hpp"


// ---- METHODES ---- //

//On gère le cas où le constructeur n'a pas de Date (diplôme en cours)
void Diplome::Affiche() const {

    cout << "Diplome: " << nomNational << ", Code: " << Code << ", Lieu: " << lieuObtention;
    //Si on ne gère pas de date, on affiche que le diplôme est en cours.
    if (dateObtention != nullptr) {
        cout << ", Date d'obtention: " << dateObtention->toString() << endl;
    } else {
        cout << ", Diplome en cours." << endl;
    }
}

// -- GETTERS -- //

string Diplome::getCode() const {
    return Code;
};

string Diplome::getNom() const {
    return nomNational;
};

Date* Diplome::getDate() const {
    return dateObtention;
};

string Diplome::getLieu() const {
    return lieuObtention;
};

// -- SETTERS -- //

void Diplome::setCode(string code) {
    Code = code;
}

void Diplome::setNom(string nom) {
    nomNational = nom;
}

void Diplome::setDate(Date* date) {
    dateObtention = date;
}

void Diplome::setLieu(string lieu) {
    lieuObtention = lieu;
}
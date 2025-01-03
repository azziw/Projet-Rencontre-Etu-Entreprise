#include <iostream>

using namespace std;

#include "Diplome.hpp"
#include "Date.hpp"

void Diplome::Affiche() const {

    cout << "Diplome: " << nomNational << ", Code: " << Code << ", Date: " << dateObtention->toString() << ", Lieu: " << lieuObtention << endl;
}

string Diplome::getCode() const {
    return Code;
};

string Diplome::getNom() const {
    return nomNational;
};

Date Diplome::getDate() const {
    return *dateObtention;
};

string Diplome::getLieu() const {
    return lieuObtention;
};

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
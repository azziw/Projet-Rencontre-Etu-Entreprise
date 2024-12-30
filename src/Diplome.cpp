#include <iostream>

using namespace std;

#include "Diplome.hpp"


void Diplome::afficher() const {

    char dateStr[11];  // Format "YYYY-MM-DD"
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &dateObtention);

    cout << "Diplome: " << nomNational << ", Code: " << Code << ", Date: " << dateStr << ", Lieu: " << lieuObtention << endl;
}

string Diplome::getCode() const {
    return Code;
};

string Diplome::getNom() const {
    return nomNational;
};

tm Diplome::getDate() const {
    return dateObtention;
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

void Diplome::setDate(tm date) {
    dateObtention = date;
}

void Diplome::setLieu(string lieu) {
    lieuObtention = lieu;
}
#include <iostream>
#include <ctime>
#include "Diplome.hpp"
#include "DoubleDiplome.hpp"

int main() {
    // Création de deux diplômes
    tm date = {};
    date.tm_year = 120;  // 2020
    date.tm_mon = 5;     // Juin
    date.tm_mday = 15;

    Diplome d1("D001", "Math", date, "Paris");
    Diplome d2("D002", "Informatique", date, "Lyon");

    // Création d'un DoubleDiplome
    DoubleDiplome dd(d1, d2);

    // Affichage des diplômes
    dd.afficher();

    //dziodhqziodoiqh

    //dzidzioq

    return 0;
}

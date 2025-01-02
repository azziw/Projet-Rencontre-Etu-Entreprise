#include <iostream>
#include <ctime>
// #include "Diplome.hpp"
// #include "DoubleDiplome.hpp"
// #include "RendezVous.hpp"
#include "Date.cpp"
#include "Heure.cpp"
#include "Entreprise.hpp"

int main() {
    // Création de deux diplômes
    // tm date = {};
    // date.tm_year = 120;  // 2020
    // date.tm_mon = 5;     // Juin
    // date.tm_mday = 15;

    // Diplome d1("D001", "Math", date, "Paris");
    // Diplome d2("D002", "Informatique", date, "Lyon");

    // Etudiant e1(2, "azzi", "william", "adresse", "0606060606");
    Entreprise ent1("entreprise", "adresse", "contact", "06060606");

    Date date1(2022, 01, 3);
    Heure h1(1, 2);

    h1.Affiche();
    cout<< h1.tempsTotal() << endl;



    // RendezVous r1(date, date, date, &e1, &ent1);

    // r1.Affiche();

    // Création d'un DoubleDiplome
    // DoubleDiplome dd(d1, d2);

    // Affichage des diplômes
    // dd.afficher();

    //bonjour
    //dziodhqziodoiqh
    //dzidzioq

    //dzhqiodhqiodhqio

    //au revoir

    return 0;
}

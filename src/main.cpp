#include <iostream>
#include <ctime>
// #include "Diplome.hpp"
// #include "DoubleDiplome.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"

int main() {
    // Création de deux diplômes
    // Diplome d1("D001", "Math", date, "Paris");
    // Diplome d2("D002", "Informatique", date, "Lyon");

    Date date1(2022, 8, 2);
    Date date2(2023, 3 ,3);
    Heure heureDebut(10, 9);
    Heure heureFin(9,40);

    Etudiant etu1(2, "azzi", "william", "adresse", "0606060606");
    Entreprise ent1("entreprise", "adresse", "contact", "06060606");

    // Date date1(2022, 01, 3);
    Heure h1(1, 2);

    RendezVous r1(&date1, &heureDebut, &heureFin, &etu1, &ent1);

    h1.Affiche();
    cout<< h1.tempsTotal() << endl;

    ent1.addRendezVous(&r1);
    
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

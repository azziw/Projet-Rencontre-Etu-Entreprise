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
    Heure heureDebut(9, 30);
    Heure heureFin(10,00);
    Heure heureDebut2(9,45);
    Heure heureFin2(11,00);

    Etudiant etu1(2, "azzi", "william", "adresse", "0606060606");
    Etudiant etu2(23, "azzou", "zoao", "dzd", "0606060606");
    Entreprise ent1("entreprise", "adresse", "contact", "06060606");
    Entreprise ent2("auchan", "adresse", "contact", "06060606");

    // Date date1(2022, 01, 3);
    Heure h1(1, 2);

    RendezVous r1(&date1, &heureDebut, &heureFin, &etu1, &ent1);
    RendezVous r2(&date2, &heureDebut, &heureFin, &etu1, &ent1);


    ent1.addRendezVous(&r1);
    ent1.AfficheRdv(); 

    // ent1.addRendezVous(&r2); 

    // ent1.AfficheRdv();  
    etu1.AfficheRdv();

    ent1.removeRendezVous(&r1);

    etu1.AfficheRdv();
    ent1.AfficheRdv();
    
    etu1.addRendezVous(&r2);
    etu1.AfficheRdv(); 
    ent1.AfficheRdv(); 

    ent1.setRendezVous(&etu2, &date1, &heureDebut2, &heureFin2);

    etu1.AfficheRdv(); 
    ent1.AfficheRdv(); 

    etu2.AfficheRdv();

    
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

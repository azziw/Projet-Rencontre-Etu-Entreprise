#include <iostream>
#include <ctime>
// #include "Diplome.hpp"
// #include "DoubleDiplome.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "EtudiantPremierCycle.hpp"
#include "EtudiantDeuxiemeCycle.hpp"
#include "ExperiencePro.hpp"

int main() {
    // Création de deux diplômes
    // Diplome d1("D001", "Math", date, "Paris");
    // Diplome d2("D002", "Informatique", date, "Lyon");

    Date date1(2, 8, 2019);
    Date date2(3, 8 ,2019); 
    Heure heureDebut(9, 30);
    Heure heureFin(10,00);
    Heure heureDebut2(8,00);
    Heure heureFin2(9,00);

    Diplome d1("D001", "Licence", &date1, "Limoges");
    Diplome d2("D003", "BUT", &date2, "Limoges");
    InscriptionActuelle ins1(&d1, &date1, 3);
    ExperiencePro ep1(&date1, &date2, "Thales", "Ingénieur");

    Etudiant etu1(2, "azzi", "william", "94 chemin romain, Bagnols-sur-cèze", "0606060606", nullptr);
    Etudiant etu2(23, "azzou", "zoao", "dzd", "0606060606", &ins1);
    Entreprise ent1("Thales", "18 rue du pigeon", "jean", "06060606");
    Entreprise ent2("auchan", "adresse", "contact", "06060606");

    EtudiantPremierCycle etu4(34890, "Jean", "Jean", "94 chemin romain", "0606060606", &ins1, "BAC S", "2021", "Lyon");
    EtudiantDeuxiemeCycle etu3(34890, "Jean", "Michel", "94 chemin romain", "0606060606", &ins1, "Informatique");

    // Date date1(2022, 01, 3);
    Heure h1(1, 2);

    RendezVous r1(&date1, &heureDebut, &heureFin, &etu1, &ent1);
    RendezVous r2(&date2, &heureDebut2, &heureFin2, &etu1, &ent1);

    etu4.Affiche();
    cout << endl;
    etu4.addExperience(&ep1);
    etu4.addDiplome(&d1);
    etu4.addDiplome(&d2);
    etu4.AfficheCv();


    etu4.setRendezVous(&ent1, &date1, &heureDebut, &heureFin);
    etu4.setRendezVous(&ent2, &date2, &heureDebut2, &heureFin2);
    etu4.AfficheRdv();


    // ent1.addRendezVous(&r1);
    // ent1.AfficheRdv(); 

    // // ent1.addRendezVous(&r2); 

    // // ent1.AfficheRdv();  
    // etu1.AfficheRdv();

    // ent1.removeRendezVous(&r1);

    // etu1.AfficheRdv();
    // ent1.AfficheRdv();
    
    // etu1.addRendezVous(&r2);
    // etu1.AfficheRdv(); 
    // ent1.AfficheRdv(); 

    // ent1.setRendezVous(&etu2, &date1, &heureDebut2, &heureFin2);

    // etu1.AfficheRdv(); 
    // ent1.AfficheRdv(); 

    // etu2.AfficheRdv();

    
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

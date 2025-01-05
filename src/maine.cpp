#include <iostream>
#include <ctime>

#include "Diplome.hpp"
#include "DoubleDiplome.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "EtudiantPremierCycle.hpp"
#include "EtudiantDeuxiemeCycle.hpp"
#include "ExperiencePro.hpp"
#include "GestionEntreprise.hpp"

int main() {

    // ---- CREATION DE DIPLOMES ---- //

    //Dates des diplômes
    Date dateD1(2, 8, 2021);
    Date dateD2(3, 8, 2023);
    Date dateD3(4, 8, 2020);
    Date dateD3bis(4, 8, 2018);

    //- DIPLOMES ACQUIS -//
    Diplome d1("D1", "Licence", &dateD1, "Paris");
    Diplome d2("D2", "BUT", &dateD2, "Limoges");
    Diplome d3("D3", "Master", &dateD3, "Lyon");
    Diplome d3bis("D3bis", "Licence", &dateD3bis, "Lyon");

    //- DIPLOMES EN COURS -//
    //Diplômes sans dates car en cours (Diplomes des inscriptions actuelles)
    Diplome d4("D4", "Master", "Paris"); 
    Diplome d5("D5", "Licence", "Limoges");
    Diplome d6("D6", "Doctorat", "Lyon");
    //Double diplome
    Diplome d7("D7", "Licence Droit", "Lyon");
    Diplome d8("D8", "Licence Eco", "Lyon");
    DoubleDiplome dd1(&d7, &d8);

    Date dateI1(2, 9, 2022);
    Date dateI2(3, 8 ,2024); 
    Date dateI3(4, 8, 2021);
    Date dateI4(4, 8, 2021);

    InscriptionActuelle ins1(&d4, &dateI1, 3);
    InscriptionActuelle ins2(&d5, &dateI2, 1);
    InscriptionActuelle ins3(&d6, &dateI3, 2);
    InscriptionActuelle ins4(&dd1, &dateI4, 1);


    // ---- CREATION D'ETUDIANTS ---- //

    //On crée 3 étudiants
    Etudiant etu1(1, "Jean", "Jean", "11 rue de la rue, Paris", "0606060606",  &ins1); //création d'un étudiant simple pour le test
    EtudiantPremierCycle etu2(2, "Claude", "Bernard", "12 rue qui existe, Limoges", "0707070707", &ins2, "BAC S", "2019", "Limoges");
    EtudiantDeuxiemeCycle etu3(3, "Jean", "Michel", "13 rue sympa, Lyon", "0808080808", &ins3, "Informatique");

    EtudiantPremierCycle etu4(4, "Bernard", "Claude", "14 rue inexistante, Lyon", "0808080808", &ins4, "BAC ES", "2019", "Lyon");

    // ---- CREATION D'EXPERIENCES ---- //

    //dates des expériences
    Date dateDebutExp1(16, 4, 2019);
    Date dateFinExp1(27, 6, 2019);

    //expériences
    ExperiencePro ep1(&dateDebutExp1, &dateFinExp1, "Thales", "développeur");   

    // CREATION D'ENTREPRISES

    GestionEntreprise gestion; //gestion des entreprises (ajout et affichage des rendez-vous de toutes les entreprises) 

    Entreprise ent1("Thales", "18 rue du pigeon", "Yves", "0404040404");
    Entreprise ent2("Auchan", "19 rue saucisse", "DarkVador", "0909090909");

    // ---- CREATION DE RENDEZ-VOUS ---- //

    //Création de dates
    Date date1(2, 4, 2025);
    Date date2(2, 4 ,2025); 
    Date date3(4, 4, 2025);

    //Création d'heures de début et de fin
    Heure heureDebut(9,30);
    Heure heureDebut2(8,00);
    Heure heureDebut3(8,00);

    Heure heureFin(10,00);
    Heure heureFin2(9,00);
    Heure heureFin3(9,00);

    RendezVous r1(&date1, &heureDebut, &heureFin, &etu1, &ent1);
    RendezVous r2(&date1, &heureDebut2, &heureFin2, &etu1, &ent1);

    // ----- TESTS ----- //

    //Ajout des diplômes actuels aux étudiants
    etu1.setDiplomeActuel(&ins1); //Inscrit en Master
    etu2.setDiplomeActuel(&ins2); //Inscrit en Licence
    etu3.setDiplomeActuel(&ins3); //Inscrit en Doctorat
    etu4.setDiplomeActuel(&ins4); //Inscrit en Double Licence

    //Ajout des diplômes possédés aux étudiants
    etu1.addDiplome(&d1); //Avant son master il a fait une licence
    etu2.addDiplome(&d2); //Avant sa licence il a fait un BUT
    etu3.addDiplome(&d3bis); //Avant son doctorat il a fait une licence et un master
    etu3.addDiplome(&d3);
    // l'etudiant 4 n'a que son bac avant son double diplome (ajouté dans le constructeur)

    etu2.addExperience(&ep1); //Ajout d'une expérience à l'étudiant 2

    etu2.AfficheCv(); //Affichage du CV de l'étudiant 2
    
    etu2.addRendezVous(&r1); //Ajout d'un rendez-vous à l'étudiant 2
    etu2.addRendezVous(&r2); //Ajout d'un rendez-vous à l'étudiant 2

    etu2.AfficheRdv(); //Affichage des rendez-vous de l'étudiant 2

    gestion.AfficheRdv(); //Affichage des rendez-vous de toutes les entreprises

    return 0;
}




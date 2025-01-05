#include <iostream>
#include <vector>

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
#include "GestionEtudiant.hpp"


using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Ajouter un étudiant" << endl;
    cout << "2. Rechercher un étudiant" << endl;
    cout << "3. Afficher les etudiants participants aux rencontres" << endl;
    cout << "4. Afficher les rendez-vous d'un étudiant" << endl;
    cout << "5. Ajouter une entreprise" << endl;
    cout << "6. Ajouter un rendez-vous à une entreprise" << endl;
    cout << "7. Supprimer un rendez-vous d'une entreprise" << endl;
    cout << "8. Afficher les rendez-vous d'une entreprise" << endl;
    cout << "9. Quitter" << endl;
    cout << "Choisissez une option: ";
}

int main() {
    GestionEtudiant gestionEtudiant;
    GestionEntreprise gestionEntreprise;
    int choix;


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
    RendezVous r2(&date1, &heureDebut2, &heureFin2, &etu2, &ent1);

    gestionEntreprise.addEntreprise(&ent1);
    gestionEntreprise.addEntreprise(&ent2);

    etu1.addRendezVous(&r1);
    etu2.addRendezVous(&r2);

    gestionEtudiant.addEtudiant(&etu1);
    gestionEtudiant.addEtudiant(&etu2);
    gestionEtudiant.addEtudiant(&etu3);
    gestionEtudiant.addEtudiant(&etu4);

    do {
        displayMenu();
        cin >> choix;

        switch (choix) {
            case 1: {
                // Ajouter un étudiant
                string nom, prenom, adresse, numeroTel, nomDiplomeActuel, codeDiplomeActuel, lieuDiplomeActuel;
                int numeroEtudiant, jour, mois, annee, anneeActuelle;
                cout << "Nom: ";
                cin >> nom;
                cout << "Prenom: ";
                cin >> prenom;
                cout << "Numero d'etudiant: ";
                cin >> numeroEtudiant;
                cout << "Adresse: ";
                cin >> adresse;
                cout << "Numero de telephone: ";
                cin >> numeroTel;
                cout << "Nom du diplome actuel: ";
                cin >> nomDiplomeActuel;
                cout << "Code du diplome actuel: ";
                cin >> codeDiplomeActuel;
                cout << "Lieu d'obtention du diplome actuel: ";
                cin >> lieuDiplomeActuel;
                cout << "Date de premiere inscription: ";
                cout << "Jour: ";
                cin >> jour;
                cout << "Mois: ";
                cin >> mois;
                cout << "Annee: ";
                cin >> annee;
                cout << "Annee actuelle du diplome: ";
                cin >> anneeActuelle;

                InscriptionActuelle* inscriptionActuelle = new InscriptionActuelle(new Diplome(nomDiplomeActuel, codeDiplomeActuel, nullptr, lieuDiplomeActuel), new Date(jour, mois, annee), anneeActuelle);
                gestionEtudiant.addEtudiant(new Etudiant(numeroEtudiant, nom, prenom, adresse, numeroTel, inscriptionActuelle));
                break;
            }
            case 2: 
            {
                int numeroEtudiant;

                cout << "Entrez le numéro de l'étudiant a chercher : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {   
                    etudiant->Affiche();
                }
                else
                {
                    cout << "Aucun étudiant trouvé avec le numéro " << numeroEtudiant << ". Veuillez Réessayer."<< endl;
                }
                break;
            }
            // Afficher les etudiants
            case 3:
            {
                gestionEtudiant.AfficheEtudiants();
                cout << endl;
                break;
            }
            case 4:
            {
                int numeroEtudiant;

                cout << "Entrez le numéro de l'étudiant dont vous voulez afficher les rendez-vous : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    etudiant->AfficheRdv();
                }
                else
                {
                    cout << endl;
                    cout << "Aucun étudiant trouvé avec le numéro " << numeroEtudiant << ". Veuillez Réessayer."<< endl;
                }
                cout << endl;
                break;
            }
            case 9:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Option invalide." << endl;
                break;
        }
    } while (choix != 9);

    return 0;
}
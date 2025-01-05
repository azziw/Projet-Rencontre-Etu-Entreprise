#include <iostream>
#include <vector>
#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "RendezVous.hpp"
#include "GestionEntreprise.hpp"
#include "GestionEtudiant.hpp"


using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Ajouter un étudiant" << endl;
    cout << "2. Ajouter un rendez-vous à un étudiant" << endl;
    cout << "3. Supprimer un rendez-vous d'un étudiant" << endl;
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
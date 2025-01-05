#include <iostream>
#include <vector>
#include <sstream>

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

void nettoieEcran() {
    #ifdef _WIN32
        system("cls"); // windows
    #else
        system("clear"); // linux/mac
    #endif
}

void RetourMenu() {
    char choix;
    cout << "\nSouhaitez-vous revenir au menu principal ? ( o / n ) : ";
    cin >> choix;

    if (choix == 'n' || choix == 'N') {
        cout << "Au revoir !" << endl;
        exit(0); // Quitte le programme
    }
}

void displayMenu() {
    cout << "======================================" << endl;
    cout << "              MENU PRINCIPAL          " << endl;
    cout << "======================================" << endl;

    // ------- ETUDIANTS ------- //

    cout << "\n----- GESTION DES eTUDIANTS -----" << endl;
    cout << "1. Ajouter un etudiant" << endl;
    cout << "2. Rechercher un etudiant" << endl;
    cout << "3. Planifier un rendez-vous à un etudiant" << endl;
    cout << "4. Ajouter un dîplome à un etudiant" << endl;
    cout << "5. Ajouter une experience à un etudiant" << endl;

    cout << "6. Enlever un etudiant" << endl;
    cout << "7. Enlever le rendez-vous d'un etudiant" << endl;
    cout << "8. Enlever un dîplome à un etudiant" << endl;
    cout << "9. Enlever une experience à un etudiant" << endl;

    cout << "10. Afficher les etudiants participants aux rencontres" << endl;
    cout << "11. Afficher les rendez-vous d'un etudiant" << endl;
    cout << "12. Afficher les dîplomes d'un etudiant" << endl;
    cout << "13. Afficher les experiences d'un etudiant" << endl;
    cout << "14. Afficher le CV d'un Etudiant" << endl;

    // ------- ENTREPRISES ------- //

    cout << "\n----- GESTION DES ENTREPRISES -----" << endl;
    cout << "15. Ajouter une entreprise" << endl;
    cout << "16. Rechercher une entreprise" << endl;
    cout << "17. Planifier un rendez-vous à une entreprise" << endl;

    cout << "18. Supprimer un rendez-vous d'une entreprise" << endl;

    cout << "19. Afficher les entreprises participants aux rencontres" << endl;
    cout << "20. Afficher les rendez-vous d'une entreprise" << endl;

    // ------- RENCONTRES ------- //
    cout << "\n----- RENCONTRE -----" << endl;
    cout << "21. Afficher tout les rendez-vous de la rencontre" << endl;

    cout << "22. Supprimer tout les rendez-vous de la rencontre" << endl;

    cout << "30. Quitter" << endl;
    cout << endl;
    cout << "Choisissez une option: ";
}

Date* createDate() {
    string date;
    int day, month, year;
    cin >> date;

    stringstream ss(date);
    char separateur; // le caractère qui separe jours mois et annees (/)

    ss >> day >> separateur >> month >> separateur >> year;

    return new Date(day, month, year);
}

Heure* createHeure() {
    string heure;
    int heures, minutes;
    cin >> heure;

    stringstream ss(heure);
    char separateur; // le caractère qui separe jours mois et annees (/)

    ss >> heures >> separateur >> minutes;

    return new Heure(heures, minutes);
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

    //On cree 3 etudiants
    Etudiant etu1(1, "Jean", "Jean", "11 rue de la rue, Paris", "0606060606",  &ins1); //creation d'un etudiant simple pour le test
    EtudiantPremierCycle etu2(2, "Claude", "Bernard", "12 rue qui existe, Limoges", "0707070707", &ins2, "BAC S", "2019", "Limoges");
    EtudiantDeuxiemeCycle etu3(3, "Jean", "Michel", "13 rue sympa, Lyon", "0808080808", &ins3, "Informatique");

    EtudiantPremierCycle etu4(4, "Bernard", "Claude", "14 rue inexistante, Lyon", "0808080808", &ins4, "BAC ES", "2019", "Lyon");

    // ---- CREATION D'EXPERIENCES ---- //

    //dates des experiences
    Date dateDebutExp1(16, 4, 2019);
    Date dateFinExp1(27, 6, 2019);

    //experiences
    ExperiencePro ep1(&dateDebutExp1, &dateFinExp1, "Thales", "developpeur");   

    // CREATION D'ENTREPRISES

    Entreprise ent1("Thales", "18 rue du pigeon", "Yves", "0404040404");
    Entreprise ent2("Auchan", "19 rue saucisse", "DarkVador", "0909090909");

    // ---- CREATION DE RENDEZ-VOUS ---- //

    //Creation de dates
    Date date1(2, 4, 2025);
    Date date2(2, 4 ,2025); 
    Date date3(4, 4, 2025);

    //Creation d'heures de debut et de fin
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

    etu1.addExperience(&ep1);

    gestionEtudiant.addEtudiant(&etu1);
    gestionEtudiant.addEtudiant(&etu2);
    gestionEtudiant.addEtudiant(&etu3);
    gestionEtudiant.addEtudiant(&etu4);

    do {
        displayMenu();
        cin >> choix;

        switch (choix) {
            // ---- AJOUTER UN ETUDIANT ---- //
            case 1: {
                nettoieEcran();
                gestionEtudiant.AfficheRappelEtudiant();

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
                RetourMenu();
                break;
            }
            // ---- CHERCHER UN ETUDIANT ---- //
            case 2: 
            {
                nettoieEcran();
                gestionEtudiant.AfficheRappelEtudiant();

                int numeroEtudiant;

                cout << "Entrez le numero de l'etudiant a chercher : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {   
                    etudiant->Affiche();
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                RetourMenu();
                break;
            }
            case 3:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                string nomEntreprise, date, heureDebut, heureFin;
                cout << "Entrez le numero de l'etudiant pour qui vous voulez planifier un rendez-vous : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    gestionEntreprise.AfficheEntreprises();
                    cout << "Entrez le nom de l'entreprise avec qui vous voulez planifier un rendez-vous : ";
                    cin >> nomEntreprise;
                    Entreprise* entreprise = gestionEntreprise.getEntreprise(nomEntreprise);
                    if(entreprise != nullptr)
                    {
                        cout << "Entrez la date du rdv (jj/mm/aaaa): ";
                        Date* D = createDate();
                        cout << "Entrez l'heure de debut du rendez-vous (H:M): ";
                        Heure* H = createHeure();
                        cout << "Entrez l'heure de fin du rendez-vous (H:M): ";
                        Heure* H2 = createHeure();

                        etudiant->setRendezVous(entreprise, D, H, H2);
                    }
                    else
                    {
                        cout << "Aucune entreprise trouvee avec le nom " << nomEntreprise << ". Veuillez Reessayer.";
                    }
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                RetourMenu();
                break;
            }
            case 4:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                string nomDiplome, codeDiplome, lieuDiplome;
                cout << "Entrez le numero de l'etudiant pour qui vous voulez ajouter un diplome : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    cout << "Entrez le nom du diplome (Licence,Master,...): ";
                    cin >> nomDiplome;
                    cout << "Entrez le code du diplome (DX): ";
                    cin >> codeDiplome;
                    cout << "Entrez le lieu d'obtention du diplome : ";
                    cin >> lieuDiplome;
                    cout << "Entrez la date d'obtention du diplome (jj/mm/aaaa): ";
                    Date* date = createDate();
                    etudiant->addDiplome(new Diplome(nomDiplome, codeDiplome, date, lieuDiplome));
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                RetourMenu();
                break;
            }
            case 5:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                string dateDebut, dateFin, nomEntreprise, poste;
                cout << "Entrez le numero de l'etudiant pour qui vous voulez ajouter une experience : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    cout << "Entrez le nom de l'entreprise : ";
                    cin >> nomEntreprise;
                    cout << "Entrez le poste occupe : ";
                    cin >> poste;
                    cout << "Entrez la date de debut de l'experience (jj/mm/aaaa): ";
                    Date* dateDebut = createDate();
                    cout << "Entrez la date de fin de l'experience (jj/mm/aaaa): ";
                    Date* dateFin = createDate();
                    etudiant->addExperience(new ExperiencePro(dateDebut, dateFin, nomEntreprise, poste));
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                RetourMenu();
                break;
            }
            // ENLEVER UN ETUDIANT
            case 6:
            {
                nettoieEcran();

                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();
                cout << "Entrez le numero de l'etudiant à enlever : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    gestionEntreprise.removeRendezVousEtudiant(etudiant);
                    gestionEtudiant.removeEtudiant(etudiant);
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;
                RetourMenu();
                break;
            }
            //ENLEVER RENDEZ-VOUS ETUDIANT
            case 7:
            {
                nettoieEcran();
                int numeroEtudiant;
                string nomEntreprise;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez enlever un rendez-vous : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant->getRendezVous().empty())
                {
                    cout << "Aucun rendez-vous n'est planifie pour l'etudiant " << etudiant->getNomEtudiant() << ". Veuillez Reessayer."<< endl;
                    RetourMenu();
                    break;
                }
                if(etudiant != nullptr)
                {
                    etudiant->AfficheRdv();
                    cout << "Entrez l'entreprise avec laquelle vous souhaitez retirer un rendez-vous : ";
                    cin >> nomEntreprise;
                    cout << "Entrez la date du rendez-vous (jj/mm/aaaa): ";
                    Date* date = createDate();
                    cout << "Entrez l'heure de debut du rendez-vous (H:M): ";
                    Heure* heureDebut = createHeure();
                    cout << "Entrez l'heure de fin du rendez-vous (H:M): ";
                    Heure* heureFin = createHeure();

                    RendezVous* dispo = etudiant->checkDispo(new RendezVous(date, heureDebut, heureFin, etudiant, gestionEntreprise.getEntreprise(nomEntreprise)));
                    bool existe = true ? dispo != nullptr : false;
                    if(existe)
                    {
                        vector<RendezVous *> listeRdv = etudiant->getRendezVous();
                        for (auto& rdv : listeRdv)
                        {
                            if(rdv->getEntreprise()->getNom() == nomEntreprise && rdv->getDate()->toString() == date->toString() && rdv->getHeureDebut()->toString() == heureDebut->toString() && rdv->getHeureFin()->toString() == heureFin->toString())
                            {
                                etudiant->removeRendezVous(rdv);
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Aucun rendez-vous trouve.. Verifiez les informations saisies"<< endl;
                    }
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;
                RetourMenu();
                break;
            }
            case 8:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez enlever un diplome : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant->getDiplomes().empty())
                {
                    cout << "Aucun diplôme n'est enregistre pour l'etudiant " << etudiant->getNomEtudiant() << ". Veuillez Reessayer."<< endl;
                    RetourMenu();
                    break;
                }
                if(etudiant != nullptr)
                {
                    etudiant->AfficheDiplomes();

                    string codeDiplome;
                    cout << "Entrez le code du diplome à enlever : ";
                    cin >> codeDiplome;

                    for(auto& diplome : etudiant->getDiplomes())
                    {
                        if(diplome->getCode() == codeDiplome)
                        {
                            etudiant->removeDiplome(diplome);
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;

                RetourMenu();
                break;
            }
            case 9:
            {
                nettoieEcran();
                int numeroEtudiant;
                string fonction, nomEntreprise;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez enlever une experience : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant->getExperiences().empty())
                {
                    cout << "Aucune experience n'est enregistree pour l'etudiant " << etudiant->getNomEtudiant() << ". Veuillez Reessayer.";
                     RetourMenu();
                    break;
                }
                if(etudiant != nullptr)
                {
                    etudiant->AfficheExperiences();

                    cout << "Entrez le nom de l'entreprise de l'experience à enlever : ";
                    cin >> nomEntreprise;
                    cout << "Entrez la fonction occupee lors de l'experience : ";
                    cin >> fonction;
                    cout << "Entrez la date de debut de l'experience :";
                    Date* dateDebut = createDate();
                    cout << "Entrez la date de fin de l'experience :";
                    Date* dateFin = createDate();

                    for(auto& experience : etudiant->getExperiences())
                    {
                        if(experience->getNomEnt() == nomEntreprise && experience->getFonction() == fonction && experience->getDateDebut()->toString() == dateDebut->toString() && experience->getDateFin()->toString() == dateFin->toString())
                        {
                            etudiant->removeExperience(experience);
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;

                RetourMenu();
                break;
            }
            // Afficher les etudiants
            case 10:
            {
                nettoieEcran();
                gestionEtudiant.AfficheEtudiants();
                cout << endl;
                RetourMenu();
                break;
            }
            //AFFICHE RDV
            case 11:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez afficher les rendez-vous : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    etudiant->AfficheRdv();
                }
                else
                {
                    cout << endl;
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;
                RetourMenu();
                break;
            }
            case 12:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez afficher les diplomes : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    etudiant->AfficheDiplomes();
                }
                else
                {
                    cout << endl;
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;

                RetourMenu();
                break;
            }
            case 13:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez afficher les experiences : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    etudiant->AfficheExperiences();
                }
                else
                {
                    cout << endl;
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;

                RetourMenu();
                break;
            }
            case 14:
            {
                nettoieEcran();
                int numeroEtudiant;

                gestionEtudiant.AfficheRappelEtudiant();

                cout << "Entrez le numero de l'etudiant dont vous voulez afficher le CV : ";
                cin >> numeroEtudiant;
                Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                if(etudiant != nullptr)
                {
                    etudiant->AfficheCv();
                }
                else
                {
                    cout << endl;
                    cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer."<< endl;
                }
                cout << endl;

                RetourMenu();
                break;
            }
            case 15:
            {
                nettoieEcran();
                gestionEntreprise.AfficheEntreprises();

                string nom, adresse, nomContact, numeroTel;

                cout << "Nom de l'entreprise: ";
                cin >> nom;
                cout << "Adresse de l'entreprise: ";
                cin >> adresse;
                cout << "Nom du contact: ";
                cin >> nomContact;
                cout << "Numero de telephone: ";
                cin >> numeroTel;
                gestionEntreprise.addEntreprise(new Entreprise(nom, adresse, nomContact, numeroTel));

                RetourMenu();
                break;
            }
            case 16:
            {
                nettoieEcran();
                gestionEntreprise.AfficheEntreprises();
                string nom;

                cout << "Entrez le nom de l'entreprise a chercher : ";
                cin >> nom;
                Entreprise* entreprise = gestionEntreprise.getEntreprise(nom);
                if(entreprise != nullptr)
                {
                    cout << "Entreprise trouvee : " << entreprise->getNom() << endl;
                }
                else
                {
                    cout << "Aucune entreprise trouvee avec le nom " << nom << ". Veuillez Reessayer."<< endl;
                }
                
                RetourMenu();
                break;
            }
            case 17:
            {
                nettoieEcran();
                string nomEntreprise, date, heureDebut, heureFin;
                int numeroEtudiant;

                gestionEntreprise.AfficheEntreprises();

                cout << "Entrez le nom de l'entreprise pour qui vous voulez planifier un rendez-vous : ";
                cin >> nomEntreprise;
                Entreprise* entreprise = gestionEntreprise.getEntreprise(nomEntreprise);
                if(entreprise != nullptr)
                {
                    gestionEtudiant.AfficheRappelEtudiant();
                    cout << "Entrez le numero de l'etudiant avec qui vous voulez planifier un rendez-vous : ";
                    cin >> numeroEtudiant;
                    Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                    if(etudiant != nullptr)
                    {
                        cout << "Entrez la date du rdv (jj/mm/aaaa): ";
                        Date* D = createDate();
                        cout << "Entrez l'heure de debut du rendez-vous (H:M): ";
                        Heure* H = createHeure();
                        cout << "Entrez l'heure de fin du rendez-vous (H:M): ";
                        Heure* H2 = createHeure();
                        entreprise->setRendezVous(etudiant, D, H, H2);
                    }
                    else
                    {
                        cout << "Aucun etudiant trouve avec le numero " << numeroEtudiant << ". Veuillez Reessayer.";
                    }
                }
                else
                {
                    cout << "Aucune entreprise trouvee avec le nom " << nomEntreprise << ". Veuillez Reessayer.";
                }

                RetourMenu();
                break;
            }
            case 18:
            {
                nettoieEcran();
                string nomEntreprise, date, heureDebut, heureFin;
                int numeroEtudiant;

                gestionEntreprise.AfficheEntreprises();

                cout << "Entrez le nom de l'entreprise pour qui vous voulez enlever un rendez-vous : ";
                cin >> nomEntreprise;
                Entreprise* entreprise = gestionEntreprise.getEntreprise(nomEntreprise);
                if(entreprise != nullptr)
                {
                    if(entreprise->getRendezVous().empty())
                    {
                        cout << "Aucun rendez-vous n'est planifie pour l'entreprise " << entreprise->getNom() << ". Veuillez Reessayer."<< endl;
                        RetourMenu();
                        break;
                    }
                    entreprise->AfficheRdv();
                    cout << endl;
                    gestionEtudiant.AfficheRappelEtudiant();

                    cout << "Entrez le numero de l'etudiant avec qui vous voulez enlever un rendez-vous : ";
                    cin >> numeroEtudiant;
                    cout << "Entrez la date du rendez-vous (jj/mm/aaaa): ";
                    Date* D = createDate();
                    cout << "Entrez l'heure de debut du rendez-vous (H:M): ";
                    Heure* H = createHeure();
                    cout << "Entrez l'heure de fin du rendez-vous (H:M): ";
                    Heure* H2 = createHeure();
                    Etudiant* etudiant = gestionEtudiant.getEtudiant(numeroEtudiant);
                    RendezVous* dispo = entreprise->checkDispo(new RendezVous(D, H, H2, etudiant, entreprise));
                    bool existe = true ? dispo != nullptr : false;
                    if(existe)
                    {
                        vector<RendezVous *> listeRdv = entreprise->getRendezVous();
                        for (auto& rdv : listeRdv)
                        {
                            if(rdv->getEtudiant()->getNumeroEtudiant() == etudiant->getNumeroEtudiant() && rdv->getDate()->toString() == D->toString() && rdv->getHeureDebut()->toString() == H->toString() && rdv->getHeureFin()->toString() == H2->toString())
                            {
                                entreprise->removeRendezVous(rdv);
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Aucun rendez-vous trouve.. Verifiez les informations saisies"<< endl;
                    }
                }
                else
                {
                    cout << "Aucune entreprise trouvee avec le nom " << nomEntreprise << ". Veuillez Reessayer.";
                }

                RetourMenu();
                break;
            }
            case 19:
            {
                nettoieEcran();
                gestionEntreprise.AfficheEntreprises();
                cout << endl;

                RetourMenu();
                break;
            }
            case 20:
            {
                nettoieEcran();
                string nomEntreprise;

                gestionEntreprise.AfficheEntreprises();

                cout << "Entrez le nom de l'entreprise dont vous voulez afficher les rendez-vous : ";
                cin >> nomEntreprise;
                Entreprise* entreprise = gestionEntreprise.getEntreprise(nomEntreprise);
                if(entreprise != nullptr)
                {
                    entreprise->AfficheRdv();
                }
                else
                {
                    cout << "Aucune entreprise trouvee avec le nom " << nomEntreprise << ". Veuillez Reessayer.";
                }
                
                RetourMenu();
                break;
            }
            case 21:
            {
                nettoieEcran();
                gestionEntreprise.AfficheRdv();
                cout << endl;
                gestionEtudiant.AfficheRdv();
                cout << endl;

                RetourMenu();
                break;
            }
            //SUPPRIMER TOUT LES RDV DE LA RENCONTRE
            case 22:
            {
                nettoieEcran();
                gestionEntreprise.removeRendezVous();
                gestionEtudiant.removeRendezVous();
                cout << endl;
                cout << "\033[4mTous les rendez-vous ont ete supprimes.\033[0m" << endl;
                cout << endl;

                RetourMenu();
                break;
            }
            case 30:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Option invalide." << endl;
                break;
        }
    } while (choix != 30);

    return 0;
}
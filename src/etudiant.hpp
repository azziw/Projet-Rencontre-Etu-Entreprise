# include <iostream>
#include <string>
#include <vector>

using namespace std;

class Etudiant {
    int numeroEtudiant;
    string nom;
    string prenom;
    string adresse;
    string numeroTel;
    InscriptionActuelle diplomeActuel;
    vector<ExperiencePro> listeExperience;
    vector<RendezVous> rendezVous;
    vector<Diplome> listeDiplomes;

    public: 
        // Constructeur 
        Etudiant(int numEtu, string Nom, string Prenom, string Addr, string Telephone){
            numeroEtudiant = numEtu;
            nom = Nom;
            prenom = Prenom;
            adresse = Addr;
            numeroTel = Telephone;
        }

        // Ajout d'un Diplome 
        void addDiplome(Diplome D);

        // Ajout d'une experience
        void addExperience(ExperiencePro E);

        // Ajout d'un rendez vous
        void addRendezVous(RendezVous R);

        getCV();



};
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Etudiant.hpp"
#include "ExperiencePro.hpp"
#include "RendezVous.hpp"
#include "Date.hpp"
#include "Heure.hpp"
#include "Entreprise.hpp"

using namespace std;

// ---- METHODES ---- //


// Permet de verifier si un rendez-vous est disponible à l'insertion
RendezVous* Etudiant::checkDispo(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        //Si il existe deja un rendez-vous le même jour
        if(*(*iT)->getDate() == *rdv->getDate())
        {
            //Alors je regarde si le rendez-vous est au milieu du creneau d'un rendez-vous existant
            
            //Si le rendez-vous est pendant un autre rendez-vous
            if (*(*iT)->getHeureDebut() < *rdv->getHeureFin() && *rdv->getHeureDebut() < *(*iT)->getHeureFin()) 
            {
                return *iT;
            }
            //Si le rendez-vous que j'ajoute est a la même heure qu'un existant
            // on suppose que les rendez-vous peuvent commencer à la même heure que lorsque l'un des rendez-vous se termine (ex: 10h-11h et 11h-12h)
            if (*(*iT)->getHeureDebut() == *rdv->getHeureFin()) 
            {
                return *iT;
            }
        }
    }
    //si il n'y a pas de problème, le rendez-vous est disponible
    return nullptr;
}

// ajoute un rendez-vous à l'etudiant et à l'entreprise correspondante.
void Etudiant::addRendezVous(RendezVous* rdv)
{
    RendezVous* conflitEtu = checkDispo(rdv); //On regarde si il y a un conflit avec les rendez-vous de l'etudiant

    Entreprise* entrepriseConcerne = rdv->getEntreprise();
    RendezVous* conflitEnt = entrepriseConcerne->checkDispo(rdv); // On regarde si il y a un conflit avec l'entreprise concernee

    cout << endl;

    //Si il n'y a pas de conflit pour l'etudiant
    if(conflitEtu == nullptr)
    {
        //Si il n'y a pas de conflit pour l'entreprise concernee
        if(conflitEnt == nullptr)
        {
            cout << "Creneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
            entrepriseConcerne->addRendezVous(rdv);
        }
        //Si il n'y a pas de confl it pour l'etudiant mais qu'il y en a un pour l'entreprise
        else
        {
            cout << "Creneau Disponible, ajout du rendez-vous entre : " << rdv->toString() << " pour " << nom << endl;
            ensRendezVous.push_back(rdv);
        }
    }
    //Si il y a un conflit pour l'etudiant
    else
    {
        cerr << "Impossible d'ajouter ce rendez-vous, le creneau du " << rdv->getDate()->toString() << " de " <<
        rdv->getHeureDebut()->toString() << " à " << rdv->getHeureFin()->toString() << " n'est pas disponible." << endl <<
        "Celui-ci est en conflit avec le rdv de: " << conflitEtu->toString() << endl << //erreur on affiche que le creneau n'est pas dispo
        "Veuillez Reessayer!" << endl;
    }
}

// Verifie si un rendez-vous existe dejà //
bool Etudiant::checkExistence(RendezVous* rdv)
{
    vector<RendezVous*>::iterator iT;

    for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
    {
        if((*iT) == rdv)
        {
            return true;
        }
    }
    return false;
}


// Permet d'enlever un rendez-vous existant 
void Etudiant::removeRendezVous(RendezVous* rdv, bool called)
{
    cout << endl;

    Entreprise* entrepriseConcerne = rdv->getEntreprise();

    RendezVous* conflitEtu = checkDispo(rdv); //On regarde si il y a un conflit avec les rendez-vous de l'etudiant
    bool exist = checkExistence(rdv); //permet de verifier si le rendez-vous existe dans la liste de rendez-vous

    //si il n'existe pas, c'est qu'on essaie de supprier un rendez-vous qui n'as jamais ete ajoute.
    if(!exist)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", celui-ci n'existe pas pour " << nom << endl;
        return;
    }

    //Si on trouve ne trouve pas le rendez-vous
    if(conflitEtu == nullptr)
    {
        cerr << "Impossible de supprimer le rdv entre " << rdv->toString() << ", il n'est pas programme pour " << nom << endl; 
    }
    //On trouve le rendez-vous
    else
    {
        vector<RendezVous*>::iterator iT;

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            if((*iT) == rdv)
            {
                ensRendezVous.erase(iT);
                cout << "Le rendez-vous " << rdv->toString() << " a ete supprime de " << nom << " avec succès." << endl;
                if(called != true)
                {
                    entrepriseConcerne->removeRendezVous(rdv, true); // On enlève aussi le rendez-vous pour l'entreprise
                }
                return;
            }
        }
    }
}

void Etudiant::removeDiplome(Diplome* diplome)
{
    vector<Diplome*>::iterator iT;

    for(iT = ensDiplomes.begin(); iT != ensDiplomes.end(); iT++)
    {
        if((*iT) == diplome)
        {
            ensDiplomes.erase(iT);
            cout << "Le diplôme " << diplome->getNom() << " a ete supprime de " << nom << " avec succès." << endl;
            return;
        }
    }
    cerr << "Impossible de supprimer le diplôme " << diplome->getNom() << ", celui-ci n'existe pas pour " << nom << endl;
}

void Etudiant::removeExperience(ExperiencePro* experience)
{
    vector<ExperiencePro*>::iterator iT;

    for(iT = ensExperience.begin(); iT != ensExperience.end(); iT++)
    {
        if((*iT) == experience)
        {
            ensExperience.erase(iT);
            cout << "L'experience " << experience->getNomEnt() << " a ete supprimee de " << nom << " avec succès." << endl;
            return;
        }
    }
    cerr << "Impossible de supprimer l'experience " << experience->getNomEnt() << ", celle-ci n'existe pas pour " << nom << endl;
}

// Affiche les rendez-vous d'un etudiant tries par date
void Etudiant::AfficheRdv()
{
    vector<RendezVous *>::iterator iT;

    cout << endl;

    //Si l'ensemble est vide on ne le parcours pas.
    if (ensRendezVous.empty())
    {
        cout << "Aucun rendez-vous n'est planifie pour l'etudiant " << nom << endl;
    }
    else
    {
        if(nom == prenom) //en cas d'homonyme on affiche aussi le numero d'etudiant
        {
            cout << "L'etudiant "  << nom << " " << prenom << " n° " << numeroEtudiant << " a les rendez-vous suivants:" << endl;
        }
        else
        {
            cout << "L'etudiant " << nom << " " << prenom << " a les rendez-vous suivants:" << endl;
        }

        sort(ensRendezVous.begin(), ensRendezVous.end(), [](RendezVous* a, RendezVous* b) {
            return *a < *b;
        });

        for(iT = ensRendezVous.begin(); iT != ensRendezVous.end(); iT++)
        {
            (*iT)->Affiche();
        }
    }
}

// Affiche l'etudiant 
void Etudiant::Affiche() const
{
    cout << "(n°" << numeroEtudiant << "): " << nom << " " << prenom << " habite " <<
        adresse << " et peut être joint au " << numeroTel << endl;

    cout << "Il est inscrit en " << diplomeActuel->getDiplome()->getNom() << " depuis le " <<
        diplomeActuel->getDate()->toString() << " et est en " << diplomeActuel->getAnnee() << " annee." << endl;
}

// Affiche les diplômes d'un etudiant
void Etudiant::AfficheDiplomes() const
{
    if(ensDiplomes.empty())
    {
        cout << "Aucun diplôme n'est enregistre pour cet etudiant." << endl;
    }
    else
    {
        cout << "Diplômes obtenus par " << nom << " " << prenom << ":" << endl;
        for (Diplome* diplome : ensDiplomes)
        {
            diplome->Affiche();
        }
    }
    cout << endl;
}

// Affiche les experiences d'un etudiant
void Etudiant::AfficheExperiences() const
{
    if(ensExperience.empty())
    {
        cout << "Aucune experience professionnelle n'est enregistree pour cet etudiant." << endl;
    }
    else
    {
        for (ExperiencePro* experience : ensExperience)
        {
            experience->Affiche();
        }
    }
    cout << endl;
}

// Permet d'afficher le CV d'un etudiant.
void Etudiant::AfficheCv() const
{
    cout << endl;
    cout << "\033[4mCV de " << nom << " " << prenom << " etudiant n°" << numeroEtudiant << ":\033[0m" << endl;
    cout << endl;
    cout << "\033[4mInformations Administratives:\033[0m" << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Numero de telephone: " << numeroTel << endl;
    cout << endl;
    cout << "\033[4mDiplômes Obtenus:\033[0m" << endl;
    this->AfficheDiplomes();
    cout << endl;
    cout << "\033[4mExperiences Professionnelles:\033[0m" << endl;
    this->AfficheExperiences();
    cout << endl;
}


// Ajout d'un diplome 
void Etudiant::addDiplome(Diplome* D){
    ensDiplomes.push_back(D);
}

// Ajout d'une Experience
void Etudiant::addExperience(ExperiencePro* E){
    ensExperience.push_back(E);
}


// ---- GETTERS ---- //

int Etudiant::getNumeroEtudiant() const {
    return numeroEtudiant;
}

string Etudiant::getNomEtudiant() const {
    return nom;
}

string Etudiant::getPrenomEtudiant() const{
    return prenom;
}

string Etudiant::getAdresseEtudiant() const{
    return adresse;
}

string Etudiant::getNumeroTel() const{
    return numeroTel;
}

InscriptionActuelle* Etudiant::getDiplomeActuel() const{
    return diplomeActuel;
}

vector<RendezVous*> Etudiant::getRendezVous(){
    return ensRendezVous;
}

vector<Diplome*> Etudiant::getDiplomes(){
    return ensDiplomes;
}

vector<ExperiencePro*> Etudiant::getExperiences(){
    return ensExperience;
}

// ---- SETTERS ---- //

// Permet de planifier un rendez-vous avec une entreprise
void Etudiant::setRendezVous(Entreprise* ent, Date* date, Heure* heureDebut, Heure* heureFin)
{
    RendezVous* rdv = new RendezVous(date, heureDebut, heureFin, this, ent);

    cout << endl;

    //on ajoute le rendez-vous via la methode addRendezVous
    addRendezVous(rdv);
}


void Etudiant::setNumeroEtudiant(int num){
    numeroEtudiant = num;
}

void Etudiant::setNomEtudiant(string Nom){
    nom = Nom;
}

void Etudiant::setPrenomEtudiant(string Prenom){
    prenom = Prenom;
}

void Etudiant::setAdresseEtudiant(string Adresse){
    adresse = Adresse;
}

void Etudiant::setNumeroTel(string tel){
    numeroTel = tel;
}

void Etudiant::setDiplomeActuel(InscriptionActuelle* Inscription){
    diplomeActuel = Inscription;
}

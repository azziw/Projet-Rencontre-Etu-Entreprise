#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#include "GestionEtudiant.hpp"
#include "RendezVous.hpp"
#include "Heure.hpp"


// ---- METHODES ---- //

void GestionEtudiant::addEtudiant(Etudiant* etu)
{
    ensEtudiant.push_back(etu);
}

Etudiant* GestionEtudiant::getEtudiant(int numEtu)
{
    for (auto& etu : ensEtudiant) {
        if (etu->getNumeroEtudiant() == numEtu) {
            return etu;
        }
    }
    return nullptr;
}

void GestionEtudiant::AfficheEtudiants()
{
    if (ensEtudiant.empty()) {
        cout << endl;
        cout << "Aucun étudiant n'a été ajouté." << endl;
        return;
    }
    else
    {
        sort(ensEtudiant.begin(), ensEtudiant.end(), [](Etudiant* a, Etudiant* b) {
        if (a->getNomEtudiant() == b->getNomEtudiant()) {
            return a->getPrenomEtudiant() < b->getPrenomEtudiant();
        }
        return a->getNomEtudiant() < b->getNomEtudiant();
        });

        cout << "\033[4mLes étudiants sont :\033[0m" << endl;
        for (auto& etu : ensEtudiant) {
            etu->Affiche();
        }
    }
    }

void GestionEtudiant::AfficheRdv()
{
    sort(ensEtudiant.begin(), ensEtudiant.end(), [](Etudiant* a, Etudiant* b) {
        if (a->getNomEtudiant() == b->getNomEtudiant()) {
            return a->getPrenomEtudiant() < b->getPrenomEtudiant();
        }
        return a->getNomEtudiant() < b->getNomEtudiant();
    });

    // Affichage des rendez-vous pour chaque entreprise
    cout << "\033[4mLes entreprises et leurs rendez-vous sont :\033[0m" << endl;
    for (auto& etu : ensEtudiant) {
        cout << "\nEtudiant : \033[4m" << etu->getNomEtudiant() << " " << etu->getPrenomEtudiant() << "\033[0m" << endl;
        etu->AfficheRdv();
    }
}
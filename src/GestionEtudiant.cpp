#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#include "GestionEtudiant.hpp"
#include "RendezVous.hpp"
#include "Heure.hpp"


// ---- METHODES ---- //

void GestionEtudiant::removeRendezVous()
{
    vector<Etudiant*>::iterator iT;

    for (iT = ensEtudiant.begin(); iT != ensEtudiant.end(); iT++)
    {
        vector<RendezVous*> rdv = (*iT)->getRendezVous();
        vector<RendezVous*>::iterator iT2;

        if(!rdv.empty())
        {
            for (iT2 = rdv.begin(); iT2 != rdv.end(); iT2++)
            {
                (*iT)->removeRendezVous(*iT2);
                return;
            }
        }
    }
}

void GestionEtudiant::addEtudiant(Etudiant* etu)
{
    ensEtudiant.push_back(etu);
}

void GestionEtudiant::removeEtudiant(Etudiant* etu)
{
    vector<Etudiant*>::iterator iT;

    for (iT = ensEtudiant.begin(); iT != ensEtudiant.end(); iT++)
    {
        if (*iT == etu)
        {
            ensEtudiant.erase(iT);
            return;
        }
    }
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

        cout << "\033[4mLes étudiants sont (triés alphabétiquement):\033[0m" << endl;
        cout << endl;
        for (auto& etu : ensEtudiant) {
            etu->Affiche();
            cout << endl;
        }
    }
}

void GestionEtudiant::AfficheRappelEtudiant()
{
    cout << "Rappel des étudiants: (triés par n° etu)" << endl;
    if(ensEtudiant.empty())
    {
        cout << "Aucun étudiant n'a été ajouté." << endl;
    }
    else
    {
        sort(ensEtudiant.begin(), ensEtudiant.end(), [](Etudiant* a, Etudiant* b) {
            if (a->getNumeroEtudiant() == b->getNumeroEtudiant()) {
                if(a->getNomEtudiant() == b->getNomEtudiant())
                {
                    return a->getPrenomEtudiant() < b->getPrenomEtudiant();
                }
                return a->getNomEtudiant() < b->getNomEtudiant();
            }
            return a->getNumeroEtudiant() < b->getNumeroEtudiant();
        });
        for(auto etu : ensEtudiant)
        {
            cout << etu->getNumeroEtudiant() << " : " << etu->getNomEtudiant() << " " << etu->getPrenomEtudiant() << endl;
        }
    }
    cout << endl;
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
    cout << "\033[4mLes étudiants et leurs rendez-vous sont :\033[0m" << endl;
    for (auto& etu : ensEtudiant) {
        cout << "\nEtudiant : \033[4m" << etu->getNomEtudiant() << " " << etu->getPrenomEtudiant() << "\033[0m" << endl;
        etu->AfficheRdv();
    }
}

vector<Etudiant*> GestionEtudiant::getEnsEtudiant() const
{
    return ensEtudiant;
}
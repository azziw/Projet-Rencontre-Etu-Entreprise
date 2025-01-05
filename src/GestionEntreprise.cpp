#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#include "GestionEntreprise.hpp"
#include "RendezVous.hpp"
#include "Heure.hpp"


// ---- METHODES ---- //

void GestionEntreprise::removeRendezVous()
{
    vector<Entreprise*>::iterator iT;

    for (iT = ensEntreprises.begin(); iT != ensEntreprises.end(); iT++)
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

void GestionEntreprise::removeRendezVousEtudiant(Etudiant* etu)
{
    vector<Entreprise*>::iterator iT;

    for (iT = ensEntreprises.begin(); iT != ensEntreprises.end(); iT++)
    {
        vector<RendezVous*> rdv = (*iT)->getRendezVous();
        vector<RendezVous*>::iterator iT2;

        if(!rdv.empty())
        {
            for (iT2 = rdv.begin(); iT2 != rdv.end(); iT2++)
            {
                if ((*iT2)->getEtudiant() == etu)
                {
                    (*iT)->removeRendezVous(*iT2);
                    return;
                }
            }
        }
    }
}

void GestionEntreprise::addEntreprise(Entreprise* ent)
{
    ensEntreprises.push_back(ent);
}

Entreprise* GestionEntreprise::getEntreprise(string nom)
{
    for (auto& ent : ensEntreprises) {
        if (ent->getNom() == nom) {
            return ent;
        }
    }
    return nullptr;
}

void GestionEntreprise::AfficheEntreprises()
{
    if (ensEntreprises.empty()) {
        cout << endl;
        cout << "Aucune entreprise n'a été ajoutée." << endl;
        return;
    }
    else
    {
        sort(ensEntreprises.begin(), ensEntreprises.end(), [](Entreprise* a, Entreprise* b) {
            return a->getNom() < b->getNom();
        });

        cout << "\033[4mLes entreprises sont :\033[0m" << endl;
        for (auto& ent : ensEntreprises) {
            cout << " - " << ent->getNom() << endl;
        }
    }
}

void GestionEntreprise::AfficheRdv()
{
    sort(ensEntreprises.begin(), ensEntreprises.end(), [](Entreprise* a, Entreprise* b) {
        return a->getNom() < b->getNom();
    });

    // Affichage des rendez-vous pour chaque entreprise
    cout << "\033[4mLes entreprises et leurs rendez-vous sont :\033[0m" << endl;
    for (auto& ent : ensEntreprises) {
        cout << "\nEntreprise : \033[4m" << ent->getNom() << "\033[0m" << endl;
        ent->AfficheRdv();
    }
}
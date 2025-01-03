#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#include "GestionEntreprise.hpp"
#include "RendezVous.hpp"
#include "Heure.hpp"

void GestionEntreprise::addEntreprise(Entreprise* ent)
{
    ensEntreprises.push_back(ent);
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
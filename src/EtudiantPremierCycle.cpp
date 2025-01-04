#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "EtudiantPremierCycle.hpp"

// ---- METHODES ---- //

void EtudiantPremierCycle::Affiche() const 
{
    Etudiant::Affiche(); cout << "Il a précédemment obtenu un " << SerieBac << " en " << anneeObtentionBac << " à " << lieuObtentionBac << endl;
}

// ---- GETTERS ---- //

string EtudiantPremierCycle::getSerie() const{
    return SerieBac;
}

string EtudiantPremierCycle::getAnneeBac() const{
    return anneeObtentionBac;
}

string EtudiantPremierCycle::getLieuBac() const{
    return lieuObtentionBac;
}

// ---- SETTERS ---- //

void EtudiantPremierCycle::setSerie(string s){
    SerieBac = s;
}

void EtudiantPremierCycle::setAnneeBac(string annee){
    anneeObtentionBac = annee;
}

void EtudiantPremierCycle::setLieuBac(string Lieu){
    lieuObtentionBac = Lieu;
}

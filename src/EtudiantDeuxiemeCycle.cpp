# include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "EtudiantDeuxiemeCycle.hpp"

// ----- METHODES ----- //

void EtudiantDeuxiemeCycle::Affiche() const 
{
    Etudiant::Affiche(); cout << "La discipline principale de son diplôme de " << diplomeActuel->getDiplome()->getNom() << " est: " << NomDisciplinePrincipale << endl;
}

// ----- GETTERS ----- //

string EtudiantDeuxiemeCycle::getNomDiscipline() const{
    return NomDisciplinePrincipale;
}

// ----- SETTERS ----- //

void EtudiantDeuxiemeCycle::setNomDiscipline(string nom){
    NomDisciplinePrincipale = nom;
}
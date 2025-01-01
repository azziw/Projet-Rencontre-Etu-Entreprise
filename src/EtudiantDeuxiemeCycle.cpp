# include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "EtudiantDeuxiemeCycle.hpp"

string EtudiantDeuxiemeCycle::getNomDiscipline() const{
    return NomDisciplinePrincipale;
}

void EtudiantDeuxiemeCycle::setNomDiscipline(string nom){
    NomDisciplinePrincipale = nom;
}
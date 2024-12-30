#ifndef DIPLOME_HPP
#define DIPLOME_HPP

#include <iostream>

using namespace std;

class Diplome {
    private:
        string Code;
        string nomNational;
        tm dateObtention;
        string lieuObtention;

    public:
        Diplome(string code, string nom, tm date, string lieu)
        {
            Code = code;
            nomNational = nom;
            dateObtention = date;
            lieuObtention = lieu;
        }


        virtual void afficher() const;
        string getCode() const;
        string getNom() const;
        tm getDate() const;
        string getLieu() const;

        void setCode(string code);
        void setNom(string nom);
        void setDate(tm date);
        void setLieu(string lieu);
};

#endif
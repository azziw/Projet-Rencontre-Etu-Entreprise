#ifndef DIPLOME_HPP
#define DIPLOME_HPP

#include <iostream>

using namespace std;

class Date;

class Diplome {
    private:
        string Code;
        string nomNational;
        Date* dateObtention;
        string lieuObtention;

    public:
        Diplome(string code, string nom, Date* date, string lieu)
        {
            Code = code;
            nomNational = nom;
            dateObtention = date;
            lieuObtention = lieu;
        }


// ---- METHODES ---- //

        virtual void Affiche() const;

// ---- GETTERS ET SETTERS ---- //

    // GETTERS //
        string getCode() const;
        string getNom() const;
        Date* getDate() const;
        string getLieu() const;

    // SETTERS //
        void setCode(string code);
        void setNom(string nom);
        void setDate(Date* date);
        void setLieu(string lieu);
};

#endif
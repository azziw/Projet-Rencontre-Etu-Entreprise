#ifndef DATE_HPP
#define DATE_HPP

class Date {
    private:
        int annee;
        int mois;
        int jour;

    public:

        //Lors de la création d'une date on s'assure que les jours et les mois sont correctements instanciés sinon on renvoie une erreur
        Date(int J, int M, int A)
        {
            if (M < 1 || M > 12 || J < 1 || J > 31) {
            throw invalid_argument("Date invalide");
            }
            jour = J;
            mois = M;
            annee = A;
        }

// ---- METHODES ---- //

        string toString() const;
        void Affiche() const;

// ---- GETTERS ET SETTERS ---- //

    // GETTERS //
        int getAnnee() const;
        int getMois() const;
        int getJour() const;

    // SETTERS //
        void setAnnee(int A);
        void setMois(int M);
        void setJour(int J);

// ---- OPERATEURS ---- //

        bool operator< (const Date& date2) const;
        bool operator== (const Date& date2) const;
        bool operator!= (const Date& date2) const;
};

#endif
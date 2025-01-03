#ifndef DATE_HPP
#define DATE_HPP

class Date {
    private:
        int annee;
        int mois;
        int jour;

    public:
        Date(int J, int M, int A)
        {
            if (M < 1 || M > 12 || J < 1 || J > 31) {
            throw invalid_argument("Date invalide");
            }
            jour = J;
            mois = M;
            annee = A;
        }
        string toString() const;
        void Affiche() const;
        bool operator< (const Date& date2) const;
        bool operator== (const Date& date2) const;
        bool operator!= (const Date& date2) const;
};

#endif
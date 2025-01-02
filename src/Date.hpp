#ifndef DATE_HPP
#define DATE_HPP

class Date {
    private:
        int annee;
        int mois;
        int jour;

    public:
        Date(int A, int M, int J)
        {
            if (M < 1 || M > 12 || J < 1 || J > 31) {
            throw invalid_argument("Date invalide");
            }
            annee = A;
            mois = M;
            jour = J;
        }
        string toString() const;
        void Affiche() const;
        bool operator< (const Date& date2) const;
        bool operator== (const Date& date2) const;
};

#endif
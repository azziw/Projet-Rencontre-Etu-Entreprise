#ifndef DATE_HPP
#define DATE_HPP

class Date {
    private:
        int annee;
        int mois;
        int jour;

    public:
        Date(int A, int M, int J);
        void Affiche() const;
        bool operator< (const Date& date2) const;
        bool operator== (const Date& date2) const;
};

#endif
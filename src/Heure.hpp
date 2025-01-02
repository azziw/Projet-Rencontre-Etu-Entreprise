#ifndef HEURE_HPP
#define HEURE_HPP

class Heure {
    private:
        int heures;
        int minutes;

    public:
        Heure(int H, int M);
        void Affiche() const;
        bool operator< (const Heure& heure2) const;
        bool operator== (const Heure& heure2) const;
};

#endif

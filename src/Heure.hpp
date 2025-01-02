#ifndef HEURE_HPP
#define HEURE_HPP

class Heure {
    private:
        int heures;
        int minutes;

    public:
        Heure(int H, int M)
        {
            if (H < 0 || H > 24 || M < 0 || M > 60) {
            throw invalid_argument("Heure ou minutes invalides");
            }
            heures = H;
            minutes = M;
        }
        
        string toString() const;
        void Affiche() const;
        int tempsTotal() const;
        bool operator< (const Heure& heure2) const;
        bool operator== (const Heure& heure2) const;
};

#endif

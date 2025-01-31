#ifndef HEURE_HPP
#define HEURE_HPP

class Heure {
    private:
        int heures;
        int minutes;

    public:
        Heure(int H, int M)
        {
            if (H < 0 || H > 23 || M < 0 || M > 59) {
            throw invalid_argument("Heure ou minutes invalides");
            }
            heures = H;
            minutes = M;
        }

// ----- METHODES ----- //
        
        string toString() const;
        void Affiche() const;
        int tempsTotal() const;

// ----- GETTERS ET SETTERS ---- //
    
    // GETTERS //
        int getHeures() const;
        int getMinutes() const;

    // SETTERS //
        void setHeures(int H);
        void setMinutes(int M);
        
// ---- OPERATEURS ---- //

        bool operator< (const Heure& heure2) const;
        bool operator== (const Heure& heure2) const;
        bool operator!= (const Heure& heure2) const;
};

#endif

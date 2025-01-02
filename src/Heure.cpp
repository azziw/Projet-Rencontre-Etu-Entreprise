#include <iostream>
#include <iomanip>

using namespace std;

class Heure 
{
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

        int tempsTotal() const
        {
            //temps total en minutes
            return heures*60 + minutes;
        }

        void Affiche()
        {
            //setw définit la largeur minimale a afficher a 2 caractères et setfill définit le remplissage comme des 0
            // si la valeur pour l'heure ou les minutes inscrite est 8 par exemple cela deviendra 08.
            cout << setw(2) << setfill('0') << heures << ":" << setw(2) << setfill('0') << minutes << endl;
        }

        bool operator< (const Heure& heure2) const 
        {
            return tempsTotal() < heure2.tempsTotal();
        }

        bool operator== (const Heure& heure2) const {
        return heures == heure2.heures && minutes == heure2.minutes;
        }
};
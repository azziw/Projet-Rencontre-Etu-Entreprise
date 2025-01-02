#include <iostream>
#include <iomanip>

using namespace std;

class Date 
{
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

        void Affiche()
        {
            //setw définit la largeur minimale a afficher a 2 caractères et setfill définit le remplissage comme des 0
            // si la valeur pour le jour ou le mois inscrite est 8 par exemple cela deviendra 08.
            cout << setw(2) << setfill('0') << jour << "/" << setw(2) << setfill('0') << mois << "/" << annee << endl;
        }

        bool operator< (const Date& date2) const 
        {
            if(annee == date2.annee)
            {
                if(mois == date2.mois)
                {
                    return jour < date2.jour;
                }
                else
                {
                    return mois < date2.mois;
                }
            }
            else
            {
                return annee < date2.annee;
            }
        }

        bool operator== (const Date& date2) const {
            return annee == date2.annee && mois == date2.mois && jour == date2.jour;
        }
};
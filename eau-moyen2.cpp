#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#include "tableau-donnees.h"

int main() {
    vector<vector<int> >    brut = litTableauInt(".\\donnees\\volumes_d_eau_distribues.txt", 2);
    vector<vector<int> > mois;
    vector<string>          noms = {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "};


    for(int m = 0; m < 12; ++m) {
        int nombre = 0,somme = 0;
        for(int i = 0; i < brut.size(); ++i) {
            if(brut[i][0] == m+1){
                somme += brut[i][1];
                ++nombre;
            }
        }
        if(nombre) {
            mois.push_back({m,(somme*1.0)/nombre});
            cout << "Le volume d'eau distribue en ce mois de " << noms.at(m) << "\test de\t" << mois.back()[1] << " litres." << endl;
        }
        else
            cout << "Le volume d'eau distribue en ce mois de " << noms.at(m) << "\test de\t" << 0 << " litres." << endl;
    }


}

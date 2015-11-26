#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#include "tableau-donnees.h"

int main() {
    vector<vector<int> >    brut = litTableauInt(".\\donnees\\volumes_d_eau_distribues.txt", 2);
    vector<vector<int> >    mois;
    vector<string>          noms = {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "};

    for(int m = 1; m <= 12; ++m) {
        int nombre = 0,somme = 0;
        for(int i = 0; i < brut.size(); ++i) {
            if(brut[i][0] == m){
                somme += brut[i][1];
                ++nombre;
            }
        }
        if(nombre)
            mois.push_back({m,somme});
    }

    cout        << "Le volume d'eau distribue au mois de " <<  noms.at(mois[maxPosition(colonne(mois,1))].front()-1)     << "\test de\t" << max(colonne(mois,1))  << " litres a ete le plus grand"    << endl;
}

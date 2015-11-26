#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int> > brut;
    vector<vector<int> > mois;
    vector<string>          noms = {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "};



    ifstream fichier(".\\donnees\\volumes_d_eau_distribues.txt");
    if(fichier){
        while(fichier) {
            int moiss;
            int litres;
            fichier >> moiss;
            fichier >> litres;
            if(fichier)
                brut.push_back({moiss,litres});
        }
    }
    else
        cout << "ERREUR";

    for(int m = 1; m <= 12; ++m) {
        int nombre = 0,somme = 0;
        for(int i = 0; i < brut.size(); ++i) {
            if(brut[i][0] == m){
                somme += brut[i][1];
                ++nombre;
            }
        }
        if(nombre)
            mois.push_back({m,(somme*1.0)/nombre});
    }

    for(int i = 0; i < mois.size(); ++i) {
        cout << "Le volume d'eau distribue en ce mois de " << noms.at(mois[i][0]-1) << "\test de\t" << mois[i][1] << " litres." << endl;
    }

}

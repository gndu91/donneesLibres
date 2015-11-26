#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int> >    brut;
    vector<vector<int> >    mois;
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
    else {
        cout << "ERREUR de lecture du fichier";
        return(-1);
    }

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
    int maximum = 0, apogee = 0;
    for(int i = 0; i < mois.size(); ++i) {
        if(mois.at(i).at(1) > maximum) {
            maximum = mois.at(i).at(1);
            apogee = mois.at(i).at(0);
        }
    }
    cout        << "Le volume d'eau distribue au mois de " <<  noms.at(apogee-1)     << "\test de\t" << maximum      << " litres a ete le plus grand"    << endl;
}

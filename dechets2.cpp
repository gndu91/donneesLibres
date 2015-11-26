#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#include "tableau-donnees.h"

int main() {
    vector<vector<int>> dechets = litTableauInt(".\\donnees\\tonnages_des_dechets_bacs_jaunes.txt", 13);
    vector<vector<int>> palmares(12,vector<int>(2,0));
    vector<string>          noms = {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "};

    for(int m = 0; m < 12; m++)
        palmares.at(m) = {dechets[maxPosition(colonne(dechets, m + 1))].front(),max(colonne(dechets, m+1))};
    for(unsigned int i = 0; i < palmares.size(); ++i)
        cout << noms.at(i) << ":\t" << palmares[i].front()-75000 << "\t" << palmares[i].back() << endl;
}

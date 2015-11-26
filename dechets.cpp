#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> dechets;
    vector<vector<int>> palmares(12,vector<int>(2,0));
    vector<string>          noms = {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "};


    /**Extraction*/ {
    ifstream fichier(".\\donnees\\tonnages_des_dechets_bacs_jaunes.txt");
    if(fichier){
        while(fichier) {
            int actuel;
            char c;
            do {
                fichier >> actuel;
                if(fichier) {
                    if(actuel < 5000)
                        dechets.back().push_back(actuel);
                    else if(actuel > 7500)
                        dechets.push_back({actuel});
                }

                c = fichier.get();
            } while(fichier);
        }
    }
    else
        cout << "ERREUR";
    }

    /**Tri*/ {
        vector<vector<int>> dechets2;
        int maxArrondissements = 0;
        for(auto arrondissement : dechets) {
            if(arrondissement.front() - 75000 > maxArrondissements)
                maxArrondissements = arrondissement.front() - 75000;
        }
        for(int i = 1; i < maxArrondissements;++i) {
            dechets2.push_back({});
            for(auto arrondissement : dechets) {
                if(arrondissement.front()-75000==i) {
                    for(auto mois : arrondissement) {
                        dechets2.back().push_back(mois);
                    }
                }
            }
        }
        dechets = dechets2;
    }

    /**Classement*/ {
        for(int m = 0; m < 12; m++) {
            for(auto arrondissement : dechets) {
                if(arrondissement.at(m+1) > palmares.at(m).back() ) {
                    palmares.at(m).back()  = arrondissement.at(m+1);
                    palmares.at(m).front() = arrondissement.front();
                }
            }
        }
    }
    /**Affichage*/
    for(int i = 0; i < palmares.size(); ++i) {
        cout << noms.at(i) << ":\t";
        cout<< palmares[i].front()-75000 << "\t" << palmares[i].back();
        cout << endl;
    }
}

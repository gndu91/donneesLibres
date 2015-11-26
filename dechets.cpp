#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> dechets;


    ifstream fichier(".\\donnees\\tonnages_des_dechets_bacs_jaunes.txt");
    if(fichier){
        while(fichier) {
            int actuel;
            char c;
            do {
                fichier >> actuel;
                if(fichier) {
                    if(actuel < 7500)
                        dechets.back().push_back(actuel);
                    else
                        dechets.push_back({actuel});
                }

                c = fichier.get();
            } while(fichier);
        }
    }
    else
        cout << "ERREUR";
    for(auto arro : dechets) {
        for(auto i : arro) {
            cout << i << "\t";
        }
        cout << endl;
    }
}

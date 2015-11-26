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
            vector<int> arrondissement;
            char c;
            do {
                fichier >> actuel;
                arrondissement.push_back(actuel);
                c = fichier.get();
            } while((c==' ' or c=='\t') and fichier and c!='\n');
            if(fichier)
                dechets.push_back(arrondissement);
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

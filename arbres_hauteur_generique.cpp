#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<string>> lit_donnees(string fichier, int nbcolonnes) {
    ifstream f(fichier);
    vector<vector<string>> resultat;
    while ( f ) {
        vector<string> ligne;
        for ( int i=0; i<nbcolonnes; i++ ) {
            string s;
            getline(f, s, ';');
            ligne.push_back(s);
        }
        resultat.push_back(ligne);
        string poubelle;
        getline(f, poubelle);
    }
    return resultat;
}

int main() {
    vector<vector<string>> donnees = lit_donnees("donnees/arbresremarquablesparis2011.csv", 13);
    for ( auto ligne: donnees ) {
        cout << ligne[1] << ' ' << ligne[5] << endl;
    }
}

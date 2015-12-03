#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "affichage.h"

using namespace std;

vector<vector<string>> extraireFichier(string chemin,char separateur);
vector<string> extraireColonne(vector<vector<string>> entree, int rang);

template<typename T> T
convertir(string entree, T& sortie) {
    ofstream out("tmp");
        out << entree;
        out.close();
    ifstream in("tmp");
        in >> sortie;
        in.close();
    return sortie;
}

template<typename T> vector<T>
extraireContenuColonne(vector<string> entree, string& titre, T test) {
    vector<T> sortie;
    titre = entree.front();
    for(int i = 1; i < entree.size(); ++i)
        sortie.push_back(convertir(entree.at(i),test));
    return sortie;
}

#include <fstream>
#include <iostream>
using namespace std;

int total(vector<int> t) {
    int somme(0);
    for(auto line : t)
        somme+=line;
    return somme;
}

vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
    vector<vector<int>> r = {{}};
    ifstream fichier(nom_fichier);
    if(fichier){
        while(fichier) {
            int actuel;
            fichier >> actuel;
            if(fichier) {
                if(r.back().size() < nb_colonnes)
                    r.back().push_back(actuel);
                else
                    r.push_back({actuel});
            }
        }
        fichier.close();
    }
    return r;

}

vector<int> colonne(vector<vector<int>> t, int i) {
    vector<int> r;
    for(auto line : t)
        r.push_back(line.at(i));
    return r;
}

int main() {
    cout << "Le volume total d'eau distribue a Paris en 2011 est de " << total ( colonne(litTableauInt(".\\donnees\\volumes_d_eau_distribues.txt", 2),1) ) << " litres." << endl;
}

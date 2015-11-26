#include <fstream>
#include "tableau-donnees.h"

int moyenne(vector<int> t) {
    int somme(0);
    for(auto line : t)
        somme+=line;
    return (1.0*somme)/t.size();
}

int total(vector<int> t) {
    int somme(0);
    for(auto line : t)
        somme+=line;
    return somme;
}

int max(vector<int> t) {
    int maxi(0);
    for(auto line : t)
        if(maxi<line)
            maxi = line;
    return maxi;
}

int maxPosition(vector<int> t) {
    int maxi(0),rang(-1);
    for(int i = 0; i < t.size(); ++i)
        if(maxi<t.at(i)) {
            rang = i;
            maxi = t.at(i);
        }
    return rang;
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

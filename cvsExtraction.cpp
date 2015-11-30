#include "cvsExtraction.h"

#define AVOID(cc) while(cc.size())cc.pop_back();

vector<vector<string>> extraireFichier(string chemin) {
    vector<vector<string>>  sortie;
    string                  ligneComplete;
    vector<string>          ligne;
    char                    caractere;
    ifstream fichier(chemin.c_str());
    if(fichier){
        while(fichier) {
            AVOID(ligne)
            fichier >> ligneComplete;
            ligne.push_back({});
            for(char c : ligneComplete) {
                if(c == ';')
                    ligne.push_back({});
                else
                    ligne.back().push_back(c);
            }
            if(fichier)
                sortie.push_back(ligne);
        }
        fichier.close();
    } else {
        cout << "ERREUR de lecture du fichier";
        return(vector<vector<string>>(0));
    }
    return sortie;
}

vector<string> extraireColonne(vector<vector<string>> entree, int rang) {
    vector<string> sortie;
    if(rang < 0)
        rang = 0;
    if(rang >= entree.size())
        rang = entree.size() - 1;

    for(auto actuel : entree)
        sortie.push_back(actuel.at(rang));

    return sortie;
}

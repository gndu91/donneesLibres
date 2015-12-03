#include "dechets3.h"

vector<vector<string>> lit_donnees(string fichier, int nbcolonnes) {
    ifstream f(fichier);
    vector<vector<string>> resultat = {{""}};
    if(f)
        while ( f ) {
            char c = f.get();
            if( f ) {
                if(c == '\n')
                    resultat.push_back({""});
                else if(c == ';')
                    resultat.back().push_back("");
                else if(c == ',')
                    resultat.back().back().push_back('.');
                else
                    resultat.back().back().push_back(c);
            }
        }
    else
        cout << "error";
    int t = 0;
    for(auto ligne : resultat.back())
        t+=ligne.size();
    if(!t)
        resultat.pop_back();
    int taille = 0;
    for(auto ligne : resultat)
        if(ligne.size() > taille)
            taille = ligne.size();

    for(auto& ligne : resultat)
        while(ligne.size() < taille)
            ligne.push_back({});
    return resultat;
}

int main() {
    string fichier = "donnees/tonnages_des_dechets_bacs_jaunes.csv";
    vector<vector<string>> matriceFichier = lit_donnees(fichier,13);
    vector<string> pollueur;
    cout << "Loading";
    for(int i = 1; i < matriceFichier.size(); ++i) {
        float tmp;
        float s = somme(sansLepremier(matriceFichier.at(i)),tmp);
        cout<<".";
    }
    ENDL
    for(int i = 1; i < matriceFichier.size(); ++i) {
        float tmp;
        string tmp2;
        float s = somme(sansLepremier(matriceFichier.at(i)),tmp);
        if(convertir(matriceFichier.at(i).front(),tmp))
            cout<<"Arrondisement n° " << convertir(matriceFichier.at(i).front(),tmp) - 75000 << " :\t" << nombre(s);
       else
            cout<<"Tout Paris:\t\t"<<nombre(s);
        matriceFichier.at(i).back() = convertir_(s,tmp2);
        ENDL
    }
    ENDL
    pollueur = matriceFichier.back();
    for(int i = 1; i < matriceFichier.size(); ++i) {
        float tmp;
        if(convertir(matriceFichier.at(i).front(),tmp)&&(convertir(matriceFichier.at(i).back(),tmp) > convertir(pollueur.back(),tmp)))
            pollueur = matriceFichier.at(i);
    }
    println(matriceFichier);
    for(int i = 0; i < pollueur.size(); ++i) {
        if(matriceFichier.front().at(i).size() > 7)
            cout << matriceFichier.front().at(i) << "\t: " << pollueur.at(i) << endl;
        else
            cout << matriceFichier.front().at(i) << "\t\t: " << pollueur.at(i) << endl;
    }
}

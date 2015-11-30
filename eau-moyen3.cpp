#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

string extraire(string entree, int rang = -1) {
    vector<string> sortie;
    vector<string> r2;

    sortie.push_back("");
    for(auto C : entree) {
        if(C == ';')
            sortie.push_back("");
        else
            sortie.back().push_back(C);
    }
    if(rang < 0 or rang > sortie.size())
        return sortie.back();
    return sortie.at(rang);
}

int different(string a, string b) {
    int r(0),i(0),j(0);
    while((i < a.size())&&(j < b.size())) {
        if(a[i]!=b[j]) {
            r+=1;
        }
        ++i;
        ++j;
    }
    return r;
}

int toInt(string t) {
    int i = 0;
        ofstream out("tmp");
            out << t;
            out.close();
        ifstream in("tmp");
            in >> i;
            in.close();
    return i;
}

int main() {
    vector<vector<int> >    brut(2),mois;
    vector<int> lignes;
    vector<vector<string>>  noms =  {{"janv-11", "f��vr-11", "mars-11", "avr-11", "mai-11", "juin-11", "juil-11", "ao��t-11", "sept-11", "oct-11", "nov-11", "d��c-11"},{"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "}};
    vector<string> lignes_;
    string temp;
    ifstream fichier("./donnees/volumes_d_eau_distribues.csv");
    if(fichier){
        fichier >> temp;
        while(fichier) {
            fichier >> temp;
            if(fichier)
                lignes.push_back(toInt(extraire(string(temp))));
                lignes_.push_back(extraire(string(temp),0));
        } fichier.close();
    } else { cout << "ERREUR de lecture du fichier"; return(-1); }
    brut.back() = lignes;
    /**Pour chaque mois*/
    for(int m = 1; m <= 12; ++m) {
        int nombre = 0,somme = 0;
        /**On parcourt la liste*/
        for(int i = 0; i < lignes.size(); ++i) {
            if(different(lignes_.at(i),noms.front().at(m-1)) <= 2){
                somme += brut.back().at(i);
                brut.front().push_back(m);
                ++nombre;
                break;
            }
        }
        if(nombre)
            mois.push_back({m,somme*1.0/nombre});
    }

    for(int i = 0; i < mois.size(); ++i) {
        cout << "Le volume d'eau distribue en ce mois de " << noms.back().at(mois[i][0]-1) << "\test de\t" << mois[i][1] << " litres." << endl;
    }
}

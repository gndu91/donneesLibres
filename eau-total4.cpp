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
    string temp;
    int totale(0);
    ifstream fichier("./donnees/volumes_d_eau_distribues.csv");
    if(fichier){fichier >> temp;
        while(fichier) {fichier >> temp;
            if(fichier) totale += toInt(extraire(string(temp)));
        } fichier.close();
    } else {cout << "ERREUR de lecture du fichier"; return(-1);}
    cout << "Le volume d'eau distribue en cette annee de 2011 est de\t" << totale << " litres." << endl;
}

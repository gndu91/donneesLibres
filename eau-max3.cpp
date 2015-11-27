#include <fstream>
#include <vector>
#include <iostream>

#define println(X)  print(X);\
                    print('\n');

#define FOR(i,corresp) for(int i = 0; i < corresp.size(); ++i)
using namespace std;


template<typename T>
void print(T t) {
    cout << t;
}

template<typename T>
void print(vector<T> t) {
    print('{');
    for(int i = 0; i < t.size(); ++i) {
        print(t.at(i));
        if(i != t.size() - 1)
            print(',');
    }
    print('}');
}

vector<string>
couper(string entree, string) {
    vector<string> sortie;
    sortie.push_back("");
    for(auto C : entree) {
        if(C == ';')
            sortie.push_back("");
        else
            sortie.back().push_back(C);
    }
    return sortie;
}

vector<int>
couper(string entree, int, vector<string> corresp) {
    vector<string> sortie;
    vector<int> r;
    println(entree);

    sortie.push_back("");
    for(auto C : entree) {
        if(C == ';')
            sortie.push_back("");
        else
            sortie.back().push_back(C);
    }
    ofstream out("temp");
    if(out) {
        for(auto Case : sortie)
        FOR(i,corresp) {
            if(Case == corresp.at(i))
                out << i ;
            else
                out << Case;
            out << endl;
        }
    }
        for(auto C : sortie)
    out.close();
    while(r.size() < sortie.size())
        r.push_back(1);
    ifstream in("temp");
    if(in)
        for(auto& C : r)
            in >> C;
    in.close();
    println(r);
    return r;
}

template<typename T> T
correspondance(vector<vector<T>> t, T t_, int a=0, int b = __SIZEOF_INT__) {
    return t_;
}

int main() {
    vector<vector<int> >    brut;
    vector<vector<int> >    mois;
    vector<vector<string>>  noms =  {{"janv-11", "f�vr-11", "mars-11", "avr-11", "mai-11", "juin-11", "juil-11", "ao�t-11", "sept-11", "oct-11", "nov-11", "d�c-11"},
                                    {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "}};
    vector<string> enTete;
    vector<vector<int>> lignes;
    string temp;
    ///Mois;Volumes_d'eau_distribu�s_(m3)
    ifstream fichier(".\\donnees\\volumes_d_eau_distribues.csv");
    if(fichier){
        fichier >> temp;
        enTete = couper(string(temp),string(""));
        while(fichier) {
            fichier >> temp;
            if(fichier)
                lignes.push_back(couper(string(temp),0,noms.front()));
        }
    }
    else {
        cout << "ERREUR de lecture du fichier";
        return(-1);
    }
    println(lignes);
    int maxi = 0;
    for(auto l : lignes) {
        if(l.back()>maxi) {
            maxi = l.back();
            cout << l.back();
        }
    }
    if(not(brut.size()))
        return -1;

    for(int m = 1; m <= 12; ++m) {
        int nombre = 0,somme = 0;
        for(int i = 0; i < brut.size(); ++i) {
            if(brut[i][0] == m){
                somme += brut[i][1];
                ++nombre;
            }
        }
        if(nombre)
            mois.push_back({m,somme});
    }
    int maximum = 0, apogee = 0;
    for(int i = 0; i < mois.size(); ++i) {
        if(mois.at(i).at(1) > maximum) {
            maximum = mois.at(i).at(1);
            apogee = mois.at(i).at(0);
        }
    }
    cout        << "Le volume d'eau distribue au mois de " <<  correspondance(noms,string("a"))                      << "\test de\t" << maximum      << " litres a ete le plus grand"    << endl;
}

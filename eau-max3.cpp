#define LINUX

#ifdef LINUX
#define FICHIER "./donnees/volumes_d_eau_distribues.csv"
#endif // LINUX
#ifdef WINDOWS
#define FICHIER ".\\donnees\\volumes_d_eau_distribues.csv"
#endif // WINDOWS

#include <fstream>
#include <vector>
#include <iostream>

#define println(X)  print(X);\
                    print('\n');

#define FOR(i,vect,at_,instructions) {\
                                        int i = 0;\
                                        while(i < vect.size()) {\
                                            auto& at_ = vect[i];\
                                            {\
                                                instructions;\
                                            };\
                                            ++i;\
                                        }\
                                    }
#define IF(bool,instr0,instr1) if(bool){instr0;}else{instr1;}

#define SWITCH(var,block) {auto ___VAR___ = var; block;}
#define CASE(   ___VALUE___,\
                ___INSTRUCION_IF___,\
                ___INSTRUCION_ELSE___) {\
                                        IF( ___VAR___==___VALUE___,\
                                            ___INSTRUCION_IF___,\
                                            ___INSTRUCION_ELSE___\
                                           )\
                                       }

#define SWITCH_(var,block) {auto ___VAR___ = var;\
                            int ___BLOCKS_VER___ = 0;\
                            block;\
                          }
#define CASE_(   ___VALUE___,\
                ___INSTRUCION_IF___) {\
                                        IF( ___VAR___==___VALUE___&&!___BLOCKS_VER___,\
                                            ___INSTRUCION_IF___; \
                                            ___BLOCKS_VER___ = 1,\
                                          )\
                                       }
using namespace std;

template<typename T> int
toInt(T t) {
    ofstream out("tmp");
    out << t;
    out.close();
    ifstream in("tmp");
    int i = 0;
    in >> i;
    return i;
    in.close();
}

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
    println(sortie);
}

template<typename T> T
correspondance(vector<vector<T>> t, T t_, int a=0, int b = __SIZEOF_INT__) {
    return t_;
}

int main() {
    int i = 1;
    SWITCH_(i,
        CASE_(i,cout<<1)
        CASE_(___VAR___,cout<<2)
    )
}

int mainL() {
    vector<vector<int> >    brut;
    vector<vector<int> >    mois;
    vector<vector<string>>  noms =  {{"janv-11", "févr-11", "mars-11", "avr-11", "mai-11", "juin-11", "juil-11", "août-11", "sept-11", "oct-11", "nov-11", "déc-11"},
                                    {"Janvier  ", "Fevrier  ", "Mars     ", "Avril    ", "Mai      ", "Juin     ", "Juillet  ", "Aout     ", "Septembre", "Octobre  ", "Novembre ", "Decembre "}};
    vector<string> enTete;
    vector<int> lignes;
    vector<string> lignes_;
    string temp;
    ///Mois;Volumes_d'eau_distribués_(m3)
    ifstream fichier(FICHIER);
    if(fichier){
        fichier >> temp;
        enTete = couper(string(temp),string(""));
        while(fichier) {
            fichier >> temp;
            if(fichier)
                lignes.push_back(toInt(extraire(string(temp))));
                lignes_.push_back(extraire(string(temp)));
        }
    }
    else {
        cout << "ERREUR de lecture du fichier";
        return(-1);
    }
    vector<string> corresp = noms.front();
    string moi;
    int maxi = 0;
    FOR(i,lignes,l, {
        IF(l>maxi, {
            FOR(i, corresp,C,)
            maxi = l;
        },);
    });
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

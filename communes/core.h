#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

#define println(T)  print(T,profondeur(T));\
                    print('\n',0);

#define DO(t) __ACCU__ = 0;  while (__ACCU__++ < t)
#define DO_INIT              int __ACCU__ = 0;

template<typename T> int
profondeur(T t) {
    return 0;
}
template<typename T> int
profondeur(vector<T> t) {
    T t2;
    if(!t.size())
        t.push_back(t2);
    return profondeur(t.front()) + 1;
}


template<typename T>
void print(T t, int layer) {
    cout << t;
}

#warning FIXME (Ghoul Nadir#1#): Allow mote than 2 dimensions

template<typename T>
void print(vector<T> t, int layer) {
    DO_INIT
    print('{', layer);
    unsigned int i = 0;
    if(t.size()) {
        if(layer == profondeur(t))
            print('\n',layer);
        while(i < t.size()) {
            if(i > 0) {
                print(',',layer);
                if(layer == profondeur(t))
                    print('\n',layer);
            }
            DO(profondeur(t)-layer + 1) {
                print('\t',0);
            }
            print(t.at(i),layer);
            i+=1;
        }
        if(layer == profondeur(t))
            print('\n',layer);
    }else   print("__VOID__", layer);
    print('}', layer);
}

void fprint(string nom);

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

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>

using namespace std;
#define println(T)  print(T,profondeur(T));\
                    print('\n',0);

#define DO(t) int __ACCU__ = 0; while (__ACCU__++ < t)

#define ENDL cout << endl;

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
    print('{', layer);
    unsigned int i = 0;
    if(t.size()) {
        if(layer == profondeur(t))
            print('\n',layer);
        while(i < t.size()) {
            if(i > 0) {
                print(',',layer);
                print(' ',layer);
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

template<typename T> vector<T>
sansLepremier(vector<T> entree) {
    vector<T> sortie;///pop_front
    for(int i = 1; i < entree.size(); ++i)
        sortie.push_back(entree[i]);
    return sortie;
}

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

template<typename T> string
convertir_(T entree, string& sortie) {
    ofstream out("tmp");
        out << entree;
        out.close();
    ifstream in("tmp");
        in >> sortie;
        in.close();
    return sortie;
}

string sansEspace(string entree) {
    string sortie;
    for(auto lettre : entree)
        if(lettre != ' '&&lettre != '\t'&&lettre != '\n')
            sortie.push_back(lettre);
    return sortie;
}
template<typename T> string
nombre(T entree_) {
    string tmp;
    string entree = convertir_(entree_,tmp);
    string sortie;

    for(int i = entree.size()-1; i >=0 ;--i) {
        if((!((entree.size()-i-1)%3))&&(entree.size()-1!=i))
            sortie = " " + sortie;
        sortie = entree.at(i)  + sortie;
    }

    return sortie;
}

template<typename T,typename T2> T2
somme(vector<T> entree, T2 tmp) {
    T2 sortie;
    for(int i = 0; i < entree.size(); ++i)
        sortie += convertir(sansEspace(entree[i]),tmp);
    return sortie;
}
/**
                if(c!='\n') {///TODO:detecter la fin de la 1ere ligne
                    string s;
                    s+= c;
                    string s2;
                    getline(f, s2, ';');
                    for(auto c2 : s2) {
                        if(c!='\n')
                            s += c2;
                        else
                            break;
                    }
                    ligne.push_back(s);
                }
                else break;*/




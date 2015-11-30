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

#define MARco( abcd ) z

#define println(X)  print(X);\
                    print('\n');

#define AVOID(matrix) while(matrix.size()) matrix.pop_back();


#define FOR(i,vect,at_,instructions,__debut__,__millieu__,__fin__)\
{\
    int i = 0;\
    __debut__;\
    while(i < vect.size())\
    {\
        auto& at_ = vect.at(i);\
        {\
            instructions;\
        }\
        \
        ++i;\
        \
        if(i < vect.size())\
        {\
            __millieu__;\
        }\
    }\
    __fin__;\
}
#define IF(bool,instr0,instr1) if(bool){instr0;}else{instr1;}

#define SWITCH(var,block) {auto ___VAR___ = var; block;}
#define CASE(   ___VALUE___,___INSTRUCION_IF___,___INSTRUCION_ELSE___) IF( ___VAR___==___VALUE___,___INSTRUCION_IF___,___INSTRUCION_ELSE___)

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
#define SET(_a_,_b_) initialize(_a_,_b_);
using namespace std;

template<typename T> void
initialize(T& t, T C) {
    t = C;
}

template<typename T, typename T2> void
initialize(vector<T>& t, T2 C) {
    FOR(i,t,t_,initialize(t_,C),,,)
}


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
    IF(t.size(),FOR(i,t,t_,print(t_),,print(','),),print("__VOID__"))
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

int commun(string a, string b) {
    IF(a.size()==b.size(),int r(0);FOR(i,a,a_,r+=a_==b[i],,,)return r,return 0)
}
template<typename type> type
plusGrand(type a, type b) {
    if(a.size() < b.size())
        return b;
    return a;
}

template<typename type> type
plusPetit(type a, type b) {
    if(a.size() < b.size())
        return a;
    return b;
}

int contient(string a, string b) {
    ///Not finished
    auto big    = plusGrand(a,b);
    auto small  = plusPetit(a,b);
    int i(0),j(0);
    bool pasTermine = true;
    while(pasTermine) {
        while((i < small.size())&&(j < big.size())) {
            if(a[i]!=b[j]) {/*
                r+=1;
                ++i;*/
            }
        }
    }
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

int main() {
    vector<vector<int> >    brut(2);
    vector<vector<int> >    mois;
    vector<vector<string>>  noms =  {{"janv-11", "féévr-11", "mars-11", "avr-11", "mai-11", "juin-11", "juil-11", "aoûût-11", "sept-11", "oct-11", "nov-11", "dééc-11"},
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
                lignes_.push_back(extraire(string(temp),0));
        }
    }
    else {
        cout << "ERREUR de lecture du fichier";
        return(-1);
    }
    vector<string> corresp = noms.front();
    brut.back() = lignes;
    if(not(brut.size()))
        return -1;
    /**Pour chaque mois*/
    for(int m = 1; m <= 12; ++m) {
        int nombre = 0,somme = 0;
        /**On parcourt la liste*/
        FOR(i,lignes_,l__,
            if(different(l__,corresp.at(m-1)) <= 2){
                somme += brut.back().at(i);
                brut.front().push_back(m);
                ++nombre;
                break;
            }
            else
             cout << "Error between " << corresp.at(m-1) << " and " << l__ << " : " << different(l__,corresp.at(m-1)) << " defferences";
            ,,
            ,cout << endl;)
        if(nombre)
            mois.push_back({m,somme});
    }
    println(mois);
    int maximum = 0, apogee = 0;
    for(int i = 0; i < mois.size(); ++i) {
        if(mois.at(i).at(1) > maximum) {
            maximum = mois.at(i).at(1);
            apogee = mois.at(i).at(0);
        }
    }
    cout        << "Le volume d'eau distribue au mois de " <<  correspondance(noms,string("a"))                      << "\test de\t" << maximum      << " litres a ete le plus grand"    << endl;
}

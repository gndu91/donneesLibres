#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "cvsExtraction.h"
#define DO(t) __ACCU__ = 0;  while (__ACCU__++ < t)
#define DO_INIT              int __ACCU__ = 0;

#define AVOID(cc) while(cc.size())cc.pop_back();

using namespace std;

vector<vector<string>> extraireFichier(string chemin,char separateur) {
    vector<vector<string>>  sortie;
    string                  ligneComplete;
    vector<string>          ligne;
    char                    caractere;
    ifstream fichier(chemin.c_str());
    if(fichier){
        while(fichier) {
            AVOID(ligne)
            getline(fichier,ligneComplete);
            ligne.push_back({});
            for(char c : ligneComplete) {
                if(c == separateur)
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

int main() {
    vector<vector<string>> matrix = extraireFichier("donnees/velib_a_paris_et_communes_limitrophes.csv",';');
    vector<vector<string>> proches;
    vector<vector<double>> dist;
    vector<vector<double>> geoLocations;
    double multiple = 1;
    double av = 0;
    double av_= 0;
    int sizeOfBar = 75;
    string spc,ret;
    DO_INIT
    DO(sizeOfBar)  ret+='\b';
    DO(sizeOfBar)  spc+=' ';
    double Float;
    ///println(matrix);
    cout << "Loading: \n\tPart 1 (extraction des positions)\n\t\t[" << spc <<']' << ret;
    for(int i_ = 1; i_ < matrix.size(); ++i_) {
        geoLocations.push_back({convertir(matrix.at(i_).at(6),Float),convertir(matrix.at(i_).at(7),Float)});
        ///print(geoLocations.back(),9484);
        ///cout << "\t:" << i_ <<endl;
        av = (sizeOfBar*i_)/matrix.size();
        if((int)av>(int)av_) {
            cout << "\b=>";
            av_ = av;
        }
    }
    av = av_ = 0;
    cout << "\n\tPart 2 (calcul des distances et optimisation)\n\t\t[" << spc <<']' << ret;
    for(int a = 1; a < geoLocations.size(); ++a) {
        dist.push_back({});
        for(int b = 1; b < geoLocations.size(); ++b) {
            if(b!=a) {
                double xa((geoLocations.at(a).back())    * multiple);
                double ya((geoLocations.at(a).front())   * multiple);
                double xb((geoLocations.at(b).back())    * multiple);
                double yb((geoLocations.at(b).front())   * multiple);
                double d(sqrt(pow(yb-ya,2)+pow(xb-xa,2)));
                dist.back().push_back(d);
            }
            else
                dist.back().push_back(10000000);
            ///print(dist.back(),9484);
            ///cout << endl;
        }
        av = (sizeOfBar*a)/matrix.size();
        if((int)av>(int)av_) {
            cout << "\b=>";
            av_ = av;
        }
    }
    av = av_ = 0;
    double mini = __INT_MAX__;
    int minA,minB;
    cout << "\n\tPart 3 (determination de la plus courte distance)\n\t\t[" << spc <<']' << ret;
    for(int i = 1; i < dist.size(); ++i) {
        for(int j = 1; j < dist.at(i).size(); ++j) {
            if(dist.at(i).at(j)<mini&&dist.at(i).at(j)) {
                minA = i;
                minB = j;
                mini = dist.at(i).at(j);
            }
            av = (sizeOfBar*i)/dist.size();
            if((int)av>(int)av_) {
                cout << "\b=>";
                av_ = av;
            }
        }
    }
    av = av_ = 0;
    cout << "\n\tPart 4 (Analyse des resultats obtenus)\n\t\t[" << spc <<']' << ret;
    proches.push_back(matrix.front());
    proches.push_back(matrix.at(minA));
    proches.push_back(matrix.at(minB));
    for(int i = 1; i < dist.size(); ++i) {
        if((int)av>(int)av_) {
            cout << "\b=>";
            av_ = av;
        }
    }
    cout << "\nLes deux stations les plus proches les unes des autres sont:\n";
    println(proches);
}

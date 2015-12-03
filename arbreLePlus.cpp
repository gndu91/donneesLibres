#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<string>> lit_donnees(string fichier, int nbcolonnes) {
    ifstream f(fichier);
    vector<vector<string>> resultat;
    if(f)
        while ( f ) {
            vector<string> ligne;
            for ( int i=0; i<nbcolonnes; i++ ) {
                string s;
                getline(f, s, ';');
                ligne.push_back(s);
            }
            resultat.push_back(ligne);
            string poubelle;
            getline(f, poubelle);
        }
    else
        cout << "error";
    return resultat;
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

vector<string> vieu() {
    vector<vector<string>> donnees = lit_donnees("donnees/arbresremarquablesparis2011.csv", 13);
    int maxi = 1;
    for ( int i = 0; i < donnees.size(); ++i ) {
        if(toInt(donnees[i][5])>0)
            if(toInt(donnees[i][5])<toInt(donnees[maxi][5]))
                maxi = i;
    }
    if(donnees.size())
        return donnees.at(maxi);
    return {"E",
            "R",
            "R",
            "O",
            "R"};

}
vector<string> grand() {
    vector<vector<string>> donnees = lit_donnees("donnees/arbresremarquablesparis2011.csv", 13);
    int maxi = 1;
    for ( int i = 1; i < donnees.size(); ++i ) {
        if(toInt(donnees[i][6])>0)
            if(toInt(donnees[i][6])<toInt(donnees[maxi][6]))
                maxi = i;
    }
    if(donnees.size())
        return donnees.at(maxi);
    return {"E",
            "R",
            "R",
            "O",
            "R"};
}
int main() {
    for ( auto ligne: vieu() ) {
        cout << ligne << '\n';
    }
    cout << endl;
    cout << endl;
    cout << endl;
    for ( auto ligne: grand() ) {
        cout << ligne << '\n';
    }
}

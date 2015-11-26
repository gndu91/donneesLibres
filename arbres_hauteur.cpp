#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream f("donnees/arbresremarquablesparis2011.csv");
    string poubelle;
    float x, y;
    char c;
    int arrondissement;
    string genre;
    string espece;
    string famille;
    int annee;
    int hauteur;
    int circonference;
    string adresse;
    string nom_commun;
    string variete;
    string foo;
    string bar;
    getline(f, poubelle);
    while (f.good()) {
        for (int i=0; i<5; i++) {
            getline(f, poubelle, ';');
        }
        f >> annee >> c >> hauteur;
        cout << annee << " " << hauteur << endl;

        getline(f, poubelle);
    }
}

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fichier(".\\donnees\\volumes_d_eau_distribues.txt");
    int litres(0);
    if(fichier){
        while(fichier) {
            string texte;
            int litre;
            fichier >> texte;
            fichier >> litre;
            litres+=litre;
        }
    }
    else
        cout << "ERREUR";
    cout << "Le volume total d'eau distribue a Paris en 2011 est de " << litres << " litres." << endl;
}

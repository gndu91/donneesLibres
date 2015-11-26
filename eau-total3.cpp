#include <fstream>
#include <iostream>
using namespace std;
#include "tableau-donnees.h"

int main() {
    cout << "Le volume total d'eau distribue a Paris en 2011 est de " << total ( colonne(litTableauInt(".\\donnees\\volumes_d_eau_distribues.txt", 2),1) ) << " litres." << endl;
}

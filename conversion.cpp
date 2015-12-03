#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

#include "cvsExtraction.h"

using namespace std;

void testConvertion();
void testExtraction();

int main() {
    testExtraction();
    testConvertion();
}

ostream abc;

void testConvertion() {
    float f;
    int i;
    double d;
    string str;
    vector<int> ligne;
    vector<string> ligneStr;

    assert(convertir("123",i) == 123);
    assert(convertir("258",i) == 258);

    ligne = extraireContenuColonne(extraireColonne(extraireFichier("./donnees/volumes_d_eau_distribues.csv",';'),1),str,0);
    print(str,0);
    print(" : ",0);
    println(ligne);

    ligneStr = extraireContenuColonne(extraireColonne(extraireFichier("./donnees/volumes_d_eau_distribues.csv",';'),0),str,str);
    print(str,0);
    print(" : ",0);
    println(ligneStr);
}

void testExtraction() {
    println(extraireFichier("./donnees/volumes_d_eau_distribues.csv",';'));
    println(extraireColonne(extraireFichier("./donnees/volumes_d_eau_distribues.csv",';'),1));
    println(extraireColonne(extraireFichier("./donnees/volumes_d_eau_distribues.csv",';'),0));/*
    extraireFichier("./donnees/tonnages_des_dechets_bacs_verts.csv");*/
}

void other() {
    fprint("./donnees/volumes_d_eau_distribues.csv");
}

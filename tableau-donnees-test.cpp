#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<int> c = { 1, 5, 3, 5, 1 };
vector<vector<int>> t = { {1, 2}, {2,4}, {3,1}, {0,0} };

void moyenneTest() {
    ASSERT( moyenne(c) == 3 );
}

void totalTest() {
    ASSERT( total({}) == 0 );
    ASSERT( total(c)  == 15 );
}

void maxTest() {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction maxTest non implanté");
}

void maxPositionTest() {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction maxPositionTest non implanté");
}

void litTableauIntTest() {
    ASSERT( litTableauInt("donnees/volumes_d_eau_distribues.txt", 2) ==
            vector<vector<int>>({
                    {  4, 15688700 },
                    {  7, 16049700 },
                    {  3, 16260600 },
                    {  6, 17028600 },
                    {  9, 16858200 },
                    { 12, 15530100 },
                    {  2, 14019000 },
                    {  8, 13959600 },
                    {  1, 16231200 },
                    { 10, 16592900 },
                    { 11, 15672000 },
                    {  4, 17711200 },
            }) );
}

void colonneTest() {
    ASSERT( colonne(t, 0) == vector<int>({1, 2, 3, 0}) );
    ASSERT( colonne(t, 1) == vector<int>({2, 4, 1, 0}) );
}

int main() {
    cout << "Lancement des tests de moyenne:" << endl;
    moyenneTest();
    cout << "Lancement des tests de total:" << endl;
    totalTest();
    cout << "Lancement des tests de max:" << endl;
    maxTest();
    cout << "Lancement des tests de maxPosition:" << endl;
    maxPositionTest();
    cout << "Lancement des tests de litTableauInt:" << endl;
    litTableauIntTest();
    cout << "Lancement des tests de colonne:" << endl;
    colonneTest();
}

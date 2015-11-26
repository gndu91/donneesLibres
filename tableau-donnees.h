#include <vector>
#include <string>
using namespace std;

/** Moyenne d'un tableau
 * @param un tableau d'entiers
 * @result la moyenne de ces entiers
 **/
int moyenne(vector<int> t);

/** Total d'un tableau
 * @param un tableau d'entiers
 * @result la somme de ces entiers
 **/
int total(vector<int> t);

/** Max d'un tableau
 * @param un tableau d'entiers
 * @result le plus grand de ces entiers (0 par defaut)
 **/
int max(vector<int> t);

/** Position du max d'un tableau
 * @param un tableau d'entiers
 * @result la position du plus grand de ces entiers;
    le premier s'il y en a plusieurs;
    -1 si le tableau est vide
 **/
int maxPosition(vector<int> t);

/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<int>> litTableauInt(string fichier, int nb_colonnes);

/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param i un numéro de colonne
 * @return la colonne i, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int i);

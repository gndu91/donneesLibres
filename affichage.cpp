#include "affichage.h"

void fprint(string chemin) {
    ifstream fichier(chemin.c_str());
    if(fichier){
            do {
                char caractere;
                fichier >> caractere;
                putwchar(caractere);
            } while(!fichier.eof());
        fichier.close();
    } else {
        cout << "ERREUR de lecture du fichier";
    }
}

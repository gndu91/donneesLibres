#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <vector>
#include "core.h"

using namespace std;

int Main(vector<vector<string>> matrice);

int main ( int argc, char** argv ) {
    DO_INIT
    int av(0), av_(0),sizeOfBar(60);
    string spc,ret;
    DO(sizeOfBar)  ret+='\b';
    DO(sizeOfBar)  spc+=' ';
    cout << "Chargement des positions.";
    vector<vector<string>> matrice = extraireFichier("../donnees/communes-plus-20140630.csv",';');
    cout << "..";
    cout << "\n\tPart 1 (Analyse des resultats obtenus)\n\t\t[" << spc <<']' << ret;
    for(int i = 1; i < matrice.size(); ++i) {
        av = (sizeOfBar*i)/matrice.size();
        if((int)av>(int)av_) {
            cout << "\b=>";
            av_ = av;
        }
    }
    cout << endl << "Enjoy ;)";
    Main(matrice);
}

#include <SDL/SDL.h>

int Main(vector<vector<string>> matrice) {
    int     window_height(480),
            window_width(640);
    Uint32 color = 0x000000FF;

    float   zoom(1);


    if ( SDL_Init( SDL_INIT_VIDEO ) < 0  ) { printf( "Unable to init SDL: %s\n", SDL_GetError() ); return 1; } else cout << "\n\nSDL successfully loaded\n";    atexit(SDL_Quit);
    SDL_Surface* screen = SDL_SetVideoMode(window_width, window_height, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen ) { printf("Unable to set 640x480 video: %s\n", SDL_GetError()); return 1; } else cout << "\n\nWindows initialized by " << screen->w << '*' << screen->h;
    ///SDL_Surface* bmp = SDL_LoadBMP("cb.bmp"); if (!bmp) { printf("Unable to load bitmap: %s\n", SDL_GetError()); return 1; }
    ///SDL_Rect dstrect = { (screen->w - bmp->w) / 2 , (screen->h - bmp->h) / 2 };
    cout << "\nCréation des surfaces";
    SDL_Surface* communes[matrice.size()];
    SDL_Surface* commune = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);
    SDL_Rect cartePos[matrice.size()];
    cout << "\nPositionnement";
    for(int i = 0; i < matrice.size(); ++i) {
        cartePos[i].h = 2;
        cartePos[i].w = 2;
        cartePos[i].x = matrice.at(i).at(4);
        cartePos[i].y = matrice.at(i).at(4);
    }
    cout << "\nRemplissage des surfaces";
    SDL_FillRect(commune, NULL, SDL_MapRGB(screen->format, 127, 255, 127));
    for(int i = 0; i < matrice.size(); ++i) {
        communes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, cartePos[i].w, cartePos[i].h, 32, 255, 255, 255, 255);
        SDL_FillRect(communes[i], NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    }
    cout << "\nChargement des surfaces";


    bool done = false;
    int tour = 0;
    while (!done) {
        tour++;
        cout << "tour n°" << tour << endl;
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_KEYDOWN: {
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            done = true;
                        break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        ///SDL_BlitSurface(bmp, 0, screen, &dstrect);
        for(int i = 0; i < matrice.size(); ++i)
            SDL_BlitSurface(communes[i], 0/*&(cartePos[i])*/, screen, &(cartePos[i]));

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    ///SDL_FreeSurface(bmp);

    // all is well ;)
    printf("Exited cleanly\n");/*45*/
    return 0;
}

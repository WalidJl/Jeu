#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include <SDL/SDL_ttf.h>
#include <time.h>
int main()
{


int d=1;

srand(time(NULL));
d=rand()%7;
SDL_Surface *backg=NULL ; //declaration des variables globale
SDL_Rect positiond;
SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
SDL_Surface *ecran =NULL;
ecran=SDL_SetVideoMode(800, 600, 32,SDL_ANYFORMAT); // Ouverture de la fenêtre
backg = IMG_Load("enigme.png");
positiond.x=0 ;
positiond.y=0 ;
SDL_BlitSurface(backg,NULL, ecran, &positiond);
SDL_Flip(ecran);
SDL_Delay(300);
enigma(ecran,d);
SDL_Flip(ecran);
reponse(ecran,d);
SDL_FreeSurface(backg);
SDL_Quit(); // Arrêt de la SL

    return EXIT_SUCCESS; // Fermeture du programme
}

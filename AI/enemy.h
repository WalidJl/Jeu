#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
////////////////////////////////PERSO//////////////////////////////////
typedef struct
{
////images////
//perso
SDL_Surface *image1;
SDL_Surface *image2;
SDL_Surface *image3;
SDL_Surface *image4;
SDL_Surface *image5;
SDL_Surface *image6;
SDL_Surface *image7;
SDL_Surface *image8;
SDL_Surface *image9;
SDL_Surface *image10;
SDL_Surface *image11;
SDL_Surface *image12;
SDL_Surface *imagepersoAvant[7][5];
//perso position
SDL_Rect positionEcranPerso;
//ult position

//acceleration et vitesse
double vitesse , acceleration;
}Personne;
////////////////////////////////////////ENEMY/////////////////////////////////
typedef struct
{
SDL_Surface *image1;
SDL_Surface *image2;
SDL_Surface *image3;
SDL_Surface *image4;
SDL_Surface *imageEnemyAvant[3][2];
//enemy position
SDL_Rect positionEcranEnemy;
}enemy;


void initPerso(Personne *p);
void movePerso(Personne *p,Uint32 dt);
void initPerso2(Personne *p1);
void initEnemy(enemy *e);
#endif

#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
/////////////////////////////////////////////////////////////MENU//////////////////////////////////////////////////////
typedef struct
{
//MUSIC
Mix_Music *music;
//TEXTE
SDL_Surface *texte;
//SCREEN
SDL_Surface *screen;
//BACKGROUND
SDL_Surface *image;
SDL_Rect positionEcran; 

//START
SDL_Surface *image1,*image11;
SDL_Rect positionEcran1; 

//SETTINGS
SDL_Surface *image2,*image22;
SDL_Rect positionEcran2;

//EXIT
SDL_Surface *image3,*image33;
SDL_Rect positionEcran3;
}menu;
/////////////////////////////////////////////////////////START////////////////////////////////////////////////////////
typedef struct
{
//screen
SDL_Surface *screen;
//background
SDL_Surface *image1;
SDL_Rect positionEcran;
//back
SDL_Surface *image,*image2;
SDL_Rect positionEcranback;
}start;

/////////////////////////////////////////////////////////OPTION///////////////////////////////////////////////////////
typedef struct
{
//background
SDL_Surface *image;
SDL_Rect positionEcran;
//BACK
SDL_Surface *image2,*image52;
SDL_Rect positionEcranBack;
//SAVE
SDL_Surface *image12,*image32;
SDL_Rect positionEcranSave;
//FULLSCREEN
SDL_Surface *image3,*image33;
SDL_Rect positionEcranFS;
//VOLUME
SDL_Surface *image4,*image5,*image6,*image7,*image8,*image9,*image10;
SDL_Rect positionEcranMoins;
SDL_Rect positionEcranPlus;
SDL_Rect positionEcranVol;
SDL_Surface *tab[5];
//MUTE
SDL_Surface *image11,*image22;
SDL_Rect positionEcranMUSIC;
}option;

void startj();
void optionjeu(menu menu);
void sonc();

#endif

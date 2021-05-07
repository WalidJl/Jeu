#ifndef PERS_H_INCLUDED
#define PERS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>



struct text {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;

typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;


typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}pers;

typedef struct 
{
	SDL_Surface *map ;
	SDL_Rect pos_map;
	SDL_Surface *mini_perso;
	SDL_Rect perso_pos_map;
}map ;
void initialiserperso(pers *perso);
void deplacer_perso(pers *perso,SDL_Event event);
void afficher_perso(SDL_Surface *screen,pers perso);
void free_perso(pers perso);
void initialiser_map (map *m,SDL_Surface *screen,pers *perso) ;
void perso_map(map *m,pers *perso);
void affiche_map(map *m, SDL_Surface *screen,pers *perso);
SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,pers perso);
void collision(SDL_Surface *psurface,pers *perso);


void inittemps(Time *t);
void Timer(int *tempsdebut);
int initTexttime(Text* T);
int loadFonttime(Text* T, char * ch);
void update_time(Time* T);
void displaytime(Time T,SDL_Surface *screen);
void freeTexttime(Text T);





#endif

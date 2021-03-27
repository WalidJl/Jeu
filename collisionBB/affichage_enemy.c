#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"

void affichage_enemy (enemy e , SDL_Surface *screen) 
{

SDL_BlitSurface(e.image, NULL, screen, &(e.position));
SDL_Flip(screen);

}



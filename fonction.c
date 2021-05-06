#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include "fonction.h"
#include <string.h>
void afficherbackground(background b,SDL_Surface *screen)
{
SDL_BlitSurface(b.img,NULL,screen,&b.pos);
SDL_Flip(screen);
}
void initbackground (background *b)
{
b->pos.x=0;
b->pos.y=0;}
void scrolling (background *b,int direction)
{
if ((direction==1)&&((b->pos.x+1250)<4000))
b->pos.x=b->pos.x-10;
if ((direction==2)&&(b->pos.x<0)) 
b->pos.x=b->pos.x+10;
}

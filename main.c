#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include "fonction.h"
#include <string.h>
int main (void)
{
int done=1,direction;
SDL_Surface *screen;
background b;
b.img=IMG_Load("back.png");
SDL_Event event;
SDL_Surface *perso=IMG_Load("complet.png");
SDL_Rect pos;
pos.x=50;
pos.y=600;
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
screen=SDL_SetVideoMode(1250,1000,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
initbackground (&b);
afficherbackground(b,screen);
SDL_BlitSurface(perso,NULL,screen,&pos);
SDL_Flip(screen);
while (done)
{
while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_LEFT)
{
pos.x=pos.x-5;
direction=2;
scrolling (&b,direction);
afficherbackground(b,screen);
SDL_BlitSurface(perso,NULL,screen,&pos);
SDL_Flip(screen);
}
if (event.key.keysym.sym==SDLK_RIGHT)
{
pos.x=pos.x+5;
direction=1;
scrolling (&b,direction);
afficherbackground(b,screen);
SDL_BlitSurface(perso,NULL,screen,&pos);
SDL_Flip(screen);
}
break;
case SDL_QUIT :
done=0;
break;
}
}
}
return 0;}

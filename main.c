#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "pres.h"

int main(void)
{	
		int continuer=1;
	SDL_Surface *screen,*backg,*backgm;
	SDL_Rect backg_pos,backgm_pos;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1300,375,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}

	backg = IMG_Load("2.PNG");
	backg_pos.x = 0;
	backg_pos.y = 0;
	backgm = IMG_Load("mapMasque.png");
	backgm_pos.x = 0;
	backgm_pos.y = 0;
//initialisation du temps et de map et du perso 

	Time temps;
	map m;
	pers perso;
	
	inittemps(&temps);
	initialiser_map (&m,screen,&perso) ;
	initialiserperso(&perso);
	
	SDL_Event event;
	while (continuer)
	{	
	SDL_PollEvent(&event);
     
		update_time(&temps);
		deplacer_perso(&perso,event);
		collision(backgm,&perso);
		perso_map(&m,&perso);
		SDL_BlitSurface(backg,NULL,screen,&backg_pos);
		
		displaytime(temps,screen);
		affiche_map(&m,screen,&perso);
		afficher_perso(screen,perso);
		SDL_Flip(screen);
		SDL_Delay(100);
	}

	freeTexttime(temps.temps);
	free_perso(perso);
	SDL_Quit();

	return 1;
}

#include "pres.h"

void initialiserperso(pers *perso)
{	
	perso->image_p=IMG_Load("hero.bmp");
	perso->pos_perso.x=0;
	perso->pos_perso.y=0;
	perso->pos_perso.w=120;
	perso->pos_perso.h=120;
}

void afficher_perso(SDL_Surface *screen,pers perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}

void deplacer_perso(pers *perso,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            perso->pos_perso.y=perso->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            perso->pos_perso.y=perso->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            perso->pos_perso.x=perso->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            perso->pos_perso.x=perso->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}
void free_perso(pers perso)
{
	SDL_FreeSurface(perso.image_p);
}


void initialiser_map (map *m,SDL_Surface *screen,pers *perso)
{
	m->map=IMG_Load("21.PNG");
	m->pos_map.x = 20;
	m->pos_map.y = 20;

	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,15,25,14,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,220,222,25));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


void perso_map(map *m,pers *perso)
{
	m->perso_pos_map.x=perso->pos_perso.x/5+m->pos_map.x;
	m->perso_pos_map.y=perso->pos_perso.y/5+m->pos_map.y;
}


void affiche_map(map *m , SDL_Surface *screen,pers *perso)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
	SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);
}

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{	
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char* ) pSurface->pixels;
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
	return (color);
}
int  collisionparfaite(SDL_Surface *psurface,pers perso)
{	
	int tabx[7],taby[7],i;
	SDL_Color color1,color;
	color1.r = 0;
	color1.g = 0;
	color1.b = 0;
	tabx[0]=perso.pos_perso.x;
	tabx[1]=(perso.pos_perso.x)+((perso.pos_perso.w)/2);
	tabx[2]=(perso.pos_perso.x+perso.pos_perso.w);
	tabx[3]=perso.pos_perso.x;
	tabx[4]=perso.pos_perso.x;
	tabx[5]=(perso.pos_perso.x)+((perso.pos_perso.w)/2);
	tabx[6]=(perso.pos_perso.x+perso.pos_perso.w);
        tabx[7]=(perso.pos_perso.x+perso.pos_perso.w);
	taby[0]=perso.pos_perso.y;
	taby[1]=perso.pos_perso.y;
	taby[2]=perso.pos_perso.y;
	taby[3]=(perso.pos_perso.y)+((perso.pos_perso.h)/2);
	taby[4]=(perso.pos_perso.y+perso.pos_perso.h);
	taby[5]=(perso.pos_perso.y+perso.pos_perso.h);
	taby[6]=(perso.pos_perso.y+perso.pos_perso.h);
        taby[7]=(perso.pos_perso.y)+((perso.pos_perso.h)/2);
	
	for(i=0;i<8;i++)
	{
	color=getpixel(psurface,tabx[i],taby[i]);
	if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
	{
		return i;

	}
	}
	return 10;
	
}	

void collision(SDL_Surface *psurface,pers *perso)
{	int i;
	i=collisionparfaite(psurface,*perso);

	switch (i)
	{
		case 0 :perso->pos_perso.y=perso->pos_perso.y+12;
			break;
		case 1 :perso->pos_perso.y=perso->pos_perso.y+12;
			 break;
		case 2 :perso->pos_perso.y=perso->pos_perso.y+12;
			break;
		case 3 :perso->pos_perso.x=perso->pos_perso.x+12;
			break;
		case 4 :perso->pos_perso.y=perso->pos_perso.y-12;
			break;
		case 5 :perso->pos_perso.y=perso->pos_perso.y-12; 
			break;
		case 6 :perso->pos_perso.y=perso->pos_perso.y-12; 
			break;
		case 7 :perso->pos_perso.x=perso->pos_perso.x-12;
			break;
		

	}
}

void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}

void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}

int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 205; 
    T->couleurTxt.b = 155;

    strcpy(T->txt, "");
    T->positionText.x = 900;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"Semibold.ttf");
    T->textSurface=NULL;
    return testload;   
}

int loadFonttime(Text* T, char* ch)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(ch,60);
    if (police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;


    T->mm=ts/ 60;
    T->ss=ts % 60;
    
    if(T->mm<10&&T->ss<10)
       sprintf(T->temps.txt," 0%d:0%d  ",T->mm,T->ss);
    else if(T->mm<10&&T->ss>10)
        sprintf(T->temps.txt," 0%d:%d  ",T->mm,T->ss);
    else if(T->mm>10&&T->ss<10)
          sprintf(T->temps.txt," %d:0%d  ",T->mm,T->ss);
    
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}
void displaytime(Time T,SDL_Surface *screen)
{
    
     
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));

}

void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}














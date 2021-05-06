/**
 *@file lot4/minimap.c
 * */
#include "type.h"

/** 
* @brief To initialize The minimap . 
* @param m the minimap
* @param url the url of the image  
* @return Nothing 
*/
void init_map(minimap *m)
{


m->imageDeFond=IMG_Load("lot4/minimap.png");
m->positionFond.x=80;
m->positionFond.y=150;

m->positionFond.h=m->imageDeFond->h;
m->positionFond.w=m->imageDeFond->w;

m->detective = IMG_Load("lot4/testpt.png");
m->positiondetective.x=80;
m->positiondetective.y=190;
m->positiondetective.h=m->detective->h;
m->positiondetective.w=m->detective->w;

}

/** 
* @brief Blit the Minimap .
* @return Nothing 
*/
void affichage_map (minimap m , SDL_Surface *screen) {
SDL_BlitSurface(m.imageDeFond, NULL, screen, &(m.positionFond));
SDL_BlitSurface(m.detective, NULL, screen, &(m.positiondetective));
}

void Timer(int *tempsdebut)
{
    
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
      
      
    }
  
}

/** 
* @brief loadFonttime
* @param T the text
* @param ch
* @return integer
*/ 



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

/** 
* @brief To initialize the time . 
* @param t the Time
* @return Nothing 
*/ 

int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 205; 
    T->couleurTxt.b = 155;

    strcpy(T->txt, "");
    T->positionText.x = 1500;
    T->positionText.y = 20; 
    testload=loadFonttime(T,"lot4/Semibold.ttf");
    T->textSurface=NULL;
    return testload;   
}
/** 
* @brief To initialize the texttime. 
* @param T the text
* @return integer 
*/ 
void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}





/** 
* @brief update_time
* @param T the Time
* @return Nothing 
*/ 


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


/** 
* @brief displaytime
* @param T the Time 
* @param screen the url surface 
* @return Nothing 
*/ 

void displaytime(Time T,SDL_Surface *screen)
{   
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));
}



/** 
* @brief freeTexttime
* @param T the text
* @return Nothing 
*/ 


void freeTexttime(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}


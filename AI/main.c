#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void main()
{
///////////////////////////////////////////////////////////////////////////////DECLARATION///////////////////////////////////////////////////////////////////////////////////////////
SDL_Init (SDL_INIT_EVERYTHING);
TTF_Init();
////////PLAYER TEST 
Personne p;
////////ENEMY
enemy e;
SDL_Event event;
int c=1;

///////screen
SDL_Surface *screen;
screen=SDL_SetVideoMode(2100,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
////////background
SDL_Surface *image;
image=IMG_Load("background2.PNG");


//////////////
SDL_Rect positionEcran={0,0,image->w,image->h};

SDL_Rect Camera={0,100,image->w,image->h};
Uint8 *keys;
//LES FCTS
initPerso(&p);

initEnemy(&e);
//pers1
int colone=0 , ligne=0 ,b=0,acc =0;

//ENEMY
int colone2=0 , ligne2=0,b3=0,STOP=0,collision=0;
/////////////////////////////////////////////////////BOUCLE DE JEU///////////////////////////////////////////////////////////////////////////////////////////////////////////
while (c)
{


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////PERSO1///////////////////////////////////////////////////////////////////////
////ACCELERATION//////
//keys press test
keys=SDL_GetKeyState(NULL);
//Avant
if (keys[SDLK_RIGHT])
{
ligne=1;
Camera.x+=20;
//////////////////////mouvement player//////////////////
if (p.positionEcranPerso.x <= (1550/2))
{
acc = acc +1;
if ( acc < 4 )
{p.positionEcranPerso.x+=20;}
else {p.positionEcranPerso.x+=40;}
}
}




else {ligne=0;colone=0;b=0;p.positionEcranPerso.y=705,Camera.y=100,acc =0;}


/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////ENEMY deplacement
if (p.positionEcranPerso.x >= 250 && STOP == 0)
{
ligne2=1;
e.positionEcranEnemy.x=e.positionEcranEnemy.x-50;
if (e.positionEcranEnemy.x - p.positionEcranPerso.x <= 100)
{
STOP=1;
collision=1;
}
}
//collision
if (collision == 1)
{
ligne2=2;
ligne=3;
//b3 image 1
if (b3 == 1)
{
colone2=1;
colone=1;
p.positionEcranPerso.y=780;
if ( colone2 == 1)
{colone2 = 1;collision=0;STOP=0;ligne2=0;colone2=0;}
}
b3=1;
}





/////////////////////////////////BACKGROUND END////////////////////////////////////////////////////

if (Camera.x<=0)
{Camera.x=0;}

if (Camera.x + screen->w  >= image->w)
{Camera.x=0;}
//p.acceleration-=0.001;
/////////////////////////////////////////////////////////////////////eventS//////////////////////////////////////////////////////////////////////////
while (SDL_PollEvent(&event))
{
switch (event.type)
{
case  SDL_QUIT : 
                 c =  0 ; 
break;
case SDL_KEYDOWN:
if (event.key.keysym.sym == SDLK_ESCAPE)
{c=0;}
///////////////////////////////////////////////

break;
}//switch
}//event
////////////////////////////////////////////////////////////////////////////BLIT////////////////////////////////////////////////////////////////////////
//background
SDL_BlitSurface(image ,&Camera,screen,&positionEcran);
//SDL_Delay(80);
/////////////////////////////////////////PLAYER
SDL_BlitSurface(p.imagepersoAvant[ligne][colone] ,NULL,screen,&p.positionEcranPerso);
////////////////////////////////////////ENEMY
SDL_BlitSurface(e.imageEnemyAvant[ligne2][colone2] ,NULL,screen,&e.positionEcranEnemy);


//à la fin de la boucle de jeu
SDL_Flip(screen);
}
//free
SDL_FreeSurface(screen);
SDL_FreeSurface(image);
SDL_FreeSurface(p.image1);
SDL_FreeSurface(p.image2);
SDL_FreeSurface(p.image4);
SDL_FreeSurface(p.image5);
SDL_FreeSurface(p.image6);
SDL_FreeSurface(e.image1);
SDL_FreeSurface(e.image2);
SDL_FreeSurface(e.image3);
SDL_FreeSurface(e.image4);

SDL_Quit();
}

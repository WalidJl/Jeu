#include "menu.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void main()
{
SDL_Init (SDL_INIT_EVERYTHING);
TTF_Init();
SDL_Event event;
int c=1,mouseX,mouseY;
menu menu;
///////////////////////////////////////////////////////////////////SCREEN//////////////////////////////////////////////////
menu.screen=SDL_SetVideoMode(618,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
///////////////////////////////////////////////////////////////////TEXTE///////////////////////////////////////////////////////
TTF_Font *police;
SDL_Color couleurNoir={0,0,0};
SDL_Rect positionEcrant={20,20};
police=TTF_OpenFont("a.ttf",50);
menu.texte=TTF_RenderText_Blended(police,"GLAUBEN",couleurNoir);
///////////////////////////////////////////////////////////////////////SONFBREF////////////////////////////////////////////////
int bref=0;//start
int bref1=0;//Settings
int bref2=0;//Exit
//////////////////////////////////////////////////////////////////////MUSIC///////////////////////////////////////////////////
if (Mix_OpenAudio(44100,AUDIO_S16SYS,2,1024))
{
printf("%s",Mix_GetError());
}
menu.music = Mix_LoadMUS("music.mp3");
Mix_PlayMusic(menu.music,-80);
///////////////////////////////////////////////////////////////////BACKGROUND//////////////////////////////////////////////////
menu.image=IMG_Load("background.png");
menu.positionEcran.x=0;
menu.positionEcran.y=0;
menu.positionEcran.w=menu.image->w;
menu.positionEcran.h=menu.image->h;
///////////////////////////////////////////////////////////////BUTTONS/////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////START///////////////////////////////////////////////////////////
int p=0; //BLIT//
menu.image1=IMG_Load("Frame 1.png");
menu.image11=IMG_Load("1.png");
menu.positionEcran1.x=90;
menu.positionEcran1.y=140;
menu.positionEcran1.w=menu.image1->w;
menu.positionEcran1.h=menu.image1->h;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////SETTINGS///////////////////////////////////////////////////////////
int p1=0; //BLIT//
menu.image2=IMG_Load("Frame 2.png");
menu.image22=IMG_Load("2.png");
menu.positionEcran2.x=90;
menu.positionEcran2.y=320;
menu.positionEcran2.w=menu.image2->w;
menu.positionEcran2.h=menu.image2->h;
///////////////////////////////////////////////////////////////EXIT///////////////////////////////////////////////////////////
int p2=0; //BLIT//
menu.image3=IMG_Load("Frame 3.png");
menu.image33=IMG_Load("3.png");
menu.positionEcran3.x=90;
menu.positionEcran3.y=510;
menu.positionEcran3.w=menu.image3->w;
menu.positionEcran3.h=menu.image3->h;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                            //BOUCLE DE JEU
while(c)
{
////////////////////EVENTS//////////////////////
while(SDL_PollEvent(&event))
{
/////////////////////////////////////////////////////////////////////////KEY////////////////////////////////////////////////////
switch (event.type)
{
case SDL_KEYDOWN:
if(event.key.keysym.sym == SDLK_ESCAPE) 
c=0; 

if(event.key.keysym.sym == 'j') 
{
startj();
menu.screen=SDL_SetVideoMode(618,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
}

if(event.key.keysym.sym == 'o') 
{optionjeu(menu);}

break;

///////////////////////////////////////////////MOTION//////////////////////////////////////////////////////////////
case SDL_MOUSEMOTION:
SDL_GetMouseState(&mouseX, &mouseY);
////////START_MOTIONS
if(mouseX >= menu.positionEcran1.x  && mouseX <= menu.positionEcran1.x  + menu.positionEcran1.w  && mouseY > menu.positionEcran1.y  && mouseY <= menu.positionEcran1.y  + menu.positionEcran1.h  ) 
{
if ( bref == 0)
{
p=1;
sonc();
bref=1;
}
}
else {p=0;
bref=0;}
//////SETTINGS_MOTION
if(mouseX >= menu.positionEcran2.x  && mouseX <= menu.positionEcran2.x  + menu.positionEcran2.w  && mouseY > menu.positionEcran2.y  && mouseY <= menu.positionEcran2.y  + menu.positionEcran2.h  ) 
{
if (bref1 == 0)
{
p1=1;
sonc();
bref1=1;
}
}
else 
{
p1=0;
bref1=0;
}
//////EXIT_MOTION
if(mouseX >= menu.positionEcran3.x  && mouseX <= menu.positionEcran3.x  + menu.positionEcran3.w  && mouseY > menu.positionEcran3.y  && mouseY <= menu.positionEcran3.y  + menu.positionEcran3.h  ) 
{
if (bref2 ==0)
{
p2=1;
sonc();
bref2=1;
}
}
else {
p2=0;
bref2=0;
}
break;
//////////////////////////////////////////////PRESS/////////////////////////////////////////////////////////////////
case SDL_MOUSEBUTTONDOWN:
SDL_GetMouseState(&mouseX, &mouseY);
if(mouseX >= menu.positionEcran3.x  && mouseX <= menu.positionEcran3.x  + menu.positionEcran3.w  && mouseY > menu.positionEcran3.y  && mouseY <= menu.positionEcran3.y  + menu.positionEcran3.h  ) 
{
c=0;
}

if(mouseX >= menu.positionEcran1.x  && mouseX <= menu.positionEcran1.x  + menu.positionEcran1.w  && mouseY > menu.positionEcran1.y  && mouseY <= menu.positionEcran1.y  + menu.positionEcran1.h  ) 
{
startj();
menu.screen=SDL_SetVideoMode(618,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
}

if(mouseX >= menu.positionEcran2.x  && mouseX <= menu.positionEcran2.x  + menu.positionEcran2.w  && mouseY > menu.positionEcran2.y  && mouseY <= menu.positionEcran2.y  + menu.positionEcran2.h  ) 
{
optionjeu(menu);
}

break;
}//SWITCH
}//POLLEVENT




//////////////////////BLIT//////////////////////
//BACKGROUND
SDL_BlitSurface(menu.image ,NULL,menu.screen,&menu.positionEcran);
//TEXTE
SDL_BlitSurface(menu.texte ,NULL,menu.screen,&positionEcrant);
positionEcrant.x+=20;
if(positionEcrant.x >= menu.screen->w) positionEcrant.x =0;
//START
if (p==0)
{
SDL_BlitSurface(menu.image1 ,NULL,menu.screen,&menu.positionEcran1);
}
else SDL_BlitSurface(menu.image11 ,NULL,menu.screen,&menu.positionEcran1);
//SETTINGS
if (p1==0)
{
SDL_BlitSurface(menu.image2 ,NULL,menu.screen,&menu.positionEcran2);
}
else SDL_BlitSurface(menu.image22 ,NULL,menu.screen,&menu.positionEcran2);
//EXIT
if (p2==0)
{
SDL_BlitSurface(menu.image3 ,NULL,menu.screen,&menu.positionEcran3);
}
else SDL_BlitSurface(menu.image33 ,NULL,menu.screen,&menu.positionEcran3);

SDL_Flip(menu.screen);
}
//FREE
TTF_CloseFont(police);
TTF_Quit();
Mix_FreeMusic(menu.music);
SDL_FreeSurface(menu.screen);
SDL_FreeSurface(menu.texte);
SDL_FreeSurface(menu.image);
SDL_FreeSurface(menu.image1);
SDL_FreeSurface(menu.image11);
SDL_FreeSurface(menu.image2);
SDL_FreeSurface(menu.image22);
SDL_FreeSurface(menu.image3);
SDL_FreeSurface(menu.image33);
SDL_Quit();
}

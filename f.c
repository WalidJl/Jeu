#include "menu.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void sonc()
{
Mix_Chunk *son;
son=Mix_LoadWAV("button-3.wav");
Mix_PlayChannel(1,son,0);
}
/////////////////////////////////////////////STARRRRRRRRRRRRT/////////////////////////////////////
void startj()
{
int c=1,mouseX,mouseY;
start start;
SDL_Event event;
////////////////////////////////////////////////////////////////screen///////////////////////////////////////////////////////////////////////
start.screen=SDL_SetVideoMode(1500,800,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
//////////////////////////////////////////////////////////////BACKGROUND////////////////////////////////////////////////////////////////////
start.image1=IMG_Load("start.PNG");
start.positionEcran.x=0;
start.positionEcran.y=0;
start.positionEcran.w=start.image1->w;
start.positionEcran.h=start.image1->h;
/////////////////////////////////////////////////////////////BUTTONBACK/////////////////////////////////////////////////////////////////////
int b=0;
start.image=IMG_Load("back1.png");
start.positionEcranback.x=20;
start.positionEcranback.y=40;
start.positionEcranback.w=start.image->w;
start.positionEcranback.h=start.image->h;

start.image2=IMG_Load("BACK.png");
start.positionEcranback.x=20;
start.positionEcranback.y=40;
start.positionEcranback.w=start.image2->w;
start.positionEcranback.h=start.image2->h;
while(c)
{
////////////////////////////////////////////////////////////////EVENTS///////////////////////////////////////////////////////////////////////
while(SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_KEYDOWN:
if(event.key.keysym.sym == SDLK_ESCAPE) 
{
return;
}
break;

case SDL_MOUSEMOTION:
SDL_GetMouseState(&mouseX, &mouseY);
if(mouseX >= start.positionEcranback.x  && mouseX <= start.positionEcranback.x  + start.positionEcranback.w  && mouseY > start.positionEcranback.y  && mouseY <= start.positionEcranback.y  + start.positionEcranback.h ) 
{
b=1;
}
else b=0;
break;

case SDL_MOUSEBUTTONDOWN:
SDL_GetMouseState(&mouseX, &mouseY);

//BACK
if(mouseX >= start.positionEcranback.x  && mouseX <= start.positionEcranback.x  + start.positionEcranback.w  && mouseY > start.positionEcranback.y  && mouseY <= start.positionEcranback.y  + start.positionEcranback.h ) 
{
return;
}

}//switch
}//event

///////////////////////////////////////////////////////////BLIT////////////////////////////////////
SDL_BlitSurface(start.image1 ,NULL,start.screen,&start.positionEcran);
if (b == 0)
{SDL_BlitSurface(start.image ,NULL,start.screen,&start.positionEcranback);}
else
{SDL_BlitSurface(start.image2 ,NULL,start.screen,&start.positionEcranback);}

SDL_Flip(start.screen);
}
SDL_FreeSurface(start.screen);
SDL_Quit();
}
/////////////////////////////////////////////////////////////////OPTIOOOOOOOOOOOOOOOOOOON/////////////////////////////////////////////////////////////
void optionjeu(menu menu)
{
int c=1,mouseX,mouseY;
SDL_Event event;
option option;
////////////////////////////////////////////////////DECLARATION/////////////////////////////////////////////////
//background
option.image=IMG_Load("settings.png");
option.positionEcran.x=0;
option.positionEcran.y=0;
option.positionEcran.w=option.image->w;
option.positionEcran.h=option.image->h;
//back
int b=0;
option.image52=IMG_Load("BACK.png");
option.image2=IMG_Load("back1.png");
option.positionEcranBack.x=70;
option.positionEcranBack.y=625;
option.positionEcranBack.w=option.image2->w;
option.positionEcranBack.h=option.image2->h;
//save
int s=0;
option.image32=IMG_Load("SAVE.png");
option.image12=IMG_Load("save1.png");
option.positionEcranSave.x=299;
option.positionEcranSave.y=625;
option.positionEcranSave.w=option.image2->w;
option.positionEcranSave.h=option.image2->h;
//fullscreen
int FS=0;
option.image3=IMG_Load("fullscreen.png");
option.image33=IMG_Load("11.png");
option.positionEcranFS.x=100;
option.positionEcranFS.y=470;
option.positionEcranFS.w=option.image3->w;
option.positionEcranFS.h=option.image3->h;
//VOLUME
option.image4=IMG_Load("+0.png");
option.image5=IMG_Load("+2.png");
option.image6=IMG_Load("+4.png");
option.image7=IMG_Load("+6.png");
option.image8=IMG_Load("+8.png");
option.image9=IMG_Load("+.png");
option.image10=IMG_Load("-.png");
///////MOINS//////
option.positionEcranMoins.x=190;
option.positionEcranMoins.y=295;
option.positionEcranMoins.w=option.image10->w;
option.positionEcranMoins.h=option.image10->h;
//////PLUS/////
option.positionEcran;
option.positionEcranPlus.x=370;
option.positionEcranPlus.y=295;
option.positionEcranPlus.w=option.image9->w;
option.positionEcranPlus.h=option.image9->h;
//////VOL//////
option.positionEcranVol.x=100;
option.positionEcranVol.y=280;
option.positionEcranVol.w=option.image10->w;
option.positionEcranVol.h=option.image10->h;
option.tab[0]=option.image4;
option.tab[1]=option.image5;
option.tab[2]=option.image6;
option.tab[3]=option.image7;
option.tab[4]=option.image8;
int indice=4,volume=128,off=0;
/////MUTE///////
option.image11=IMG_Load("music on 1.png");
option.image22=IMG_Load("music off 1.png");
option.positionEcranMUSIC.x=520;
option.positionEcranMUSIC.y=280;
option.positionEcranMUSIC.w=option.image11->w;
option.positionEcranMUSIC.h=option.image11->h;

//////////////////////////
while(c)
{
////////////////////////////////////////////////////////////////EVENTS///////////////////////////////////////////////////////////////////////
while(SDL_PollEvent(&event))
{
switch (event.type)
{


case SDL_KEYDOWN:
if(event.key.keysym.sym == SDLK_ESCAPE) 
{
return;
}
break;

case SDL_MOUSEMOTION:
SDL_GetMouseState(&mouseX, &mouseY);
if(mouseX >= option.positionEcranBack.x  && mouseX <= option.positionEcranBack.x  + option.positionEcranBack.w  && mouseY > option.positionEcranBack.y  && mouseY <= option.positionEcranBack.y  + option.positionEcranBack.h ) 
{
b=1;
}
else b=0;

if(mouseX >= option.positionEcranSave.x  && mouseX <= option.positionEcranSave.x  + option.positionEcranSave.w  && mouseY > option.positionEcranSave.y  && mouseY <= option.positionEcranSave.y  + option.positionEcranSave.h ) 
{
s=1;
}
else s=0;
break;

case SDL_MOUSEBUTTONDOWN:
SDL_GetMouseState(&mouseX, &mouseY);

//BACK
if(mouseX >= option.positionEcranBack.x  && mouseX <= option.positionEcranBack.x  + option.positionEcranBack.w  && mouseY > option.positionEcranBack.y  && mouseY <= option.positionEcranBack.y  + option.positionEcranBack.h ) 
{
return;
}
//FS
if(mouseX >= option.positionEcranFS.x  && mouseX <= option.positionEcranFS.x  + option.positionEcranFS.w  && mouseY > option.positionEcranFS.y  && mouseY <= option.positionEcranFS.y  + option.positionEcranFS.h ) 
{
sonc();
FS=!FS;
if (FS == 0)
{
menu.screen = SDL_SetVideoMode(618,800,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}
else 
{
menu.screen = SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
}
}
//+
if(mouseX >= option.positionEcranPlus.x  && mouseX <= option.positionEcranPlus.x  + option.positionEcranPlus.w  && mouseY > option.positionEcranPlus.y  && mouseY <= option.positionEcranPlus.y  + option.positionEcranPlus.h ) 
{
sonc();
indice ++;
off=0;
volume+=32;
if (indice >4)
{
indice=4;
volume =128;
}
Mix_VolumeMusic(volume);
}
//-
if(mouseX >= option.positionEcranMoins.x  && mouseX <= option.positionEcranMoins.x  + option.positionEcranMoins.w  && mouseY > option.positionEcranMoins.y  && mouseY <= option.positionEcranMoins.y  + option.positionEcranMoins.h) 
{
sonc();
indice --;
volume-=32;
if (indice <=0)
{
off =1;
indice = 0;
volume=0;
}
Mix_VolumeMusic(volume);
}
//mute
if(mouseX >= option.positionEcranMUSIC.x  && mouseX <= option.positionEcranMUSIC.x  + option.positionEcranMUSIC.w  && mouseY > option.positionEcranMUSIC.y  && mouseY <= option.positionEcranMUSIC.y  + option.positionEcranMUSIC.h)
{
sonc();
off=!off;
indice=0;
volume=0;
Mix_VolumeMusic(volume);
}
break;


}//switch
}//event
///////////////////////////////////////////////////////////BLIIIIIIIIIIIIIIIIIIIIT//////////////////////////////////////////////////////////////////////////////////
SDL_FillRect(menu.screen,0,SDL_MapRGB(menu.screen->format,0,0,0));
//BACKGROUND
SDL_BlitSurface(option.image ,NULL,menu.screen,&option.positionEcran);
//BACK
if (b == 1)
SDL_BlitSurface(option.image52 ,NULL,menu.screen,&option.positionEcranBack);
else SDL_BlitSurface(option.image2 ,NULL,menu.screen,&option.positionEcranBack);
//SAVE
if (s == 1)
SDL_BlitSurface(option.image32 ,NULL,menu.screen,&option.positionEcranSave);
else SDL_BlitSurface(option.image12 ,NULL,menu.screen,&option.positionEcranSave);
//FS
if (FS ==0)
{
SDL_BlitSurface(option.image33 ,NULL,menu.screen,&option.positionEcranFS);
}
else 
{
SDL_BlitSurface(option.image3 ,NULL,menu.screen,&option.positionEcranFS);
}
//Volume
SDL_BlitSurface(option.image10 , NULL,menu.screen,&option.positionEcranMoins);
SDL_BlitSurface(option.tab[indice] , NULL,menu.screen,&option.positionEcranVol);
SDL_BlitSurface(option.image9 , NULL,menu.screen,&option.positionEcranPlus);
//MUTE
if (off == 0)
{SDL_BlitSurface(option.image11 , NULL,menu.screen,&option.positionEcranMUSIC);}
else {SDL_BlitSurface(option.image22 , NULL,menu.screen,&option.positionEcranMUSIC);}

SDL_Flip(menu.screen);
}
SDL_FreeSurface(menu.screen);
SDL_FreeSurface(option.image);
SDL_FreeSurface(option.image2);
SDL_FreeSurface(option.image3);
SDL_FreeSurface(option.image12);
SDL_FreeSurface(option.image33);
SDL_Quit();
}


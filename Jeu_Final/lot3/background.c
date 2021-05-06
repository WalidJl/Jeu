/**
 *@file lot3/background.c
 * */
#include "type.h"
void InitBackground(background *b)
{
//Background1
b->image=IMG_Load("lot3/BG.png");
//Background2
b->image1=IMG_Load("lot3/BG2.PNG");
//Checkpoints
b->checkpoint1=IMG_Load("lot3/women 3.png");
b->checkpoint2=IMG_Load("lot3/11.png");
//traps
b->traps=IMG_Load("lot3/traps.PNG");
//win
b->win=IMG_Load("lot3/win.png");
//menu
b->menu=IMG_Load("lot3/background.png");
b->newgame=IMG_Load("lot3/new game.png");
b->save=IMG_Load("lot3/save.png");
b->load=IMG_Load("lot3/load.png");
b->exit=IMG_Load("lot3/exit.png");
//////////////////////////POSITIONS//////////////////////////////////
SDL_Rect positionEcran={0,0,b->image->w,b->image->h};
SDL_Rect Camera={0,100,b->image->w,b->image->h};
SDL_Rect cp1={2200,600,b->checkpoint1->w,b->checkpoint1->h};
SDL_Rect cp2={2200,600,b->checkpoint1->w,b->checkpoint1->h};
SDL_Rect trapsP={1000,650,b->traps->w,b->traps->h};
SDL_Rect winP={0,0,b->win->w,b->win->h};

SDL_Rect menuP={0,0,b->menu->w,b->menu->h};
SDL_Rect newgameP={600,400,b->newgame->w,b->newgame->h};
SDL_Rect saveP={800,400,b->save->w,b->save->h};
SDL_Rect loadP={1000,400,b->load->w,b->load->h};
SDL_Rect exitP={800,600,b->exit->w,b->exit->h};

b->positionEcran=positionEcran;
b->Camera=Camera;
b->cp1=cp1;
b->cp2=cp2;
b->trapsP=trapsP;
b->winP=winP;

b->menuP=menuP;
b->newgameP=newgameP;
b->saveP=saveP;
b->loadP=loadP;
b->exitP=exitP;

}

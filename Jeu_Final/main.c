/** 
* @file main.c 
* @brief Testing Program. 
* @author Glauben
* @version 0.1 
* @date Apr 21, 2021
* 
* Testing program for background scrollilng * 
*/

#include "main.h"

//(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
void main()
{
///////////////////////////////////////////////////////////////////////////////DECLARATION///////////////////////////////////////////////////////////////////////////////////////////
SDL_Init (SDL_INIT_EVERYTHING);
TTF_Init();
//MUSIC
Mix_Music *music;
if (Mix_OpenAudio(44100,AUDIO_S16SYS,2,1024))
{
printf("%s",Mix_GetError());
}
music = Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-80);
///////////8/////////////////////////////////
///BACKGROUND///
background bg;
InitBackground(&bg);
////////////////
/////////TIME//////////
Time temps;
inittemps(&temps);
///////////////////////
//pers
int succes=0,succes1=0,partage=0,level2=0,argc;
char argv[5];
Personne p,p1;
//partage
int BlitEnemy1=1,hurt1=0,STOP1=0,i1=5;
//enemy
//
enemy e;
enemy e1;
initEnemy(&e);
initEnemy(&e1);


SDL_Event event;
int c=1,mouseX,mouseY,menu=0,endmenu=0;
Uint32 dt, t_prev;
//screen
SDL_Surface *screen;
screen=SDL_SetVideoMode(2100,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
///////PARTAGE//////////////////
SDL_Surface *imageP1;
SDL_Surface *imageP2;
imageP1=IMG_Load("MiniBG.png");
imageP2=IMG_Load("MiniBG1.png");

//pour perso 2
//2backgrounds
//////////////
//SDL_Rect positionEcran={0,0,image->w,image->h};
SDL_Rect positionEcranMini1={0,0,imageP1->w,imageP1->h};
SDL_Rect positionEcranMini2={0,imageP1->h,imageP2->w,imageP2->h};
//pour perso 2
//2 positions
//////////////
//SDL_Rect Camera={0,100,image->w,image->h};
SDL_Rect Camera2={0,100,imageP2->w,imageP2->h};
//camera partage
//keys
Uint8 *keys;
//LES FCTS
initPerso(&p);
initPerso2(&p1);
///minimap
minimap m;
init_map(&m);
//pers1
int colone=0 , ligne=0 ,b=0,acc =0,ult=0,stopi = 2,done,done1,i=5;
//pers2
int perso2=1;
int colone1=0 , ligne1=0,acc1=0,b7=0;
//enemy
int colone2=0,ligne2=0,BlitEnemy=1,STOP=0,hurt=0,ligne22=0,colone22=0;
/////////////////////////////////////////////////////LEVELS///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////BOUCLE DE JEU///////////////////////////////////////////////////////////////////////////////////////////////////////////
while (c)
{
t_prev=SDL_GetTicks();//au début de la boucle de jeu
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////PERSO1///////////////////////////////////////////////////////////////////////
////ACCELERATION//////
//keys press test
keys=SDL_GetKeyState(NULL);
//Avant
if (keys[SDLK_RIGHT])
{
moveRight(&ligne,&p,&bg.Camera,&m);
}
//}
//ARRIERE
else if (keys[SDLK_LEFT])
{
moveLeft(&ligne,&p,&bg.Camera,&m);
}
/**/
//JUMP
else if (keys[SDLK_SPACE])
{
jump(&ligne,&p,&bg.Camera,&acc,&p1);
e.positionEcranEnemy.y=740;
}
//SLAP
else if (keys['e'])
{
slap(&ligne,&colone,&b);
}
//ULT 
else if (keys['r'])
{
ulti(&ligne,&colone,&ult,&p);
}
//DEATH
else if (keys['$'])
{
death(&ligne,&colone,&b,&p);
}
else if (keys['='])
{
sprint(&ligne,&p,&bg.Camera);
acc =7;
stopi=1;
}

else 
{ 
//stop apres le sprint
if (stopi == 1)
{stop(&ligne,&p,&bg.Camera,&acc,&colone,&done);}
//if ( acc == 0}
//stopi=0;
if (done == 1 ) {stopi=0;done1=1;}
if (stopi == 0) 
{
ligne=0;colone=0;b=0;
if ( level2 == 0)
{p.positionEcranPerso.y=625;}
bg.Camera.y=100;ult=0;p.ult.x= p.positionEcranPerso.x + p.image11->w + 5;p1.positionEcranPerso.y=630;done=0;
}
else {
ligne=0;colone=0;b=0;
if ( level2 == 0)
{p.positionEcranPerso.y=625;}
bg.Camera.y=100;ult=0;p.ult.x= p.positionEcranPerso.x + p.image11->w + 5;p1.positionEcranPerso.y=630;e.positionEcranEnemy.y=640;
}
}
///////////////////////////////ENIGME///////////////////////////////

////////ENIGME1///////
if (( bg.Camera.x >= (bg.cp1.x/1.6) || Camera2.x >= (positionEcranMini2.w/2) ) && succes == 0)
{succes=Enigme();
screen=SDL_SetVideoMode(2100,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);}
//////////////////////

//////ENIGME2////////
if (level2 == 1 && bg.Camera.x >= (bg.cp2.x/1.6) && succes1 == 0 )
{
succes1=EnigmeSansFichier();
screen=SDL_SetVideoMode(2100,900,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
}
////////////////////

//////LEVEL2////////
if (succes == 1 && level2==0)
{
p.positionEcranPerso.x=0;
bg.Camera.x=0;
level2=1;
}
//traps
if ( level2 == 1)
{
	if (bg.Camera.x >= 500 && bg.Camera.x <= 1000)
	{
	p.positionEcranPerso.y=450;
	}
 	else
	{
 	p.positionEcranPerso.y=630;
	}
}
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////PARTAGE/////////////////////////////////////////////////
if (partage == 1)
{
//perso
p.positionEcranPerso.y=705;
//enemy
e.positionEcranEnemy.y=720;
//ult
p.ult.y= 735;
//pers2
p1.positionEcranPerso.y=230;
//vie
p.positionEcranVie.x=1400;
//enemy2
e1.positionEcranEnemy.y=215;
//minimap
m.positionFond.y=0;
m.positiondetective.y=35;
//////////////////FCTS FOR ENEMY2////////////////////
if (p1.positionEcranPerso.x < 250)
    { deplacement_enemy_aleatoire(&e1);}
if (STOP1 == 0)
{DeplacementEnemy(&e1 ,p1,&colone22,&ligne22);}
if (hurt1 == 0 && BlitEnemy1 == 1 && i1!=0)
{EnemyAttack(e1 ,p1,&colone22,&ligne22,&STOP1,&hurt1);}

//perso hurt
else if (hurt1 == 1)
{
i1=i1-1;
hurt1=0;
}

//Death
//enemy
EnemyDeath2(p1,e1,&BlitEnemy1,ligne1);
//perso
if (i1 == 0)
{perso2=0;}	
//////////////////////////////////////////////////
if (keys['d'])
{
ligne1=1;
Camera2.x+=20;
///milieu de ecran///
if (p1.positionEcranPerso.x <= (1550/2))
{
acc1 = acc1 +1;
if ( acc1 < 4 )
{p1.positionEcranPerso.x+=20;}
else {p1.positionEcranPerso.x+=40;}
}
}
//ARRIERE
else if (keys['q'])
{
ligne1=1;
Camera2.x-=20;
acc1 = acc1 +1;
if (acc1 < 4)
{p1.positionEcranPerso.x-=20;}
else {p1.positionEcranPerso.x-=40;}
}
//JUMP
else if (keys['z'])
{
ligne1=4;
p1.positionEcranPerso.y=180;
Camera2.y=0;
}
//ATTA
else if (keys['x'])
{
ligne1=5;
if  (b7 == 1)
{
colone1=colone1+1;
if (colone1 >= 4)
{
colone1 = 4;
colone1=0;
}
}
b7=1;
}

else {ligne1=0;colone1=0;acc1=0;p.positionEcranPerso.y=705,b7=0;Camera2.y=100;}
}
////////////////////NON PARTAGE//////////////////////
else if (partage == 0)
{
if (level2 ==0)
{p.positionEcranPerso.y=625;}
e.positionEcranEnemy.y=640;
p.ult.y= 655;
p1.positionEcranPerso.y=630;
p.positionEcranVie.x=80;
m.positionFond.y=150;m.positiondetective.y=190;
}
///////////////////////ENEMY//////////////////////
//deplacement

if (p.positionEcranPerso.x < 250)
    { deplacement_enemy_aleatoire(&e);}
if (STOP == 0)
{DeplacementEnemy(&e ,p,&colone2,&ligne2);}

//attack
if (hurt == 0 && BlitEnemy == 1 && i!=0)
{EnemyAttack(e ,p,&colone2,&ligne2,&STOP,&hurt);}

//perso hurt
else if (hurt == 1)
{
hurtperso(&ligne,&colone,&hurt);
i=i-1;
hurt=0;
}

//Death
EnemyDeath(e , p,&BlitEnemy,ligne);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////END OF BACKGROUND/////////////////////////////////////////////////////////////////
if (bg.Camera.x<=0)
{bg.Camera.x=0;}
if (Camera2.x<=0)
{Camera2.x=0;}

if (bg.Camera.x + screen->w  >= bg.image->w)
{bg.Camera.x=0;}
if (Camera2.x + screen->w  >= imageP1->w)
{Camera2.x=0;}
//p.acceleration-=0.001;
//////////////////////////////////////////////////////////////////////eventS//////////////////////////////////////////////////////////////////////////
///////////
while (SDL_PollEvent(&event))
{
switch (event.type)
{
/////////////////////////////////////////////////////////////////BUTTONPRESSS//////////////////////////////////////////////////////////
case SDL_KEYDOWN:
if (event.key.keysym.sym == SDLK_ESCAPE)
{endmenu=!endmenu;}
///////////////////////////////////////////////perso2
if(event.key.keysym.sym == 'm') 
{
perso2=!perso2;
}
if(event.key.keysym.sym == 'w') 
{
partage=!partage;
}
////SAVE_AND_LOAD////
if(event.key.keysym.sym == 's') 
{
save(p,bg,"save.txt",e,BlitEnemy,m,i,level2,temps);
}
/////////////////////
break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////MOUSEPRESS///////////////////////////////////////////////////////////
case SDL_MOUSEBUTTONDOWN:
SDL_GetMouseState(&mouseX, &mouseY);
if(mouseX >= bg.newgameP.x  && mouseX <= bg.newgameP.x  + bg.newgameP.w  && mouseY > bg.newgameP.y  && mouseY <= bg.newgameP.y  + bg.newgameP.h  ) 
{
menu=!menu;
}
else if(mouseX >= bg.exitP.x  && mouseX <= bg.exitP.x  + bg.exitP.w  && mouseY > bg.exitP.y  && mouseY <= bg.exitP.y  + bg.exitP.h  ) 
{
c=0;
}
else if(mouseX >= bg.loadP.x  && mouseX <= bg.loadP.x  + bg.loadP.w  && mouseY > bg.loadP.y  && mouseY <= bg.loadP.y  + bg.loadP.h  ) 
{
load(&p,  &bg ,"save.txt",&e,&BlitEnemy,&m,&i,&level2,&temps);
menu=!menu;
}
else if(mouseX >= bg.saveP.x  && mouseX <= bg.saveP.x  + bg.saveP.w  && mouseY > bg.saveP.y  && mouseY <= bg.saveP.y  + bg.saveP.h  ) 
{
save(p,bg,"save.txt",e,BlitEnemy,m,i,level2,temps);
menu=!menu;
}
break;



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}//switch
}//event
update_time(&temps);
SDL_FillRect(screen,0,SDL_MapRGB(screen->format,0,0,0));
////////////////////////////////////////////////////////////////////////////BLIT////////////////////////////////////////////////////////////////////////
//background
if (partage == 0)
{
	//level1
	if (level2 == 0)
	{
SDL_BlitSurface(bg.image ,&bg.Camera,screen,&bg.positionEcran);
SDL_BlitSurface(bg.checkpoint1,NULL,bg.image,&bg.cp1);
	}
        //level2
	else
	{
SDL_BlitSurface(bg.image1 ,&bg.Camera,screen,&bg.positionEcran);
SDL_BlitSurface(bg.checkpoint2,NULL,bg.image1,&bg.cp2);
SDL_BlitSurface(bg.traps ,NULL,bg.image1,&bg.trapsP);
	}
}
else if (partage == 1)
{
SDL_BlitSurface(imageP1 ,&Camera2,screen,&positionEcranMini1);
SDL_BlitSurface(imageP2 ,&bg.Camera,screen,&positionEcranMini2);
if (perso2 == 1)
{SDL_BlitSurface(p1.imagepersoAvant[ligne1][colone1] ,NULL,screen,&p1.positionEcranPerso);}
}
affichage_map (m,screen);
SDL_Delay(50);
//////minimap

/////////////////////////////////////////perso1
//void afficher(&P)
if(i>0)
{SDL_BlitSurface(p.vie[i] ,NULL,screen,&p.positionEcranVie);}
if(i==0)
{
SDL_BlitSurface(p.vie[0] ,NULL,screen,&p.positionEcranVie);
death(&ligne,&colone,&b,&p);
SDL_BlitSurface(p.end,NULL,screen,&p.positionEcranEnd);
}
//death
if (ligne == 3 && colone == 1)
{
p.positionEcranDeath.x=p.positionEcranPerso.x;
p.positionEcranDeath.y=675;
p.positionEcranDeath.h=p.image13->h;
p.positionEcranDeath.w=p.image13->w;
SDL_BlitSurface(p.image13 ,NULL,screen,&p.positionEcranDeath);
} 
SDL_BlitSurface(p.imagepersoAvant[ligne][colone] ,NULL,screen,&p.positionEcranPerso);


//afficherPerso(p,ligne ,colone,screen);
//ult
if (ult == 1)
{SDL_BlitSurface(p.image12 ,NULL,screen,&p.ult);}
///////////////////////////////////////perso2

dt=SDL_GetTicks()-t_prev;//à la fin de la boucle de jeu
///enemy///
if (BlitEnemy == 1)
{SDL_BlitSurface(e.imageEnemyAvant[ligne2][colone2] ,NULL,screen,&e.positionEcranEnemy);}
if (partage == 1)
{if (BlitEnemy1 == 1){SDL_BlitSurface(e1.imageEnemyAvant[ligne22][colone22] ,NULL,screen,&e1.positionEcranEnemy);}}
///time///
displaytime(temps,screen);
/////////
//////////////////WIN/////////////////////
if (succes1 == 1)
{
SDL_BlitSurface(bg.win,NULL,screen,&bg.winP);
}
///MENU///
if (menu == 0)
{
SDL_BlitSurface(bg.menu ,NULL,screen,&bg.menuP);
SDL_BlitSurface(bg.load ,NULL,screen,&bg.loadP);
SDL_BlitSurface(bg.newgame ,NULL,screen,&bg.newgameP);
SDL_BlitSurface(bg.exit ,NULL,screen,&bg.exitP);
}
if (endmenu == 1)
{
SDL_BlitSurface(bg.menu ,NULL,screen,&bg.menuP);
SDL_BlitSurface(bg.save ,NULL,screen,&bg.saveP);
SDL_BlitSurface(bg.exit ,NULL,screen,&bg.exitP);
}
SDL_Flip(screen);
}
//free
SDL_FreeSurface(screen);
SDL_FreeSurface(bg.image);
SDL_FreeSurface(p.score);
SDL_FreeSurface(p.image1);
SDL_FreeSurface(p.image2);
SDL_FreeSurface(p.image3);
SDL_FreeSurface(p.image4);
SDL_FreeSurface(p.image5);
SDL_FreeSurface(p.image6);
SDL_FreeSurface(p.image7);
SDL_FreeSurface(p.image8);
SDL_FreeSurface(p.image9);
SDL_FreeSurface(p.image11);
SDL_FreeSurface(p.image12);
freeTexttime(temps.temps);
Mix_FreeMusic(music);
SDL_Quit();
}//

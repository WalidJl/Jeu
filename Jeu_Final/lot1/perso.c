/**
 *@file lot1/perso.c
 * */
#include "type.h"
void initPerso(Personne *p)
{
//perso
p->image1 =IMG_Load("lot1/perso.png");
p->image2 =IMG_Load("lot1/walk.png");
p->image3 =IMG_Load("lot1/arriere.png");
p->imagepersoAvant[0][0]=p->image1;
p->imagepersoAvant[1][0]=p->image2;
p->imagepersoAvant[2][0]=p->image3;
//death
p->image4 =IMG_Load("lot1/death etape 1.png");
p->image5 =IMG_Load("lot1/death etape 2.png");
p->image13=IMG_Load("lot1/111.png");
p->imagepersoAvant[3][0]=p->image4;
p->imagepersoAvant[3][1]=p->image5;
//jump
p->image6 =IMG_Load("lot1/jump 2.png");
p->imagepersoAvant[4][0]=p->image6;
//SLAP
p->image7 =IMG_Load("lot1/slap 1.png");
p->image8 =IMG_Load("lot1/slap 2.png");
p->image9 =IMG_Load("lot1/slap 3.png");
p->image10=IMG_Load("lot1/slap 4.png");
p->imagepersoAvant[5][0]=p->image7;
p->imagepersoAvant[5][1]=p->image8;
p->imagepersoAvant[5][2]=p->image9;
p->imagepersoAvant[5][3]=p->image10;
//ULT
p->image11 =IMG_Load("lot1/hand + candy.png");
p->image12 =IMG_Load("lot1/candy ball.png");
p->imagepersoAvant[6][0]=p->image11;
/////////////////////////////////////////////
//perso
p->positionEcranPerso.x=0;
p->positionEcranPerso.y=625;
p->positionEcranPerso.h=p->image2->h;
p->positionEcranPerso.w=p->image2->w;
//ult
p->ult.x= p->positionEcranPerso.x + p->image11->w + 5;
p->ult.y= 655;
p->ult.h=p->image12->h;
p->ult.w=p->image12->w;
//score
p->score=IMG_Load("lot1/back1.png");
p->positionEcranScore.x=10;
p->positionEcranScore.y=40;
p->positionEcranScore.h=p->score->h;
p->positionEcranScore.w=p->score->w;
//vie
p->image000 =IMG_Load("lot1/score 00.png");
p->image111 =IMG_Load("lot1/score 11.png");
p->image222 =IMG_Load("lot1/score 22.png");
p->image333 =IMG_Load("lot1/score 33.png");
p->image444 =IMG_Load("lot1/score 44.png");
p->image555 =IMG_Load("lot1/score 55.png");

p->vie[0]=p->image000;
p->vie[1]=p->image111;
p->vie[2]=p->image222;
p->vie[3]=p->image333;
p->vie[4]=p->image444;
p->vie[5]=p->image555;

p->positionEcranVie.x=80;
p->positionEcranVie.y=30;
p->positionEcranVie.h= p->image111->h;
p->positionEcranVie.w= p->image111->w;
//end
p->end=IMG_Load("lot1/game over.png");

p->positionEcranEnd.x=800;
p->positionEcranEnd.y=400;
p->positionEcranEnd.h=p->end->h;
p->positionEcranEnd.w=p->end->w;
//vitesse et acc
p->vitesse=5;
p->acceleration=0;
}
////////////////////////////////PERSO2/////////////////////////////////
void initPerso2(Personne *p1)
{
//pers
//stand and walk
p1->image1 =IMG_Load("lot1/stand1.png");
p1->image2 =IMG_Load("lot1/walk1.png");
p1->imagepersoAvant[0][0]=p1->image1;
p1->imagepersoAvant[1][0]=p1->image2;
//jump
p1->image3 =IMG_Load("lot1/jump1.png");
p1->imagepersoAvant[4][0]=p1->image3;
//ATTA
p1->image4 =IMG_Load("lot1/att 1.png");
p1->image5 =IMG_Load("lot1/att 2.png");
p1->image6 =IMG_Load("lot1/att 3.png");
p1->image7 =IMG_Load("lot1/att 4.png");
p1->image8 =IMG_Load("lot1/att 5.png");
p1->imagepersoAvant[5][0]=p1->image4;
p1->imagepersoAvant[5][1]=p1->image5;
p1->imagepersoAvant[5][2]=p1->image6;
p1->imagepersoAvant[5][3]=p1->image7;
p1->imagepersoAvant[5][4]=p1->image7;

p1->positionEcranPerso.x=0;
p1->positionEcranPerso.y=630;
p1->positionEcranPerso.h=p1->image1->h;
p1->positionEcranPerso.w=p1->image1->w;
///////////////////////////////////
}
////////////////////LEFT/////////////
void moveLeft(int *ligne,Personne *p,SDL_Rect *Camera,minimap *m)
{
*ligne=2;
(*Camera).x-=20;
(*p).positionEcranPerso.x-=20;
if ((*m).positiondetective.x < 80)
{(*m).positiondetective.x = 80;}
else {(*m).positiondetective.x-=1;}

}
//////////////////RIGHT//////////////////////
void moveRight(int *ligne,Personne *p,SDL_Rect *Camera,minimap *m)
{
*ligne=1;
(*Camera).x+=20;
//milieu de ecran//
if ((*p).positionEcranPerso.x <= (1550/2))
{
(*p).positionEcranPerso.x+=20;
}
m->positiondetective.x=m->positiondetective.x+1;
}
/////////////////////SPRINT///////////////////////
void sprint(int *ligne,Personne *p,SDL_Rect *Camera)
{
*ligne=1;
(*Camera).x+=20;
//milieu de ecran//
if ((*p).positionEcranPerso.x <= (1550/2))
{
{(*p).positionEcranPerso.x+=50;}
}
}
/////////////////////STOP/////////////////////////
void stop(int *ligne,Personne *p,SDL_Rect *Camera,int *acc,int *colone,int *done)
{
*ligne=1;
if (*acc > 0 )
{
*acc = *acc -1;
//milieu de ecran//
if ((*p).positionEcranPerso.x <= (1550/2))
{
(*p).positionEcranPerso.x+=20;
}
}
if (*acc <= 0)
{*acc =0;*ligne =0 ; *colone =0;*done=1;}
}
///////////////////JUMP///////////////////////////
void jump(int *ligne,Personne *p,SDL_Rect *Camera,int *acc,Personne *p1)
{
*ligne=4;
(*p).positionEcranPerso.y=(*p).positionEcranPerso.y+15;
(*p1).positionEcranPerso.y=740;
(*Camera).y=0;
}
/////////////SLAP//////////////////////
void slap(int *ligne,int *colone,int *b)
{
*ligne =5;
if (*b==1)
{*colone = *colone +1;}
//etat final
if ( *colone == 3)
{*colone = 0;
*ligne=0;}
*b=1;
}
/////////////ULT///////////////////////
void ulti(int *ligne,int *colone,int *ult,Personne *p)
{
*ligne=6;
(*p).ult.x+=40;
//ULT DISTANCE
if ((*p).ult.x >=  (*p).positionEcranPerso.x + (*p).image11->w + 300)
{
*ligne=0;
*colone=0;
*ult=0;
}
else 
{
*ult=1;
}
}
//////////death//////////////////////////
void death(int *ligne,int *colone,int *b,Personne *p)
{
*ligne=3;
*colone =0;

if ( *colone == 1)
{
*colone = 1;
(*p).positionEcranPerso.y=805;
}
else if (*colone == 0)
{*colone = 1;
(*p).positionEcranPerso.y=805;}
}

/////////////AFFICHER//////////////////////
void afficherPerso(Personne p, int ligne ,int colone,SDL_Surface *screen)
{
SDL_BlitSurface(p.imagepersoAvant[ligne][colone] ,NULL,screen,&p.positionEcranPerso);
}
/*
void movePerso(Personne *p,Uint32 dt)
{
float dx;
p->positionEcranPerso.x = (int)((p->acceleration) * (dt * dt))/2 + (dt * p->vitesse);
dx=((p->acceleration) * (dt * dt))/2 + (dt * p->vitesse);
printf("%.2f\n",dx);
}
*/

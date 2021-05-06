/**
 *@file lot2/enemy.c
 **/

#include "type.h"
/** 
* @brief To initialize Enemy . 
* @param e the enemy
* @param url the url of the image  
* @return Nothing 
*/
void initEnemy(enemy *e)
{
e->image1 =IMG_Load("lot2/standL.png");
e->image2 =IMG_Load("lot2/walkL.png");
e->image3 =IMG_Load("lot2/attack 1L.png");
e->image4 =IMG_Load("lot2/attack 2L.png");
e->imageEnemyAvant[0][0]=e->image1;
e->imageEnemyAvant[1][0]=e->image2;
e->imageEnemyAvant[2][0]=e->image3;
e->imageEnemyAvant[2][1]=e->image4;
e->positionEcranEnemy.x=1600;
e->positionEcranEnemy.y=640;
e->positionEcranEnemy.h=e->image1->h;
e->positionEcranEnemy.w=e->image1->w;
}
//deplacement
/** 
* @brief Deplacement AI .  
* @return Nothing 
*/
void DeplacementEnemy(enemy *e , Personne p,int *colone2,int *ligne2)
{
if (p.positionEcranPerso.x >= 250)
{
*ligne2=1;
e->positionEcranEnemy.x=e->positionEcranEnemy.x-50;
if (e->positionEcranEnemy.x==0)
{e->positionEcranEnemy.x=1600;}
}
}
/** 
* @brief Enemy Attack .  
* @return Nothing 
*/
//ATTACK
void EnemyAttack(enemy e , Personne p,int *colone2,int *ligne2,int *STOP,int *Hurt)
{
if ( e.positionEcranEnemy.x - p.positionEcranPerso.x <= 100 )
{
*STOP=1;
*ligne2=2;
if (*colone2 == 1)
{
*ligne2=0;
*colone2=0;
*Hurt=1;
}
else if (*colone2 == 0)
{
*colone2 = 1;
}
}
}
/////////HURT//////////////
/** 
* @brief Perso Hurt .  
* @return Nothing 
*/
void hurtperso(int *ligne,int *colone,int *hurt)
{
*ligne=3;
*colone =0;
*hurt =0;
}
//death
/** 
* @brief Enemy Death .  
* @return Nothing 
*/
void EnemyDeath(enemy e , Personne p,int *BlitEnemy,int ligne)
{
if ((p.ult.x+50  >= e.positionEcranEnemy.x && ligne == 6) || ((p.positionEcranPerso.x + p.image10->w >= e.positionEcranEnemy.x) && ligne == 5  ))
{*BlitEnemy = 0;}
}
////////deplacement aleatoire
/** 
* @brief Deplacement Aleatoire .  
* @return Nothing 
*/
void deplacement_enemy_aleatoire(enemy *e)
{

if(e->positionEcranEnemy.x>1590)
{e->direction=1;}//gauche
if(e->positionEcranEnemy.x<1400)
{e->direction=0;}//droite

if(e->direction==1)
{e->positionEcranEnemy.x=e->positionEcranEnemy.x-20;}
if(e->direction==0)
{e->positionEcranEnemy.x=e->positionEcranEnemy.x+20;}

}
void EnemyDeath2(Personne p1,enemy e1,int *BlitEnemy1,int ligne1)
{
if ((p1.positionEcranPerso.x + p1.image7->w >= e1.positionEcranEnemy.x) && ligne1 == 5)
{*BlitEnemy1 =0;}
}


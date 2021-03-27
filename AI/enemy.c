#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
void initPerso(Personne *p)
{
//perso
p->image1 =IMG_Load("perso.png");
p->image2 =IMG_Load("walk.png");

p->imagepersoAvant[0][0]=p->image1;
p->imagepersoAvant[1][0]=p->image2;

//death
p->image4 =IMG_Load("death etape 1.png");
p->image5 =IMG_Load("death etape 2.png");
p->imagepersoAvant[3][0]=p->image4;
p->imagepersoAvant[3][1]=p->image5;


/////////////////////////////////////////////
//POSITION player
p->positionEcranPerso.x=0;
p->positionEcranPerso.y=705;
p->positionEcranPerso.h=p->image2->h;
p->positionEcranPerso.w=p->image2->w;



//vitesse et acc
p->vitesse=5;
p->acceleration=0;
}




//////////////////////////////////////////////////////////////////////ENEMY//////////
void initEnemy(enemy *e)
{
e->image1 =IMG_Load("standL.png");
e->image2 =IMG_Load("walkL.png");
e->image3 =IMG_Load("attack 1L.png");
e->image4 =IMG_Load("attack 2L.png");
e->imageEnemyAvant[0][0]=e->image1;
e->imageEnemyAvant[1][0]=e->image2;
e->imageEnemyAvant[2][0]=e->image3;
e->imageEnemyAvant[2][1]=e->image4;
e->positionEcranEnemy.x=1600;
e->positionEcranEnemy.y=705;
e->positionEcranEnemy.h=e->image1->h;
e->positionEcranEnemy.w=e->image1->w;
}
//////////////////////////////////////////////////////////////////////////


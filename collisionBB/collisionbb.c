#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"

int collisionbb( SDL_Rect pos_objetA , SDL_Rect pos_objetB )
{
 int x ; 
if ( ((pos_objetA.y+pos_objetA.h>=pos_objetB.y)&&(pos_objetA.y<=pos_objetB.y+pos_objetB.h)&&(pos_objetA.x+pos_objetA.w>=pos_objetB.x)&&(pos_objetA.x<=pos_objetB.x+pos_objetB.w)) )
{
	x=1 ; /////////// il y a collision 
}

else x=0 ; ///////////// pase de collision
return x ;
}

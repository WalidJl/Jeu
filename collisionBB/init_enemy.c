#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"

void initialiser_enemy(enemy *e , char name[] , int x , int y ) 
{

	       e->image =  IMG_Load(name); 
	  
     
 /////////////////////////////position  
     e->position.x  =  x ; 
     e->position.y  =  y ; 
     e->position.h  =  e->image->h ;
     e->position.w = e->image->w ;


}



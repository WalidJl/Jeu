
#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
SDL_Surface *image ; 
SDL_Rect position ; 

}enemy ; 

void initialiser_enemy(enemy *e , char name[] , int x , int y ) ; 
void affichage_enemy (enemy e , SDL_Surface *screen) ;
int collisionbb( SDL_Rect posj , SDL_Rect posobj ) ;  



#endif /* FONCTIONS_H_ */

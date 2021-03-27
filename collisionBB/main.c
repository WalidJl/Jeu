#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy.h"


int main()
{
SDL_Surface *screen ;


enemy e,e1;
 
SDL_Event event ; 
int c=0 , x ; 

 
     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     
    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  150 , 150)); 

    initialiser_enemy(&e ,"big mom.png" ,  0 ,  450 ) ; 
    affichage_enemy (e ,screen) ;
    initialiser_enemy( &e1 ,"enemy.png" ,  500 ,  600 ) ; 
    affichage_enemy (e1 ,screen) ;
    
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( c==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 c =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
c=1 ; 

case SDLK_LEFT : 

e.position.x-=10 ; 


SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  150 , 150));
affichage_enemy (e ,screen) ;
affichage_enemy (e1 ,screen) ;

break ; 

case SDLK_RIGHT : 

e.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  150 , 150));
affichage_enemy (e ,screen) ;
affichage_enemy (e1 ,screen) ;

break ; 
case SDLK_UP : 

e.position.y-=10 ;

SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  150 , 150));
affichage_enemy (e ,screen) ;
affichage_enemy (e1 ,screen) ;

break ; 
case SDLK_DOWN : 

e.position.y+=10 ; 

SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  150 , 150));
affichage_enemy (e ,screen) ;
affichage_enemy (e1 ,screen) ;

break ; 


                 
			 }

x=collisionbb(e.position,e1.position);

if(x==1) ///////////cas de collision ->black screen
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));


SDL_Flip(screen) ; 
}
break ; 




		 }
	 }


}

return 0 ; 
}

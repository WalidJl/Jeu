



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main()
{ 

	SDL_Surface *screen;
	enigme  e;
	int r2,r1=10,run =1,running=1,alea,cond1=0,cond2=0;
	int x1,x2 ;
	char image[30]="";
	SDL_Event event;
    srand(time(NULL));
 FILE *f ;  
f=fopen("valeur","a") ;	 
	 SDL_Init ( SDL_INIT_VIDEO ) ;


   SDL_EnableUNICODE( SDL_ENABLE );
	 screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
	srand(time(NULL));
	 while (run)
	 {
	    running=1 ;
	     SDL_PollEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
              
                run = 0;
								 }
								 
			  
            

       	
generate_afficher ( screen  , image ,&e,&alea) ;
solution_e1 (screen,image,&x1,&x2) ;
printf("%d      %d\n",x1,x2);

if(cond2!=1)
{
cond2=1 ;	
do {
r2=resolution1 (&running,&run ) ;
}while(r2<0 || r2>9) ;
}
if(cond1!=1)
{
cond1=1 ;	
do {
r1=resolution1 (&running,&run ) ;
}while(r1<0 || r1>9) ;
} 
printf("%d    %d\n",r1,r2);


 fprintf(f,"1= %.2f \nx2= %. \nr2=%d \n r1=%d\n alea: %d",x1,x2,r2,r1,alea) ;	 
			
			afficher_resultat (screen,r1,r2,&e,x1,x2) ;			
      while(running){

	
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					               case SDL_QUIT :
                              running =0 ;
						                  run=0 ;
					                break ;
                         case SDL_KEYDOWN :
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
																generate_afficher ( screen  , image ,&e,&alea) ; 
																cond1=0 ;
																cond2=0 ;
			                        break ;
			                      }
						              break ;
                       }
                    }
   } 
	 fclose(f) ;
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}

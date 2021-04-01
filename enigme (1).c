


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <math.h>
#include <time.h> 


/**  * @brief  To initialize the enigma . 
 * @param e the enigma   
 * @return Nothing  
*/
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}
/**  * @brief  generer et afficher l enigme e . 
 * @param the screen
 * @param image char
 * @parame the enigas
 * @param alea integer    
 * @return Nothing  
*/
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	
 *alea =  rand()%1 +1;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}
/**  * @brief solution de l enigme . 
 * @param image char    
 * @return int
 */ 
 void solution_e1 (SDL_Surface * screen ,char image [],int *x1,int *x2)
 {   SDL_Surface *img,*img1,*img2;
  char im1[30];
char   im2[30];
SDL_Rect p,p1,p2;   
    float delta ;
          int a,b,c,d,i,j;
 	
 	
 	if(strcmp(image,"1.jpg")==0)
 	{
   do
{
       a=1;
       d=rand()%10;
       b=-d;
       c=rand()%10;
p.x=269;
p.y=258;
p1.x=449;
p1.y=258;
p2.x=656;
p2.y=258;
img=IMG_Load("c1.png");
SDL_BlitSurface(img,NULL,screen,&p);
SDL_Flip(screen);

printf(" %d    %d    %d  %d\n",a,b,c,d);
       delta= pow(b,2) -4*a*c;



      *x1= (int) (-b- sqrt(delta))/(2*a) ;
      *x2= (int)(-b+(sqrt(delta)))/(2*a);
} while ((delta<0)&&((*x1<0)||(*x2<0)));
if(d==1)
{
img1=IMG_Load("c1.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==2)
{
img1=IMG_Load("c2.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==3)
{
img1=IMG_Load("c3.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==4)
{
img1=IMG_Load("c4.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==5)
{
img1=IMG_Load("c5.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==6)
{
img1=IMG_Load("c6.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==7)
{
img1=IMG_Load("c7.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==8)
{
img1=IMG_Load("c8.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==9)
{
img1=IMG_Load("c9.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}
else if(d==0)
{
img1=IMG_Load("c0.png");
SDL_BlitSurface(img1,NULL,screen,&p1);
SDL_Flip(screen);
}



if(c==1)
{
img2=IMG_Load("c1.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==2)
{
img2=IMG_Load("c2.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==3)
{
img2=IMG_Load("c3.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==4)
{
img2=IMG_Load("c4.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==5)
{
img2=IMG_Load("c5.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==6)
{
img2=IMG_Load("c6.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==7)
{
img2=IMG_Load("c7.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==8)
{
img2=IMG_Load("c8.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==9)
{
img2=IMG_Load("c9.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}
else if(c==0)
{
img2=IMG_Load("c0.png");
SDL_BlitSurface(img2,NULL,screen,&p2);
SDL_Flip(screen);
}


  }
 	

 }

/**  * @brief  resolution de lenigme . 
 * @param run eint
 * @param running int  
 * @return int
 */

int resolution1 (int * running,int *run )
{
	SDL_Event event ;
 int r=-1;
               SDL_WaitEvent(&event);
							    if( event.type == SDL_QUIT)
                 {
                * running= 0 ;
                *run = 0;
								 }
							    if( event.type == SDL_KEYDOWN )
                 {

            if( ( event.key.keysym.unicode >= ((Uint16)48) ) && ( event.key.keysym.unicode <= ((Uint16)57)	 ) )
            { 
							r=event.key.keysym.unicode-48  ;
							
						} 
								 }	
return r;

                 
	}


/**  * @brief  affichage de resultat .
 * @param screen surface 
 * @params int
 * @paramr int 
 * @paramen enigme  
 * @return Nothing 
 */


 void afficher_resultat (SDL_Surface * screen,int r2,int r1,enigme *en,int x1,int x2)
 {
  FILE *f ;  
f=fopen("enigme_file","a") ;	 
 	if (((r1==x1)&&(r2==x2))||((r2==x1)&&(r1==x2)))
 	{
 		en->img=IMG_Load("10.png");
 fprintf(f,"/********correct answer*******/  \n x1= %d  x2= %d\n",r1,r2) ;				 
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
fprintf(f,"wrong essai : \n x1= %d  x2= %d\n",r1,r2) ; 
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
	 fclose(f) ;
 }
 

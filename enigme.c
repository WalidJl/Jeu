#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <string.h>

void solution(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image1 = NULL;
    SDL_Rect positionFond1;
    positionFond1.x =  0 ;
    positionFond1.y =  0 ;
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    image1= IMG_Load("wrong.png");
    SDL_BlitSurface(image1,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(500);
    sprintf(im,"solution/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void correct(SDL_Surface *ecran)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"correct.png");
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}

void enigma(SDL_Surface *ecran,int d)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"enigme/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(500);
}


void reponse(SDL_Surface *ecran,int d)
{
    SDL_Event event;
    char im[100], im1[100], im2[100], im3[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"reponse/%d.png",d);
    image= IMG_Load(im);
    sprintf(im1,"reponse/%d/1.png",d);
    sprintf(im2,"reponse/%d/2.png",d);
    sprintf(im3,"reponse/%d/3.png",d);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    int continuer =1;
    int i=0;



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && d%3==1)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else if (i==2 && d%3==2)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else if (i==3 && d%3==0)
                    {
                        correct(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,d);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,ecran,&positionim);
        SDL_Flip(ecran);
    }


}

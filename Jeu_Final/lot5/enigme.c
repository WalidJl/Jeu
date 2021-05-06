/**
 *@file lot5/enigme.c
 * */
#include "type.h"
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
    image1= IMG_Load("lot5/wrong.png");
    SDL_BlitSurface(image1,NULL,ecran,&positionFond1);
    SDL_Flip(ecran);
    SDL_Delay(500);
    sprintf(im,"solution/%d.png",d);
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}
/** 
* @brief Correct Answers .  
* @return Nothing 
*/
void correct(SDL_Surface *ecran)
{
    char im[100];
    SDL_Surface *image = NULL;
    SDL_Rect positionFond;
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    sprintf(im,"lot5/correct.png");
    image= IMG_Load(im);
    SDL_BlitSurface(image,NULL,ecran,&positionFond);
    SDL_Flip(ecran);
    SDL_Delay(5000);
}
/** 
* @brief Blit Enigme .  
* @return Nothing 
*/
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
/** 
* @brief Answers .  
* @return Nothing 
*/
int reponse(SDL_Surface *ecran,int d)
{
    SDL_Event event;
    char im[100], im1[100], im2[100], im3[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"reponse/%d.png",d);
    image= IMG_Load(im);
    sprintf(im1,"lot5/reponse/%d/1.png",d);
    sprintf(im2,"lot5/reponse/%d/2.png",d);
    sprintf(im3,"lot5/reponse/%d/3.png",d);
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
case SDLK_ESCAPE:
return 1;
break;
            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && d%3==1)
                    {
                        correct(ecran);
                        continuer=0;
return 1;
                    }
                    else if (i==2 && d%3==2)
                    {
                        correct(ecran);
                        continuer=0;
return 1;
                    }
                    else if (i==3 && d%3==0)
                    {
                        correct(ecran);
                        continuer=0;
return 1;
                    }
                    else
                    {
                        solution(ecran,d);
                        continuer=0;
return 0;
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
/** 
* @brief To initialize Enigme .  
* @return Nothing 
*/
int Enigme()
{

int d=1;
int succes=0;
srand(time(NULL));
d=rand()%7;
SDL_Surface *backg=NULL ; //declaration des variables globale
SDL_Rect positiond;
SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
SDL_Surface *ecran =NULL;
ecran=SDL_SetVideoMode(800, 600, 32,SDL_ANYFORMAT); // Ouverture de la fenêtre
backg = IMG_Load("lot5/enigme.png");
positiond.x=0 ;
positiond.y=0 ;
SDL_BlitSurface(backg,NULL, ecran, &positiond);
SDL_Flip(ecran);
SDL_Delay(300);
enigma(ecran,d);
SDL_Flip(ecran);
succes=reponse(ecran,d);
SDL_FreeSurface(backg);
//SDL_Quit(); // Arrêt de la SL

    return succes; // Fermeture du programme
}


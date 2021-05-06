/** 
* @struct enemy
* @brief struct for backround 
*/ 
typedef struct
{
SDL_Surface *image1;
SDL_Surface *image2;
SDL_Surface *image3;
SDL_Surface *image4;
SDL_Surface *imageEnemyAvant[3][2];
//enemy position
SDL_Rect positionEcranEnemy;
int direction;
}enemy;

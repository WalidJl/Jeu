/** 
* @struct Personne 
* @brief struct for perso
*/ 
typedef struct
{
SDL_Surface *image1;
SDL_Surface *image2;
SDL_Surface *image3;
SDL_Surface *image4;
SDL_Surface *image5;
SDL_Surface *image6;
SDL_Surface *image7;
SDL_Surface *image8;
SDL_Surface *image9;
SDL_Surface *image10;
SDL_Surface *image11;
SDL_Surface *image12;
SDL_Surface *image13;
SDL_Surface *imagepersoAvant[7][5];
//perso position
SDL_Rect positionEcranPerso;
SDL_Rect positionEcranDeath;
//ult position
SDL_Rect ult;
//score
SDL_Surface *score;
SDL_Rect positionEcranScore;
//vie
SDL_Surface *image000;
SDL_Surface *image111;
SDL_Surface *image222;
SDL_Surface *image333;
SDL_Surface *image444;
SDL_Surface *image555;
SDL_Surface *vie[6];
SDL_Rect positionEcranVie;
//acceleration et vitesse
double vitesse , acceleration;

//end game 
SDL_Surface *end;
SDL_Rect positionEcranEnd;
}Personne;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

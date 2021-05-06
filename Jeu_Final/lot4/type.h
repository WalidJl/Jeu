/** 
* @struct minimap 
* @brief struct for backround 
*/ 
typedef struct 
{
SDL_Surface *imageDeFond;

SDL_Rect positionFond;

SDL_Surface *detective;

SDL_Rect positiondetective;

}minimap;

struct text {
    SDL_Surface* textSurface;/*!< Surface. */ 

    SDL_Rect positionText;/*!< Rectangle*/ 
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;

typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;

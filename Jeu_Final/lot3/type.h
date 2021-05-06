typedef struct
{
//level1
SDL_Surface *image;
//level 2
SDL_Surface *image1;
//chcekpoint
SDL_Surface *checkpoint1;
SDL_Rect cp1;
SDL_Surface *checkpoint2;
SDL_Rect cp2;
//traps
SDL_Surface *traps;
//WIN
SDL_Surface *win;
//Menu
SDL_Surface *menu;

SDL_Surface *save;
SDL_Surface *load;
SDL_Surface *exit;
SDL_Surface *newgame;
//POSITIONS
SDL_Rect positionEcran;
SDL_Rect Camera;
SDL_Rect trapsP;
SDL_Rect winP;
SDL_Rect menuP;
SDL_Rect saveP;
SDL_Rect loadP;
SDL_Rect exitP;
SDL_Rect newgameP;
}background;


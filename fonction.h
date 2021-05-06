#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct
{SDL_Surface *img;
SDL_Rect pos;
}background;
void afficherbackground(background b,SDL_Surface *screen);
void scrolling (background *b,int direction);
void initbackground (background *b);

#endif

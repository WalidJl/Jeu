#include "minimap.c"

void init_map(minimap *m);
void affichage_map (minimap m , SDL_Surface *screen);
void inittemps(Time *t);
void Timer(int *tempsdebut);
int initTexttime(Text* T);
int loadFonttime(Text* T, char * ch);
void update_time(Time* T);
void displaytime(Time T,SDL_Surface *screen);
void freeTexttime(Text T);

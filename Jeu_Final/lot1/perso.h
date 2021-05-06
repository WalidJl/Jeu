#include "perso.c"
void initPerso(Personne *p);
void movePerso(Personne *p,Uint32 dt);
void initPerso2(Personne *p1);
void afficherPerso(Personne p, int ligne ,int colone,SDL_Surface *screen);
void moveRight(int *ligne,Personne *p,SDL_Rect *Camera,minimap *m);
//void moveRight(int *ligne,Personne *p,SDL_Rect *Camera,minimap *m);
void sprint(int *ligne,Personne *p,SDL_Rect *Camera);
void moveLeft(int *ligne,Personne *p,SDL_Rect *Camera,minimap *m);
void stop(int *ligne,Personne *p,SDL_Rect *Camera,int *acc,int *colone,int *done);
void jump(int *ligne,Personne *p,SDL_Rect *Camera,int *acc,Personne *p1);
void slap(int *ligne,int *colone,int *b);
void ulti(int *ligne,int *colone,int *ult,Personne *p);
void death(int *ligne,int *colone,int *b,Personne *p);

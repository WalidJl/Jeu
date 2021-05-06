
#include "enigmealeatoire.c"

enigme generer();
void afficherenigme(enigme e,SDL_Surface *ecran);
void affichage_repvraie(  SDL_Surface *ecran,enigme e);
void affichage_repfausse(  SDL_Surface *ecran,enigme e);
void init_enigme(enigme *e );
void timeaff();
int EnigmeSansFichier();



/**
 *@file lot7/save.c
 * */
#include "type.h"

void save(Personne player,  background map ,char nomFich[],enemy e,int BlitEnemy,minimap m,int i,int level2,Time T)
{
    FILE* f=fopen(nomFich,"w");
 
    fprintf(f, "%d\n", player.positionEcranPerso.x);

    fprintf(f, "%d\n", map.Camera.x);

    fprintf(f, "%d\n", e.positionEcranEnemy.x);

    fprintf(f, "%d\n", BlitEnemy);

    fprintf(f, "%d\n", m.positiondetective.x);
    
    fprintf(f, "%d\n", i);

	fprintf(f, "%d\n", level2);
//time//////////////////////////////////
	fprintf(f, "%d\n", T.mm);
	fprintf(f, "%d\n", T.ss);
///////////////////////////////////////

    fclose(f);
}   

void load(Personne *player,  background *map ,char nomFich[],enemy *e,int *BlitEnemy,minimap *m,int *i,int *level2,Time* T)
{   
    FILE* f=fopen(nomFich,"r");
    
    fscanf(f,"%hd\n", &player->positionEcranPerso.x);

    fscanf(f, "%hd\n", &map->Camera.x);

    fscanf(f, "%hd\n", &e->positionEcranEnemy.x);

    fscanf(f, "%d\n", BlitEnemy);

    fscanf(f, "%hd\n", &m->positiondetective.x);
 
    fscanf(f, "%d\n", i);

	fscanf(f, "%d\n", level2);
//time////////////////////////////
	fscanf(f, "%d\n", &T->mm);
	fscanf(f, "%d\n", &T->ss);
//////////////////////////////////

    fclose(f);
}   

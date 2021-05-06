/**
 *@file lot4/enemy.h
 * */
#include "enemy.c"

void initEnemy(enemy *e);
void DeplacementEnemy(enemy *e , Personne p,int *colone2,int *ligne2);
void EnemyDeath(enemy e , Personne p,int *BlitEnemy,int ligne);
void EnemyAttack(enemy e , Personne p,int *colone2,int *ligne2,int *STOP,int *Hurt);
void hurtperso(int *ligne,int *colone,int *hurt);
void deplacement_enemy_aleatoire(enemy *e);
void EnemyDeath2(Personne p1,enemy e1,int *BlitEnemy1,int ligne1);

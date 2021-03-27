  
prog:main.o affichage_enemy.o init_enemy.o collisionbb.o
	gcc main.o affichage_enemy.o init_enemy.o collisionbb.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g

affichage_enemy.o:affichage_enemy.c
	gcc -c affichage_enemy.c -lSDL -lSDL_image -g
init_enemy.o:init_enemy.c 
	gcc -c init_enemy.c -lSDL -lSDL_image -g  
collisionbb.o:collisionbb.c 
	gcc -c collisionbb.c -lSDL -lSDL_image -g  

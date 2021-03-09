prog:menu.o f.o 
	gcc menu.o f.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
menu.o:menu.c
	gcc -c menu.c
f.o:f.c
	gcc -c f.c

all:
	gcc main.c  pres.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; ./prog

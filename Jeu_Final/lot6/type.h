typedef struct
{char question[200];
    char reponse1[200];
    char reponse2[200];
    char reponse3[200];
     SDL_Surface *img;
    int numrepjuste;

TTF_Font *police,*policequestion;;
    SDL_Surface *textequestion,*texterep1,*texterep2,*texterep3;
SDL_Rect posquestion,posreponse1,posreponse2,posreponse3;                 //ce qui concerne l'affichage de l'enigme//
SDL_Rect posimg,posboard; 
SDL_Surface *imgboard;


SDL_Rect posbravo;  //ce qui concerne l'affichage de la reponse vraie//
  SDL_Surface *textebravo;
  TTF_Font *policebravo;



  SDL_Rect posincorrecte;
TTF_Font *policeincorrecte;        //ce qui concerne l'affichage de la reponse fausse//
SDL_Surface *texteincorrecte;

}enigme;

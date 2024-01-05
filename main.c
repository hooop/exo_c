
#include <stdio.h>
#include <stdlib.h>
#include "map.h"


int main(int argc, const char * argv[]) {

/* -----  Initialisation variables  ----- */

int tableau[ROW][COLUMN]={0};
int choix_menu = 0;
int jx = 0, jy = 0;
int *joueur_x = &jx, *joueur_y = &jy;

/* -----  initialisation barrières map  ----- */

generate_map(ROW, COLUMN, tableau, joueur_x, joueur_y);

/* -----  Boucle tant que l'on ne quitte pas  ----- */

while (choix_menu != 5)

 {

/* -----  Dessin du tableau  ----- */

draw_map(tableau);


/* -----  Menu  ----- */

choix_menu = menu();

/* -----  Déplacement  ----- */

deplacement(choix_menu, tableau, joueur_x, joueur_y);

 }

 printf("Ciao !\n\n");

return 0;
}
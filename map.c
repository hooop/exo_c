#include <stdio.h>
#include <stdlib.h>
#include "map.h"


/* -----  Génération matrice  ----- */

void generate_map(int row, int column, int tableau[][COLUMN], int *joueur_x, int *joueur_y)
{


int i;


	for (i = 0; i < column; i++)
	{
		tableau[0][i] = 1;
	}
	for (i = 0; i < column; i++)
	{
		tableau[row - 1][i] = 1;
	}
	for (i = 0; i < row; i++)
	{
		tableau[i][0] = 1;
	}
	for (i = 0; i < row; i++)
	{
		tableau[i][column - 1] = 1;
	}

*joueur_x = 2;
*joueur_y = 2;

tableau[*joueur_y][*joueur_x] = 2;
}



/* -----  Dessin du tableau  ----- */

void draw_map(int tableau[][COLUMN])

{
	int x, y;
	
	for (y = 0; y < ROW; y++)
	{
		for (x = 0; x < COLUMN; x++)
		{
			if (tableau[y][x] == 0)
			{
				printf(" ");
			}
			else if (tableau[y][x] == 1)
			{
				printf("█");
			}
			else if (tableau[y][x] == 2)
			{
				printf("θ");
			}
		}
	printf("\n");
	}
}


/* ----- Menu ------*/

int menu()
{
	int saisie = 0;

	printf("\n\n1 : haut\n2 : gauche\n3 : droite\n4 : bas\n5 : quitter\n\n");
	scanf("%d", &saisie);

	return saisie;
}

/* ----- Déplacment ------*/

void deplacement(int choix_menu, int tableau[][COLUMN], int *joueur_x, int *joueur_y)
{

	/* -----  Haut  ----- */
	if (choix_menu == 1)
	{
		
		if (tableau[*joueur_y - 1][*joueur_x] == 0)
		{
			tableau[*joueur_y][*joueur_x] = 0;
			*joueur_y -= 1;
			tableau[*joueur_y][*joueur_x] = 2;
			
		}
		else if (tableau[*joueur_y - 1][*joueur_x] == 1)
		{
			printf("Déplacement vers le haut impossible\n\n");
		}
	}

	/* -----  Bas  ----- */

	else if (choix_menu == 4)
	{
		if (tableau[*joueur_y + 1][*joueur_x] == 0)
		{
			tableau[*joueur_y][*joueur_x] = 0;
			*joueur_y += 1;
			tableau[*joueur_y][*joueur_x] = 2;
		}
		else
		{
			printf("Déplacement vers le bas impossible\n\n");
		}
	}

	/* -----  Gauche  ----- */

	else if (choix_menu == 2)
	{
		if (tableau[*joueur_y][*joueur_x - 1] == 0)
		{
			tableau[*joueur_y][*joueur_x] = 0;
			*joueur_x -= 1;
			tableau[*joueur_y][*joueur_x] = 2;			
		}
		else
		{
			printf("Déplacement vers la gauche impossible\n\n");
		}
	}

	/* -----  Droite  ----- */

	else if (choix_menu == 3)
	{
		if (tableau[*joueur_y][*joueur_x + 1] == 0)
		{
			tableau[*joueur_y][*joueur_x] = 0;
			*joueur_x += 1;
			tableau[*joueur_y][*joueur_x] = 2;
		}
		else
		{
			printf("Déplacement vers la droite impossible\n\n");
		}
	}
}

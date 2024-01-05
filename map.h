# ifndef MAP
# define MAP
#define ROW 6
#define COLUMN 8


void generate_map(int row, int column, int tableau[][COLUMN], int *joueur_x, int *joueur_y);
void draw_map(int tableau[][COLUMN]);
int menu();
void deplacement(int choix_menu, int tableau[][COLUMN], int *joueur_x, int *joueur_y);

#endif
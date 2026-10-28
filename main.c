// Labo 04 - Tables de multiplication
//
// Affiche un menu qui permet d'afficher une table de multiplication,
// la version du programme ou une aide. Le menu est répété jusqu'à ce que
// l'utilisateur choisisse de quitter.

#include <stdio.h>

#define MIN_TABLE 1
#define MAX_TABLE 10

void print_version(void)
{
    printf("Version 1.0.0 - Tony Maulaz\n");
}

void print_help(void)
{
    printf("Ce programme affiche les tables de multiplication\n");
    printf("de %d jusqu'au livret choisi (%d au maximum).\n", MIN_TABLE, MAX_TABLE);
}

void print_table(void)
{
    int max = 0;
    int ret = 0;

    do
    {
        printf("Livret le plus élevé (%d-%d) : ", MIN_TABLE, MAX_TABLE);
        ret = scanf("%d", &max);
        while (getchar() != '\n') {}

        if (ret != 1 || max < MIN_TABLE || max > MAX_TABLE)
        {
            printf("Valeur invalide, entrez un nombre entre %d et %d\n", MIN_TABLE, MAX_TABLE);
        }
    } while (ret != 1 || max < MIN_TABLE || max > MAX_TABLE);

    printf("\n  X ");
    for (int col = 1; col <= max; col++)
    {
        printf("| %3d ", col);
    }
    printf("\n");

    for (int row = 1; row <= max; row++)
    {
        // Ligne de séparation au-dessus de chaque ligne de la table
        printf("----");
        for (int col = 1; col <= max; col++)
        {
            printf("+-----");
        }
        printf("\n");

        printf("%3d ", row);
        for (int col = 1; col <= max; col++)
        {
            printf("| %3d ", row * col);
        }
        printf("\n");
    }
}

int main(void)
{
    int choice = 0;

    do
    {
        printf("\nVeuillez choisir une option :\n");
        printf("  1. Table de multiplication\n");
        printf("  2. Version\n");
        printf("  3. Aide\n");
        printf("  0. Quitter\n");
        printf("> ");

        if (scanf("%d", &choice) != 1)
        {
            choice = -1; // saisie invalide : traitée comme une option inconnue
        }
        while (getchar() != '\n') {}

        switch (choice)
        {
            case 1:
                print_table();
                break;
            case 2:
                print_version();
                break;
            case 3:
                print_help();
                break;
            case 0:
                printf("Au revoir\n");
                break;
            default:
                printf("Option invalide\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

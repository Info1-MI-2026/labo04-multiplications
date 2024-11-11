#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void separator(int width, int max)
{
    printf("----");
    for (int i = 0; i < max; i++) {
        printf("+");
        for (int i = 0; i <= width; i++) {
            printf("-");
        }
    }
    printf("\n");
}

void table(void)
{
    int max = 10;
    printf("Livret le plus élevé (1..%d) [%d]", max, max);
    scanf("%d", &max);

    // Compute the width of the largest number
    const int width = log10(max * max) + 2;

    // Header
    printf("\n");
    printf("  X ");
    for (int i = 0; i < max; i++) {
        printf("|%*d ", width, i + 1);
    }
    printf("\n");

    separator(width, max);

    // Table
    for (int i = 1; i <= max; i++) {
        printf(" %2d ", i);
        for (int j = 1; j <= max; j++) {
            printf("|%*d ", width, i * j);
        }
        printf("\n");
        separator(width, max);
    }
}

void version(void)
{
    printf(
        "Version 0.1.0 Copyright(c) "
        "HEIG-VD Y.Chevallier <yves.chevallier@heig-vd.ch>\n");
}

void help(void)
{
    printf("Ce programme affiche les tables de multiplications.\n");
}

int main(void)
{
    while (!feof(stdin)) {
        printf(
            "\n"
            "1. Table de multiplication\n"
            "2. Version\n"
            "3. Aide\n"
            "0. Quitter\n\n"
            "> ");

        char c = getchar();

        char d;
        while ((d = getchar()) != '\n' && d != EOF) {
        }

        switch (c) {
            case '1':
                table();
                break;
            case '2':
                version();
                break;
            case '3':
                help();
                break;
            case '0':
                exit(0);
            default:
                printf("Erreur ! Veuillez saisir une option valide\n");
        }
    }
}

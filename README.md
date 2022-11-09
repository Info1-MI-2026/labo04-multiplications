# Tabelle

- **Durée**: 4 périodes + travail à la maison

## Objectifs

Ce travail pratique à pour but de se familiariser avec les boucles imbriquées, les `printf` et la création d'un menu en ligne de commande.

Cette fois-ci nous n'allons pas utiliser les arguments, mais l'entrée standard `stdin`. L'interface utilisateur sera par conséquent interactive.

Votre programme sera testé par vos soins et un petit **rapport de test** sera présent dans votre rendu.

Voici une simulation complète du programme que vous devez réaliser :

```console
$ make
cc -std=c11 -g -Wall -pedantic tabelle.c -o tabelle -lm
$ ./tabelle

Veuillez choisir une option :

  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter

> 2

Version 0.1.0 Copyright(c) HEIG-VD Y.Chevallier <yves.chevallier@heig-vd.ch>

Veuillez choisir une option :

  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter

> 3

Ce programme affiche les tables de multiplication pour mieux vous aider à les apprendre.

Veuillez choisir une option :

  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter

> 1

Livret le plus élevé ? (1..10) [10]: 5

  X |  1 |  2 |  3 |  4 | 5
----+----+----+----+----+----
  1 |  1 |  2 |  3 |  4 | 5
----+----+----+----+----+----
  2 |  2 |  4 |  6 |  8 | 10
----+----+----+----+----+----
  3 |  3 |  6 |  9 | 12 | 15
----+----+----+----+----+----
  4 |  4 |  8 | 12 | 16 | 20
----+----+----+----+----+----
  5 |  5 | 10 | 15 | 20 | 25

Voulez-vous recommencer [Y/n] ? : n

```

## Cahier des charges

- Le programme **doit** comporter un menu à plusieurs entrées.
- Le programme **doit** pouvoir afficher l'aide et sa version.
- Une des options du menu **doit** permettre d'afficher les tables de multiplication.
- Chaque option du menu **doit** être placée dans une fonction C.
- L'utilisateur **doit** être invité à saisir le livret le plus élevé à afficher.
- L'affichage de la table de multiplication **doit** être identique à l'exemple ci-dessus.
- L'espacement entre les cases de la table **doit** être adapté selon les valeurs affichées.
- Un rapport de test **doit** être achevé.
- Des tests automatiques **peuvent** être écrits.

## Déroulement du travail

Séparez bien votre travail en différents commits. Vous êtes libre dans votre démarche, mais voici quelques étapes possibles :

1. Le menu fonctionne.
2. La version fonctionne.
3. L'aide fonctionne.
4. La saisie du livret le plus élevé fonctionne.
5. Le calcul du nombre de chiffres fonctionne.
6. L'affichage de la table de multiplication fonctionne.
7. L'utilisateur est invité à recommencer.
8. Correction de bogues.
9. Le rapport de tests est ajouté à Git et l'ensemble fonctionne.
10. Dernières corrections avant rendu.

N'oubliez pas à la fin de votre travail de vérifier sur GitHub que tous les fichiers sont présents. Ajoutez au besoin vos fichiers à Git avec `git add`.

## Détails

### Qualité du code

De plus en plus, la qualité du code est évaluée. Pour mémoire :

- un **en-tête** en début de programme décrit le fonctionnement du programme ;
- les variables sont nommées de façon **appropriée** ;
- la **visibilité** (*scope*) des variables est minimum ;
- les **constantes littérales** sont nommées pour une meilleure compréhension ;
- les **types** de données doivent être appropriés au contenu ciblé (`signed`, `unsigned`) ;
- le programme doit être **robuste**, les cas d'exception doivent être traités.

### Rapport de test

Votre rapport de test sera écrit en [Markdown](https://fr.wikipedia.org/wiki/Markdown). Créez un fichier `report.md` et ajoutez-le à votre référentiel Git avec `git add report.md`. Ce rapport doit être minimum, ne notez que vos observations et le strict essentiel. Il doit démontrer que votre programme est fonctionnel et que vous l'avez correctement testé.

### Compilation du code

Pour compiler ce code, vous utiliserez cette commande :

```console
gcc -std=c11 -Wall -otabelle tabelle.c
```

Mieux (**oui c'est mieux**), vous pouvez directement utiliser le `Makefile` associé :

```console
make
```

### Menu

L'un des objectifs de ce travail est de réaliser un menu interactif. Lorsque le programme sera exécuté, il affichera par exemple ceci sur `stdout` :

```console
Veuillez choisir une option :

  1. Option 1
  2. Option 2
  0. Quitter

>

```

Le caractère `>` est nommé *prompt*. C'est un invité de commande, c'est-à-dire un caractère qui vous invite à entrer une commande. À ce moment, le programme stoppe son exécution et attend que l'utilisateur saisisse quelque chose au clavier (en réalité, qu'une information soit écrite dans `stdin`).

L'implémentation du menu fait intervenir :

- une boucle ;
- l'instruction `switch` ;
- l'instruction `scanf` ou `getchar` ;
- l'appel de fonctions spécialisées (affichage de la version, affichage de l'aide...)

Voici un exemple de menu simple :

```c
while (!feof(stdin)) {
    // Affichage des options
      printf(
            "1. Option 1\n"
            "2. Option 2\n"
            "0. Quit\n\n"
            "> "
      );

    // Lecture d'un caractère au clavier
    char c = getchar();

    // Consomme le restant des caractères tapés encore dans `stdin`
    char d;
    while ( (d = getchar()) != '\n' && d != EOF ) { }

    // Traitement du choix
    switch(c) {
        case 1:
              break;
        case 2:
              break;
        default:
              break;
    }
}
```

La fonction `feof(stdin)` retourne `false` si la fin du buffer `stdin` est atteinte. Cette fin peut être simulée avec `<C-D>`. La fonction `getchar()` lit un seul caractère au clavier.

### Fonctions

Chaque mode de fonctionnement du programme sera une fonction séparée et indépendante. Le prototype de ces fonctions sera le suivant :

```c
void table(void) {
    // ...
}

void help(void) {
    // ...
}

void version(void) {
    // ...
}
```

### Saisie par l'utilisateur d'une valeur

La saisie sur `stdin` d'une valeur demandée à l'utilisateur pourrait être typiquement réalisée de la manière suivante :

```c
#include <stdio.h>

#define NO ('n')
#define YES ('o')

int main(void) {
    printf("Voulez-vous vous moucher ? [o/N]: ");

    char c = '\0';
    (void)scanf("%c", &c);
    switch(tolower(c)) {
        case YES:
            printf("PRUUUUUuuuST!\n");
            break;
        case NO:
        default:
            printf("(rien)\n");
            break;
    }
    return 0;
}
```

Dans un invité utilisateur, il est courant de faire figurer les options possibles entre crochets (`[]`) et de mettre en majuscule la valeur par défaut *p. ex* : `[Yn]` pour `Yes` et `No`. Constatez ci-dessus que `N` est la valeur par défaut et que le mot clé `default` est associé au cas `NO`.

### Tests et rapport de test

Il vous est demandé d'écrire un petit rapport de test dans un fichier nommé `report.md`.

Faites-y figurer quelques résultats de bon fonctionnement de votre programme. Inspirez-vous de la structure de ce fichier [README.md](README.md) pour afficher des exemples de code.

Pour tester de façon plus automatique votre programme, vous pouvez directement envoyer les valeurs à saisir sur `stdin`. Voici par exemple des commandes qu'un ingénieur de test pourrait utiliser pour tester votre programme :

```console
$ echo 2 | ./tabelle | grep -P '[Vv]ersion'
$ echo 3 | ./tabelle | grep -P 'tabelle'
$ echo 6 5 | ./tabelle | grep -P '\|  9 \|'
```

Alternativement, vous pouvez utiliser Baygon comme dans le dernier labo pour tester votre programme. Vous trouverez la documentation [ici](https://heig-tin-info.github.io/baygon/). En résumé, vous devez créer un fichier `tests.yaml` et le remplir avec vos différents tests. Pour exécuter vos tests, exécutez simplement `baygon ./tabelle`.

Notez que vous êtes totalement libre de faire vos tests comme vous le souhaitez.

# Tabelle

- **Durée**: 3 périodes + travail à la maison
- **Date de rendu**: Lundi avant minuit

## Objectifs

Ce travail pratique à pour but de se familiariser avec les boucles imbriquées, les `printf` et la création d'un menu en ligne de commande.

Cette fois-ci nous n'allons pas utiliser les arguments mais l'entrée standard `stdin`.

## Qualité du code

De plus en plus, la qualité du code est évaluée. Pour mémoire:

- Un **commentaire** en début de programme explique le but du programme à celui qui découvre le code.
- Vos variables sont nommées de façon **appropriées**.
- La **visibilité** (*scope*) de vos variable est minimum.
- Les **constantes littérales** sont nommées pour une meilleure compréhension.
- Les **types** de donnée doivent être appropriés.
- Le programme doit être **robuste**, les cas d'exception doivent être traités

## Procédure de développement

1. Commencez par vous familiariser avec les **menus**
2. Testez **séparément** chacunes de vos **fonctions** en laissant le menu de côté (tests unitaires)
3. Intégrer chaques briques de votre programme
4. Faites des tests fonctionnels
5. Rédigez votre rapport de test
6. Vérifier que votre travail respecte les critères d'évaluation présents dans `criteria.yml`

## Compilation du code

Pour compiler ce code vous utiliserez cette commande:

```console
gcc -std=c99 -Wall -otabelle tabelle.c
```

Mieux (**oui c'est mieux**), vous pouvez directement utiliser le `Makefile` associé:

```console
make
```

## Menu

Durant ce travail pratique nous allons étudier les menus interactifs. Lorsque le programme sera exécuté, il affichera ceci sur `stdout`:

```console
./tabelle

Veuillez choisir une option:

1. Table de multiplication
2. Version
3. Aide
0. Quitter

>

```

Le caractère `>` est nommé *prompt*. C'est un invité de commande, c'est à dire un caractère qui vous invite à entrer une commande. A ce moment, le programme stoppe son exécution et attends que l'utilisateur saisisse quelque chose au clavier (en réalité qu'une information soit écrite dans `stdin`).

L'implémentation du menu fait intervenir:

- Une boucle
- L'instruction `switch`
- L'instruction `scanf` ou `getchar`
- L'appel de fonctions

Voici un exemple de menu simple:

```c
while (!feof(stdin)) {
	printf(
		"1. Option\n"
		"2. Option\n"
		"0. Quit\n\n"
		"> "
	);

	switch(getchar()) {
		case 1:
			break;
		case 2:
			break;
		default:
			break;
	}
}
```

## Fonctions

Chaque mode de fonctionnement du programme sera une fonction séparée et indépendante le prototype de ces fonctions est le suivant:

```c
void table(void);
void help(void);
void version(void);
```

## Saisie

La saisie sur stdin d'une value demandée à l'utilsiateur est typiquement faite de la manière suivante:

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
            printf("PRUUUUUUUUST!\n");
            break;
        case NO:
        default:
            printf("(rien)\n");
            break;
    }
	return 0;
}
```

Il est courant de faire figurer les options possibles entre crochets (`[]`) et mettre en majuscule la valeur par défaut p.ex: `[Yn]` pour `Yes` et `No`.

## Table de multiplication

Lorsque l'utilisateur choisi cette option l'invité de commande serait le suivant:

```console

Largeur des colonnes [3]: 4
Livret le plus élevé (1..10) [10]: 5

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

Voulez-vous recommencer [Y/n] ? :

```

## Test de votre programme

Il vous est demandé d'écrire un petit rapport de test dans le fichier `report.md`.

Faites-y figurer quelques résultats de bon fonctionnement de votre programme. Inspirez-vous de la structure de ce fichier `README.md` pour afficher des exemples de code.

Pour tester de façon plus automatique votre programme, vous pouvez directement envoyer les valeurs à saisir sur `stdin`. Voici par exemple des commandes qu'un ingénieur de test pourrait utiliser pour tester votre programme:

```console
$ echo 2 | ./tabelle | grep -P '[Vv]ersion'
$ echo 3 | ./tabelle | grep -P 'tabelle'
$ echo 6 5 3 | ./tabelle | grep -P '\|    9 \|'
```

Le programme `echo` converti tous les arguments passés au programme sur `stdout`:

```console
$ echo Bonjour         les       amis
Bonjour les amis
```

Le caractère de tuyauterie *pipe* `|` redirige le `stdout` d'un programme vers le `stdin` d'un autre programme.

Votre programme `tabelle` fait appel à des fonctions tels que `getchar` ou `scanf` qui lisent `stdin`.

Enfin le programme `grep`, le plus magique de tous et le plus compliqué à comprendre cherche dans `stdin` un motif saisi sous forme d'expressions régulières. L'option `-P` utilisée permet d'utiliser une certaine senteur (*flavor*) d'expressions régulières, ici **PCRE**.

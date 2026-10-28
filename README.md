# Labo 04 – Les tables de multiplication

## Objectifs pédagogiques
- Réaliser un menu avec une boucle et l'instruction `switch`.
- Utiliser des boucles imbriquées (une boucle dans une boucle).
- Aligner un affichage en colonnes avec `printf`.
- Contrôler une saisie avec `scanf` et la redemander si elle est invalide.
- Appeler des fonctions.

## Cahier des charges
- Le programme affiche un menu avec 4 options : `1` table de multiplication, `2` version, `3` aide et `0` quitter.
- Le choix de l'utilisateur est traité avec un `switch`.
- Après chaque option, le menu est affiché à nouveau, jusqu'à ce que l'utilisateur choisisse `0`.
- Si l'option n'existe pas (ex. `7` ou `abc`), le programme affiche un message d'erreur, puis le menu.
- Chaque option est réalisée dans sa fonction. Les fonctions `print_table`, `print_version` et `print_help` sont déjà dans `main.c` : il faut écrire leur contenu et les appeler depuis le `switch`.
- **Table** : le programme demande le livret le plus élevé, entre `1` et `10`. Si la valeur est invalide, il la redemande.
- La table doit être **identique** à l'exemple ci-dessous : chaque nombre est aligné à droite sur `3` caractères.
- **Version** : affiche le numéro de version et votre nom.
- **Aide** : explique en quelques lignes ce que fait le programme.
- Utiliser des constantes (ex. pour les livrets `1` et `10`).
- Il ne doit pas y avoir de doublon dans le code.
- Attention à l'indentation du code et au formatage.

## Affichage du programme
Vous êtes libres des textes du menu et des messages, mais la table doit être identique.

```console
$ ./tabelle

Veuillez choisir une option :
  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter
> 7
Option invalide

Veuillez choisir une option :
  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter
> 1
Livret le plus élevé (1-10) : 12
Valeur invalide, entrez un nombre entre 1 et 10
Livret le plus élevé (1-10) : 5

  X |   1 |   2 |   3 |   4 |   5
----+-----+-----+-----+-----+-----
  1 |   1 |   2 |   3 |   4 |   5
----+-----+-----+-----+-----+-----
  2 |   2 |   4 |   6 |   8 |  10
----+-----+-----+-----+-----+-----
  3 |   3 |   6 |   9 |  12 |  15
----+-----+-----+-----+-----+-----
  4 |   4 |   8 |  12 |  16 |  20
----+-----+-----+-----+-----+-----
  5 |   5 |  10 |  15 |  20 |  25

Veuillez choisir une option :
  1. Table de multiplication
  2. Version
  3. Aide
  0. Quitter
> 0
Au revoir
```

## Aides

### Appeler une fonction
Une fonction est un bloc de code qui porte un nom. Pour exécuter ce code, on écrit son nom suivi de `()` :

```c
print_help(); // exécute le code de la fonction print_help
```

### Le menu
- Le menu doit être affiché au moins une fois : la boucle `do … while` est adaptée.
- Pour lire le choix et le livret, reprenez l'exemple [redemander une saisie](https://github.com/Info1-MI-2026/example/blob/main/semaines/s05-scanf-multiple-ternaire.md#application--redemander-une-saisie) du cours : `scanf`, test de la valeur retournée et vidage du buffer.
- Théorie : [l'instruction `switch`](https://heig-tin-info.github.io/handout/content/control-structures.html#switch).

### La table
- Une boucle parcourt les lignes et, dans cette boucle, une autre boucle parcourt les colonnes.
- Commencer par afficher les nombres sans alignement, puis ajouter les `|` et les lignes `----+-----`.
- `printf("%3d", 7)` affiche `  7` : le nombre est aligné à droite sur `3` caractères.

### Compiler et déboguer
```console
$ make
$ ./tabelle
```

`F5` compile avec `make` et lance le programme en debug. Pendant un `scanf`, le programme attend la saisie dans le **terminal** en bas.

## Entrée non contrôlée
- Une entrée comme `2abc` n'est pas contrôlée et sera traitée comme `2`.
- La fin de la saisie (`Ctrl+D`) n'a pas besoin d'être gérée.

## Bonus
Adapter la largeur des colonnes au plus grand nombre de la table. Par exemple, pour le livret `5`, le plus grand nombre est `25` : les nombres sont affichés sur `2` caractères.

```console
  X |  1 |  2 |  3 |  4 |  5
----+----+----+----+----+----
  1 |  1 |  2 |  3 |  4 |  5
```

Indice : `printf("%*d", width, value)` affiche `value` sur `width` caractères.

## Étapes conseillées
Faire un commit à chaque étape :
1. Le menu s'affiche et `0` quitte le programme.
2. Les options version et aide fonctionnent.
3. La saisie du livret est contrôlée.
4. La table s'affiche, sans alignement.
5. La table est identique à l'exemple.

## Travaux à rendre
Commit sur GitHub en respectant le délai donné sur Cyberlearn.

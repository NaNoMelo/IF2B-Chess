#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include <windows.h>

/**
 * Fonction demandant au joueur quuel options du menu il souhaite selectionner
 * @return 1 si il souhaite commencer une nouvelle partie, 2 si il souhaite reprendre la dernière partie sauvegarder, 3 si il souhaite quitter le programme
 */
int askMenu() {
    int m;
    do {
        printf("1 | Demmarer une partie\n2 | Reprendre une partie\n3 | Quitter\n");
        scanf("%d", &m);
    } while (m > 3 || m < 1);
    return m;
}

/**
 * Fonction demandant au joueur la taille de plateau qu'il souhaite entre 6 et 12
 * @return t qui correspond à la taille du plateau
 */
int askTaillePlateau() {
    int t;
    do {
        printf("Choisisez la taille de votre plateau, entre 6 et 12:\n");
        scanf("%d", &t);
    } while (t > 12 || t < 6);
    return t;
}

/**
 * Fonction qui demande au joueur le mouvement qu'il souhaite éffectuer et qui le stock dans une matrice
 * @param taillePlateau
 * @param joueur
 * @param move
 * @return 0 si le joueur à rentrer un déplacement sous la bonne forme, break sinon avec message d'erreur
 */
int askDeplacement(int taillePlateau, int joueur, int **move) {
    char strColor[2][10] = {"Blanc", "Noir"};
    int state, action;
    char unparsedMove[10];
    int number;
    do {
        action = 0;
        state = 0;
        move[0][0] = -1;
        move[0][1] = -1;
        move[1][0] = -1;
        move[1][1] = -1;
        printf("Deplacement du joueur %s (exemple : a1b2):\n", strColor[joueur - 1]);
        fflush(stdin);
        scanf("%s", &unparsedMove);
        strupr(unparsedMove);
        if (strcmp(unparsedMove, "S") == 0) action = 1;
        if (strcmp(unparsedMove, "X") == 0) action = 2;
        if (strcmp(unparsedMove, "L") == 0) action = 3;
        if (!action) {
            for (int i = 0; i < strlen(unparsedMove); ++i) {
                while (unparsedMove[i] == ' ') i++;
                if (state % 2) {
                    number = strtol(&unparsedMove[i], NULL, 10);
                    if (number <= 12 && number >= 1) {
                        move[1][(state - 1) / 2] = number - 1;
                        if (isdigit(unparsedMove[i + 1]))i++;
                    } else {
                        printf("Mouvement invalide\n");
                    }
                } else {
                    if (unparsedMove[i] >= 65 && unparsedMove[i] < 65 + taillePlateau) {
                        move[0][state / 2] = unparsedMove[i] - 65;
                    } else {
                        printf("Mouvement invalide\n");
                    }
                }
                state++;
            }
        }
    } while ((!(move[0][0] + 1 && move[0][1] + 1 && move[1][0] + 1 && move[1][1] + 1)) && !action);
    return action;
}

/**
 * Fonction permet de poser une question à l’utilisateur à laquelle il peut répondre par oui ou par non.
 * @param question chaîne de caractères contenant une question binaire
 * @return true si "oui" false si "non"
 */
bool askOuiNon(char *question) {
    char reponse[10];
    char help[100];
    bool rep;
    printf("%s\n", question);
    fflush(stdin);
    scanf("%s", &reponse);
    strupr(reponse);
    strcpy(help, question);
    strcat(help, " (Oui/Non)");
    while (!(strcmp(reponse, "OUI") == 0 || strcmp(reponse, "NON") == 0)) {
        printf("%s\n", help);
        fflush(stdin);
        scanf("%s", reponse);
        strupr(reponse);
    }
    if (strcmp(reponse, "OUI") == 0) rep = true;
    if (strcmp(reponse, "NON") == 0) rep = false;
    return rep;
}

/**
 * Fonction servant à obtenir le signe d'un nombre
 * @param nombre nombre à analyser
 * @return 1 si le nombre est positif, -1 si il est négatif, 0 sinon
 */
int sign(int nombre) {
    return ((nombre > 0) - (nombre < 0));
}

/**
 * Fonction affichant sur la console les erreurs dans le mouvement que propose le joueur (si il y en as)
 * @param validite valeur reçue des fonctions de ferification des mouvements
 * */
void printErr(int validite) {
    switch (validite) {
        default:
            printf("Code erreur non supporte\n");
            break;
        case 0:
            break;
        case 1:
            printf("Mouvement case vide\n");
            break;
        case 2:
            printf("Mouvement piece autre joueur\n");
            break;
        case 3:
            printf("Pas de deplacement\n");
            break;
        case 4:
            printf("Mouvement illegal\n");
            break;
        case 5:
            printf("Piece sur le chemin\n");
            break;
        case 6:
            printf("Mange propre piece\n");
            break;
        case 7:
            printf("Echec\n");
    }
}

/**
 * Fonction affichant les couleurs sur le texte et le fond
 * @param texte Couleur choisie pour le texte
 * @param fond Couleur choisie pour le fond
 */
void setColor(Couleur texte, Couleur fond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, fond * 16 + texte);
}

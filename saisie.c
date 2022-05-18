//
// Created by natha on 10/05/2022.
//

#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ctype.h"
#include "verif.h"
#include "board.h"

int askMenu() {
    int m;
    do {
        printf("1 | Demmarer une partie\n2 | Reprendre une partie\n3 | Quitter\n");
        scanf("%d", &m);
    } while (m > 3 || m < 1);
    return m;
}

int askTaillePlateau() {
    int t;
    do {
        printf("Choisisez la taille de votre plateau, entre 6 et 12:\n");
        scanf("%d", &t);
    } while (t > 12 || t < 6);
    return t;
}

int askDeplacement(int taillePlateau, int joueur, int **move) {
    int state;
    char unparsedMove[10];
    int number;
    do {
        state = 0;
        move[0][0] = -1;
        move[0][1] = -1;
        move[1][0] = -1;
        move[1][1] = -1;
        printf("Deplacement du joueur %d:\n", joueur + 1);
        fflush(stdin);
        scanf("%s", &unparsedMove);
        strupr(unparsedMove);
        if (strcmp(unparsedMove, "S\0") == 0) return 1;
        for (int i = 0; i < strlen(unparsedMove); ++i) {
            while (unparsedMove[i] == ' ') { i++; }
            if (state % 2) {
                number = strtol(&unparsedMove[i], NULL, 10);
                if (number <= 12 && number >= 1) {
                    move[1][(state - 1) / 2] = number - 1;
                    if (isdigit(unparsedMove[i + 1]))i++;
                } else {
                    printf("Mouvement invalide\n");
                    break;
                }
            } else {
                if (unparsedMove[i] >= 65 && unparsedMove[i] < 65 + taillePlateau) {
                    move[0][state / 2] = unparsedMove[i] - 65;
                } else {
                    printf("Mouvement invalide\n");
                    break;
                }
            }
            state++;
        }
        printf("%d %d\n%d %d\n", move[0][0], move[0][1], move[1][0], move[1][1]);
    } while (!(move[0][0] + 1 && move[0][1] + 1 && move[1][0] + 1 && move[1][1] + 1));
    return 0;
}

int sign(int nombre) {
    return ((nombre > 0) - (nombre < 0));
}

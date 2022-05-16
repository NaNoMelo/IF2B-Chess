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

void askDeplacement(int taillePlateau, int joueur, int **move) {
    int state;
    char unparsedMove[10];
    do {
        state = 0;
        printf("Deplacement du joueur %d:\n", joueur + 1);
        fflush(stdin);
        scanf("%s", &unparsedMove);
        strupr(unparsedMove);
        for (int i = 0; i < strlen(unparsedMove); ++i) {
            if (state % 2) {
                if (isdigit(unparsedMove[i]) && unparsedMove[i] - '0' > 0 && unparsedMove[i] - '0' <= taillePlateau) {
                    move[1][(state - 1) / 2] = unparsedMove[i] - '0';
                    if (isdigit(unparsedMove[i + 1]) && unparsedMove[i + 1] - '0' > 0 &&
                        unparsedMove[i + 1] - '0' <= taillePlateau) {
                        i++;
                        move[1][(state - 1) / 2] *= 10;
                        move[1][(state - 1) / 2] += unparsedMove[i];
                    }
                }
            } else {
                if (unparsedMove[i] >= 65 && unparsedMove[i] < 65 + taillePlateau) {
                    move[0][state / 2] = unparsedMove[i] - 64;
                }
            }
            state++;
        }
        printf("%d %d\n%d %d", move[0][0], move[0][1], move[1][0], move[1][1]);
    } while (!(move[0][0] && move[0][1] && move[1][0] && move[1][1]));
}

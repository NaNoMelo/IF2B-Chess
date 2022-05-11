#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "saisie.h"
#include "board.h"

int main() {
    Piece **board;

    switch (askMenu()) {
        case 1: {
            int taillePlateau = askTaillePlateau();
            board = (Piece **) malloc(sizeof(Piece) * taillePlateau);
            for (int i = 0; i < taillePlateau; i++) {
                board[i] = malloc(sizeof(Piece) * taillePlateau);
            }
            genererPlateau(taillePlateau, board);
            afficherPlateau(taillePlateau, board);
            break;
        }
        case 2:
            printf("load");
            break;

        case 3:
            printf("quit");

            break;
    }

    free(board);

    return 0;
}
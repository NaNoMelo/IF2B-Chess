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
    int taillePlateau, move[2][2], tour, joueur;
    bool partie = true;
    switch (askMenu()) {
        case 1: {
            taillePlateau = askTaillePlateau();
            board = (Piece **) malloc(sizeof(Piece) * taillePlateau);
            for (int i = 0; i < taillePlateau; i++) {
                board[i] = malloc(sizeof(Piece) * taillePlateau);
            }
            genererPlateau(taillePlateau, board);
            tour = 0;
            break;
        }
        case 2:
            printf("load");
            break;

        case 3:
            printf("quit");
            return 0;
    }
    while (partie == true) {
        joueur = tour % 2;
        printf("Déplacement du joueur %d", joueur + 1);


        tour++;
        partie = false;
    }

    afficherPlateau(taillePlateau, board);


    free(board);
    return 0;
}
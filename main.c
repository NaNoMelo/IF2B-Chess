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
    int taillePlateau, **move, tour, joueur;
    move = (int **) malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        move[i] = (int *) malloc(sizeof(int) * 2);
    }
    bool partie = true;
    switch (askMenu()) {
        case 1: {
            taillePlateau = askTaillePlateau();
            board = (Piece **) malloc(sizeof(Piece *) * taillePlateau);
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
        afficherPlateau(taillePlateau, board);
        askDeplacement(taillePlateau, joueur, move);


        tour++;
        partie = false;
    }


    free(board);
    return 0;
}
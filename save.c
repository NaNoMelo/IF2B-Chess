//
// Created by natha on 16/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "saisie.h"
#include "board.h"
#include "verif.h"
#include "save.h"

void saveGame(Piece **board, int taillePlateau, int tour) {
    FILE *save = fopen("./save.txt", "w");
    printf("save\n");
    rewind(save);
    fprintf(save, "%d\n%d\n", taillePlateau, tour);
    for (int y = 0; y < taillePlateau; ++y) {
        for (int x = 0; x < taillePlateau; ++x) {
            fprintf(save, "%d\n%d\n%d\n", (int) board[x][y].typePiece, (int) board[x][y].couleurPiece,
                    board[x][y].nbMove);
        }
    }
    fclose(save);
}

void loadGame(Piece **board, int taillePlateau, int *tour) {
    FILE *save = fopen("./save.txt", "r");
    fscanf(save, "%d", &taillePlateau);
    fscanf(save, "%d", tour);
    printf("Tour : %d\n", *tour);
    for (int y = 0; y < taillePlateau; ++y) {
        for (int x = 0; x < taillePlateau; ++x) {
            fscanf(save, "%d", &board[x][y].typePiece);
            fscanf(save, "%d", &board[x][y].couleurPiece);
            fscanf(save, "%d", &board[x][y].nbMove);
        }
    }
    fclose(save);
}
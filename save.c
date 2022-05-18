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

void saveGame(FILE *save, Piece **board, int taillePlateau, int tour) {
    fprintf(save, "%d\n%d\n", taillePlateau, tour);
    for (int y = 0; y < taillePlateau; ++y) {
        for (int x = 0; x < taillePlateau; ++x) {
            fprintf(save, "%d\n%d\n%d\n", (int) board[x][y].typePiece, (int) board[x][y].couleurPiece,
                    board[x][y].nbMove);
        }
    }
}
//
// Created by natha on 16/05/2022.
//

#ifndef IF2B_CHESS_SAVE_H
#define IF2B_CHESS_SAVE_H

#include "board.h"

void loadGame(FILE *save, Piece **board, int taillePlateau, int *tour);

void saveGame(FILE *save, Piece **board, int taillePlateau, int tour);

#endif //IF2B_CHESS_SAVE_H

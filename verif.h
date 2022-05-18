//
// Created by yannt on 16/05/2022.
//

#ifndef IF2B_CHESS_VERIF_H
#define IF2B_CHESS_VERIF_H
#include "board.h"
int verifPion(Piece **board, int **move);

int verifFou(Piece **board, int **move);

int verifCavalier(Piece **board, int **move);

int verifTour(Piece **board, int **move);

int verifDame(Piece **board, int **move);

int verifRoi(Piece **board, int **move);

int verifEchec(Piece **board, int **move, int taillPlateau);

#endif //IF2B_CHESS_VERIF_H

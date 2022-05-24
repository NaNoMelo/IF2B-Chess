//
// Created by yannt on 16/05/2022.
//

#ifndef IF2B_CHESS_VERIF_H
#define IF2B_CHESS_VERIF_H

#include "board.h"

int verifDeplacement(Piece **board, int **move, int joueur, int taillePlateau, int *echec);

int verifMouvement(Piece **board, int **move, int *piece, int joueur);

int verifPion(Piece **board, int **move, int joueur);

int verifFou(Piece **board, int **move);

int verifCavalier(int **move);

int verifTour(Piece **board, int **move);

int verifDame(Piece **board, int **move);

int verifRoi(int **move);

int verifEchec(Piece **board, int taillePlateau);

#endif //IF2B_CHESS_VERIF_H

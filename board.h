//
// Created by natha on 10/05/2022.
//

#ifndef IF2B_CHESS_BOARD_H
#define IF2B_CHESS_BOARD_H
typedef enum {
    VIDE, PION, FOU, CAVALIER, TOUR, DAME, ROI
    //0   1     2    3         4     5     6
} TypePiece;

typedef enum {
    NONE, BLANC, NOIR
    //0   1      2
} CouleurPiece;

typedef struct {
    TypePiece typePiece;
    CouleurPiece couleurPiece;
    int nbMove;
} Piece;

void genererPlateau(int taille, Piece **board);

void afficherPlateau(int taille, Piece **board);

void executeMove(Piece **board, int **move);

int verifDeplacement(Piece **board, int **move, int joueur);

#endif //IF2B_CHESS_BOARD_H

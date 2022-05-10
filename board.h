//
// Created by natha on 10/05/2022.
//

#ifndef IF2B_CHESS_BOARD_H
#define IF2B_CHESS_BOARD_H
typedef enum {
    VIDE, PION, FOU, CAVALIER, TOUR, REINE, ROI
    //0   1    2         3     4      5
} TypePiece;

typedef enum {
    NOIR, BLANC
    //0   1
} CouleurPiece;

typedef struct {
    TypePiece typePiece;
    CouleurPiece couleurPiece;
    int nbMove;
} Piece;

void genererPlateau(int taille, Piece **);

#endif //IF2B_CHESS_BOARD_H

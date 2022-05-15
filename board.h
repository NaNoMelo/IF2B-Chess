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
    NONE, NOIR, BLANC
    //0   1
} CouleurPiece;

typedef struct {
    TypePiece typePiece;
    CouleurPiece couleurPiece;
    int nbMove;
} Piece;

void genererPlateau(int taille, Piece **board);

void afficherPlateau(int taille, Piece **board);


void verifDeplacement(Piece **board, int **move);

int verifPion(Piece **board, int **move);

int verifFou(Piece **board, int **move);

int verifCavalier(Piece **board, int **move);

int verifTour(Piece **board, int **move);

int verifReine(Piece **board, int **move);

int verifRoi(Piece **board, int **move);

#endif //IF2B_CHESS_BOARD_H

#include "board.h"
#include <stdlib.h>
#include "stdio.h"
#include <time.h>
#include "saisie.h"

/**
 * Fonction générant les pièces répartis alléatoirement sur le plateau
 * @param taille
 * @param board
 */
void genererPlateau(int taille, Piece **board) {
    srand(time(NULL));
    board[rand() % taille][0] = (Piece) {ROI, NOIR, 0};
    board[rand() % taille][taille - 1] = (Piece) {ROI, BLANC, 0};

    for (int x = 0; x < taille; x++) {
        for (int y = 0; y < taille; ++y) {
            if (board[x][y].typePiece != ROI) {
                if (y < 2) {
                    board[x][y] = (Piece) {(rand() % 5) + 1, NOIR, 0};
                } else if (y >= taille - 2) {
                    board[x][y] = (Piece) {(rand() % 5) + 1, BLANC, 0};
                } else {
                    board[x][y] = (Piece) {VIDE, NONE, 0};
                }
            }
        }
    }
}

/**
 * Fonction affichant le plateau sur la console
 * @param taille
 * @param board
 */
void afficherPlateau(int taille, Piece **board) {
    char lettres[] = {" abcdefghijkl"};
    char pieces[] = {" PFCTDR"};
    char couleurs[] = {" BN"};
    for (int y = 0; y <= taille; y++) {
        for (int x = 0; x <= taille; ++x) {
            if (y == 0) {
                printf(" %c ", lettres[x]);
            } else {
                if (x == 0) {
                    printf(" %d", y);
                    if (y < 10) printf(" ");
                } else {
                    setColor((x + y) % 2 * (WHITE - BLEU_FONCE) + BLEU_FONCE,
                             (x + y + 1) % 2 * (WHITE - BLEU_FONCE) + BLEU_FONCE);
                    printf(" %c%c", pieces[board[x - 1][y - 1].typePiece],
                           couleurs[board[x - 1][y - 1].couleurPiece]);
                }
            }

            if (x == taille) printf("\n");
            setColor(WHITE, BLACK);
        }
    }

}

/**
 * Fonction effectuant concretement le déplacement choisi par le joueur sur le plateau
 * @param board
 * @param move
 */
void executeMove(Piece **board, int **move) {
    board[move[0][1]][move[1][1]] = board[move[0][0]][move[1][0]];
    board[move[0][1]][move[1][1]].nbMove++;
    board[move[0][0]][move[1][0]] = (Piece) {VIDE, NONE, 0};
}

/**
 * Fonction retirant le déplacement précédent si la vérification revient fausse
 * @param board
 * @param move
 * @param previous
 */
void undoMove(Piece **board, int **move, Piece previous) {
    board[move[0][0]][move[1][0]] = board[move[0][1]][move[1][1]];
    board[move[0][0]][move[1][0]].nbMove--;
    board[move[0][1]][move[1][1]] = previous;
}

/**
 * Fonction permettant de localiser un roi sur le plateau
 * @param board
 * @param taillePlateau
 * @param rois
 */
void chercherRois(Piece **board, int taillePlateau, int **rois) {
    for (int y = 0; y < taillePlateau; y++) {
        for (int x = 0; x < taillePlateau; ++x) {
            if (board[x][y].typePiece == ROI) {
                rois[board[x][y].couleurPiece - 1][0] = x;
                rois[board[x][y].couleurPiece - 1][1] = y;
            }
        }
    }
    //printf("Rois :\n%d %d\n%d %d\n", rois[0][0], rois[0][1], rois[1][0], rois[1][1]);
}
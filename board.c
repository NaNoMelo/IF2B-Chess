#include "board.h"
#include <stdlib.h>
#include "stdio.h"
#include <time.h>
#include "saisie.h"

/**
 * Fonction générant les pièces réparties alléatoirement sur le plateau
 * @param taille taille du plateau
 * @param board tableau représentant le plateau de jeu
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
 * @param taille taille du plateau
 * @param board tableau représentant le plateau de jeu
 */
void afficherPlateau(int taille, Piece **board) {
    const Couleur couleur1 = WHITE, couleur2 = BLEU_FONCE;
    const char lettres[] = {" abcdefghijkl"};
    const char pieces[] = {" PFCTDR"};
    const char couleurs[] = {" BN"};
    for (int y = 0; y <= taille; y++) {
        for (int x = 0; x <= taille; ++x) {
            if (y == 0) {
                printf(" %c ", lettres[x]);
            } else {
                if (x == 0) {
                    printf(" %d", y);
                    if (y < 10) printf(" ");
                } else {
                    setColor((x + y) % 2 * (couleur1 - couleur2) + couleur2,
                             (x + y + 1) % 2 * (couleur1 - couleur2) + couleur2);
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
 * @param board tableau représentant le plateau de jeu
 * @param move tableau à 2 dimensions représentant le mouvement effectué
 */
void executeMove(Piece **board, int **move) {
    board[move[0][1]][move[1][1]] = board[move[0][0]][move[1][0]];
    board[move[0][1]][move[1][1]].nbMove++;
    board[move[0][0]][move[1][0]] = (Piece) {VIDE, NONE, 0};
}

/**
 * Fonction retirant le déplacement précédent si la vérification revient fausse
 * @param board tableau représentant le plateau de jeu
 * @param move tableau à 2 dimensions représentant le mouvement effectué
 * @param previous pièce présente dans la case d'arrivée avant le déplacement
 */
void undoMove(Piece **board, int **move, Piece previous) {
    board[move[0][0]][move[1][0]] = board[move[0][1]][move[1][1]];
    board[move[0][0]][move[1][0]].nbMove--;
    board[move[0][1]][move[1][1]] = previous;
}

/**
 * Fonction permettant de localiser un roi sur le plateau
 * @param board tableau représentant le plateau de jeu
 * @param taillePlateau taille du plateau
 * @param rois tableau à 2 dimensions contenant les coordonnées des rois
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
}
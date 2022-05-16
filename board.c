//
// Created by natha on 10/05/2022.
//

#include "board.h"
#include <stdlib.h>
#include "stdio.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "saisie.h"
#include "verif.h"


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

void afficherPlateau(int taille, Piece **board) {
    char lettres[] = {" abcdefghijkl"};
    char pieces[] = {"-PFCTDR"};
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
                    printf(" %c%c", pieces[board[x - 1][y - 1].typePiece],
                           couleurs[board[x - 1][y - 1].couleurPiece]);
                }
            }

            if (x == taille) printf("\n");
        }
    }
}

void executeMove(Piece **board, int **move) {
    board[move[0][1]][move[1][1]] = board[move[0][0]][move[1][0]];
    board[move[0][1]][move[1][1]].nbMove++;
    board[move[0][0]][move[1][0]] = (Piece) {VIDE, NONE, 0};
}

int verifDeplacement(Piece **board, int **move, int joueur) {

    int validite;

    if (board[move[0][0]][move[1][0]].typePiece == PION) { // 0 si ok, 1 sinon
        validite = verifPion(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == FOU) { // 0 si ok, 2 sinon
        validite = verifFou(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == CAVALIER) { // 0 si ok, 3 sinon
        validite = verifCavalier(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == TOUR) { // 0 si ok, 4 sinon
        validite = verifTour(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == DAME) { // 0 si ok, 5 sinon
        validite = verifDame(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == ROI) { // 0 si ok, 6 sinon
        validite = verifRoi(board, move);
        return validite;
    } else if (board[move[0][0]][move[1][0]].typePiece == VIDE) { // 7 si case de départ Vide
        return 7;
    } else {
        return 8;
    }
}
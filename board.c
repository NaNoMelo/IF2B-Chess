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

void undoMove(Piece **board, int **move, Piece previous) {
    board[move[0][0]][move[1][0]] = board[move[0][1]][move[1][1]];
    board[move[0][0]][move[1][0]].nbMove--;
    board[move[0][1]][move[1][1]] = previous;
}

int verifDeplacement(Piece **board, int **move, int joueur, int taillePlateau) {
    int validite, piece;
    Piece previous;
    if (board[move[0][0]][move[1][0]].typePiece == VIDE) {
        validite = 1;       //mouvement case vide
    } else if (board[move[0][0]][move[1][0]].couleurPiece != joueur) {
        validite = 2;       //mouvement pièce autre joueur
    } else if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        validite = 3;       //pas de déplacement
    } else {
        validite = verifMouvement(board, move, &piece);
        printf("Piece : %d\n", piece);
        if (validite) {
            //4 si move illegal
            //5 si piece sur le chemin
        } else if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            validite = 6;   //mange propre piece
        } else {
            previous = board[move[0][1]][move[1][1]];
            executeMove(board, move);
            if (verifEchec(board, taillePlateau) == joueur) {
                validite = 7;   //echec
                undoMove(board, move, previous);
            }
        }
    }
    printErr(validite);
    return validite;
}

void chercherRois(Piece **board, int taillePlateau, int **rois) {
    for (int y = 0; y < taillePlateau; y++) {
        for (int x = 0; x < taillePlateau; ++x) {
            if (board[x][y].typePiece == ROI) {
                rois[0][board[x][y].couleurPiece - 1] = x;
                rois[1][board[x][y].couleurPiece - 1] = y;
            }
        }
    }
}
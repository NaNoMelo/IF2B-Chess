//
// Created by yannt on 16/05/2022.
//

#include "verif.h"
#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "ctype.h"
#include "board.h"

/**
 * Fonction globale de vérifications des déplacement qui vérifie chaque cas possible
 * @param board
 * @param move
 * @param joueur
 * @param taillePlateau
 * @return "validité" qui permettra d'afficher les messages d'erreur correspondants si il y a une erreur dans la déplacement
 */
int verifDeplacement(Piece **board, int **move, int joueur, int taillePlateau, int *echec) {
    int validite;
    Piece previous;

    if (board[move[0][0]][move[1][0]].typePiece == VIDE) {
        validite = 1;       //mouvement case vide
    } else if (board[move[0][0]][move[1][0]].couleurPiece != joueur) {
        validite = 2;       //mouvement pièce autre joueur
    } else if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        validite = 3;       //pas de déplacement
    } else {
        validite = verifMouvement(board, move, joueur);
        if (validite) {
            //4 si move illegal
            //5 si piece sur le chemin
        } else if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            validite = 6;   //mange propre piece
        } else {
            previous = board[move[0][1]][move[1][1]];
            executeMove(board, move);
            *echec = verifEchec(board, taillePlateau);
            undoMove(board, move, previous);
            if (*echec == joueur) {
                validite = 7;   //echec
            }
        }
    }
    return validite;
}

/**
 * Fonction centralisant les vérifications des pièces
 * @param board
 * @param move
 * @param piece
 * @param joueur
 * @return "validité" qui contient le code retourné par chaque vérification
 */
int verifMouvement(Piece **board, int **move, int joueur) {
    int validite;
    switch (board[move[0][0]][move[1][0]].typePiece) {
        case VIDE:
            validite = 1;
            break;
        case PION:
            validite = verifPion(board, move, joueur);
            break;
        case FOU:
            validite = verifFou(board, move);
            break;
        case CAVALIER:
            validite = verifCavalier(move);
            break;
        case TOUR:
            validite = verifTour(board, move);
            break;
        case DAME:
            validite = verifDame(board, move);
            break;
        case ROI:
            validite = verifRoi(move);
            break;
    }
    return validite;
}

/**
 * Fonction vérifiant si le mouvement d'un pion est possible
 * @param board
 * @param move
 * @param joueur
 * @return
 */
int verifPion(Piece **board, int **move, int joueur) {
    int pion = 0;
    joueur *= 2; //2 pour joueur 1, 4 pour joueur 2
    joueur -= 3; //-1 pour joueur 1, 1 pour joueur 2
    if (sign(move[1][1] - move[1][0]) == joueur) {
        if (board[move[0][0]][move[1][0]].nbMove > 0) {
            if (abs(move[1][1] - move[1][0]) > 1) {
                pion = 4;
            }
        } else {
            if (abs(move[1][1] - move[1][0]) > 2) {
                pion = 4;
            }
        }

        if (!pion) {
            if (move[0][1] - move[0][0] == 0) {
                if (board[move[0][1]][move[1][1]].typePiece != VIDE) pion = 5;
                if (abs(move[0][1] - move[0][0]) == 2 && board[move[0][1]][move[1][1] - joueur].typePiece != VIDE) {
                    pion = 5;
                }
            } else if (abs(move[0][1] - move[0][0]) == 1 && abs(move[1][1] - move[1][0]) == 1 &&
                       board[move[0][1]][move[1][1]].typePiece != VIDE) {
                pion = 0;
            } else pion = 4;
        } else pion = 4;
    } else pion = 4;
    return pion;
}

/**
 * Fonction vérifiant si le mouvement d'un fou est possible
 * @param board
 * @param move
 * @return 4 si le mouvement n'est pas possible, 5 si une pièce est sur la trajectoire de la pièce ou 0 si le mouvement est valide
 */
int verifFou(Piece **board, int **move) {
    int fou = 0;
    if (abs(move[0][1] - move[0][0]) == abs(move[1][1] - move[1][0])) {
        for (int i = 1; i < abs((move[0][0] - move[0][1])); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                fou = 5;
            }
        }
    } else fou = 4;
    return fou;
}

/**
 * Fonction vérifiant si le mouvement d'un cavalier est possible
 * @param move
 * @return 0 si le mouvement est possible, 4 si il n'est pas possible
 */
int verifCavalier(int **move) {
    int cavalier = 0;
    if (!(abs(move[0][1] - move[0][0]) + abs(move[1][1] - move[1][0]) == 3 &&
          (abs(move[0][1] - move[0][0]) < 3 && abs(move[0][1] - move[0][0]) > 0))) {
        cavalier = 4;
    }
    return cavalier;
}

/**
 * Fonction vérifiant si le mouvement d'une tour est possible
 * @param board
 * @param move
 * @return 0 si le mouvement est possible, 4 si il n'est pas valide, 5 si il y a une pièce sur la trajectoire
 */
int verifTour(Piece **board, int **move) {
    int tour = 0;
    if (abs(move[1][1] - move[1][0]) == 0 || abs(move[0][1] - move[0][0]) == 0) {
        for (int i = 1; i < abs(move[0][1] - move[0][0]) + abs(move[1][1] - move[1][0]); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                tour = 5;
            }
        }
    } else {
        tour = 4;
    }
    return tour;
}

/**
 * Fonctvérifiant si le mouvement d'une dame est possible en utilisant les fonctions du fou et de la tour
 * @param board
 * @param move
 * @return 0 si le mouvement est possible, tour/fou qui contient le numéro d'erreur relié à la tour ou au fou
 */
int verifDame(Piece **board, int **move) {
    int dame;
    int tour = verifTour(board, move), fou = verifFou(board, move);
    if (tour == 0 || fou == 0) {
        dame = 0;
    } else if (tour > fou) {
        dame = tour;
    } else {
        dame = fou;
    }
    return dame;
}

/**
 * Foncton vérifiant si le mouvement d'un roi est possible
 * @param move
 * @return 0 si le mouvement est possible, 4 si le mouvement n'est pas valide
 */
int verifRoi(int **move) {
    int roi;
    if (abs(move[1][1] - move[1][0]) <= 1 && abs(move[0][1] - move[0][0]) <= 1) {
        roi = 0;
    } else {
        roi = 4;
    }
    return roi;
}

/**
 * Fonction vérifiant si il y a echec
 * @param board
 * @param taillePlateau
 * @return 0 si il n'y a pas echec, le joueur auquel appartient le roi en echec sinon
 */
int verifEchec(Piece **board, int taillePlateau) {
    int **rois = (int **) malloc(2 * sizeof(int *));
    rois[0] = (int *) malloc(2 * sizeof(int));
    rois[1] = (int *) malloc(2 * sizeof(int));
    chercherRois(board, taillePlateau, rois);
    //printf("Rois :\n%d %d\n%d %d\n",rois[0][0],rois[0][1],rois[1][0],rois[1][1]);
    int **tempMove = (int **) malloc(2 * sizeof(int));
    tempMove[0] = (int *) malloc(2 * sizeof(int));
    tempMove[1] = (int *) malloc(2 * sizeof(int));
    int echec = 0;
    int r = 0, y, x;
    while (r < 2 && !echec) {
        y = 0;
        while (y < taillePlateau && !echec) {
            x = 0;
            while (x < taillePlateau && !echec) {
                tempMove[0][0] = x;
                tempMove[0][1] = rois[r][0];
                tempMove[1][0] = y;
                tempMove[1][1] = rois[r][1];
                if (!verifPion(board, tempMove, -1 * (r - 2))) {
                    if (board[x][y].typePiece == PION && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifFou(board, tempMove)) {
                    if (board[x][y].typePiece == FOU && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifCavalier(tempMove)) {
                    if (board[x][y].typePiece == CAVALIER && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifTour(board, tempMove)) {
                    if (board[x][y].typePiece == TOUR && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifDame(board, tempMove)) {
                    if (board[x][y].typePiece == DAME && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifRoi(tempMove)) {
                    if (board[x][y].typePiece == ROI && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                //if (echec) printf("x:%d y:%d r:%d\n", x, y, r + 1);
                x++;
            }
            y++;
        }
        r++;
    }
    free(rois);
    free(tempMove);
    return echec;
}

int verifMat(Piece **board, int taillePlateau, int joueur) {
    Piece previous;
    bool mat = true;
    int echec;
    int **tempMove = (int **) malloc(2 * sizeof(int));
    tempMove[0] = (int *) malloc(2 * sizeof(int));
    tempMove[1] = (int *) malloc(2 * sizeof(int));

    int xa = 0, ya, xb, yb;

    while (xa < taillePlateau && mat) {
        ya = 0;
        while (ya < taillePlateau && mat) {
            if (board[xa][ya].couleurPiece == joueur) {
                xb = 0;
                while (xb < taillePlateau && mat) {
                    yb = 0;
                    while (yb < taillePlateau && mat) {
                        tempMove[0][0] = xa;
                        tempMove[0][1] = xb;
                        tempMove[1][0] = ya;
                        tempMove[1][1] = yb;
                        if (!verifMouvement(board, tempMove, joueur)) {
                            previous = board[xb][yb];
                            executeMove(board, tempMove);
                            echec = verifEchec(board, taillePlateau);
                            undoMove(board, tempMove, previous);
                            printf("%d", echec);
                            if (echec != joueur) {
                                printf("Mat :\n%d %d\n%d %d\n", xa, ya, xb, yb);
                                mat = false;
                            }
                        }
                        yb++;
                    }
                    xb++;
                }
            }
            ya++;
        }
        xa++;
    }
    free(tempMove);
    return mat;
}
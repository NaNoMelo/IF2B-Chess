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
        validite = verifMouvement(board, move, &piece, joueur);
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

/**
 * Fonction centralisant les vérifications des pièces
 * @param board
 * @param move
 * @param piece
 * @param joueur
 * @return "validité" qui contient le code retourné par chaque vérification
 */
int verifMouvement(Piece **board, int **move, int *piece, int joueur) {
    int validite;
    switch (board[move[0][0]][move[1][0]].typePiece) {
        case VIDE:
            validite = 1;
            *piece = 0;
            break;
        case PION:
            validite = verifPion(board, move, joueur);
            *piece = 1;
            break;
        case FOU:
            validite = verifFou(board, move);
            *piece = 2;
            break;
        case CAVALIER:
            validite = verifCavalier(move);
            *piece = 3;
            break;
        case TOUR:
            validite = verifTour(board, move);
            *piece = 4;
            break;
        case DAME:
            validite = verifDame(board, move);
            *piece = 5;
            break;
        case ROI:
            validite = verifRoi(move);
            *piece = 6;
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

    joueur *= 2; //2 pour joueur 1, 4 pour joueur 2
    joueur -= 3; //-1 pour joueur 1, 1 pour joueur 2

    if (sign(move[1][1] - move[1][0]) == joueur) {
        if (move[0][1] - move[0][0] == 0) {
            if (board[move[0][0]][move[1][0]].nbMove > 0) {
                if (abs(move[1][1] - move[1][0]) > 1) {
                    return 4;
                } else if (board[move[0][1]][move[1][1]].typePiece != VIDE) {
                    return 5;
                } else return 0;
            } else {
                if (abs(move[1][1] - move[1][0]) > 2) {
                    return 4;
                } else if (board[move[0][1]][move[1][1] - joueur].typePiece != VIDE ||
                           board[move[0][1]][move[1][1]].typePiece != VIDE) {
                    return 5;
                } else return 0;
            }
        } else if (abs(move[1][1] - move[1][0]) > 1 || abs(move[0][1] - move[0][0]) > 1) {
            return 4;
        } else return 0;
    } else return 4;



    /*if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        printf("Vous n'avez effectuer aucun déplacement\n");
        return 1;
    } else if ((board[move[0][0]][move[1][0]].nbMove == 0) && (move[0][0] - move[0][1] == 0) &&
               (move[1][0] - move[1][1] == 2)) { //BLANC DONC VERS LE HAUT
        if (board[move[0][0]][move[1][0] - 1].typePiece == VIDE && board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][0]][move[1][0] - 1].typePiece != VIDE ||
                   board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 1;
        }
    } else if ((board[move[0][0]][move[1][0]].nbMove == 0) && (move[0][0] - move[0][1] == 0) &&
               (move[1][0] - move[1][1] == -2)) { //NOIR DONC VERS LE BAS
        if (board[move[0][0]][move[1][0] + 1].typePiece == VIDE && board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][0]][move[1][0] + 1].typePiece != VIDE ||
                   board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 1;
        }
    } else if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] == 1) { //BLANC TOUT DROIT DE 1
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 1;
        }
    } else if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] == -1) { //NOIR TOUT DROIT DE 1
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 1;
        }
    } else if (move[0][0] - move[0][1] == 1 && move[1][0] - move[1][1] == 1) { //BLANC DIAGONALE DROITE
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 1;
        }
    } else if (move[0][0] - move[0][1] == -1 && move[1][0] - move[1][1] == 1) { //BLANC DIAGONALE GAUCHE
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 1;
        }
    } else if (move[0][0] - move[0][1] == 1 && move[1][0] - move[1][1] == -1) { //NOIR DIAGONALE DOITE (DE A VERS Z)
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 1;
        }
    } else if (move[0][0] - move[0][1] == -1 && move[1][0] - move[1][1] == -1) { //NOIR DIAGONALE GAUCHE (DE Z VERS A)
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 1;
        }
    }*/
}

/**
 * Fonction vérifiant si le mouvement d'un fou est possible
 * @param board
 * @param move
 * @return 4 si le mouvement n'est pas possible, 5 si une pièce est sur la trajectoire de la pièce ou 0 si le mouvement est valide
 */
int verifFou(Piece **board, int **move) {

    if (abs((move[0][1] - move[0][0]) == abs(move[1][1] - move[1][0]))) {
        for (int i = 1; i < abs((move[0][0] - move[0][1])); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                return 5;
            }
        }
    } else {
        return 4;
    }
    return 0;
}

/**
 * Fonction vérifiant si le mouvement d'un cavalier est possible
 * @param move
 * @return 0 si le mouvement est possible, 4 si il n'est pas possible
 */
int verifCavalier(int **move) {

    if (abs(move[0][1] - move[0][0]) + abs(move[1][1] - move[1][0]) == 3 &&
        (abs(move[0][1] - move[0][0]) < 3 && abs(move[0][1] - move[0][0]) > 0)) {
        return 0;
    } else {
        return 4;
    }
}

/**
 * Fonction vérifiant si le mouvement d'une tour est possible
 * @param board
 * @param move
 * @return 0 si le mouvement est possible, 4 si il n'est pas valide, 5 si il y a une pièce sur la trajectoire
 */
int verifTour(Piece **board, int **move) {
    if (abs(move[1][1] - move[1][0]) == 0 ||
        abs(move[0][1] - move[0][0]) == 0) {
        for (int i = 1; i < abs(move[0][1] - move[0][0]) + abs(move[1][1] - move[1][0]); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                return 5;
            }
        }
    } else {
        return 4;
    }
    return 0;
}

/**
 * Fonctvérifiant si le mouvement d'une dame est possible en utilisant les fonctions du fou et de la tour
 * @param board
 * @param move
 * @return 0 si le mouvement est possible, tour/fou qui contient le numéro d'erreur relié à la tour ou au fou
 */
int verifDame(Piece **board, int **move) {
    int tour = verifTour(board, move), fou = verifFou(board, move);
    if (tour == 0 || fou == 0) {
        return 0;
    } else if (tour > fou) {
        return tour;
    } else {
        return fou;
    }
}

/**
 * Foncton vérifiant si le mouvement d'un roi est possible
 * @param move
 * @return 0 si le mouvement est possible, 4 si le mouvement n'est pas valide
 */
int verifRoi(int **move) {
    if (abs(move[1][1] - move[1][0]) <= 1 && abs(move[0][1] - move[0][0]) <= 1) {
        return 0;
    } else {
        return 4;
    }
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
    int r = 0, y = 0, x = 0;
    while (r < 2 && !echec) {
        while (y < taillePlateau && !echec) {
            while (x < taillePlateau && !echec) {
                tempMove[0][0] = x;
                tempMove[0][1] = rois[r][0];
                tempMove[1][0] = y;
                tempMove[1][1] = rois[r][1];
                if (!verifPion(board, tempMove, -1*(r-2))) {
                    if (board[x][y].typePiece == PION && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                    }
                }
                if (!verifFou(board, tempMove)) {
                    if (board[x][y].typePiece == FOU && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                        break;
                    }
                }
                if (!verifCavalier(tempMove)) {
                    if (board[x][y].typePiece == CAVALIER && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                        break;
                    }
                }
                if (!verifTour(board, tempMove)) {
                    if (board[x][y].typePiece == TOUR && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                        break;
                    }
                }
                if (!verifDame(board, tempMove)) {
                    if (board[x][y].typePiece == DAME && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                        break;
                    }
                }
                if (!verifRoi(tempMove)) {
                    if (board[x][y].typePiece == ROI && board[x][y].couleurPiece != r + 1) {
                        echec = r + 1;
                        break;
                    }
                }
                if (echec) printf("x:%d y:%d r:%d\n", x, y, r + 1);
            }
        }
    }
    free(rois);
    free(tempMove);
    return echec;
}
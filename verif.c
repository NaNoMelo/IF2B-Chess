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

int verifPion(Piece **board, int **move) {

    if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        printf("Vous n'avez effectuer aucun déplacement\n");
        return 0;
    }

    if ((board[move[0][0]][move[1][0]].nbMove == 0) && (move[0][0] - move[0][1] == 0) &&
        (move[1][0] - move[1][1] == 2)) { //BLANC DONC VERS LE HAUT
        if (board[move[0][0]][move[1][0] - 1].typePiece == VIDE && board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][0]][move[1][0] - 1].typePiece != VIDE ||
                   board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 0;
        }
    }

    if ((board[move[0][0]][move[1][0]].nbMove == 0) && (move[0][0] - move[0][1] == 0) &&
        (move[1][0] - move[1][1] == -2)) { //NOIR DONC VERS LE BAS
        if (board[move[0][0]][move[1][0] + 1].typePiece == VIDE && board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][0]][move[1][0] + 1].typePiece != VIDE ||
                   board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 0;
        }
    }

    if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] == 1) { //BLANC TOUT DROIT DE 1
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 0;
        }
    }

    if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] == -1) { //NOIR TOUT DROIT DE 1
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != VIDE) {
            return 0;
        }
    }

    if (move[0][0] - move[0][1] == 1 && move[1][0] - move[1][1] == 1) { //BLANC DIAGONALE DROITE
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }
    }

    if (move[0][0] - move[0][1] == -1 && move[1][0] - move[1][1] == 1) { //BLANC DIAGONALE GAUCHE
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }
    }
    if (move[0][0] - move[0][1] == 1 && move[1][0] - move[1][1] == -1) { //NOIR DIAGONALE DOITE (DE A VERS Z)
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }
    }

    if (move[0][0] - move[0][1] == -1 && move[1][0] - move[1][1] == -1) { //NOIR DIAGONALE GAUCHE (DE Z VERS A)
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece == board[move[0][0]][move[1][0]].typePiece) {
            printf("Vous n'avez pas le droit de manger une de vos pièces\n");
            return 0;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        } else if (board[move[0][1]][move[1][1]].typePiece != board[move[0][0]][move[1][0]].typePiece &&
                   board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }
    }
    //si premier coup: -> peut avancer de deux cases
    //                           -> si rien sur case 1 et 2
    //si pas premier coup: -> peut avancer d'une case
    //                           -> si rien sur case
    //                     -> peut manger en diagonale gauche
    //                           -> si pièces différente de sa couleur
    //                           -> si pièce != du Roi de l'autre couleur (car dans ce cas c'est l'échec)
    //                     -> peut manger en diaginale droite
    //                           -> si pièces différente de sa couleur
    //                           -> si pièce != du Roi de l'autre couleur (car dans ce cas c'est l'échec)
    // dans un premier temps on regarde la couleur du pion pour savoir si il doit monter ou descendre /au plateau
    // on va regarder le move de départ et le move d'arrivé et voir dans quel cas on se trouve
    // d'abord on compare les x, si ils sont pareils c'est déplacement droit sinon en diagonale
    // on vérifie si le x se déplace que de 1 à gauche ou a droite pour diagonale sinon mauvais coup
    // on regarde coord en y de départ et d'arrivé pour déplacement droit ensuite soustraction pour se placer dans un cas
    // pour diagonale on vérifie que soustraction de y départ - y arrivé = 1
}

int verifFou(Piece **board, int **move) {

    if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        printf("Vous n'avez effectuer aucun déplacement\n");
        return 0;
    }

    if (abs((move[0][1] - move[0][0]) == abs(move[1][1] - move[1][0]))) {
        for (int i = 1; i < abs((move[0][0] - move[0][1])); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                return 0;
            }

        }

        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        }
    }

    if (abs((move[0][1] - move[0][0]) != abs(move[1][1] - move[1][0]))) {
        return 0;
    }
    // -> Pas de limite de déplacement mais seulement en diagonale
    // on vérifie d'abord si le coup est correct
    //      -> on compare la différence des x et des y
    //      -> la différence devrait être nulle pour un déplacement en diagonale
    // on vérifie ensuite chaque case que le fou va parcourir
    // -> on cherche déja si c'est un déplacement vers la droite ou la gauche
    //      -> si droite
    //              -> (BLANC) on augmente les coord x et y de départ de 1 et on regarde la case,
    //                 (NOIRS) on augmente le x de 1 et on soustraie le y de 1
    //                      -> si case vide on continue jusqu'aux coord d'arrivée
    //                      -> si pièce de la même couleur coup impossible
    //                      -> si pièce autre couleur:
    //                              -> si coord de la ou on est == coord d'arrivé et pièces adverse != roi, coup possible
    //                              -> si coord de la ou on est != coup d'arrivé, coup impossible
    //      -> (BLANC) si gauche pareil mais on ajoute 1 au y et soustraie 1 au x,
    //         (NOIR) on soustraie 1 aux coord a chaque fois
}

int verifCavalier(Piece **board, int **move) {

    if ((move[0][0] - move[0][1]) == 0 || (move[0][0] - move[0][1]) > 2) {
        return 0;
    }

    if ((move[0][0] - move[0][1] == 2 || move[0][0] - move[0][1] == -2) &&
        (move[1][0] - move[1][1] == 1 || move[1][0] - move[1][1] == -1)) {

        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            printf("Vous ne pouvez pas manger vos propre pièces");
            return 0;
        }

        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        }
    }

    if ((move[1][0] - move[1][1] == 2 || move[1][0] - move[1][1] == -2) &&
        (move[0][0] - move[0][1] == 1 || move[0][0] - move[0][1] == -1)) {

        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            printf("Vous ne pouvez pas manger un roi\n");
            return 0;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            printf("Vous ne pouvez pas manger vos propre pièces\n");
            return 0;
        }

        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            return 1;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        }
    }
    // -> limite de déplacement en l
    // peut passer au dessus des autres pièces
    // -> on vérifie si la différence des x ou des y est égale à 1 ou a 2
    //          -> si différence == 0 ou <3 coup incorrect
    //          -> si différence x ou y == 2 on vérifie que différence de x ou y == 1
    //          -> si différence x ou y == 1 on vérifie que différence de x ou y == 2
    // -> on vérifie si la case d'arriver à une pièce de l'autre couleur dessus
    //          -> si même couleur coup impossible
    //          -> si roi autre couleur coup impossible
    //          -> si autre couleur sauf roi coup possible
    //          -> si aucune pièce coup possible

}

int verifTour(Piece **board, int **move) {

    if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) { //SI AUCUN MOUVEMENT
        printf("Vous n'avez effectuer aucun déplacement\n");
        return 0;
    }

    if (move[0][0] - move[0][1] != 0 &&
        move[1][0] - move[1][1] != 0) { //SI DEPLACEMENT VERTICALE ET HORIZONTAL EN MEME TEMPS
        return 0;
    }

    if (move[0][0] - move[0][1] != 0 && move[1][0] - move[1][1] == 0) { //DEPLACEMENT HORIZONTAL
        if (move[0][0] - move[0][1] < 0) { //VERS LA DROITE
            for (int i = 1; i < (move[0][1] - move[0][0]); i++) {
                if ((board[move[0][0] + i][move[1][0]].typePiece != VIDE) && ((move[0][0] + i) != move[0][1])) {
                    return 0;
                }
                if ((move[0][0] + i) == move[0][1]) {
                    if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                        board[move[0][1]][move[1][1]].typePiece != ROI) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                        printf("Vous ne pouvez pas manger vos propre pièces\n");
                        return 0;
                    }
                    if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                        printf("Vous ne pouvez pas manger un roi\n");
                        return 0;
                    }
                }
            }
        }
        if (move[0][0] - move[0][1] > 0) { //VERS LA GAUCHE
            for (int i = 1; i < (move[0][0] - move[0][1]); i++) {
                if ((board[move[0][0] - i][move[1][0]].typePiece != VIDE) && ((move[0][0] - i) != move[0][1])) {
                    return 0;
                }
                if ((move[0][0] - i) == move[0][1]) {
                    if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                        board[move[0][1]][move[1][1]].typePiece != ROI) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                        printf("Vous ne pouvez pas manger vos propre pièces\n");
                        return 0;
                    }
                    if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                        printf("Vous ne pouvez pas manger un roi\n");
                        return 0;
                    }
                }
            }
        }
    }

    if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] != 0) { //DEPLACEMENT VERTICAL
        if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] != 0) {
            if (move[1][0] - move[1][1] < 0) { //VERS LE BAS
                for (int i = 1; i < (move[1][1] - move[1][0]); i++) {
                    if ((board[move[0][0]][move[1][0] + i].typePiece != VIDE) && ((move[1][0] + i) != move[1][1])) {
                        return 0;
                    }
                    if ((move[1][0] + i) == move[1][1]) {
                        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                            board[move[0][1]][move[1][1]].typePiece != ROI) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                            printf("Vous ne pouvez pas manger vos propre pièces\n");
                            return 0;
                        }
                        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                            printf("Vous ne pouvez pas manger un roi\n");
                            return 0;
                        }
                    }
                }
            }
            if (move[1][0] - move[1][1] > 0) { //VERS LE HAUT
                for (int i = 1; i < (move[1][0] - move[1][1]); i++) {
                    if ((board[move[0][0]][move[1][0] - i].typePiece != VIDE) && ((move[1][0] - i) != move[1][1])) {
                        return 0;
                    }
                    if ((move[1][0] - i) == move[1][1]) {
                        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                            board[move[0][1]][move[1][1]].typePiece != ROI) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                            printf("Vous ne pouvez pas manger vos propre pièces\n");
                            return 0;
                        }
                        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                            printf("Vous ne pouvez pas manger un roi\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // -> déplacement seulement dans une direction
    // -> on soustraie les déplacement d'arrivé et de départ et on regarde si l'un des deux est égal à 0
    //          -> si aucun == 0 coup impossible
    //          -> si les deux == 0 coup impossible
    //          -> si un seul des deux == 0
    // -> si c'est le déplacement en x qui est != de 0
    //          -> si différence négative déplacement vers la droite
    //              -> on rajoute 1 à x et on regarde si il y a une pièce
    //                  -> si il y a une pièce et que coord != de celles d'arrivé
    //                  -> si coord == coord d'arrivé
    //                      -> si pas de pièce, coup possible
    //                      -> si pièce de même couleur coup impossible
    //                      -> si pièce de couleur differente et != du roi coup possible
    //          -> si différence positive déplacement vers la gauche
    //              -> on retire 1 à x et on regarde si il y a une pièce
    //                  -> si il y a une pièce et que coord != de celles d'arrivé
    //                  -> si coord == coord d'arrivé
    //                      -> si pas de pièce, coup possible
    //                      -> si pièce de même couleur coup impossible
    //                      -> si pièce de couleur differente et != du roi coup possible
    // -> si c'est le déplacement en x qui est != de 0
    //           -> si différence négative déplacement vers le haut
    //              -> on rajoute 1 à y et on regarde si il y a une pièce
    //                  -> si il y a une pièce et que coord != de celles d'arrivé
    //                  -> si coord == coord d'arrivé
    //                      -> si pas de pièce, coup possible
    //                      -> si pièce de même couleur coup impossible
    //                      -> si pièce de couleur differente et != du roi coup possible
    //          -> si différence positive déplacement vers le bas
    //              -> on retire 1 à y et on regarde si il y a une pièce
    //                  -> si il y a une pièce et que coord != de celles d'arrivé
    //                  -> si coord == coord d'arrivé
    //                      -> si pas de pièce, coup possible
    //                      -> si pièce de même couleur coup impossible
    //                      -> si pièce de couleur differente et != du roi coup possible
}

int verifDame(Piece **board, int **move) {

    if ((move[0][0] == move[0][1]) && (move[1][0] == move[1][1])) {
        printf("Vous n'avez effectuer aucun déplacement\n");
        return 0;
    }

    if (move[0][0] - move[0][1] != 0 && move[1][0] - move[1][1] == 0) { //DEPLACEMENT HORIZONTAL
        if (move[0][0] - move[0][1] < 0) { //VERS LA DROITE
            for (int i = 1; i < (move[0][1] - move[0][0]); i++) {
                if ((board[move[0][0] + i][move[1][0]].typePiece != VIDE) && ((move[0][0] + i) != move[0][1])) {
                    return 0;
                }
                if ((move[0][0] + i) == move[0][1]) {
                    if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                        board[move[0][1]][move[1][1]].typePiece != ROI) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                        printf("Vous ne pouvez pas manger vos propre pièces\n");
                        return 0;
                    }
                    if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                        printf("Vous ne pouvez pas manger un roi\n");
                        return 0;
                    }
                }
            }
        }
        if (move[0][0] - move[0][1] > 0) { //VERS LA GAUCHE
            for (int i = 1; i < (move[0][0] - move[0][1]); i++) {
                if ((board[move[0][0] - i][move[1][0]].typePiece != VIDE) && ((move[0][0] - i) != move[0][1])) {
                    return 0;
                }
                if ((move[0][0] - i) == move[0][1]) {
                    if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                        board[move[0][1]][move[1][1]].typePiece != ROI) {
                        return 1;
                    }
                    if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                        printf("Vous ne pouvez pas manger vos propre pièces\n");
                        return 0;
                    }
                    if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                        printf("Vous ne pouvez pas manger un roi\n");
                        return 0;
                    }
                }
            }
        }
    }

    if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] != 0) { //DEPLACEMENT VERTICAL
        if (move[0][0] - move[0][1] == 0 && move[1][0] - move[1][1] != 0) {
            if (move[1][0] - move[1][1] < 0) { //VERS LE BAS
                for (int i = 1; i < (move[1][1] - move[1][0]); i++) {
                    if ((board[move[0][0]][move[1][0] + i].typePiece != VIDE) && ((move[1][0] + i) != move[1][1])) {
                        return 0;
                    }
                    if ((move[1][0] + i) == move[1][1]) {
                        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                            board[move[0][1]][move[1][1]].typePiece != ROI) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                            printf("Vous ne pouvez pas manger vos propre pièces\n");
                            return 0;
                        }
                        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                            printf("Vous ne pouvez pas manger un roi\n");
                            return 0;
                        }
                    }
                }
            }
            if (move[1][0] - move[1][1] > 0) { //VERS LE HAUT
                for (int i = 1; i < (move[1][0] - move[1][1]); i++) {
                    if ((board[move[0][0]][move[1][0] - i].typePiece != VIDE) && ((move[1][0] - i) != move[1][1])) {
                        return 0;
                    }
                    if ((move[1][0] - i) == move[1][1]) {
                        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
                            board[move[0][1]][move[1][1]].typePiece != ROI) {
                            return 1;
                        }
                        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
                            printf("Vous ne pouvez pas manger vos propre pièces\n");
                            return 0;
                        }
                        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
                            printf("Vous ne pouvez pas manger un roi\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    if (abs((move[0][1] - move[0][0]) == abs(move[1][1] - move[1][0]))) {
        for (int i = 1; i < abs((move[0][0] - move[0][1])); i++) {
            if (board[move[0][0] + i * sign(move[0][1] - move[0][0])][move[1][0] + i * sign(move[1][1] -
                                                                                            move[1][0])].typePiece !=
                VIDE) {
                return 0;
            }

        }

        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }

        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            return 1;
        }
    }
}

int verifRoi(Piece **board, int **move) {

    if (move[0][1] - move[0][0] == 1 && move[1][1] - move[1][0] == 0) { //DROITE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == -1 && move[1][1] - move[1][0] == 0) { //GAUCHE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == 0 && move[1][1] - move[1][0] == 1) { //HAUT
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == 0 && move[1][1] - move[1][0] == -1) { //BAS
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == 1 && move[1][1] - move[1][0] == 1) { //HAUT DROITE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == 1 && move[1][1] - move[1][0] == -1) { //BAS DROITE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == -1 && move[1][1] - move[1][0] == 1) { //HAUT GAUCHE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }

    if (move[0][1] - move[0][0] == -1 && move[1][1] - move[1][0] == -1) { //BAS GAUCHE
        if (board[move[0][1]][move[1][1]].couleurPiece == board[move[0][0]][move[1][0]].couleurPiece) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == ROI) {
            return 0;
        }
        if (board[move[0][1]][move[1][1]].typePiece == VIDE) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
        if (board[move[0][1]][move[1][1]].couleurPiece != board[move[0][0]][move[1][0]].couleurPiece &&
            board[move[0][1]][move[1][1]].typePiece != ROI) {
            //vérifie si pas echec si echec return 0 si pas echec return 1
            return 1;
        }
    }
}
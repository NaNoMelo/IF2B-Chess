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
    char couleurs[] = {" NB"};
    for (int y = 0; y <= taille; y++) {
        for (int x = 0; x <= taille; ++x) {
            if (y == 0) {
                printf(" %c ", lettres[x]);
            } else {
                if (x == 0) {
                    printf(" %d", taille - y + 1);
                    if (taille - y + 1 < 10) printf(" ");
                } else {
                    printf(" %c%c", pieces[board[x - 1][y - 1].typePiece],
                           couleurs[board[x - 1][y - 1].couleurPiece]);
                }
            }

            if (x == taille) printf("\n");
        }
    }
}

void verifDeplacement(Piece **board, int **move) {

}

void verifPion(Piece **board, int **move) {
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

void verifFou(Piece **board, int **move) {
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

void verifCavalier(Piece **board, int **move) {

}

void verifTour(Piece **board, int **move) {

}

void verifReine(Piece **board, int **move) {

}

void verifRoi(Piece **board, int **move) {

}
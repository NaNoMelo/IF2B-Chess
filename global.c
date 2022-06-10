//
// Created by natha on 10/06/2022.
//

#include "global.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "saisie.h"
#include "board.h"
#include "verif.h"
#include "save.h"
/**
 *
 * @param board
 * @param tour
 * @param taillePlateau
 */
void game(Piece **board, int tour, int taillePlateau) {
    int **move = (int **) malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        move[i] = (int *) malloc(sizeof(int) * 2);
    }
    bool partie = true;
    int joueur, echec, action, validite;

    while (partie) {
        joueur = tour % 2 + 1; //si joueur Blanc : 1, si joueur Noir : 2
        afficherPlateau(taillePlateau, board);
        do {
            do {
                action = askDeplacement(taillePlateau, joueur, move);
                switch (action) {
                    default:
                        break;
                    case 1:
                        saveGame(board, taillePlateau, tour);
                        break;
                    case 2:
                        printf("Abandon du joueur %d !\n", joueur);
                        partie = false;
                        break;
                    case 3:
                        partie = false;
                        break;
                }
            } while (action && partie);
            if (partie) {
                validite = verifDeplacement(board, move, joueur, taillePlateau, &echec);
                printErr(validite);
            }
        } while (validite && partie);
        if (partie) {
            executeMove(board, move);
            if (echec == -1 * (joueur - 3)) {
                printf("verif mat\n");
                if (verifMat(board, taillePlateau, -1 * (joueur - 3))) {
                    printf("Echec et Mat ! Victoire pour le joueur %d\n", joueur);
                    partie = false;
                } else {
                    printf("pas mat");
                }
            }
            switch (echec) {
                default:
                    break;
                case 1:
                    printf("Echec pour le joueur Blanc !\n");
                    break;
                case 2:
                    printf("Echec pour le joueur Noir !\n");
                    break;
            }
            tour++;
        }
    }

    for (int i = 0; i < 2; ++i) {
        free(move[i]);
    }
    free(move);
}
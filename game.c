#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "saisie.h"
#include "board.h"
#include "verif.h"
#include "save.h"

/**
 * Fonction centralisant le déroulement d'une partie
 * @param board tableau représentant le plateau de jeu
 * @param tour tour auquel le jeu commence
 * @param taillePlateau taille du plateau
 */
void game(Piece **board, int tour, int taillePlateau) {
    char strColor[2][10] = {"Blanc", "Noir"};
    int **move = (int **) malloc(sizeof(int *) * 2);
    move[0] = (int *) malloc(sizeof(int) * 2);
    move[1] = (int *) malloc(sizeof(int) * 2);
    bool partie = true;
    bool tabEchec[2];
    int joueur, action, validite;
    setColor(BLACK, WHITE),
            printf(" A tout moment de la partie, vous pouvez Saisir : \n  'X' pour abandonner                             \n  'S' Pour sauvegarder l'etat actuel de la partie \n"),
            setColor(WHITE, BLACK);
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
                        printf("Abandon du joueur %s !\n", strColor[joueur - 1]);
                        partie = false;
                        break;
                    case 3:
                        partie = false;
                        break;
                }
            } while (action && partie);
            if (partie) {
                validite = verifDeplacement(board, move, joueur, taillePlateau, tabEchec);
                printErr(validite);
            }
        } while (validite && partie);
        if (partie) {
            executeMove(board, move);
            for (int i = 0; i < 2; ++i) {
                if (tabEchec[i]) {
                    printf("Echec pour le joueur %s !\n", strColor[i]);
                }
            }

            if (tabEchec[-1 * (joueur - 3)]) {
                if (verifMat(board, taillePlateau, -1 * (joueur - 3))) {
                    printf("Echec et Mat ! Victoire pour le joueur %s\n", strColor[joueur - 1]);
                    partie = false;
                }
            }
            tour++;
        }
    }
    free(move[0]);
    free(move[1]);
    free(move);
}
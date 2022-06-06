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

int main() {
    int taillePlateau, **move, tour, joueur, action, menu, echec;
    bool partie, saveAvailable, ready;
    Piece **board;

    move = (int **) malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        move[i] = (int *) malloc(sizeof(int) * 2);
    }

    FILE *save;
    do {
        partie = true, saveAvailable = true, ready = false;

        save = fopen("./save.txt", "r+");
        if (save == NULL) {
            save = fopen("./save.txt", "w");
            saveAvailable = false;
        }

        do {
            menu = askMenu();
            switch (menu) {
                case 2:
                    if (saveAvailable) {
                        printf("load\n");
                        fscanf(save, "%d", &taillePlateau);
                        printf("Taille : %d\n", taillePlateau);
                        if (taillePlateau > 12 || taillePlateau < 6) {
                            printf("Echec du chargement de la partie\n");
                        } else {
                            board = (Piece **) malloc(sizeof(Piece *) * taillePlateau);
                            for (int i = 0; i < taillePlateau; i++) {
                                board[i] = (Piece *) malloc(sizeof(Piece) * taillePlateau);
                            }
                            loadGame(save, board, taillePlateau, &tour);
                            ready = true;
                            break;
                        }
                    } else printf("Aucune sauvegarde disponible\n");
                    break;

                case 1: {
                    taillePlateau = askTaillePlateau();
                    board = (Piece **) malloc(sizeof(Piece *) * taillePlateau);
                    for (int i = 0; i < taillePlateau; i++) {
                        board[i] = (Piece *) malloc(sizeof(Piece) * taillePlateau);
                    }
                    genererPlateau(taillePlateau, board);
                    tour = 0;
                    ready = true;
                    break;
                }

                case 3:
                    printf("quit\n");
                    exit(0);

                default:
                    break;
            }
        } while (!ready);

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
                            saveGame(save, board, taillePlateau, tour);
                            break;
                        case 2:
                            printf("Abandon du joueur %d !\n", joueur);
                            break;
                        case 3:
                            exit(0);
                    }
                    if (action == 2) break;
                } while (action);
                if (action == 2) break;
            } while (verifDeplacement(board, move, joueur, taillePlateau, &echec));
            if (action == 2) break;
            executeMove(board, move);
            printf("execute into mat");
            if (echec == -1 * (joueur - 3) && verifMat(board, taillePlateau, -1 * (joueur - 3))) {
                printf("Echec et Mat ! Victoire pour le joueur %d\n", joueur);
                partie = false;
            } else {
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
            }
            tour++;
        }

        for (int i = 0; i < taillePlateau; i++) {
            free(board[i]);
        }
        free(board);
        fclose(save);
    } while (true);
    for (int i = 0; i < 2; ++i) {
        free(move[i]);
    }
    free(move);
    return 0;
}
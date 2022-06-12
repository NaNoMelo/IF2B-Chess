#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "saisie.h"
#include "board.h"
#include "save.h"
#include "game.h"

int main() {
    int taillePlateau, tour, menu;
    bool rejouer;
    bool saveAvailable, ready;
    Piece **board;
    FILE *save;
    do {
        saveAvailable = true, ready = false;

        save = fopen("./save.txt", "r");
        if (save == NULL) {
            saveAvailable = false;
            fclose(save);
        } else {
            fscanf(save, "%d", &taillePlateau);
            fclose(save);
        }

        do {
            menu = askMenu();
            switch (menu) {
                case 2:
                    if (saveAvailable) {
                        if (taillePlateau > 12 || taillePlateau < 6) {
                            printf("Echec du chargement de la partie\n");
                        } else {
                            board = (Piece **) malloc(sizeof(Piece *) * taillePlateau);
                            for (int i = 0; i < taillePlateau; i++) {
                                board[i] = (Piece *) malloc(sizeof(Piece) * taillePlateau);
                            }
                            loadGame(board, taillePlateau, &tour);
                            ready = true;
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
                    exit(0);

                default:
                    break;
            }
        } while (!ready);

        game(board, tour, taillePlateau);

        for (int i = 0; i < taillePlateau; i++) {
            free(board[i]);
        }
        free(board);

        rejouer = askOuiNon("Shouaitez vous rejouer ?");
    } while (rejouer);
    return 0;
}
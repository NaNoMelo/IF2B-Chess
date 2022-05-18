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
    FILE *save = fopen("./save.txt", "r+");
    if (save == NULL) save = fopen("./save.txt", "w");
    Piece **board;
    int taillePlateau, **move, tour, joueur;
    move = (int **) malloc(sizeof(int *) * 2);
    for (int i = 0; i < 2; i++) {
        move[i] = (int *) malloc(sizeof(int) * 2);
    }
    bool partie = true;
    int menu;
    do {
        menu = askMenu();
    } while (menu > 3 || menu < 1);
    switch (menu) {
        case 2:
            printf("load");
            fscanf(save, "%d", &taillePlateau);
            printf("%d", taillePlateau);
            if (taillePlateau > 12 || taillePlateau < 6) {
                printf("Echec du chargement de la partie, creation d'une nouvelle partie.\n");
            } else {
                //loadGame();
                break;
            }

        case 1: {
            taillePlateau = askTaillePlateau();
            board = (Piece **) malloc(sizeof(Piece *) * taillePlateau);
            for (int i = 0; i < taillePlateau; i++) {
                board[i] = (Piece *) malloc(sizeof(Piece) * taillePlateau);
            }
            genererPlateau(taillePlateau, board);
            tour = 0;
            break;
        }

        case 3:
            printf("quit");
            exit(0);

        default:
            exit(1);
    }
    while (partie == true) {
        joueur = tour % 2; //si joueur Blanc : 0, si joueur Noir alors 1
        afficherPlateau(taillePlateau, board);
//        do {
        if (askDeplacement(taillePlateau, joueur, move)) {
            if (save != NULL) {
                saveGame(save, board, taillePlateau, tour);
                exit(0);
            } else {
                printf("fichier invalide");
            }
        }
//        }while(!verifDeplacement(board,move,joueur));
        executeMove(board, move);

        tour++;

    }


    free(board);
    return 0;
}
//
// Created by natha on 10/05/2022.
//

#ifndef IF2B_CHESS_SAISIE_H
#define IF2B_CHESS_SAISIE_H

#include <stdbool.h>

typedef enum {
    BLACK,
    BLEU_FONCE,
    VERT_FONCE,
    CYAN_FONCE,
    ROUGE_FONCE,
    VIOLET,
    JAUNE_FONCE,
    GRIS_CLAIR,
    GRIS_FONCE,
    BLEU_CLAIR,
    VERT_CLAIR,
    CYAN_CLAIR,
    ROUGE_CLAIR,
    ROSE,
    JAUNE,
    WHITE
    //0    1           2           3           4            5       6            7           8           9           10          11          12           13    14     15
} Couleur;

int askMenu();

int askTaillePlateau();

int askDeplacement(int taillePlateau, int joueur, int **move);

bool askOuiNon(char *question);

int sign(int nombre);

void printErr(int validite);

void setColor(Couleur texte, Couleur fond);

#endif //IF2B_CHESS_SAISIE_H

//
// Created by natha on 10/05/2022.
//

#ifndef IF2B_CHESS_SAISIE_H
#define IF2B_CHESS_SAISIE_H

int askMenu();

int askTaillePlateau();

int askDeplacement(int taillePlateau, int joueur, int **move);

int sign(int nombre);

void printErr(int validite);

#endif //IF2B_CHESS_SAISIE_H

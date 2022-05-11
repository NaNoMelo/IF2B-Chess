//
// Created by natha on 10/05/2022.
//

#include "saisie.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

int askMenu() {
    int m;
    do {
        printf("1 | Demmarer une partie\n2 | Reprendre une partie\n3 | Quitter\n");
        scanf("%d", &m);
    } while (m > 3 || m < 1);
    return m;
}

int askTaillePlateau() {
    int t;
    do {
        printf("Choisisez la taille de votre plateau, entre 6 et 12:\n");
        scanf("%d", &t);
    } while (t > 12 || t < 6);
    return t;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.struct.h"
#include "functions.h"
#include "arbre.h"

int main(int argc, unsigned char *argv[]) {

    Arbre a = NULL;
    unsigned char buffer[51];
    scanf(" %51s", buffer);
    addNoeud(&a, buffer);
    scanf(" %51s", buffer);
    addNoeud(&a, buffer);

    printArbre(a);

    freeArbre(&a);

    return EXIT_SUCCESS;
}

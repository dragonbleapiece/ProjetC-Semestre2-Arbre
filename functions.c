#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"
#include "functions.h"


int addNoeud(Arbre *a, unsigned char *mot) {
    Arbre temp = NULL;
    if(*a == NULL) {
        *a = allocNoeud(*mot);
        if(*a == NULL) return 0;
        if(*mot != '\0')
        return addNoeud(&(*a)->filsg, mot + 1);
    }
    if(*mot > (*a)->lettre) {
        return addNoeud(&(*a)->frered, mot);
    } else if(*mot < (*a)->lettre) {
        temp = *a;
        *a = allocNoeud(*mot);
        (*a)->frered = temp;
        if(*mot != '\0')
            return addNoeud(&(*a)->filsg, mot + 1);
    } else if(*mot == (*a)->lettre && *mot != '\0') {
        return addNoeud(&(*a)->filsg, mot + 1);
    }

    return 1;
}

void printArbre_rec(Arbre a, unsigned char *buffer, size_t indice) {
    if(a != NULL) {
        buffer[indice] = a->lettre;
        if(a->lettre != '\0')
            printArbre_rec(a->filsg, buffer, indice + 1);
        else
            printf("%s\n", buffer);
        printArbre_rec(a->frered, buffer, indice);
    }
}

void printArbre(Arbre a) {
    unsigned char buffer[MAX];
    printArbre_rec(a, buffer, 0);
}

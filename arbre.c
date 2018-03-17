#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "arbre.struct.h"

Noeud *allocNoeud(unsigned char lettre) {
    Noeud *temp = (Noeud *)malloc(sizeof(*temp));

    if(temp != NULL) {
        temp->lettre = (unsigned char)tolower(lettre);
        temp->filsg = NULL;
        temp->frered = NULL;
    }

    return temp;
}

void freeArbre(Arbre *a) {
    if(*a != NULL) {
        freeArbre(&(*a)->filsg);
        freeArbre(&(*a)->frered);
        free(*a);
        *a = NULL;
    }
}

#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <stdlib.h>

#define MAX 50

typedef struct noeud {
    unsigned char lettre;
    struct noeud *filsg, *frered;
} Noeud, *Arbre;

#endif // ARBRE_H_INCLUDED

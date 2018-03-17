#ifndef ARBRE_STRUCT_H_INCLUDED
#define ARBRE_STRUCT_H_INCLUDED

#include <stdlib.h>

#define MAX 51

typedef struct noeud {
    unsigned char lettre;
    struct noeud *filsg, *frered;
} Noeud, *Arbre;

#endif /* ARBRE_STRUCT_INCLUDED */

#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <stdlib.h>
#include "arbre.struct.h"
#include "arbre.h"

Noeud *allocNoeud(unsigned char lettre);

void freeArbre(Arbre *a);

#endif /* ARBRE_H_INCLUDED */

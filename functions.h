#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int addNoeud(Arbre *a, unsigned char *mot);
void printArbre_rec(Arbre a, unsigned char *buffer, size_t indice);
void printArbre(Arbre a);

#endif /* FUNCTIONS_H_INCLUDED */

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int addNoeud(Arbre *a, const unsigned char *mot);
void printArbre_rec(Arbre a, unsigned char *buffer, size_t indice, FILE *out);
void printArbre(Arbre a, FILE *out);
int readMots(FILE *in, Arbre *a);
int searchMot(Arbre a, const unsigned char *mot);
int constructArbre(Arbre *a, FILE *in);
void saveArbre(Arbre a, FILE *out);

#endif /* FUNCTIONS_H_INCLUDED */

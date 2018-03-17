#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arbre.h"
#include "functions.h"


int addNoeud(Arbre *a, const unsigned char *mot) {
    Arbre temp = NULL;
    unsigned char c = (unsigned char)tolower(*mot);
    if(*a == NULL) {
        *a = allocNoeud(*mot);
        if(*a == NULL) return 0;
        if(c != '\0')
        return addNoeud(&(*a)->filsg, mot + 1);
    }
    if(c > (*a)->lettre) {
        return addNoeud(&(*a)->frered, mot);
    } else if(*mot == (*a)->lettre) {
        if(c != '\0')
            return addNoeud(&(*a)->filsg, mot + 1);
    } else {
        temp = *a;
        *a = allocNoeud(c);
        if(*a == NULL) return 0;
        (*a)->frered = temp;
        if(c != '\0')
            return addNoeud(&(*a)->filsg, mot + 1);
    }

    return 1;
}

int readMots(FILE *in, Arbre *a) {
    unsigned char read[MAX];
    int k = 1;
    while(fscanf(in, " %51s", read) != EOF && (k = addNoeud(a, read)));

    return k;
}

int searchMot(Arbre a, const unsigned char *mot) {
    unsigned char c = (unsigned char)tolower(*mot);
    if(a == NULL)
        return 0;
    if(c > a->lettre) {
        return searchMot(a->frered, mot);
    } else if(c == a->lettre) {
        if(c != '\0')
            return searchMot(a->filsg, mot + 1);
        else
            return 1;
    } else {
        return 0;
    }
}

void saveNoeud(Arbre a, FILE *out) {
    unsigned char c;
    if(a != NULL) {
        c = (a->lettre == '\0') ? ' ' : a->lettre;
        fprintf(out, "%c", c);
        saveNoeud(a->filsg, out);
        saveNoeud(a->frered, out);
    } else {
        fprintf(out, "\n");
    }
}

int constructArbre(Arbre *a, FILE *in) {
    char c = fgetc(in);
    switch(c) {
        case(' '):
            *a = allocNoeud('\0');
            break;
        case('\n'):
            return 1;
            break;
        case(EOF):
            return 0;
            break;
        default:
            *a = allocNoeud(c);
            break;
    }

    if(*a == NULL) return 0;
    return constructArbre(&(*a)->filsg, in) && constructArbre(&(*a)->frered, in);
}

void printArbre_rec(Arbre a, unsigned char *buffer, size_t indice, FILE *out) {
    if(a != NULL) {
        buffer[indice] = a->lettre;
        if(a->lettre != '\0')
            printArbre_rec(a->filsg, buffer, indice + 1, out);
        else
            fprintf(out, "%s\n", buffer);
        printArbre_rec(a->frered, buffer, indice, out);
    }
}

void printArbre(Arbre a, FILE *out) {
    unsigned char buffer[MAX];
    printArbre_rec(a, buffer, 0, out);
}

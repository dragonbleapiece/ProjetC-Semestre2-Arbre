#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.struct.h"
#include "functions.h"
#include "arbre.h"

void affiche_UI() {
    printf("====================\n");
    printf("======INTERFACE=====\n");
    printf("====================\n");
    printf("\n");
    printf("0 -- Ajouter Noeud\n");
    printf("1 -- Afficher Arbre\n");
    printf("2 -- Supprimer Max\n");
    printf("3 -- Supprimer Min\n");
    printf("4 -- Reset Arbre\n");
    printf("5 -- Construire Arbre a partir d'un fichier\n");
    printf("6 -- Sauvegarder Arbre\n");
    printf("7 -- Arbre Binaire de Recherche ?\n");
}

int main(int argc, char *argv[]) {

    Arbre a = NULL;
    FILE *in, *out;

    char *name = argv[1];
    char nameL[MAX], nameDICO[MAX], name2[MAX];
    sprintf(nameL, "%s.L", name);
    sprintf(nameDICO, "%s.DICO", name);
    sprintf(name2, "2%s", name);

    if(argc == 1){
        in = stdout;
        fprintf(stderr,"stdout output\n");
    }
    else if((in=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"problem opening %s\n",argv[1]);
        exit(1);
    }

    readMots(in, &a);
    if (argc > 1) fclose(in);

    if(searchMot(a, "n'est")) {
        printf("Est present !\n");
    }

    if((out = fopen(nameL, "w"))) {
        printArbre(a, out);
    } else {
        printf("Erreur ecriture de %s !\n", nameL);
    }
    if(fclose(out) != EOF) {
        printf("Success !\n");
    }

    if((out = fopen(nameDICO, "w"))) {
        saveNoeud(a, out);
    } else {
        printf("Erreur ecriture de %s !\n", nameDICO);
    }
    if(fclose(out) != EOF) {
        printf("Success !\n");
    }

    freeArbre(&a);

    if((out = fopen(nameDICO, "r"))) {
        constructArbre(&a, out);
    } else {
        printf("Erreur ecriture de %s !\n", nameDICO);
    }
    if(fclose(out) != EOF) {
        printf("Success !\n");
    }

    printArbre(a, stdout);

    freeArbre(&a);

    return EXIT_SUCCESS;
}

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
    printf("2 -- Reset Arbre\n");
    printf("3 -- Sauvegarder Arbre en .L\n");
    printf("4 -- Sauvegarder Arbre en .DICO\n");
    printf("5 -- Construire Arbre a partir du fichier .DICO\n");
    printf("6 -- Chercher un mot\n");
}

int main(int argc, char *argv[]) {

    Arbre a = NULL;
    FILE *in, *file;
    char cmd;
    unsigned char mot[MAX];

    char *name = argv[1];
    char nameL[MAX], nameDICO[MAX];
    sprintf(nameL, "%s.L", name);
    sprintf(nameDICO, "%s.DICO", name);

    if(argc == 1){
        in = stdout;
        fprintf(stderr,"stdout output\n");
        return EXIT_FAILURE;
    }
    else if((in=fopen(argv[1],"r"))==NULL){
        fprintf(stderr,"problem opening %s\n",argv[1]);
        exit(1);
    }

    readMots(in, &a);

    affiche_UI();

    while(scanf(" %c", &cmd) && cmd != 'e') {
        switch(cmd) {
            case('0'):
                if(scanf(" %51s", mot)) {
                    if(addNoeud(&a, mot)) {
                        printf("%s ajoute !\n", mot);
                    } else {
                        printf("Erreur !\n");
                    }
                } else {
                    printf("Entree invalide !");
                }
                break;
            case('1'):
                printArbre(a, stdout);
                break;
            case('2'):
                freeArbre(&a);
                break;
            case('3'):
                if((file=fopen(nameL,"w"))==NULL){
                    fprintf(stderr, "problem create %s\n", nameL);
                } else {
                    printArbre(a, file);
                    if(fclose(file) != EOF) {
                        printf("Success !\n");
                    }
                }
                break;
            case('4'):
                if((file=fopen(nameDICO,"w"))==NULL){
                    fprintf(stderr, "problem create %s\n", nameDICO);
                } else {
                    saveArbre(a, file);
                    if(fclose(file) != EOF) {
                        printf("Success !\n");
                    }
                }
                break;
            case('5'):
                if(scanf( "%51s", mot) && (strstr((char *)mot, ".DICO") != NULL)) {
                    if((file=fopen((char *)mot,"r"))==NULL){
                        fprintf(stderr, "problem opening %s\n", mot);
                    } else {
                        freeArbre(&a);
                        constructArbre(&a, file);
                        if(fclose(file) != EOF) {
                            printf("Success !\n");
                        }
                    }
                } else {
                    printf("Entree invalide !\n");
                }
                break;
            case('6'):
                if(scanf(" %51s", mot)) {
                    if(searchMot(a, mot)) {
                        printf("\"%s\" present !\n", mot);
                    } else {
                        printf("\"%s\" absent...\n", mot);
                    }
                } else {
                    printf("Entree invalide\n");
                }
                break;
            default:
                break;
        }
    }

    if(argc > 1) fclose(in);
    freeArbre(&a);

    return EXIT_SUCCESS;
}

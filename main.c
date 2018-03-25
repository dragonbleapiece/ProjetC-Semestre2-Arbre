/*CUSUMANO Nicolas SCHMID Vincent*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.struct.h"
#include "functions.h"
#include "arbre.h"

/*FONCTIONS D'INTERFACE-----------------------------------------------*/

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
    printf("6 -- Chercher un mot\n\n");
	printf("Taper 'e' pour mettre fin au programme.\n\n");
}

void Info() {
	printf("\nINFO\n");
	printf("-l nom : affiche les mots du fichier nom dans l'ordre alphabetique.\n");
	printf("-r Mot nom : signale si le Mot est present dans le fichier nom\n");
	printf("-s nom : sauvegarde dans l'ordre alphabétique les mots du fichier nom dans un fichier nom.L\n");
	printf("-S nom : sauvegarde dans le format .DICO les mots du fichier nom dans un fichier nom.DICO\n");
	
}

/*FONCTIONS UTILITAIRES-----------------------------------------------*/

void Open(const char name[], FILE **in) {
        if((*in=fopen(name,"r"))==NULL){
            fprintf(stderr,"problem opening %s\n",name);
            exit(1);
        }
}

void Save(Arbre a, const char nameDICO[]) {
    FILE *file;
    if((file=fopen(nameDICO,"w"))==NULL){
        fprintf(stderr, "problem create %s\n", nameDICO);
    } else {
        saveArbre(a, file);
        if(fclose(file) != EOF) {
            printf("Success !\n");
        }
    }
}

void Write(Arbre a, const char nameL[]) {
    FILE *file;
    if((file=fopen(nameL,"w"))==NULL){
        fprintf(stderr, "problem create %s\n", nameL);
    } else {
        printArbre(a, file);
        if(fclose(file) != EOF) {
            printf("Success !\n");
        }
    }
}

void Search(Arbre a, const char mot[]) {
    if(searchMot(a, (unsigned char *)mot)) {
        printf("\"%s\" present !\n", mot);
    } else {
        printf("\"%s\" absent...\n", mot);
    }
}

void Add(Arbre *a, const unsigned char mot[]) {
    if(addNoeud(a, mot)) {
        printf("%s ajoute !\n", mot);
    } else {
        printf("Erreur !\n");
    }
}

void Construct(Arbre *a, const char name[]) {
    FILE *file;
    if((file=fopen(name,"r"))==NULL){
        fprintf(stderr, "problem opening %s\n", name);
    } else {
        freeArbre(a);
        constructArbre(a, file);
        if(fclose(file) != EOF) {
            printf("Success !\n");
        }
    }
}

/*MAIN---------------------------------------------------------*/

int main(int argc, char *argv[]) {

    Arbre a = NULL;
    FILE *in;
    char cmd;
    char mot[MAX];
    char nameL[MAX], nameDICO[MAX];
    char *name;

    if(argc == 1){
        Info();
        return EXIT_FAILURE;
    }

    else if(argc == 2) {

        name = argv[1];
        Open(name, &in);

        sprintf(nameL, "%s.L", name);
        sprintf(nameDICO, "%s.DICO", name);

        readMots(in, &a);

        affiche_UI();

        while(scanf(" %c", &cmd) && cmd != 'e') {
            switch(cmd) {
                case('0'):
                    if(scanf(" %51s", mot)) {
                        Add(&a, (unsigned char *)mot);
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
                    Write(a, nameL);
                    break;
                case('4'):
                    Save(a, nameDICO);
                    break;
                case('5'):
                    if(scanf( " %51s", mot) && (strstr(mot, ".DICO") != NULL)) {
                        Construct(&a, mot);
                    } else {
                        printf("Entree invalide !\n");
                    }
                    break;
                case('6'):
                    if(scanf(" %51s", mot)) {
                        Search(a, mot);
                    } else {
                        printf("Entree invalide\n");
                    }
                    break;
                default:
                    break;
            }
        }
    }

    else if(argc == 3) {

        name = argv[2];
        Open(name, &in);
        sprintf(nameL, "%s.L", name);
        sprintf(nameDICO, "%s.DICO", name);

        readMots(in, &a);

        if(strcmp(argv[1], "-l") == 0) {
            printArbre(a, stdout);

        } else if(strcmp(argv[1], "-s") == 0) {

            Write(a, nameL);

        } else if(strcmp(argv[1], "-S") == 0) {

            Save(a, nameDICO);

        }
    }

    else if(argc == 4 && strcmp(argv[1], "-r") == 0) {
        Open(argv[3], &in);

        readMots(in, &a);

         if(strlen(argv[2]) < MAX) {
           Search(a, argv[2]);
        } else {
            printf("Entree invalide\n");
        }

    }

    fclose(in);
    freeArbre(&a);

    return EXIT_SUCCESS;
}

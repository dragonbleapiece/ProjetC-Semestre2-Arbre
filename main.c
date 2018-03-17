#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.struct.h"
#include "functions.h"
#include "arbre.h"

int main(int argc, char *argv[]) {

    Arbre a = NULL;
    FILE *in;

    if(argc == 1){
        in = stdout;
        fprintf(stderr,"stdout output\n");
    }
    else if((in=fopen(argv[1],"rw"))==NULL){
        fprintf(stderr,"problem opening %s\n",argv[1]);
        exit(1);
    }

    readMots(in, &a);

    if(searchMot(a, "n'est")) {
        printf("Est present !\n");
    }

    printArbre(a);

    if (argc > 1) fclose(in);
    freeArbre(&a);

    return EXIT_SUCCESS;
}

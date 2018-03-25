#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>

/*Ajoute les noeuds qui composent le mot à l'arbre dans l'ordre alphabétique. Renvoie 0 si erreur d'allocation, 1 sinon.
	/ *a : Arbre dans lequel on ajoute le mot
	/ *mot : mot à ajouter
*/
int addNoeud(Arbre *a, const unsigned char *mot);

/*Ecrit les mots qui composent l'arbre dans l'ordre alphabétique dans un fichier.
	//a : Arbre dont on affiche les mots
	/ *buffer : mot tampon
	//indice : indice dans le mot
	/ *out : fichier dans lequel on écrit
*/
void printArbre_rec(Arbre a, unsigned char *buffer, size_t indice, FILE *out);

/*Ecrit les mots qui composent l'arbre dans l'ordre alphabétique dans un fichier en initialisant le mot tampon et l'indice.
	//a : Arbre dont on affiche les mots
	/ *out : fichier dans lequel on écrit
*/
void printArbre(Arbre a, FILE *out);

/*Hache les mots du fichier et les ajoute alphabétiquement dans l'Arbre. Renvoie 0 si erreur d'allocation, 1 sinon.
	/ *in : fichier lu
	/ *a : Arbre dans lequel on ajoute les mots
*/
int readMots(FILE *in, Arbre *a);

/*Cherche un mot dans un Arbre. Renvoie 0 si le mot est absent, 1 sinon.
	/ *mot : mot recherché
	//a : arbre dans lequel on le cherche
*/
int searchMot(Arbre a, const unsigned char *mot);

/*Construit un arbre à partir d'un fichier de sauvegarde. Renvoie 0 si erreur d'allocation, 1 sinon.
	/ *a : Arbre dans lequel on construit.
	/ *in : fichier lu
*/
int constructArbre(Arbre *a, FILE *in);

/*Sauvegarde dans un fichier les mots de l'arbre suivant la procédure de sauvegarde .DICO.
	//a : Arbre à sauvegarder
	/ *out : fichier en écriture
*/
void saveArbre(Arbre a, FILE *out);

#endif /* FUNCTIONS_H_INCLUDED */

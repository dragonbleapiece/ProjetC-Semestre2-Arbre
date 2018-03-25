#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "arbre.struct.h"
#include "arbre.h"

/*Alloue un Noeud. Renvoie l'adresse d'allocation.
	//lettre : lettre que contient le noeud
*/
Noeud *allocNoeud(unsigned char lettre);

/*Libère l'Arbre. Lui affecte NULL à la fin.
	/ *a : Arbre à libérer
*/
void freeArbre(Arbre *a);

#endif /* ARBRE_H_INCLUDED */

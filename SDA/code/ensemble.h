#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

typedef struct Chaine{
	char val[3];
	struct Chaine* representant;
	struct Chaine* suivant;
}Chaine;

typedef struct Liste{
	struct Chaine* head;
	struct Chaine* tail;
}Liste;

Liste listeNouv();

bool estVide(Liste e);

Liste insertion(int valeur1, Liste e);

void detruire(Liste e);

/*  --------------------------------------Arbre--------------------------------------------------*/

typedef struct Noeud {
	int hauteur;
	int pixel[3];
	struct Noeud* pere;
}Noeud;

typedef struct Noeud* Arbre;

Arbre arbrbeNouv();

#endif

#ifndef __ENSEMBLE_H
#define __ENSEMBLE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h> 
#include "fichier.h"

typedef struct Chaine{
	int val[3];
	struct Chaine* representant;
	struct Chaine* suivant;
}Chaine;

typedef struct Liste{
	struct Chaine* head;
	struct Chaine* tail;
}Liste;

typedef struct Liste** TB;

Liste listeNouv();

bool estVide(Liste e);

Liste insertion(int valeur1, Liste e);

void detruire(Liste e);

Liste MakeSet(int valeur);

TB creerTB(PBM p);

/*  --------------------------------------Arbre--------------------------------------------------*/

typedef struct Noeud {
	int hauteur;
	int pixel[3];
	struct Noeud* pere;
}Noeud;

typedef struct Noeud* Arbre;

Arbre arbrbeNouv();

#endif

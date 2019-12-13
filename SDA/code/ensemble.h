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

Liste MakeSet(int valeur);

TB creerTB(PBM p);

Chaine* findSet(int i, int j, TB t);

void detruireTB(TB t, PBM p);

void Union(TB t, PBM p,Liste l1, Liste l2, int i, int j, int x, int y);
	
void reuniformiser(TB t,PBM p,Liste l2,int i,int j);

void uniformiser(TB t, PBM p, Liste l2, int i, int j);

/*  --------------------------------------Arbre--------------------------------------------------*/

typedef struct Noeud {
	int hauteur;
	int pixel[3];
	struct Noeud* pere;
}Noeud;

typedef struct Noeud* Arbre;

Arbre arbrbeNouv();

#endif

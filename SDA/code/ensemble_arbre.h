#ifndef __ENSEMBLE_ARBRE_H
#define __ENSEMBLE_ARBRE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h> 
#include <string.h>
#include "fichier.h"

typedef struct Noeud {
	int hauteur;
	int pixel[3];
	//int nb;
	struct Noeud* pere;
}Noeud;


typedef struct Arbre {
	struct Noeud* chaine;
}Arbre;

typedef struct Arbre** TB;

int max_2(int a, int b);

int Hauteur_Arbre(Arbre a);

Arbre arbreNouv();

bool estVide(Arbre a);

Arbre Insertion_Hauteur(Arbre a);

void Affiche_Hauteur(Arbre a);

Arbre Insertion_A(Arbre a, int pixel);

void detruire(Arbre a);

TB creerTB(PBM p);

void detruireTB(TB t, PBM p);

Arbre MakeSet(int pixel);

Noeud* findSet(Arbre a);

void Union(Arbre a1, Arbre a2);

#endif

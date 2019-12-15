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

/**
 * \brief Initialiser la liste.
 * \param
 * \return Une liste vide.
 */
Liste listeNouv();

/**
 * \brief Test de vacuite de la liste.
 * \param e une liste initialisée
 * \return true -> liste est vide / false -> liste non vide.
 */
bool estVide(Liste e);

/**
 * \brief Initialise une chaine et l'insere dans une liste vide
 * \param valeur1 valeur 0 ou 1
 * \param e liste vide
 * | fct utilisé = estVide()
 * \return Une liste avec 1 élément initialisé.
 */
Liste insertion(int valeur1, Liste e);

/**
 * \brief Initialise un ensemble 
 * \param valeur valeur 0 ou 1
 * | fct utilisé = listeNouv() / insertion()
 * \return Une liste représentant un pixel.
 */
Liste MakeSet(int valeur);

/**
 * \brief Creer un tableau bidimentionnel de pixel (TB)
 * \param valeur une structure PBM
 * | fct utilisé = Makeset()
 * \return Une TB representant l'image complete.
 */
TB creerTB(PBM p);

/**
 * \brief cherche le representant d'un ensemble
 * \param i indice de la TB 
 * \param j indice de la TB 
 * \param t tableau bidimentionnel de liste 
 * \return un pointeur vers le représentant
 */
Chaine* findSet(int i, int j, TB t);

/**
 * \brief free la structure TB 
 * \param t structure à free
 * \param p structure PBM pour connaitre la dimensiondu tableau
 * \return 
 */
void detruireTB(TB t, PBM p);

/**
 * \brief fusionne deux liste et uniformise les pointeurs de toutes les listes
 * \param t Tableau TB
 * \param p PBM p pour la dimension
 * \param l1 Liste 
 * \param l2 Liste  a fusionner avec l1
 * \param i indice de la TB  de la liste l2
 * \param j indice de la TB  de la liste l2
 * \param x indice de la TB  de la liste l1
 * \param y indice de la TB  de la liste l1
 * | fct utilisé = reuniformiser() / uniformiser()
 * \return 
 */
void Union(TB t, PBM p,Liste l1, Liste l2, int i, int j, int x, int y);

/**
 * \brief redirige la queue des listes fusionnées vers la nouvelle queue
 * \param t Tableau TB
 * \param p PBM p pour la dimension
 * \param l2 Liste a fusionner avec l1
 * \param i indice de la TB  de la liste l2
 * \param j indice de la TB  de la liste l2
 * \return 
 */
void reuniformiser(TB t,PBM p,Liste l2,int i,int j);

/**
 * \brief redirige la tete des listes fusionnées vers la nouvelle tete
 * \param t Tableau TB
 * \param p PBM  pour la dimension
 * \param l2 Liste a fusionner avec l1
 * \param i indice de la TB  de la liste l2
 * \param j indice de la TB  de la liste l2
 * \return 
 */
void uniformiser(TB t, PBM p, Liste l2, int i, int j);

/**
 * \brief test la couleur du pixel
 * \param l la liste représentant le pixel à tester
 * \return true -> pixel noir / false -> pixel blanc
 */
bool estNoir(Liste l);

/**
 * \brief parcours le tableau pour unifier les voisins blancs
 * \param t structure TB représentant l'image
 * \param p structure PBM  pour les dimensions
 * \return TB dont les pixels blancs voisin ont été unifié
 */
TB voisin(TB t, PBM p);

/**
 * \brief Convertis la TB en une structure PPM
 * \param t structure TB représentant l'image
 * \param p structure PBM  pour les dimensions
 * \return structure PPM représentant l'image coloriée
 */
PPM creerPPM(TB t, PBM p);

#endif

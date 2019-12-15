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
 * \param[in] 
 * \return Une liste vide.
 */
Liste listeNouv();

/**
 * \brief Test de vacuite de la liste.
 * \param[in] une liste initialisée
 * \return true -> liste est vide / false -> liste non vide.
 */
bool estVide(Liste e);

/**
 * \brief Initialise une chaine et l'insere dans une liste vide
 * \param[in] valeur 0 ou 1
 * \param[in] liste vide
 * | fct utilisé = estVide()
 * \return Une liste avec 1 élément initialisé.
 */
Liste insertion(int valeur1, Liste e);

/**
 * \brief Initialise un ensemble 
 * \param[in] valeur 0 ou 1
 * \param[in] liste vide
 * | fct utilisé = listeNouv() / insertion()
 * \return Une liste représentant un pixel.
 */
Liste MakeSet(int valeur);

/**
 * \brief Creer un tableau bidimentionnel de pixel (TB)
 * \param[in] une structure PBM
 * | fct utilisé = Makeset()
 * \return Une TB representant l'image complete.
 */
TB creerTB(PBM p);

/**
 * \brief cherche le representant d'un ensemble
 * \param[in] indice de la TB i
 * \param[in] indice de la TB j
 * \param[in] tableau bidimentionnel de liste t
 * \return un pointeur vers le représentant
 */
Chaine* findSet(int i, int j, TB t);

/**
 * \brief free la structure TB 
 * \param[in] structure à free
 * \param[in] structure PBM pour connaitre la dimensiondu tableau
 * \return 
 */
void detruireTB(TB t, PBM p);

/**
 * \brief fusionne deux liste et uniformise les pointeurs de toutes les listes
 * \param[in] Tableau TB
 * \param[in] PBM p pour la dimension
 * \param[in] Liste l1
 * \param[in] Liste l2 a fusionner avec l1
 * \param[in] indice de la TB i de la liste l2
 * \param[in] indice de la TB j de la liste l2
 * \param[in] indice de la TB x de la liste l1
 * \param[in] indice de la TB y de la liste l1
 * | fct utilisé = reuniformiser() / uniformiser()
 * \return 
 */
void Union(TB t, PBM p,Liste l1, Liste l2, int i, int j, int x, int y);

/**
 * \brief redirige la queue des listes fusionnées vers la nouvelle queue
 * \param[in] Tableau TB
 * \param[in] PBM p pour la dimension
 * \param[in] Liste l2 a fusionner avec l1
 * \param[in] indice de la TB i de la liste l2
 * \param[in] indice de la TB j de la liste l2
 * \return 
 */
void reuniformiser(TB t,PBM p,Liste l2,int i,int j);

/**
 * \brief redirige la tete des listes fusionnées vers la nouvelle tete
 * \param[in] Tableau TB
 * \param[in] PBM p pour la dimension
 * \param[in] Liste l2 a fusionner avec l1
 * \param[in] indice de la TB i de la liste l2
 * \param[in] indice de la TB j de la liste l2
 * \return 
 */
void uniformiser(TB t, PBM p, Liste l2, int i, int j);


#endif

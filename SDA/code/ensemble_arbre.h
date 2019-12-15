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

/**
 * \brief Maximum entre 2 int
 * \param[in] int à comparer
 * \return Maximum entre les 2 int
 */
int max_2(int a, int b);

/**
 * \brief Récupérer la hauteur d'un arbre
 * \param[in] Arbre dont on veut connaitre la hauteur
 * \return hauteur de l'abre
 */
int Hauteur_Arbre(Arbre a);

/**
 * \brief Initialiser un arbre.
 * \param[in] 
 * \return Un arbre vide.
 */
Arbre arbreNouv();

/**
 * \brief Test de vacuite de l'arbre.
 * \param[in] un arbre initialisé
 * \return true -> arbre est vide / false -> arbre non vide.
 */
bool estVide(Arbre a);

/**
 * \brief Inserer la hauteur d'une arbre
 * \param[in] un arbre initialisé
 * \return un arbre avec sa hauteur regularisé
 */
Arbre Insertion_Hauteur(Arbre a);

/**
 * \brief Affiche la hauteur à l'ecran (pour les tests).
 * \param[in] un arbre initialisé
 * \return 
 */
void Affiche_Hauteur(Arbre a);

/**
 * \brief Initialise un noeud et l'insere dans un arbre vide
 * \param[in] valeur 0 ou 1
 * \param[in] arbre vide
 * | fct utilisé = estVide()
 * \return Un Arbre avec 1 élément initialisé.
 */
Arbre Insertion_A(Arbre a, int pixel);

/**
 * \brief Creer un tableau bidimentionnel de pixel (TB)
 * \param[in] une structure PBM
 * | fct utilisé = Makeset() 
 * \return Une TB representant l'image complete.
 */
TB creerTB(PBM p);

/**
 * \brief free la structure TB 
 * \param[in] structure à free
 * \param[in] structure PBM pour connaitre la dimensiondu tableau
 * \return 
 */
void detruireTB(TB t, PBM p);

/**
 * \brief Initialise un ensemble 
 * \param[in] valeur 0 ou 1
 * | fct utilisé = arbreNouv() / insertion_A()
 * \return Un arbre représentant un pixel.
 */
Arbre MakeSet(int pixel);

/**
 * \brief cherche le representant d'un ensemble
 * \param[in] arbre dont on veut le représentant
 * \return un pointeur vers le représentant
 */
Noeud* findSet(Arbre a);

/**
 * \brief test la couleur du pixel
 * \param[in] l'arbre représentant le pixel à tester
 * \return true -> pixel noir / false -> pixel blanc
 */
bool estNoir(Arbre a);

/**
 * \brief fusionne deux liste et uniformise les pointeurs 
 * \param[in] Arbre a1
 * \param[in] Arbre a2 a fusionner avec a1
 * | fct utilisé = reuniformiser() / uniformiser()
 * \return 
 */
void Union(Arbre a1, Arbre a2);

/**
 * \brief parcours le tableau pour unifier les voisins blancs
 * \param[in] structure TB représentant l'image
 * \param[in] structure PBM p pour les dimensions
 * \return TB dont les pixels blancs voisin ont été unifié
 */
TB voisin(TB t, PBM p);

/**
 * \brief colorier tous les noeud de l'arbre avec lacouleur du représentant
 * \param[in] structure TB représentant l'image
 * \param[in] structure PBM p pour les dimensions
 * \return TB entierement colorié
 */
TB uniformiserColori(TB t, PBM p);

/**
 * \brief Convertis la TB en une structure PPM
 * \param[in] structure TB représentant l'image
 * \param[in] structure PBM p pour les dimensions
 * \return structure PPM représentant l'image coloriée
 */
PPM creerPPM(TB t, PBM p);

#endif

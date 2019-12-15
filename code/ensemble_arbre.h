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
 * \brief Initialiser un arbre.
 * \param[in] 
 * \return Un arbre vide.
 */
Arbre arbreNouv();

/**
 * \brief Test de vacuite de l'arbre.
 * \param a un arbre initialisé
 * \return true -> arbre est vide / false -> arbre non vide.
 */
bool estVide(Arbre a);

/**
 * \brief Inserer la hauteur d'une arbre
 * \param a un arbre initialisé
 * \return un arbre avec sa hauteur regularisé
 */
Arbre Insertion_Hauteur(Arbre a);

/**
 * \brief Affiche la hauteur à l'ecran (pour les tests).
 * \param a un arbre initialisé
 * \return 
 */
void Affiche_Hauteur(Arbre a);

/**
 * \brief Initialise un noeud et l'insere dans un arbre vide
 * \param pixel valeur 0 ou 1
 * \param a arbre vide
 * | fct utilisé = estVide()
 * \return Un Arbre avec 1 élément initialisé.
 */
Arbre Insertion_A(Arbre a, int pixel);

/**
 * \brief Creer un tableau bidimentionnel de pixel (TB)
 * \param p une structure PBM
 * | fct utilisé = Makeset() 
 * \return Une TB representant l'image complete.
 */
TB creerTB(PBM p);

/**
 * \brief free la structure TB 
 * \param t structure à free
 * \param p structure PBM pour connaitre la dimensiondu tableau
 * \return 
 */
void detruireTB(TB t, PBM p);

/**
 * \brief Initialise un ensemble 
 * \param pixel valeur 0 ou 1
 * | fct utilisé = arbreNouv() / insertion_A()
 * \return Un arbre représentant un pixel.
 */
Arbre MakeSet(int pixel);

/**
 * \brief cherche le representant d'un ensemble
 * \param a arbre dont on veut le représentant
 * \return un pointeur vers le représentant
 */
Noeud* findSet(Arbre a);

/**
 * \brief test la couleur du pixel
 * \param a l'arbre représentant le pixel à tester
 * \return true -> pixel noir / false -> pixel blanc
 */
bool estNoir(Arbre a);

/**
 * \brief fusionne deux liste et uniformise les pointeurs 
 * \param a1 Arbre a1
 * \param a2 Arbre a2 a fusionner avec a1
 * | fct utilisé = reuniformiser() / uniformiser()
 * \return 
 */
void Union(Arbre a1, Arbre a2);

/**
 * \brief parcours le tableau pour unifier les voisins blancs
 * \param t structure TB représentant l'image
 * \param p structure PBM p pour les dimensions
 * \return TB dont les pixels blancs voisin ont été unifié
 */
TB voisin(TB t, PBM p);

/**
 * \brief colorier tous les noeud de l'arbre avec lacouleur du représentant
 * \param t structure TB représentant l'image
 * \param p structure PBM p pour les dimensions
 * \return TB entierement colorié
 */
TB uniformiserColori(TB t, PBM p);

/**
 * \brief Convertis la TB en une structure PPM
 * \param t structure TB représentant l'image
 * \param p structure PBM p pour les dimensions
 * \return structure PPM représentant l'image coloriée
 */
PPM creerPPM(TB t, PBM p);

#endif

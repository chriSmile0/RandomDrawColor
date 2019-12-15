#ifndef __FICHIER_H
#define __FICHIER_H
 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int** Tab;

typedef struct { 
	char * nbMage;
	int nbl;
	int nbh;
	Tab tableau;
}PBM;

typedef struct {
	char *nbMage;
	int nbl;
	int nbh;
	int max;
	Tab tableau;
}PPM;

/**
 * \brief Lis une image au format PBM et la stocke dans une structure
 * \param filename nom de l'image à lire
 * | fct utilisé = ouverture fermeture de fichier standard
 * \return Une struure PBM contenant l'image 
 */
PBM Read(char * filename);

 /**
 * \brief Libere l'espace utilisé pour une PBM
 * \param p structure PBM à free
 * \return none
 */
void freetab(PBM p);

/**
 * \brief Libere l'espace utilisé pour une PPM
 * \param p structure PBM à free
 * \return none
 */
void freeTab(PPM p);

/**
 * \brief Ecrire une image en couleur 
 * \param p structure PPM à convertir en image 
 * \return none
 */
void Write(PPM p);


/**
 * \brief Genere une image PBM aléatoire
 * \param n largeur n de l'image à générer
 * \param m longueur m de l'image à générer
 * \return
 */
void Generate(int n,int m);


#endif

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h> 



typedef struct Noeud {
	int hauteur;
	int pixel[3];
    int rang;
	struct Noeud* pere;
}Noeud;

typedef struct Noeud* Arbre;

int max_2(int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}

int Hauteur_Arbre(Arbre a)
{
    if (a == NULL) 
        return -1;

    return 1 + Hauteur_Arbre(a->pere);
}



Arbre arbreNouv()
{
	Arbre a = NULL;
	return a;
}

bool estVide(Arbre a){
	if (a == NULL) 
		return true; 
	else 
		return false;
}

/*On fait d'abord un arbre en l'endroit puis on le fera a l'envers*/

Arbre Insertion_A(Arbre a, int pixel)
{
    Noeud * nouv_node = malloc(sizeof(Noeud));
    
    if (pixel == 1) {
        nouv_node->pixel[0] = 0;
        nouv_node->pixel[1] = 0;
        nouv_node->pixel[2] = 0;
    }

    if (pixel == 0) {
        nouv_node->pixel[0] = rand() % 255;
		nouv_node->pixel[1] = rand() % 255;
		nouv_node->pixel[2] = rand() % 255;
    }
    /*
    if (estVide(a) ){
        nouv_node->pere = nouv_node;
        nouv_node->hauteur = 0;
    }
    else {
        nouv_node->pere = a;
        nouv_node->hauteur = 0;
    }

    a->hauteur = Hauteur_Arbre(a);
    return a;*/

    if(estVide(a)){
        nouv_node->pere = nouv_node;
        nouv_node->hauteur = 0;
        nouv_node->rang = 0;
        a = nouv_node;
    }
    else {
       nouv_node->pere = a;
       nouv_node->rang = a->rang +1;
       a = nouv_node;
    }
    
    
    //a->hauteur = Hauteur_Arbre(a);
    return a;
}

Arbre MakeSet(int pixel){
	Arbre e = arbreNouv();
	
	e = Insertion_A(e,pixel);
	return e;
}

/*void AfficheArbre(Arbre A){
    Arbre copie_a = A;
    //while(copie_a->pere->rang!=0)
}*/




int main(){
    Arbre ab = arbreNouv();
    printf("%d\n",ab);
    printf("%d\n",Hauteur_Arbre(ab));
    //ab = Insertion_A(ab,1);
    printf("est vide ? %d\n",estVide(ab));//Vrai il est vide il renvoie bien 1 
    ab = Insertion_A(ab,0);
    printf("est vide ? %d\n",estVide(ab));//Renvoie bien 0 donc il n'est pas vide 
    printf("pixel 3 de 1 : %d \n",ab->pixel[2]);
    ab = Insertion_A(ab,1);
    printf("est vide ? %d\n",estVide(ab));//Rnevoie bien 0 
    printf("pixel 3 de 0 : %d\n",ab->pixel[2]);
    ab = Insertion_A(ab,0);
    printf("est vide ? %d\n",estVide(ab));
    printf("pixel 1 de 1 : %d\n",ab->pixel[0]);
    printf("pixel pere de l'element precedent : %d\n",ab->pere->pixel[0]);//On obtient bien 0
    printf("pixel du grand pere de l'element 1 de 1 de la ligne 124 du code : %d\n",ab->pere->pere->pixel[2]);//J'ai bien 162 
    //printf("%d\n",ab->hauteur);
    return 0;
}
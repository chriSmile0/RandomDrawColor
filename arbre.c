#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h> 
#include <string.h>


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



typedef struct Noeud {
	int hauteur;
	int pixel[3];
    int rang;
	struct Noeud* pere;
}Noeud;

typedef struct Noeud* Arbre;
typedef struct Arbre** TB;

int max_2(int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}

int Hauteur_Arbre(Arbre a)//La fonction Hauteur et correct aussi 
{
    int hauteur = -1;
    if (a == NULL) 
        return hauteur;

    Arbre copie_a = a;
    while(copie_a->pere!=copie_a){
        hauteur+= 1;
        copie_a = copie_a->pere;
    }
    hauteur++;
    return hauteur;
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



Arbre Insertion_Hauteur(Arbre a){//On va inserer les hauteurs dans l'arbre
    Noeud *ptr_a = a;
    int hauteur = 0;
    while(a->pere!=a){
        a = a->pere;
        hauteur +=1;
        a->hauteur = hauteur;  
    }
      
    return ptr_a;
}

void Affiche_Hauteur(Arbre a){
    Arbre copie_a = a;

    if(copie_a!=NULL){
        while(copie_a->pere!=copie_a){
            printf("hauteur de copie_a dans affiche hauteur : %d\n",copie_a->hauteur);
            copie_a = copie_a->pere;
        }
        if(copie_a->pere==copie_a){
            printf("hauteur de copie_a dans affiche hauteur : %d\n",copie_a->hauteur);
        }
    }
}




/*On fait d'abord un arbre en l'endroit puis on le fera a l'envers*/

Arbre Insertion_A(Arbre a, int pixel)//FOnctionne il faut juste ajouter la hauteur 
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
   
    if(estVide(a)){
        nouv_node->pere = nouv_node;
        nouv_node->rang = 0;
        nouv_node->hauteur = 0;
        a = nouv_node;
        return a;
    }
    else {
       nouv_node->pere = a;
       nouv_node->rang = a->rang +1;
       nouv_node = Insertion_Hauteur(nouv_node);
       a = nouv_node;
       
    }
    //Mon insertion et juste et fonctionne, il faut juste ajouter la hauteur
    return a;
}


void detruire(Arbre a){
	
	Noeud* tmp = a;
	Noeud* tmp1;
	while (tmp->pere != tmp){
		tmp1 = tmp->pere;
		free(tmp);
		tmp = tmp1;
	}

}


TB creerTB(PBM p){
	
	TB t = malloc(sizeof(Arbre*) * p.nbh);
	for(int i=0; i<p.nbh; i++)
		t[i] = malloc(sizeof(Arbre) * p.nbl);
	
	srand(time(NULL));
	
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			//printf("%d",p.tableau[i][j]);
			t[i][j] = MakeSet(p.tableau[i][j]);
		}
	}
	return t;
}

void detruireTB(TB t, PBM p){
	
	/*
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			detruire(t[i][j]);
		}
	}*/
	
	for(int i=0; i<p.nbh; i++){
		free(t[i]);
	}
	free(t);
	
}

Arbre MakeSet(int pixel)
{
	Arbre e = arbreNouv();
	
	e = Insertion_A(e,pixel);
	return e;
}

Noeud  findSet(int i, int j, TB t) {
    while (t[i][j]->pere != t[i][j] )
        t[i][j] = t[i][j]->pere;
    return t[i][j];
	
}

/*void AfficheArbre(Arbre A)
{
    Arbre copie_a = A;
    if (copie_a != NULL) {
        while (copie_a->pere != copie_a) {
            printf("%d\n",copie_a->pixel[0]);
            printf("%d\n",copie_a->pixel[1]);
            printf("%d\n",copie_a->pixel[2]);
            printf("Hauteur du noeud : %d\n",copie_a->hauteur);
            printf("Rang du noeud : %d\n",copie_a->rang);
            //printf("Hauteur de l'arbre : %d\n",Hauteur_Arbre(copie_a));
            copie_a = copie_a->pere;
        }
        if (copie_a->pere == copie_a){
            printf("Racine de l'arbre : \n");
            printf("%d\n",copie_a->pixel[0]);
            printf("%d\n",copie_a->pixel[1]);
            printf("%d\n",copie_a->pixel[2]);
            printf("Hauteur du noeud : %d\n",copie_a->hauteur);
            printf("Rang du noeud : %d\n",copie_a->rang);
            //printf("Hauteur de l'arbre : %d\n",Hauteur_Arbre(copie_a));
        }
    }
}*/




int main(){
    Arbre ab = MakeSet(0);
    Affiche_Hauteur(ab);

    Arbre ac = MakeSet(0);
    Affiche_Hauteur(ac);


    /*Arbre ab = arbreNouv();
    ab = Insertion_A(ab,0);
    printf("Insertion de la racine : ----\n");
    Affiche_Hauteur(ab);*/
    //printf("Valeur de ab : %d\n",ab->pixel[0]);
    /*printf("Hauteur de ab : %d\n",ab->hauteur);
    printf("Hauteur du pere de ab : %d\n",ab->hauteur);
    printf("valeur de ab : %d\n",ab->pixel[0]);*/
   //ab = Insertion_A(ab,0);
     //printf("Valeur de ab : %d\n",ab->pixel[0]);
    /*printf("Hauteur de ab : %d\n",ab->hauteur);
    printf("Hauteur du pere de ab : %d\n",ab->pere->hauteur);
    printf("valeur de ab : %d\n",ab->pixel[0]);*/
    //ab = Insertion_A(ab,0);
   /* printf("Hauteur avant increment : %d\n",ab->hauteur);
    printf("valeur : %d\n",ab->pixel[0]);
    //ab = Increment_A(ab);
    printf("hauteur de a: %d\n",ab->hauteur);
    printf("valeur : %d\n",ab->pixel[0]);*/
    /*printf("Hauteur de ab : %d\n",ab->hauteur);
    printf("Hauteur du pere de ab : %d\n",ab->pere->hauteur);
    printf("Hauteur du grand pere de ab : %d\n",ab->pere->hauteur);
    printf("valeur de ab : %d\n",ab->pixel[0]);
    printf("Hauteur de ab avec la fonction : %d\n",Hauteur_Arbre(ab));
    //AfficheArbre(ab);


    //ab = Increment_A(ab);
    printf("::%d\n",ab->pere->pixel[0]);
    ab = Increment_A(ab);
    printf("::%d\n",ab->pere->pixel[0]);*/

    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de la valeur suivant : %d\n",ab->pere->hauteur);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);

    ab = Insertion_A(ab,0);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);

    ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);

     ab = Insertion_A(ab,0);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);

    ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);

     ab = Insertion_A(ab,0);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("Hauteur de cette valeur : %d\n ",ab->hauteur);*/

    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("valeur pere du ptr : %d\n",ab->pere->pixel[0]);
    printf("Hauteur de cette valeur : %d\n",ab->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n",ab->pere->pere->hauteur);*/

    /*ab = Insertion_A(ab,0);
    printf("Insertion du premier fils : ----------\n");
    Affiche_Hauteur(ab);*/
    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("valeur pere du ptr : %d\n",ab->pere->pixel[0]);
    printf("Hauteur de cette valeur : %d\n",ab->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n",ab->pere->pere->pere->hauteur);*/

    /*ab = Insertion_A(ab,0);
    printf("Insertion du second fils : ---------\n");
    Affiche_Hauteur(ab);
    */
    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("valeur pere du ptr : %d\n",ab->pere->pixel[0]);
    printf("Hauteur de cette valeur : %d\n",ab->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n ",ab->pere->pere->pere->hauteur);*/

    /*ab = Insertion_A(ab,0);
    printf("Insertion du 3eme fils : ---------\n");
     Affiche_Hauteur(ab);*/
    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("valeur pere du ptr : %d\n",ab->pere->pixel[0]);
    printf("Hauteur de cette valeur : %d\n",ab->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n ",ab->pere->pere->pere->hauteur);*/

    /*ab = Insertion_A(ab,0);
    printf("Insertion du 4eme fils\n ");
    Affiche_Hauteur(ab);// Et senser nous afficher une hauteur de la racine de 5*/
    /*ab = Insertion_Hauteur(ab);
    printf("valeur du ptr : %d\n",ab->pixel[0]);
    printf("valeur pere du ptr : %d\n",ab->pere->pixel[0]);
    printf("Hauteur de cette valeur : %d\n",ab->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n ",ab->pere->pere->hauteur);
    printf("Hauteur du pere de cette valeur : %d\n ",ab->pere->pere->pere->hauteur);*/



  
    
    return 0;
}
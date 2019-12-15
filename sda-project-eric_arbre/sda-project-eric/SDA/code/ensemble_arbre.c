#include "ensemble_arbre.h"

Arbre arbreNouv()
{
	Arbre a;
	a.chaine = NULL;
	return a;
}

int max_2(int a, int b)
{
    if (a >= b)
        return a;
    else return b;
}

int Hauteur_Arbre(Arbre a)//La fonction Hauteur et correct aussi 
{
    int hauteur = -1;
    if (a.chaine == NULL) 
        return hauteur;

    Arbre copie_a = a;
    while(copie_a.chaine->pere!=copie_a.chaine){
        hauteur+= 1;
        copie_a.chaine = copie_a.chaine->pere;
    }
    hauteur++;
    return hauteur;
}

bool estVide(Arbre a){
	if (a.chaine == NULL) 
		return true; 
	else 
		return false;
}



/*Arbre Insertion_Hauteur(Arbre a){//On va inserer les hauteurs dans l'arbre
    Noeud *ptr_a = a.chaine;
    int hauteur = 0;
    while(a.chaine->pere!=a.chaine){
        a.chaine = a.chaine->pere;
        hauteur +=1;
        a.chaine->hauteur = hauteur;  
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
*/



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
   
    
    nouv_node->pere = nouv_node;
    nouv_node->rang = 0;
    nouv_node->hauteur = 0;
	a.chaine = nouv_node;
    return a;
    

    //Mon insertion et juste et fonctionne, il faut juste ajouter la hauteur
}

/*
void detruire(Arbre a){
	
	Noeud* tmp = a;
	Noeud* tmp1;
	while (tmp->pere != tmp){
		tmp1 = tmp->pere;
		free(tmp);
		tmp = tmp1;
	}

}*/

Arbre MakeSet(int pixel)
{
	Arbre e = arbreNouv();
	
	e = Insertion_A(e,pixel);
	return e;
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

Noeud* findSet(int i, int j, TB t) {
    Noeud* tmp = t[i][j].chaine;
    while(tmp->pere != tmp){
		tmp = tmp->pere;
	}
	return tmp;
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



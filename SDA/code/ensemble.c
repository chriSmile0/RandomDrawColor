#include "ensemble.h"

Liste listeNouv(){
	
	Liste e;
	e.head = NULL;
	e.tail = NULL;
	return e;
}

bool estVide(Liste e){
	if (e.head == NULL) 
		return true; 
	else 
		return false;
}

Liste insertion(int valeur1,Liste e){
		
	Chaine* nouv = malloc(sizeof(Chaine));
	
	if (valeur1 == 1){
		nouv->val[0] = 0;
		nouv->val[1] = 0;
		nouv->val[2] = 0;
	}
	
	if (valeur1 == 0){
		srand(time(NULL));
		nouv->val[0] = rand() ;
		nouv->val[1] = rand() ;
		nouv->val[2] = rand() ;
	}

	nouv->suivant = NULL;
		
	if (estVide(e)){
		e.head = nouv;
		e.tail = nouv;
		nouv->representant = nouv;
	}
		
	else {
		e.tail->suivant = nouv;
		e.tail = nouv;
		nouv->representant = e.head;
	}
	
	return e;
}

void detruire(Liste e){
	
	Chaine* tmp = e.head;
	Chaine* tmp1;
	while (tmp != NULL){
		tmp1 = tmp->suivant;
		free(tmp);
		tmp = tmp1;
	}
	free(tmp1);
}

Liste MakeSet(int valeur){
	Liste e = listeNouv();
	e = insertion(valeur,e);
	return e;
}

TB creerTB(PBM p){
	
	TB t = malloc(sizeof(Liste*) * p.nbh);
	for(int i=0; i<p.nbh; i++)
		t[i] = malloc(sizeof(Liste) * p.nbl);
	
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			printf("%d",p.tableau[i][j]);
			t[i][j] = MakeSet(p.tableau[i][j]);
		}
	}
	return t;
}

/*--------------------------------------------------------Arbre--------------------------------------------------------------*/
Arbre arbrbeNouv(){
	Arbre a = NULL;
	return a;
}

/*int main(){
	
	Liste e = listeNouv();

	return 0;
} */


			

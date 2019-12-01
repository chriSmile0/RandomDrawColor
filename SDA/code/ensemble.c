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
		for (int i=0; i<2; i++) 
			nouv->val[i] = 0;
	}
	
	if (valeur1 == 0){
		srand(time(NULL));
		for (int i=0; i<2; i++) 
			nouv->val[i] = (rand() / RAND_MAX * (254));
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

/*TB creerTB(){
	
	
}*/

/*--------------------------------------------------------Arbre--------------------------------------------------------------*/
Arbre arbrbeNouv(){
	Arbre a = NULL;
	return a;
}

/*int main(){
	
	Liste e = listeNouv();

	return 0;
} */


			

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
		for (int i=0; i<2; i++) 
			nouv->val[i] = 255;
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



/*--------------------------------------------------------Arbre--------------------------------------------------------------*/
Arbre arbrbeNouv(){
	Arbre a = NULL;
	return a;
}

/*int main(){
		
	Liste e = listeNouv();
	e = insertion(1,e);
	e = insertion(2,e);
	e = insertion(3,e);
	e = insertion(4,e);
	e = insertion(5,e);
	
	Chaine* tmp = e.head;
	while(tmp != NULL){
		printf("%d\n",tmp->val);
		tmp = tmp->suivant;
	}
	
	return 0;
} */


			

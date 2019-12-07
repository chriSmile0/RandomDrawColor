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
		
		nouv->val[0] = rand() % 255;
		nouv->val[1] = rand() % 255;
		nouv->val[2] = rand() % 255;
		
		if (nouv->val[0] == 0 && nouv->val[1] == 0 && nouv->val[2] == 0){
			nouv->val[0] = rand() % 255;
			nouv->val[1] = rand() % 255;
			nouv->val[2] = rand() % 255;
		}
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
	
	srand(time(NULL));
	
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			//printf("%d",p.tableau[i][j]);
			t[i][j] = MakeSet(p.tableau[i][j]);
		}
	}
	return t;
}

Chaine* findSet(int i, int j, TB t){
	return t[i][j].head->representant;
}

void detruireTB(TB t, PBM p){
	
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			detruire(t[i][j]);
		}
	}
	
	for(int i=0; i<p.nbh; i++){
		free(t[i]);
	}
	free(t);
	
}
	
void Union(Liste l1, Liste l2){
	
	l1.tail->suivant = l2.head;
	l1.tail = l2.tail;
	
	Chaine* tmp = l2.head;
	while(tmp != NULL){
		tmp->representant = l1.head;
		tmp->val[0] = l1.head->representant->val[0];
		tmp->val[1] = l1.head->representant->val[1];
		tmp->val[2] = l1.head->representant->val[2];
		tmp = tmp->suivant;
	}
	
	l2.head = l1.head->representant;
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


			

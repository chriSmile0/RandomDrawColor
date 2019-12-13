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
		

	e.head = nouv;
	e.tail = nouv;
	nouv->representant = nouv;
	
	return e;
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
	
	/*
	for(int i=0; i<p.nbh; i++){
		for(int j=0; j<p.nbl; j++){
			Chaine* tmp = t[i][j].head;
			free(tmp);
		}
	}*/
	
	for(int i=0; i<p.nbh; i++){
		free(t[i]);
	}
	free(t);
	
}
	
void Union(TB t, PBM p,Liste l1, Liste l2, int i, int j, int x, int y){ // i j -> liste 2   x y ->liste 1
	
	l1.tail->suivant = l2.head;
	l1.tail = l2.tail;
	
	Chaine* tmp = l2.head;
	while(tmp != NULL){
		tmp->representant = l1.head->representant;
		tmp->val[0] = l1.head->representant->val[0];
		tmp->val[1] = l1.head->representant->val[1];
		tmp->val[2] = l1.head->representant->val[2];
		tmp = tmp->suivant;
	}
	reuniformiser(t,p,l2,x,y);
	uniformiser(t,p,l1,i,j);
}

void reuniformiser(TB t,PBM p,Liste l2,int i,int j){
	t[i][j].tail = l2.tail;
	if (i == 0 && j == 0){
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
	}
	
	else if (i == p.nbh-1 && j == 0){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i-1,j);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
	}
	
	else if (i == 0 && j == p.nbl-1){
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail= l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
	}
	
	else if (i == p.nbh-1 && j == p.nbl-1){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
	}
	
	else if (i > 0 && i < p.nbh-1 && j == 0){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i-1,j);
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
	}
	
	else if (i == 0 && j < p.nbl-1 && j > 0){//la
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
	}
	
	else if (i > 0 && i < p.nbh-1 && j == p.nbl-1){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i-1,j);
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
	}
	
	else if (i == p.nbh-1 && j < p.nbl-1 && j > 0){
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i-1,j);
		}
	}
	
	else {
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i-1,j);
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].tail = l2.tail;
			//reuniformiser(t,p,l2,i+1,j);
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j-1);
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].tail = l2.tail;
			//reuniformiser(t,p,l2,i,j+1);
		}
	}
	
}

void uniformiser(TB t, PBM p, Liste l1, int i, int j){
	t[i][j].head = l1.head;
	
	if (i == 0 && j == 0){
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
	}
	
	else if (i == p.nbh-1 && j == 0){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
	}
	
	else if (i == 0 && j == p.nbl-1){
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
	}
	
	else if (i == p.nbh-1 && j == p.nbl-1){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
	}
	
	else if (i > 0 && i < p.nbh-1 && j == 0){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
	}
	
	else if (i == 0 && j < p.nbl-1 && j > 0){
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
	}
	
	else if (i > 0 && i < p.nbh-1 && j == p.nbl-1){
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
	}
	
	else if (i == p.nbh-1 && j < p.nbl-1 && j > 0){
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
	}
	
	else {
		if (t[i-1][j].head->representant == t[i][j].head->representant){
			t[i-1][j].head = l1.head;
		}
		if (t[i+1][j].head->representant == t[i][j].head->representant){
			t[i+1][j].head = l1.head;
		}
		if (t[i][j-1].head->representant == t[i][j].head->representant){
			t[i][j-1].head = l1.head;
		}
		if (t[i][j+1].head->representant == t[i][j].head->representant){
			t[i][j+1].head = l1.head;
		}
	}
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


			

#include "ensemble_arbre.h"

Arbre arbreNouv()
{
	Arbre a;
	a.chaine = NULL;
	return a;
}

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

    nouv_node->pere = nouv_node;
    nouv_node->hauteur = 0;
	a.chaine = nouv_node;
    return a;
}

Arbre MakeSet(int pixel)
{
	Arbre e = arbreNouv();
	e = Insertion_A(e,pixel);
	return e;
}

TB creerTB(PBM p)
{
	TB t = malloc(sizeof(Arbre*) * p.nbh);
	for (int i = 0; i < p.nbh; i++)
		t[i] = malloc(sizeof(Arbre) * p.nbl);
	
	srand(time(NULL));
	
	for (int i = 0; i < p.nbh; i++)
		for (int j = 0; j < p.nbl; j++)
			t[i][j] = MakeSet(p.tableau[i][j]);
	return t;
}

bool estNoir(Arbre a)
{
	if (a.chaine->pixel[0] == 0)
		if (a.chaine->pixel[1] == 0)
			if (a.chaine->pixel[2] == 0)
				return true;		
	else return false;
}

void Union(Arbre a1, Arbre a2)
{ 
	Noeud* tmp = findSet(a2);
	Noeud* tmp2 = a1.chaine;
	
	tmp->pere = tmp2;
	
	if (tmp2->hauteur <= tmp->hauteur) {
		tmp2->hauteur = 1 + tmp->hauteur;
	
		Noeud* temp = tmp2->pere;
		while (temp->pere != temp){
			if (temp->hauteur <= tmp2->hauteur) {
				temp->hauteur = tmp2->hauteur +1;
				tmp2 = temp;
				temp = temp->pere;
			}
			else  temp = temp->pere;
		}
		temp->hauteur = tmp2->hauteur +1;
	}
}

Noeud* findSet(Arbre a) {
    Noeud* tmp = a.chaine;
    while(tmp->pere != tmp){
		tmp = tmp->pere;
	}
	return tmp;
}

void detruireTB(TB t, PBM p)
{
	for (int i = 0; i < p.nbh; i++)
		free(t[i]);
	free(t);
	
}

TB voisin(TB t, PBM p)
{
	int cmp = 0;
	int fin = p.nbh*p.nbl;
	for (int i = 0; i < p.nbh; i++) {
		for (int j = 0; j < p.nbl; j++) {
			printf("%d/%d\n",cmp,fin);
			cmp++;
			if (i == 0 && j == 0) {  //en haut a gauche
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j+1])) 
						if (findSet(t[i][j]) != findSet(t[i][j+1])) 
							Union(t[i][j], t[i][j+1]); 
					
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j])) 
							Union(t[i][j], t[i+1][j]); 	
				}
			}
			else if (i == p.nbh-1 && j == 0) {  //en bas a gauche
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]); 
					
					if (!estNoir(t[i][j+1]))
						if (findSet(t[i][j]) != findSet(t[i][j+1]))  
							Union(t[i][j], t[i][j+1]);	
				}
			}
			else if (i == 0 && j == p.nbl-1) { //en haut a droite
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]);  
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j]))  
							Union(t[i][j], t[i+1][j]); 
				}
			}
			
			else if (i == p.nbh-1 && j == p.nbl-1) {  //en bas a droite
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]); 
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]);  
				}
			}
			else if (i > 0 && i < p.nbh-1 && j == 0) { //colonne gauche 
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j+1]))
						if (findSet(t[i][j]) != findSet(t[i][j+1]))  
							Union(t[i][j], t[i][j+1]);  
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j]))  
							Union(t[i][j], t[i+1][j]); 
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]);  
				}
			}
			else if (i == 0 && j < p.nbl-1 && j > 0) { //ligne haut 
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]);  
					if (!estNoir(t[i][j+1]))
						if (findSet(t[i][j]) != findSet(t[i][j+1]))  
							Union(t[i][j], t[i][j+1]); 
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j]))  
							Union(t[i][j], t[i+1][j]); 
				}
			}
			else if (i > 0 && i < p.nbh-1 && j == p.nbl-1) { // colonne droite
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]); 
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j]))  
							Union(t[i][j], t[i+1][j]); 
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]); 

					printf("cd\n");
				}
			}
			else if (i == p.nbh-1 && j < p.nbl-1 && j > 0){ // ligne bas
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i][j+1]))
						if (findSet(t[i][j]) != findSet(t[i][j+1]))  
							Union(t[i][j], t[i][j+1]);  
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]); 
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]); 
				}
			}
			else {
				if (!estNoir(t[i][j])) {
					if (!estNoir(t[i-1][j]))
						if (findSet(t[i][j]) != findSet(t[i-1][j]))  
							Union(t[i][j], t[i-1][j]); 
					if (!estNoir(t[i+1][j]))
						if (findSet(t[i][j]) != findSet(t[i+1][j]))  
							Union(t[i][j], t[i+1][j]); 
					if (!estNoir(t[i][j-1]))
						if (findSet(t[i][j]) != findSet(t[i][j-1]))  
							Union(t[i][j], t[i][j-1]); 
					if (!estNoir(t[i][j+1]))
						if (findSet(t[i][j]) != findSet(t[i][j+1]))  
							Union(t[i][j], t[i][j+1]);  
				}
			}
		}
	}
	return t;
}

TB uniformiserColori(TB t, PBM p)
{
	for ( int i = 0; i < p.nbh; i++)
		for (int j = 0; j < p.nbl; j++) {
			Noeud* tmp = findSet(t[i][j]);
			if ( tmp != t[i][j].chaine){
				t[i][j].chaine->pixel[0] = tmp->pixel[0];
				t[i][j].chaine->pixel[1] = tmp->pixel[1];
				t[i][j].chaine->pixel[2] = tmp->pixel[2];
			}
		}

	return t;
}

PPM creerPPM(TB t, PBM p)
{
	PPM p1;
	p1.nbMage = "P3";
	p1.nbl = p.nbl;
	p1.nbh = p.nbh;
	p1.max = 255;
	
	int tmp = p.nbl*3;
	
	p1.tableau = malloc(sizeof(int*) * p1.nbh);
	for (int = 0; i < p1.nbh; i++)
		p1.tableau[i] = malloc(tmp * sizeof(int));
	
	for (int j = 0; j < p1.nbh; j++)
		for (int k = 0, x = 0; k < tmp; x++, k++) {
			int i=0;
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
		}
		
	return p1;
}



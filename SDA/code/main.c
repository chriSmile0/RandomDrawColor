#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fichier.h"
#include "ensemble.h"

bool estNoir(Liste l)
{
	if (l.head == NULL){
		fprintf(stderr, " erreur estNoir");
		exit(EXIT_FAILURE);
	}
	if (l.head->val[0] == 0){
		if(l.head->val[1] == 0){
			if(l.head->val[2] == 0){
				return true;
			}
		}
	}
	else{
		return false;
	}
	
	return false;
}

TB voisin(TB t, PBM p){
	
	for (int i=0; i<p.nbh; i++){
		for (int j=0; j<p.nbl; j++){
			printf("%d/%d\n", i, j);
			printf("%d/%d\n", p.nbl, p.nbh);
			if (i == 0 && j == 0){  //en haut a gauche
				if (estNoir(t[i][j]) == false){
					if (estNoir(t[i][j+1]) == false){
						if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
						else { Union(t[i][j+1],t[i][j]); }
					}
					if (estNoir(t[i+1][j]) == false){
						if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
						else { Union(t[i+1][j],t[i][j]); }
					}
				}
				printf("hg\n");
			}
			
			/*
			if (i == p.nbh-1 && j == 0){  //en bas a gauche
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i-1][j])){
						if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
						else { Union(t[i-1][j], t[i][j]); }
					}
					if ( !estNoir(t[i][j+1])){
						if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
						else { Union(t[i][j+1], t[i][j]); }
					}
					printf("bg\n");
				}
			}
			
			if (i == 0 && j == p.nbl-1){ //en haut a droite
				printf("hd\n");
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
						else { Union(t[i][j-1], t[i][j]); }
					}
					if (!estNoir(t[i+1][j])){
						if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
						else { Union(t[i+1][j], t[i][j]); }
					}
				}
			}
			
			if (i == p.nbh-1 && j == p.nbl-1){  //en bas a droite
				printf("bd\n");
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
						else { Union(t[i][j-1], t[i][j]); }
					}
					if (!estNoir(t[i-1][j])){
						if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
						else { Union(t[i-1][j], t[i][j]); }
					}
				}
			}
			
			if (i > 0 && i < p.nbh-1 && j == 0){ //colonne gauche 
				printf("cg\n");
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i-1][j])){
						if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
						else { Union(t[i-1][j], t[i][j]); }
					}
					if (!estNoir(t[i][j+1])){
						if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
						else { Union(t[i][j+1], t[i][j]); }
					}
					if (!estNoir(t[i+1][j])){
						if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
						else { Union(t[i+1][j], t[i][j]); }
					}
				}
			}
			*/
			/*
			if (i == 0 && j < p.nbl-1 && j > 0){ //ligne haut 
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						
						if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
						else { Union(t[i][j-1], t[i][j]); }
					}
					if (!estNoir(t[i][j+1])){
						if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
						else { Union(t[i][j+1], t[i][j]); }
					}
					if (!estNoir(t[i+1][j])){
						if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
						else { Union(t[i+1][j], t[i][j]); }
					}
					
				}
			}
			*/
			/*
			if (i > 0 && i < p.nbh-1 && j == p.nbl-1){ // colonne droite
				printf("cd\n");
				if (!estNoir(t[i][j-1])){
					if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
					else { Union(t[i][j-1], t[i][j]); }
				}
				if (!estNoir(t[i+1][j])){
					if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
					else { Union(t[i+1][j], t[i][j]); }
				}
				if (!estNoir(t[i-1][j])){
					if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
					else { Union(t[i-1][j], t[i][j]); }
				}
			}
			
			if (i == p.nbh-1 && j < p.nbl-1 && j > 0){ // ligne bas
				printf("lb\n");
				if (!estNoir(t[i][j+1])){
					if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
					else { Union(t[i][j+1], t[i][j]); }
				}
				if (!estNoir(t[i-1][j])){
					if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
					else { Union(t[i-1][j], t[i][j]); }
				}
				if (!estNoir(t[i][j-1])){
					if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
					else { Union(t[i][j-1], t[i][j]); }
				}
			}
			
			else {
				if (!estNoir(t[i-1][j])){
					if (t[i-1][j].head->representant == t[i-1][j].head) { Union(t[i][j], t[i-1][j]); }
					else { Union(t[i-1][j], t[i][j]); }
				}
				if (!estNoir(t[i+1][j])){
					if (t[i+1][j].head->representant == t[i+1][j].head) { Union(t[i][j], t[i+1][j]); }
					else { Union(t[i+1][j], t[i][j]); }
				}
				if (!estNoir(t[i][j-1])){
					if (t[i][j-1].head->representant == t[i][j-1].head) { Union(t[i][j], t[i][j-1]); }
					else { Union(t[i][j-1], t[i][j]); }
				}
				if (!estNoir(t[i][j+1])){
					if (t[i][j+1].head->representant == t[i][j+1].head) { Union(t[i][j], t[i][j+1]); }
					else { Union(t[i][j+1], t[i][j]); }
				}
			}*/
			
			printf("connard\n");
		}
	}
	
	return t;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr,"error argument");
		exit(EXIT_FAILURE);
	}
	
	
	PBM p = Read(argv[1]);
	
	TB t = creerTB(p);
	
	t = voisin(t,p);
			
	/*
	Liste l = t[0][40];
	
	int v1,v2,v3;
	
	v1 = l.head->val[0];
	v2 = l.head->val[1];
	v3 = l.head->val[2];
	
	printf("\n");
	printf("%d\n",v1);
	printf("%d\n",v2);
	printf("%d\n",v3);
	*/
	
	PPM p1;
	p1.nbMage = "P3";
	p1.nbl = p.nbl;
	p1.nbh = p.nbh;
	p1.max = 255;
	
	int tmp = p.nbl*3;
	
	p1.tableau = malloc(sizeof(int*) * p1.nbh);
	
	int i;
	
	for(i=0; i<p1.nbh; i++){
		p1.tableau[i] = malloc(tmp * sizeof(int));
	}
	
	for (int j=0; j<p1.nbh; j++){
		for (int k=0, x=0; k<tmp; x++, k++){
			int i=0;
			p1.tableau[j][k] = t[j][x].head->val[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].head->val[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].head->val[i];
		}
	}
	
	
	Write(p1);
	
	
	//Generate(80,80);
	
	detruireTB(t,p);
	freetab(p);
	freeTab(p1);
	
	return 0;
}
	
		

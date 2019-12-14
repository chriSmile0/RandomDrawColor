#include <stdbool.h>
#include <time.h>
#include "fichier.h"
#include "ensemble_arbre.h"

bool estNoir(Arbre a)
{
	if (a.chaine->pixel[0] == 0){
		if (a.chaine->pixel[1] == 0){
			if (a.chaine->pixel[2] == 0){
				return true;
			}
		}
	}
	else {
		return false;
	}	
	
	return false;
}

TB voisin(TB t, PBM p){
	
	for (int i=0; i<p.nbh; i++){
		for (int j=0; j<p.nbl; j++){
			if (i == 0 && j == 0){  //en haut a gauche
				if (estNoir(t[i][j]) == false){
					if (estNoir(t[i][j+1]) == false){
						if (findSet(t[i][j]) != findSet(t[i][j+1])){ Union(t[i][j], t[i][j+1]); }
					}
					if (estNoir(t[i+1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
				}
			}
			
			
			else if (i == p.nbh-1 && j == 0){  //en bas a gauche
				if (estNoir(t[i][j]) == false){
					if (estNoir(t[i-1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]); }
					}
					if ( !estNoir(t[i][j+1])){
						if (findSet(t[i][j]) != findSet(t[i][j+1])) { Union(t[i][j], t[i][j+1]);  }
					}
				}
			}
			
			
			
			else if (i == 0 && j == p.nbl-1){ //en haut a droite
				
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]);  }
					}
					if (!estNoir(t[i+1][j])){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
				}
			}
			
			else if (i == p.nbh-1 && j == p.nbl-1){  //en bas a droite
				if (estNoir(t[i][j]) == false){
					if (estNoir(t[i-1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]); }
					}
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]);  }
					}
				}
			}
			
			
			else if (i > 0 && i < p.nbh-1 && j == 0){ //colonne gauche 
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j+1])){
						if (findSet(t[i][j]) != findSet(t[i][j+1])) { Union(t[i][j], t[i][j+1]);  }
					}
					if (!estNoir(t[i+1][j])){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
					if (!estNoir(t[i-1][j])){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]);  }
					}
				}
			}
			
			
			else if (i == 0 && j < p.nbl-1 && j > 0){ //ligne haut 
				
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]);  }
					}
					if (!estNoir(t[i][j+1])){
						if (findSet(t[i][j]) != findSet(t[i][j+1])) { Union(t[i][j], t[i][j+1]); }
					}
					if (!estNoir(t[i+1][j])){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
				}
			}
			
			else if (i > 0 && i < p.nbh-1 && j == p.nbl-1){ // colonne droite
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]); }
					}
					if (!estNoir(t[i+1][j])){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
					if (estNoir(t[i-1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]); }
					}
				}
			}
			
			else if (i == p.nbh-1 && j < p.nbl-1 && j > 0){ // ligne bas
				if (estNoir(t[i][j]) == false){
					if (!estNoir(t[i][j+1])){
						if (findSet(t[i][j]) != findSet(t[i][j+1])) { Union(t[i][j], t[i][j+1]);  }
					}
					if (estNoir(t[i-1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]); }
					}
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]); }
					}
				}
			}
			
			
			else {
				
				if (estNoir(t[i][j]) == false){
					
					if (estNoir(t[i-1][j]) == false){
						if (findSet(t[i][j]) != findSet(t[i-1][j])) { Union(t[i][j], t[i-1][j]); }
					}
					if (!estNoir(t[i+1][j])){
						if (findSet(t[i][j]) != findSet(t[i+1][j])) { Union(t[i][j], t[i+1][j]); }
					}
					
					if (!estNoir(t[i][j-1])){
						if (findSet(t[i][j]) != findSet(t[i][j-1])) { Union(t[i][j], t[i][j-1]) ; }
					}
					
					if (!estNoir(t[i][j+1])){
						if (findSet(t[i][j]) != findSet(t[i][j+1])) { Union(t[i][j], t[i][j+1]);  }
					}
				}
			}
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
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
			k++;
			i++;
			p1.tableau[j][k] = t[j][x].chaine->pixel[i];
		}
	}
	
	
	Write(p1);
	
	freetab(p);
	freeTab(p1);
	detruireTB(t,p);
	
	return 0;
}

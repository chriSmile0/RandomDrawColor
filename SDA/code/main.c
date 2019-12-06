#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fichier.h"
#include "ensemble.h"

bool estNoir(Liste l)
{
	return (l.head.val[0] == 0 && l.head.val[1] == 0 && l.head.val[2] == 0);
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr,"error argument");
		exit(EXIT_FAILURE);
	}
	
	
	PBM p = Read(argv[1]);
	
	printf("Read fini\n");
	
	TB t = creerTB(p);
	
	for (int i=0; i<p.nbh; i++){
		for (int j=0; j<p.nbl; j++){
			if (i == 0 && j ==0){
				if (!estNoir(t[i][j+1]))
					Union(t[i][j], t[i][j+1]);
				if (!estNoir(t[i+1][j]))
					Union(t[i][j], t[i+1][j]);
			}
			if (i == p.nbh-1 && j ==0){
				if (!estNoir(t[i-1][j]))
					Union(t[i][j], t[][]
			}//a finir
			
	
	printf("Creation TB\n");
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
	
	printf("Crea PPM\n");
	
	Write(p1);
	
	printf("Write\n");
	
	//Generate(80,80);
	
	detruireTB(t,p);
	freetab(p);
	freeTab(p1);
	
	printf("Free\n");
	
	return 0;
}
	
		

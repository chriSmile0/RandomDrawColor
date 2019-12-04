#include <stdio.h>
#include <stdlib.h>

#include "fichier.h"
#include "ensemble.h"

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr,"error argument");
		exit(EXIT_FAILURE);
	}
	
	
	PBM p = Read(argv[1]);
	
	TB t = creerTB(p);
	
	/*
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
	p1.nbl = p.nbl*3;
	p1.nbh = p.nbh;
	p1.max = 255;
	
	p1.tableau = malloc(sizeof(int*) * p1.nbh);
	
	int i;
	
	for(i=0; i<p1.nbh; i++){
		p1.tableau[i] = malloc(p1.nbl * sizeof(int));
	}
	
	for (int j=0; j<p1.nbh; j++){
		for (int k=0, x=0; k<p1.nbl; x++, k++){
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
	
	return 0;
}
	
		

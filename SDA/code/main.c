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
	
	Liste l = t[0][0];
	
	int v1,v2,v3;
	
	v1 = l.head->val[0];
	v2 = l.head->val[1];
	v3 = l.head->val[2];
	
	printf("\n");
	printf("%d\n",v1);
	printf("%d\n",v2);
	printf("%d\n",v3);
	
	/*
	PPM p1;
	p1.nbMage = "P3";
	p1.nbl = 3;
	p1.nbh = 1;
	p1.max = 255;
	
	p1.tableau = malloc(sizeof(int*) * p1.nbh);
	
	int i;
	
	for(i=0; i<p1.nbh; i++){
		p1.tableau[i] = malloc(p1.nbl * sizeof(int));
	}
	
	p1.tableau[0][0] = 200;
	p1.tableau[0][1] = 100;
	p1.tableau[0][2] = 250;
	*/
	//Write(p1);
	
	//Generate(80,80);
	
	return 0;
}
	
		

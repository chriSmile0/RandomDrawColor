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
	
	
	//PBM p = Read(argv[1]);
	
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
	
	//Write(p1);
	
	Generate(80,80);
	
	return 0;
}
	
		

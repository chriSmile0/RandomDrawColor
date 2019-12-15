/**
 * \file main.c
 * \brief Main.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "fichier.h"
#include "ensemble.h"


int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr,"error argument");
		exit(EXIT_FAILURE);
	}
	
	float temps;
	clock_t t1,t2;
	
	t1 = clock();
	
	PBM p = Read(argv[1]);
	
	TB t = creerTB(p);
	
	t = voisin(t,p);
	
	PPM p1 = creerPPM(t,p);

	Write(p1);

	freetab(p);
	freeTab(p1);
	detruireTB(t,p);
	
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps = %f\n", temps);
	
	return 0;
}
	
		

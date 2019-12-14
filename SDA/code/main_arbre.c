#include "fichier.h"
#include "ensemble_arbre.h"

int main(int argc, char *argv[])
{
	if (argc != 2){
		fprintf(stderr,"error argument");
		exit(EXIT_FAILURE);
	}
	
	PBM p = Read(argv[1]);
	TB t = creerTB(p);
	
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

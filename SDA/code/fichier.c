#include "fichier.h"

PBM Read(char * filename){
	
	FILE * pfile = NULL;
	pfile = fopen(filename, "r+");
	if (pfile == NULL) {
		fprintf(stderr,"echec ouverture");
		exit(EXIT_FAILURE);
	}
	
	PBM p;

	int n,m;// m largeur/ n hauteur
	p.nbMage = malloc (2 * sizeof(char));
	fscanf(pfile,"%s",p.nbMage);
	fscanf(pfile,"%d",&m);
	fscanf(pfile,"%d",&n);
	
	printf("mag : %s\n",p.nbMage);
	printf("largeur : %d\n",m);
	printf("hauteur : %d\n",n);
	
	p.nbl = m;
	p.nbh = n;
	
	p.tableau = malloc(sizeof(int*) * n);
	if (p.tableau == NULL){
		fprintf(stderr,"Tableau error");
		exit(EXIT_FAILURE);
	}
	
	int i,j;
	//char c[1];
	
	for(i=0; i<n; i++){
		p.tableau[i] = malloc(m * sizeof(int));
		if (p.tableau == NULL){
			fprintf(stderr,"Tableau error");
			exit(EXIT_FAILURE);
		}
	}
	int k;
	
	//fseek(pfile, 1, SEEK_CUR);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fscanf(pfile,"%d",&k);
			//c = fgetc(pfile);
			/*fread(c, 1, 1,pfile);
			if (c[0] == '\n' || c[0] == ' '){
				fseek(pfile, 1, SEEK_CUR);
				fread(c, 1, 1,pfile);
			}
			k = c[0]-'0';
			printf("%d\n",k);*/
			p.tableau[i][j] = k;
		}
	}
	pclose(pfile);
	
	/*for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d",p.tableau[i][j]);
		}
	}*/
	
	return p;
}

void freetab(PBM p){
	
	//free(p.nbMage);
	
	for(int i=0; i<p.nbh; i++){
		free(p.tableau[i]);
	}
	free(p.tableau);
}

void freeTab(PPM p){
	
	//free(p.nbMage);
	
	for(int i=0; i<p.nbh; i++){
		free(p.tableau[i]);
	}
	free(p.tableau);
}
	
void Write(PPM p){
	
	FILE* image = NULL;
	
	image = fopen("Image", "a");
	
	if(image != NULL){
		fputs(p.nbMage,image);
		fputs("\n",image);
		fprintf(image, "%d", p.nbl);
		fputs(" ",image);
		fprintf(image, "%d", p.nbh);
		fputs("\n",image);
		fprintf(image, "%d", p.max);
		fputs("\n",image);
		
		int i,j;
		for (i=0; i<p.nbh; i++){
			for (j=0; j<p.nbl*3; j++){
				fprintf(image, "%d", p.tableau[i][j]);
				fputs(" ", image);
			}
		}
	}
	fclose(image);
}

void Generate(int n,int m){
	
	FILE* image = NULL;
	
	image = fopen("Image", "a");
	
	if(image != NULL){
		
		fputs("P1\n",image);
		fprintf(image, "%d", m);
		fputs(" ",image);
		fprintf(image, "%d", n);
		fputs("\n",image);
		
		srand(time(NULL));
		int i,j;
		int cmp = 0;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				if (cmp < 70){
					cmp++;
					int chiffre = rand()%2;
					fprintf(image, "%d",chiffre );
					fputs(" ",image);
				}
				if (cmp == 69){
					cmp = 0;
					int chiffre = rand()%2;
					fprintf(image, "%d", chiffre);
					fputs("\n",image);
				}
			}
		}
	}
	fclose(image);
}

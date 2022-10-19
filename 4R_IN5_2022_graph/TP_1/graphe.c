
#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	//Adjacence A = AdjacenceVide(9);
	//AfficheAdjacence(A);
	Adjacence B = LireGraphe(argv[1]);
	dotting(B);
	//AfficheAdjacence(B);
	//Adjacence C = Transpose(B);
	//AfficheAdjacence(C);
	return 0;
}


Adjacence LireGraphe(const char * nom){

	int val, i, n, x, y;
	FILE * fichier;
	fichier = fopen(nom,"r");

	if(fichier == NULL) exit(1);

	fscanf(fichier, "%d", &val);
	Adjacence A;
	A = AdjacenceVide(val);
	
	while( !feof(fichier) ){
		fscanf(fichier,"%d" "%d", &x, &y);
		A->Matrice[x][y] = 1;
	}
	return A;
}


Adjacence AdjacenceVide(int n){
	int i, j;

	Adjacence ret_struct;

	ret_struct = (Adjacence)malloc(sizeof(Adjacence));

	if(ret_struct == NULL){
		 exit(1);
	}
	ret_struct->nb_sommets = n;


	ret_struct->Matrice = (int **)malloc(n*sizeof(int *));

	for(i=0;i<n;i++){
		ret_struct->Matrice[i] = (int*)malloc(n*sizeof(int));
		if(ret_struct->Matrice[i] ==  NULL) exit(1);
		for(j=0;j<n;j++){
			 ret_struct->Matrice[i][j] = 0;
		}
	}

	return ret_struct;
}


void AfficheAdjacence (Adjacence A) {
	int n = A->nb_sommets, i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("[%d]", A->Matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

Adjacence Transpose( Adjacence A ){
	int i,j;
	Adjacence B = AdjacenceVide(A->nb_sommets);
	for(i=0;i<A->nb_sommets;i++){
		for(j=0;j<A->nb_sommets;j++){
			B->Matrice[i][j] = A->Matrice[j][i];
		}
	}
	return B;
}


void dotting( Adjacence A ){
	int i,j;
	for(i=0;i<A->nb_sommets;i++){
		for(j=0;j<A->nb_sommets;j++){
			if(A->Matrice[i][j] == 1) printf("%d -> %d\n", i, j);
		}
	}
}

#ifndef _GRAPHE_H
#define _GRAPHE_H


typedef struct struct_adjacence{

	int nb_sommets;
	int **Matrice;

}struct_adjacence;

typedef struct_adjacence * Adjacence;


void AfficheAdjacence(Adjacence);
Adjacence AdjacenceVide(int);
Adjacence LireGraphe( const char *);
Adjacence Transpose(Adjacence);
void dotting(Adjacence);

#endif

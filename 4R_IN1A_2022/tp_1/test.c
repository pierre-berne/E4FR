#include "tp1.h"
#include <stdio.h>

int main(int argc, char * argv[]){
/*	int i, j;
	char r;

	if(argc==2){
		sscanf(argv[1], "%d %c %d", &i, &r, &j);
		printf("%d\n", calcule(i,j,r));
		return 0;
	
	}else if(argc > 2 || argc < 4){
		if(sscanf(argv[1]," %d", &i) != 1){
			printf("erreur - le premier arg n'est pas un chiffre\n"); 
			return 0;
		}
		else if(sscanf(argv[2]," %d", &j) != 1){
			printf("erreur - le deuxieme arg n'est pas un chiffre\n"); 
			return 0;
		}
		else if(sscanf(argv[3]," %c", &r) != 1){
			printf("erreur - le troisieme arg n'est pas un operande\n"); 
			return 0;
		}
		sscanf(argv[2]," %d", &j);
		sscanf(argv[3]," %c", &r);
		printf("retour : %d \n", calcule(i, j,r));
		return 0;
	}
	else{
		printf("Je manque d'information\n");
		return 0;
	}
*/

/** printf("%d\n", nb_partition(6,5)); **/

int tab_i[] = {5,9,7};
char tab_c[] = {'a','b','c'};
char *tab= "bur";
print_int_tab(tab_i, 3);
print_char_tab(tab_c, 3);
print_string(tab);

}



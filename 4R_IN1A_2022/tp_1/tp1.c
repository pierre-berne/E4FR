#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

/**
void print_message(char* message){
	printf("%s\n", message);
}

int calcule(int a, int b, char op){
	char def;
	switch (op) {
		case '+': 
			return a+b;
			break;
		case '-': 
			return a-b;
			break;
		case '/' : 
			return a/b;
			break;
		case 'x': 
			return a*b;
			break;
		default:
			printf("Operande inconnu, taper nouvel operande:\n");
			scanf("%c", &def);
			calcule(a,b,def);

	}
}

int nb_partition(int n, int t){

	if(n == 0) return 1;
	if(n < 0) return 0;
	if(n > 0 && t == 1) return 1;
	if(n > 0 && t > 1){
		return nb_partition(n-t, t) + nb_partition(n, t-1);
	}
}

void print_int_tab(int * tab, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%d\n",*(tab+i));
	}
}

void print_char_tab(char * tab, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%c\n",*(tab+i));
	}
}

void print_string(char* tab){
	printf("%s\n", tab);
}
**/

int* new_int_tab(int size){
	int * tab = (int)malloc(size*sizeof(int));
	if(tab

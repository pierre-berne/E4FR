#define H 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void generer_enfant(int h);

int main(){
	generer_enfant(1);
	exit(0);
}

void generer_enfant(int h){

	if(h > H) return; //fin du parcours vertical

	for(int i = 0; i<=h; i++){ //creation de(s) enfant(s)
		if(fork()== 0){
		generer_enfant(h+1);
		break;
		}
	}
	printf("%d -- %d\n", getpid(), getppid());
	return; //rec
}

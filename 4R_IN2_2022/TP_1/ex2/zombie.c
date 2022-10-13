#define H 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void generer_enfant(int h);

int main(){
	if(fork()==0){
		printf("pid FILS : %d de pere %d\n", getpid(), getppid());
		exit(0);
	}else{
		sleep(3);
		printf("pid PERE : %d, de pere %d\n", getpid(), getppid());
	
	}

	exit(0);



}

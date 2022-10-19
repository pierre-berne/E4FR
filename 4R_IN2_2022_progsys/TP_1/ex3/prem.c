#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/* Main function */
int main(int argc, char* argv[]){
  long long int n, a, b,i;
  sscanf(argv[1], "%lld", &n);
  sscanf(argv[2], "%lld", &a);
  sscanf(argv[3], "%lld", &b);
  int pid, res=-1;
  pid = getpid();

  /* Function */
  for (i = a; i <= b; i++) {
    if(i<2 || i==n) continue;
    if((n%i)==0){
      res = i;
      break;
    }
  }

  /* print result */
  if (res != -1){
    printf("PID %d : %lld admet %d comme diviseur\n", pid, n, res);
    exit(1);
  }else{
    printf("PID %d : pas de diviseur de %lld trouvé\n", pid, n);
    exit(0);
  }

}

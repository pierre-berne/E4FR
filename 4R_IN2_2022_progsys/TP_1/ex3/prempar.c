#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>


/* Main function */
int main(int argc, char* argv[]){
  long long int n, intervalle;
  int p, pid, i=0, rn, pid_t, pid_f, t, res=0,c;
  int* pid_fils=malloc(30*sizeof(int));
  char a[30], b[30];
  /* Verif arguments */
  if(sscanf(argv[1],"%lld",&n) != 1){
      fprintf(stderr, "Les arguments doivent être des entiers\n");
      return 0;
  }
  if(sscanf(argv[2],"%d",&p) != 1){
      fprintf(stderr, "Les arguments doivent être des entiers\n");
      return 0;
  }
  pid = getpid();
  pid_fils = realloc(pid_fils,p*sizeof(int));
  /* Function */
  rn = (int)sqrtl(n);
  printf("PID %d : lance %d processus\n", pid, p);
  intervalle = 0;
  t = rn%p;
  if (t !=0){
    t = rn/p +1;
  }else t=rn/p;
  for(;i<p;i++){
    sprintf(a, "%lld", intervalle);
    sprintf(b, "%lld", intervalle+t-1);
    intervalle +=t;
    pid_t=fork();
    if(pid_t == 0){
      execl("prem","prem", argv[1], a, b, NULL);
      pid_fils[i]=pid_t;
      wait(&c);
    }
  }

  for(i=0;i<p;i++){
    pid_t = waitpid(-1,&t,WIFEXITED(t));
    t = WEXITSTATUS(t);
    /*t >>= 8;*/
    printf("t: %d\n", t);
    if(t==1){
      res=1;
      pid_f = pid_t;
      break;
    }
  }
  if(res == 1){
    for(i=0;i<p;i++){
      /*printf("%d\n", pid_fils[i]);*/
      if(pid_fils[i] != pid_f) kill(pid_fils[i],3);
    }
  }

  return res;
}

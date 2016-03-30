#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <strings.h>

#define MAX 256



void siggy(int signum)
{
  usleep(1000);
  printf("I am child.\n");
}
void sigintd(int signum)
{
  usleep(1000);
  printf("child got sigint, exiting...\n");
  exit(0);
}

int main(int argc, char* argv[])
{
  char buf[MAX];
  pid_t pid;

  pid = fork();

  if(pid == -1){
    perror("forking error");
    exit(1);
  }
  else if(pid==0){
    // child
    signal(SIGUSR1,siggy);
    signal(SIGUSR2,siggy);
    signal(SIGINT,sigintd);
    for(;;);
  }
  else {
    // parent
    printf("I am dad af.\n");
    for(;;){
      printf("\nWhat signal would you like to send?\nSIGUSR[1] SIGUSR[2] SIGIN[T]\n");
      fgets(buf,MAX,stdin);
      if(strncasecmp(buf,"1",1)==0){
        kill(pid,SIGUSR1);
      }
      else if(strncasecmp(buf,"2",1)==0){
        kill(pid,SIGUSR2);
      }
      else if(strncasecmp(buf,"t",1)==0){
        kill(pid,SIGINT);
        printf("sending sigint to child, exiting...\n");
        exit(0);
      }
      else {
        printf("invalid\n");
      }

    }
  }
}

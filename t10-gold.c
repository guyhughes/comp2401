#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_STR 32

void *threadFunc(void*);
void childFunc();
void parentFunc();

char str[MAX_STR];


int main() 
{
  int rc, status;

  strcpy(str, "Timmy loves C");

  rc = fork();

  if (rc == 0) {
    childFunc();
    printf("Process %d says:  %s\n", getpid(), str);
  }
  else {
    parentFunc();
    wait(&status);
    printf("Process %d says:  %s\n", getpid(), str);
  }

  return(0);
}


void parentFunc()
{
  printf("Process %d:  in parent process\n", getpid());

}

void childFunc()
{
  printf("Process %d:  in child process\n", getpid());

  pthread_t t1;
  int tnum = 1;

  pthread_create(&t1, NULL, threadFunc, &tnum);
  sleep(1);

  strcat(str, "++");
}

void *threadFunc(void *num) 
{
  printf("Process %d:  in thread %d\n", getpid(), *(int *)num);
  strcat(str, "++");
}


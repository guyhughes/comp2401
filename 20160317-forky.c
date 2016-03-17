#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
  int pid, ppid, i, count;

  if (argc < 2)
    count =1;
  else
    count = atoi(argv[1]);

  printf("Parent process %d\n", getpid());
  for(i=0; i < count; ++i){
    if (fork() == 0){
      printf("Child process %d\n", getpid());
      return 0;
    } 
  }
  return 0;
}

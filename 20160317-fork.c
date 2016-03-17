#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int r, i;
  printf("Forking\n");

  r = fork();
  if(r == 0){
    printf("fork returned %d, this is the child \n",r);
    for(i=0; i < 24; ++i){
      printf("Marching *%d*\n",i);
      usleep(5000);
    }
    return 0;
  } else {
    printf("Marching ");
    for(i=0; i < 24; ++i){
      printf("Marching %d\n",i);
      usleep(2500);
    }
    return 0;
  }
}

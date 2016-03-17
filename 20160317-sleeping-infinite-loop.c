#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (void)
{
  int i;
  for(i=0; ; i++){
    printf("Marching %d...\n",i);
    sleep(1);
  }
}

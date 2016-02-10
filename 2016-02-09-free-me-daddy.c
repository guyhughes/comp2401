#include <stdlib.h>
#include <stdio.h>

int
main( void )
{
  int *ptr1, *ptr2;
  ptr1 = calloc(100,sizeof(int));
  ptr2 = calloc(100000,sizeof(long long));

  // valgrind will show remaining memory
  free(ptr2);
}


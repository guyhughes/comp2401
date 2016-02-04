#include <stdio.h>
#include <stdlib.h>

int
main( int argc, char * argv[] )
{
  int n;
  int * ptr;
  puts("Enter number of intts that you want");
  scanf("%d",&n);
  ptr=calloc(n,sizeof(int));
  *ptr = 10;
  ptr[1] = 20;
  for (int i=0; i<n; i++)
    printf("%d ", ptr[i]);

  puts("\n------------------------------");
  for (int i=0; i<n; i++, ptr++)
    printf("%d ", *ptr);

  puts("");


  return 0;
}

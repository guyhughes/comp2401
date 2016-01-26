#include <stdio.h>

int main()
{
  char *c;
  c = "hello bitch do i have any bounds or is this just going to go on for ever and efor ever eand for aever 27498237498274987234 98293 847298374982743982 498723984729837498327498273498274987329482374987239487239847 998798374982734928734293874";
  printf("%s\n",c);

  puts("----\n");
  
  char x[10];
  x[0] = 'a';
  x[1] = 0;
  printf("x: %s\n",x);
  char * q = "hello daddy";
  /* char * q = x; */
 //q = "fuck";
 *x = *q;
  printf("q: %s\nx: %s",q,x);

}

#include <stdio.h>
#include <string.h>

#define MAX_STR 32

struct p_t {
  char first[MAX_STR];
  char last[MAX_STR];
  int  age;
};

int main()
{
  puts("main called");
  struct p_t g;
  strcpy(g.first,"Gertrude");
  strcpy(g.last,"Kung Pu Panda");
  g.age = 101;

  printf("g sizeof() is %d\n",(int)sizeof(g));

  puts ("main complete");
  return 0;
}

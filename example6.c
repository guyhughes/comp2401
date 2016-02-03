#include <stdio.h>
#include <string.h>

#define MAX_STR 32

int main()
{
  char i1[MAX_STR];
  char i2[MAX_STR];
  char n[MAX_STR];
  char b[MAX_STR];

  puts("Enter two strings");
  scanf("%s %s", i1, i2);

  printf("You say: %s %s\n",i1, i2);

  strcpy(n,i1);
  n[0]='j';
  printf("I say: %s\n",n);

  printf("We both say %s %s\n", strcat(i1,n), i2);

  sprintf(b,"%s %s, y%d", i1, i2, 0);
  printf("%s\n",b);

}

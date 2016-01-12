#include <stdio.h>
int main()
{
  int num1, num2, num3, num4;
  num1=4;
  num2=num1;
  num3=num2 + 2 * num1 -3;
  num4=num3*3;
  printf("%d %d %d %d\n",num1,num2,num3,num4);
  return 0;
}

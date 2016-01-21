#include <stdio.h>
#include <stdint.h>

int gcd(int,int);

int main()
{
  int a, b;
  scanf("%d",&a);
  scanf("%d",&b);

  printf("%d\n",gcd(a,b));
}

int gcd(int a, int b)
{
  int t;
  while (b != 0){
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}

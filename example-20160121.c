#include <stdio.h>
#include <limits.h>
const char* toBinaryString(unsigned long num)
{
    static char buffer[CHAR_BIT*sizeof(num)+1];
    char* pBuffer = &buffer[sizeof(buffer)-1];

    do *--pBuffer = '0' + (num & 1);
    while (num >>= 1);
    return pBuffer;
}

void inBinary(unsigned int x)
{
  printf("%20s\n", toBinaryString(x));
  return;
}

void shit(int x)
{
           char c;
  unsigned char uc;

  c = uc = x; 
  printf("%d -- %d \n",c,uc);
  return;
}

void other_shit()
{
  unsigned char a=0;
  printf("%d → %d\n",a,a|(1<<30));

}

int main()
{
  other_shit();
  return 0;
}

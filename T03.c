#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
char* giveBits(unsigned char c);
void printBits(unsigned char);

int
main() {

  unsigned char a = 'A';

  unsigned char arr[2][3][4] = {
                                  {
                                    {62,138,241,129},
                                    {8,221,163,159},
                                    {91,158,169,150}
                                 },
                                  {
                                    {15,138,251,198},
                                    {14,211,161,158},
                                    {77,204,188,217}
                                  }
                                };

  unsigned int i,j,k;


  printBits(a);
  a = setBit(a, 2);
  a = setBit(a, 3);
  printBits(a);
  a = clearBit(a, 2);
  printBits(a);
  printf("\n");

  /* implement question 4 here */
  puts("--------------------------------------------------------------------------------");
  puts("QUESTION 4.a");
  puts("--------------------------------------------------------------------------------");
  for(i=0; i < sizeof(arr)/sizeof(arr[0]); ++i){
    for(j=0; j < sizeof(arr[i])/sizeof(arr[i][0]); ++j){
      for(k=0; k < sizeof(arr[i][j])/sizeof(arr[i][j][0]); ++k){
        printf("%4d: %s → ",arr[i][j][k],giveBits(arr[i][j][k]));
        arr[i][j][k] = arr[i][j][k] & (~( 1 << 6));
        printf("%s\n",giveBits(arr[i][j][k]));
      }
    }
  }
  puts("--------------------------------------------------------------------------------");
  puts("QUESTION 4.b");
  puts("--------------------------------------------------------------------------------");
  for(i=0; i < sizeof(arr)/sizeof(arr[0]); ++i){
    for(j=0; j < sizeof(arr[i])/sizeof(arr[i][0]); ++j){
      for(k=0; k < sizeof(arr[i][j])/sizeof(arr[i][j][0]); ++k){
        printf("%4d: %s → ",arr[i][j][k],giveBits(arr[i][j][k]));
        arr[i][j][k] = arr[i][j][k] & ( 1 << 3);
        printf("%s\n",giveBits(arr[i][j][k]));
      }
    }
  }
  puts("--------------------------------------------------------------------------------");
  puts("QUESTION 4.c");
  puts("--------------------------------------------------------------------------------");
  for(i=0; i < sizeof(arr)/sizeof(arr[0]); ++i){
    for(j=0; j < sizeof(arr[i])/sizeof(arr[i][0]); ++j){
      for(k=0; k < sizeof(arr[i][j])/sizeof(arr[i][j][0]); ++k){
        printf("%4d, ",arr[i][j][k]);
      }
      puts("");
    }
    puts("");
  }
  puts("");
  return 0;
}


unsigned char
getBit(unsigned char c, int n) {
  assert(n < 8); // n must be on [0,7]
  return (c & (1 << n))>>n;
}

unsigned char
setBit(unsigned char c, int n) {
  assert(n < 8);
  return (c | ( 1<<n ));
}

unsigned char
clearBit(unsigned char c, int n) {
  assert(n < 8);
  return (c & (~( 1<<n )));
}

void
printBits(unsigned char c) {
  printf("%d%d%d%d %d%d%d%d\n",getBit(c,7),getBit(c,6),getBit(c,5),getBit(c,4),getBit(c,3),getBit(c,2),getBit(c,1),getBit(c,0));
}

char*
giveBits(unsigned char c) {
  char * result=malloc(sizeof(char)*100);
  sprintf(result,"%d%d%d%d %d%d%d%d",getBit(c,7),getBit(c,6),getBit(c,5),getBit(c,4),getBit(c,3),getBit(c,2),getBit(c,1),getBit(c,0));
  return result;
}

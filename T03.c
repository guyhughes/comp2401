#include <stdio.h>

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
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

  int i, j, k;

  printBits(a);
  a = setBit(a, 2);
  a = setBit(a, 3);
  printBits(a);
  a = clearBit(a, 2);
  printBits(a);
  printf("\n");

  /* implement question 4 here */

  return 0;
}


unsigned char
getBit(unsigned char c, int n) {

}

unsigned char
setBit(unsigned char c, int n) {

}

unsigned char
clearBit(unsigned char c, int n) {

}

void
printBits(unsigned char c) {

}


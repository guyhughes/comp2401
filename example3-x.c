#include <stdio.h>
#include <string.h>
#define MAX 100
// init array with Fionacci numbers and finds a specific number and returns the
// index
void printArray(unsigned long long *);
void initArray(unsigned long long *);
int findNum(unsigned long long *, int);

int main() {
  long long array[MAX];
  // int index, selectedNum;
  initArray(array);
  printArray(array);
  return 0;
}

void printArray(unsigned long long *array) {
  int i;

  for (i = 0; i < MAX; ++i)
    printf("[%i] %llu\n", i, array[i]);
}

void initArray(unsigned long long *array) {
  int i;

  array[0] = 0;
  array[1] = 1;

  for (i = 2; i < MAX; ++i) {
    array[i] = array[i - 1] + array[i - 2];
  }
}

int findNum(unsigned long long *array, int num) {
  int i;

  for (i = 0; i < MAX; ++i) {
    if (array[i] == num)
      return i;
  }
  return -1;
}

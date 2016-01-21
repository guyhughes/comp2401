#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#define MAX  100
// init array with Fionacci numbers and finds a specific number and returns the index
void printArray(uint64_t *);
void initArray(uint64_t *);
int findNum(uint64_t *, uint16_t);

int main()
{ 
  uint64_t array[MAX];
  //int index, selectedNum;
  initArray(array);
  printArray(array);
  return 0;
}

void printArray(uint64_t *array)
{
  uint16_t i;

  for(i=0; i < MAX; ++i)
    printf("[%"PRIu16"] %"PRIu64"\n",i,array[i]);
}

void initArray(uint64_t *array)
{
  int i;

  array[0] = 0;
  array[1] = 1;

  for(i=2; i < MAX; ++i){
    array[i] = array[i-1] + array[i-2];
  }

}

int findNum(uint64_t *array, uint16_t num)
{
  uint16_t i;
  
  for(i=0; i < MAX; ++i){
    if (array[i]==num)
      return i;
  }
  return -1;
}



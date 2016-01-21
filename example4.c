#include <stdio.h>
#include <string.h>

#define MAX  16

void printArray(int *);
void    getNums(int *);
int  computeMax(int *);

int main()
{
  int array[MAX];
  int max;

  getNums(array);
  max = computeMax(array);

  printArray(array);

  printf("Max is %d\n", max);

  return 0;
}

void getNums(int * arr)
{
  int currNum, i;
  int totalNums = 0;

  for (i=0; i < MAX; ++i){
    arr[i] = 0;
  }

  while ( totalNums < MAX-1 ) {
   printf("Enter a fucking number: ");
   scanf("%i", &currNum);
   if (currNum < 0)
     break;
   arr[totalNums++] = currNum;
  }
}

void printArray(int * arr)
{
  int i;

  for(i=0; i < MAX; ++i)
    printf("[%i] %i\n",i,arr[i]);
}

int computeMax(int * arr)
{
  int i=0;
  int currMax = -1;

  for(;;){
    if(arr[i]<0)
      break;

    if (arr[i] > currMax)
      currMax=arr[i];

    ++i;
  }
  
  return currMax;
}

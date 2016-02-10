/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                               */
/*  Program:  T04gold                                            */
/*  Author:   Christine Laurendeau                               */
/*  Date:     Oct. 2, 2013                                       */
/*                                                               */
/*  Purpose:  Prompts the user for three numbers, assigns        */
/*            a pointer to point to each number in turn then     */
/*            prints out the value of the number and its pointer */
/*                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

int main()
{
  int  num[3];
  int  *ptr;
  int  i;

  for (i=0; i<3; ++i) {
    printf("Enter a number:  ");
    scanf("%d", &(num[i]));
  }
  printf("\n");

  for (i=0; i<3; ++i) {
    ptr = &num[i];
    printf("value of num[%d]:  %d \n", i, *ptr);
    printf("value of ptr:     %p \n\n", ptr );
  }

  return 0;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                               */
/*  Program:  T03gold                                            */
/*  Author:   Christine Laurendeau                               */
/*  Date:     Sept. 25, 2013                                     */
/*                                                               */
/*  Purpose:  Prompts the user for a string, and modifies the    */
/*            string to be its mirror image, i.e. each           */
/*            character in nth position from the beginning       */
/*            is switched with the character in nth position     */
/*            from the end.  Example:  the mirror of "hello"     */
/*            is "olleh"                                         */
/*                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <stdio.h>
#include <string.h>


int main()
{
  char str[32];
  char c;
  unsigned int  i, j;

  printf("Enter string:  ");
  scanf("%s", str);

  i = 0;

  while (i < strlen(str)/2) {
    j = strlen(str) -1 - i;
    c = str[i];
    str[i] = str[j];
    str[j] = c;
    i++;
  }

  printf("Mirror string: %s\n", str);

  return(0);
}

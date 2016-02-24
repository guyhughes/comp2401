#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "T05goldDefs.h"


int main ()
{
   StudentType *matilda;
   int i;

   initStudent ( "Matilda", "Mallister", 22, "100888777", 11.2, &matilda );

   printStudent ( matilda );
   cleanupStudent ( matilda );

   return ( 0 );
}

void initStudent ( char *f, char *l, int a,
                   char *n, float g, StudentType **stuPtr )
{
   StudentType *stu = (StudentType *) calloc ( 1, sizeof ( StudentType ) );
   strcpy ( stu->basicInfo.first, f );
   strcpy ( stu->basicInfo.last, l );
   stu->basicInfo.age = a;
   strcpy ( stu->stuNumber, n );
   stu->gpa = g;
   *stuPtr = stu;
}

void printStudent ( const StudentType *stuPtr )
{
   printf ( "Student #%s:  %s %s, age %d, gpa %.1f\n",
            stuPtr->stuNumber, stuPtr->basicInfo.first, stuPtr->basicInfo.last,
            stuPtr->basicInfo.age, stuPtr->gpa );
}

void cleanupStudent ( StudentType *stuPtr )
{
   free ( stuPtr );
}


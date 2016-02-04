#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char  *first;
  char  *last;
  int   age;
} info_t;

typedef struct {
  info_t basicInfo;
  char   *studentnumber;
  float  gpa;
} student_t;

void
initstudent(char *f, char *l, int a, char *n, float g, student_t *stu)
{
  stu->basicInfo.first = malloc(sizeof(char)*254);
  stu->basicInfo.last  = malloc(sizeof(char)*254);
  stu->studentnumber   = malloc(sizeof(char)*15);

  strcpy(stu->basicInfo.first, f);
  strcpy(stu->basicInfo.last, l);
  stu->basicInfo.age = a;
  strcpy(stu->studentnumber, n);
  stu->gpa = g;
}

void
printstudent(const student_t* stu)
{
  printf("%s %s #%s\nAge %d\tGPA %f\n",stu->basicInfo.first,stu->basicInfo.last,stu->studentnumber,stu->basicInfo.age,stu->gpa);
}

int
main()
{
  int i;
  student_t stud[5];
  initstudent("Won","Love",20,"10037199",4.0,&stud[0]);
  initstudent("Seconde","Cup",21,"10037198",3.2,&stud[1]);
  initstudent("Tree","Hugger",25,"10037197",2.2,&stud[2]);
  initstudent("Fort","Knox",25,"10037196",3.1,&stud[3]);
  initstudent("Hive","Mind",26,"10037195",3.0,&stud[4]);
  for(i=0;i<5;++i){
    printstudent(&stud[i]);
    puts("");
  }
}

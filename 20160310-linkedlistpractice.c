#include <stdlib.h>
#include <stdio.h>

#define MAX

typedef struct Person {
  char name[256];
  int age;
} PersonType;

void person_init(Person *p, char* name, int age ){
  strcpy(p->name,name);
  p->age=age;
}

void person_print(Person *p)
{
  printf("%s, %d",p->name,p->age);
}

typedef struct Node NodeType;
struct Node {
  Person *data;
  Node *next;
  Node *prev;
};

typedef struct List ListType;
struct List {
  Node *head;
};

void list_add(:q)

typedef struct DList DListType;
struct DList {
  Node *head;
  Node *tail;
};


int main ( void )
{
  int i;
  char x[2]="a\0";
  Person people[MAX];
  ListType list;
  DListType dlist;

  for(i=0; i < MAX; ++i){
    x[0]= 'a'+i%('Z'-'a');
    person_init(&people[i],x,i%5+20);
    list_add(&list,&people[i]);
  }
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR 256


typedef struct Runner RunnerType;
typedef struct Node NodeType;
typedef struct List ListType;
struct Runner{
  char name[MAX_STR];
  int  bidNumber;
  int  finishTime;
};
struct Node {
  NodeType   *next, *prev;
  RunnerType *data;
};
struct List {
  NodeType *head;
};


/* runners.c */
void menu(ListType *l);
void addRunner(RunnerType *r, ListType *l);
void list_print(ListType *l);
RunnerType *runner_init(void);
void list_init(ListType **l);

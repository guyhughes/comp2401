#include "runners.h"
int main(int argc, char** argv, char** envp)
{
  ListType *l;
  list_init(&l);
  for(;;){
    menu(l);
  }
  free(l);
}

void menu(ListType *l)
{
  int i;
  RunnerType *r;
  printf("1. Add\n"
         "2. Show\n"
         ": "
         );
  scanf("%d",&i);
  switch(i){
    case 1:
      r=runner_init();
      addRunner(r,l);
      break;
    default:
      list_print(l);
  }
}


void list_print(ListType *l){
  NodeType *p;
  if (l->head == NULL) {
    printf("empty\n");
  }
  printf("%-10s  %-10s  %-10s  %-10s  %-10s\n","Name","Bid No.","Finish Time","Prev","Next");
  printf("-----------------------------------------------------------\n");
  for(p=l->head; p != NULL; p=p->next){
    printf("%-10s |%10d |%10d |%-10s |%-10s|\n",p->data->name,p->data->bidNumber,p->data->finishTime,
        (p->prev==NULL? "-": p->prev->data->name),
        (p->next==NULL? "-": p->next->data->name)
        );
  }
}

RunnerType* runner_init(){
  RunnerType *r = calloc(1,sizeof(RunnerType));
  char str[MAX_STR];

  printf("Name: "); 
  fflush(stdout);  /* we flush so we don't have to print a newline in prompt */
  scanf("%s",str);
  strncpy(r->name,str,MAX_STR);

  printf("Bid No.: ");
  fflush(stdout);
  scanf("%d",&r->bidNumber);

  printf("Finish Time: ");
  fflush(stdout);
  scanf("%d",&r->finishTime);

  return r;
}

void list_init(ListType **l)
{
  *l = calloc(1,sizeof(ListType));
}



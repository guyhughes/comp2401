#include "runners.h"
/**
 * This is the simple way to do this.
 */
void addRunner(RunnerType *r, ListType *l)
{
  NodeType *node, *pivot, *pprev;

  if(r == NULL || l == NULL){
    perror("NULL param");
    return;
  }

  node=calloc(1,sizeof(NodeType));
  node->data = r;
  node->next = node->prev = NULL;

  for(pivot=l->head,pprev=NULL; pivot != NULL; pprev = pivot, pivot = pivot->next){
    if(r->finishTime <= pivot->data->finishTime){
      break;
    }
  }
  if(pprev==NULL){ // then we are adding to the head
    node->next = l->head;
    l->head = node;
  }
  else { // then we are adding to tail or middle
    node->next = pprev->next;
    pprev->next = node;
    node->prev = pprev;
  }

  if(node->next != NULL){
    node->next->prev = node;
  }
}

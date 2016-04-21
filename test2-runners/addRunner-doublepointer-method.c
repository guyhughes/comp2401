#include "runners.h"
/**
 * This is the way I prefer to do this, but it would probably annoy Dr. Laurendeau in marking it so I try not to do it this way.
 */
void addRunner(RunnerType *r, ListType *l)
{
  NodeType **insertionpoint=NULL, *node, *pivot;

  if(r == NULL || l == NULL){
    perror("null param");
    return;
  }

  node=calloc(1,sizeof(NodeType));
  node->data = r;
  node->next = node->prev = NULL;

  if(l->head  == NULL)
    insertionpoint = &l->head;

  for(pivot=l->head; insertionpoint == NULL; pivot=pivot->next){
    if(r->finishTime <= pivot->data->finishTime)
      insertionpoint = (pivot->prev != NULL? &pivot->prev->next: &l->head); 
    else if (pivot->next == NULL)
      insertionpoint = &pivot->next;
  }

  if(*insertionpoint != NULL) {
    node->prev=(*insertionpoint)->prev;
    node->next=*insertionpoint;
    (*insertionpoint)->prev = node;
  }
  *insertionpoint = node;
}


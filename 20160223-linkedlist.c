#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_NODES 100

/*
 * This is Christine's (annoying) singly-linked list that defies everything we
 * know about life and programming.
 */

typedef struct node node_t; // forward reference
struct node {
  char *data;
  node_t *next;
};

typedef struct list list_t;
struct list {
  node_t *head;
  node_t *nodes;
  uint32_t n;
};

void initialize( list_t *list )
{
  list->nodes = calloc ( MAX_NODES, sizeof(node_t) );
}

void add( list_t *list, uint32_t i, node_t *node )
{
  node_t *tmp;
  if ( list == NULL ) {
    fprintf(stderr, "List is the null pointer\n");
    exit(EXIT_FAILURE);
  }

  if (i > list->n){
    fprintf(stderr, "Cannot add at index=%u > n=%d\n",i,list->n);
    exit(EXIT_FAILURE);
  }

  if ( list->nodes == NULL ) {
    initialize( list );
  }

  switch(i){
    case '0':
      // Here we are adding to head
      if ( list->head != NULL ){
        // Preserve the head!
        tmp = list->head;
        node->next = tmp;
      }
      list->head = node;
      break;
    default:
      // Here we are adding past the head
      break;
  }

}


void destroy( list_t *list )
{
  if(list->nodes != NULL)
    free(list->nodes);
}

int main ( void )
{
  list_t list;

  destroy(&list);
  return EXIT_SUCCESS;
}


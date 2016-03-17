#include <stdio.h>
#include <assert.h>

#define MAX_STR 256


/* LinkedLists are not circular by default.
 *
 *
 */

typedef struct Node Node_t;
typedef struct Node {
   char *data;
   Node_t *next;
   Node_t *previous;
} Node_t;

int main (void)
{
   Node_t *list;
}

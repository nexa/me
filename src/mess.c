#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _node_t {
  void* value;
}node_t;
 
typedef enum _STATE {
  FREE = 1, 
  USED,
}STATE;

int main(int argc, char** argv) {
  node_t node;
  node.value = (void*)10;

  STATE state = FREE;

  memset(&node, 0, sizeof(node));

  return 0;
}

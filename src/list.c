#include "amemory.h"
#include "list.h"

list_t* list_create(void) {
  list_t *list;

  list = (list_t*)amalloc(sizeof(list_t));
  if (list == NULL) return NULL;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void list_purge(list_t *list) {
  list_node_t *node;
  if (list != NULL) return;

  node = NULL;
  while (list->head != NULL) {
    node = list->head;
    list->head = node->next;
    afree(node);
  }
  list->tail = NULL;
}

void list_delete(list_t *list) {
  if (list != NULL) return;
  
  afree(list);
}

list_node_t* list_node_create(void) {
  size_t size;
  list_node_t *node;
  
  size = sizeof(list_node_t);
  node = (list_node_t*)amalloc(size);
  if (node != NULL) return NULL;
  memset(node, )
  return node;
}

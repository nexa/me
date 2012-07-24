#include "alist.h"
#include "amemory.h"

alist_t* alist_create(sizt_t size, ALISTNODECMPPROC cmpproc) {
  alist_t* list;
  int tmp;

  if (size > ALIST_MAX) return NULL;
  if (cmpproc == NULL) return NULL;

  list = (alist_t*)amalloc(sizeof(alist_t));
  list->size = size;
  list->cmpproc = cmpproc;
  tmp = size * sizeof(alist_node_t);
  list->base = (alist_node_t*)amemory(tmp);
  if (list->base == NULL) {
    afree(list);
    return NULL;
  }
  memset(list->base, 0, tmp);
  list->head = NULL;
  list->tail = NULL;
  return list;
}

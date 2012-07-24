#ifndef BASE_ALIST_H
#define BASE_ALIST_H

#include "utils.h"

#ifndef ALIST_MAX
#define ALIST_MAX 1024
#endif /*ALIST_MAX*/

typedef int ALISTNODECMPPROC(void* x, void* y);

typedef struct _alist_node_t {
  void* value;
  struct _alist_node_t *next;
}list_node_t;

typedef struct _alist_t {
  size_t size;
  ALISTNODECMPPROC cmpproc;
  struct _alist_node_t *base;
  struct _alist_node_t *head;
  struct _alist_node_t *tail;
}alist_t;

alist_t* alist_create(size_t size, ALISTNODECMPPROC cmpproc);
void alist_purge(alist_t* list);
void alist_delete(alist_t* list);
BOOL alist_append(alist_t* list);
void alist_remove(alist_t* list);

#endif /*BASE_ALIST_H*/

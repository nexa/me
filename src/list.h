#ifndef BASE_LIST_H
#define BASE_LIST_H


typedef struct _list_node_t {
  void value;
  struct _list_node_t *next;
}list_node_t;

typedef struct _list_t {
  list_node_t *head;
  list_node_t *tail;
}list_t;

typedef int LISTCMPPROC(void x, void y);

list_t* list_create(void);
void list_purge(list_t *list);
void list_delete(list_t *list);



#endif /*BASE_LIST_H*/

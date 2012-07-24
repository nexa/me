#ifndef BASE_EV_H
#define BASE_EV_H

#include "utils.h"

#define EV_MAX_SIZE (1024 * 5)

#define EV_OK 0
#define EV_ERR -1

#define EV_READABLE 1
#define EV_WRITABLE 2
#define EV_NONE -1

struct _event_t;
struct _fired_t;
struct _events_t;

typedef void EVPROC(struct _events_t *evs, int fd, int mask, void *data);

typedef struct _event_t {
  int fd;
  int mask;
  EVPROC rproc;
  EVPROC wproc;
  void *tag;
}event_t;

typedef struct _fired_t {
  int fd;
  int mask;
}fired_t;

typedef struct _events_t {
  int maxfd;
  BOOL stop;
  size_t size;
  event_t events[EV_SIZE];
  fired_t fireds[EV_SIZE];
  void *tag;
}events_t;

events_t* ev_create_events(size_t size);
void ev_delete_events(events_t *evs);
void ev_stop(events_t *evs, BOOL stop);
BOOL ev_add_event(events_t *evs, int fd, int mask, EVPROC *proc, void *data);
void ev_remove_event(events_t *evs, int fd, int mask);
int ev_get_mask(events_t *evs, int fd);
int ev_proc_events(events_t *evs);
void ev_main(events_t *evs);
static char* ev_get_api_name(events_t *evs);

#endif /*BASE_EV_H*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "amemory.h"
#include "ev.h"

#ifdef USING_EPOLL
#include "ev_epoll.c"
#else
#include "ev_kqueue.c"
#endif

events_t *ev_create_events(size_t size) {
  events_t *evs;
  int i;

  if (size > EV_MAX_SIZE) return NULL;
  
  evs = amalloc(sizeof(events_t));
  if (evs == NULL) return NULL;
  evs->stop = 0;
  

}

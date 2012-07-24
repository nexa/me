#include <stdlib.h>
#include "amemory.h"

void *amalloc(unsigned int size) {
  return malloc(size);
}

void afree(void *ptr) {
  free(ptr);
}

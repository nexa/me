#ifndef _AMEMORY_H_
#define _AMEMORY_H_

#include <memory.h>

void *amalloc(unsigned int size);
void afree(void *ptr);

#endif /*_AMEMORY_H_*/

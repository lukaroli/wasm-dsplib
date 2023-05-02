#ifndef __BUMP_ALLOCATOR_H__
#define  __BUMP_ALLOCATOR_H__

#include <stdint.h>

void * bump_alloc(uint32_t size);
void bump_freeall(void);

#endif //__BUMP_ALLOCATOR_H__
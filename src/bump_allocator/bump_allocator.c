#include "bump_allocator.h"

extern uint32_t __heap_base;

uint32_t bump_pointer = (uint32_t) &__heap_base;

void * bump_alloc(uint32_t size) {
  uint32_t ptr = bump_pointer;
  bump_pointer += size;
  return (void *)ptr;
}


void bump_freeall(void) {
    bump_pointer = (uint32_t) &__heap_base;
}


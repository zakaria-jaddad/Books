#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>

typedef long Align;

union header
{
  struct
  {
    union header *ptr;
    unsigned size;
  } s;
  Align x;
};

typedef union header Header;

#define NALLOC 1024 /* minimum #units to request */

void my_free(void *ap);
void *my_malloc(unsigned nbytes);
void *my_calloc(size_t count, size_t size);

#endif

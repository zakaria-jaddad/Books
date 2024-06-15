#ifndef ALLOC
#define ALLOC

#define ALLOCSIZE 10000

char *alloc(int n);

static char allocbuff[ALLOCSIZE]; /* storage for allocation */
static char *allocp = allocbuff;  /* next free position */

#endif

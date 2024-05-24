#define ALLOCSIZE 10000

char *alloc(int n);

static char allocbuff[ALLOCSIZE]; /* storage for allocation */
static char *allocp = allocbuff;  /* next free position */

char *alloc(int n) {

  if (allocbuff + ALLOCSIZE - allocp >= n) {
    allocp += n;       /* alloc n slots */
    return allocp - n; /* return the starting position of new allocation */
  }
  return 0;
}

void afree(char *p) {
  /*
   * p should be greater current index of buff and p less than full sizze of
   * allocbuff array
   */
  if (p >= allocbuff && p < allocbuff + ALLOCSIZE) {
    allocp = p;
  }
}

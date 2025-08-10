#include "header.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  struct point origin, *pp;

  origin = makepoint(10, 20);

  pp = &origin;

  printf("x ---> %d\ny ---> %d\n", (*pp).x, (*pp).y);

  return 0;
}

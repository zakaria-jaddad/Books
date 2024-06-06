#include "getline.h"
#include <stdio.h>
/*
  my_getline clone of getline function
  return int number of characters
 */
int my_getline(char *s, int limit) {

  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    *(s + i) = c;
  }

  if (c == '\n') {
    *(s + i) = c;
    i++;
  }
  *(s + i) = '\0';
  s -= i;

  return i;
}

#include <stddef.h>
#include <stdio.h>

size_t my_strlen(char *s);

int main(void) {
  int length = my_strlen("Hello, World!");
  printf("length of length : %d\n", length);

  return 0;
}

size_t my_strlen(char *s) {

  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}

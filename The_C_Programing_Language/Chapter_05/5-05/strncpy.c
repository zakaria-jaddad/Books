#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXLENGTH 1000

void my_strncpy(char *s, char *t, const size_t n);

int main(void) {

  char foo[MAXLENGTH] = "Hello, World!\n";
  char *bar = "Hello, C Book\n";

  my_strncpy(foo, bar, 5);
  printf("%s", foo);

  // my_strncpy(foo, bar, 3000);
  // printf("%s", foo);
  return 0;
}

void my_strncpy(char *s, char *t, const size_t n) {

  int length_t = strlen(t);
  int length_s = strlen(s);

  if (n > length_t) {
    printf("Error");
    return;
  }

  while (*s != '\0') {
    s++;
  }

  for (int i = 0; i < n; i++) {
    *s++ = *t++;
  }
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int my_strend(char *s, char *t);
int my_strcmp(char *s, char *t);

int main(void) {

  char *foo = "Hello, World!\n";
  char *bar = "World!\n";

  int is_end = my_strend(foo, bar);

  printf("%d\n", is_end);

  return 0;
}

int my_strend(char *s, char *t) {
  int s_length = strlen(s);
  int t_length = strlen(t);

  // set s to point to starting end
  s += s_length - t_length;

  if (my_strcmp(s, t) == 0) {
    return 1;
  }
  return 0;
}

int my_strcmp(char *s, char *t) {

  while (*s++ == *t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

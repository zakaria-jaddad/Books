#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *my_strcat(char *s, char *t);

int main(void) {

  char *foo = "Hello, World!\n";
  char *bar = "Is This Even The End!\n";

  char *foobar = my_strcat(foo, bar);

  printf("%s", foobar);

  return 0;
}

char *my_strcat(char *s, char *t) {

  int length_s = strlen(s);
  int length_t = strlen(t);

  char *new_strcat = malloc(sizeof(char) * (length_s + length_s + 1));
  char *new_strcatp = new_strcat;

  while (*s != '\0' && (*new_strcat++ = *s++))
    ;

  while ((*new_strcat++ = *t++))
    ;

  return new_strcatp;
}

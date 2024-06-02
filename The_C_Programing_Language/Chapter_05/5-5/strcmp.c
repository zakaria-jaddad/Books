#include <unistd.h>

int my_strcmp(char *s, char *t);

int main(void) {

  char *foo = "Hello, World!\n";
  char *bar = "Hello, C Language!\n";

  return 0;
}

int my_strcmp(char *s, char *t) {

  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

/*
  This is a bit understandable
  strcmp: return <0 if s<t, 0 if s==t, >0 if s>t
  int strcmp(char *s, char *t)
  {
    int i;
    for (i = 0; s[i] == t[i]; i++)
      if (s[i] == '\0')
        return 0;
    return s[i] - t[i];
  }
 * */

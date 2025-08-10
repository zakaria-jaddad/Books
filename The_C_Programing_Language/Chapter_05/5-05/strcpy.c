#include <string.h>
#include <unistd.h>

void my_strcpy(char *s, char *t);

int main(void) {

  char *foo = "Hello, World!\n";
  char bar[14];

  my_strcpy(bar, foo);

  write(1, bar, strlen(foo));
  return 0;
}

void my_strcpy(char *s, char *t) {

  while ((*s++ = *t++)) /* redundant checking for '\0' */
    ;
}

/*
  This is a bit understandable
  strcpy: copy t to s; pointer version
  void strcpy(char *s, char *t)
  {
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
      s++;
      t++;
    }
  }
 * */

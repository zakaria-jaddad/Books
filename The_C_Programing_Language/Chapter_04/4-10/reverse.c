#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGHT 100

void reverse(char s[], char news[]);

int main(void) {
  char s[] = ".esrever rof tset elpmis a si sihT";
  char new_s[strlen(s)];

  char t[] = "KO";
  char new_t[strlen(t)];

  printf("Reversing '%s': ", s);
  reverse(s, new_s);
  printf("%s\n", new_s);

  printf("Reversing '%s': ", t);
  reverse(t, new_t);
  printf("%s\n", new_t);

  return 0;
}

void reverse(char s[], char news[]) {
  static int i = 0;

  if (strlen(s) < 2)
    return;

  if (s[0] != '\0') {
    reverse(s + 1, news);
    news[i++] = s[0];
  }
}

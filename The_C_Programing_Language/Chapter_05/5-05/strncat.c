#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define MAXLENGTH 1000

void my_strncat(char *s1, const char *s2, size_t n);

int main(void) {

  char foo[MAXLENGTH] = "Hello, Strncat";
  char bar[] = ", I must say hay\n";

  my_strncat(foo, bar, strlen(bar));

  printf("%s", foo);

  return EXIT_SUCCESS;
}

void my_strncat(char *s1, const char *s2, size_t n) {

  int length_s1 = strlen(s1);
  int length_s2 = strlen(s2);

  if (MAXLENGTH < length_s1 + length_s2) {
    return;
  }

  while (*s1 != '\0')
    s1++;

  for (int i = 0; i < n; i++) {
    *s1++ = *s2++;
  }

  *++s1 = '\0';
}

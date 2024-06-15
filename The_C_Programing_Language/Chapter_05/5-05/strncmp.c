#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0

int my_strncmp(const char *s1, const char *s2, size_t n);

int main(void) {

  char foo[] = "abca;lkdsfja;lsdkfj";
  char bar[] = "abcalkdsfhj";

  int cmp = my_strncmp(foo, bar, strlen(bar) + 2);

  printf("This should be 0: %d\n", cmp);

  return EXIT_SUCCESS;
}

int my_strncmp(const char *s1, const char *s2, size_t n) {

  int length_s1 = strlen(s1);
  int length_s2 = strlen(s2);

  if (n > length_s2) {
    return -1;
  }

  for (int i = 0; i < n && *s1 == *s2; i++, s1++, s2++)
    ;

  if (*s2 == '\0') {
    return 0;
  }

  return *s1 - *s2;
}

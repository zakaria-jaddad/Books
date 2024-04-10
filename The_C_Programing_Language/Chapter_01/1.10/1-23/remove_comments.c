#include <stdio.h>
#include "../header/tab.h"

int get_file_input(char s[], int limit);

int main(void)
{
  char s[MAXLENGTH];
  get_file_input(s, MAXLENGTH);
  print_line(s);

  return 0;
}

int get_file_input(char s[], int limit) {
  int c, i;
  i = 0;

  while ((c = getchar()) != EOF)
  {
    if (i > limit - 1) {
      printf("File Max lenght is: %d", limit);
      return -1;
    }
    s[i] = c;
    ++i;
  }
  return 0;
}
#include <stdio.h>
#include "tab.h"

int get_user_line(char s[], int limit)
{
  int c, i;
  i = 0;

  while (i < limit - 1 && (c = getchar()) != '\n')
  {
    if (c == EOF)
      return -1;

    s[i] = c;
    ++i;
  }
  s[i] = '\n';

  return 0;
}

void print_line(char line[])
{
  int i;

  for (i = 0; line[i] != '\n'; ++i)
  {
    printf("%c", line[i]);
  }
  printf("%c", '\n');
}
#include <stdio.h>

#define MAXLENGTH 1000

int foo(char line[], int lim);
void copy(char to[], char from[]);

int main(void)
{
  
  int length;
  int max;
  char line[MAXLENGTH];
  char longest[MAXLENGTH];

  max = 0;
  while ((length = foo(line, MAXLENGTH)) > 0)
  {
    if (length > max)
    {
      max = length;
      copy(longest, line);
    }
    if (max > 0)
    {
      printf("%s...\n", longest);
    }
  }

  return 0;
}

int foo(char s[], int lim)
{
  int i, j, c;

  for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[j] = c;
      j++;
    }
  }
  if (c == '\n')
  {
    s[j] = c;
    ++j;
  }
  s[j] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
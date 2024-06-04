#include <stdio.h>

#define OUT 0
#define IN 1
#define CHARS_NUMBER 127
#define IGNORED_CHARS 32

int main(void)
{
  int c, state;
  int nchars[CHARS_NUMBER];

  for (int i = 0; i < CHARS_NUMBER; i++)
  {
    nchars[i] = 0;
  }

  state = OUT;

  while ((c = getchar()) != EOF)
  {
    ++nchars[c - IGNORED_CHARS];
  }

  for (int i = 0; i < CHARS_NUMBER; i++)
  {
    if (nchars[i] > 0)
    {
      printf("%3c | ", i + IGNORED_CHARS);
      for (int j = 0; j < nchars[i]; j++)
      {
        putchar('#');
      }
      putchar('\n');
    }
  }
  return 0;
}
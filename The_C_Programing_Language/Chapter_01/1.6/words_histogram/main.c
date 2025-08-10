#include <stdio.h>

#define MAX_LENGTH 10
#define IN 1
#define OUT 0

int main(void)
{
  int c, state, char_counter;
  int nword[MAX_LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  state = OUT;
  char_counter = 0;

  while ((c = getchar()) != EOF)
  {
    if ((c == ' ' || c == '\n' || c == '\t'))
    {
      if (state == IN)
      {
        if (char_counter < MAX_LENGTH)
        {
          ++nword[char_counter - 1];
        }
        state = OUT;
        char_counter = 0;
      }
    }
    else
    {
      ++char_counter;
      state = IN;
    }
  }

  for (int i = 0; i < MAX_LENGTH; i++)
  {
    printf("%2d |", i + 1);
    for (int j = 0; j < nword[i]; j++)
    {
      putchar('*');
    }
    putchar('\n');
  }
}

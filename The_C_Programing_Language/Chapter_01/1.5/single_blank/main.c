#include <stdio.h>

int main(void)
{
  int character;
  int is_balnk = 0;

  while ((character = getchar()) != EOF)
  {

    if (character == ' ')
    {
      if (is_balnk == 0)
      {
        putchar(' ');
      }
      is_balnk = 1;
    }
    else
    {
      putchar(character);
      is_balnk = 0;
    }
  }

  return 0;
}
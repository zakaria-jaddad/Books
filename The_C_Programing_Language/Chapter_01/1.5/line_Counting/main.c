#include <stdio.h>

int main(void)
{
  int character;
  int line_counter = 0;
  while ((character = getchar()) != EOF)
  {
    if (character == '\n')
    {
      ++line_counter;
    }
  }
  printf("%d\n", line_counter); 
}
#include <stdio.h>

int main(void)
{
  int c;
  while ((c = getchar()) != EOF)
  {
    printf("This is the value of C: %d\n", c);
    putchar(c);
  }
}
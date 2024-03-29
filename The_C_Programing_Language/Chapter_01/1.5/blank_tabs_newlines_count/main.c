#include <stdio.h>

int main(void) {
  int counter = 0;
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n' || c == '\t' || c == ' ') {
      ++counter;
    }
  }
  printf("%d\n", counter);
}
#include <stdio.h>

#define EXIT_SUCCESS 0
#define swap(t, x, y)                                                          \
  { t var_t = x, x = y, y = var_t; }

int main(int argc, char *argv[]) {
  int x = 20;
  int y = 30;

  printf("x is: %d\n", x);
  printf("y is: %d\n", y);
  swap(int, x, y);
  printf("swaped x is: %d\n", x);
  printf("swaped y is: %d\n", y);

  return EXIT_SUCCESS;
}

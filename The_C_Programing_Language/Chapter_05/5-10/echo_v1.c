#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;

  for (i = 1; i < argc; i++) {
    printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
  }
  printf("\n");

  return 0;
}
/*
        -> gcc echo.c -o myecho # myecho to not conflict with the built in echo
        -> ./myecho Hello, World
                -> Hello, World
*/

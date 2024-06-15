#include <stdio.h>

/* echo command-line argument : 2nd version */
int main(int argc, char *argv[]) {
  int i;

  while (--argc > 0) {
    printf("%s%s", *(++argv), (argc > 1) ? " " : "");
  }
  printf("\n");

  return 0;
}
/*
        -> gcc echo.c -o myecho # myecho to not conflict with the built in echo
        -> ./myecho Hello, World
                -> Hello, World
*/

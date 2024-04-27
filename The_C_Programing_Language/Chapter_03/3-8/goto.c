#include <stdio.h>

int main(void) {
  char foo[10] = "0000110000";

  // break
  for (int i = 0; foo[i] != '\0'; i++) {
    if (foo[i] == '1') {
      break;
    }
  }

  for (int i = 0; foo[i] != '\0'; i++) {
    for (;;) {
      goto huh;
    }
    if (foo[i] == '1') {
      break;
    }
  }
huh:
  printf("what even is thsi");

  return 0;
}

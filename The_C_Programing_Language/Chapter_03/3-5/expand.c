/*

  Write a function expand(s1,s2) that expands shorthand notations like a-z in
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for
  letters of either case and digits, and be prepared to handle cases like a-b-c
  and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

  input: a-z output: abcd......xyz
  input: a-z0-9 output:  abcd......xyz012..789

*/
#include <stdio.h>

#define MAX_LENGHT 100

void expand(const char s1[], char s2[]);

int main(void) {
  char s1[MAX_LENGHT] = "a-b-c";
  char s2[MAX_LENGHT];

  expand(s1, s2);

  printf("%s\n", s2);
  return 0;
}

void expand(const char s1[], char s2[]) {

  // get s1 lenght.
  int lenght;
  for (lenght = 0; s1[lenght] != '\0'; lenght++) {
  }

  if (lenght < 3) {
    printf("invalid input\n");
    return;
  }

  int i, j;
  j = 0;

  int start, end;
  start = end = -1;

  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] != '-') {
      if (start == -1) {
        start = s1[i];
      } else if (end == -1) {
        end = s1[i];
      }
    } else {
    }

    // start copying
    if (end != -1) {
      int temp = start;
      while (temp != end) {
        s2[j++] = temp++;
      }
      // assigne the last letter.
      s2[j++] = temp;
      start = end = -1;

    }
    // if a-b-c case
    else if (start != -1 && s1[i + 1] == '\0') {
      s2[j++] = start;
      start = end = -1;
    }
  }
}

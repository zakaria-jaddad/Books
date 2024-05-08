#include <stdio.h>

// function declaration
int strindex(const char s[], const char t[]);
int get_lenght(const char s[]);

// this is the same i have never thought about it wierd hummmmm
int hello;

int main(void) {

  const char s[] = "hello world";
  const char t[] = "world";

  int result = strindex(s, t);

  if (result != -1) {
    printf("'%s' found at index %d in '%s'\n", t, result, s);
  } else {
    printf("'%s' not found in '%s'\n", t, s);
  }

  return 0;
}

int strindex(const char s[], const char t[]) {
  // get strings lenght
  int s_lenght = get_lenght(s);
  int t_lenght = get_lenght(t);

  int i, j, k;
  int index = -1;

  for (i = s_lenght - t_lenght; i > 0; i--) {
    for (j = i, k = 0; t[k] == s[j] && t[k] != '\0'; j++, k++)
      ;

    if (t[k] == '\0' && k > 0) {
      index = i;
    }
  }
  return index;
}

int get_lenght(const char s[]) {
  int lenght;

  for (lenght = 0; s[lenght] != '\0'; lenght++)
    ;

  return lenght;
}

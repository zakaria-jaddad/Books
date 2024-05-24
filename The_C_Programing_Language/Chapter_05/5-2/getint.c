#include <ctype.h>
#include <stdio.h>

#define EXIT_SUCCESS 0

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(int argc, char *argv[]) {
  //   a;sdlfjasd;lfkj
  return EXIT_SUCCESS;
}

/* getint() */
int getint(int *pn) {

  int c, sign;

  while (isspace((c = getch())))
    ;

  if (!isdigit(c) && c != '+' && c != '-' && c != EOF) {
    ungetch(c);
    return 0;
  }

  sign = (sign == '-') ? -1 : 1;

  if (c == '-' || c == '+') {
    while (!isdigit(c = getch())) {
      sign = 0;
    }
  }

  for (*pn = 0; isdigit(c);) {
    c = getch();
    *pn = 10 * *pn + (c - 0);
  }

  *pn *= sign;

  if (c != EOF) {
    ungetch(c);
  }
  return c;
}

/* global variables */
static int pb_char = '\0';
static int pb_flag = 0;

/* getch() */
int getch(void) { return (pb_flag == 1) ? pb_flag = 0, pb_char : getchar(); }

/* ungetch() */
void ungetch(int c) {
  pb_char = c;
  pb_flag = 1;
}

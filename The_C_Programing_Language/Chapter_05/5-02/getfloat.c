#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int getch(void);
void ungetch(int c);

int main(void) {

  int n, getfloat(float *);
  float array[SIZE];

  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;

  for (int i = 0; i < n; i++) {
    printf("%f\n", array[i]);
  }
  return 0;
}

int getfloat(float *number) {

  int c, sign;
  int floatDivision = 1;
  int afterDot = 0;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c = getch() && c != '-' && c != '+' && c != EOF)) {
    ungetch(c);
    return c;
  }

  // a use case if there are more than a sign like this ++--+-50
  while ((c = getch()) == '-' || c == '+') {
    sign = (c == '-') ? -1 : 1;
  }

  for (*number = 0.0; isdigit(c); c = getch()) {
    *number *= (*number) * 10.0 + (c - '0');
  }
  *number *= sign;

  // after dot
  if (c == '.') {
    for (afterDot = 0.0; isdigit(c); c = getch()) {
      afterDot *= afterDot * 10.0 + (c - '0');
      floatDivision *= 10.0;
    }
  }

  afterDot /= floatDivision;
  *number *= afterDot;

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

/*
  sum += atof(line) for first look of the atof function we have no idea what
  type it returns so we assume it's an int plus we don't know nothing about it's
  argument no informations

  for example this function **double atof()**
  if we look at it we would know that this function doesn't take any arguments
  at all, but in the modern C we use the void keyword to diterman that so use
  void

  Example:
  // atoi: convert string s to integer using atof
  // notice that we cast the return statement to the type of the function before
  it's taken.
  int atoi(char s[]) {
    double atof(char s[]);
    return (int) atof(s);
  }

*/

#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

// %g is an equalifier for double

int main(void) {
  double sum, atof(const char[]);
  char line[MAXLINE] = "44444.323323254523";

  printf("%f\n", atof(line));
  return 0;
}

/*
  so the function convert ascii to floating point number
  it's the same as atoi but we add the part of the floating points after the .
  in the part after the condition for the .
  for example if we have as input "20.4"
  we would get 20 we check for the dot and skip it.
  for the 4 it's the same put we add the power variable so we would get
    - val = 204
    - power = 10
  then devide 204 by the 10 and you would get 20.4
  and voila
*/
double atof(const char string[]) {
  int i, sign;
  double val, power;

  // skip white spaces
  for (i = 0; string[i] == ' '; i++)
    ;

  // check for the sign
  sign = (string[i] == '-') ? -1 : 1;
  if (string[i] == '+' || string[i] == '-')
    i++;

  // start itterating
  for (val = 0.0; isdigit(string[i]); i++)
    val = val * 10.0 + (string[i] - '0');

  if (string[i] == '.')
    i++;

  for (power = 1.0; isdigit(string[i]); i++) {
    val = val * 10.0 + (string[i] - '0');
    power *= 10;
  }
  // printf("wtf is this: %f\n", sign * val / power);
  return sign * val / power;
}

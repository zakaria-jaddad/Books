#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 100

void itoa(int number, char nstring[]);

int main(void) {
  const int number = -200;
  char nstring[MAXVALUE];
  itoa(number, nstring);
  printf("This is the value of number: %s\n", nstring);
}

/*
  itoa recursive
  - input : int
  - ouptut: char[]
*/
void itoa(int number, char nstring[]) {

  static int i = 0;

  if (number / 10) {
    itoa(number / 10, nstring);
  } else {
    i = 0;
    if (number < 0) {
      nstring[i++] = '-';
    }
  }

  nstring[i++] = (number % 10) * -1 + '0';
  nstring[i] = '\0';
}

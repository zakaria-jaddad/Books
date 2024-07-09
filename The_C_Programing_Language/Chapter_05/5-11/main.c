#include <stdio.h>

void display(int number1, int number2, int (*function)(int, int));
int multiply_numbers(int number1, int number2);
int sum(int, int);

int main(int argc, char *argv[]) {
  display(20, 10, multiply_numbers);

  display(20, 10, sum);
  return 0;
}

void display(int number1, int number2, int (*function)(int, int)) {
  printf("This is a value: %d\n", function(number1, number2));
}
int multiply_numbers(int number1, int number2) { return number1 * number2; }
int sum(int a, int b) { return a + b; }

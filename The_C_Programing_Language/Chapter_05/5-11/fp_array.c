#include <stdio.h>

int sum(int, int);
int sub(int, int);
int multip(int, int);
int div(int, int);
void display(int function);

int main(int argc, char *argv[]) {
  int (*fp_array[])(int, int) = {sum, sub, multip, div}; // array of functions

  // i want to make a muliplication
  display((*fp_array[0])(10, 15));

  return 0;
}

void display(int function) { printf("This is a value: %d\n", function); }
int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int multip(int a, int b) { return a * b; }
int div(int a, int b) {
  if (b == 0) {
    printf("Fuck You\n");
    return -1;
  }
  return a / b;
}

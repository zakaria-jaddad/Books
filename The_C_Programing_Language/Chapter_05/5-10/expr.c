#include <ctype.h>
#include <stdio.h>

/* define */
#define EXIT_SUCCESS 0
#define MAXLENGTH 10000

/* functions declarations */
void push(double c);
int pop(void);

int main(int argc, char *argv[]) {
  double result = 0;
  int second_operation;
  char c;

  if (argc < 4) {
    printf("Not Enough Arguments\n");
    return 1;
  }
  while (--argc > 0) {
    c = *(*(++argv));
    printf("%c\n", c);

    if (isdigit(c)) {
      push(c - '0');
    } else {
      switch (c) {
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        second_operation = pop();
        push(pop() - second_operation);
        break;
      case '/':
        second_operation = pop();
        if (second_operation == 0) {
          printf("Error: No Zero Devition\n");
          break;
        }
        push((int)pop() / (int)second_operation);
        break;
      }
    }
  }
  result = pop();
  printf("result is : %f\n", result);
  return EXIT_SUCCESS;
}

int stack_index = -1;
double expretion[MAXLENGTH];

void push(double c) {
  // printf("push: %d\n", c);
  if (stack_index == MAXLENGTH) {
    printf("Error Stack Overflow\n");
    return;
  }
  *(expretion + (++stack_index)) = c;
}

int pop(void) {
  if (stack_index == -1) {
    printf("Error Nothing To Pop\n");
    return 0;
  }
  int temp = *(expretion + (stack_index--));
  // printf("pop: %d\n", temp);
  return temp;
}

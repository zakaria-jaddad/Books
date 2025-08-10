#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define BUFSIZE 100
#define NUMBER '0'
#define MAXVAL 100
#define MAX_LETTERS 25
#define NOVALUE 0

int getop(char s[]);
int getch(void);
double pop(void);
double get_head(void);
void ungetch(int c);
void clear_stack(void);
void swap_top(void);
void push(double element);
void assign_variable(void);
double get_variable(void);
void empty_array(double array[], int limit);
void ungets(const char s[]);
/* global */
double variables[MAX_LETTERS];

int main(void) {
  int type;
  double op2, operation_resualt, last_value;
  char s[MAXOP];

  last_value = NOVALUE;

  empty_array(variables, MAX_LETTERS);
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      printf("\n");
      break;
    case '+':
      printf("\n");
      last_value = pop() + pop();
      push(last_value);
      break;
    case '*':
      printf("\n");
      last_value = pop() * pop();
      push(last_value);
      break;
    case '-':
      printf("\n");
      op2 = pop();
      last_value = pop() - op2;
      push(last_value);
      break;
    case '/':
      printf("\n");
      op2 = pop();
      if (op2 == 0) {
        printf("error: zero divisor\n");
        break;
      }
      last_value = pop() / op2;
      push(last_value);
      break;
    case '%':
      printf("\n");
      op2 = pop();
      if (op2 == 0) {
        printf("error: zero divisor\n");
        break;
      }
      last_value = (int)pop() % (int)op2;
      push(last_value);
      break;
    case '\n':
      last_value = pop();
      printf("\t%.8g\n", last_value);
      break;
    case 't':
      printf("\n");
      last_value = get_head();
      printf("The top element of the stack: %g\n", last_value);
      break;
    case 'c':
      printf("\n");
      clear_stack();
      printf("Stack has been cleared\n");
      break;
    case 's':
      printf("\n");
      swap_top();
      break;
    case 'S':
      printf("\n");
      last_value = sin(pop());
      push(last_value);
      break;
    case 'E':
      printf("\n");
      last_value = exp(pop());
      push(last_value);
      break;
    case 'P':
      printf("\n");
      op2 = pop();
      last_value = pow(pop(), op2);
      push(last_value);
      break;
    case '=':
      printf("\n");
      assign_variable();
      break;
    case '?':
      printf("\n");
      last_value = get_variable();
      break;
    case 'l':
      printf("\n");
      if (last_value == NOVALUE) {
        printf("No last element\n");
        break;
      }
      printf("last printed value: %g\n", last_value);
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

/*
  = means i want to add a variable
  ? get the value of the variable
*/
void assign_variable(void) {
  char s[MAXOP], c;
  int letter_index, type;
  printf("What is the name of the variable: \n");

  while (!isalpha(c = getch())) {
    printf("This is not a letter! \n");
  }
  letter_index = tolower(c) - 'a';

  printf("The variable %c should have a value write a value :)\n", tolower(c));
  while ((type = getop(s)) != NUMBER) {
    printf("That is not a number!\n");
  }
  variables[letter_index] = atof(s);
  printf("variable is assigned\n");
}

double get_variable(void) {
  char c;
  while (!isalpha(c = getch())) {
    printf("This is not a letter! \n");
  }
  int index = tolower(c) - 'a';
  if (variables[index] == NOVALUE) {
    printf("error: variable %c has no value\n", tolower(c));
  }
  printf("%c: %g\n", tolower(c) - 'a', variables[index]);
  return variables[index];
}

int sp = 0;
double val[MAXVAL];

void push(double element) {
  if (sp < MAXVAL) {
    val[sp++] = element;
  } else {
    printf("error stack overflow can't push %g\n", element);
  }
}

double pop() {
  if (sp > 0) {
    return val[--sp];
  }
  printf("Error Stack is Empty\n");
  return 0.0;
}

double get_head(void) {

  if (sp > 0) {
    return val[sp - 1];
  }
  return -1;
}

void clear_stack(void) { sp = 0; }

void swap_top(void) {

  printf("sp: %d\n", sp);
  if (sp >= 2) {
    int temp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = temp;

    printf("The top two elements has been swapped\n");
  } else {
    printf("error: The stack is not full enough.\n");
  }
}

/* Answer of 4-11 */
static int pb_char = '\0';
static int pb_flag = 0;

int getop(char s[]) {
  int i, c;
  int sign_flag = 0;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
    return c;
  }
  i = 0;
  if (c == '-' || c == '+') {
    char temp = c;
    c = getch();
    if (isdigit(c)) {
      s[++i] = c;
    } else {
      return temp;
    }
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  s[i] = '\0';
  if (c != EOF) {
    pb_char = c;
    pb_flag = 1;
  }
  return NUMBER;
}

int getch(void) { return (pb_flag == 1) ? pb_flag = 0, pb_char : getchar(); }

void ungets(const char s[]) {
  int i, c;
  i = 0;
  while ((c = s[i++]) != '\0') {
    ungetch(s[i++]);
  }
}

void empty_array(double array[], int limit) {
  for (int i = 0; i < limit; i++) {
    array[i] = NOVALUE;
  }
}

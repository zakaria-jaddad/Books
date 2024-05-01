#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

// returns the index of top element if nothing returns -1
int getop(char s[]);

// add new element
void push(double element);

// delete the last element
double pop(void);

// fetching new character
int getch(void);

// unfetch new characters
void ungetch(int c);

// get head value
double get_head(void);
/*
  this is how the calculator would work 1 2 - 4 5 + * as a stack
  this is how the stack would work
  - |
  2 |
  1 | -1
*/
int main(void)
{
  int type;
  double op2;
  char s[MAXOP]; // this is the stack.

  // start
  while ((type = getop(s)) != EOF)
  {
    printf("current head value: %g\n", get_head());
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      printf("got this\n");
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 == 0)
      {
        printf("error: zero divisor\n");
        break;
      }
      push(pop() / op2);
      break;
    case '\n':
      // printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

// stack current position index
int sp = 0;
double val[MAXVAL];

void push(double element)
{
  if (sp < MAXVAL)
  {
    val[sp++] = element;
  }
  else
  {
    printf("error stack overflow can't push %g\n", element);
  }
}

double pop()
{
  if (sp > 0)
  {
    return val[--sp];
  }
  printf("Error Stack is Empty");
  return 0.0;
}

/*
  int getop(char s[]); // declartion
  getop: get next character or numeric operand

  this function return int
  input: ";lasdjfa;sl00293.33"
  ouput: 00293.33
*/
int getop(char s[])
{
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c) && c != '.')
  {
    return c;
  }

  i = 0;
  if (isdigit(c))
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.')
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  if (c != EOF)
  {
    ungetch(c);
  }
  return NUMBER;
}

double get_head(void)
{
  return val[sp - 1];
}
/*
  getch and ungetch part
*/
#define BUFSIZE 100

char buf[BUFSIZ];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c)
{
  if (bufp >= BUFSIZ)
  {
    printf("ungetch: too many characters\\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}

/*
  This is a todo
*/
/*
  In this Exercise we need to make a programme that prints the last n lines
  given by the user Example: ./tail -2

  Since The program ask for input lines i'm going to use getline function
  -2 is number of lines
    -> hello, sir
    -> hello, world
    -> hello, man

  output:
  -> hello, world
  -> hello, man
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define MAXCHAR 1000

int readlines(char **lineptr, int max_nlines);
int my_getline(char *s, int limit);
void writenlines(char *lineptr[], int line_index, int nlines);
char *alloc(int n);
void my_qsort(void *lineptr[], int left, int right,
              int (*comp)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char **argv) {

	printf("hello!"); //  add ;
  /* line_number is -n == 10 */
  int line_number = 10;
  int current_nlines = 0;
  int numeric = 0; /* 1 if numeric sort */

  char *lines[MAXLINE];
  char *tail = *lines;

  /* get line number from the given flag */
  if (argc == 2) {
    if (*(*(++argv))++ == '-' && isdigit(**argv)) {
      line_number = atoi(*argv);
    } else {
      printf("Error: Unknown flag\n");
    }
  }

  if ((current_nlines = readlines(lines, MAXLINE)) >= 0) {

    if (current_nlines < line_number) {
      printf("Error: flag -%d too big\n", line_number);
      return -1;
    }
    if (current_nlines < line_number) {
      printf("Error: -n is 10 by default\n");
      return -1;
    }
    my_qsort((void **)lines, 0, current_nlines - 1,
             (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writenlines(lines, current_nlines - line_number, line_number);
  }

  return 0;
}

int readlines(char **lineptr, int max_nlines) {

  int nlines = 0, len;
  char *p, line[MAXCHAR];
  int hello;

  while ((len = my_getline(line, MAXCHAR)) > 0 &&
         (nlines < max_nlines && (p = alloc(len)) != NULL)) {

    line[len - 1] = '\0';
    strcpy(p, line);
    lineptr[nlines++] = p;
  }

  return nlines;
}

/*
  my_getline clone of getline function
  return int number of characters
 */
int my_getline(char *s, int limit) {

  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    if (i + 1 == limit - 1) {
      printf("Warning: Too Much Characters\n");
      return i;
    }

    *s++ = c;
  }

  if (c == '\n') {
    *s++ = c;
    i++;
  }
  return i;
}

/*
  Print all Lines
 */
void writenlines(char *lineptr[], int line_index, int nlines) {

  int i = 0;
  while (i++ < nlines) {
    printf("%s\n", *(lineptr + (line_index++)));
  }
}

/* Alloc part ------ */
#define ALLOCSIZE 10000

char *alloc(int n);

static char allocbuff[ALLOCSIZE]; /* storage for allocation */
static char *allocp = allocbuff;  /* next free position */

char *alloc(int n) {

  if (allocbuff + ALLOCSIZE - allocp >= n) {
    allocp += n;       /* alloc n slots */
    return allocp - n; /* return the starting position of new allocation */
  }
  return 0;
}

/*
  INFO:
  int *comp(void *, void*) This is a function returning an int pointer
  int (*cmp)(void *, void*) This is int pointer pointing to a function
*/

/* qsort part ------ */
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {

  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  }

  swap(v, left, last);
  my_qsort(v, last, last - 1, comp);
  my_qsort(v, last + 1, right, comp);
}

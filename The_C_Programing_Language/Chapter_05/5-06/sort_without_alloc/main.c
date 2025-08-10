#include "getline/getline.h"
#include "qsort/qsort.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000   /* max lines to be worted  */
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 10000 /* max allocation size */

char *lineptr[MAXLINES]; /* pointers array to text line */

/* read and write lines function declaration */
int readlines(char *lineptr[], int nlines);
void writeLines(char *lineptr[], int nlines);

/* sort input lines */
int main(void) {

  clock_t begin = clock();
  int nlines; /* number of liens read */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    my_qsort(lineptr, 0, nlines - 1);
    writeLines(lineptr, nlines);
  } else {
    printf("Error: input too big to sort\n");
    return 1;
  }

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The run time is %f\n", time_spent);
  return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {

  // allocation part
  char allocbuff[ALLOCSIZE];
  char *allocp = allocbuff;

  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0) {

    if (allocbuff + ALLOCSIZE - allocp < len || nlines >= maxlines) {
      return -1;
    }

    p = allocp;
    line[len - 1] = '\0';
    strcpy(p, line);

    lineptr[nlines++] = p;

    p = NULL;
    allocp += len;
  }
  return nlines;
}

/* writelines: write output lines */
void writeLines(char *lineptr[], int nlines) {

  int i = 0;
  while (i < nlines) {
    printf("%s\n", lineptr[i++]);
  }
}

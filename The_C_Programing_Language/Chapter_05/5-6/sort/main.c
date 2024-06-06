#include "alloc/alloc.h"
#include "getline/getline.h"
#include "qsort/qsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be worted  */
#define MAXLEN 1000   /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers array to text line */

/* read and write lines function declaration */
int readlines(char *lineptr[], int nlines);
void writeLines(char *lineptr[], int nlines);

/* sort input lines */
int main(void) {

  int nlines; /* number of liens read */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    my_qsort(lineptr, 0, nlines - 1);
    writeLines(lineptr, nlines);
  } else {
    printf("Error: input too big to sort\n");
    return 1;
  }
  return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {

  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    }
    line[len - 1] = '\0';
    strcpy(p, line);
    lineptr[nlines++] = p;
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

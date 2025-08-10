#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int my_getline(char *s, int limit);

/*
 The standard lbrary function strstr(s, t) return a pointer to the first
 accurence of the string t in the string s or NULL
*/
int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;

  if (argc != 2) {
    printf("Usage: find patter\n");
  } else {
    while (my_getline(line, MAXLINE) > 0) {
      if (strstr(line, *(argv + 1)) != NULL) {
        printf("%s", line);
        found++;
      }
    }
  }
  return found;
}

/*
  my_getline clone of getline function
  return int number of characters
 */
int my_getline(char *s, int limit) {

  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    *(s + i) = c;
  }

  if (c == '\n') {
    *(s + i) = c;
    i++;
  }
  *(s + i) = '\0';
  s -= i;

  return i;
}

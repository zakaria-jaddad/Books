#ifndef HEADER_H
#define HEADER_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 500

struct key
{
  char *word;
  int count;
};

int getword(char *, int);
struct key *binsearch(char *word, struct key *tab, int n);
int ft_getword(char *word, int lim);
int getch(void);
void ungetch(int c);
void ungets(const char s[]);

#endif

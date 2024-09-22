#ifndef HEADER_H
#define HEADER_H

/* ---------- Includes ---------- */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Constants ---------- */
#define MAXWORD 1000

/* ---------- Structures ---------- */
struct tnode
{
  char *word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child */
  struct tnode *right; /* right child */
};

/* ---------- Prototypes ---------- */
void treeprint(struct tnode *root);
struct tnode *talloc(void);

int ft_getword(char *word, int lim);
int getch(void);
void ungetch(int c);
void ungets(const char s[]);

struct tnode *addtree(struct tnode *, char *);

#endif

#include "../includes/header.h"

/* talloc: make a tnod */
struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

/* addtree: add a node with word: w at or bellow p */
struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else
  {
    cond = strcmp(w, p->word);
    if (cond == 0) /* repeated word */
      p->count++;
    else if (cond < 0) /* less than into left subtree */
      p->left = addtree(p->left, w);
    else /* greater than into right subtree */
      p->right = addtree(p->right, w);
  }
  return p;
}

#include "../includes/tnode.h"
#include <stdio.h>

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  {
    p = (struct tnode *)malloc((sizeof(struct tnode)));
    p->word = strdup(w);
    p->left = p->right = NULL;
  }
  else
  {
    cond = strcmp(w, p->word);
    if (cond > 0)
      p->right = addtree(p->right, w);
    else if (cond < 0)
      p->left = addtree(p->left, w);
  }
  return p;
}

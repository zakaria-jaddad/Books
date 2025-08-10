#include "../includes/tnode.h"

void treeprint(struct tnode *p)
{
  if (p != NULL)
  {
    treeprint(p->left);
    printf("%s\n", p->word);
    treeprint(p->right);
  }
}

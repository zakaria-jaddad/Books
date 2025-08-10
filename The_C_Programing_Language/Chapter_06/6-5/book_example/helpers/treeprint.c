#include "../includes/header.h"

void treeprint(struct tnode *root)
{
  if (root != NULL)
  {
    treeprint(root->left);
    printf("%4d %s\n", root->count, root->word);
    treeprint(root->right);
  }
}

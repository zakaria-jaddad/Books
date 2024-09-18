#include "includes/header.h"
#include <stdio.h>

/* word frequency count */
int main(int argc, char **argv)
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (ft_getword(word, MAXWORD) != EOF)
  {
    if (isalpha(word[0]))
    {
      printf("got this -> %s\n", word);
      root = addtree(root, word);
    }
  }
  treeprint(root);
  return 0;
}

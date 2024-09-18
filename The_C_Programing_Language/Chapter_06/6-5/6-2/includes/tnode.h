#ifndef TNODE_H
#define TNODE_H

struct tnode
{
  char *word;
  struct tnode *right;
  struct tnode *left;
};

#endif

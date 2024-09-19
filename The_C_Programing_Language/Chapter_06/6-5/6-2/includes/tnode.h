#ifndef TNODE_H
#define TNODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
  char *word;
  struct tnode *right;
  struct tnode *left;
};

struct list_node
{
  struct tnode *var_group;
  struct list_node *next;
};

/* addtree: add a node to tree */
struct tnode *addtree(struct tnode *, char *);

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p);

/* addlist: add word to list */
struct list_node *addlist(struct list_node *, char *, int);

/* printnvar: var list */
void print_list(struct list_node *node_p);

#endif

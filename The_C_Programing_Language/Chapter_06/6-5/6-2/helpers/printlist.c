#include "../includes/tnode.h"

void print_list(struct list_node *head)
{
  if (head != NULL)
  {
    treeprint(head->var_group);
    printf("\n");
    print_list(head->next);
  }
}

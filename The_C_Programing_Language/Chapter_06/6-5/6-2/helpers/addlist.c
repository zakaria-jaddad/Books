#include "../includes/tnode.h"

struct list_node *addlist(struct list_node *head, char *w, int n)
{
  if (head == NULL)
  {
    head = (struct list_node *)malloc(sizeof(struct list_node));
    head->var_group = addtree(head->var_group, w);
  }
  else if (strncmp(w, head->var_group->word, n) == 0)
    head->var_group = addtree(head->var_group, w);
  else
  {
    head->next = addlist(head->next, w, n);
  }
  return head;
}

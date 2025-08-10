#include "../includes/nlist.h"

void undef(char *name, char *def)
{
  int hashval;
  struct nlist *next;
  struct nlist *prev;
  struct nlist *np = lookup(name);

  if (np == NULL)
    return;

  hashval = hash(name);

  /* set next point to nlist rest */
  next = np->next;
  prev = hashtab[hashval];

  /* locate node before np */
  while (prev->next != NULL && strcmp(prev->next->name, name) == 0)
    prev = prev->next;

  /* set located node to point to rest */
  prev->next = next;

  /* free np */
  free((void *)np->name);
  free((void *)np->defn);
  free((void *)np);
}

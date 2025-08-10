#include "../includes/nlist.h"
#include <stdio.h>

struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
  {
    if (strcmp(s, np->name) == 0)
      return np;
  }
  return NULL;
}

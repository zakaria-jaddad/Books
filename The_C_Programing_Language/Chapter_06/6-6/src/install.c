#include "../includes/nlist.h"
#include <stdio.h>

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned int hashval;

  /* not found */
  if ((np = lookup(name)) == NULL)
  {
    np = (struct nlist *)malloc(sizeof(struct nlist));
    if (np == NULL)
      return NULL;

    np->name = strdup(name);
    if (np->name == NULL)
      return NULL;

    hashval = hash(name);

    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  }
  /* free previous defn */
  else
    free((void *)np->defn);

  np->defn = strdup(defn);
  if (np->defn == NULL)
    return NULL;

  return np;
}

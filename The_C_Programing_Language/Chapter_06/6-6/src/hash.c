#include "../includes/nlist.h"

unsigned int hash(char *s)
{
  unsigned int hashval;

  for (hashval = 0; *s; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

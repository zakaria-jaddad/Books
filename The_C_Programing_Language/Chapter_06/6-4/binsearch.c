#include "../header.h"

struct key *binsearch(char *word, struct key *tab, int n)
{
  int cond = 0;
  struct key *low = &tab[0];
  struct key *mid;
  struct key *high = &tab[n - 1];

  while (low <= high)
  {
    mid = (low + (high - low) / 2);
    cond = strcmp(word, mid->word);
    if (cond < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}

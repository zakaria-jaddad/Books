#include "../header.h"

int binsearch(char *word, struct key *tab, int n)
{
  int cond = 0;
  int low, mid, high;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (int)(low + high) / 2;
    cond = strcmp(word, tab[mid].word);
    if (cond < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

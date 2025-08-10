#include "../../includes/ft_split.h"

int count_words(char *str, char *charset)
{
  int count = 0;
  int i = 0;

  while (str[i])
  {
    if (!ft_strchr(charset, str[i]) &&
        (i == 0 || ft_strchr(charset, str[i - 1])))
      count++;
    i++;
  }
  return count;
}

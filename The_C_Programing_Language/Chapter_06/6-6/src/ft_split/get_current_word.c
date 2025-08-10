#include "../../includes/ft_split.h"

char *get_current_word(char *str, char *charset, int index)
{
  int count = 0;
  int i = 0;

  while (str[i])
  {
    if (!ft_strchr(charset, str[i]) &&
        (i == 0 || ft_strchr(charset, str[i - 1])))
    {
      count++;
      if (count == index)
      {
        return &str[i];
      }
    }
    i++;
  }
  return str;
}

#include "../../includes/ft_split.h"

int ft_strlen(char *str, char *charset)
{
  int length = 0;
  while (str[length] && !ft_strchr(charset, str[length]))
    length++;
  return length;
}

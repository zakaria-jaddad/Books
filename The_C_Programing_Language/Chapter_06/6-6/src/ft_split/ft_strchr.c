#include "../../includes/ft_split.h"

char *ft_strchr(char *charset, int c)
{
  while (*charset)
  {
    if (*charset == c)
      return charset;
    charset++;
  }
  if (*charset == c)
    return charset;
  return NULL;
}
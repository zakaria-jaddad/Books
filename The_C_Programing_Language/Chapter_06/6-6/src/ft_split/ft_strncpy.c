#include "../../includes/ft_split.h"

char *ft_strncpy(char *dst, char *src, int length)
{
  int i = 0;
  while (src[i] && i < length)
  {
    dst[i] = src[i];
    i++;
  }
  dst[i] = 0;
  return dst;
}

#include "../includes/header.h"

char *ft_getline(unsigned int limit)
{

  char *s = (char *)malloc(limit);
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    *(s + i) = c;
  }
  *(s + i) = '\0';

  return s;
}
